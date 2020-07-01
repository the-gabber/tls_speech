#include <benchmark/benchmark.h>
#include <pthread.h>

extern thread_local unsigned t_tls_value_dso; //Value from DSO
static thread_local unsigned t_tls_value; //LE defined in another .o
thread_local unsigned t_tls_main;

static unsigned g_data_value; //Reference access to memory


//----------------------------------- .data variable

static void BM_Static(benchmark::State& state)
{
	for (auto _: state)
	{
		benchmark::DoNotOptimize(g_data_value++);
	}
}
BENCHMARK(BM_Static);

//-----------------------------------

static void BM_InitialExec(benchmark::State& state)
{
	for (auto _: state)
	{
		benchmark::DoNotOptimize(t_tls_value_dso++);
	}
}
BENCHMARK(BM_InitialExec);

//-----------------------------------

static void BM_LocalExec(benchmark::State& state)
{
	for (auto _: state)
	{
		benchmark::DoNotOptimize(t_tls_value++);
	}
}
BENCHMARK(BM_LocalExec);

//-----------------------------------

static void BM_PthreadSpecificGet(benchmark::State& state)
{
	pthread_key_t key;
	pthread_key_create(&key, nullptr);
	pthread_setspecific(key, (void*)10);
	for (auto _: state)
	{
		pthread_getspecific(key);
	}
	pthread_key_delete(key);
}
BENCHMARK(BM_PthreadSpecificGet);

//-----------------------------------

static void BM_PthreadSpecificInc(benchmark::State& state)
{
	pthread_key_t key;
	pthread_key_create(&key, nullptr);
	pthread_setspecific(key, (void*)10);
	for (auto _: state)
	{
		auto val = (uintptr_t)pthread_getspecific(key);
		val++;
		pthread_setspecific(key, (void*)val);
	}
	pthread_key_delete(key);
}
BENCHMARK(BM_PthreadSpecificInc);

//-----------------------------------
BENCHMARK_MAIN();


#include <benchmark/benchmark.h>
thread_local unsigned t_tls_value_dso;
extern thread_local unsigned t_tls_main;


//-----------------------------------

static void BM_LocalDynamic(benchmark::State& state)
{
        for (auto _: state)
        {
                benchmark::DoNotOptimize(t_tls_value_dso++);
        }
}
BENCHMARK(BM_LocalDynamic);


//-----------------------------------

static void BM_GeneralDynamic(benchmark::State& state)
{
        for (auto _: state)
        {
                benchmark::DoNotOptimize(t_tls_main++);
        }
}
BENCHMARK(BM_GeneralDynamic);

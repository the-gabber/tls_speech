#include <stdio.h>
#include <dlfcn.h>

typedef void (*fn_type)();

thread_local int t_glob = 0;
thread_local int t_glob_with_val = 5;

int main(int argc, char** argv)
{
	void* lib = dlopen("./libdso.so", RTLD_LAZY);
	if (!lib)
	{
		printf("Can't open %s\n", dlerror());
		return 1;
	}
	fn_type fn = (fn_type) dlsym(lib, "_Z2fnv");
	if (fn)
	{
		fn();
		printf("Glob %d glob_with_val %d\n", t_glob, t_glob_with_val);
	}

	dlclose(lib);
	return 0;
}

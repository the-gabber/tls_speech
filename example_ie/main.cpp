#include <stdio.h>

extern void fn();

thread_local int t_glob = 0;
thread_local int t_glob_with_val = 5;

int main(int argc, char** argv)
{
	fn();
	printf("Glob %d glob_with_val %d\n", t_glob, t_glob_with_val);
	return 0;
}

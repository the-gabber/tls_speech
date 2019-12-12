#include <stdio.h>

extern thread_local int t_glob;
extern thread_local int t_glob_with_val;

int main(int argc, char** argv)
{
	t_glob++;
	t_glob_with_val += 2;
	printf("Glob %d glob_with_val %d\n", t_glob, t_glob_with_val);
	return 0;
}

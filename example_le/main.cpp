#include <stdio.h>

static thread_local int t_glob = 0;
static thread_local int t_glob_with_val = 5;

int main(int argc, char** argv)
{
	t_glob++;
	t_glob_with_val += 2;
	printf("Glob %d glob_with_val %d\n", t_glob, t_glob_with_val);
	return 0;
}

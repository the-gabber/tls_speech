#include <stdio.h>

extern int fn(int& val2);

int main(int argc, char** argv)
{
	int b;
	int a = fn(b);
	printf("Glob %d glob_with_val %d\n", a, b);
	return 0;
}

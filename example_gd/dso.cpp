
extern thread_local int t_glob;
extern thread_local int t_glob_with_val;

void fn()
{
	t_glob++;
	t_glob_with_val += 2;
}


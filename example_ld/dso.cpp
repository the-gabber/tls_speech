
static thread_local int t_glob = 0;
static thread_local int t_glob_with_val = 5;

int fn(int& val2)
{
	t_glob++;
	t_glob_with_val += 2;
	val2 = t_glob_with_val;
	return t_glob;
}


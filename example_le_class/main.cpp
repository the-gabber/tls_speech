#include <stdio.h>

class SomeCls
{
public:
	SomeCls()
	{
		printf("Init\n");
	}

	~SomeCls()
	{
		printf("Destr count=%d\n", m_count);
	}

	void increment()
	{
		m_count++;
	}

private:
	int m_count = 0;
};

thread_local SomeCls t_scls;

int main(int argc, char** argv)
{
	t_scls.increment();
	return 0;
}

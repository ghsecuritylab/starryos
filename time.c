#include <time.h>

int luban_time()
{
	int now = 0;

	now = time(NULL);	

	return now;
}

char *luban_time_str()
{
	time_t now = 0;

	now = time(NULL);	
	return ctime(&now);
}


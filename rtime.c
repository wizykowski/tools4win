#include <process.h>
#include <stdio.h>
#include <windows.h>

double diff_time(LARGE_INTEGER t2, LARGE_INTEGER t1)
{
	LARGE_INTEGER cycles;
	double ret;
	QueryPerformanceFrequency(&cycles);

	ret=(double)(t2.QuadPart-t1.QuadPart);
	ret/=cycles.QuadPart;

	printf("Precision: %.10f\n", 1.0f/(double)cycles.QuadPart);
	return ret;
}

int main(int argc, char *argv[])
{
	LARGE_INTEGER time1, time2;

	if (argc <= 1) {
		printf("Missing argument!\n");
		return 0;
	}

	QueryPerformanceCounter(&time1);
	int res = spawnv(P_WAIT, argv[1], argv + 1);
	QueryPerformanceCounter(&time2);

	if (res == -1)
		printf("Error executing %s: %s\n", argv[1], strerror(errno));
	else if (res != 0)
		printf("Program returned code %d\n", res);

	printf("Time: %.10f seconds\n", diff_time(time2, time1));
	return 0;
}

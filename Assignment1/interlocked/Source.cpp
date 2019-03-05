#include<stdio.h>
#include<Windows.h>
long glo_var;
DWORD WINAPI thread_func1(LPVOID param)
{
	InterlockedExchangeAdd(&glo_var, 1);
	return 0;
}
DWORD WINAPI thread_func2(LPVOID param)
{
	InterlockedExchangeAdd(&glo_var, 1);
	return 0;
}
int main()
{
	DWORD dwthreadid1, dwthreadid2;
	HANDLE hthread1, hthread2;
	HANDLE arr[2];

	while (1)
	{
		glo_var = 0;

		hthread1 = CreateThread(NULL, 0, thread_func1, NULL, 0, &dwthreadid1);
		if (hthread1 == NULL)
			printf("thread1 is not created");
		hthread2 = CreateThread(NULL, 0, thread_func2, NULL, 0, &dwthreadid2);
		if (hthread2 == NULL)
			printf("thread2 is not created");

		arr[0] = hthread1;
		arr[1] = hthread2;

		//waiting for the threads to close

		WaitForMultipleObjects(2, arr, TRUE, INFINITE);
		//closing the thread of the process
		CloseHandle(hthread1);
		CloseHandle(hthread2);
		if (glo_var != 2)
		{
			printf("inconsistent value\n");
			break;
		}
		else
			printf("value of gloabal variable is %d\n", glo_var);
	}
	system("pause");
}


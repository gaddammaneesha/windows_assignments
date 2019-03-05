#include<stdio.h>
#include<windows.h>
CRITICAL_SECTION obj;
long int glo_var = 0;
DWORD WINAPI thread_func1(LPVOID lparam)
{
	EnterCriticalSection(&obj);
	glo_var++;
	printf("entered critical section of Thread1\n");
	LeaveCriticalSection(&obj);
	return 0;
}
DWORD WINAPI thread_func2(LPVOID lparam)
{
	EnterCriticalSection(&obj);
	glo_var++;
	printf("entered critical section of Thread2\n");
	LeaveCriticalSection(&obj);
	return 0;
}
int main()
{
	HANDLE hthread1, hthread2;
	DWORD dwthread_id1, dwthread_id2;
	HANDLE arr[2];
	InitializeCriticalSection(&obj);
	hthread1 = CreateThread(NULL, 0, thread_func1, NULL, 0, &dwthread_id1);
	if (hthread1 == NULL)
		printf("thread1 not created\n");
	else
		arr[0] = hthread1;
	hthread2 = CreateThread(NULL, 0, thread_func2, NULL, 0, &dwthread_id2);
	if (hthread2 == NULL)
		printf("thread2 not created\n");
	else
		arr[1] = hthread2;
	WaitForMultipleObjects(2, arr, TRUE, 1000);
	printf("value of shared variable is %d\n", glo_var);
	DeleteCriticalSection(&obj);
	CloseHandle(hthread1);
	CloseHandle(hthread2);
	getchar();
}
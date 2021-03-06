#include<stdio.h>
#include<Windows.h>
//exit secondary thread using ExitThread API
DWORD WINAPI thread_func(LPVOID param)
{
	for (int i = 0; i < 10; i++)
		printf("%d", i);
	return 0;
}
int main()
{
	DWORD dwthreadid;
	HANDLE hthread;
	DWORD dwExitCode = 0;
	hthread = CreateThread(NULL, 0, thread_func, NULL, 0, &dwthreadid);
	if (hthread == NULL)
		printf("thread is not created");
	//waiting for the thread to close
	WaitForSingleObject(hthread, 1000);
	printf("terminating thread  %d",TerminateThread(hthread, dwExitCode));
	printf("\nExitCode = %d\n", GetExitCodeThread(hthread, &dwExitCode));
	//closing the thread of the process
	CloseHandle(hthread);
	system("pause");
}
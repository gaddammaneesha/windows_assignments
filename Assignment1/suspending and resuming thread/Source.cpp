#include<stdio.h>
#include<Windows.h>
#include<shellapi.h>
DWORD WINAPI thread_func(LPVOID param)
{
	for (int i = 1; i <= 1000; i++)
		printf("%d  ", i);
	return 0;
}
int main()
{
	DWORD dwthreadid;
	HANDLE hthread;
	hthread = CreateThread(NULL, 0, thread_func, NULL, CREATE_SUSPENDED, &dwthreadid);
	//thread is activated after 5sec
	Sleep(5000);  //sleep time in milliseconds
	ResumeThread(hthread);  //resuming thread for execution
	if (hthread == NULL)
		printf("thread is not created\n");
	//waiting fot thread to close
	WaitForSingleObject(hthread, 5000);
	//closing the thread of the process
	CloseHandle(hthread);
	getchar();
}
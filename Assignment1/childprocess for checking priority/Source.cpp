#include<stdio.h>
#include<windows.h>
DWORD WINAPI thread_func(LPVOID lparam)
{
	printf("created thread sucessfully");
	return 0;
}
int main()
{
	DWORD dwThreadId1;  //variable to strore thread id
	HANDLE hThread1;    //handle for thread
						//creating thread 
	hThread1 = CreateThread(NULL, 0, thread_func, NULL, 0, &dwThreadId1);
	//Checking whether thread is created or not
	if (hThread1 == NULL)
		printf("thread is not created");
	SetPriorityClass(GetCurrentProcess(), BELOW_NORMAL_PRIORITY_CLASS);
	SetThreadPriority(GetCurrentThread(), -2);
	//waiting for the thread to close
	WaitForSingleObject(hThread1, 1000);
	//closing the thread of the process
	CloseHandle(hThread1);
	system("pause");
}
//printing process and thread id using different functions
#include<Windows.h>
#include<tchar.h>
#include<stdio.h>
void _tmain(int argc, LPTSTR argv[])
{
	STARTUPINFO si1;            //structures for processes
	PROCESS_INFORMATION pi1;
	ZeroMemory(&si1, sizeof(si1));   // structure pointer pointing to zero
	ZeroMemory(&pi1, sizeof(pi1));

	BOOL ret = 0;
	HANDLE hProcess;   //handle for process
	HANDLE hThread;    //handle for thread
					   //creating child process
	ret = CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &si1, &pi1);

	wprintf(L"Currentprocess id is : %lu\n", GetCurrentProcessId());

	wprintf(L"Currentthread id is : %lu\n", GetCurrentThreadId());

	wprintf(L"Process id is : %lu\n", GetProcessId(pi1.hProcess));

	wprintf(L"Thread id is : %lu\n", GetThreadId(pi1.hThread));

	wprintf(L"Process id of thread is : %lu\n", GetProcessIdOfThread(pi1.hThread));
	system("pause");

}
#include<stdio.h>
#include<windows.h>
#include<tchar.h>
//parent process creation
int _tmain(int argc, LPTSTR argv[])
{
	STARTUPINFO si1;  //process structures
	PROCESS_INFORMATION pi1;
	ZeroMemory(&si1, sizeof(si1));
	ZeroMemory(&pi1, sizeof(pi1));
	BOOL res = 0;
	//creating child process
	res = CreateProcess(NULL, argv[1], NULL, NULL,TRUE, 0, NULL, NULL, &si1, &pi1);
	if (!res)
		printf("Create Process failed (%d).\n", GetLastError());
	res = SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
	CloseHandle(pi1.hProcess);
	getchar();
}
#include<stdio.h>
#include<windows.h>
#include<tchar.h>
//parent process
int _tmain(int argc, LPTSTR argv[])
{
	STARTUPINFO si1;  //process structures
	PROCESS_INFORMATION pi1;
	STARTUPINFO si2;  
	PROCESS_INFORMATION pi2;
	ZeroMemory(&si1, sizeof(si1));
	ZeroMemory(&pi1, sizeof(pi1));
	ZeroMemory(&si2, sizeof(si2));
	ZeroMemory(&pi2, sizeof(pi2));
	BOOL res = 0;
	//creating child process
	res = CreateProcess(NULL, argv[1], NULL, NULL, TRUE, 0, NULL, NULL, &si1, &pi1);
	if (!res)
		printf("CreateProcess failed (%d).\n", GetLastError());
	else 
	{
		printf("first process id : %d\n", pi1.hProcess);
		printf("first process handle : %d\n", pi1.hThread);
	}
	res = CreateProcess(NULL, argv[2], NULL, NULL, TRUE, 0, NULL, NULL, &si2, &pi2);
	if (!res)
		printf("CreateProcess failed (%d).\n", GetLastError());
	else
	{
		printf("second process id : %d\n", pi2.hProcess);
		printf("second process handle : %d\n", pi2.hThread);
	}
	getchar();
}
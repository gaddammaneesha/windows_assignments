#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<shellapi.h>
int _tmain(int argc, LPTSTR argv[])
{
	STARTUPINFO si;    //declaring structure variables
	PROCESS_INFORMATION pi;
	SECURITY_ATTRIBUTES se;
	se.nLength = sizeof(SECURITY_ATTRIBUTES);
	se.bInheritHandle = TRUE;
	se.lpSecurityDescriptor = NULL;
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));
	for (int i = 0; i < argc; i++)   //checking whether comman line arguments are read or not
		_tprintf(_T("ARGV[i] = %s\n"), argv[i]);
	// creating event and receiving a handle
	HANDLE hEve = CreateEvent(
		&se, FALSE, FALSE, L"object");
	//checking whether file is created or not
	if (hEve == INVALID_HANDLE_VALUE)
		printf("Event Creation failed\n");
	//creating process for the thread to inherit
	BOOL ret = CreateProcess(
		NULL, argv[1], NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
	if (ret == 0)
	{
		printf("Process creation failed, Error = %d", GetLastError());
	}
	//waiting for the inherited process to close
	WaitForSingleObject(pi.hProcess, INFINITE);
	//printing process id and thread
	_tprintf(_T("ProcessId : %lu\n"), GetProcessId(pi.hProcess));
	_tprintf(_T("ThreadId : %lu\n"), pi.hThread);
	//closing process
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	system("pause");
	return 0;
}


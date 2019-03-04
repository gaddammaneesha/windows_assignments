#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<shellapi.h>
//creating event program
int main()
{
	SECURITY_ATTRIBUTES se;
	se.bInheritHandle = TRUE;
	se.lpSecurityDescriptor = NULL;
	se.nLength = sizeof(se);
	//creating event
	HANDLE hEve = CreateEvent(
		&se, FALSE, FALSE, L"ANVESH");
	//checking whether event is created or not
	if (hEve == INVALID_HANDLE_VALUE)
		printf("Event Creation failed\n");
	else
		printf("DONE - [%d]\n", GetLastError());
	//closing the handle
	CloseHandle(hEve);

	getchar();
	return 0;
}
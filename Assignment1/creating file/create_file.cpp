#include<stdio.h>
#include<windows.h>
#include<tchar.h>
#include<string.h>
# define BUFFSIZE 50
//creating and reading file
int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hfile;	//creating handle for file
	char buffer[BUFFSIZE];
	if (argc != 2)
	{
		printf("enter file name to open \n");
		return 0;
	}
	_tprintf(_T("filename :%s\n"), argv[1]);
	hfile=CreateFile(argv[1], GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL); //open file
	if (hfile == INVALID_HANDLE_VALUE)
	{
		printf("file doesnot exist\n");
		return 0;
	}
	else
	{
		_tprintf(_T("file %s opened successfully\n"), argv[1]);
			DWORD dwcount;	//counting the number of bytes
			BOOL ret = ReadFile(hfile, buffer,BUFFSIZE, &dwcount, NULL);
			if (ret == FALSE)
			{
				_tprintf(_T("cannot read file"));
				getchar();
				CloseHandle(hfile);
				return FALSE;
			}
			else if (ret == TRUE && dwcount == 0)		// no data present and file exist
			{
				_tprintf(_T("Reached End Of File"));
				CloseHandle(hfile);
			
			}
			else
			{
				CloseHandle(hfile);
				printf("%s\n", buffer);
			}

	}
	system("pause");
}
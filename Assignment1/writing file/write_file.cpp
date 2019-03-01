#include<stdio.h>
#include<windows.h>
#include<tchar.h>
#include<string.h>

//creating and writting file
int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hfile;	//creating handle for file
	char buffer[]="writting to the file";
	if (argc != 2)
	{
		printf("enter file name to open \n");
		return 0;
	}
	_tprintf(_T("filename :%s\n"), argv[1]);
	hfile = CreateFile(argv[1], GENERIC_WRITE, 0, NULL,CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); //creating file
	if (hfile == INVALID_HANDLE_VALUE)
	{
		printf("file not created\n");
		return 0;
	}
	else
	{
		_tprintf(_T("file %s created successfully\n"), argv[1]);
		DWORD dwcount;	//counting the number of bytes
		BOOL ret = WriteFile(hfile, buffer,strlen(buffer), &dwcount, NULL);
		if (ret == FALSE)
		{
			_tprintf(_T("cannot write file"));
			getchar();
			CloseHandle(hfile);
			return FALSE;
		}
		else
		{
			CloseHandle(hfile);
			printf("writting to the file done successfully\n");
		}

	}
	system("pause");
}
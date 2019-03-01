

#include<stdio.h>
#include<windows.h>
#include<shellapi.h>
#include<tchar.h>
using namespace std;
int main()
{
	LPWSTR *SZargslist;
	int i, nargs;
	SZargslist=CommandLineToArgvW(GetCommandLineW(), &nargs);
	if (SZargslist == NULL)
		wprintf(L"no commandline arguments\n");
	else
	{
		for (i = 0; i < nargs; i++)
			wprintf(L"%d-%s\n", i, SZargslist[i]);
	}
	system("pause");
	return 0;
}
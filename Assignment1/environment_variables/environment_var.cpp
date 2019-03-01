#include<stdio.h>
#include<windows.h>
#include<tchar.h>
void DumpEnvstrings(PTSTR pEnvBlock[])
{
	int current = 0;
	PTSTR *pelement = (PTSTR*)pEnvBlock;
	PTSTR pcurrent = NULL;
	while (pelement != NULL)
	{
		pcurrent = (PTSTR)(*pelement);
		if (pcurrent == NULL)
			pelement = NULL;
		else
		{
			_tprintf(_T("[%u]%S/r\n"), current, pcurrent);
			current++;
			pelement++;
		}

	}
}
int main(int argc,TCHAR *argv[],TCHAR *env[])
{
	DumpEnvstrings(env);
	TCHAR envstring0[] = TEXT("%windir%");
	TCHAR envstring1[] = TEXT("%systemroot%");
	TCHAR buffer[MAX_PATH];
	DWORD ret;
	ret = ExpandEnvironmentStrings(envstring0, buffer, MAX_PATH);//returns no.of characters if success else 0
	if (!ret)
		printf("error %d", GetLastError());
	else
		_tprintf(L"%ws\n", buffer);
	ret = ExpandEnvironmentStrings(envstring1, buffer, MAX_PATH);//returns no.of characters if success else 0
	if (!ret)
		printf("error %d", GetLastError());
	else
		_tprintf(L"%ws\n", buffer);
	system("pause");

}
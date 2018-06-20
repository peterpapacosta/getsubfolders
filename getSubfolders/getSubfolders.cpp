// getSubfolders.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include<string>
#include <atlstr.h>
using namespace std;
int main(int argc, char *argv[])
{
	int a;
	WIN32_FIND_DATA findfiledata;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	//std::string path = "C:\\Users\\Peter Papacosta\\Documents\\*";
	CString path = "C:\\Users\\peter\\Documents\\*";
	CString filename;
	char fullpath[MAX_PATH];
	//GetFullPathName((LPCWSTR)path.c_str(), MAX_PATH, (LPWSTR)fullpath, 0);
	//char* fp("C:\\Users\\Peter Papacosta\\Documents\\*");
	std::string fp(fullpath);
	hFind = FindFirstFile((LPCWSTR)path, &findfiledata);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			filename = findfiledata.cFileName;
			if ((findfiledata.dwFileAttributes | FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY
				|| (findfiledata.cFileName[0] == '.'))
			{
				
				wcout << "<DIR>    " << filename.GetString() << "\n";
			}
			else
			{
				wcout << filename.GetString() << "\n";
			}
			//a = FindNextFile(hFind, &findfiledata);
		} while (FindNextFile(hFind, &findfiledata) !=0);
	}
}


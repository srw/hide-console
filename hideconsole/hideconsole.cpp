// hideconsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include <string>
#include <iostream>
#include <stdio.h>

namespace std
{
#ifdef _UNICODE
	typedef wstring tstring;
	#define tout std::wcout
#else
	typedef string tstring;
	#define tout std::cout
#endif
}
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	if(argc == 1) {
		//wprintf(_T("Usage: %s <cmd> [<parameter1>..<parametern>]"));
		tout << "Usage: " << argv[0] << " <cmd> [<parameter1>..<parametern>]" << endl;
		return 0;
	}

	tstring file = argv[1];
	tstring parameters;

	for(int i=2; i < argc; i++) {
		if( i != 2)
			parameters.append(_T(" "));
		parameters.append(argv[i]);
	}

	ShellExecute(NULL, _T("open"), file.c_str(), parameters.c_str(), NULL, SW_HIDE);
	tout << "Running cmd = " << file << endl;
	tout << "Arguments = " << parameters << endl;


	return 0;
}


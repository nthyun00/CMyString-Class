// StringCtrl.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "MyString.h"


int _tmain(int argc,_TCHAR* argv[])
{
	CMyString strData, strTest;
	strData.SetString("Hello");
	strTest.SetString("Hello");

	cout << strData.GetString() << endl;
	(cout << (strData != strTest))<< endl;

    return 0;
}


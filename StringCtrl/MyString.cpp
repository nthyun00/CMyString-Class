#include "stdafx.h"
#include "MyString.h"


CMyString::CMyString()
	: m_pszData(NULL)
	, m_nLength(0)
{
}
CMyString::CMyString(const CMyString& rhs)
	: m_pszData(NULL)
	, m_nLength(0)
{
	this->SetString(rhs.GetString());
}
CMyString::CMyString(const char* pszParam)
	: m_pszData(NULL)
	, m_nLength(0)
{
	SetString(pszParam);
}
CMyString::CMyString(CMyString&& rhs)
	: m_pszData(NULL)
	, m_nLength(0)
{
	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	rhs.m_pszData = NULL;
	rhs.m_nLength = 0;
}
CMyString::~CMyString()
{
	Release();
}

CMyString::operator char*() const
{
	return m_pszData;
}
CMyString& CMyString::operator=(const CMyString& rhs)
{
	if(this!=&rhs)	//�ڱ� �ڽſ� ���� �����̸� �ƹ��͵� ���� ����
		this->SetString(rhs.GetString());
	return *this;
}
CMyString CMyString::operator+(const CMyString& rhs)
{
	CMyString strResult(m_pszData);
	strResult.Append(rhs.GetString());
	return strResult;
}
CMyString& CMyString::operator+=(const CMyString& rhs)
{
	Append(rhs.GetString());
	return *this;
}
char& CMyString::operator[](int nIndex)
{
	/*if (nIndex < 0 || nIndex >= GetLength())
		return ??;*/
	return m_pszData[nIndex];
}
char CMyString::operator[](int nIndex) const
{
	/*if (nIndex < 0 || nIndex >= GetLength())
		return 0;*/
	return m_pszData[nIndex];
}
int CMyString::operator==(const CMyString &rhs)
{
	if (m_pszData != NULL&&rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == true)
			return true;
	return false;
}
int CMyString::operator!=(const CMyString &rhs)
{
	if (m_pszData != NULL&&rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == true)
			return false;
	return true;
}


int CMyString::SetString(const char* pszParam)
{
	Release();

	if (pszParam == NULL)
		return 0;

	int nLength = strlen(pszParam);
	if (nLength == 0)
		return 0;
	m_pszData = new char[nLength + 1];
	strcpy_s(m_pszData, sizeof(char)* (nLength + 1), pszParam);

	return nLength;
}
int CMyString::Append(const char* pszParam)
{
	if (pszParam == NULL)	//��ȿ�� �˻�
		return 0;

	int nLenParam = strlen(pszParam);
	if (nLenParam == 0)
		return 0;

	//��Ʈ�� ���ڿ��� ���ٸ� ���� ���ڿ��� �Ҵ�
	if (m_pszData == NULL)
	{
		SetString(pszParam);
		return m_nLength;
	}

	//��ģ �� ���ڿ��� ������ �� �ִ� �޸𸮸� ���� �Ҵ���
	char* pszResult = new char[m_nLength + nLenParam + 1];
	
	//���ڿ� ����
	strcpy_s(pszResult, 
		sizeof(char)*(m_nLength + 1), 
		m_pszData);
	strcpy_s(pszResult + (sizeof(char)*m_nLength), 
		sizeof(char)*(nLenParam + 1), 
		pszParam);
	
	//���� ���ڿ� ����, ������� ����
	Release();
	m_pszData = pszResult;
	m_nLength += nLenParam;

	return m_nLength;
}
const char* CMyString::GetString() const
{
	return m_pszData;
}
int CMyString::GetLength() const
{
	return m_nLength;
}
void CMyString::Release()
{
	if (m_pszData != NULL)
		delete[] m_pszData;

	m_pszData = NULL;
	m_nLength = 0;
}

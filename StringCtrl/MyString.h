#pragma once
class CMyString
{
private:
	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;
	// ����� ���ڿ��� ����
	int m_nLength;
public:
	CMyString();
	CMyString(const CMyString& rhs); //���� ������
	explicit CMyString(const char* pszParam); //��ȯ ������
	CMyString(CMyString&& rhs);	//�̵� ������
	~CMyString();

	operator char*() const;
	CMyString& operator=(const CMyString& rhs);
	CMyString operator+(const CMyString& rhs);
	CMyString& operator+=(const CMyString& rhs);
	char& operator[](int nIndex);
	char operator[](int nIndex) const;
	int operator==(const CMyString &rhs);
	int operator!=(const CMyString &rhs);


	int SetString(const char* pszParam);
	int Append(const char* pszParam);
	const char* GetString() const;
	int GetLength() const;
	void Release();
};


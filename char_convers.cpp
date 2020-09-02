#include "StdAfx.h"
#include "Wchar2Char.h"


CWchar2Char::CWchar2Char(void)
{
	m_char = NULL;
	m_wchar = NULL;
}


CWchar2Char::~CWchar2Char(void)
{
	Release();
}

CWchar2Char & CWchar2Char::getInstance()
{
	static CWchar2Char instance;
	return instance;

}

char* CWchar2Char::WcharToChar(wchar_t* wc)  
{  
	//Release();  
	int len= WideCharToMultiByte(CP_ACP,0,wc,(int)wcslen(wc),NULL,0,NULL,NULL);  
	m_char = new char[len + 1];
	WideCharToMultiByte(CP_ACP,0,wc,(int)wcslen(wc),m_char,len,NULL,NULL);  
	m_char[len]='\0';  
	return m_char;  
}  

wchar_t* CWchar2Char::CharToWchar(char* c)  
{  
	//Release();  
	int len = MultiByteToWideChar(CP_ACP,0,c,(int)strlen(c),NULL,0);  
	/*m_wchar=new wchar_t[len+1];*/  
	MultiByteToWideChar(CP_ACP,0,c,(int)strlen(c),m_wchar,len);  
	m_wchar[len]='\0';  
	return m_wchar;  
}  

void CWchar2Char::Release()  
{  
	if(m_char)  
	{  
		memset(m_char, 0, 1024); 
	}  
	if(m_wchar)  
	{  
		memset(m_wchar, 0, 1024);  
	}  
} 

std::string CWchar2Char::Unicode2Utf8(const std::wstring& widestring)
{
	//using namespace std;
	int utf8size = ::WideCharToMultiByte(CP_UTF8, 0, widestring.c_str(), -1, NULL, 0, NULL, NULL);
	if (utf8size == 0)
	{
		throw std::exception("Error in conversion.");
	}
	std::vector<char> resultstring(utf8size);
	int convresult = ::WideCharToMultiByte(CP_UTF8, 0, widestring.c_str(), -1, &resultstring[0], utf8size, NULL, NULL);
	if (convresult != utf8size)
	{
		throw std::exception("La falla!");
	}
	return std::string(&resultstring[0]);
}


std::wstring CWchar2Char::utf8toUnicode(const std::string & sStr)
{
	auto len = strlen(sStr.c_str());
	int unicodeLen = ::MultiByteToWideChar(CP_UTF8, 0, sStr.c_str(), -1, NULL, 0);
	wchar_t* pUnicode;
	pUnicode = new wchar_t[unicodeLen + 1];
	memset((void*)pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));
	::MultiByteToWideChar(CP_UTF8, 0, sStr.c_str(), -1, (LPWSTR)pUnicode, unicodeLen);
	std::wstring wstrReturn(pUnicode);
	delete [] pUnicode;
	return wstrReturn;
}
#pragma once

#include <string>
#include <vector>

class CWchar2Char
{
public:
	CWchar2Char(void);
	~CWchar2Char(void);

public:  
	/*virtual~ CUser(); */ 
	static CWchar2Char& getInstance();

	char* WcharToChar(wchar_t* wc);//宽字节转单字节   
	wchar_t* CharToWchar(char* c); //单字节转宽字节   
	void Release();//释放资源   

	std::string Unicode2Utf8(const std::wstring& widestring);
	std::wstring  utf8toUnicode(const std::string & sStr);

private:  
	char *m_char;  
	wchar_t *m_wchar; 
};


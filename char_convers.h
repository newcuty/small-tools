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

	char* WcharToChar(wchar_t* wc);// 宽字符转换至一半字符   
	wchar_t* CharToWchar(char* c); // 一般字符转换至宽字符 
	void Release();//释放资源   

	std::string Unicode2Utf8(const std::wstring& widestring); //unicode to utf8
	std::wstring utf8toUnicode(const std::string & sStr); // utf8 to unicode

private:  
	char m_char[1024];  
	wchar_t m_wchar[1024]; 
};


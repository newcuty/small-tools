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

	char* WcharToChar(wchar_t* wc);//���ֽ�ת���ֽ�   
	wchar_t* CharToWchar(char* c); //���ֽ�ת���ֽ�   
	void Release();//�ͷ���Դ   

	std::string Unicode2Utf8(const std::wstring& widestring);
	std::wstring  utf8toUnicode(const std::string & sStr);

private:  
	char *m_char;  
	wchar_t *m_wchar; 
};


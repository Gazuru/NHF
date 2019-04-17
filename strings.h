#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <iostream>
#include <string.h>

class String{
    char* pData;
    size_t len;
public:
    String(const char* c = ""): pData(0), len(strlen(c)){
        pData = new char[len+1];
        for(size_t i = 0; i < len; i++)
            pData[i] = c[i];
    }
    String(const char c): pData(0), len(1){
        pData = new char[len+1];
        pData[0] = c;
    }
    String(const String &s){
        len = s.len;
        pData = new char[len+1];
        for(size_t i = 0; i < len; i++)
            pData[i] = s[i];
    }
    ~String(){ delete[] pData; }

    size_t getSize() const { return len; }
    char* c_str() const { return pData; }

    char operator[](size_t i) const;
    char operator[](size_t i);
    String& operator=(const String &s);
    String& operator=(const char* c);

};

std::ostream& operator<<(std::ostream& os, const String &s);
//std::istream& operator>>(std::istream& is, String& s);

#endif // STRING_H_INCLUDED


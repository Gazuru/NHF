#include "strings.h"
#include <iostream>

char String::operator[](size_t i) const{
    if(i >= 0 && i < len)
        return pData[i];
    throw("Tulindexelve");
}

char String::operator[](size_t i){
    if(i >= 0 && i < len)
        return pData[i];
    throw("Tulindexelve");
}

String& String::operator=(const String &s){
    if(this != &s){
        delete[] pData;
        len = s.getSize();
        pData = new char[len+1];
        for(size_t i = 0; i < len; i++)
            pData[i] = s[i];
    }
    return *this;
}

String& String::operator=(const char* c){
    delete[] pData;
    len = strlen(c);
    pData = new char[len+1];
    strcpy(pData, c);

    return *this;
}

std::ostream& operator<<(std::ostream& os, const String& s){
    return os << s.c_str() << std::endl;
}


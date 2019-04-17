//
//  string.cpp
//  Gábor nagyházi
//
//  Created by Angéla Pinke on 2019. 04. 01..
//  Copyright © 2019. Angéla Pinke. All rights reserved.
//

#include <iostream>
#include "string.h"

char String::operator[](size_t i){
    if(i < len && i >= 0)
        return pData[i];
    throw("Tulindexelve");
}

char String::operator[](size_t i) const {
    if(i < len && i >= 0)
        return pData[i];
    throw("Tulindexelve");
}

String& String::operator=(const String& s){
    if(this != &s){
        delete[] pData;
        len = s.getSize();
        pData = new char[len+1];
        strcpy(pData, s.c_str());
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

String& String::operator=(const char c){
    delete[] pData;
    len = 1;
    pData = new char[len+1];
    pData[0] = c;
    pData[len] = '\0';
    return *this;
}

std::ostream& operator<<(std::ostream& os, const String& s){
    return os << s.c_str();
}

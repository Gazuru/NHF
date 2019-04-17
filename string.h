//
//  string.h
//  Gábor nagyházi
//
//  Created by Angéla Pinke on 2019. 04. 01..
//  Copyright © 2019. Angéla Pinke. All rights reserved.
//

#ifndef string_h
#define string_h

#include <string.h>

class String{
    char* pData;
    size_t len;
public:
    String(const char* c = ""): pData(0), len(strlen(c)){
        pData = new char[len+1];
        strcpy(pData, c);
    }

    String(const char c): pData(0), len(1){
        pData = new char[len+1];
        pData[0] = c;
        pData[len] = '\0';
    }

    String(const String& s){
        len = s.len;
        pData = new char[len+1];
        strcpy(pData, s.pData);
    }

    ~String(){ delete[] pData; }

    size_t getSize() const { return len; }
    const char* c_str() const { return pData; }
    char operator[](size_t i);
    char operator[](size_t i) const;
    String& operator=(const String& s);
    String& operator=(const char* c);
    String& operator=(const char c);
};

std::ostream& operator<<(std::ostream& os, const String& s);

#endif /* string_h */

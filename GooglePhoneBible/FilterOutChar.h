//
//  FilterOutChar.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/15/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef FilterOutChar_h
#define FilterOutChar_h

#include "DataStructure.h"

using namespace std;

/*
 
 filter out the given char. 如：给“abcdefg”，需要filter掉的是“a“，则给出的char *应该是“bcdefg”，要做到in place
 
 */

void FilterOutChar(string & s, char c) {
    int i = 0, j = 0;
    while(j<s.length()) {
        if (s[j]!=c) {s[i]=s[j]; i++;j++;continue;}
        else {
            j++;
        }
    }
    s = s.substr(0, i);
}

#endif /* FilterOutChar_h */

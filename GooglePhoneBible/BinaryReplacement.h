//
//  BinaryReplacement.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/10/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef BinaryReplacement_h
#define BinaryReplacement_h

#include "DataStructure.h"

using namespace std;

void replaceHelper(vector<string> & result, string s, int pos) {
    if (pos==s.length()) {
        result.push_back(s);
        return;
    }
    
    if (s[pos]=='*') {
        s[pos] = '0';
        replaceHelper(result, s, pos+1);
        s[pos] = '1';
        replaceHelper(result, s, pos+1);
    }
    else {
        replaceHelper(result, s, pos+1);
    }
}



vector<string> BinaryReplacement(string s) {
    vector<string> result;
    replaceHelper(result, s, 0);
    return result;
}



#endif /* BinaryReplacement_h */

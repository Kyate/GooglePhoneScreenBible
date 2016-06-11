//
//  MisspellingWord.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/11/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef MisspellingWord_h
#define MisspellingWord_h

#include "DataStructure.h"

using namespace std;

vector<string> MisspellingWord(vector<string> & dict, string word) {
    unordered_set<string> myset(dict.begin(), dict.end());
    vector<string> result;
    for (int i = 0; i < word.length(); i++) {
        char c = word[i];
        for (int j = 0; j < 26; j++) {
            char d = 'a' + j;
            if (d==c) continue;
            word[i]=d;
            if (myset.count(word)!=0) result.push_back(word);
        }
        word[i] = c;
    }
    
    return result;
}

#endif /* MisspellingWord_h */

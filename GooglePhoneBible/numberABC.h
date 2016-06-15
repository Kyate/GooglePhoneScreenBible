//
//  numberABC.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/14/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef numberABC_h
#define numberABC_h

#include "DataStructure.h"

using namespace std;

int numberABC(int A, int B) {
    string strA = to_string(A);
    string strB = to_string(B);
    if (strA.length()!=strB.length()) return stoi(strA);
    sort(strA.begin(), strA.end(), greater<char>());
    return stoi(strA);
}


bool findMinA(string & result, string strA, multiset<char> & myset, string strB, int bpos) {
    
    char bc = strB[bpos];
    auto aiter = myset.lower_bound(bc);
    if (aiter == myset.end()) return false;
    
    if (*aiter > bc) {
        myset.erase(aiter);
        for (auto it : myset) result.push_back(it);
        return true;
    }
    if (*aiter == bc) {
        for (auto it = aiter; it!=myset.end(); ) {
            result.push_back(*it);
            char th = *it;
            if (th > bc) {
                myset.erase(it);
                for (auto n : myset) result.push_back(n);
                return true;
            }
            it = myset.erase(it);
            bool current = findMinA(result, strA, myset, strB, bpos+1);
            if (current) return true;
            else {
                result.pop_back();
                myset.insert(th);
            }
        }
        
        return false;
    }
    
    return false;
    
}

int MinimumNumberABC(int A, int B) {
    string strA = to_string(A);
    string strB = to_string(B);
    if (strA.length()!=strB.length()) return stoi(strA);
    multiset<char> myset;
    for (auto c : strA) myset.insert(c);
    string result;
    findMinA(result, strA, myset, strB, 0);
    return stoi(result);
}




#endif /* numberABC_h */

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

/*
 
 二面：白男
 
 上来直接问我做过的一个Android项目，问的挺细致的，让我讲扫描二维码登陆的具体实现原理。。。 然后做题：
 
 A: 34567
 B: 45678
 C: 67345
 交换A中的数字位置，得到一个新的数C，使得C大于B。
 我的想法是，每次挑出最大的那个digit跟前面的swap，直到找大于B的，时间复杂度是O(n*n);corner case：当A、B的digits个数不等时，直接返回结果。
 
 这时候小哥给了hint说这本质上是一个sort问题，那么sort问题你ideal复杂度应该是多少呢？sort我就直接想到了quicksort，我就说找最大digit的那个过程
 可以用quick select，这样就是O(nlogn)了。然后让用test case跑一边quick select，让分析复杂度。
 
 Follow up: 存在很多这样的C，返回其中最小的那个。
 
 */

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

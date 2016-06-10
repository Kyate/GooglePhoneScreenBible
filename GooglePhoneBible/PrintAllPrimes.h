//
//  PrintAllPrimes.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/9/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef PrintAllPrimes_h
#define PrintAllPrimes_h

#include "DataStructure.h"

using namespace std;

/*
 第一题：打印所有的质数（print all prime numbers），我已开始没理解清楚范围，设了个i <Integer.MAX_VALUE，为了第一题秒时间，我没多想就用了
 俩for loop写出来了，他说可以，这样能保证小范围的质数短时间打出来
*/

vector<int> PrintAllPrimes(int upper) {
    int x = 2;
    unordered_set<int> myset;
    vector<int> result;
    while(x*x<=upper) { // sqrt is expensive
        if (myset.count(x)>0) { x++; continue; }
        int j = x*x;
        while(j<=upper) {
            myset.insert(j);
            j+=x;
        }
        x++;
    }
    for (int i = 2; i <= upper; i++) {
        if (myset.count(i)==0) result.push_back(i);
    }
    return result;
}

#endif /* PrintAllPrimes_h */

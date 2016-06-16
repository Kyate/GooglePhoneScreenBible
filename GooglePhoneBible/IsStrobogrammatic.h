//
//  IsStrobogrammatic.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/15/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef IsStrobogrammatic_h
#define IsStrobogrammatic_h

#include "DataStructure.h"

using namespace std;

/*
 
 上周五面的，上来直接做题~
 
 判断一个数是不是rotation symmetric，就是把一个数旋转180度，是不是还是原来的那个数，例如“619”，旋转180度还是“619”；followup：给一个数n，输出所有小于n的rotation symmetric number。
 
 链接: https://instant.1point3acres.com/thread/176815 来源: 一亩三分地
 
 */

bool isStrobogrammatic(string num) {
    if (num.length()==0) return false;
    if (num.length()>1 && num[0] == '0') return false;
    int l = 0, r = num.length()-1;
    while(l<r){
        char lc = num[l], rc = num[r];
        if ((lc=='1' && rc=='1') || (lc=='8' && rc=='8') || (lc=='0' && rc=='0') || (lc=='6' && rc=='9') || (lc=='9' && rc=='6')){
            l++;
            r--;
        }
        else return false;
    }
    
    if (l==r) {
        char mid = num[l];
        return mid=='1' || mid=='0' || mid=='8';
    }
    return true;
}

void genHelper(string x, string upper, vector<string> & result);


vector<string> strobogrammaticInRange(string upper) {
    vector<string> result;
    genHelper("", upper, result);
    genHelper("0", upper, result);
    genHelper("1", upper, result);
    genHelper("8", upper, result);
    return result;
}

void genHelper(string x, string upper, vector<string> & result) {
    if (x.length()>upper.length()) return;
    if (x.length()==upper.length()) {
        if (x<=upper && (x.length()==1 || (x.length()>1 && x[0]!='0'))) result.push_back(x);
        return;
    }
    if (x.length()<upper.length() && (x.length()==1 || (x.length()>1 && x[0]!='0')))
        result.push_back(x);

    genHelper("0"+x+"0", upper, result);
    genHelper("1"+x+"1", upper, result);
    genHelper("8"+x+"8", upper, result);
    genHelper("6"+x+"9", upper, result);
    genHelper("9"+x+"6", upper, result);

}


#endif /* IsStrobogrammatic_h */

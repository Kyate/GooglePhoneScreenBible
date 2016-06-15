//
//  BCDAddOne.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/15/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef BCDAddOne_h
#define BCDAddOne_h

#include "DataStructure.h"

using namespace std;

/*
 
 求BCD编码 + 1的值，例如：35的BCD编码是0011 | 0101，给一个BCD的值，输出这个值 + 1的BCD，比如input为0011 | 0101，输出则为0011 | 0110
 每四位BCD码在0-9之间 所以从0000到1001
 */

string singleBCDAddone(string bcd) {
    int add = 0;
    string result(4,' ');
    for (int i = bcd.length()-1; i>=0; i--) {
        if (i==bcd.length()-1) {
            int sum = bcd[i]-'0'+add+1;
            add = sum/2;
            result[i]='0'+sum%2;
        }
        else {
            int sum = bcd[i]-'0'+add;
            add = sum/2;
            result[i]='0'+sum%2;
        }
    }
    return result;
}

string BCDAddOne(string bcd) {
    vector<string> bcds;
    for (int i = 0; i < bcd.length(); i+=4) {
        bcds.push_back(bcd.substr(i,4));
    }
    
    int add = 0;
    for (int i = bcds.size()-1; i>=0; i--) {
        if (i==bcds.size()-1) {
            string current = singleBCDAddone(bcds[i]);
            if (current=="1010") {
                add = 1;
                bcds[i]="0000";
            }
            else bcds[i]=current;
        }
        else {
            if (add==1) {
                string current = singleBCDAddone(bcds[i]);
                if (current=="1010") {
                    add = 1;
                    bcds[i]="0000";
                }
                else {
                    bcds[i] = current;
                    add = 0;
                }
            }
        }
    }
    
    if (add==1) bcds.insert(bcds.begin(), "0001");
    
    string result;
    for (auto str : bcds) {
        result += str;
        result += " ";
    }
    
    return result;
}



#endif /* BCDAddOne_h */

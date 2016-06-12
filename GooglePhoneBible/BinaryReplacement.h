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

/*
 
 美国小哥。上来先问我自我介绍和最challenge的project。聊了大概七八分钟， 然后上题。很简单。 1. 给一个字符串里面只包含0-9的数字和＊，＊可以被0或
 者1代替，求出input字符串中的＊代替成0或者1的所有结果。100*11 结果是 100011，100111
 
 链接: https://instant.1point3acres.com/thread/176414
 来源: 一亩三分地
 
 */

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

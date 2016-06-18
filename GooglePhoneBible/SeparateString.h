//
//  SeparateString.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/18/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef SeparateString_h
#define SeparateString_h

#include "DataStructure.h"

using namespace std;

/*
 
 Google 电面是和fremont office的印度小哥， 做了一道题目15分钟，然后聊了30分钟，过了。
 
 题目是， 一个string, 有空格，有引号，sparse string, 两个引号中间的部分的空格不处理, 引号外面的空格将前后划成两个String。
 
 做法就是traverse一遍就搞定了，细节处理一下。
 
 然后问了test case, 时间复杂度空间复杂度。
 
 http://www.1point3acres.com/bbs/thread-188226-1-1.html
 
 */

vector<string> SeparateString(string str) {
    vector<string> result;
    int pos = 0;
    while(pos<str.length()) {
        while(pos < str.length() && str[pos]==' ') pos++;
        int startpos = pos;
        while(pos < str.length() && str[pos]!=' ' && str[pos]!='"') pos++;
        if (str[pos]=='"') {
            if (pos>startpos) {
                result.push_back(str.substr(startpos, pos-startpos));
                continue;
            }
            startpos++;
            pos++;
            while(pos<str.length() && str[pos]!='"') pos++;
        }
        result.push_back(str.substr(startpos, pos-startpos));
        pos++;
    }
    
    return result;
}

#endif /* SeparateString_h */

//
//  ShortestPalindrome.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/16/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef ShortestPalindrome_h
#define ShortestPalindrome_h

#include "DataStructure.h"

using namespace std;

/*
 
 刚刚结束的Google电面，在google呆了8年的貌似国人大哥。
 
 判断一个树是不是另一个的subTree.
 
 shortest palindrome. 求个onsite
 
 链接: https://instant.1point3acres.com/thread/176963 来源: 一亩三分地
 
 
 */

vector<int> getNext(string s) {
    vector<int> result(s.length(), 0);
    for (int j = 1; j < s.length(); j++) {
        int k = result[j-1];
        while(k>0 && s[k]!=s[j]) k = result[k-1];
        if (s[k]==s[j]) k++;
        result[j] = k;
    }
    return result;
}

string ShortestPalindrome(string s) {
    // using kmp
    string rs = s;
    reverse(rs.begin(), rs.end());
    string str = s + "#" + rs;
    vector<int> next = getNext(str);
    int pl = next.back();
    string last = s.substr(pl);
    reverse(last.begin(), last.end());
    return last+s;
}

#endif /* ShortestPalindrome_h */

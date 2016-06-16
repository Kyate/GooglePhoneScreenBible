//
//  GetLongestSubstring.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/15/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef GetLongestSubstring_h
#define GetLongestSubstring_h

#include "DataStructure.h"

using namespace std;

/*
 
 题2 Suppose we have a method “getLongestSubstring(String s, int m)” which finds the longest substring with exactly M distinct characters. Examples: “ABACAAAB” M=2 -> “ACAAA”
 
 链接: https://instant.1point3acres.com/thread/171729 来源: 一亩三分地
 
 */

string getLongestSubstring(string s, int m) {
    unordered_map<char, int> charMap;
    deque<char> myqueue;
    int pos = 0;
    string result;
    int maxLength = 0;
    while(pos<s.length()) {
        if (charMap.find(s[pos])!=charMap.end()) {
            charMap[s[pos]]++;
            myqueue.push_back(s[pos]);
        }
        else {
            charMap[s[pos]]++;
            myqueue.push_back(s[pos]);
            if (charMap.size()>m) {
                while(charMap.size()>m) {
                    char c = myqueue.front();
                    myqueue.pop_front();
                    charMap[c]--;
                    if (charMap[c]==0) charMap.erase(c);
                }
            }
        }
        if (myqueue.size()>maxLength) {
            result = string(myqueue.begin(), myqueue.end());
            maxLength = myqueue.size();
        }
        pos++;
    }
    
    return result;
}


/*
 
 There are now new requirements for getLongestSubstring! The string doesn't fit into memory. Instead you get an object of type BigString:
 
 interface BigString {
     public boolean hasNextChar();
     public char getNextChar();
 }
 
 and return the begin and end 
 
 链接: https://instant.1point3acres.com/thread/171729 来源: 一亩三分地
 
 */

/*
 because the string is too big to fit in the memory, we can't use deque to track the string
 */



#endif /* GetLongestSubstring_h */

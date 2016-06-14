//
//  StringDecompression.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/13/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef StringDecompression_h
#define StringDecompression_h

#include "DataStructure.h"

using namespace std;

string decomHelper(string & s, int & pos) {
    string current;
    int repNum = 0;
    while(pos < s.length() && s[pos]!=']') {
        
        while(pos < s.length() && (s[pos]<'0' || s[pos]>'9') && s[pos]!=']') {
            current.push_back(s[pos]);
            pos++;
        }
        
        if (pos<s.length() && s[pos]==']') {pos++; return current;}
        if (pos<s.length() && s[pos]>='0' && s[pos]<='9') {
            int startpos = pos;
            while(pos<s.length() && s[pos]>='0' && s[pos]<='9') pos++;
            string numStr = s.substr(startpos, pos-startpos);
            repNum = stoi(numStr);
            pos++;
            string next = decomHelper(s, pos);
            for (int i = 0; i < repNum; i++) current+=next;
        }
    }
    
    if (pos<s.length() && s[pos]==']') pos++;
    
    return current;
}

string StringDecompression(string & s) {
    string result;
    int pos = 0;
    while(pos<s.length()){
        if (s[pos]<'0' || s[pos]>'9') {
            result.push_back(s[pos]);
            pos++;
        }
        else {
            result += decomHelper(s, pos);
        }
    }
    
    return result;
}

string StringDecompressionIterative(string & s) {
    stack<string> mystack;
    int pos = 0;
    string result = "";
    while(pos<s.length()){
        if (s[pos]!=']') {
            mystack.push(string(1,s[pos]));
            pos++;
            continue;
        }
        else {
            string current;
            while(!mystack.empty() && mystack.top()!="[") {
                current += mystack.top();
                mystack.pop();
            }
            mystack.pop();
            string num;
            while(!mystack.empty() && mystack.top()>="0" && mystack.top()<="9") {
                num += mystack.top();
                mystack.pop();
            }
            reverse(num.begin(), num.end());
            int numRep = stoi(num);
            string repCurrent;
            for (int i = 0; i < numRep; i++) repCurrent += current;
            mystack.push(repCurrent);
            pos++;
        }
    }
    
    while(!mystack.empty()) {
        result += mystack.top();
        mystack.pop();
    }
    
    reverse(result.begin(), result.end());
    
    return result;
    
}



#endif /* StringDecompression_h */

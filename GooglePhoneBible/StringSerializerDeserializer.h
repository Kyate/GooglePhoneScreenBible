//
//  StringSerializerDeserializer.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/12/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef StringSerializerDeserializer_h
#define StringSerializerDeserializer_h

#include "DataStructure.h"

using namespace std;

/*
 
 第二题： serialize a string array, then deserialize it. 祝大家猴年大吉！！加油加油！！
 
 链接: https://instant.1point3acres.com/thread/157007 来源: 一亩三分地
 
 */

class StringSerializer{
public:
    string serializer(vector<string> & strs) {
        string result;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            int l = s.length();
            result += to_string(l) + " " + s + " ";
        }
        result.pop_back();
        return result;
    }
    
    vector<string> deSerializer(string str) {
        vector<string> result;
        int pos = 0;
        while(pos < str.length()) {
            int startpos = pos;
            while(pos < str.length() && str[pos]!=' ') pos++;
            string numStr = str.substr(startpos, pos-startpos);
            int len = stoi(numStr);
            pos++;
            string current;
            for (int i = 0; i < len; i++) {
                current.push_back(str[pos]);
                pos++;
            }
            result.push_back(current);
            pos++;
        }
        
        return result;
    }
};

#endif /* StringSerializerDeserializer_h */

//
//  StringEncoderDecoder.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/12/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef StringEncoderDecoder_h
#define StringEncoderDecoder_h

#include "DataStructure.h"

using namespace std;

class StringEncoderDecoder {
public:
    string encoder(string s) {
        string result;
        int p = 0;
        while(p<s.length()){
            char c = s[p];
            int num = 0;
            while(p < s.length() && s[p]==c) { p++; num++; }
            
            string last;
            last = c;
            
            if (num>2) result += to_string(num) + "\\x" + last;
            else {
                for (int i = 0; i < num; i++) result += last;
            }

        }
        return result;
    }
    
    string decoder(string s) {
        string result;
        
        int p = 0;
        while(p<s.length()){
            int startp = p;
            while(p<s.length() && s[p]>='0' && s[p]<='9') p++;
            if (p>startp) {
                string numstr = s.substr(startp, p-startp);
                if (p<s.length() && s[p]=='\\') { // encoded
                    int num = stoi(numstr);
                    p+=2;
                    char c = s[p];
                    for (int i = 0; i < num; i++) result.push_back(c);
                }
                else {
                    result += numstr;
                }
                p++;
            }
            else {
                result.push_back(s[p]);
                p++;
            }
        }
        
        return result;
    }
};

#endif /* StringEncoderDecoder_h */

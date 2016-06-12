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

/*
 
 第二轮： 本地小哥 地里的encode decode aaaa->4xa 这里楼主作死了，我就说那 4xa 和aaaa 结果都是4xa 怎么区别？ 对面蒙了，我也傻了，天哪就你嘴
 贱，我是在给自己出题吗？ 果然对面就回了既然你这么diao，你来解决这个问题吧。。。。。。 楼主想了想：1， 全部做成 2x a的形式，但是在不重复字母多的
 时候perform很差 2. 参照编译器用转义符， 变成2\xa， 如果是\输入就变成\\ 对方好像自己在嘟囔一些东西，说转义符是可以，但是会有问题，但是也觉得没
 啥其他办法。
 
 */


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

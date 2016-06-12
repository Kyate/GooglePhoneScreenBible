//
//  MisspellingWord.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/11/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef MisspellingWord_h
#define MisspellingWord_h

#include "DataStructure.h"

using namespace std;


/*
 
 5/6 google 电面 首先给一个字典，比如：{apple, people,...} 再给一个misspelling word，比如：adple，返回它的正确拼写，即 apple 还知道一个
 限制条件，misspelling word只跟原单词有一个字母的区别。如果输入是addle，返回null。如果字数不同，也返回null 还是比较简单的一个题，一开始以为是
 warm up。结果发现这种简单题也是能扯出很多东西的，主要在问题的理解和交流上。比如：是不是需要返回所有的correction，如何降低一些时间复杂度。写完
 代码，又问了下我怎么测试。一共用了30分钟在这道题上。剩下的15分钟就是聊我过去的项目和她现在的team。45分钟准时挂电话。。 上周五电面，今天就给了
 onsite通知，还是很有效率的。
 
 链接: https://instant.1point3acres.com/thread/178030
 来源: 一亩三分地
 
 
 */



vector<string> MisspellingWord(vector<string> & dict, string word) {
    unordered_set<string> myset(dict.begin(), dict.end());
    vector<string> result;
    for (int i = 0; i < word.length(); i++) {
        char c = word[i];
        for (int j = 0; j < 26; j++) {
            char d = 'a' + j;
            if (d==c) continue;
            word[i]=d;
            if (myset.count(word)!=0) result.push_back(word);
        }
        word[i] = c;
    }
    
    return result;
}

#endif /* MisspellingWord_h */

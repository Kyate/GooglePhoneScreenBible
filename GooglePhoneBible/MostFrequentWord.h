//
//  MostFrequentWord.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/14/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef MostFrequentWord_h
#define MostFrequentWord_h

#include "DataStructure.h"

using namespace std;


/*
 
 2. Design a interface for find the running mode in a stream of values: 随时返回most frequent word
 先写函数
 
 get();
 add(String input);
 再问怎么实现这个两个函数：先说了Heap, get()--O(1),add()--O(n)
 
 然后她说优化add(),我说用HashMap+ counter，这样get()-->O(1),add()--->O(1)   然后开始写代码。。
 
 写完了问你觉得这个代码有什么问题，我说multi-threading可能有错，一个在get(), 一个在add(),她说 是的，如果这是single thread
 
 我说可能space太大了,因为有些hot词频会被频繁输入，但是冷门的词语也会一直保存，她说对的 怎么优化？
 
 我说用Tritree，减少HashMap key的存放空间，她说这个key不一定是string，可能是object，
 
 我说group input searching，比如 google， google.inc 表示的可能是一样的意思，只用一个key保存，这样插入时判断similarity，小于一个threshold就认定match，把当前位置+1；
 
 我说用cache。大概说了说，时间就到了，她说you are in the right track，但是我们没时间了。
 
 http://www.1point3acres.com/bbs/thread-188200-1-1.html
 
 
 */



class MostFreqWord {
public:
    MostFreqWord(){};
    
    void add(string s) {
        wordmap[s]++;
        if (wordmap[s]>freq) {
            freq = wordmap[s];
            mostword = s;
        }
    }
    
    string get() {
        return mostword;
    }
    
    unordered_map<string,int> wordmap;
    string mostword;
    int freq = 0;
};

#endif /* MostFrequentWord_h */

//
//  RandomHashMap.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/16/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef RandomHashMap_h
#define RandomHashMap_h

#include "DataStructure.h"

using namespace std;

/*
 
 是个印度小哥，打电话的时间就晚了五分钟，跟我聊了十分钟，最后还提前结束了，做题的时间就很少了。
 
 最后只做了一道题：自己实现一个hashtable的insert，delete，search，getRandom，全部都要O（1）
 
 时间紧迫，而且一开始没明白他的意思，边问边写~就写了这一道，小哥全程比较冷淡，但是还是有回答我的问题的！
 
 也不多想了，应该是要挂了~.
 
 http://www.1point3acres.com/bbs/thread-178900-1-1.html
 
 */


class RandomHashMap {
public:
    RandomHashMap() {};
    
    void insert(int key, int value) {
        valuemap[key] = value;
        keys.push_back(key);
        indexmap[key] = static_cast<int>(keys.size()-1);
    }
    
    void remove(int key) {
        int idx = indexmap[key];
        valuemap.erase(key);
        indexmap.erase(key);
        int lastkey = keys.back();
        indexmap[lastkey] = idx;
        swap(keys[idx], keys[keys.size()-1]);
        keys.resize(keys.size()-1);
    }
    
    int search(int key) {
        return valuemap[key];
    }
    
    int getRandom() {
        
        srand(static_cast<unsigned int> (time(NULL)));
        int rdxidx = rand() % keys.size();
        return keys[rdxidx];
    }
    
    unordered_map<int, int> valuemap;
    unordered_map<int, int> indexmap;
    vector<int> keys;
};

#endif /* RandomHashMap_h */

//
//  FastStructure.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/11/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef FastStructure_h
#define FastStructure_h

#include "DataStructure.h"

using namespace std;

/*
 
 然后给了个第三题，是说如果说要实现一个数据结构，要有insert（）， delete（），medium（），mode（）方法，怎么写。 这题感觉是我最后被拒的原因，
 因为我感觉我没正确理解他的意思。因为这里你用LinkedList（）也好，ArrayList（）也好，总会有一个时间复杂度会很高，后面结束的时候想想可能是想让我
 比较每种结构的优缺点。 我当时是写了一个Arraylist的，他问如果找中位数怎么办，是不是会time complexity很高，然后我说每个结构都会有缺点，是个
 trade off。 最后时间也不够，因为是额外加的，草草结束了这题。 其实答完感觉还可以，不过最后还是挂了。
 
 */


class FastStructure {
public:
    FastStructure() {
        mostNum = 0;
        freq = 0;
    };
    
    void insert(int val) {
        myset.insert(val);
        mymap[val]++;
        freqMap[mymap[val]].insert(val);
        if (mymap[val]>freq) {
            freq = mymap[val];
            mostNum = val;
        }
    };
    
    void del(int val) {
        auto it = myset.find(val);
        if (it!=myset.end()) {
            myset.erase(it);
            freqMap[mymap[val]].erase(val);
            if (freqMap[mymap[val]].size()==0) freqMap.erase(mymap[val]);
            mymap[val]--;
            freqMap[mymap[val]].insert(val);
            freq = freqMap.begin()->first;
            mostNum = *(freqMap.begin()->second.begin());
        }
    };
    
    double median(){
        if (myset.size()%2!=0) {
            auto it = myset.begin();
            advance(it, myset.size()/2);
            int median = *it;
            return static_cast<double>(median);
        }
        else {
            auto it = myset.begin();
            advance(it, myset.size()/2);
            double median1 = static_cast<double>(*it);
            it = next(it);
            double median2 = static_cast<double>(*it);
            return (median1+median2)/2.0;
        }
    };
    
    int mode() {
        return mostNum;
    };
    
private:
    int mostNum;
    int freq;
    multiset<int> myset;
    unordered_map<int,int> mymap;
    map<int, unordered_set<int>, greater<int>> freqMap;
};

#endif /* FastStructure_h */

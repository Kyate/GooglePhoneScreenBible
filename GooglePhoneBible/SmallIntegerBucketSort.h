//
//  SmallIntegerBucketSort.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/19/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef SmallIntegerBucketSort_h
#define SmallIntegerBucketSort_h

#include "DataStructure.h"

using namespace std;

/*
 
 你有 10^12个short integer，然后找出largest top100。最直白的方法就是用heap，分分钟完成。然后我想当然的说可以用hashmap，因为short integer 大概范围是-32000~32000，差不多64000个数，然后怎么
 弄key-value我不太清楚。他说heap is perfect enough，hashmap这个key-value pair不太好搞 - -。第二题就这么结束了。
 
 感觉老美面试还是稳，题比三哥简单。但是自己刚开始有点懵逼，表现的不太好，希望不要受到影响，求Onsite
 
 http://www.1point3acres.com/bbs/thread-187850-1-1.html

 
 */


vector<int> SmallIntegerBucketSort(vector<int> & nums) {
    vector<int> buckets(64001, 0);
    int minimum = 32000;
    int x = 0;
    int pos = 0;
    while(x<100 && pos < nums.size()) {
        int num = nums[pos++];
        buckets[num+minimum]++;
        if (num==32000) x++;
    }
    vector<int> result;
    if (x==100) {
        int pos = buckets.size()-1;
        while(x>0) {
            for (int i = 0; i < buckets[pos]; i++) {
                result.push_back(pos-32000);
                x--;
            }
            pos--;
        }
        std::cout << "Stop before" << std::endl;
        return result;
    }
    else {
        int pos = buckets.size()-1;
        while(result.size()<100 && pos>0) {
            for (int i = 0; i < buckets[pos]; i++) {
                result.push_back(pos-32000);
            }
            pos--;
        }
        return result;
    }
}

vector<int> SmallIntegerHeapSort(vector<int> & nums) {
    priority_queue<int, vector<int>> myqueue;
    for (auto n : nums) {
        myqueue.push(n);
    }
    
    vector<int> result;
    while(result.size()<100 && !myqueue.empty()) {
        result.push_back(myqueue.top());
        myqueue.pop();
    }
    
    return result;
}

#endif /* SmallIntegerBucketSort_h */

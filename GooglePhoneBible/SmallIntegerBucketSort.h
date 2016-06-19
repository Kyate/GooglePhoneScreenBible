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

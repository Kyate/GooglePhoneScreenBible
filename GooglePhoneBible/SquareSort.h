//
//  SquareSort.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/12/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef SquareSort_h
#define SquareSort_h

#include "DataStructure.h"

using namespace std;

/*
 
 美国小哥挺友好的，一直在肯定我说的话，题目不难，气氛还算不错，希望能顺利onsite。
 
 第一题：给一个 sorted Integer array, 返回square后的array.主要是要考虑负数的情况，很多trick的地方比如全都是negative或者全都是positive
 
 链接: https://instant.1point3acres.com/thread/157007 来源: 一亩三分地
 
 */

vector<int> SquareSort(vector<int> & nums) {
    int zeropos = 0;
    while(zeropos < nums.size() && nums[zeropos]<0) zeropos++;
    vector<int> result;
    int neg = zeropos-1, pos = zeropos;
    while(result.size()<nums.size()) {
        if (neg>=0 && pos<nums.size()){
            if (abs(nums[neg])<nums[pos]) {
                result.push_back(nums[neg]*nums[neg]);
                neg--;
            }
            else {
                result.push_back(nums[pos]*nums[pos]);
                pos++;
            }
        }
        else if (neg<0) {
            result.push_back(nums[pos]*nums[pos]);
            pos++;
        }
        else if (pos>=nums.size()) {
            result.push_back(nums[neg]*nums[neg]);
            neg--;
        }
    }
    
    return result;
}

#endif /* SquareSort_h */

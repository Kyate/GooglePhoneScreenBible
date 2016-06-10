//
//  SortedListTwoSum.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/9/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef SortedListTwoSum_h
#define SortedListTwoSum_h

#include "DataStructure.h"

using namespace std;

/*
 第二题 sorted list 2sum
 楼主一看感觉这tm挽回颜面的时间到了！！！解释了下思路然后瞬间秒了，然后walk trough了一下test case。小哥就说没时间了，然后good luck。。
 感觉好虚……第一题居然花了那么久，还是自己太不淡定了，现在只求2面。。bless me....
 大家面试的时候一定要静下心来，不要浮躁。。发挥出自己的正常水平基本就很稳了。祝大家找工顺利。。
 http://www.1point3acres.com/bbs/thread-192578-1-1.html
 
 The given array is sorted
 https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

 If the array is not sorted : use hashmap
 */

vector<int> SortedListTwoSum(vector<int> & nums, int target) {
    vector<int> result;
    int begin = 0, end = nums.size()-1;
    while(begin<end) {
        if (nums[begin]+nums[end]==target) {
            return vector<int>{begin,end};
        }
        if (nums[begin]+nums[end]<target) {
            begin++;
            continue;
        }
        if (nums[begin]+nums[end]>target) {
            end--;
            continue;
        }
    }
    return result;
}

/*
 If the array is not sorted, we need to use hashmap
 */

vector<int> TwoSum(vector<int> & nums, int target) {
    unordered_map<int,int> numMap;
    for (int i = 0; i < nums.size(); i++) {
        numMap[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (numMap.find(target-nums[i])!=numMap.end() && numMap[target-nums[i]]!=i) {
            return vector<int>{i, numMap[target-nums[i]]};
        }
    }
    return vector<int>{};
}

#endif /* SortedListTwoSum_h */

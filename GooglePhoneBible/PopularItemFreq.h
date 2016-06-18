//
//  PopularItemFreq.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/18/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef PopularItemFreq_h
#define PopularItemFreq_h

#include "DataStructure.h"

using namespace std;

/*
 给一个sorted int array 定义popular item的frequency/occurerence 大于N/4
 
 求item 值最小的frequency.
 
 写了个O(N)
 
 说不行。。（第一次没看清题 写了个return popular item value的。。。。）
 
 要更快(<O(N))
 
 想了半天没想出来，，，，然后把frequency的threshold改成N/2
 
 提出了把array切成2份看
 
 然后就卡这了 期间给了我个例子要我找pattern 整个面试45分钟就一道题，可能是没解出来就不让进下一题
 
 面试结束后 想到了。。。。用binary search 在切好的两个array里找到canditate 的index 两个index减一下得出frequency，应该是个O(lgN)的解法。
 
 基本走远了。。。但还是祈祷给我个机会。
 
 http://www.1point3acres.com/bbs/thread-181863-1-1.html
 */

int binarySearch(vector<int> & nums, int candidate, bool start) {
    int left = 0, right = nums.size()-1;
    int result = -1;
    while(left<=right) {
        int mid = left + (right-left)/2;
        if (nums[mid]==candidate) {
            if (start) right = mid-1;
            else left = mid+1;
            result = mid;
        }
        else if (nums[mid]<candidate) left = mid+1;
        else right = mid-1;
    }
    
    return result;
}

int PopularItemFreq(vector<int> & nums) {
    vector<int> popItems;
    int n = nums.size();
    popItems.push_back(nums[n/4]);
    popItems.push_back(nums[n/2]);
    popItems.push_back(nums[3*n/4]);
    int result = INT_MAX;
    for (int i = 0; i < 3; i++) {
        int candidate = popItems[i];
        int startpos = binarySearch(nums, candidate, true);
        int endpos = binarySearch(nums, candidate, false);
        if (endpos-startpos+1 > n/4)result = min(result, endpos-startpos+1);
    }
    return result;
}


#endif /* PopularItemFreq_h */

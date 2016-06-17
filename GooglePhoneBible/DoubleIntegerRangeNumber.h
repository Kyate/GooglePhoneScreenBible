//
//  DoubleIntegerRangeNumber.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/9/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef DoubleIntegerRangeNumber_h
#define DoubleIntegerRangeNumber_h

#include "DataStructure.h"

using namespace std;

/* 
 有一个double类型的数组， 找满足 [a, a + 1) 的最长序列含有的元素的个数， eg. [ 1.0 ,1.3 ,1.5 ,2.3, 3.5],  最长的是[1.0 1.3 1.5], 应该
 返回3。这种小学5年级的数学（数组操作）题对我来说是很困难的， 我直接说暴力解法呗， 然后面试官提醒了下用greedy的方法。 然而代码还是写的很艰
 难。。。大家可以自己写写O(n)的方法练习一下。
http://www.1point3acres.com/bbs/thread-192426-1-1.html
*/

// The following solution runs in O(n^2)
int DoubleIntegerRangeNumber(vector<double> & nums) {
    int maxlength = 1;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        double x = nums[i]+1;
        int end = i+1;
        // If i do binary search here, can be improved to O(nlgn)
        while(end<nums.size() && nums[end]<x) end++;
        if (end-i > maxlength) maxlength = end-i;
    }
    return maxlength;
}

// Can be further improved to O(nlgn) if using binary search
int DoubleIntegerRangeNumberBS(vector<double> & nums) {
    int maxlength = 1;
    double maxX;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        double x = nums[i]+1;
        // binary search version
        int begin = i+1, end = nums.size()-1;
        while(begin<end) {
            int mid = (begin+end)/2;
            if (nums[mid]<x) begin = mid+1;
            else end = mid;
        }
        
        if (begin-i > maxlength) {
            maxlength = begin-i;
            maxX = nums[i];
        }
    }
    return maxlength;
}

// Another O(nlgn) solution
// O(n) after sorted

int DoubleIntegerRangeNumberON(vector<double> & nums) {
    int maxlength = 1;
    sort(nums.begin(), nums.end());
    int i = 0;
    for (int j = 0; j < nums.size(); j++) {
        if (nums[j]<nums[i]+1) continue;
        maxlength = max(maxlength, j-i);
        i++;
    }
    maxlength = max(maxlength, static_cast<int>(nums.size())-i);
    return maxlength;
}


#endif /* DoubleIntegerRangeNumber_h */

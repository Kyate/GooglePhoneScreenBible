//
//  LongestConsecutiveSubarray.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/17/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef LongestConsecutiveSubarray_h
#define LongestConsecutiveSubarray_h

#include "DataStructure.h"

using namespace std;

/*
 
 刚刚面完：本人已经工作了一年了，公司很多印度同事，跟他们交流完全没什么问题，但是今天这个印度哥哥真心口音重，而且开免提有回声我跟他说能不能关免提他说他没带耳机。。。然后我就听了45分钟自己的回声。。。
 
 这位小哥一来先介绍自己的组，然后完全没问我任何东西直接上题：
 
 第一题：给一个array,找出最长的连续片段   比如：[5,2,3,4,5,8,9]   就是2，3，4，5，返回4
 
 我觉得这道题很眼熟，但是忘了最优解了，所以最开始写了一个看似两层循环但是time O(n)，space O(n)的。但是小哥觉得还可以优化，所以开始提示我了，然后我在自己代码的基础上改了改最后改成了
 time:O(n),space:O(1)最优解
 
 */

int LongestConsecutiveSubarray(vector<int> & nums) {
    int result = 1, dp = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i]==nums[i-1]+1) {
            dp+=1;
            result = max(result, dp);
        }
        else {
            dp = 1;
        }
    }
    return result;
}

#endif /* LongestConsecutiveSubarray_h */

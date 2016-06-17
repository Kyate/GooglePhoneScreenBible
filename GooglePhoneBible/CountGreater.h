//
//  CountGreater.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/16/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef CountGreater_h
#define CountGreater_h

#include "DataStructure.h"

using namespace std;

/*
 星期一电话面试。是一个印度哥哥。之前觉得印度哥哥没什么，因为学校印度人很多，工作地方也是印度人，口音不是那么难以理解啊。但是这次，我晕。不知道是我理解有问题还是怎么着。anyway，上题。
 
 给一个integer array，让你求比array  (where i is from 0 to array.length() - 1) 大的maximum number of element i.e 就是求每个integer右边比它大的个数，求最大值。
 
 e.g.
 A = [2 3 0 1 5 7 4]
 4 3 4 3 1 0 0
 answer is 4
 不知道是楼主理解能力差还是他表达不好，弄明白题意就整了好长时间。写码也磕磕绊绊。
 
 印度哥哥提示Divide and conquer... 楼主做的不好，已经挂了。
 
 和这个题很类似，大家可以看看。祝你们好运！求大米！
 
 补充内容 (2016-3-17 00:21):
 
 老印可能想要的是这个解法。merge sort 大家可以去看看。
 
 https://leetcode.com/discuss/73256/mergesort-solution
 
 祝你们好运
 
 http://www.1point3acres.com/bbs/thread-178983-1-1.html
 
 */


int bitSum(int i, vector<int> & bitree) {
    int sum = 0;
    while(i>0) {
        sum += bitree[i];
        i-=i&(-i);
    }
    return sum;
}

void bitAdd(int i, vector<int> & bitree) {
    while(i<bitree.size()) {
        bitree[i]+=1;
        i+=i&(-i);
    }
}

vector<int> countGreater(vector<int> & nums) {
    vector<int> numCopy(nums);
    sort(numCopy.begin(), numCopy.end(), greater<int>());
    vector<int> bitree(nums.size()+1, 0);
    vector<int> result(nums.size(), 0);
    unordered_map<int,int> sortMap;
    for (int i = 0; i < numCopy.size(); i++) {
        sortMap[numCopy[i]] = i+1;
    }
    for (int i = nums.size()-1; i>=0; i--) {
        result[i] = bitSum(sortMap[nums[i]]-1, bitree);
        bitAdd(sortMap[nums[i]], bitree);
    }
    
    return result;
}

#endif /* CountGreater_h */

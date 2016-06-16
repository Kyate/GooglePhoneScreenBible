//
//  MissingRanges.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/15/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef MissingRanges_h
#define MissingRanges_h

#include "DataStructure.h"

using namespace std;

/*
 
 Leetcode 原题， missing range 。因为没有做过 电面也很紧张，所以45分钟只有时间做一道题。
 
 所以说 leetcode 收费题目还是应该去花钱做一做的。
 
 http://www.1point3acres.com/bbs/thread-190925-1-1.html
 
 */

string genStr(int from, int to) {
    string result;
    if (to-from >0) {
        result += to_string(from);
        result += "->";
        result += to_string(to);
    }
    else {
        result += to_string(from);
    }
    return result;
}

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> result;
    if (nums.size()==0) {
        result.push_back(genStr(lower,upper));
        return result;
    }
    if (lower < nums[0]) result.push_back(genStr(lower, nums[0]-1));
    for (int i = 0; i < nums.size()-1; i++) {
        int curr = nums[i], next = nums[i+1];
        if (next-curr>1) result.push_back(genStr(curr+1, next-1));
    }
    int last = nums.back();
    if (upper-last>0) result.push_back(genStr(last+1, upper));
    return result;
}

#endif /* MissingRanges_h */

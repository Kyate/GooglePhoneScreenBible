//
//  TwoSumClosestModel.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/14/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef TwoSumClosestModel_h
#define TwoSumClosestModel_h

#include "DataStructure.h"

using namespace std;

/*
 
 一个整数数组，找sum最接近0的一对数。2Sum Closest Pair。 求onsite。(:з)∠) 烙印全程不怎么说话，搞得我心里很虚。是福不是祸，是祸躲不过。(:з)∠)
 
 链接: https://instant.1point3acres.com/thread/165509 来源: 一亩三分地
 
 */

vector<int> TwoSumClosestPair(vector<int> & nums) {
    vector<int> result(2);
    sort(nums.begin(), nums.end());
    int mDist = INT_MAX;
    int l = 0, r = nums.size()-1;
    while(l<r) {
        if (nums[l]+nums[r]==0)
            return vector<int>{nums[l], nums[r]};
        if (abs(nums[l]+nums[r])<mDist) {
            result[0] = nums[l], result[1] = nums[r];
            mDist = abs(nums[l]+nums[r]);
        }
        if (nums[l]+nums[r]>0) r--;
        else l++;
    }
    
    return result;
}

#endif /* TwoSumClosestModel_h */

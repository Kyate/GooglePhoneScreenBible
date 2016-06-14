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

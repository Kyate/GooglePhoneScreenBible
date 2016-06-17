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

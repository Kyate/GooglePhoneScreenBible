//
//  TwentyFour.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/19/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef TwentyFour_h
#define TwentyFour_h

#include "DataStructure.h"

using namespace std;

bool twentyFourHelper(vector<int> nums, int target);

bool TwentyFour(vector<int> & nums, int target) {
    return twentyFourHelper(nums, target);
}

bool twentyFourHelper(vector<int> nums, int target) {
    
    if (nums.size()==1 && nums[0]==target) return true;
    
    for (int i = 0; i < nums.size()-1; i++) {
        int add = nums[i] + nums[i+1];
        int substract = nums[i]- nums[i+1];
        int multiply = nums[i] * nums[i+1];
        vector<int> innerpart{add, substract, multiply};
        if (nums[i+1]!=0) {
            int devide = nums[i] / nums[i+1];
            innerpart.push_back(devide);
        }
        
        for (int k = 0; k < innerpart.size(); k++) {
            vector<int> next;
            for (int j = 0; j < i; j++) {
                next.push_back(nums[j]);
            }
            next.push_back(innerpart[k]);
            for (int j = i+2; j < nums.size(); j++) next.push_back(nums[j]);
            bool current = twentyFourHelper(next, target);
            if (current) return true;
        }
    }
    
    return false;
}

#endif /* TwentyFour_h */

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

/*
 
 本人小白，这次电面对本人来说挺难的，很紧张。对面是个白人小哥，感觉是第一次当面试官，听得出他也挺紧张。我是一路跟着小哥的提示走的，最后写了伪代码，还不一定对。目测已跪。
 
 给出一个 list of int, the target, 输出这个 list 中所用的数能否通过4则运算 得到 target。
 boolean EvaluatesTo(list numbers, int target)
 [2 3 6 9] -> 75
 (2+3)*(6+9) = 75 return true
 [2 3 6 9] －> 11 return false
 顺便求米，谢谢
 
 http://www.1point3acres.com/bbs/thread-186172-1-1.html
 
 */

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

//
//  CombinationSum.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/17/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef CombinationSum_h
#define CombinationSum_h

#include "DataStructure.h"

using namespace std;


/*
 
 第二题：
 
 Football:
 {2, 3, 6, 7, 8}
 9 = { 7 + 2, 6 + 3, 3 + 3 + 3, ... }
 don’t need both 6+3 and 3+6
 其实就是leetcode combination sum的原题，给你一个数组，一个target，求所有的组合方式。 上来先和小哥讨论了下输入项的可能性，然后噼啪一顿代码又出来了。小哥给了个case，然后我就把代码的执行过程给写了
 出来，小哥还比较满意。然后就问我可能出现的一些corner case，然后我就讲可能空数组啊，target value可能是0啊，可能有负数啊，等等。
 
 关于这个几个corener case的输出，跟小哥探讨了一番，关于返回{}还是{{}}讨论了一下，结果就是根据实际的要求来做，小哥表示认可。讨论到负数的可能性，发现代码会进入死循环，果断表示不能允许duplicate的存
 在，小哥也恩恩表示赞同了。
 
 */

void csumHelper(vector<vector<int>> & result, vector<int> & current, vector<int> & nums, int target, int p);

vector<vector<int>> CombinationSum(vector<int> & nums, int target) {
    vector<vector<int>> result;
    vector<int> current;
    csumHelper(result, current, nums, target, 0);
    return result;
}

void csumHelper(vector<vector<int>> & result, vector<int> & current, vector<int> & nums, int target, int p) {
    if (target<0) return;
    if (target==0) {
        result.push_back(current);
        return;
    }
    for (int i = p; i < nums.size(); i++) {
        if (target-nums[i]>=0) {
            current.push_back(nums[i]);
            csumHelper(result, current, nums, target-nums[i], i);
            current.pop_back();
        }
            
    }
}

#endif /* CombinationSum_h */

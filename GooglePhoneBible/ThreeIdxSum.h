//
//  ThreeIdxSum.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/12/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef ThreeIdxSum_h
#define ThreeIdxSum_h

#include "DataStructure.h"

using namespace std;

/*
 
 一个小时前的面经，就问了一个问题，回头想想很简单，不过答得不咋好。 :-( 面试官小哥特别好，很轻松，前面瞎扯扯，让我先问问题，说后面写算法的时候会耽误点时间，所以先问问题，（满善解人意的）。
 
 废话不多说，上题：
 
 Give you an array of integers: A
 
 Goal is to find three indexes (i,j,k) such that A[i] + A[j] == A[k]
 
 For Example:
 A = [ -5, 10, 1, 8, -2 ]
 
 10 + -2 == 8
 
 Good answer: i=1, j=4, k=3
 也不知道那时候脑子怎么抽了，一直在回想刷过的题目，搞复杂了，好可惜。
 
 希望将来面试的人好好审题。 Good Luck Everyone!
 
 */

vector<vector<int>> ThreeIdxSum(vector<int> & nums) {
    unordered_map<int,vector<int>> mymap;
    for (int i = 0; i < nums.size(); i++) {
        mymap[nums[i]].push_back(i);
    }
    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++) {
            vector<int> current;
            int x = nums[i]+nums[j];
            if (mymap.find(x)!=mymap.end()) {
                current = vector<int>{i,j};
                for (auto k : mymap[x]) {
                    if (k!=i && k!=j) {
                        current.push_back(k);
                        result.push_back(current);
                        current.pop_back();
                    }
                }
            }
        }
    }
    
    return result;
}

#endif /* ThreeIdxSum_h */

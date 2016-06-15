//
//  LongestConsecutiveArray.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/15/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef LongestConsecutiveArray_h
#define LongestConsecutiveArray_h

#include "DataStructure.h"

using namespace std;

/*
 
 第二次电面：两题都是lc原题，lc298 (Longest consecutive sequence in BT) 和lc128 (longest consecutive sequence in array)。各位自己去看解法吧！
 
 祝大家找工作顺利！！！
 
 http://www.1point3acres.com/bbs/thread-192677-1-1.html
 
 */

int longestConsecutive(vector<int>& nums) {
    unordered_map<int,int> mymap;
    unordered_map<int,int> resultmap;
    for (auto n : nums) mymap[n]++;
    int result = 1;
    while(!mymap.empty()) {
        int current = mymap.begin()->first;
        int currentlength = 0;
        int x = current;
        while(mymap.find(x)!=mymap.end()) {
            mymap[x]--;
            if (mymap[x]==0) mymap.erase(x);
            currentlength++;
            x--;
        }
        if (resultmap.find(x)!=resultmap.end()) {
            currentlength += resultmap[x];
        }
        result = max(result, currentlength);
        resultmap[current] = max(resultmap[current], currentlength);
    }
    
    return result;
}

#endif /* LongestConsecutiveArray_h */

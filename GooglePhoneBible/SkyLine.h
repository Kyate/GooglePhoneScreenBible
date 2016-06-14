//
//  SkyLine.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/14/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef SkyLine_h
#define SkyLine_h

#include "DataStructure.h"

using namespace std;


/*
 
 第二题Skyline类似的问题，似乎不是用的最优解法但是面试官还算满意。 后面聊了一些工作环境以及他们组的工作内容。今天下午面试的，希望能过！
 
 链接: https://instant.1point3acres.com/thread/154428 来源: 一亩三分地
 
 */

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    multimap<int,int> coord;
    for (auto v : buildings) {
        coord.emplace(v[0], v[2]); // left corner of the building
        coord.emplace(v[1],-v[2]); // right corner of the building
    }
    
    int x = -1, y = 0; // previous
    multiset<int> heights{0};
    vector<pair<int,int>> corners;
    for (auto p : coord) {
        
        // p.first != x ----------> all corners at x have been processed, and we can find the maximum height at x
        // corners.rbegin()->second != y ---------> avoid the repeat like (2,3), (5,3) in the result
        
        if ((x>=0) && (p.first != x) && (corners.empty() || corners.rbegin()->second != y)) {
            corners.push_back(pair<int,int>(x,y));
        }
        
        if (p.second >= 0) {
            heights.insert(p.second);
        }
        else {
            heights.erase(heights.find(-(p.second)));
        }
        
        x = p.first;
        y = *heights.rbegin();
    }
    
    if (!corners.empty()) corners.push_back(pair<int,int>(x, 0));
    
    return corners;
}

#endif /* SkyLine_h */

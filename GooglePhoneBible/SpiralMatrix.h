//
//  SpiralMatrix.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/9/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef SpiralMatrix_h
#define SpiralMatrix_h

#include "DataStructure.h"

/*
 第一个 lc 54 spiral matrix
 稍微改动了下成了x,y坐标的image上色，解释题目解释了半天，其实换汤不换药。这个时候加上前面找doc和看小哥演示链接的时间，快磨叽过去十分钟了，但是自
 己非常sb的紧张的一比，结果半个小时才断断续续写出来，中途还想打开leetcode抄一波，结果居然忘了题目的名字了。。崩盘。。只好默默回去写……而且中间还
 把x,y坐标搞反了，自己卡了半天，小哥显然非常的无语。。写完了以后竟然过去半个多小时了，感觉还有bug，不过就小哥也没care。。
*/

/*
 https://leetcode.com/problems/spiral-matrix/
 http://www.1point3acres.com/bbs/thread-192578-1-1.html

 */

vector<int> SpiralMatrix(vector<vector<int>> & matrix) {
    vector<int> result;
    int m = matrix.size();
    if (m==0) return result;
    int n = matrix[0].size();
    
    // this vector is used to indicate how long should we go along this direction
    // along column or along row
    vector<int> steps{n, m-1};
    int row = 0, col = -1;
    vector<vector<int>> dirts{{0,1}, {1,0}, {0,-1}, {-1,0}};
    int direction = 0; // index of direction
    while(steps[direction%2]) {
        int d = direction%4;
        for (int s = 0; s < steps[direction%2]; s++ ) {
            row += dirts[d][0];
            col += dirts[d][1];
            result.push_back(matrix[row][col]);
        }	
        steps[direction%2]--;
        direction++;
    }
    return result;
    
}

#endif /* SpiralMatrix_h */

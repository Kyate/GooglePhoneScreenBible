//
//  RangeMaximumQuery.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/18/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef RangeMaximumQuery_h
#define RangeMaximumQuery_h

#include "DataStructure.h"

using namespace std;


/*
 
 Using Sparse Table
 Query Time O(1)
 Preprocessing Time O(nlogn)
 Space O(nlogn)
 
 */

class RangeMaximumQuery {
public:
    RangeMaximumQuery(vector<int> & nums) : mynums(nums) {
        int N = static_cast<int>(nums.size());
        double cols = log2(static_cast<double>(N));
        int icols = static_cast<int>(cols);
        M = vector<vector<int>>(N, vector<int>(icols, 0));
        
        for (int i = 0; i < N; i++) {
            M[i][0] = i;
        }
        for (int j = 1; 1<<j <= N; j++) {
            for (int i = 0; i + (1<<j) -1 < N; i++) {
                if (nums[M[i][j-1]]>nums[M[i+ (1<<(j-1))][j-1]]) {
                    M[i][j] = M[i][j-1];
                }
                else {
                    M[i][j] = M[i+(1<<(j-1))][j-1];
                }
            }
        }
        
    };
    
    int query(int i, int j) {
        if (j>mynums.size()-1) j = static_cast<int>(mynums.size()-1);
        int k = log2(j-i+1);
        if (mynums[M[i][k]] >= mynums[M[j-(1<<k)+1][k]])
            return mynums[M[i][k]];
        else 
            return mynums[M[j-(1<<k)+1][k]];
    }
    
    
    vector<vector<int>> M;
    vector<int> mynums;
};

/*
 Using Segmentation Tree
 
 
 */

class RangeMaximumQuerySegTree {
public:
    RangeMaximumQuerySegTree(vector<int> & nums) : mynums(nums) {
        int N = static_cast<int>(mynums.size());
        int height = static_cast<int>(ceil(log2(N)));
        int treesize = 2 * static_cast<int>(pow(2, height)) - 1;
        segTree.resize(treesize, INT_MIN);
        initialize(0, 0, N-1);
    }
    
    void initialize(int idx, int start, int end) {
        if (start==end) {
            segTree[idx] = start;
        }
        else {
            initialize(2*idx+1, start, (start+end)/2);
            initialize(2*idx+2, (start+end)/2+1, end);
            if (mynums[segTree[2*idx+1]] > mynums[segTree[2*idx+2]]) {
                segTree[idx] = segTree[2*idx+1];
            }
            else {
                segTree[idx] = segTree[2*idx+2];
            }
        }
    }
    
    int query(int i, int j) {
        int end = static_cast<int>(mynums.size()-1);
        int maxIdx = query(0, 0, end, i, j);
        return mynums[maxIdx];
    }
    
    int query(int idx, int start, int end, int i, int j) {
        if (i > end || j < start) return -1;
        if (start>=i && end<=j) return segTree[idx];
        int p1 = query(2*idx+1, start, (start+end)/2, i, j);
        int p2 = query(2*idx+2, (start+end)/2+1, end, i, j);
        if (p1==-1) return p2;
        if (p2==-1) return p1;
        if (mynums[p1]>=mynums[p2]) return p1;
        else return p2;
        
    }
    
    vector<int> segTree;
    vector<int> mynums;

};



#endif /* RangeMaximumQuery_h */

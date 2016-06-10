//
//  GridMaxQuery.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/10/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef GridMaxQuery_h
#define GridMaxQuery_h

#include "DataStructure.h"

using namespace std;

/**********************************************************
直接上题
write a grid class.
 
1. set the height and width
2. set value at arbitrary point
3. get max value of the grid

一开始问我用什么结构存这个grid， 我说vector，他问为什么，我说可以random access。
然后做题，先直接brute-force， 2问O(1), 3问O(n^2)。他说取最大值太慢了，我就用了个priority_queue（他还问了我priority_queue<int, vector<
 int>, less<int>>参数的意思，说他不太清楚。。），2问变O(n^2)，3问变O(1)。他说不行，set value太慢了，我说创建一个vector<int> 
 maxVallue(m, 0)，记录每行的最大值，这样2问复杂度是O(n), 3问是O(m)。-google 1point3acres
他又否了我的想法，说如果是一个1*1000的grid复杂度还是很高。我说binary search tree可以都O(logn)，他说有duplicate怎么办，后来我说用multiset
 ，这样都是O(logn)并且可以重复。（PS: 因为太久没用multiset+时间太赶，用法写错了。。。multiset是不能改变值的，只能找到了然后删了再加新的，当时
 没时间了就跟set一样直接ms[grid[i][j]] = newValue了。。。应该是ms.erase(ms.find(grid[i][j])); ms.insert(newValue)。悲剧）
 
这一道题就把时间用光了，前前后后写了4种方法，最后那个也不知道达到他的要求没

**********************************************************/

/* Method 1: Using multiset
 Time: getMax O(1) set O(logN)
 */

class grid {
public:
    grid(int m, int n): rows(m), cols(n) {
        mgrid = vector<vector<int>>(m, vector<int>(n,0));
    };
    
    void set(int i, int j, int val) {
        int oldval = mgrid[i][j];
        if (myset.find(oldval)==myset.end()) {
            myset.insert(val);
        }
        else {
            auto it = myset.find(oldval);
            myset.erase(it);
            myset.insert(val);
        }
        mgrid[i][j] = val;
    };
    
    int getMax() {
        return *myset.rbegin();
    }
    multiset<int> myset;
    vector<vector<int>> mgrid;
    int rows, cols;
};

/* Method 2: Using segment tree
 Time: getMax O(1) set O(logN)
 */

class SegmentTreeGrid {
public:
    SegmentTreeGrid(int m, int n) : rows(m),cols(n) {
        grid.resize(m*n, 0);
        int height = static_cast<int>(ceil(log2(m*n)));
        int treesize = 2 * static_cast<int>(pow(2, height)) - 1;
        segTree.resize(treesize, INT_MIN);
    }
    
    pair<int,int> IdxToCoord(int idx) {
        return make_pair(idx/cols, idx%cols);
    }
    
    int CoordToIdx(pair<int,int> & coord) {
        return coord.first * cols + coord.second;
    }
    
    void setSegtree(int idx, int low, int high, int val, int pos) {
        if (idx<low || idx>high) return;
        if (low==high) {
            segTree[pos] = val;
            return;
        }
        int mid = low + (high-low)/2;
        setSegtree(idx, low, mid, val, pos*2+1);
        setSegtree(idx, mid+1, high, val, pos*2+2);
        segTree[pos] = max(segTree[2*pos+1], segTree[2*pos+2]);
    }
    
    void set(int i, int j, int val) {
        pair<int,int> coord = make_pair(i,j);
        int idx = CoordToIdx(coord);
        setSegtree(idx, 0, rows*cols-1, val, 0);
        grid[idx]=val;
    }
    
    int getMax(){
        return segTree[0];
    }
    
    vector<int> segTree;
    vector<int> grid;
    int rows, cols;
};

#endif /* GridMaxQuery_h */

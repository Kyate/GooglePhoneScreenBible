//
//  RandomMatrixGenerator.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/18/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef RandomMatrixGenerator_h
#define RandomMatrixGenerator_h

#include "DataStructure.h"

using namespace std;

/*
 
 先聊了一下research然后就开始做题
 
 第一题是random generator的题，比如给100*100的matrix，初始为全零，让随机把其中p（比如百分之六十）的值设为1
 
 第二题是tree level order traversal，按层输出，只用打印出来就可以了
 
 然后就让我问问题了
 
 求人品啊希望大家都好运
 
 http://www.1point3acres.com/bbs/thread-188230-1-1.html
 
 */

void MatrixRandomGenerator(vector<vector<int>> & matrix, double p) {
    int rows = matrix.size();
    if (rows==0) return;
    int cols = matrix[0].size();
    int total = rows*cols;
    vector<int> idx(total, 0);
    iota(begin(idx), end(idx), 0);
    srand(time(NULL));
    int number = total * p;
    for (int i = 0; i < number; i++) {
        int idxidx = rand() % total--;
        int curr = idx[idxidx];
        int m = curr/cols;
        int n = curr%cols;
        matrix[m][n] = 1;
        swap(idx[idxidx], idx[idx.size()-1]);
    }
    
    return;
}

#endif /* RandomMatrixGenerator_h */

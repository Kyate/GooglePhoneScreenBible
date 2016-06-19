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

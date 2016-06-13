//
//  main.cpp
//  GooglePhoneBible
//
//  Created by Jerome on 6/9/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#include <iostream>
#include "DataStructure.h"
#include "OutputHelper.h"

#include "ThreeIdxSum.h"

using namespace std;


int main(int argc, const char * argv[]) {
    
    vector<int> nums{-5, 10, 1, 8, -2};
    
    vector<vector<int>> result = ThreeIdxSum(nums);
    
    output2DMatHelper(result);


    return 0;
}

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

#include "SquareSort.h"

using namespace std;


int main(int argc, const char * argv[]) {
    
    vector<int> nums{-9, -7, -6, -5, -2, -1};
    
    vector<int> result = SquareSort(nums);
    
    output1DVectorHelper(result);


    return 0;
}

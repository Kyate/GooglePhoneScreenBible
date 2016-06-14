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
#include <mutex>
#include <thread>

#include "TwoSumClosestModel.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<int> n1{-6, 0, -10, 2, 13, 12, 5, 3, 8, 7};
    
    vector<int> result = TwoSumClosestPair(n1);
    
    output1DVectorHelper(result);

    return 0;
}

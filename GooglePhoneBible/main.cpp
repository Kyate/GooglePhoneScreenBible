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

#include "BigNumberAdd.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<int> n1{9,5,3,8,7};
    vector<int> n2{5,8,6,5,9};
    
    vector<int> x = BigNumberAdd(n1, n2);
    
    output1DVectorHelper(x);


    return 0;
}

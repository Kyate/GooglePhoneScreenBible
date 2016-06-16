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

#include "IsStrobogrammatic.h"

using namespace std;


int main(int argc, const char * argv[]) {
    

    vector<string> result = strobogrammaticInRange("1000");
    
    output1DVectorHelper(result);
    
    return 0;
}

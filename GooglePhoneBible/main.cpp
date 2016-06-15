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

#include "numberABC.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    int A = 34567, B = 45678;
    
    int result = MinimumNumberABC(A, B);
    
    std::cout << result << std::endl;

    return 0;
}

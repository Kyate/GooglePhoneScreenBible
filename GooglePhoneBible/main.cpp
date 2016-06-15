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

#include "BCDAddOne.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    string result = BCDAddOne("10011001");
    
    std::cout << result << std::endl;
    
    return 0;
}

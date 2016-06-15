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

#include "RobotMoving.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    RobotMoving robot;
    
    pair<int,int> coord = robot.moveWithRepBlock("FF2(FFR)");
    
    std::cout << coord.first << " " << coord.second << std::endl;
    
    return 0;
}

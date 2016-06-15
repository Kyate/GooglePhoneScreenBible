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

#include "MinMaxRecentSystem.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    MinMaxRecentSystem system;
    system.add(1, 4);
    std::cout << system.getMin() << " " << system.getMax() << " " << system.getRecent() << std::endl;
    system.add(4, 7);
    std::cout << system.getMin() << " " << system.getMax() << " " << system.getRecent() << std::endl;
    system.add(2, 5);
    std::cout << system.getMin() << " " << system.getMax() << " " << system.getRecent() << std::endl;
    system.update(2, 8);
    std::cout << system.getMin() << " " << system.getMax() << " " << system.getRecent() << std::endl;
    system.remove(4);
    std::cout << system.getMin() << " " << system.getMax() << " " << system.getRecent() << std::endl;
    return 0;
}

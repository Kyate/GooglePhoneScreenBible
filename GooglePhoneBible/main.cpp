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

#include "MovingAverageDataStream.h"

using namespace std;

int main(int argc, const char * argv[]) {

    MovingAverage mov(3);
    
    std::cout << mov.next(1) << " ";
    std::cout << mov.next(10) << " ";
    std::cout << mov.next(3) << " ";
    std::cout << mov.next(5) << " ";
    std::cout << mov.next(0) << " ";
    std::cout << mov.next(2) << " ";
    std::cout << mov.next(1) << " ";

    return 0;
}

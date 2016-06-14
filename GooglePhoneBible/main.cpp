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

#include "MovingAverageDataStream.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    
    MovingAverage ma(3);
    std::thread t1(&MovingAverage::next, &ma, 1);
    t1.join();
    std::thread t2(&MovingAverage::next, &ma, 3);
    t2.join();
    std::thread t3(&MovingAverage::next, &ma, 4);
    std::thread t4(&MovingAverage::next, &ma, 0);
    std::thread t5(&MovingAverage::next, &ma, 10);
    std::thread t6(&MovingAverage::next, &ma, 2);

    
    
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    
    //    std::cout << ma.next(1) << std::endl;
//    std::cout << ma.next(3)<< std::endl;
//    std::cout << ma.next(7)<< std::endl;
//    std::cout << ma.next(2)<< std::endl;
//    std::cout << ma.next(6)<< std::endl;


    return 0;
}

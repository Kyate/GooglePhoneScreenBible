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

#include "GridMaxQuery.h"

using namespace std;

int main(int argc, const char * argv[]) {

    SegmentTreeGrid mygrid(5,5);
    
    mygrid.set(1,1,5);
    mygrid.set(2,2,10);
    mygrid.set(3,3,10);
    mygrid.set(4,4,15);
    std::cout << mygrid.getMax() << std::endl;    //15
    mygrid.set(4,4,20);
    std::cout << mygrid.getMax() << std::endl;    //20
    mygrid.set(4,4,15);
    std::cout << mygrid.getMax() << std::endl;    //15
    mygrid.set(4,4,5);
    mygrid.set(3,3,5);
    std::cout << mygrid.getMax() << std::endl;    //10
    mygrid.set(1,1,50);
    std::cout << mygrid.getMax() << std::endl;    //50
    mygrid.set(1,1,0);
    mygrid.set(2,2,0);
    mygrid.set(3,3,0);
    mygrid.set(4,4,0);
    std::cout << mygrid.getMax() << std::endl;    //0
    return 0;
}

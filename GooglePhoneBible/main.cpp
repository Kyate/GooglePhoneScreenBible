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

#include "SkyLine.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> buildings{{0,2,3}, {2,5,3}, {2,6,5}};
    
    vector<pair<int,int>> result = getSkyline(buildings);

    return 0;
}

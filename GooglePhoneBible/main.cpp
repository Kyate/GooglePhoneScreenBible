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

#include "GroupFiveConsecutive.h"

using namespace std;


int main(int argc, const char * argv[]) {
    

    vector<int> nums{4,5,3,1,2,5,4};
    
    bool result = GroupFiveConsecutive(nums);
    
    std::cout << result << std::endl;

    return 0;
}

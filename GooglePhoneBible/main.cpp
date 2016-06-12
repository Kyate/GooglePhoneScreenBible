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

#include "DifferentChar.h"

using namespace std;


int main(int argc, const char * argv[]) {
    
    string s2 = "appl", s1 = "apppl";
    
    char one = DifferentCharUnordered(s1, s2);
    
    std::cout << one << std::endl;

    return 0;
}

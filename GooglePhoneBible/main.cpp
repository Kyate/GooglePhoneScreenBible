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

#include "FastStructure.h"

using namespace std;


int main(int argc, const char * argv[]) {
    

    FastStructure test;
    
    test.insert(1);
    test.insert(2);
    test.insert(3);
    test.insert(4);
    test.insert(4);
    test.insert(5);
    test.insert(5);
    test.insert(5);
    test.del(5);
    test.del(5);
    
    double med = test.median();
    
    int mod = test.mode();

    return 0;
}

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

#include "PrintAllPrimes.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    vector<int> prime = PrintAllPrimes(100);
    output1DVectorHelper(prime);
    
    return 0;
}

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

#include "AddOneToLargeNumber.h"

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> x{1,3,9,7,9};
    vector<int> result = AddOneToLargeInteger(x);
    output1DVectorHelper(result);

    return 0;
}

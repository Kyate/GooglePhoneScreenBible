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

#include "MisspellingWord.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<string> dict{"apple", "people", "main","leetcode", "add", "adc"};
    
    vector<string> result = MisspellingWord(dict, "adb");
    
    output1DVectorHelper(result);

    return 0;
}

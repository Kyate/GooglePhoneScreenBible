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

#include "GetLongestSubstringDistinct.h"

using namespace std;


int main(int argc, const char * argv[]) {
    
    string s = "ABACAAAB";
    
    string result = getLongestSubstring(s, 2);
    
    cout << result << endl;
    
    
    return 0;
}

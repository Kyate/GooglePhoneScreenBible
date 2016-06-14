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

#include "StringDecompression.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    
    string s = "2[ab3[d]uo]2[cc]";
    
    string result = StringDecompressionIterative(s);
    
    cout << result << std::endl;


    return 0;
}

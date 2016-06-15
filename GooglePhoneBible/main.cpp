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

#include "MostFrequentWord.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    MostFreqWord freq;
    freq.add("abc");
    
    std::cout << freq.get() << std::endl;

    freq.add("abc");
    freq.add("jjj");
    freq.add("jjj");
    freq.add("jjj");
    freq.add("abc");
    freq.add("abc");
    std::cout << freq.get() << std::endl;
    
    return 0;
}

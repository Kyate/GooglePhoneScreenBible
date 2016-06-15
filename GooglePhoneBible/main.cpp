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

#include "SortStringsFavorite.h"

using namespace std;


int main(int argc, const char * argv[]) {

    vector<string> strs{"aab","baa","caa","aaa","aaaa"};
    
    SortWithFavorite(strs, "zh");
    
    output1DVectorHelper(strs);

    
    return 0;
}

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

#include "StringEncoderDecoder.h"

using namespace std;


int main(int argc, const char * argv[]) {
    

    string s = "yyyyy\\\\";
    
    std::cout << "original " << s << std::endl;
    
    StringEncoderDecoder sde;
    string result = sde.encoder(s);
    
    std::cout << "encoded  " << result << std::endl;
    
    string r2 = sde.decoder(result);
    std::cout << "decoded  " << r2 << std::endl;

    return 0;
}

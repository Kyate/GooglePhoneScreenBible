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

#include "TreeInorderConnect.h"

using namespace std;


int main(int argc, const char * argv[]) {

    TreeDoubleLinkNode * root = new TreeDoubleLinkNode(1);
    TreeDoubleLinkNode * n2 = new TreeDoubleLinkNode(2);
    TreeDoubleLinkNode * n3 = new TreeDoubleLinkNode(3);
    TreeDoubleLinkNode * n4 = new TreeDoubleLinkNode(4);
    TreeDoubleLinkNode * n5 = new TreeDoubleLinkNode(5);
    TreeDoubleLinkNode * n6 = new TreeDoubleLinkNode(6);
    
    root->left = n2;
    root->right = n3;
    
    n2->left = n4;
    n3->left = n5;
    n3->right = n6;
    
    InorderConnectRecursive(root); 
    
    return 0;
}

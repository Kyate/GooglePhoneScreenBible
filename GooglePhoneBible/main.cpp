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

#include "SeparateString.h"

using namespace std;

TreeNode * ConstructTree() {
    TreeNode * root1 = new TreeNode(1);
    TreeNode * n2 = new TreeNode(2);
    TreeNode * n3 = new TreeNode(3);
    TreeNode * n4 = new TreeNode(4);
    TreeNode * n5 = new TreeNode(5);
    TreeNode * n6 = new TreeNode(6);
    
    root1->left = n2;
    root1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n5->left = n6;
    
    return root1;
}


int main(int argc, const char * argv[]) {
    
    string s = "abc def iuo\"program edede with exit\"lushen tai shen";
    vector<string> result = SeparateString(s);
    
    output1DVectorHelper(result);
    
    return 0;
}

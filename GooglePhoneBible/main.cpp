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

#include "PlayerRoleCount.h"

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
    
    UpdateLog l1(1, "mike", "fighter");
    UpdateLog l2(2, "john", "wizard");
    UpdateLog l3(5, "mike", "wizard");
    UpdateLog l4(8, "mike", "knight");
    
    PlayLog p1(3, "mike");
    PlayLog p2(6, "mike");
    PlayLog p3(5, "john");
    PlayLog p4(9, "mike");
    
    vector<UpdateLog> updates{l1,l2,l3,l4};
    vector<PlayLog> players{p1,p2,p3,p4};
    
    vector<pair<string, int>> result = CountRoleNumber(updates, players);
    
    for (auto p : result) {
        std::cout << p.first << " " << p.second << std::endl;
    }
    
    return 0;
}

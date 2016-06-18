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

#include "FourWayStop.h"

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
    
    Lane * lane1 = new Lane();
    Lane * lane2 = new Lane();
    Lane * lane3 = new Lane();
    Lane * lane4 = new Lane();
    
    FourWayStop fws;
    
    Car * car1 = new Car(1);
    fws.arriveCar(car1, lane1);
    
    Car * car2 = new Car(2);
    fws.arriveCar(car2, lane1);
    
    Car * car3 = new Car(3);
    fws.arriveCar(car3, lane1);
    
    Car * car4 = new Car(4);
    fws.arriveCar(car4, lane1);
    
    Car * car5 = new Car(5);
    fws.arriveCar(car5, lane1);
    
    Car * car6 = new Car(6);
    fws.arriveCar(car6, lane2);
    
    Car * car7 = new Car(7);
    fws.arriveCar(car7, lane3);
    
    Car * car8 = new Car(8);
    fws.arriveCar(car8, lane4);
    
    Car * car9 = new Car(9);
    fws.arriveCar(car9, lane2);
    
    int i = 0;
    
    while(i < 9) {
        Car * c = fws.getNextCar();
        std::cout << c->carid << std::endl;
    }
    
    return 0;
}

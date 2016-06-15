//
//  RobotMoving.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/15/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef RobotMoving_h
#define RobotMoving_h


#include "DataStructure.h"

using namespace std;


class RobotMoving {
public:
    RobotMoving() {
        x = 0, y = 0;
    }
    
    void moveForward(int direction, int & x, int & y, int rep) {
        if (direction%4==0) y+=rep;
        else if (direction%4==1) x+=rep;
        else if (direction%4==2) y-=rep;
        else if (direction%4==3) x-=rep;
        return;
    }
    
    void moveRight(int direction, int & x, int & y, int rep) {
        if (direction%4==0) x+=rep;
        if (direction%4==1) y-=rep;
        if (direction%4==2) x-=rep;
        if (direction%4==3) y+=rep;
        return;
    }
    
    pair<int,int> move(string command) {
        int repeat = 1;
        for (int i = 0; i < command.length(); i++) {
            char c = command[i];
            if (c<'0' || c>'9') { // not number
                if (c=='F') moveForward(direction, x, y, repeat);
                else if (c=='R') {
                    moveRight(direction, x, y, repeat);
                    direction++;
                }
                std::cout << x << " " << y << std::endl;
                if (x<0 || y<0) {
                    return make_pair(-1,-1);
                }
            }
            else {
                int start = i;
                while(i<command.length() && command[i]>='0' && command[i]<='9') i++;
                string numStr = command.substr(start, i-start);
                repeat = stoi(numStr);
                i--;
                std::cout << "hold" << std::endl;
            }
        }
        
        return make_pair(x,y);
    }
    
    pair<int,int> moveWithRepBlock(string command) {
        int pos = 0;
        int rep = 1;
        string result;
        while(pos<command.length()) {
            char c = command[pos];
            if (c<'0'||c>'9') {
                result.push_back(c);
                pos++;
            }
            else {
                int start = pos;
                while(pos<command.length() && command[pos]>='0' && command[pos]<='9') pos++;
                string numStr = command.substr(start, pos-start);
                if (command[pos]=='(') {
                    int innerstart = pos;
                    while(pos<command.length() && command[pos]!=')') pos++;
                    string innercommand = command.substr(innerstart, pos-innerstart);
                    for (int i = 0; i < stoi(numStr); i++)
                        result += innercommand;
                    pos++;
                }
                else {
                    result+=numStr;
                }
            }
        }
        
        return move(result);
    }
    
    int direction = 0;
    int x,y;
};

#endif /* RobotMoving_h */

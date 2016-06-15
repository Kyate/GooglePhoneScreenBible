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

/*
 
 一上来就直接贴题目做。面试官是个口音不重的印度小哥，不过给我的感觉他还比较nice。
 
 让设计一个机器人，实现前进，向右转以及输出当前位置的功能（面经题，之前是乌龟来着），一开始在原点坐标，不能去负的坐标，去的话报错。
 
 follow1：输入指令，如 FFRRF3R，F就是前进，R就是向右转，2R就是RRR。输出这个指令之后所处的位置。
 
 follow2：在指令里面会出现2（FFR）这种情况，就是FFRFFR。 就问了这个就没了，在写follow2的时候感觉和小哥的作法有出入，他让我怎么怎么写，但是我不
 太理解，改来改去消耗了些时间。最后还是按着我的代码写完了……
 
 40分钟结束问问题。 在google doc上面，感觉撤销有点诡异。不知道是不是同步的问题，当时想回到之前的代码，怎么也回不去了。 感觉自己写的有点慢，题目
 挺简单的，但也没让面试官很满意。感觉直接给onsite希望不大了……诶，不过还是求个人品吧~
 
 链接: https://instant.1point3acres.com/thread/176255 来源: 一亩三分地
 
 */

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

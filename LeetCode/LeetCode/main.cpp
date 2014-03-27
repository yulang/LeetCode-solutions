//
//  main.cpp
//  LeetCode
//
//  Created by 余 浪 on 14-3-27.
//  Copyright (c) 2014年 余 浪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "evaluate_reverse_polish_notation.h"

using namespace std;
int main(int argc, const char * argv[])
{
    int rst;
    vector<string> input;
    input.push_back("2");
    input.push_back("1");
    input.push_back("+");
    input.push_back("3");
    input.push_back("*");
    rst = evalRPN(input);
    cout<< rst << endl;
    return 0;
}


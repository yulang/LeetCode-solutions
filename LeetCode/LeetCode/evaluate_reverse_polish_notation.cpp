//
//  evaluate_reverse_polish_notation.cpp
//  LeetCode
//
//  Created by 余 浪 on 14-3-27.
//  Copyright (c) 2014年 余 浪. All rights reserved.
//

#include "evaluate_reverse_polish_notation.h"


#define NUM 0
#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4

int checkTokenType(string s);

int evalRPN(vector<string> &tokens) {
    //push the token into stack in reverse order
    vector<int> num_stack;
    vector<int>::iterator stack_pt;
    int rst = 0,loprd, roprd;
    for (vector<string>::iterator iter = tokens.begin(); iter != tokens.end(); iter++) {
        //push stack
        if (checkTokenType(*iter) == NUM) {
            const char *tmp = string(*iter).data();
            num_stack.push_back(atoi(tmp));
        } else {
            stack_pt = num_stack.end() - 1;
            roprd = *stack_pt--;
            loprd = *stack_pt;
            num_stack.pop_back();
            num_stack.pop_back();
            if (checkTokenType(*iter) == ADD) {
                loprd += roprd;
            } else if (checkTokenType(*iter) == SUB) {
                loprd -= roprd;
            } else if (checkTokenType(*iter) == MUL) {
                loprd *= roprd;
            } else if (checkTokenType(*iter) == DIV) {
                loprd /= roprd;
            } else
                cout << "ILLEGAL OP" << endl;
            num_stack.push_back(loprd);
        }
    }
    
    stack_pt = num_stack.begin();
    return *stack_pt;
}

int checkTokenType(string s) {
    if (s == "*") {
        return MUL;
    } else if (s == "/") {
        return DIV;
    } else if (s == "+") {
        return ADD;
    } else if (s == "-") {
        return SUB;
    } else {
        return NUM;
    }
}
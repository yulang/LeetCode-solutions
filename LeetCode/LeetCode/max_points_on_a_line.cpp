//
//  max_points_on_a_line.cpp
//  LeetCode
//
//  Created by 余 浪 on 14-3-27.
//  Copyright (c) 2014年 余 浪. All rights reserved.
//

#include "max_points_on_a_line.h"

int maxPoints(vector<Point> &points) {
    
    return 1;
}

int gcd(int a, int b){
    return a?a/abs(a)*abs(gcd(b%a, a)):b;
}
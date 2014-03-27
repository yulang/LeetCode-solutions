//
//  useful_function.cpp
//  LeetCode
//
//  Created by 余 浪 on 14-3-27.
//  Copyright (c) 2014年 余 浪. All rights reserved.
//

#include "useful_function.h"

int _gcd(int a, int b){
    return a?a/abs(a)*abs(_gcd(b%a, a)):b;
}

vector<string> _split(string str,string pattern)
{
    string::size_type pos;
    vector<string> result;
    //    vector<string>::iterator iter;
    str.erase(0,str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
    if (str.empty()) {
        result.push_back(str);
        return result;
    }
    
    str+=pattern;//扩展字符串以方便操作
    int size=str.size();
    
    for(int i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            string s=str.substr(i,pos-i);
            //            iter = result.end() -1;
            s.erase(0,s.find_first_not_of(" "));
            s.erase(s.find_last_not_of(" ") + 1);
            if (s != " " && !s.empty()) {
                result.push_back(s);
            }
            
            i=pos+pattern.size()-1;
        }
    }
    return result;
}
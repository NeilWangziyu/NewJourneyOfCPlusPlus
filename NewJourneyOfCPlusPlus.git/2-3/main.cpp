//
//  main.cpp
//  2-3
//
//  Created by 王子昱 on 2019/11/24.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int ival = 1024, i2 = 2048;
    int  &refval = ival;
//    int &refVal2; it is wrong, reference must be initilized
    int i3 = 1024, &ri = i3;
    int &r3 = i3, &r4 = i2;
    
    int *ip1, *ip2;
    double dp, *dp2;
    int ip1_v = 42;
    ip1 = &ip1_v;
    
    cout << " *ip1 " << *ip1 << endl;
    cout << " &ip1 " <<&ip1 << endl;

    
//    null pointer
    int *p1 = nullptr;
    int *p2 = 0;
    int *p3 = NULL;
    
//    任何非0指针对应的条件值都是true
    
//    void* 可以存放任意对象的地址
    double obj = 3.14, *pd = &obj;
    void *pv = &obj;
    pv = pd;
    
    int i = 42;
    int *pi = &i;
    *pi = *pi * *pi;
    cout << "the value of pi: " <<*pi << endl;
//    2-4 const
    const int bufSize = 256;
//    bufSize  = 1;
    const int ci = 1024;
    const int &rp = ci;
    cout << "rp:" << rp << endl;
    
    const double pie = 3.14;
//    double *ptr = &pie;
    const double *cptr = &pie;
//    只有指向常量的指针才能使用->pointer to const
//    const pointer
    int errNumb = 0;
    int *const curErr = &errNumb;
    const double pie2 = 3.14159;
    const double *const pip = &pie2;
    
    constexpr int mf = 20;
    constexpr int limit = mf + 1;
//    constexpr int sz = size();
    
    const int *p = nullptr;
    constexpr int *q = nullptr;
//    p:pointer to a const
//    q: a const pointer
//    for the constexpr make it's target a top-level const
    
    
    
    
    
    return 0;
}

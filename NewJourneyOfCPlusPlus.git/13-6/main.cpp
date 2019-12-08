//
//  main.cpp
//  13-6
//
//  Created by 王子昱 on 2019/12/6.
//  Copyright © 2019 王子昱. All rights reserved.
//  这一章也tm太难了吧


#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct X{
    int i;
    string s;
};
struct hasX{
    X mem;
};


class Foo
{
public:
    Foo sorted() &&;
    Foo sorted() const &;
    
private:
    vector<int> data;
    
};

Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const &
{
    Foo ret(*this);
    sort(ret.data.begin(), ret.data.end());
    return ret;
}




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    rvalue reference
    int i = 32;
    
    int &r = i;
    const int &r3 = i *42;
    int &&rr2 = i *42;
    cout << rr2 << endl;        //rvalue rr2, 可以绑定到一个表达式上
    
    int &&rr1 = 42;
    int &&rr3 = std::move(rr1);      //should use std::move, for conflict
    
    cout << rr3 << endl;
    
    X x, x2 = std::move(x);
    hasX hx, hx2 = std::move(hx);
    
    
    
    return 0;
}

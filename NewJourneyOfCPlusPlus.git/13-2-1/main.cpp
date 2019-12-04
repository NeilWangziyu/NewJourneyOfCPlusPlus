//
//  main.cpp
//  13-2-1
//
//  Created by 王子昱 on 2019/12/4.
//  Copyright © 2019 王子昱. All rights reserved.
//  行为像值的类

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class HasPtr{
public:
    HasPtr(const string &s = string()):
    ps(new string(s)), i(0) { }
    
    HasPtr(const HasPtr &p):
    ps(new string(*p.ps)), i(p.i) { }
    
    HasPtr& operator=(const HasPtr &);
    ~HasPtr()   { delete ps;}
    
private:
    string *ps;
    int i;
    
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

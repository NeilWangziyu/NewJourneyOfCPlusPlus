//
//  main.cpp
//  13-2-2
//
//  Created by 王子昱 on 2019/12/4.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HasPtr{
public:
    
//    构造函数分配新的string和新的计数器，将计数器置位1
    HasPtr(const string &s = string()):
    ps(new string(s)), i(0), use(new std::size_t(1)) { }
//    拷贝构造函数拷贝所有三个数据成员，并递增计数器
    HasPtr(const HasPtr &p):
    ps(p.ps), i(p.i), use(p.use) { ++*use;}
    
    HasPtr& operator=(const HasPtr &);
    ~HasPtr();
    
    friend void swap(HasPtr&, HasPtr&);
    
private:
    string *ps;
    int i;
    std::size_t *use;
    
};

HasPtr::~HasPtr()
{
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    HasPtr p1("hiya");
    HasPtr p2(p1);
    HasPtr p3(p2);
    
    return 0;
}

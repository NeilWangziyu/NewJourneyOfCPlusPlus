//
//  main.cpp
//  13-1
//
//  Created by 王子昱 on 2019/12/3.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Sales_data{
public:
    
    //    这是一个拷贝构造函数声明
    Sales_data() = default;
    
    Sales_data(const Sales_data&);
    ~Sales_data() {};
//    ~Sales_data() = default;
    Sales_data& operator=(const Sales_data&);
private:
    string bookNo;
    int units_sold;
    double revenue;
    
};

Sales_data&
Sales_data::operator=(const Sales_data &rhs)
{
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
    return  *this;
}

class Foo
{
public:
    ~Foo();
    // 析构函数
};

class HasPtr
{
public:
    
    HasPtr(const HasPtr&);
    
    HasPtr(const string &s = string()):
    ps(new string(s)), i(0) {}
    
    int i_value()
    {
        return i;
    }
    
    string ps_value()
    {
        return *ps;
    }
    
private:
    string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr &rhs):
ps(rhs.ps), i(rhs.i)    {   }

struct NoCop
{
    NoCop() = default;
    NoCop(const NoCop&) = delete;
    NoCop &operator=(const NoCop&) = delete;
    ~NoCop() = delete;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    
    //    直接初始化和拷贝初始化
    string dots(10, '.');
    string s(dots); //直接
    string s2 = dots;   //拷贝
    string null_book = "12345-1233";    //拷贝
    string nines = string(100, '9');     //拷贝
    //    用 = 定义时会发生
    
    HasPtr test("nwe");
    HasPtr new_test = test;
    
    cout << new_test.i_value() << endl;
    cout << new_test.ps_value() << endl;

    
    
    return 0;
}

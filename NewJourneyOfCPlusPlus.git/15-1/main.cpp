//
//  main.cpp
//  15-1
//
//  Created by 王子昱 on 2019/12/9.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Quote{
public:
    Quote() =default;
    Quote(const string &book, double sales_price) :
    bookNo(book), price(sales_price) { }
    
    string isbn() const { return bookNo;}
    
    virtual double net_price(size_t n) const
    {return n * price;}
    
    virtual ~Quote() = default;     //析构函数动态绑定
    
private:
    string bookNo;
protected:
    double price = 0.0;
    
};

class Bulk_Quota:public Quote
{
public:
    Bulk_Quota() = default;
    Bulk_Quota(const string&, double, size_t, double);
    
    double net_price(size_t) const override;
    
private:
    size_t min_Qty = 0;
    double discont = 0.0;
};

Bulk_Quota::Bulk_Quota(const string& book, double p,  size_t qty, double disc):
Quote(book, p), min_Qty(qty), discont(disc) { }
//dynamic binding : 运行时绑定

double Bulk_Quota::net_price(size_t cnt) const
{
    if (cnt >= min_Qty) {
        return cnt * ( 1 - discont) * price;
    }
    else
        return cnt * price;
}


double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

struct B  {
    virtual void f1(int) const;
    virtual void f2();
    void f3();
};

struct D1: B
{
    void f1(int) const override;
//    void f2(int) override;  //wrong！
//    void f3() override;     //wrong
//    void f4() override; //wrong
};

struct D2 : B{
    void f1(int) const final;   //不允许后续的其他类覆盖f1(int)
};

struct D3 : D2
{
    void f2();
//    void f1(int) const;     //wrong! alreagy final
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    Quote item;
    Bulk_Quota bulk;
    Quote *p = &item;
    p = &bulk;
    
    Quote &r = bulk;
    // derived-to-base
    
    // final: 防止被继承
    
    Quote base("09-01", 50);
    print_total(cout , base, 10);
    
    Bulk_Quota dericed("011-11", 50, 5, 0.19);
    print_total(cout, dericed, 40);
    
    
    return 0;
}

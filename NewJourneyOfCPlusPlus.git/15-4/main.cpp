//
//  main.cpp
//  15-4
//
//  Created by 王子昱 on 2019/12/9.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <memory>

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

class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const string& book, double price, size_t qty, double disc):
    Quote(book, price), quantity(qty), discont(disc) { }
    
    double net_price(size_t) const = 0;
protected:
    size_t quantity = 0;
    double discont = 0.0;
};

class Bulk_quote : public Disc_quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double price, size_t qty, double disc):
    Disc_quote(book, price, qty, disc) { }
    
    double net_price(size_t) const override;
    
};

double Bulk_quote::net_price(size_t n) const
{
    if (n >= quantity) {
        return n * ( 1 - discont) * price;
    }
    else
        return n * price;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<shared_ptr<Quote>> basket;
    basket.push_back(make_shared<Quote>("0-12-1", 50));
    basket.push_back(make_shared<Bulk_quote>("9-1-1-1", 50, 10, 0.25));
    
    cout << basket.back()->net_price(15) << endl;
//    if use vector to manage class, use the pointer

    return 0;
}

//
//  main.cpp
//  15-8
//
//  Created by 王子昱 on 2019/12/9.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Quote{
public:
    Quote() =default;
    Quote(const string &book, double sales_price) :
    bookNo(book), price(sales_price) { }
    
    virtual Quote* clone() const & { return new Quote(*this);}
    virtual Quote* clone() && { return new Quote(std::move(*this));}
    
    
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
    
    Bulk_Quota* clone() const & {return new Bulk_Quota(*this);}
    Bulk_Quota* clone() const && { return new Bulk_Quota(std::move(*this));}
    
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


class Basket{
public:
    void add_item(const std::shared_ptr<Quote> &sale)
    {
        items.insert(sale);
    }
    
    void add_item(const Quote& sale)
    {
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }
    
    void add_item(const Quote&& sale)
    {
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }
    
//    void add_item(const Quote& sale);
//    void add_item(Quote** sale);
    
    
    double total_receipt(std::ostream&) const;
    
private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }
    
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*>
    items{compare};
};

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

double Basket::total_receipt(std::ostream &os) const
{
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << " Total sale:" << sum <<  endl;
    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

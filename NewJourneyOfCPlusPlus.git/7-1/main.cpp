//
//  main.cpp
//  7-1
//
//  Created by 王子昱 on 2019/11/28.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
#include "Sales_data.h"
using namespace std;


double Sales_data::avg_price() const
{
    if (units_sold) {
        return revenue/units_sold;
    }
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
//    return this pointer
}

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
    << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);
//    在类的外部定义构造函数
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    return 0;
}

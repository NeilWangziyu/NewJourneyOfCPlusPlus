//
//  Sales_data.h
//  NewJourneyOfCPlusPlus.git
//
//  Created by 王子昱 on 2019/11/28.
//  Copyright © 2019 王子昱. All rights reserved.
//

#ifndef Sales_data_h
#define Sales_data_h
#include <iostream>
#include <string>
using namespace std;

class Sales_data
{
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend istream &read(istream&, Sales_data&);
    friend ostream &print(ostream&,const Sales_data&);
    
public:
    
    //    initiate function
    Sales_data() = default;
    //    默认构造函数
    Sales_data(const string &s): bookNo(s) {};
    Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n){};
    //    构造函数初始值列表
    //    函数体都是空的
    Sales_data(std::istream &);
    
    std::string isbn() const { return this->bookNo;}
    //    this is not necessary
    //    const member function
    
    Sales_data& combine(const Sales_data&);
    

private:

    double avg_price() const;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    //    default value
};

Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data);
istream &read(istream&, Sales_data&);

#endif /* Sales_data_h */

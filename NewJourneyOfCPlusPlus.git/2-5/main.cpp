//
//  main.cpp
//  2-5
//
//  Created by 王子昱 on 2019/11/24.
//  Copyright © 2019 王子昱. All rights reserved.
//
#include <string>
#include <iostream>
using namespace std;

struct Sales_data{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    //    类内初始值 in-class initializer
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //    type alias
    typedef double wages;
    typedef wages base, *p;
    
    //    using SI = Sales_item;
    //    c++ 11 new feature
    wages hourly, weekly;
    
    //    auto
    auto i = 0, *pi = &i;
    cout << *pi << endl;
    
    //decltype
    const int ci = 0, &cj = ci;
    decltype(ci) x = 0;
    //    x is a const int
    decltype(cj) y = x;
    //    y is a const int &
    cout << "x is " << x << endl;
    
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    cout << "c start is " <<c << endl;
    
    ++c;
    cout << "d start is " <<d << endl;
    
    ++d;
    cout << "c is " <<c << endl;
    cout << "d is " <<d << endl;
    
    Sales_data data1, data2;
    
    double price = 0;
    
    cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    cout << "book1 revenue: " << data1.revenue<< endl;
    
    
    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;
    cout << "book2 revenue: " << data2.revenue<< endl;
    
    if(data1.bookNo == data2.bookNo)
    {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        cout << data1.bookNo << " " << totalCnt << " " << totalRevenue;
        if (totalCnt != 0) {
            cout << totalRevenue / totalCnt << endl;
        }
        else
        {
            cout << "no sales" << endl;
        }
    }
    else
    {
        cout << "this books are differnt" << endl;
    }
    
    return 0;
//    note in header, commonly dont use "using"
}

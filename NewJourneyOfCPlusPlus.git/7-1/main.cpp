//
//  main.cpp
//  7-1
//
//  Created by 王子昱 on 2019/11/28.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

#include "Sales_data.h"
#include "Screen.h"

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

inline
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
//in class, named inline
{
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;
    return *this;
}

Windows_mgr::ScreenIndex
Windows_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}

void Windows_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Sales_data mydata;
    
    
    Screen myScreen(10, 10, '$');
    
    
    myScreen = myScreen.move(4, 0);
    myScreen = myScreen.set('t');
    char get_c = myScreen.get(4, 0);
    
    cout << get_c << endl;
    
    get_c = myScreen.get(4, 1);
    cout << get_c << endl;

    myScreen.display(cout);
    
    myScreen.move(4, 5).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
    
    return 0;
}

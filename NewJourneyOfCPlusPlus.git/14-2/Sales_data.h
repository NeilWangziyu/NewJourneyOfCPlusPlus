//
//  Sales_data.h
//  NewJourneyOfCPlusPlus.git
//
//  Created by 王子昱 on 2019/12/8.
//  Copyright © 2019 王子昱. All rights reserved.
//

#ifndef Sales_item_h

#define Sales_item_h

#include <iostream>
#include <string>

using namespace std;

class Sales_item
{
    // these declarations are explained section 7.2.1
    friend istream& operator >> (istream&, Sales_item&);
    friend ostream& operator << (ostream&, const Sales_item&);
    friend bool operator < (const Sales_item&, const Sales_item&);
    friend bool operator==(const Sales_item&, const Sales_item&);
    
public:
     // constructors are explained in section 7.1.4
    Sales_item()= default;
    Sales_item(const string & book):bookNo(book) {}
    Sales_item(istream &is) {
        is >> *this;
    }
public:
    Sales_item& operator += (const Sales_item&);
    string isbn() const { return bookNo;}
    double avg_price() const;

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
// used in chapter 10
inline
bool compareIsbn(const Sales_item &lhs, const Sales_item &rhs)
{ return lhs.isbn() == rhs.isbn(); }

// nonmember binary operator: must declare a parameter for each operand
Sales_item operator+(const Sales_item&, const Sales_item&);

inline bool
operator==(const Sales_item &lhs, const Sales_item &rhs)
{
    // must be made a friend of Sales_item
    return lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue &&
           lhs.isbn() == rhs.isbn();
}

inline bool
operator!=(const Sales_item &lhs, const Sales_item &rhs)
{
    return !(lhs == rhs); // != defined in terms of operator==
}

// assumes that both objects refer to the same ISBN
Sales_item& Sales_item::operator+=(const Sales_item& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// assumes that both objects refer to the same ISBN
Sales_item
operator+(const Sales_item& lhs, const Sales_item& rhs)
{
    Sales_item ret(lhs);  // copy (|lhs|) into a local object that we'll return
    ret += rhs;           // add in the contents of (|rhs|)
    return ret;           // return (|ret|) by value
}



std::istream&
operator>>(std::istream& in, Sales_item& s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    // check that the inputs succeeded
    if (in)
        s.revenue = s.units_sold * price;
    else
        s = Sales_item();  // input failed: reset object to default state
    return in;
}

std::ostream&
operator<<(std::ostream& out, const Sales_item& s)
{
    out << s.isbn() << " " << s.units_sold << " "
        << s.revenue << " " << s.avg_price();
    return out;
}

double Sales_item::avg_price() const
{
    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
}


#endif /* Sales_item_h */
//from:
//https://github.com/amidvidy/learning/blob/master/cpp-primer/Sales_item.h

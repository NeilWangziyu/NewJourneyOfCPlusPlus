//
//  main.cpp
//  14-2
//
//  Created by 王子昱 on 2019/12/8.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>

//#include "Sales_data.h"
//#include "StrVec.h"

using namespace std;

//struct absInt {
//    int operator()(int val) const
//    {
//        return val < 0 ? -val : val;
//        }
//};


//class PrintStringOur{
//    public:
//        PrintStringOur(ostream &o = cout, char c = ' '):
//        os(o), sep(c) { }
//
//        void operator()(const string &s) cosnt {os << s << sep;}
//
//    private:
//        ostream &os;
//        char sep;
//};
//

class ShorterString
{
public:
    bool operator()(const string &s1, const string &s2) const
    {
        return s1.size() < s2.size();
    }
};

int add(int i, int j) { return i + j; }
auto mod = [](int i, int l) { return i % l; };
struct divide{
    int operator()(int denominator, int divisor)
    {
        return denominator / divisor;
    }
};

class smallInt
{
public:
    smallInt(int i = 0) :val(i)
    {
        if (i < 0 || i > 255) {
            throw std::out_of_range("Bad smallint value");
        }
    }
    operator int() const { return val;}
    
//    explicit operator int() const {return val;}   显式

private:
    size_t val;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //
    //        int i = -42;
    //        absInt absobj;
    //        int ui = absobj(i);
    //        cout << ui << endl;
    //
    
    plus<int> intadd;
    negate<int> intNegate;
    int sum = intadd(10, 20);
    cout << sum << endl;
    sum  = intNegate(intadd(10, 20));
    cout << sum << endl;
    
    //    function table
    map<string, int(*)(int, int)> binops;
    binops.insert({"+", add});
    
    
    function<int(int, int)> f1 = add;
    function<int(int, int)> f2 = divide();
    function<int(int, int)> f3 = [](int i, int j) { return  i * j;};
    
    cout << f1(4, 2) << " " << f2(4, 5) << " " << f3(5, 6) << endl;
    
    //    map<string, function<int(int, int)>> binops2;
    
    //    use the fucntion map binops2
    map<string, function<int(int, int)>> binops2 = {
        {"+", add},
        {"-", std::minus<int>()},
        {"/", divide()},
        {"*", [](int i, int j) { return i*j;}},
        {"%", mod}
    };
    
    cout << binops2["+"](10, 5) << endl;
    
    cout << binops2["-"](10, 5) << endl;
    
    cout << binops2["/"](10, 5) << endl;
    
    int (*fp)(int, int) = add;
    
    binops2.insert({"+", fp});
    
    smallInt si;
    si = 4;
    si + 3;
    cout << si << endl;
    return 0;
}

//
//  main.cpp
//  6-2
//
//  Created by 王子昱 on 2019/11/26.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void myswap(int* x, int* y)
{
//    6.2.1
    int tem = *x;
    *x = *y;
    *y = tem;
    return;
}
void myswap2(int& x, int& y)
{
    int tem = x;
    x = y;
    y = tem;
    return;
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}


string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
//    const string &s is important
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size()) {
                ret = i;
            }
            ++occurs;
        }
    }
    return ret;
}

bool is_sentence(const string &s)
{
    string::size_type ctr = 0;
//    ctr is the occurs
    return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;
}

//below is same:
void print(const int*);
void print(const int[]);
void print(const int[10]);


void print(const char *cp)
{
//    使用标记指定数组长度
    if (cp) {
        while (*cp) {
            cout << *cp++;
        }
    }
    cout << '\n';
    return;
}

void print(const int *beg, const int *end)
{
//    使用STL
    while (beg != end) {
        cout << *beg++ << endl;
    }
    return;
}

void print(const int ia[], size_t size)
{
//    显式传递形参
    for (size_t i = 0; i != size; ++i) {
        cout << ia[i] << endl;
    }
    return;
}

void print(int (&arr)[10])
{
//    数组引用形参
    for (auto elem:arr) {
        cout << elem << endl;
    }
}

void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg) {
        cout << *beg << endl;
    }
    return;
}

//void error_msg(error_code e, initializer_list<string> il)
//{
//    cout << e.message() << ": ";
//    for (const auto &elem : il) {
//        cout << elem << " ";
//    }
//    cout << endl;
//    return;
//}

void make_sure_same(const int x, const int y)
{
    if (x == y) {
        cout << "fine!" << endl;
        error_msg({"make_sure_same", "okay"});
    }
    else
    {
        error_msg({"make_sure_same", "not", "same"});

    }
}

//void make_sure_same(const char x, const char y)
//{
//    the class shoud define yourself
//    if (x == y) {
//        cout << "fine!" << endl;
//        error_msg(error_code(0), {"make_sure_same", "okay"});
//    }
//    else
//    {
//        error_msg(error_code(42),{"make_sure_same", "not", "same"});
//
//    }
//}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}


//return lvalue


int main(int argc, const char * argv[]) {
    int x = 1, y = 2;
    cout << "first: \nx:" << x << " , y:" << y << endl;
    int *xp = &x;
    int *yp = &y;
    myswap(xp, yp);
    cout << "second:\nx:" << x << " , y:" << y << endl;
    
    int &xt = x;
    int &yt = y;
    myswap2(xt, yt);
    
    cout << "second:\nx:" << x << " , y:" << y << endl;
    
    string s = "Ifind_char in my programmer in there";
    string &sr = s;
    
    char c = 'i';
    string::size_type occurs;
    string::size_type &occursr = occurs;
    auto first_find = find_char(sr, c, occursr);
    cout << "first time find " << c << " is at " << first_find << ", \nTotal occurs " << occurs << " Times \n";
    
    char ca[] = "c++++";
    print(ca);
    
    int j[3] = {0, 5, 7};
    print(begin(j), end(j));
    
    print(j, end(j) - begin(j));
    
    int k[10] = {1,2,3,4,5,6,7,8,9,10};
    print(k);
    
//  initializer_list
    cout << "\n";

    int x1 = 0;
    int x2 = 0;
    int x3 = 1;
    
    make_sure_same(x1, x2);
    cout << "\n";
    make_sure_same(x1, x3);
    
    return 0;
}

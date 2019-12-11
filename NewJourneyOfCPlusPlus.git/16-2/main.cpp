//
//  main.cpp
//  16-2
//
//  Created by 王子昱 on 2019/12/11.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <sstream>
using namespace std;

template <typename T>
string debug_rep(const T &t)
{
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T> string debug_rep(T *p)
{
    ostringstream ret;
    ret << "pointer:" << p;
    if (p) {
        ret << " " << debug_rep(*p);
    }
    else
    {
        ret << " null pointer";
    }
    return ret.str();
}

//  --------------
string debug_rep(const string &s)
{
    return  '"' + s + '"';
}

string debug_rep(char *p)
{
    return debug_rep(string(p));
}

string debug_rep(const char *p)
{
    return debug_rep(string(p));
}


//  ------
// 可变参数模板
template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest);


template <typename ... Args> void g(Args ... args)
{
    cout << sizeof...(Args) << endl;    //类型参数的数目
    cout << sizeof...(args) << endl;    //函数参数的数目
}

//  ----
//
template<typename T>
ostream &print(ostream &os, const T& t)
{
    return os << t;
}

// 包括两个包拓展 ...
template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)
{
    os << t <<", ";         //打印第一个实参
    return print(os, rest...);      //递归调用，打印后续的实参
}

template <typename... Args>
ostream &errorMsg(ostream &os, const Args&... rest)
{
    return print(os, debug_rep(rest)...);
}

//  -------------
//  template specialization
template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) {
        return -1;
    }
    if (v2 < v1) {
        return 1;
    }
    return 0;
}

template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}

template <> // 模板特例化
int compare(const char* const &p1, const char* const &p2)
{
    return strcmp(p1, p2);
}





int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    string s("hi");
    cout << debug_rep(s) << endl;
    cout << debug_rep(&s) << endl;
    cout << "-----------------------------------\n";
    
    int i = 99;
    string t = "ilove";
    print(cout, i, t, 45);
    cout << endl;
    
    return 0;
}

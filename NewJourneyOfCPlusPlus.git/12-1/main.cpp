//
//  main.cpp
//  12-1
//
//  Created by 王子昱 on 2019/12/2.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>

using namespace std;

class strBlob
{
public:
    typedef std::vector<string>::size_type size_type;
    strBlob();
    strBlob(initializer_list<string> il);
    size_type size() const{return data->size();}
    bool empty() const {return data->empty();}
    void push_back(const string &t) { data->push_back(t);}
    void pop_back();
    
    string & front();
    string & back();
    
    
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};
//note:make sure construction function is defined
strBlob::strBlob():data(make_shared<vector<string>>()){ };
strBlob::strBlob(initializer_list<string> il):
data(make_shared<vector<string>>(il)){};

void strBlob::check(size_type i , const string &msg) const
{
    if (i >= data->size()) {
        throw out_of_range(msg);
    }
};

string& strBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string& strBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}
void strBlob::pop_back()
{
    check(0, "pop_back on empty strblob");
    data->pop_back();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    shared_ptr<int> pointer_to_int = make_shared<int>(20);
    int tem = 10;
    
    //    if (pointer_to_int and pointer_to_int->empty()) {
    //        *pointer_to_int = tem;
    //    }
    cout << *pointer_to_int << endl;
    shared_ptr<string> ptos = make_shared<string>(10, '9');
    cout << *ptos << endl;
    
    auto p = make_shared<int>(42);
    auto q(p);
    cout << *q << endl;
    //    利用析构函数销毁对象 destruction
    
    strBlob ourblo = {"aa", "bb"};
    ourblo.push_back("use it");
    
    cout << ourblo.back()<< endl;
    cout << ourblo.front() << endl;
    
    
//    new
    string *ps = new string;
    int *pi = new int;
    int *pi2 = new int(1024);
    string *ps2 = new string(10, '9');
    cout << *ps2 << endl;
    
    vector<int> *ptov = new vector<int>{0,1,2,3,4};
    
    delete ptov;
    
    shared_ptr<double> pp1;
    shared_ptr<int> pp2(new int(1024));
    
    
//    unique ptr
    unique_ptr<int> up1;
    unique_ptr<int> up2(new int(42));
    
    unique_ptr<string> up3(new string("hellow"));
    // unique ptr 不支持拷贝和赋值
    cout << *up3 << endl;
    unique_ptr<string> up4(up3.release());
    cout << *up4 << endl;
    unique_ptr<string> upp4(new string("Alex"));
    cout << *upp4 << endl;
    up4.reset(upp4.release());
    cout << *up4 << endl;
    
//    weakptr
    
    return 0;
}

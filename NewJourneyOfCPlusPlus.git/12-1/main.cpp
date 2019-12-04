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

class strBlobPtr;

class strBlob
{
    friend class strBlobPtr;
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
    
    strBlobPtr begin();
    strBlobPtr end();
    
    
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


class strBlobPtr{
public:
    strBlobPtr():curr(0) {}
    strBlobPtr(strBlob &a, size_t sz = 0):
    wptr(a.data), curr(sz) {}
    string & deref() const;
    strBlobPtr& incr();

    
private:
    shared_ptr<vector<string>> check(size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

shared_ptr<vector<string>> strBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound strblobptr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
//    return the pointer to vector
}

string& strBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
//    (*p) is pointer to vector
}

strBlobPtr& strBlobPtr::incr()
{
    check(curr, "increment past end of strblobptr");
    ++curr;
    return *this;
}

strBlobPtr strBlob::begin(){ return strBlobPtr(*this);}

strBlobPtr strBlob::end() {
    auto ret = strBlobPtr(*this, data->size());
    return ret;
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
    auto oldp =  make_shared<int>(42);
    weak_ptr<int> wp(oldp);
    cout << wp.use_count() << endl;
    
    
    strBlobPtr ourbloptr(ourblo);
    
    cout << ourbloptr.deref() << endl;
    ourbloptr.incr();
    cout << ourbloptr.deref() << endl;
    ourbloptr.incr();
    cout << ourbloptr.deref() << endl;
    
    int *pia = new int[10];
    
    typedef int arrT[42];
    int *parrT = new arrT;
    
    int *pia2 = new int[10]();
    
    string *psa = new string[10];
    string *psa2 = new string[10] ();
    
    int *pia3 = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    string *ps3 = new string[2]{"hi", "hihao"};
    
    delete [] pia;
    delete [] parrT;
    delete [] ps3;
//    in delete动态数组, the [] is necessary
    
    unique_ptr<int []> up(new int[10]);
    for(size_t i = 0; i != 10; ++i)
    {
        up[i] = i;
    }

    up.release();
//    use the unique_ptr to manage 动态数组
    
//    share_ptr 不直接支持管理动态数组
//    为了使用share_ptr, 必须提供删除器
    shared_ptr<int> sp(new int[10], [](int *p) { delete [] p;});
    sp.reset();
    
//    allocator: 帮助将内存分配和对象构造分离
    allocator<string> alloc;
    size_t n = 10;
    auto const pa = alloc.allocate(n);
    
    auto qa = pa;
    alloc.construct(qa++);
    alloc.construct(qa++, 10, 'a');
    alloc.construct(qa++, "hi, neil");
//
//    while (pa != qa) {
//        cout << *pa << " ";
//        pa ++;
//    }
//    cout << endl;
    cout << *pa << endl;
//    cout << *pa << endl;
    while (qa != pa) {
        alloc.destroy(--qa);
    }
    
    
    alloc.deallocate(pa, n);
    
    
    allocator<int> alloc2;

    vector<int> tesrtv {1,2,3,4,5};
    auto ptest = alloc2.allocate(tesrtv.size() * 2);
    auto ptest2 = uninitialized_copy(tesrtv.begin(), tesrtv.end(), ptest);
    
    uninitialized_fill_n(ptest2, tesrtv.size(), 42);
    
    cout << *ptest2 << endl;
//    page 429, but still some problems
    
    return 0;
}


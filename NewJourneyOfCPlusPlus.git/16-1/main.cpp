//
//  main.cpp
//  16-1
//
//  Created by 王子昱 on 2019/12/10.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <list>

using namespace std;

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

//  -------------------

template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);


//template class
template <typename T> class Blob{
    friend class BlobPtr<T>;
    friend bool operator==<T>
    ( const Blob<T>&, const Blob<T>&);
    
public:
    typedef T value_type;
    typedef typename std::vector<int>::size_type size_type;
    
    Blob();
    
    Blob(std::initializer_list<T> il);
    
    size_type size() const {return data->size();}
    
    bool empty() const { return data->empty();}
    
    void push_back(const T &t) { data->push_back(t);}
    
    void push_back(T &&t) { data->push_back(std::move(t));}
    
    void pop_back();
    
    T& back();
    T& operator[](size_type i);
    
private:
    shared_ptr<vector<T>> data;
    void check(size_type i, const string &msg) const;
};

// the function in template class
template <typename T>
void Blob<T>::check(size_type i, const string &msg) const
{
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
    return;
}


template <typename T>
T& Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back;
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
    return;
}

template <typename T>
Blob<T>::Blob():
data(make_shared<vector<T>>()) { }

template <typename T>
Blob<T>::Blob(initializer_list<T> il):
data(make_shared<vector<T>>(il)) { }

// --------------------------------

template <typename T>
class BlobPtr
{
public:
    BlobPtr(): curr(0) { }
    
    BlobPtr(Blob<T> &a, size_t sz = 0):
    wptr(a.data), curr(sz) { }
    
    T& operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    
    BlobPtr& operator++();
    
    BlobPtr& operator--();
    //    BlobPtr<T>& operator++(); 是一样的， 因为在处理自身引用
    
private:
    shared_ptr<vector<T>>
    check(size_t, const string&) const;
    std::weak_ptr<vector<T>> wptr;
    size_t curr;
    
};


template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
    BlobPtr ret =*this;
    ++*this;
    return ret;
}

//  ------------default template argument
template <typename T, typename F = less<T>>
int compare_new(const T &v1, const T &v2, F f = F())
{
    if(f(v1, v2)) return -1;
    if(f(v2, v1)) return 1;
    return 0;
}


//      -----------
template <class T = int>
class Number{
public:
    Number(T v = 0):val(v) { }
private:
    T val;
};

//      ---------------
//  member template
class DebugDelete
{
public:
    DebugDelete(ostream &s = std::cerr):os(s) { }
    
    template <typename T> void operator()(T *p) const
    {  os << " delete unique_ptr " << endl;
        delete p;
    }
        
private:
    ostream &os;
};

        
template <typename A, typename B>
int flexibleComapre(const A& v1, const B& v2)
        {
        if(v1 < v2) return -1;
        if(v2 < v1) return 1;
        return 0;
        }

template <typename T> ostream &print(ostream &os, const T &obj)
        {
        return os << obj;
        }
        
// -------
// explicit template argument
template <typename T1, typename T2, typename T3>
T1 sum(T2 v2, T3 v3)
        {
        return v2 + v3;
        }

        
//  --------- 尾置返回类型
template <typename It>
auto fcn(It beg, It end) -> decltype(*beg)
        {
        return *beg;
        }

        
//
template <typename It>
auto fcn2(It beg, It end) -> typename remove_reference<decltype(*beg)>::type
        {
        return *beg;
        }
        
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int v1 = 0, v2 = 1;
    cout << compare(v1, v2) << endl;
    cout << compare(1, 2) << endl;
    
    vector<int> vec1{1, 2, 3}, vec2{2, 3, 4};
    cout << compare(vec1, vec2) << endl;
    
    cout << compare("hi", "mom") << endl;
    
    Blob<int> ia;
    Blob<int> ia2 = {0,2,3,4};
    
    Blob<string> articles = {"a", "v", "d"};
    
    Blob<int> squares = {9, 1, 2, 3, 4, 5};
    for (size_t i = 0; i != squares.size(); ++i) {
        squares[i] = i * i;
    }
    
    cout << squares[0] << " " << squares[1] << endl;
    
    Number<long double> lot_of_precision;
    Number<> average_precision;
    
    double* p = new double;
    DebugDelete d;
        
    d(p);
    int * ip = new int;
    DebugDelete()(ip);
    
    
    int iia[] = {0, 1, 2, 3, 4, 5};
    vector<long> vi = {1,2,3};
    list<const char*> w = {"ww", "xx", "ll"};
//        Blob<int> a1(begin(iia), end(iia));
    
        print(cout, 42);
        
//        ofstream f("output");
//        print(f, 10);
        cout << endl;
        long i = 99;
        long lng = 789;
        auto val3 = sum<long long>(i, lng);
        cout << val3 << endl;
    
        vector<int> viii = {91,2,3,4,5};
        auto &viip = fcn(viii.begin(), viii.end());
        cout << viip << endl;
    
        
        
    return 0;
}

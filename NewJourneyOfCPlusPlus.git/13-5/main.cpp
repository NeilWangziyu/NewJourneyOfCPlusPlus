//
//  main.cpp
//  13-5
//
//  Created by 王子昱 on 2019/12/5.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class StrVec{
    
public:
    StrVec():
    elements(nullptr), first_free(nullptr), cap(nullptr) { }    //allocator element default initiate
    
    StrVec(const StrVec&);  //copy construction
    
    StrVec &operator=(const StrVec&);   // 拷贝赋值
    
    ~StrVec();
    
    void push_back(const string&);  //copy
    
    size_t size() const { return first_free - elements;}
    
    size_t capacity() const { return cap - elements;}
    
    string *begin() const { return elements;}
    
    string *end() const { return first_free;}
    
    
    
    
private:
    static std::allocator<std::string> alloc;   //allocate elements
    
    void chk_n_all()
    { if( size() == capacity())   reallocate();}
    
    pair<string*, string*> alloc_n_copy
    (const string*, const string*);
    
    void free();
    void reallocate();
    
    string *elements;   // point to the first elem
    string *first_free; // point to the first free elem
    string *cap;    // point to the last pos in vector
    
};


void StrVec::push_back(const string &s)
{
    chk_n_all();
    alloc.construct(first_free++, s);
}

pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements) {
        for (auto p = first_free; p != elements; ) {
            alloc.destroy(--p);
        }
        
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    
    auto dest = newdata;
    auto elem = elements;
    
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest ++, std::move(*elem++));
    }
    
    free();
    
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

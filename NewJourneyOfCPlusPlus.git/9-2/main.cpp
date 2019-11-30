//
//  main.cpp
//  9-2
//
//  Created by 王子昱 on 2019/11/29.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <string>
#include <stack>

using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> v = {1,3,4,5};
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
    
    v.emplace(v.begin(), 9);
    
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
    
    v.emplace(v.begin(), 0);
    
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
    cout << "size of vector:" << v.size() << endl;
    
    cout << "max size of vector:" << v.max_size() << endl;
    
    //    iterator
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
        cout << *i << endl;
    }
    
    //
    cout << "reverse_iterator" << endl;
    for (vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); ++i) {
        cout << *i << endl;
    }
    
    vector<int> c2(v);
    
    cout << "use copy to build c2" << endl;
    
    for (auto i2 = c2.cbegin(); i2 != c2.cend(); i2++) {
        cout << *i2 << endl;
    }
    
    cout << "copy char* into string" << endl;
    vector<const char*> articele = {"a", "b", "c"};
    forward_list<string> words(articele.begin(), articele.end());
    for (auto f_item : words) {
        cout << f_item << endl;
    }
    
    list<string> author = {"neil", "tim", "kitty"};
    auto it = author.begin();
    it++;
    it++;
    deque<string> authorList(author.begin(), it);
    
    cout << "copy some of the author" << endl;
    for (auto f_item : authorList) {
        cout << f_item << endl;
    }
    
    vector<int> ivec(10, -2);
    list<string> svec(10, "hei");
    forward_list<int> iv(25);
    deque<string> sv(5);
    
    //    array
    cout << "array" << endl;
    array<int, 4> a1 = {9,2,3,4};
    array<int, 4>::size_type aindex;
    cout << a1[aindex]<< endl;
    aindex ++;
    cout << a1[aindex]<< endl;
    array<int, 4> a2 = {0};
    
    //    assign
    
    list<string> names;
    vector<const char*> oldstyle;
    char c22 = 'i';
    const char* c22p = &c22;
    
    oldstyle.push_back(c22p);
    
    names.assign(oldstyle.cbegin(), oldstyle.cend());
    //    use the assign, and we can transfer char* into string
    for (auto f_item : names) {
        cout << f_item << endl;
    }
    
//    forward_list is quite different
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end()) {
        if (*curr % 2) {
            curr = flst.erase_after(prev);
        }
        else{
            prev = curr;
            ++curr;
        }
    }
    for (auto item : flst) {
        cout << item << " ";
    }
    cout << endl;
    
//    loop
    vector<int> vvv = {1,2,3,4,5,6,7,8,9};
    auto iter = vvv.begin();
    while (iter != vvv.end()) {
        
        if (*iter % 2) {
            iter = vvv.insert(iter, *iter);
            iter += 2;
        }
        else
            iter = vvv.erase(iter);
    }
    for (auto item : vvv) {
        cout << item << " ";
    }
    cout << endl;
    cout << "vvv cap:" << vvv.capacity() << endl;
    
//    容器适配器
//    adaptor
    stack<int> intStack;
    for (size_t ix = 0; ix != 10; ++ix) {
        intStack.push(ix);
    }
    while (!intStack.empty()) {
        int Value = intStack.top();
        intStack.pop();
        
        cout << Value << endl;
    }
    return 0;
}

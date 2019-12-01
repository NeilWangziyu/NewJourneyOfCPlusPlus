//
//  main.cpp
//  10-4
//
//  Created by 王子昱 on 2019/12/1.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <numeric>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    list<int> lst = {1,2,3,4};
    list<int> lst2, lst3;
    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
    for (auto item:lst2) {
        cout << item << " ";
    }
    cout << endl;
    for (auto item:lst3) {
        cout << item << " ";
    }
    cout << endl;
    
//    use the istream to read input stream and store in vector
//    istream_iterator<int> in_iter(cin);
//    istream_iterator<int> eof;
//    vector<int> vec;
//    while (in_iter != eof) {
//        vec.push_back(*in_iter++);
//    }
//    for (auto item:vec) {
//        cout << item << " ";
//    }
//    等价：
//    istream_iterator<int> in_iter2(cin), eof2;
//    vector<int> vec2(in_iter2, eof2);
    
    cout << endl;
    cout << "input some number, end with \\0:" << endl;
    istream_iterator<int> in(cin), eof;
    
    cout << "sum is:" << accumulate(in, eof, 0) << endl;
    
    ostream_iterator<int> out_iter(cout, " ");
    for (auto e : lst3) {
        *out_iter ++ = e;
    }
    cout << endl;
    
    copy(lst2.begin(), lst2.end(), out_iter);
    cout << endl;
    
    
//    泛型算法结构：
//    1. input iterator
//    2. output iterator
//    3. forward
//    4. bidirectional
//    5. random-access
    
    return 0;
}

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
    
    return 0;
}

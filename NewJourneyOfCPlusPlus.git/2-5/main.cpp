//
//  main.cpp
//  2-5
//
//  Created by 王子昱 on 2019/11/24.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    type alias
    typedef double wages;
    typedef wages base, *p;
    
//    using SI = Sales_item;
//    c++ 11 new feature
    wages hourly, weekly;
    
//    auto
    auto i = 0, *pi = &i;
    cout << *pi << endl;
    

    
    return 0;
}

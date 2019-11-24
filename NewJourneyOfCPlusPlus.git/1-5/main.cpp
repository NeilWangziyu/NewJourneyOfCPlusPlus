//
//  main.cpp
//  1-5
//
//  Created by 王子昱 on 2019/11/24.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include "Sales_item.h"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    using SI = Sales_item;
    
    std::cout << "Hello, World!\n";
    
    Sales_item book;
    cin >> book;
    cout << book << endl;
    
    Sales_item book_extra;
    cin >> book_extra;
    
    if (book.isbn() == book_extra.isbn()) {
        cout << "they are same book" << endl;
        cout << book + book_extra << endl;

    }
    else
    {
        cout  << "they are different book" << endl;
    }
    
    
    
    
    return 0;
}

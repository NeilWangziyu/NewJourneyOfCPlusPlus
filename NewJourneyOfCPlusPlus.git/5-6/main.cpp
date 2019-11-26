//
//  main.cpp
//  5-6
//
//  Created by 王子昱 on 2019/11/26.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

struct Sales_data{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    //    类内初始值 in-class initializer
};

int fact(int val)
{
    int ret = 1;
    while (val > 1) {
        ret *= val--;
    }
    return ret;
}

double square(double x)
{
    return x*x;
}

size_t count_calls()
{
    static size_t ctr = 0;
    return ++ctr;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, World!\n";
    
    string item1, item2;
    
    cin >> item1 >> item2;
    if (item1 == item2) {
        cout << "enter same book: " << item1 << endl;
    }
    else
    {
        throw runtime_error("Item must refer same");
    }
    cout << item1 + item2 << endl;
    
    //    using try
    cout << "using try" << endl;
    cout << "please input two string" <<endl;
    while (cin >> item1 >> item2) {
        try {
            if (item1 == item2) {
                cout << "enter same book: " << item1 << endl;
                break;
            }
            else
            {
                throw runtime_error("Item must refer same");
            }
        } catch (runtime_error err) {
            cout << err.what()
            << "\n Try again? enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n') {
                break;
            }
        }
    }
    
    
    int res = fact(10);
    cout << "func returns:" << res << endl;
    
//    use static variable
    for (int i = 0; i < 10; ++i) {
        cout << count_calls() << endl;
    }
    
    return 0;
}

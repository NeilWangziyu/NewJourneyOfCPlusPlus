//
//  main.cpp
//  1-2
//
//  Created by 王子昱 on 2019/11/24.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout << "Enter two numbers" << endl;
    int v1 = 0, v2 = 0;
    cin >> v1 >> v2;
    cout << "the sum of the two number of " << v1 << " and " << v2 << " is " << v1 + v2 << endl;
    
    //  1-4-1
    
    int sum = 0, val = 1;
    while (val <= 10) {
        sum += val;
        ++val;
        
    }
    cout << "the sum of 1 to 10 is " << sum << endl;
    
    int sum2 = 0;
    for (int val2 = 1; val2 <= 10; val2 ++) {
        sum2 += val2;
    }
    cout << "the sum2 of 1 to 10 is " << sum2 << endl;
    
    
    //    1-4-3
    cout << "input some number, if you want stop, input '\\n'"<< endl;
    
    int sum3 = 0, value = 0;
    while (cin >> value) {
        cout << "input " << value << " successful" << endl;
        sum3 += value;
    }
    cout << "sum3 is " << sum3 << endl;
    
    //    1-4-4
//    this section should be rerun
    int currVal = 0, val3 = 0, cnt = 0;
    if (cin >> currVal) {
        cnt = 1;
        while (cin >> val3) {
            if (val3 == currVal) {
                ++ cnt;
            }
            else
            {
                cout << currVal << " occurs " << cnt << "times " << endl;
                currVal = val3;
                cnt = 1;
            }
        }
        cout << currVal << " occurs " << cnt << " times " << endl;
    }
    
    return 0;
}

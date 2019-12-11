//
//  main.cpp
//  17-1
//
//  Created by 王子昱 on 2019/12/11.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <tuple>
#include <list>
#include <string>
#include <vector>

//tuple
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    tuple<size_t, size_t, size_t> threeD;
    
    tuple<string, vector<double>, int, list<int>>
    someVAl("constants", {3.14, 2.718}, 42, {0, 1, 2, 3});
    
    cout << get<0>(someVAl) << endl;
    
    return 0;
}

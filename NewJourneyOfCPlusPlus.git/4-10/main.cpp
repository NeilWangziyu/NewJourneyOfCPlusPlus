//
//  main.cpp
//  4-10
//
//  Created by 王子昱 on 2019/11/26.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> ivec(5);
    
    vector<int>::size_type cnt = ivec.size();
//    the comma operator
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
    {
        ivec[ix] = cnt;
    }
    
    for (auto i :ivec) {
        cout << i << endl;
    }
    
    int ival = 3.451 + 3;
    cout << ival << endl;
    
    int ia[10];
    int *ip = ia;
    
    int i = 3, j = 8;
    double slope = i / j;
    cout << "slope:" << slope << endl;
    
    double slope2 = static_cast<double>(i) / j;
    cout << "slope2:" << slope2 << endl;
    
    char c[] = "c++";
    const char *pc = c;
    char *p = const_cast<char*>(pc);
    
    cout << pc << endl;
    cout << p << endl;
    
    ; //an empty line
    
//    if, switch, while, for
//    in those block, you can define variable
    
    unsigned aCnt=0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (cin >> ch) {
        switch (ch) {
            case 'a':
                ++aCnt;
                cout << "get A" << endl;
                break;
            
            case 'e':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            case 'o':
                ++oCnt;
                break;
            case 'u':
                ++uCnt;
                break;
                
            default:
                break;
        }
    }
    
    cout << "number of a: \t" << aCnt << '\n'
    << "number of e: \t" << eCnt << endl;
    
    return 0;
}

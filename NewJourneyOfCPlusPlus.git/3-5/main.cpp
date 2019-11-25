//
//  main.cpp
//  3-5
//
//  Created by 王子昱 on 2019/11/25.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    unsigned cnt = 42;
    constexpr unsigned sz = 3;
    int arr[10];
//    array with 10 int
    int *parr[sz];
//    array with 3 pointer to int
    cout << "array" << endl;
    int ia1[sz] = {0, 1, 2};
    int a2[] = {0, 1, 2};
    int a3[5] = {0, 1, 2};
    string a4[3] = {"hi", "bey"};
    
    char a5[] = "C++";
//    size of a5 is 4
    
    
    string nums[] = {"one", "two", "three"};
    string *p = &nums[0];
    string *p2 = nums;
//  for most of time, the operation on array is using pointer
   
    int ia[] = {0, 1, 2, 3, 4, 5};
    int *beg = begin(ia);
    int *last = end(ia);
    while (beg != last) {
        cout << *beg << endl;
        ++ beg;
    }
    cout << "count the size: " << endl;
    auto n = end(ia) - begin(ia);
    cout << "the size of ia is " << n << endl;
//    use the std function begin/end to count the number of array.
//    ptrdiff_t
    
    int lastnum = *(ia + n - 1);
    cout << " the last number in ia is " << lastnum << endl;
//  利用解引用获得想要的值
    
//    use the pointer to zero all array
    int *pr = ia;
    while (n >= 1) {
        *pr = 0;
        --n;
        ++pr;
    }
    for (auto i : ia) {
        cout << i << endl;
    }
    
    
//    C style
    char ca[] = "test";
    char ca2[] = "test";

    cout << "use strlen : " <<strlen(ca) << endl;
    cout << "use strcmp : " <<strcmp(ca, ca2) << endl;
    
    strcat(ca, ca2);
    cout << "use strcat : " << ca << endl;
    
    strcpy(ca, ca2);
    cout << "use strcpy : " << ca << endl;
    
//    c_str
    string s("hellow world");
    const char * str = s.c_str();
    cout << str << endl;
    
    
//    use array to initliaze vector
    int int_arr[] = {0, 1, 2, 3, 4, 5};
    vector<int> ivec2(begin(int_arr), end(int_arr));
    for (auto c : ivec2) {
        cout << c << endl;
    }
    
//    multi-dimensional array
    int arr2[10][20] = {0};
    
    int iia[2][3] =
    {
        {1,2,5},
        {2,3,9}
    };
    
    cout << " use pointer : " << endl;
    for (auto p = iia; p != iia + 2; ++p) {
        for (auto qi = *p ; qi != *p + 3; ++qi) {
            cout << *qi << " ";
        }
        cout << endl;
    }
    
    cout << "use iterator:" <<endl;
    for (auto pp = begin(iia); pp != end(iia); ++pp) {
        for (auto qq = begin(*pp); qq != end(*pp); ++qq) {
            cout << *qq << " ";
        }
        cout << endl;
    }
    

    return 0;
}

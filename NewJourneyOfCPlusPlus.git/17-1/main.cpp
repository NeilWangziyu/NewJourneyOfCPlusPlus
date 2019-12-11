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
#include <bitset>
#include <regex>

#include <random>

using namespace std;

vector<unsigned> good_randVec()
{
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(0, 9);
    vector<unsigned> ret;
    for (size_t i = 0; i < 15; ++i) {
        ret.push_back(u(e));
    }
    return ret;
}


//tuple
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    tuple<size_t, size_t, size_t> threeD;
    
    tuple<string, vector<double>, int, list<int>>
    someVAl("constants", {3.14, 2.718}, 42, {0, 1, 2, 3});
    
    cout << get<0>(someVAl) << endl;
    
    auto item = make_tuple("0-11-1", 3, 2.01);
    
    auto book = get<0>(item);
    auto cnt = get<1>(item);
    auto price = get<2>(item);
    cout << book << " " << cnt << " " << price << endl;
    
    get<2>(item) *= 0.9;
    
    cout << get<2>(item) << endl;
    
    
    //  bitset
    bitset<13> bitvec1(0xbeef);
    
    bitset<20> bitvec2(0xbeef);
    
    bitset<32> bitvec4("1100");
    
    string str("11111100000011001101");
    bitset<32> bitvec5(str, 5, 4);
    // str[5]开始四位
    
    bitset<32> bitvec6(str, str.size() - 4);
    // 最后四个字符
    
    cout << bitvec1.any() << endl;
    //    是否有置位的二进制位
    
    cout << bitvec2.all() << endl;
    
    cout << bitvec4.count() << endl;
    
    cout << bitvec4.size() << endl;
    //    a constexpr function, return bitvec4位数
    
    cout << bitvec5[0] << endl;
    
    
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern);
    smatch results;
    
    string text_str = "receipt friend theif receive";
    if (regex_search(text_str, results, r)) {
        cout << results.str() << endl;
    }
    
    //    随机数
    default_random_engine e;
    
    for (size_t i = 0; i < 10; ++i) {
        cout << e() << endl;
        //        use e() to build a random number
    }
    
    uniform_int_distribution<unsigned> u(0, 15);
    default_random_engine e2;
    for (size_t i = 0; i < 10; ++i) {
        cout << u(e2) << endl;
        //        use e() to build a random number
    }
    
    cout << "min:" << e.min() << " max:" << e.max() << endl;
    
    vector<unsigned> res = good_randVec();
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    
    default_random_engine e4;
    uniform_real_distribution<double>u2(0,1);
    for (size_t i = 0; i < 10; ++i) {
        cout << u2(e4) << endl;
        //        use e() to build a random number
    }
    
    default_random_engine e5;
    normal_distribution<> n(4, 1.5);
    vector<unsigned> vals(9);
    
    for (size_t i = 0; i != 200; ++i) {
        unsigned v = lround(n(e5));
        if (v < vals.size()) {
            ++vals[v];
        }
    }
    
    for (size_t j = 0; j != vals.size(); ++j) {
        cout << j << ": " << string(vals[j], '*') << endl;
    }
    
    
//    IO 库
    
    cout << "Default bool values:" << true <<" " << false << endl;
    cout <<"alpha bool values: " << boolalpha << true << " " << false << endl;
    
    
    cout << showbase;
    cout << "default: " << 20 <<" " << 1024 << endl;
    cout << "octal: " << oct << 20 << " "<< 1024 << endl;
    cout <<" hex: " << hex << 20 <<" " << 1024 << endl;
    cout << " decimal: " << dec << 20 <<" " << 1024 << endl;
    cout << noshowbase;
    
    
    cout << "Precision: " << cout.precision() << ", Value: " << sqrt(2.0) << endl;
    cout.precision(12);
    cout << "Precision: " << cout.precision() << ", Value: " << sqrt(2.0) << endl;
    cout.precision(3);
    cout << "Precision: " << cout.precision() << ", Value: " << sqrt(2.0) << endl;

    
    return 0;
}

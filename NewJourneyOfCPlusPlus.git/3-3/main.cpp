//
//  main.cpp
//  3-3
//
//  Created by 王子昱 on 2019/11/25.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> v1(10);
    vector<int> v2{10};
    vector<int> v3(10, 1);
    vector<int> v4{10, 1};
    for (auto each : v4) {
        cout << each <<endl;
    }
    vector<string> v5{"hi"};
    vector<int> v22;
    for (int i = 0; i < 10; ++i) {
        v22.push_back(i);
    }
    
    for (auto e : v22) {
        cout << e << endl;
    }
    cout << "v22 index 2: " << v22[2] << endl;
    cout << "v22 size: " << v22.size() << endl;
    for (auto &ee : v22) {
        ee *= ee;
    }
    cout << "v22 new value : " << endl;
    for (auto e3 : v22) {
        cout << e3 << endl;
    }
    
    
//  for input
//    vector<unsigned> scores(11, 0);
//    unsigned score;
//    while (cin >> score) {
//        if (score <= 100) {
//            ++scores[score/10];
//        }
//    }
//    for (auto e4 : scores) {
//        cout << e4 << " " ;
//    }
    
//    3-4 iterator
//    v.begin()
//    v.end() -> one past the end
//    if v is empty, then begin and end is same
    string s("some string");
    if (s.begin() != s.end()) {
        auto it = s.begin();
        * it = toupper(*it);
    }
    cout << "new s : " << s << endl;
    for (auto it = s.begin(); it!=s.end() && !isspace(*it); ++it) {
        *it = toupper(*it);
    }
    cout << "new new s: " << s << endl;
    
    vector<int>::iterator it;
//    it can w/r vector<int>
    string::iterator it2;
//    it2 can w/r string
    vector<int>::const_iterator it3;
//    it3 can only read
    string::const_iterator it4;
//    it4 can only read
//    const_iterator is same to const pointer, can read and can not write
    
    vector<int> v;
    const vector<int> cv;
    auto itv = v.begin();   //iterator;
//    because now it is empty, the itv is also points to v.end()
    auto itcv = cv.begin(); //const iterator
    auto itcv3 = v.cbegin();
//    const_iterator
    
    
    v.push_back(10);
    v.push_back(15);
    itv = v.begin();   //iterator;

    cout << *itv << endl;
//    while (itv != v.end()) {
//        cout << *itv << endl;
//        itv++;
//    }
    vector<string> vs;
    vs.push_back("str1");
    vs.push_back("str2");
    cout << "use auto &" << endl;
    for (auto &vsi:vs) {
        cout << vsi << endl;
    }
    cout << "use iterator:"<< endl;
    
    for (vector<string>::iterator it=vs.begin(); it!=vs.end(); ++it) {
        cout << *it << endl;
    }
    
//    must make sure understand (*it).empty
    vector<string> text = {"today is a good day!", "", "n=s"};
    for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
        cout << *it << endl;
    }
    
//    binary search
//    use iterator for binary search
    int sought = 8;
    vector<int> raw{1,2,3,4,5,6,7,8,9,10};
    auto beg = raw.begin(), end = raw.end();
    auto mid = beg + (end - beg) / 2;
    while (mid != end && *mid != sought) {
        cout << "now checking: " << *mid << endl;
        if (*mid > sought) {
            end = mid;
        }
        else
        {
            beg = mid+1;
        }
        mid = beg + (end - beg) /2;
    }
    cout << "final find: " << *mid << endl;
    
    
    
    
    return 0;
}

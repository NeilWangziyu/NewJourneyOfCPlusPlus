//
//  main.cpp
//  3-2
//
//  Created by 王子昱 on 2019/11/25.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, const char * argv[]) {
//    string s1, s2;
//    cout << "input two strings" << endl;
//    cin >> s1 >> s2;
//    cout << s1 << "\n" << s2 << endl;
    
    string s3;
    string s4(s3);
    string s5 = s4;
//    copy initialization
    string s6("s6values");
    string s7 = "values";
    string s8(10, 'c');
    s3 = "s3 values";
    cout << s3 << " " << s4 << " " << s5 << " " << s6 << " " << s7 << " " << s8 <<endl;
    
    string s9 = s7 + " ";
    s9 = s9 + s8;
    cout << "s9 value : " << s9 << endl;
    
    cout << isalnum(s9[0]) << endl;
    cout << toupper(s9[0]) << endl;
    cout << "print s9" << endl;
    for (auto c: s9) {
        cout << c << endl;
    }
    
    string s("hello, world!!");
    decltype(s.size()) punct_cnt = 0;
    for (auto c:s) {
        if (ispunct(c)) {
            ++punct_cnt;
        }
    }
    cout << "in string " << s << " , there are total " << punct_cnt << " punct"<<endl;
    for (auto &c : s) {
        c = toupper(c);
    }
    cout << "new string: " << s << endl;
    if (!s.empty()) {
        cout << s[0] << " " << s[s.size() - 1] << endl;
        s[0] = tolower(s[0]);
    }
    cout << s << endl;
    
    string s2 = "some string";
    for (decltype(s.size()) index = 0; index < s2.size() && !isspace(s2[index]); ++index) {
        s2[index] = toupper(s2[index]);
    }
    cout << s2 << endl;
    
    const string hexdigits = "0123456789ABCDEF";
    cout << " enter number between 0 and 15, use space to separate, and end when input enter '\n' " << endl;
    string result;
    size_t n;
    while (cin >> n) {
        if (n < hexdigits.size()) {
            result += hexdigits[n];
        }
    }
    cout << "your hex number is " << result << endl;
    string stt;
    cout << stt[0] << endl;
    
//    cout << "input some strings" << endl;
//    string word;
//    while (cin >> word) {
//        cout << "inputed: " << word << endl;
//
//    }
//    cout << "input ends" << endl;
    
    
//    string line;
//    while (getline(cin, line)) {
//        cout << "line:" << line << endl;
//    }
    
    

    return 0;
}

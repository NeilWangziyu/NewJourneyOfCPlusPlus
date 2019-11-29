//
//  main.cpp
//  8-1
//
//  Created by 王子昱 on 2019/11/29.
//  Copyright © 2019 王子昱. All rights reserved.
//
#include <stdio.h>
#include<fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include<cmath>

using namespace std;

struct PersonInfo{
    string name;
    vector<string> phones;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    auto old_state = cin.rdstate();
    cin.clear();
        
    cin.setstate(old_state);
    
    cout << "plear enter a value: " << endl;
    
//
    cout << "hi!" << endl;
    
    cout << "hi!" << flush;
    
    cout << "hi!" << ends;
    
//  unitbuf
    cout << unitbuf; //所有输出z操作后都立即刷新缓冲区
    
    cout << nounitbuf; //回到正常缓冲方式
    
//
    string line, word, filename, output;
    filename = "name.txt";
    output = "out.txt";
    cout << "opening " << filename << endl;
    vector<PersonInfo> people;
    
//    ifstream inf;
//    inf.open(filename);
    
    ifstream inf(filename.c_str());
    
    ofstream outf;
    outf.open(output.c_str());
    
    while (getline(inf, line)) {

        cout << "line: " << line << endl;
        
        outf << line << '\n';
        
        PersonInfo info;
        
        istringstream record(line);
        
        record >> info.name;
        
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    
    inf.close();
    outf.close();
    return 0;
}

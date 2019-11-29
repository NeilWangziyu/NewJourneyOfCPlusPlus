//
//  main.cpp
//  7-6
//
//  Created by 王子昱 on 2019/11/29.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//static variable
class Account
{
public:
    Account() = default;
    Account(string s):owner(s){};
    Account(string s, double a):owner(s), amount(a){};
    
    void calculate() { amount += amount * interestRate;}
    
    static double rate() { return interestRate;}
    
    static void rate(double newRate)
    {
        interestRate = newRate;
        return;
    }
    string show_owner() { return owner;}
    
    
private:
    std::string owner;
    double amount = 0;
    static double interestRate;
    static double initRate();
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    double Account::interestRate = initRate();
    
//    double r;
//    r = Account::rate();
    Account ac1("neil");
    Account *ac2 = &ac1;
    cout << "owner:" << ac1.show_owner() << endl;
    cout << "owner:" << ac2->show_owner() << endl;
    
    double r = 0.1;
    ac1.rate(r);
//    cout << ac1.rate() << endl;
//    r = ac1.rate();
//    cout << r << endl;
//    r = ac2->rate();
//    cout << r << endl;
//
    
    return 0;
}

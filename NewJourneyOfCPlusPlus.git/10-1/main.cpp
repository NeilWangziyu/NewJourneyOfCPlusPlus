//
//  main.cpp
//  10-1
//
//  Created by 王子昱 on 2019/11/30.
//  Copyright © 2019 王子昱. All rights reserved.
//  泛型算法

#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>

using namespace std;
void elimDups(vector<string> &word)
{
    sort(word.begin(), word.end());
    auto end_unique = unique(word.begin(), word.end());
    word.erase(end_unique, word.end());
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

string make_plural(size_t ctr,const string &word, const string &ending)
{
    return (ctr==1) ? word : word+ending;//make_plural(wc, "word ", "s ")当输入中文本中
    //word数大于一是在word后加s，为words为word的复数！
}

void func1()
{
    size_t v1 = 42;
    auto f = [v1] {return v1;};
    v1 = 0;
    auto j = f();
    cout << j << endl;
    //    j is 42, f is the copy of v1
}
void func2()
{
    size_t v1 = 42;
    auto f2 = [&v1] {return v1;};
    v1 = 0;
    auto j = f2();
//    j is 0, in f2 is ref of v1, not copy of v1
    cout << j << endl;
}

void func3()
{
    size_t v1 = 42;
    auto f = [v1] () mutable { return ++v1;};
    v1 = 0;
    auto j = f();
    cout << j << endl;
//    j is 43, mutable:改变一个被捕获的变量
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int val = 42;
    vector<int> vec = {1,2,3,4,5,56,42,0,9};
    auto result = find(vec.cbegin(), vec.cend(), val);
    cout << "The value " << val
    << (result == vec.cend() ? "is not present" : " is present") << endl;
    
    int sum = accumulate(vec.cbegin(), vec.cend(), 0);
    cout << "sum of the vec: " << sum << endl;
    
    
    vector<int> vec2;
    auto it = back_inserter(vec2);
    *it = 42;
    
    cout << "output vec2" << endl;
    for (auto ite: vec2) {
        cout << ite << endl;
    }
    
    fill_n(back_inserter(vec2), 10, 0);
    
    cout << "output vec2:" << endl;
    for (auto ite: vec2) {
        cout << ite << endl;
    }
    
    //copy:
    int a1[] = {0,1 ,2,3,4,5,6,7};
    int a2[sizeof(a1)/sizeof(*a1)];
    auto ret = copy(begin(a1), end(a1), a2);
    cout << "output a2:" << endl;
    for (auto ite: a2) {
        cout << ite << endl;
    }
    
    replace(vec.begin(), vec.end(), 0, 42);
    cout << "output vec:" << endl;
    for (auto ite: vec) {
        cout << ite << endl;
    }
    
    //
    vector<string> inputs = {"the","quick", "fox", "jumps", "over","the", "quick", "red", "slow", "the", "turtle"};
    for (string it:inputs) {
        cout << it << " ";
    }
    cout << endl;
    
    elimDups(inputs);
    
    for (string it:inputs) {
        cout << it << " ";
    }
    cout << endl;
    
    vector<string> inputs2 = {"quick", "fox", "jumps", "o","the", "quick", "red", "slow", "the", "turtleeee"};
    sort(inputs2.begin(), inputs2.end(), isShorter);
    for (string it:inputs2) {
        cout << it << " ";
    }
    cout << endl;
    
    //    lambda
    auto f = [] {return 42;};
    cout << f() << endl;
    
    //    same as isShorter
    [] (const string &a, const string &b)
    { return a.size() < b.size();};
    
    vector<string> inputs3 = {"quick", "fox", "jumps", "o","the", "quick", "slow", "the", "red", "turtleeee"};
    stable_sort(inputs3.begin(), inputs3.end(), [] (const string &a, const string &b)
                { return a.size() < b.size();});
    
    for (string it:inputs3) {
        cout << it << " ";
    }
    cout << endl;
    string::size_type sz;
    
    [sz] (const string &a)
    {return a.size() >= sz;};
    
    //    查找第一个长度大于等于4的单词
    auto wc = find_if(inputs3.begin(), inputs3.end(),     [sz] (const string &a)
                      {return a.size() >= 4;});
    
    cout << *wc << endl;
    
    //    利用find_if查找从r他开始到末尾共有多少个元素
    auto count = inputs3.end() - wc;
    cout << count << " " << make_plural(count , "word", "s")
    << " of length " << sz << " or longer" << endl;
    
    //    for_Each
    for_each(wc, inputs3.end(), [](const string &s){ cout << s << " ";});
    cout << endl;
    
    func1();
    func2();
    func3();
    return 0;
    
}
//command + R -> Run
//control + i -> Re-indent


//
//  main.cpp
//  11-1
//
//  Created by 王子昱 on 2019/12/2.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

pair<string, int>
process(vector<string> &v)
{
    if (!v.empty()) {
        return {v.back(), v.back().size()}; //列表初始化
    }
    else
        return pair<string, int> ();    //隐式构造
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    map<string, size_t> word_count;
    //    string word;
    
    vector<string> words = {"hwoow", "hi", "hi", "ni", "hao", "i", "i", "i", "the", "fudna"};
    for (auto word:words) {
        ++word_count[word];
    }
    for (const auto &w : word_count) {
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? "times" : "time") << endl;
    }
    
    //    use set to exclude some word
    cout << " <set" << endl;
    map<string, size_t> new_count;
    set<string> exlude = {"the", "i"};
    for (auto word:words) {
        if (exlude.find(word) == exlude.end()) {
            ++new_count[word];
        }
    }
    for (const auto &w : new_count) {
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? "times" : "time") << endl;
    }
    
//    map: {key, value}
    map<string, string> authors = { {"joyce", "james"}, {"niek", "time"}};
    
    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i) {
        ivec.push_back(i);
        ivec.push_back(i);
    }
    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());
    
    cout << "iset" << endl;
    for (auto item : iset) {
        cout  << item << " ";
    }
    cout << endl;
    
    cout << "miset" << endl;
    for (auto item : miset) {
        cout  << item << " ";
    }
    cout << endl;
    
//    pair: define in utility
    pair<string, string> anon;
    pair<string, string> auth("hames", "harden");
//    one is first, one is second
    pair<string, int> res = make_pair("neil", 199);
    cout << res.first << " " << res.second << endl;
    
//    key_type
//    mapped_type
//    value_type
    set<string>::value_type v1;
    cout << v1 << endl;
    
//    iterator in map
    auto map_it = word_count.begin();
    // map_it is a pair<const string, size_t>
    cout << map_it->first;
    cout << " " << map_it->second;
    ++map_it->second;
    
    cout << "\nAfter chanege:" << map_it->second;
    cout << endl;
    //    note: key is const
    
    
//    遍历
    cout << "遍历:" << endl;
//    const pair<const string, size_t> map_it2 = word_count.cbegin();
    auto map_it2 = word_count.cbegin();
    while (map_it2 != word_count.cend()) {
        cout << map_it2->first << " occurs " << map_it2->second << " times" << endl;
        ++map_it2;
    }
    
    
//    insert
    vector<int> ivec2 = {1,3,4,6,8};
    set<int> set2;
    set2.insert(ivec2.begin(), ivec2.end());
    cout << set2.size() << endl;
    set2.insert({1,2,3,4,5});
    cout << set2.size()<< endl;
    
    word_count.insert({"nhao",1});
    word_count.insert(make_pair("asary", 1));
    word_count.insert(pair<string, int>("neil", 2));
    
    map_it2 = word_count.cbegin();
    while (map_it2 != word_count.cend()) {
        cout << map_it2->first << " occurs " << map_it2->second << " times" << endl;
        ++map_it2;
    }
    
//    下标运算符
    word_count["anna"] = 10;
    cout << word_count["anna"] << endl;
    
    if (word_count.find("test") == word_count.end()) {
        cout << "test is not in word_count" << endl;
    }
    
//    Three way to search in multimap
    multimap<string, string> manthors = {{"Neil", "neil1"}, {"Neil", "neil2"}, {"Tom", "tom1"}, {"Tom", "tom2"}, {"tim", "tim1"}};

//    find
    cout << "methods 1:" << endl;
    string search_item("Neil");
    auto entries = manthors.count(search_item);
    auto iter = manthors.find(search_item);
    while (entries) {
        cout << iter->second << endl;
        ++iter;
        --entries;
    }
    
//    lower_bound and upper_bound: for multimap
    cout << "methods 2:" << endl;
    for (auto beg = manthors.lower_bound("Neil"),
         end = manthors.upper_bound("Neil");
         beg != end; ++beg) {
        cout << beg->second << endl;
    }
    
//    equal_range
    cout << "methods 3:" << endl;
    for (auto pos = manthors.equal_range(search_item); pos.first != pos.second; ++pos.first) {
        cout << pos.first -> second << endl;
    }
    
    cout << hash<string>()("string")<<endl;
    
    return 0;
}

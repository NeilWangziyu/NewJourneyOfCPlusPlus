//
//  TextQuery.h
//  NewJourneyOfCPlusPlus.git
//
//  Created by 王子昱 on 2019/12/9.
//  Copyright © 2019 王子昱. All rights reserved.
//

#ifndef TextQuery_h
#define TextQuery_h
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;

using line_no = vector<string>::size_type;
using std::getline;
class QueryResult;

class TextQuery
{
public:
    TextQuery(std::ifstream&);
    
    QueryResult query(const std::string&) const;
    
    
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
    
};

TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
    string text;
    //    while (getline(is, text)) {
    //        奇怪...getline为什么不对！！！
    while (true) {
        file->push_back(text);
        int n = file->size();
        istringstream line(text);
        string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines) {
                lines.reset(new set<line_no>);
            }
            lines->insert(n);
        }
    }
}

class QueryResult
{
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(std::string s,
                std::shared_ptr<set<line_no>> p,
                shared_ptr<vector<string>> f):
    sought(s), lines(p), file(f) { }
    
private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};

QueryResult
TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end()) {
        return QueryResult(sought, nodata, file);
    }
    else
        return QueryResult(sought, loc->second, file);
}

ostream &print(ostream & os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
    << endl;
    for (auto num : *qr.lines) {
        os << "\t (line " << num + 1<< ") "
        << *(qr.file->begin() + num) << endl;
    }
    return os;
}

void runQueries(ifstream &infile)
{
    //
    TextQuery tq(infile);
    while (true) {
        cout << "enter wor to look for or q to quit" << endl;
        string s;
        if (!(cin >> s) || s == "q") {
            break;
        }
        print(cout, tq.query(s)) << endl;
    }
}

#endif /* TextQuery_h */

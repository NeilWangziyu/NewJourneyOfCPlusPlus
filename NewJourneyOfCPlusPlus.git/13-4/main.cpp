//
//  main.cpp
//  13-4
//
//  Created by 王子昱 on 2019/12/4.
//  Copyright © 2019 王子昱. All rights reserved.
//  https://codar.club/blogs/c-primer-message-and-folder-classes.html

#include <iostream>
#include <string>
#include <vector>
#include <set>


using namespace std;
class Folder;

class Message{
    friend class Folder;
    friend void swap(Message&, Message&);
    friend void print(const Message&);
    
public:
    explicit Message(const string &str=""):
    contents(str){ }
    
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    
    void save(Folder&);
    void remove(Folder&);
    void addFolder(Folder&);
    void remFolder(Folder&);
    
private:
    string contents;
    set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};

class Folder
{
    friend class Message;
    friend void print(const Folder&);
    friend void swap(Folder&, Folder&);
public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    void addMsg(Message*);
    void remMsg(Message*);
    
private:
    set<Message*> messages;
};

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders) {
        f->addMsg(this);
    }
}

Message::Message(const Message &m):
contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}   //Message's copy construction function

void Message::remove_from_Folders()
{
    for (auto f: folders) {
        f -> remMsg(this);
    }
}

void Message::addFolder(Folder &f)
{
    folders.insert(&f);
}
void Message::remFolder(Folder &f)
{
    folders.erase(&f);
}

Message::~Message()
{
    remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f: lhs.folders) {
        f -> remMsg(&lhs);
    }
    for (auto f: rhs.folders) {
        f->remMsg(&rhs);
    }
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (auto f: lhs.folders) {
        f -> addMsg(&lhs);
    }
    for (auto f: rhs.folders) {
        f->addMsg(&rhs);
    }
}

void print(const Message &m)
{
    cout << m.contents << endl;
}

//The definition of Folder class correlation function
void Folder::addMsg(Message *m)
{
    messages.insert(m);
}

void Folder::remMsg(Message *m)
{
    messages.erase(m);
}

Folder::Folder(const Folder &f):messages(f.messages)
{
    for (auto i : f.messages) {
        i -> folders.insert(this);
    }
}
Folder::~Folder()
{
    for (auto i : messages) {
        i->folders.erase(this);
    }
}

Folder& Folder::operator=(const Folder &f)
{
    for (auto i : messages) {
        i -> folders.erase(this);
    }
    for ( auto i : messages) {
        i -> folders.insert(this);
    }
    return *this;
}

void print(const Folder &f)
{
    for (auto i: f.messages) {
        print(*i);
    }
}

void swap(Folder &f1, Folder &f2)
{
    using std::swap;
    for (auto i: f1.messages) {
        i ->remove(f1);
    }
    for (auto i : f2.messages ) {
        i -> remove(f2);
    }
    swap(f1.messages, f2.messages);
    for (auto i : f1.messages ) {
        i ->save(f1);
    }
    for (auto i : f2.messages) {
        i -> save(f2);
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    return 0;
}

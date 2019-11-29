//
//  Screen.h
//  NewJourneyOfCPlusPlus.git
//
//  Created by 王子昱 on 2019/11/28.
//  Copyright © 2019 王子昱. All rights reserved.
//



#ifndef Screen_h
#define Screen_h

#include <iostream>
#include <string>
#include <vector>

class Screen{
public:
    typedef std::string::size_type pos;
    
    friend class Windows_mgr;
//    windows_mgr can access private varibales
//    friend void Windows_mgr::clear(ScreenIndex);
//    in this way, the windows_mgr should declare before screen
    
    Screen() = default;
    
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c){};
    
    char get() const
    {
//        隐式内连
        return contents[cursor];
    }
    
    inline char get(pos ht, pos wd) const;
//    显式内连
    
    Screen &move(pos r, pos c);
//    可以之后被设为内联
    
    void some_member() const
    {
        ++access_ctr;
    }
    
    Screen &set(char);
    Screen &set(pos, pos, char);
    
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    
    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }
    
    
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;
//    mutable: in const member, it can also be changed
    void do_display(std::ostream &os) const {os << contents << std::endl;}

};

class Windows_mgr
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
    
    ScreenIndex addScreen(const Screen&);
private:
    
    std::vector<Screen> screens{Screen(24, 80, ' ')};
    
};

#endif /* Screen_h */

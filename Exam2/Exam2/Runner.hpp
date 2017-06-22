//
//  Runner.hpp
//  Exam2
//
//  Created by Josiah on 6/22/17.
//  Copyright © 2017 Josiah. All rights reserved.
//

#ifndef Runner_hpp
#define Runner_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Runner{
    string firstname, lastname;
    int pace = 0;
public:
    string get_firstname();
    string get_lastname();
    int get_pace();
    bool operator<(Runner& r);
    bool operator>(Runner& r);
    friend ostream& operator<<(ostream& os, Runner& r);
    friend istream& operator>>(istream& is, Runner& r);
};

#endif /* Runner_hpp */

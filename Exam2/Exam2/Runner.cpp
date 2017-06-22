//
//  Runner.cpp
//  Exam2
//
//  Created by Josiah on 6/22/17.
//  Copyright © 2017 Josiah. All rights reserved.
//

#include "Runner.hpp"

string Runner::get_firstname(){
    return firstname;
}
string Runner::get_lastname(){
    return lastname;
}
int Runner::get_pace(){
    return pace;
}
bool Runner::operator<(Runner &r){
    return pace<r.pace;
}
bool Runner::operator>(Runner &r){
    return pace>r.pace;
}
ostream& operator<<(ostream& os, Runner& r){
    os << r.get_firstname() << " " << r.get_lastname() << " " << r.get_pace();
    return os;
}
istream& operator>>(istream& is, Runner& r){
    is >> r.firstname >> r.lastname >> r.pace;
    return is;
}

/**
 *      Name: Bradey Lounsbury
 *      Date: February 5, 2020
 *      Email: bl396918@ohio.edu
 *      Desc: Implementation file of "friend.h" 
 */
#include "friend.h"
using namespace std;

//constructor
Friend::Friend() {
    name = "No Friend";
    bday = Date();
}

//accessors
string Friend::get_name() const{
    return name;
}
Date Friend::get_bday() const{
    return bday;
}


//these compare both name and bday
bool Friend::operator == (const Friend& other) const{
    return (name == other.get_name() && bday == other.get_bday());
}
bool Friend::operator != (const Friend& other) const{
    return (name != other.get_name() || bday != other.get_bday());
}


//ignores '\n' before and after each friend then inputs a friend
void Friend::input(istream& ins) {
    while (ins.peek() == '\n' || ins.peek() == '\r')    
    {
        ins.ignore();
    }
    getline(ins, name);
    ins >> bday;
    if (ins.peek() == '\n' || ins.peek() == '\r')
    {
        ins.ignore();
    }
}
void Friend::output(ostream& outs) const{
    outs << name << endl << bday;   //had to remove endl after bday bc when output to file, has extra '\n' which 
}                                   //creates a blank friend when loading from file again

istream& operator >> (istream& ins, Friend& f) {
    f.input(ins);
    return ins;
}

ostream& operator << (ostream& outs, const Friend& f) {
    f.output(outs);
    return outs;
}
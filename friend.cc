/**
 *      Name: Bradey Lounsbury
 *      Date: February 5, 2020
 *      Email: bl396918@ohio.edu
 *      Desc: Implementation file of "friend.h" 
 */
#include "friend.h"
using namespace std;

Friend::Friend() {
    name = " ";
    bday = Date();
}

string Friend::get_name() const{
    return name;
}

Date Friend::get_bday() const{
    return bday;
}

bool Friend::operator == (const Friend& other) const{
    return (name == other.get_name() && bday == other.get_bday());
}

bool Friend::operator != (const Friend& other) const{
    return (name != other.get_name() || bday != other.get_bday());
}

void Friend::input(istream& ins) {
    getline(ins, name);
    ins >> bday;
    if (ins.peek() == '\n' || ins.peek() == '\r')
    {
        ins.ignore();
    }
}

void Friend::output(ostream& outs) const{
    outs << name << endl << bday << endl;
}

istream& operator >> (istream& ins, Friend& f) {
    f.input(ins);
    return ins;
}

ostream& operator << (ostream& outs, Friend& f) {
    f.output(outs);
    return outs;
}
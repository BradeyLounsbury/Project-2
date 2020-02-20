/**
 *      Name: Bradey Lounsbury
 *      Date: February 5, 2020
 *      Email: bl396918@ohio.edu
 *      Desc: Implementation file of "fbfriends.h" 
 */
#include "fbfriends.h"
#include <algorithm>
using namespace std;

//constructor
FBFriends::FBFriends() {
    used = 0;
    capacity = 5;
    current_index = 0;
    data = new Friend[capacity];
}

//BIG 3
FBFriends::~FBFriends() { //destructor
    delete[] data;
}

FBFriends::FBFriends(const FBFriends& other) { //copy constructor
    used = other.used;
    capacity = other.capacity;
    current_index = other.current_index;
    data = new Friend[capacity];
    copy(other.data, other.data+used, data);
}

void FBFriends::operator= (const FBFriends& other) { //assignment op
    if (this == &other)
    {
        return;
    }
    delete[] data;
    used = other.used;
    capacity = other.capacity;
    current_index = other.current_index;
    data = new Friend[capacity];
    copy(other.data, other.data + used, data);
}


//iterators
void FBFriends::start() {
    current_index = 0;
}

void FBFriends::advance() {
    current_index++;
}

bool FBFriends::is_item() {     //checks if iterator is on a friend
    return (current_index <= used-1);
}

Friend FBFriends::current() {
    return data[current_index];
}

void FBFriends::remove_current() {
    if (is_item())
    {
        for (int i = current_index; i < used - 1; i++)
        {
            data[i] = data[i + 1];
        }
        used--;
    }
}

void FBFriends::insert(const Friend& f) { //adds friend before current_index
    used++;
    if (used == capacity)
    {
        resize();
    }
    for (int i = used; i > current_index; i--)
    {
        data[i] = data[i-1];
    }
    data[current_index] = f;
}

void FBFriends::attach(const Friend& f) { //adds friend after current_index
    used++;
    if (used == capacity)
    {
        resize();
    }
    for (int i = used; i > current_index + 1; i--)
    {
        data[i] = data[i-1];
    }
    data[current_index+1] = f;
}


void FBFriends::show_all(ostream& outs) const {
    for (int i = 0; i < used; i++)
    {
        outs << "Name: " << data[i].get_name() << endl;
        outs << "Birthday: " << data[i].get_bday() << endl << endl;
    }    
}

void FBFriends::bday_sort() {   //uses bubble sort to sort by earliest bday to latest
    bool done = false;
    int i;
    Friend tmp;
    while (!done)
    {
        done = true;
        i = 0;
        while (i < used-1)
        {
            if (data[i].get_bday() < data[i+1].get_bday())
            {
                tmp = data[i];
                data[i] = data[i+1];
                data[i+1] = tmp;
                done = false;
            }
            i++;
        }
    }
}

Friend FBFriends::find_friend(const std::string& name) const {  //returns friend of same name
    Friend tmp;
    for (int i = 0; i < used; i++)
    {
        if (name == data[i].get_name())
        {
            return data[i];
        }
    }
    return tmp;
}

bool FBFriends::is_friend(const Friend& f) const {
    for (int i = 0; i < used; i++)
    {
        if (f == data[i])
        {
            return true;
        }
    }
    return false;
}

void FBFriends::load(istream& ins) {
    while (!ins.eof())
    {
        if (ins.peek() == '\n' || ins.peek() == '\r')
        {
            return;
        }
        if (used == capacity)
        {
            resize();
        }
        ins >> data[current_index];
        current_index++;
        used++;
    }
}

void FBFriends::save(std::ostream& outs) {
    int j;
    for (int i = 0; i < used - 1; i++)
    {
        outs << data[i] << endl;
        j = i;
    }
    j++;
    outs << data[j];
}

void FBFriends::resize() {  //increases friend array by 5
    capacity += 5;
    Friend* tmpptr;
    tmpptr = new Friend[capacity];
    copy(data, data+used, tmpptr);
    delete[] data;
    data = tmpptr;
}
#include "friend.h"
using namespace std;

int main() {
    Friend uno, dos;
    cout << "Enter name then bday: ";
    uno.input(cin);
    uno.output(cout);

    cout << "Enter another name then bday: ";
    dos.input(cin);

    cout << "Friend uno: ";
    uno.output(cout);
    cout << "\nFriend dos: ";
    dos.output(cout);

    cout << "Are they equal?\n";
    if (uno == dos)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}
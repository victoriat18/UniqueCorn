#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Unicorn {
private:
    string name;

    //shared list of taken names
    static vector<string> takenNames;

public:
    //Constructor
    Unicorn(string n) {

        //checks if name already exists
        for (string used : takenNames) {
            if (used == n) {
                cout << "Error: Unicorn name '" << n << "' is already taken!" << endl;
                name = "";
                return;
            }
        }

        //assign name if not taken
        name = n;
        takenNames.push_back(n);

        cout << "Unicorn '" << name << "' created!" << endl;
    }

    //destructor
    ~Unicorn() {
        if (name != "") {
            for (int i = 0; i < takenNames.size(); i++) {
                if (takenNames[i] == name) {
                    takenNames.erase(takenNames.begin() + i);
                    break;
                }
            }

            cout << "Unicorn '" << name << "' destroyed and name freed!" << endl;
        }
    }

    void print() {
        cout << "Unicorn name: " << name << endl;
    }
};

//defines static variable
vector<string> Unicorn::takenNames;

int main() {
    Unicorn u1("Sparkle");
    Unicorn u2("Twinkle");
    Unicorn u3("Sparkle"); //should print an error since this name is taken for u1.

    u1.print();
    u2.print();
    u3.print();

    return 0;
}
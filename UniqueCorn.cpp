#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Unicorn {
private:
    string name; // stores the unicorn name

    //shared list of taken names currently used for the unicorns
    static vector<string> takenNames;

public:
    //Constructor
    Unicorn(string n) {

        //checks if name already taken
        for (string used : takenNames) {
            if (used == n) {
                cout << "Error: Unicorn name '" << n << "' is already taken!" << endl;
                name = "";
                return;
            }
        }

        //assign name if not taken, add to the shared list
        name = n;
        takenNames.push_back(n);

        cout << "Unicorn '" << name << "' created!" << endl;
    }

    //destructor, runs automatically when a unicorn is destoryed
    ~Unicorn() {
        //only remove the name if this unicorn was created sucessfully
        if (name != "") {
            for (int i = 0; i < takenNames.size(); i++) {
                if (takenNames[i] == name) {
                    //remove the name so another unicorn can use it
                    takenNames.erase(takenNames.begin() + i);
                    break;
                }
            }

            cout << "Unicorn '" << name << "' destroyed and name freed!" << endl;
        }
    }
//display the unicorn name
    void print() {
        cout << "Unicorn name: " << name << endl;
    }
};

//defines static variable outside the class
vector<string> Unicorn::takenNames;

int main() {
    //created two unicorns with unique names
    Unicorn u1("Sparkle");
    Unicorn u2("Twinkle");
    //attempt to duplicate
    Unicorn u3("Sparkle"); //should print an error since this name is taken for u1.
//prints each unicorn's name
    u1.print();
    u2.print();
    u3.print();

    return 0;
}
/*COMSC 210 | LAb 27 | Lawrence Bryant
IDE used: VSC*/
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

void adder(map<string, tuple<int, string, string>>&);
/*void deleter(map<string, tuple<int, string, string>>&, string);
void friendUp(map<string, tuple<int, string, string>>&, string);
void friendDown(map<string, tuple<int, string, string>>&, string);
void searcher(map<string, tuple<int, string, string>>&, string);
*/

int main() 
{
    cout << "Area 0";
    // declarations
    map<string, tuple<int, string, string>> villagerColors;

    cout << "Area 1";
    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    tuple<int, string, string> aud = make_tuple(6, "wolf", "Hello there Island Representative");
    tuple<int, string, string> ray = make_tuple(4, "cat", "Hi Island Rep!");
    tuple<int, string, string> mar = make_tuple(9, "squirrel", "Seize the day");
    villagerColors["Audie"] = {aud};
    villagerColors["Raymond"] = {ray};
    villagerColors.insert(make_pair("Marshal", mar));

    cout << "Area 2";

    // access the map using a range-based for loop
    cout << "Villagers and their data:" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        cout << " [" <<get<0>(pair.second);
        cout << ", " <<get<1>(pair.second);
        cout << ", " <<get<2>(pair.second) << "]\n";


        cout << endl;
    }

    int x = 0;
    while(x != 6)
    {
        cout << "1. Add Villager\n2. Delete Villager\n3. Increase Friendship\n4. Decrease Friendship\n5. Search for Villager\n6. Exit";
        cin >> x;

        if(x == 1)
        {
            adder(villagerColors);
        }
        if(x == 2)
        {
            string name;
            cout << "Enter villager's name: ";
            cin >> name;
            //deleter(villagerColors, name);
        }
        if(x == 3)
        {
            string name;
            cout << "Enter villager's name: ";
            cin >> name;
            //friendUp(villagerColors, name);
        }
        if(x == 4)
        {
            string name;
            cout << "Enter villager's name: ";
            cin >> name;
            //friendDown(villagerColors, name);
        }
        if(x == 5)
        {
            string name;
            cout << "Enter villager's name: ";
            cin >> name;
            //searcher(villagerColors, name);
        }
        
    }

    // access the map using iterators
    /*cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }*

    // delete an element
    

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;
*/
    return 0;
}
/*
void adder(map<string, tuple<int, string, string>>& vill)
{
    string name;
    int freind;
    string spec;
    string phrase;
    cout << "Villager's name: \n";
    cin >> name;
    cout << "Friendship Level: \n";
    cin >> freind;
    cout << "Species: \n";
    cin >> spec;
    cout << "Catchphrase: \n";
    cin >> phrase;
    tuple<int, string, string> newVill = make_tuple(freind, spec, phrase);
    vill[name] = {newVill};

    cout << name << " added\n";
}

void deleter(map<string, tuple<int, string, string>>& vill, string name)
{
    vill.erase(name);
}

void freindUp(map<string, tuple<int, string, string>>& vill, string name)
{
    auto it = vill.find(name);
    if(it != vill.end())
    {
        get<0>(vill.at(name))+= 1;
    }
    else
    {
        cout << "Villager does not exist\n";
    }
    
}

void freindDown(map<string, tuple<int, string, string>>& vill, string name)
{
    auto it = vill.find(name);
    if(it != vill.end())
    {
        get<0>(vill.at(name))-= 1;
    }
    else
    {
        cout << "Villager does not exist\n";
    }
}

void searcher(map<string, tuple<int, string, string>>& vill, string name)
{
    auto it = vill.find(name);
    if (it != vill.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << name << "\n";
        cout << endl;
    } else
        cout << endl << name << " not found.\n" << endl;
}*/
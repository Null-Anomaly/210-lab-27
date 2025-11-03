/*COMSC 210 | LAb 27 | Lawrence Bryant
IDE used: VSC*/
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

void deleter();
void adder();
void friendUp(map<string, tuple<int, string, string>>&, string);
void friendDown(map<string, tuple<int, string, string>>&, string);
void searcher(map<string, tuple<int, string, string>>&, string);


int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerColors;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    tuple<int, string, string> aud = make_tuple(6, "wolf", "Hello there Island Representative");
    tuple<int, string, string> ray = make_tuple(4, "cat", "Hi Island Rep!");
    tuple<int, string, string> mar = make_tuple(9, "squirrel", "Seize the day");
    villagerColors["Audie"] = {aud};
    villagerColors["Raymond"] = {ray};
    villagerColors.insert(make_pair("Marshal", mar));

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
    while(x != -1)
    {
        cout << "1. Increase Friendship\n2. Decrease Friendship\n3. Search for Villager\n4. Exit";
        cin >> x;

        if(x == 1)
        {
            string name;
            cout << "Enter villager's name: ";
            cin >> name;
            friendUp(villagerColors, name);
        }
        if(x == 2)
        {
            string name;
            cout << "Enter villager's name: ";
            cin >> name;
            friendDown(villagerColors, name);
        }
        if(x == 3)
        {
            string name;
            cout << "Enter villager's name: ";
            cin >> name;
            searcher(villagerColors, name);
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
    }*/ 

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
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
}
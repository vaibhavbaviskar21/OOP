#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    map<string, long long> statePopulation;

    statePopulation["Maharashtra"] = 39538223;
    statePopulation["Telangana"] = 29145505;
    statePopulation["Kerala"] = 21538187;
    statePopulation["Bengal"] = 20201249;
    statePopulation["Rajasthan"] = 13002700;
    statePopulation["Tamil Nadu"] = 12812508;
    statePopulation["Goa"] = 11799448;
    statePopulation["Madhya Pradesh"] = 10711908;
    statePopulation["Uttarakhand"] = 10439388;
    statePopulation["Himachal Pradesh"] = 10077331;

    string stateName;
    cout << "Enter the name of a state: ";
    getline(cin, stateName);

    auto it = statePopulation.find(stateName);
    if (it != statePopulation.end()) {
        cout << "The population of " << stateName << " is " << it->second << "." << endl;
    } else {
        cout << "State not found in the database." << endl;
    }

    return 0;   
}
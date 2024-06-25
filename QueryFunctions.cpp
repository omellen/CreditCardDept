// Copyright by Olivia Mellen, 4/09/2024
#include "QueryFunctions.h"
using namespace std;

// write your functions for the solution here
// For each function write its purpose, 
QueryFunctions::QueryFunctions() {}

//This function adds the customers information into a map
void QueryFunctions::appendCustomers(string name, string state, double debt) {
    names.push_back(name);
    states.push_back(state);
    debts.push_back(debt);
}

//This function returns the number of customers that are within the range
int QueryFunctions::getNumOfCustomers() {
    return names.size();
}

//The purpose of this function is to search through the debts vector
//that consist of the range of customers taken into account.
//Based on the index it is located at, it will find the element at
//that index in the names vector to return. 
string QueryFunctions::getHighestDebt() {
    vector<double> temp;
    for(double debt : debts) 
        temp.push_back(debt);
    sort(temp.begin(), temp.end());

    double highestDebtNum = temp.back();

    auto it = find(debts.begin(), debts.end(), highestDebtNum);
    int index = it - debts.begin();

    string nameAtIndex = names[index];

    return nameAtIndex;
}

//This functions serves to find if the string inputed is the beginning of
//any of the names in the names vector.
int QueryFunctions::numOfNameInstances(string subName) {
    int count = 0;
    if (subName.length() > 0) {
    for (string n : names) {
        if(n.length() >= subName.length()) {
            if (toupper(n.at(0)) == toupper(subName.at(0))) {
                bool found = true;
                for(int i = 1; i < subName.length(); i++) {
                    if (toupper(n.at(i)) != toupper(subName.at(i)))
                        found = false;
                }

                if (found == true)
                    count++;

                }

            }
            
        }

    }
    return count;
}

//This function takes the debt limt and returns the
//number of customers that are above that limit
int QueryFunctions::numOfHighDebt(double subDebt) {
    int count = 0;

    for (double d : debts) {
        if (d > subDebt)
            count++;
    }

    return count;
}

//This function loops through the debts that are included in 
//the range and counts the number of those that are debt free
int QueryFunctions::numDebtFree() {
    int count = 0;

    for (double d : debts) {
        if (d == 0) 
            count++;
    }

    return count;
}

// This is an override function that has the same functionality 
// as the original getNumOfCustomers but only if the customer
// is from a given state
int QueryFunctions::getNumOfCustomers(string state) {
    int count = 0;
    for (string s : states) {
        if (s == state)
            count++;
    }

    return count;
}

//This function overrides the original getHighestDebt function
//by taking into consideration the state that the customer is from.
//This function will sort through the debt vector and determine the 
//highest debt that is from a given state.
string QueryFunctions::getHighestDebt(string state) {
    vector<double> temp;
    string nameAtIndex = "NULL";

    bool stateFound = false;
    
    for(double debt : debts) 
        temp.push_back(debt);
    sort(temp.begin(), temp.end());

    for (int i = temp.size() - 1; i > 0; i--) {
        double highestDebtNum = temp.at(i);

        auto it = find(debts.begin(), debts.end(), highestDebtNum);
        int index = it - debts.begin();

        if (states[index] == state) {
            nameAtIndex = names[index];
            break;
        }
            
    }

    return nameAtIndex;
}

// This function ovverrides numOfNameInstances where it finds the number of
// customers that start with a string the user provides only if they are from
// a specified state.
int QueryFunctions::numOfNameInstances(string subName, string state) {
    int count = 0;
    int i = 0;

    for (string n : names) {
        if(n.length() >= subName.length()) {
            if (toupper(n.at(0)) == toupper(subName.at(0))) {
                bool found = true;
                for(int i = 1; i < subName.length(); i++) {
                    if (toupper(n.at(i)) != toupper(subName.at(i)))
                        found = false;
                }

                if (found == true && states[i] == state)
                    count++;

                
            }

        }
        i++;
    }

    return count;
}

// This function overrides the original numOfHighDebt which finds the
// number of customers with debt over a certain number.  In this override function,
// it only counts if they are from a specified state.
int QueryFunctions::numOfHighDebt(double subDebt, string state) {
    int count = 0;

    for (int i = 0; i < debts.size(); i++) {
        if (debts[i] > subDebt && states[i] == state)
            count++;
    }

    return count;
}

//This function overrides numDebtFree and finds the number
//of debt free customers that a re from a specified state that
//the user inputs
int QueryFunctions::numDebtFree(string state) {
    int count = 0;

    for (int i = 0; i < debts.size(); i++) {
        if (debts[i] == 0 && states[i] == state) 
            count++;
    }

    return count;
}

#pragma once
#ifndef QUERYFUNCTIONS_H_
#define QUERYFUNCTIONS_H_

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Write your functions' prototypes here 
// Explain why you chose certain parameter types 
// (ref or not, const or not) for each function. 

class QueryFunctions {
    public:
        //Default constructor
        QueryFunctions();
        //This functions inputs all info of customer in a line
        //and will append each to designated vectors
        void appendCustomers(string name, string state, double debt);
        //Only returns the number of customers so doesn't need 
        //any parameters
        int getNumOfCustomers();
        //Can sort through debt vector to find so doesn't
        //need any parameters
        string getHighestDebt();
        //Counts the number of customers that start with
        //a specific string so parameter needs to include
        //extra info about which string they are looking for
        int numOfNameInstances(string subName);
        //Counts the number of customers that have a
        //debt about a certain num so parameter needs to include
        //extra info about which limit they are looking for
        int numOfHighDebt(double subDebt);
        //Counts the number of debt free which is already included
        //in the debt vector
        int numDebtFree();

        //Ovverrides the above functions but include a 
        //state parameter in order to double check 
        //what state they are looking for
        int getNumOfCustomers(string state);
        string getHighestDebt(string state);
        int numOfNameInstances(string subName, string state);
        int numOfHighDebt(double subDebt, string state);
        int numDebtFree(string state);
        
    private:
        //Vectors for each of the pieces of info 
        //a customer includes
        vector<string> names = {};
        vector<string> states = {};
        vector<double> debts = {};
};

#endif
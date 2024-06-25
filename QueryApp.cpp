// Copyright Olivia Mellen 
// Purpose : This is a project that was completed in CSE278 Systems 1 Class.
//           There is a list of customers that includes there name, State, and dept. 
//           When ran by doing g++ QueryApp.cpp QueryFunctions.cpp -o QueryApp,
//           the program with ask for a min and max of customers which is the customers
//           betweena certain range on the list. It will then ask for the customer's name 
//           which doesn have to be the full name; it could be the first few letters of
//           the name. Each customer has a number associated whihc is their credit card dept.
//           The next prompt asks the user to list the limit, or the lowest dept, that
//           the user is looking for. lastly, it will ask for the state that tyhe user is 
//           looking for the customer to be from. After running, the program will give a report
//           of statistics and all the customers that are within the criteria.

// Coding Trail for all your solution
// Attempt #2: I was not properly implementing the default constructor. I was doing 
//             QueryFunctions query instead of QueryFunctions
// Attempt #3: Although everything was working well, I was getting an error because
//             I wasn't taking into consideration the fact that the user may input the max
//             number first.
// Attempt #4: Within this attempt, I added a new function to QueryFuntions that
//             sorted the vector debts to find the highest number in the vector
//             befire using that index to find which name belongs to that number
// Attempt #5 and 6:  I had spelling errors in the output, capitalized Debt and accidently spelling dept
// Attempt #7: I implemented the function numOfNameInstances which will sort through the names
//             vector and return back how many name start with that string
// Attempt #8, 9, 10, 11: I'm having trouble with the previous tests that did not incorporate
//             the numOfNameInstances so for now I am moving on and will come back later to figure out how to solve that.  
// Attempt #12: Finished step 3 within one attempt, added a new method that found all customers above the debt limit.
// Attempt #13: Finished Step 4 within one attempt, which was adding a function that found all customers that were debt free
// Attempt #14: Completed Step 5 first report and almost second but forgot to implement the samll bit of code
//              to capitalize the initals of the state they are from
// Attempt #15: Completed the first two steps of step 5 and have both override functions working.
// Last Attempt: I took many attempts before this becasue I was havin error on previous steps that I had already solved.
//              I needed to check to make sure that when numOfNameInstances was being called that the string the user sent
//              was actually > than 0 in length(). It didn't check that so it gave me errors for previous inputs that did
//              not include a name.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "QueryFunctions.h"
using namespace std;

int main()
{
   int minNum, maxNum;
   std::string state;
   std::string name;
   int debtLimit;
   // Program Intro
   cout << "---------------------------------------------"<< endl;
   cout << "Customer Query Application"<< endl;
   cout << "---------------------------------------------" << endl;
   cout << "Enter customer numbers range:" << std::endl;
   cin >> minNum >> maxNum;
   
    if (minNum > maxNum) {
        int temp = minNum;
        minNum = maxNum;
        maxNum = temp;
    }
   
   cout << "Enter the customer's name:" << std::endl;
   cin >> name;
   cout << "Enter debt limit:" << std::endl;
   cin >> debtLimit;
   cout << "Enter the state initials:" << std::endl;
   cin >> state;

    //This code capitalizes the first letter and
    //make the rest lowercase in the name
    for (int i = 0; i < name.length(); i++ ) {
        if (i == 0) 
            name.at(0) = toupper(name.at(i));
        else
            name.at(i) = tolower(name.at(i));
    }
    
    //This capitalizes all letters in the state
    //that the user inputs
    for (int i = 0; i < state.length(); i++) {
        state.at(i) = toupper(state.at(i));
    }

   // Complete the rest of the solution
    QueryFunctions query = QueryFunctions();

    std::ifstream fileInput("CustomerData.csv");
    int count = 1;
    std::string line;

    //Inputs that file that customer info is coming from
    //and takes the range of customers before putting that 
    //info into a QueryFunctions object
    while(getline(fileInput, line)) {
        string tempName;
        string tempState;
        double tempDebt;
        
        if (count >= minNum && count <= maxNum) {
            std::istringstream ss(line);
            ss >> tempName >> tempState >> tempDebt;
            query.appendCustomers(tempName, tempState, tempDebt);
        }
        count++;
    }

    //FINAL OUTPUT
    cout << "---------------------------------------------" << endl;
    cout << "U.S. Report" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "#of customers: " << query.getNumOfCustomers() << endl;   
    cout << "Highest debt: " << query.getHighestDebt() << endl;
    cout << "#of customer names begining with '" << name << "': " << query.numOfNameInstances(name) << endl;
    cout << "#of customers with debt over $" << debtLimit << ": " << query.numOfHighDebt(debtLimit) << endl;
    cout << "#of customers debt free: " << query.numDebtFree() << endl;
    cout << "---------------------------------------------" << endl;
    cout << state << " Report" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "#of customers: " << query.getNumOfCustomers(state) << endl;   
    cout << "Highest debt: " << query.getHighestDebt(state) << endl;
    cout << "#of customer names begining with '" << name << "': " << query.numOfNameInstances(name, state) << endl;
    cout << "#of customers with debt over $" << debtLimit << ": " << query.numOfHighDebt(debtLimit, state) << endl; 
    cout << "#of customers debt free: " << query.numDebtFree(state) << endl;
    
    return 0;
}

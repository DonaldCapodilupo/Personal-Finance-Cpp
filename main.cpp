#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;


void setupDatabase();

string displayList(vector<string>);

void mainMenu();

void addAccount();

void removeAccount();

void updateBalances();

void viewBalances();


int main() {
    string userChoice;
    vector<string> mainMenuOptions(5);
    mainMenuOptions[0] = "Update Account Balances";
    mainMenuOptions[1] = "Add an Account";
    mainMenuOptions[2] = "Remove an Account";
    mainMenuOptions[3] = "Display Balances";
    mainMenuOptions[4] = "Exit";
    cout << "What option would you like to choose?" << endl;
    userChoice = displayList(mainMenuOptions);
    if (userChoice == "Exit"){
        return 0;
    }
    else if(userChoice == "Update Account Balances"){
        cout << "User chose to update account balances\n";
    }




    std::cout << "User chose " + userChoice;
    return 0;
}

string displayList(vector<string> listToDisplay) {
    int num = 1;
    for (const auto &item : listToDisplay) {
        std::cout << to_string(num) + ") " + item << "\n";
        num += 1;
    }
    int userChoice;
    cin >> userChoice;
    return listToDisplay.at(userChoice - 1);
}
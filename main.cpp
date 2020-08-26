#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <direct.h>
#include <io.h>
#ifdef WINDOWS
include <direct.h>
#define GetCurrentDir _getcwd
#else
//#include <unistd.h>
#define GetCurrentDir getcwd
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdio>
#include <stdlib.h>
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <windows.h>
#include <sys/stat.h>
#include <fstream>

#endif



using namespace std;


void setupDirectories();

void setupFiles();

string get_current_dir() {
    char buff[FILENAME_MAX]; //create string buffer to hold path
    GetCurrentDir( buff, FILENAME_MAX );
    string current_working_dir(buff);
    string databaseDirectory = current_working_dir + "\\Databases";

    _mkdir("C:\\Program Files\\Personal Finance Cpp");
    return current_working_dir;
}

string displayList(vector<string>);

void mainMenu();

void addAccount();

void removeAccount();

void updateBalances();

void viewBalances();


int main() {
    string currentDirectory = get_current_dir();
    setupDirectories();
    setupFiles();

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
        cout << "Exiting the program.";
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

void setupDirectories(){
    _mkdir("C:\\Documents");
    _mkdir("C:\\Personal Finance");
    _mkdir(R"(C:\\Personal Finance\\Databases)");
    _mkdir(R"(C:\\Personal Finance\\Historical Documents)");
}

void setupFiles(){
    std::ofstream databaseFile;
    databaseFile.open(R"(C:\\Personal Finance\\Databases\\Databases.txt)");
    databaseFile << "Account Nickname,Amount";
    databaseFile.close();

    std::ofstream historicalFile;
    historicalFile.open(R"(C:\\Personal Finance\\Historical Documents\\Historical Data.txt)");
    historicalFile << "Date,Account Nickname,Amount";
    historicalFile.close();
}
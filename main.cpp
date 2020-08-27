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
#include <cstdlib>

#endif



using namespace std;


int setupDirectories();

int setupFiles();

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
    else if (userChoice == "Add an Account"){
        addAccount();
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

int setupDirectories(){
    _mkdir("C:\\Documents");
    _mkdir("C:\\Personal Finance");
    _mkdir(R"(C:\\Personal Finance\\Databases)");
    _mkdir(R"(C:\\Personal Finance\\Historical Documents)");
    return 0;
}

int setupFiles(){
    cout << "Setting up directories" << endl;
    fstream databaseFile;
    databaseFile.open(R"(C:\\Personal Finance\\Databases\\Databases.txt)");
    if (!databaseFile.is_open()){
        std::ofstream databaseFileCreate;
        cout << "Creating new Database file." << endl;
        databaseFileCreate.open(R"(C:\\Personal Finance\\Databases\\Databases.txt)");
        databaseFileCreate << "Account Nickname,Amount\n";
        databaseFileCreate.close();
    }
    else {
        databaseFile.close();
        cout << "Database file was found." << endl;
    }

    fstream historicalFile;
    historicalFile.open(R"(C:\\Personal Finance\\Historical Documents\\Historical Data.txt)",ios::out | ios::app);
    if (!historicalFile.is_open()){
        std::ofstream historicalFileCreate;
        cout << "Creating new Historical documents directory." << endl;
        historicalFileCreate.open(R"(C:\\Personal Finance\\Databases\\Historical Documents.txt)");
        historicalFileCreate << "Account Nickname,Amount\n";
        historicalFileCreate.close();
        cout << "Historical file has been created" << endl;
        return 0;

    }
    else{
        historicalFile.close();
        cout << "Historical file was found." << endl;
        return 0;
    }

}

void addAccount(){
    string accountName;
    string accountBalance;
    cout << "What is the name of the account?\n";
    cin.ignore();
    getline(cin,accountName);
    cout<< "What is the current balance of the account?\n";

    getline(cin,accountBalance);


    std::ofstream databaseFile;
    databaseFile.open(R"(C:\Personal Finance\Databases\Databases.txt)", ios::out | ios::app);
    databaseFile << (accountName+","+accountBalance) <<endl;
    databaseFile.close();
}
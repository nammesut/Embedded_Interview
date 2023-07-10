/*
* File: Employee.cpp
* Author: NGUYEN HOANG NAM
* Date: 09/07/2023
* Class: Employee
* Description: This is file to define method in Employee class
*/

#include "Employee.hpp"
#include "Table_Info.hpp"

using namespace std;

/*
* Function: Constructor
* Description: This constructor will be implemented once it be called
* Input:
*   _database: database of the dishes
*   _amount: amount of the tables
* Output:
*   return: None
*/
Employee::Employee(list<Food> _database, uint8_t _amount) {
    int AMOUNT_OF_TABLES;

    database.assign(_database.begin(), _database.end());
    
    printf("\n\t%7s\t", "Amount of the tables");
    for(int i = 1; i <= _amount; i++) {
        printf("\t%3d", i);
        TableInfo tb(i, false);

        databaseTable.push_back(tb);
    }

    printf("\n\t%7s\t", "Status");
    for(auto item : databaseTable) {
        if(item.getStatus() == false)
            printf("\t%3c", 'O');
        else
            printf("\t%3c", 'X');
    }

    cout << "Choose the table: ";
    cin >> _amount;



}
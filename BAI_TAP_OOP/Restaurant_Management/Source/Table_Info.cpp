/*
* File: Table_Info.cpp
* Author: NGUYEN HOANG NAM
* Date: 09/07/2023
* Class: Table_Info
* Description: This is file to define method in Management class
*/

#include "Food.hpp"
#include "Table_Info.hpp"

/*
* Function: Constructor
* Description: This constructor will be implemented once it be called
* Input:
*   _table: number of the table
*   _status: status of the table
* Output:
*   return: None
*/
TableInfo::TableInfo(uint8_t _table, bool _status) {
    table = _table;
    status = _status;
}

/*
* Function: get table
* Description: This function used to get number of the table
* Input:
*   None
* Output:
*   return: number of the table
*/
uint8_t TableInfo::getTable() {
    return table;
}

/*
* Function: get status
* Description: This function used to get status of the table
* Input:
*   None
* Output:
*   return: status of the table (true or false)
*/
bool TableInfo::getStatus() {
    return status;
}

/*
* Function: add dish
* Description: This function used to add dish 
* Input:
*   fo: dishes
*   _amount: amount of the dishes
* Output:
*   return: None
*/
void TableInfo::addDish(Food fo, uint8_t _amount) {
    int ID;
    string DISH_NAME;

    cout << "Enter the ID: ";
    cin >> ID;
    cout << "Enter the name: ";
    cin >> DISH_NAME;
    cout << "Enter the amount: ";
    cin >> _amount;
}
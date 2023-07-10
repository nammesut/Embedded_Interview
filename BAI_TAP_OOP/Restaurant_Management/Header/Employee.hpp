/*
* File: Employee.hpp
* Author: NGUYEN HOANG NAM
* Date: 09/07/2023
* Description: This is library file for declare Employee class
*/

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <iostream>
#include <list>
#include "Food.hpp"
#include "Table_Info.hpp"
using namespace std;

class Employee {
    private:
        list<Food> database;
        list<TableInfo> databaseTable;
    public:
        Employee(list<Food> _database, uint8_t _amount);
};

#endif
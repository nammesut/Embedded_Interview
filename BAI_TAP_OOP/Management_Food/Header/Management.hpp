/*
* File: Management.hpp
* Author: NGUYEN HOANG NAM
* Date: 09/07/2023
* Description: This is library file for declare Management class
*/

#ifndef MANAGEMENT_HPP
#define MANAGEMENT_HPP
#include <iostream>
#include <list>
#include "Food.hpp"

class Management {
    private: 
        list<Food> Database;
        uint8_t numOfTable;
        void addDish();
        void updateDish();
        void removeDish();
        void listOfDishes();
        void setNumOfTable();
    public: 
        Management();
        list<Food> getDatabase();
        uint8_t getNumOfTable();
};

#endif
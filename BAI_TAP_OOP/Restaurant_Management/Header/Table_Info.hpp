/*
* File: Table_Info.hpp
* Author: NGUYEN HOANG NAM
* Date: 09/07/2023
* Description: This is library file for declare Table infomation class
*/

#ifndef TABLE_INFO_HPP
#define TABLE_INFO_HPP
#include <iostream>
#include <list>
#include "Food.hpp"

using namespace std;

class TableInfo {
    private: 
        uint8_t table;
        bool status;
        typedef struct {
            Food fo;
            uint8_t amount;
        }typeDish;
        list<typeDish> databaseDish;
    public:
        TableInfo(uint8_t _table, bool _status);
        uint8_t getTable();
        bool getStatus();
        void addDish(Food fo, uint8_t _amount);
        void updateDish(uint8_t _id, uint8_t _amount);
        void removeDish(uint8_t _id);
};

#endif
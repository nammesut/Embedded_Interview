/*
* File: Food.hpp
* Author: NGUYEN HOANG NAM
* Date: 09/07/2023
* Description: This is library file for declare Food class
*/

#ifndef FOOD_HPP
#define FOOD_HPP
#include <iostream>
#include <string>

using namespace std;

class Food {
    private:
        int id;
        string dishName;
        uint32_t dishPrice;
        void setId();
    public:
        Food(string _dishName, uint32_t _dishPrice);
        int getId();
        string getDishName();
        uint32_t getDishPrice();
};

#endif

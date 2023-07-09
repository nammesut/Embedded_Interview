/*
* File: Food.cpp
* Author: NGUYEN HOANG NAM
* Date: 09/07/2023
* Class: Food
* Description: This is file to define function in Food class
*/

#include "Food.hpp"

/*
* Function: Constructor
* Description: This constructor will be implemented once it be called
* Input:
*   Dish name, dish price
* Output:
*   return: None
*/
Food::Food(string _dishName, uint32_t _dishPrice){
    dishName = _dishName;
    dishPrice = _dishPrice;
    setId();
}

/*
* Function: set ID
* Description: This function used to set the id of dishes
* Input:
*   None
* Output:
*   return: None
*/
void Food::setId(){
    static int ID = 100;
    id = ID;
    ID++;
}

/*
* Function: get ID
* Description: This function used to get the id of dishes
* Input:
*   None
* Output:
*   return: id
*/
int Food::getId(){
    return id;
}

/*
* Function: get dish name
* Description: This function used to get the dish name
* Input:
*   None
* Output:
*   return: dish name
*/
string Food::getDishName(){
    return dishName;
}


/*
* Function: get dish price
* Description: This function used to get the dish price
* Input:
*   None
* Output:
*   return: dish price
*/
uint32_t Food::getDishPrice(){
    return dishPrice;
}
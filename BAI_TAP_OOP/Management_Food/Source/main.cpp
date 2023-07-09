/*
* File: main.cpp
* Author: NGUYEN HOANG NAM
* Date: 09/07/2023
* Description: This is main file for restaurant management
*/

#include <iostream>
#include "Food.hpp" 
#include "Management.hpp" 
#include "Menu.hpp"

typedef enum {
    BACK = 0,
    MANAGEMENT,
    EMPLOYEE
}tydeMenu;

int main()
{
    Menu menu;
    int key;

    while(1) {
        ENTER_INFORMATION(menu.showCommandMenu(), &key, key < 0);

        switch((tydeMenu)key) {
            case BACK:
                printf("You choised exit!\n");
                return 0;
            case MANAGEMENT: {
                Management mana;
            }
            case EMPLOYEE:
                
                break;
        }
    }
    return 0;
}
/*
* File: Menu.hpp
* Author: NGUYEN HOANG NAM
* Date: 09/07/2023
* Description: This is library file for declare Menu class
*/

#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>

/*
* Macro function
* Description: This used to display infomation in terminal
* Input:
*   content: content need display
*   variable: variable to enter
*   condition: condition for the loop
* Output:
*   return: None
*/
#define ENTER_INFORMATION(content, variable, condition) \
    do{                                                 \
        content;                                        \
        scanf("%d", variable);                          \
    }while(condition);

class Menu {
    public: 
        void showCommandMenu();
        void showCommandManagement();
        void showCommandEmployee();
};
#endif

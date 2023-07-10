/*
* File: Menu.cpp
* Author: NGUYEN HOANG NAM
* Date: 09/07/2023
* Class: Menu
* Description: This is file to define method in Menu class
*/

#include "Menu.hpp"

/*
* Function: show command menu
* Description: This method used to show the command of main display
* Input:
*   None
* Output:
*   return: None
*/
void Menu::showCommandMenu() {
    printf("\n\n\t\t     RESTAURANT MANAGEMENT\n\n");
    printf("\t***************** MENU *******************\n");
    printf("\t**  1. Management                       **\n");
    printf("\t**  2. Employee                         **\n");
    printf("\t**  0. Exit                             **\n");
    printf("\t******************************************\n");
    printf("Choose one of these options: ");
}

/*
* Function: show command management
* Description: This method used to show the command of management display
* Input:
*   None
* Output:
*   return: None
*/
void Menu::showCommandManagement() {
    printf("\n\n\t\t      MANAGEMENT DISPLAY\n\n");
    printf("\t******************MENU ******************\n");
    printf("\t**  1. Add dish                        **\n");
    printf("\t**  2. Update dish                     **\n");
    printf("\t**  3. Remove dish                     **\n");
    printf("\t**  4. Display list of dishes          **\n");
    printf("\t**  5. Set number of tables            **\n");
    printf("\t**  0. Return                          **\n");
    printf("\t*****************************************\n");
    printf("Choose one of these options: ");
}

/*
* Function: show command employee
* Description: This method used to show the command of employee display
* Input:
*   None
* Output:
*   return: None
*/
void Menu::showCommandEmployee() {
    printf("\n\n\t\t      EMPLOYEE DISPLAY\n\n");
    printf("\t******************MENU ******************\n");
    printf("\t**  1. Add dish                        **\n");
    printf("\t**  2. Update dish                     **\n");
    printf("\t**  3. Remove dish                     **\n");
    printf("\t**  4. Display list of dishes          **\n");
    printf("\t**  5. Pay                             **\n");
    printf("\t**  0. Return                          **\n");
    printf("\t*****************************************\n");
    printf("Choose one of these options: ");
}

/*
* Function: show command update dish
* Description: This method used to show the command of update dish display
* Input:
*   None
* Output:
*   return: None
*/
void Menu::showCommandUpdateDish() {
    printf("\t***************** MENU *******************\n");
    printf("\t**  1. Update name                      **\n");
    printf("\t**  2. Update price                     **\n");
    printf("\t**  0. Exit                             **\n");
    printf("\t******************************************\n");
    printf("Choose one of these options: ");
}
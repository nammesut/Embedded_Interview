#include "Menu.hpp"

void Menu::showCommandMenu() {
    printf("\n\n\t\t     RESTAURANT MANAGEMENT\n\n");
    printf("\t***************** MENU *******************\n");
    printf("\t**  1. Management                       **\n");
    printf("\t**  2. Employee                         **\n");
    printf("\t**  0. Exit                             **\n");
    printf("\t******************************************\n");
    printf("Choose one of these options: ");
}

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
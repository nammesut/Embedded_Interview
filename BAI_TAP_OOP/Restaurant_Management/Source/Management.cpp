/*
* File: Management.cpp
* Author: NGUYEN HOANG NAM
* Date: 09/07/2023
* Class: Management
* Description: This is file to define method in Management class
*/

#include <iostream>
#include <list>
#include "Food.hpp"
#include "Management.hpp"
#include "Menu.hpp"

typedef enum {
    BACK = 0,
    ADD_DISH,
    UPDATE_DISH,
    REMOVE_DISH,
    LIST_DISHES,
    SET_NUM_OF_TABLES
}tydeMenu;

typedef enum {
    BACK = 0,
    UPDATE_NAME,
    UPDATE_PRICE
}tydeUpdate;

/*
* Function: Constructor
* Description: This constructor will be implemented once it be called
* Input:
*   None
* Output:
*   return: None
*/
Management::Management(){
    Menu menu;
    int key;

    while(1) {
        ENTER_INFORMATION(menu.showCommandManagement(), &key, key < 0);

 		switch((tydeMenu)key)
 		{
            case BACK:
                return;
 			case ADD_DISH:
			 	addDish();
 				break;
            case UPDATE_DISH:
                updateDish();
                break;
            case REMOVE_DISH:
                removeDish();
                break;
            case LIST_DISHES:
                listOfDishes();
                break;
            case SET_NUM_OF_TABLES:
                setNumOfTable();
                break;
            default:
                printf("This option isn't had! Try again!\n");
                break;
        }
    }	
}

/*
* Function: get dishes database
* Description: This function used to get dishes database
* Input:
*   None
* Output:
*   return: dishes database
*/
list<Food> Management::getDatabase(){
    return this->Database;
}

/*
* Function: set number of tables
* Description: This function used to get number of tables
* Input:
*   None
* Output:
*   return: number of tables
*/
uint8_t Management::getNumOfTable(){
    return this->numOfTable;
}

/*
* Function: add dish
* Description: This function used to add dish
* Input:
*   None
* Output:
*   return: None
*/
void Management::addDish(){
    string sDishName;
    uint32_t sDishPrice;

    cout << "Enter dish name: ";
    cin >> sDishName;
    cout << "Enter dish price: ";
    cin >> sDishPrice;

    Food fo(sDishName, sDishPrice);
    Database.push_back(fo);
}

/*
* Function: update dish
* Description: This function is used to update the dish following the dish name or dish price
* Input:
*   None
* Output:
*   return: None
*/
void Management::updateDish() {
    int ID, key;
    string sDishName;
    uint32_t sDishPrice;
    Menu mn;

    cout << "Enter the id: ";
    cin >> ID;

    auto position = Database.begin();
    for(auto item : Database) {
        if(item.getId() == ID) {
            ENTER_INFORMATION(mn.showCommandUpdateDish(), &key, key < 0);

            switch ((tydeUpdate)key) {
                case BACK:
                    return;
                case UPDATE_NAME:
                    cout << "Enter the name: ";
                    cin >> sDishPrice;
                    break;
                case UPDATE_PRICE:
                    cout << "Enter the price: ";
                    cin >> sDishPrice;
                    break;
                default:
                    printf("This option isn't had! Try again!\n");
                    break;
            }
        }
        position++;
    }
    cout << "List of dishes after being updated by ID " << ID << " !" << endl;
    listOfDishes();
}

/*
* Function: remove dish
* Description: This function is used to update the dish following the input dish id
* Input:
*   None
* Output:
*   return: None
*/
void Management::removeDish() {
    int ID;

    cout << "Enter the ID: ";
    cin >> ID;

    auto position = Database.begin();
    for(auto item : Database) {
        if(item.getId() == ID) {
            cout << "List of dishes after removing by ID " << ID << " !" << endl;
            Database.erase(position);
        }
        position++;
    }
    listOfDishes();
}

/*
* Function: display list dishes
* Description: This function used to display list dishes
* Input:
*   None
* Output:
*   return: None
*/
void Management::listOfDishes() {
    int stt = 1;

	printf("\n\t%7s\t%7s\t%12s\t%8s","STT", "ID", "DISH NAME", "DISH PRICE");

    for(Food item : Database){
        printf("\n\t%7d\t%7d\t%12s\t%8d", stt++, item.getId(), item.getDishName().c_str(), item.getDishPrice());
    }
}

/*
* Function: set number of tables
* Description: This function used to set number of tables
* Input:
*   None
* Output:
*   return: None
*/
void Management::setNumOfTable() {
    int iNumOfTables;

    cout << "Enter the number of tables: ";
    cin >> iNumOfTables;
    numOfTable = iNumOfTables;
    cout << "Has set the number of tables!" << endl;
}
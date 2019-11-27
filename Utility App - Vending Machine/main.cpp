//
//  main.cpp
//  Utility App - Vending Machine
//
//  Created by Leo Rogers on 13/11/2019.
//  Copyright © 2019 Leo Rogers. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <iterator>
#include <array>
#include <vector>
using namespace std;

string snacksChoc[] = {
    "Snickers", "Mars", "Twix", "Bounty", "Maltesers",
    "Aero", "Crunchie", "Dairy Milk", "Flake", "KitKat",
};

string snacksCrisps[] = {
     "Walkers Ready Salted", "Walkers Roast Chicken", "McCoys Original"
};

string drinksCans[] = {
    "Coke", "Fanta", "Redbull"
};

string drinksBottle[] {
    "Coke", "Fanta", "Water Bottle", "Tropicana Orange",
    "Drench", "Dr Pepper", "Sprite", "Tango"
};

string bulkCandy[] = {
    "Jelly Babies", "M&Ms", "Oreos", "Kettle Corn", "Nutella Go"
};

int menuCounter = 0;
int balance = 0;


void DisplayMenu(string listCategory[], int arraySize, string categoryName, double categoryPrice)
{
    cout << " -- " << categoryName << " -- " << endl;
    
    if (menuCounter != 0)
    {
        menuCounter = menuCounter - 1;
    }
    
    for (int i = 0; i < arraySize; i++, menuCounter = menuCounter + 2) {
        if (i == 8 ){
            if (listCategory[i + 1] == "") {
                cout << left << setw(27) << (to_string(menuCounter + 1) +".  " + listCategory[i])
                << right << setw(0) << (listCategory[i + 1])
                << '\n';
                i = i + 1;
            }
            else {
                cout << left << setw(27) << (to_string(menuCounter + 1) +".  " + listCategory[i])
                << right << setw(0) << (to_string(menuCounter + 2) +". " + listCategory[i + 1])
                << '\n';
                i = i + 1;
                menuCounter = menuCounter + 1;
            }
        }
        else if (i > 8){
            if (listCategory[i + 1] == "") {
                cout << left << setw(27) << (to_string(menuCounter + 1) +". " + listCategory[i])
                << right << setw(0) << (listCategory[i + 1])
                << '\n';
                i = i + 1;
            }
            else {
                cout << left << setw(27) << (to_string(menuCounter + 1) +". " + listCategory[i])
                << right << setw(0) << (to_string(menuCounter + 2) +". " + listCategory[i + 1])
                << '\n';
                i = i + 1;
                menuCounter = menuCounter + 1;
            }
        }
        else {
            if (listCategory[i + 1] == "") {
                cout << left << setw(27) << (to_string(menuCounter + 1) +".  " + listCategory[i])
                << right << setw(0) << (listCategory[i + 1])
                << '\n';
                i = i + 1;
            }
            else {
                cout << left << setw(27) << (to_string(menuCounter + 1) +".  " + listCategory[i])
                << right << setw(0) << (to_string(menuCounter + 2) +".  " + listCategory[i + 1])
                << '\n';
                i = i + 1;
            }
        }
    }
    cout << " -- Prices: £ " << categoryPrice << " -- " << endl;
    cout << endl;
}


void DisplayMenuFull() {
    cout << "* Snacks & Drinks Menu *"<< endl << endl;
    DisplayMenu(snacksChoc, sizeof(snacksChoc)/sizeof(snacksChoc[0]), "Chocolate Bars", 0.80);
    DisplayMenu(snacksCrisps, sizeof(snacksCrisps)/sizeof(snacksCrisps[0]), "Crisps", 0.80);
    DisplayMenu(drinksCans, sizeof(drinksCans)/sizeof(drinksCans[0]), "Canned Drinks", 0.80);
    DisplayMenu(drinksBottle, sizeof(drinksBottle)/sizeof(drinksBottle[0]), "Bottled Drinks", 1.30);
    DisplayMenu(bulkCandy, sizeof(bulkCandy)/sizeof(bulkCandy[0]), "Bulk Candy", 1.15);
}

vector<string> combineArrays()
{
    vector<string> combinedVector;
    combinedVector.reserve(sizeof(snacksChoc)/sizeof(snacksChoc[0]) + sizeof(snacksCrisps)/sizeof(snacksCrisps[0]) + sizeof(drinksCans)/sizeof(drinksCans[0]) + sizeof(drinksBottle)/sizeof(drinksBottle[0]) + sizeof(bulkCandy)/sizeof(bulkCandy[0]));
    combinedVector.insert(combinedVector.end(), begin(snacksChoc), end(snacksChoc));
    combinedVector.insert(combinedVector.end(), begin(snacksCrisps), end(snacksCrisps));
    combinedVector.insert(combinedVector.end(), begin(drinksCans), end(drinksCans));
    combinedVector.insert(combinedVector.end(), begin(drinksBottle), end(drinksBottle));
    combinedVector.insert(combinedVector.end(), begin(bulkCandy), end(bulkCandy));
    return combinedVector;
}

void Instructions()
{
    cout << "---- Instructions ----" << endl;
    cout << "Use 'M' to view menu" << endl;
    cout << "Use 'B' to view balance" << endl;
}

void DisplayBalance()
{
    cout << "Your balance: £ " << balance << endl;
}


bool outputOptions(string userInput)
{
    transform(userInput.begin(), userInput.end(),userInput.begin(), ::toupper);
    
    if(userInput == "M")
    {
        DisplayMenuFull();
        return true;
    }
    else if(userInput == "B")
    {
        DisplayBalance();
        return true;
    }
    return false;
}


int main()
{
    int itemUserSelects = 0; double userBalance = 0;
    DisplayMenuFull();
    cout << "--------------------------------------" << endl;
    Instructions();
    cout << endl;
    
    while(true)
    {
        cout << "Which item would you like to purchase? (1 - " << menuCounter << ")" << endl;
        cin >> itemUserSelects;
        cin.clear();
        cin.ignore(256, '\n');
        
        if(itemUserSelects < 1 || itemUserSelects > menuCounter && outputOptions(itemUserSelects)) == false)
        {
            break;
        }
    }
    
    cout << "What is your balance?" << endl << "£ ";
    cin >> userBalance;
    
    
    while (cin.fail())
    {
        cout << "Invalid input" << endl << endl;
        cout << "What is your balance?" << endl << "£ ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> userBalance;
    }
}

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
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
using namespace std;

string purchasedItem[] = {};

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

double categoryPrices[] = {0.8, 0.8, 0.8, 1.3, 1.5};
string categoryNames[] = {"Chocolate Bars", "Crisps", "Canned Drinks", "Bottled Drinks", "Bulk Candy"};

int menuCounter = 0;
double balance = 0;
bool exitVending = false;


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
    DisplayMenu(snacksChoc, sizeof(snacksChoc)/sizeof(snacksChoc[0]), categoryNames[0], categoryPrices[0]);
    DisplayMenu(snacksCrisps, sizeof(snacksCrisps)/sizeof(snacksCrisps[0]), categoryNames[1], categoryPrices[1]);
    DisplayMenu(drinksCans, sizeof(drinksCans)/sizeof(drinksCans[0]), categoryNames[2], categoryPrices[2]);
    DisplayMenu(drinksBottle, sizeof(drinksBottle)/sizeof(drinksBottle[0]), categoryNames[3], categoryPrices[3]);
    DisplayMenu(bulkCandy, sizeof(bulkCandy)/sizeof(bulkCandy[0]), categoryNames[4], categoryPrices[4]);
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
    cout << "Use 'T' to top up balance" << endl;
    cout << "Use 'E' to exit" << endl;
}

void DisplayBalance()
{
    cout << endl << "Your balance: £" << balance << endl << endl;
}

void getNewBalance()
{
    cout << endl << "Choose how much to add (£)" << endl;
    cin >> balance;
    cout << endl;
}

bool checkOptions(string userInput)
{
    transform(userInput.begin(), userInput.end(),userInput.begin(), ::toupper);
    
    if (userInput == "M")
    {
        return true;
    }
    else if (userInput == "B")
    {
        return true;
    }
    else if (userInput == "E")
    {
        return true;
    }
    else if (userInput == "T")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void outputOptions(string userInput)
{
    transform(userInput.begin(), userInput.end(),userInput.begin(), ::toupper);
    
    if(userInput == "M")
    {
        DisplayMenuFull();
    }
    else if(userInput == "B")
    {
        DisplayBalance();
    }
    else if (userInput == "T")
    {
        getNewBalance();
    }
    else if(userInput == "E")
    {
    }
}

bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
  
    return true;
}

void getBalance()
{
    if (balance == 0)
    {
        cout << endl << "Please enter your balance (£): ";
        cin >> balance;
        cout << endl;
    }
}

double getItemPrice(int itemNumber)
{
    int sizeOfSnacksChock = sizeof(snacksChoc)/sizeof(snacksChoc[0]),
    sizeOfSnacksChrisps = sizeof(snacksCrisps)/sizeof(snacksCrisps[0]),
    sizeOfDrinksCans = sizeof(drinksCans)/sizeof(drinksCans[0]),
    sizeOfDrinksBottle = sizeof(drinksBottle)/sizeof(drinksBottle[0]),
    sizeOfBulkCandy = sizeof(bulkCandy)/sizeof(bulkCandy[0]);
    
    if (itemNumber >= 0 && itemNumber < sizeOfSnacksChock)
    {
        //Price For Chocolate Bars
        return categoryPrices[0];
    }
    
    else if(itemNumber >= sizeOfSnacksChock && (itemNumber < sizeOfSnacksChock + sizeOfSnacksChrisps))
    {
        //Price For Crisps
        return categoryPrices[1];
    }
    
    else if (itemNumber >= sizeOfSnacksChock + sizeOfSnacksChrisps && (itemNumber < sizeOfSnacksChock + sizeOfSnacksChrisps + sizeOfDrinksCans))
    {
        //Price For Drinks Cans
        return categoryPrices[2];
    }
    
    else if (itemNumber >= sizeOfSnacksChock + sizeOfSnacksChrisps + sizeOfDrinksCans && (itemNumber < sizeOfSnacksChock + sizeOfSnacksChrisps + sizeOfDrinksCans + sizeOfDrinksBottle))
    {
        //Price For Drinks Bottles
        return categoryPrices[3];
    }
    
    else if (itemNumber >= sizeOfSnacksChock + sizeOfSnacksChrisps + sizeOfDrinksCans + sizeOfDrinksBottle && (itemNumber < sizeOfSnacksChock + sizeOfSnacksChrisps + sizeOfDrinksCans + sizeOfDrinksBottle + sizeOfBulkCandy))
    {
        //Price For Bulk Candy
        return categoryPrices[4];
    }

    else
    {
        return 0;
    }
}



string getItemCategoryName(int itemNumber)
{
    int sizeOfSnacksChock = sizeof(snacksChoc)/sizeof(snacksChoc[0]),
    sizeOfSnacksChrisps = sizeof(snacksCrisps)/sizeof(snacksCrisps[0]),
    sizeOfDrinksCans = sizeof(drinksCans)/sizeof(drinksCans[0]),
    sizeOfDrinksBottle = sizeof(drinksBottle)/sizeof(drinksBottle[0]),
    sizeOfBulkCandy = sizeof(bulkCandy)/sizeof(bulkCandy[0]);
    
    if (itemNumber >= 0 && itemNumber < sizeOfSnacksChock)
    {
        //Price For Chocolate Bars
        return categoryNames[0];
    }
    
    else if(itemNumber >= sizeOfSnacksChock && (itemNumber < sizeOfSnacksChock + sizeOfSnacksChrisps))
    {
        //Price For Crisps
        return categoryNames[1];
    }
    
    else if (itemNumber >= sizeOfSnacksChock + sizeOfSnacksChrisps && (itemNumber < sizeOfSnacksChock + sizeOfSnacksChrisps + sizeOfDrinksCans))
    {
        //Price For Drinks Cans
        return categoryNames[2];
    }
    
    else if (itemNumber >= sizeOfSnacksChock + sizeOfSnacksChrisps + sizeOfDrinksCans && (itemNumber < sizeOfSnacksChock + sizeOfSnacksChrisps + sizeOfDrinksCans + sizeOfDrinksBottle))
    {
        //Price For Drinks Bottles
        return categoryNames[3];
    }
    
    else if (itemNumber >= sizeOfSnacksChock + sizeOfSnacksChrisps + sizeOfDrinksCans + sizeOfDrinksBottle && (itemNumber < sizeOfSnacksChock + sizeOfSnacksChrisps + sizeOfDrinksCans + sizeOfDrinksBottle + sizeOfBulkCandy))
    {
        //Price For Bulk Candy
        return categoryNames[4];
    }

    else
    {
        return 0;
    }
}




void selectedItem(int itemNumber)
{
    double tempBalance = (balance - (getItemPrice(itemNumber-1)));
    
    if (tempBalance <= 0)
    {
        cout << "You have run out of funds!" << endl;
        cout << "You need an extra £" << setprecision(2) << stod((to_string(tempBalance).erase(0,1))) << endl << endl;
    }
    else
    {
        balance = balance - (getItemPrice(itemNumber-1));
        
        cout << combineArrays()[itemNumber-1] << " has been dispensed!" << endl;
        //cout << "You have chosen: " + combineArrays()[itemNumber-1] << endl;
        cout << "The price is: £" << setprecision(2) <<  getItemPrice(itemNumber-1) << endl;
        cout << "Your change is: £" << balance << endl << endl;
    }
}


bool CheckBalance(int itemNumber)
{
    int potentialBalance = balance - getItemPrice(itemNumber);
    if (potentialBalance < 0) {
        return false;
    }
    else {return true;}
}

vector <string> purchasedItems;
vector <string> suggestedItems;

string suggestedItemIteration(string arrayToSuggest[])
{
    string suggestedItemTemp;
    while (true)
    {
        //If the randomly selected item in the last two places of the vector dosen't equal the random selection then break the array.
        if (suggestedItems[suggestedItems.size()-1] != suggestedItemTemp || suggestedItems[suggestedItems.size()-2] != suggestedItemTemp)
        {
            break;
        }
        else
        {
            //Random Item in Canned Drinks Array
            int RandIndex = rand() % (sizeof(arrayToSuggest) / sizeof(arrayToSuggest[0]) -1 );
            return arrayToSuggest[RandIndex];
        }
    }
    return "";
}


string suggestItem(string itemName, string itemCategory)
{
    string suggestedItem, suggestedItemTemp;
    
    purchasedItems.push_back(itemName);
    
    //Checking Category Choc Bars Or Crisps
    if (itemCategory == categoryNames[0] || itemCategory == categoryNames[1])
    {
        suggestedItemTemp = suggestedItemIteration(drinksCans);
    }
    
    //Checking Category Drink Cans or Drink Bottles
    else if (itemCategory == categoryNames[2] || itemCategory == categoryNames[3])
    {
        // If category is drink cans
        if (itemCategory == categoryNames[2]) {
            suggestedItemTemp = suggestedItemIteration(snacksChoc);
        }
        
        //If category is drink bottles
        else if (itemCategory == categoryNames[3]) {
            suggestedItemTemp = suggestedItemIteration(bulkCandy);
        }
    }
    
    else if (itemCategory == categoryNames[4])
    {
        suggestedItemTemp = suggestedItemIteration(drinksBottle);
    }
    
    purchasedItems.push_back(suggestedItem);
    return suggestedItem;
}


int main()
{
    string itemUserSelects, addMoreFunds;
    bool balanceFirstSet = false, itemSelected = false;
    DisplayMenuFull();
    cout << "--------------------------------------" << endl;
    Instructions();
    cout << endl;
    
    while(true)
    {
        cout << "Choose item to purchase? (1 - " << menuCounter << ")" << endl << "Or Option (M, B, T, E)" << endl;
        cin >> itemUserSelects;
        cin.clear();
        cin.ignore(256, '\n');
        
        if(itemUserSelects == "E" || itemUserSelects == "e")
        {
            cout << endl << endl << "Thank you for using our machine" << endl;
            break;
        }
        
        if(itemSelected == true)
        {
            cout << "We have suggested" <<
            suggestItem((combineArrays()[stoi(itemUserSelects)]), (getItemCategoryName(stoi(itemUserSelects))));
        }
        
        if(isNumber(itemUserSelects))
        {
            if(CheckBalance(stoi(itemUserSelects)) && balanceFirstSet == false)
            {
                //Balance hasn't been set initially
                balanceFirstSet = true;
                getBalance();
            }
            else if (!CheckBalance(stoi(itemUserSelects)) && balanceFirstSet == true)
            {
                //Balance has already been set and run out
                cout << "Your balance has run out!" << endl <<
                "Do you want to add more funds (y/n)" << endl;
                
                cin.clear();
                cin.ignore(256, '\n');
                cin >> addMoreFunds;
                
                if (addMoreFunds == "y" || addMoreFunds == "Y") {
                    getBalance();
                }
                else {break;}
            }
        }
        
        if(isNumber(itemUserSelects) && (stoi(itemUserSelects) < 1 || stoi(itemUserSelects) > menuCounter))
        {
            cout << endl << "Choose a number in the valid range" << endl;
        }
        
        else if(checkOptions(itemUserSelects))
        {
            outputOptions(itemUserSelects);
        }
        
        else if(!checkOptions(itemUserSelects) && !isNumber(itemUserSelects))
        {
            cout << "Please choose a letter in the valid range" << endl;
        }
        
        else
        {
            selectedItem(stoi(itemUserSelects));
            itemSelected = true;
        }
    }
}

//
//  Utility App - Vending Machine
//
//  Created by Leo Rogers on 13/11/2019.
//  Copyright © 2019 Leo Rogers. All rights reserved.
//

//Libaries to include
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
using namespace std;

//Vector to store previously purchased items
vector<string> purchasedItem = {};

//Vector with the string items for Chocolate Snacks
vector<string> snacksChoc = {
    "Snickers", "Mars", "Twix", "Bounty", "Maltesers",
    "Aero", "Crunchie", "Dairy Milk", "Flake", "KitKat",
};

//Vector with the string items for Chrisps
vector<string> snacksCrisps = {
     "Walkers Ready Salted", "Walkers Roast Chicken", "McCoys Original", "Doritos"
};

//Vector with the string items for Canned Drinks
vector<string> drinksCans = {
    "Coke", "Fanta", "Redbull", "Sprite"
};

//Vector with the string items for Bottled Drinks
vector<string> drinksBottle {
    "Coke", "Fanta", "Water Bottle", "Tropicana Orange",
    "Drench", "Dr Pepper", "Sprite", "Tango"
};

//Vector with the string items for Bulk Candy
vector<string> bulkCandy = {
    "Jelly Babies", "M&Ms", "Oreos", "Kettle Corn", "Nutella Go", "Large Buttons"
};

//Setting a vector with the Category Prices in the same index order as the categories
vector<double> categoryPrices = {0.8, 0.8, 0.8, 1.3, 1.5};
vector<string> categoryNames = {"Chocolate Bars", "Crisps", "Canned Drinks", "Bottled Drinks", "Bulk Candy"}; //List of Category Display Names

int menuCounter = 0; //Menu counter for displaying menu
double balance = 0; //User balance
bool exitVending = false; //If user opts to exit the program



//This function displays a menu category with the given paramets of the category vector holding items, vector/array size, Category Display Name and Category Price.
void DisplayMenu(vector<string> listCategory, int arraySize, string categoryName, double categoryPrice)
{
    cout << " -- " << categoryName << " -- " << endl; //Output category name
    
    if (menuCounter != 0)
    {
        menuCounter = menuCounter - 1; //Resetting menu counter
    }
    
    //Outputting in two columns, assigning display number to item
    for (int i = 0; i < arraySize; i++, menuCounter = menuCounter + 2) {
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
    //Outputting price of category
    cout << " -- Prices: £ " << categoryPrice << " -- " << endl;
    menuCounter = menuCounter + 1;
    cout << endl;
}


void DisplayMenuFull() {
    //Display all menu Categories
    
    //Finding array size
    int snacksChocSize = int(snacksChoc.size()),
    snacksCrispsSize = int(snacksCrisps.size()),
    drinksCansSize = int(drinksCans.size()), drinksBottleSize = int(drinksBottle.size()),
    bulkCandySize = int(bulkCandy.size());
    
    cout << "* Snacks & Drinks Menu *"<< endl << endl;
    //Display menu categories
    DisplayMenu(snacksChoc, snacksChocSize, categoryNames[0], categoryPrices[0]);
    DisplayMenu(snacksCrisps, snacksCrispsSize, categoryNames[1], categoryPrices[1]);
    DisplayMenu(drinksCans, drinksCansSize, categoryNames[2], categoryPrices[2]);
    DisplayMenu(drinksBottle, drinksBottleSize, categoryNames[3], categoryPrices[3]);
    DisplayMenu(bulkCandy, bulkCandySize, categoryNames[4], categoryPrices[4]);
    
    menuCounter = 0;
}

vector<string> combineArrays()
{
    //Combine all Vectors into one vectors with all menu items
    vector<string> combinedVector;
    combinedVector.reserve(int(snacksChoc.size()) + int(snacksCrisps.size()) + int(drinksCans.size()) + int(drinksBottle.size()) + int(bulkCandy.size()));
    combinedVector.insert(combinedVector.end(), begin(snacksChoc), end(snacksChoc));
    combinedVector.insert(combinedVector.end(), begin(snacksCrisps), end(snacksCrisps));
    combinedVector.insert(combinedVector.end(), begin(drinksCans), end(drinksCans));
    combinedVector.insert(combinedVector.end(), begin(drinksBottle), end(drinksBottle));
    combinedVector.insert(combinedVector.end(), begin(bulkCandy), end(bulkCandy));
    return combinedVector;
}

//Finding size of combined size
int combinedVectorSize = int(combineArrays().size());
//Setting static vector
vector<string> combinedVector = combineArrays();


//Output menu Instructions
void Instructions()
{
    cout << "---- Instructions ----" << endl;
    cout << "Use 'M' to view menu" << endl;
    cout << "Use 'B' to view balance" << endl;
    cout << "Use 'T' to top up balance" << endl;
    cout << "Use 'E' to exit" << endl;
}

//Outputing the balance
void DisplayBalance()
{
    cout << endl << "Your balance: £" << balance << endl << endl;
}

//Prompt the user to input new balance and add to overall balance
void getNewBalance()
{
    int amountToAdd = 0;
    cout << endl << "Choose how much to add (£)" << endl;
    cin >> amountToAdd;
    balance = balance + amountToAdd;
    cout << endl;
}


//Check if user input includes a menu item selection
bool checkOptions(string userInput)
{
    //Converting sting to upper case
    transform(userInput.begin(), userInput.end(),userInput.begin(), ::toupper);
    
    //Return true if Input Included, else return false
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


//Execute correspoding functions to menu item selection
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

//Check if User Input is a number, return true or false
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
  
    return true;
}

//Get new balance from user and add to global variable
void getBalance()
{
    if (balance == 0)
    {
        cout << endl << "Please enter your balance (£): ";
        cin >> balance;
        cout << endl;
    }
}


//Find price of item from item number
double getItemPrice(int itemNumber)
{
    //Calculate sizes of the vectors
    int sizeOfSnacksChock = int(snacksChoc.size()),
    sizeOfSnacksChrisps = int(snacksCrisps.size()),
    sizeOfDrinksCans = int(drinksCans.size()),
    sizeOfDrinksBottle = int(drinksBottle.size()),
    sizeOfBulkCandy = int(bulkCandy.size());
    
    //Check pointers to see if the item number corresponds to range of array
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


//Find category name from Item Number
string getItemCategoryName(int itemNumber)
{
    //Calculate vector sizes
    int sizeOfSnacksChock = int(snacksChoc.size()),
    sizeOfSnacksChrisps = int(snacksCrisps.size()),
    sizeOfDrinksCans = int(drinksCans.size()),
    sizeOfDrinksBottle = int(drinksBottle.size()),
    sizeOfBulkCandy = int(bulkCandy.size());
    
    //Check number against vector ranges to see what the category is
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



//Once the user has selected an item this function outputs, price, change and if the user has run out of funds to make purchase
void selectedItem(int itemNumber)
{
    double tempBalance = (balance - (getItemPrice(itemNumber-1))); //Setting temp balance
    
    if (tempBalance <= 0) //If balance is 0 or less notify the user they have run out of funds.
    {
        cout << "You have run out of funds!" << endl;
        cout << "You need an extra £" << setprecision(2) << stod((to_string(tempBalance).erase(0,1))) << endl << endl;
    }
    else
    {
        //If funds are suffitient notify user of items
        balance = balance - (getItemPrice(itemNumber-1));
        
        cout << combineArrays()[itemNumber-1] << " has been dispensed!" << endl;
        //cout << "You have chosen: " + combineArrays()[itemNumber-1] << endl;
        cout << "The price is: £" << setprecision(2) <<  getItemPrice(itemNumber-1) << endl;
        cout << "Your change is: £" << balance << endl << endl;
    }
}


//Check if the user has a positive balance and the correct funds to make a purchase for the item selected
bool CheckBalance(int itemNumber)
{
    int potentialBalance = balance - getItemPrice(itemNumber);
    if (potentialBalance < 0) {
        return false;
        //Return false if balance is not suffitient
    }
    else {return true;}
}

//Setting vectors to store previously purchased items and previously suggested items as the user buys more items.
vector <string> purchasedItems = {};
vector <string> suggestedItems = {};

//Suggest a random item based on array
string suggestedItemIteration(vector<string> arrayToSuggest)
{
    string suggestedItemTemp;
    
    //Only suggest if a minimum of two purchases have been made
    while (suggestedItems.size() >= 2)
    {
        //If the randomly selected item in the last two places of the vector dosen't equal the random selection then break the array.
        if (suggestedItems[suggestedItems.size() -1] != suggestedItemTemp || suggestedItems[suggestedItems.size() -2] != suggestedItemTemp)
        {
            break;
        }
        else
        {
            //Random Item in Canned Drinks Array
            int RandIndex = (rand() % int(arrayToSuggest.size()) -1 );
            return arrayToSuggest[RandIndex];
        }
    }
    //Return null if item hasn't been suggested
    return "";
}

//Suggest user an item to purchase based on item name and category
string suggestItem(string itemName, string itemCategory)
{
    string suggestedItem, suggestedItemTemp;
    
    purchasedItems.push_back(itemName); //Add item to purchased items
    
    //Checking Category Choc Bars Or Crisps
    if (itemCategory == categoryNames[0] || itemCategory == categoryNames[1])
    {
        // Suggest a canned drink
        suggestedItemTemp = suggestedItemIteration(drinksCans);
        //Set variable to final suggested item
    }
    
    //Checking Category Drink Cans or Drink Bottles
    else if (itemCategory == categoryNames[2] || itemCategory == categoryNames[3])
    {
        // If category is drink cans
        if (itemCategory == categoryNames[2]) {
            //Suggest a chocolate bar
            suggestedItemTemp = suggestedItemIteration(snacksChoc);
        }
        
        //If category is drink bottles
        else if (itemCategory == categoryNames[3]) {
            //Suggest a bluk candy option
            suggestedItemTemp = suggestedItemIteration(bulkCandy);
        }
    }
    
    //If category is Bulk Candy
    else if (itemCategory == categoryNames[4])
    {
        //Suggest a drinks bottle
        suggestedItemTemp = suggestedItemIteration(drinksBottle);
    }
    
    //Add suggested item to vector to compare when purchasing futher items
    suggestedItems.push_back(suggestedItem);

    return suggestedItem; //Return the suggested item
}


int main()
{
    string itemUserSelects, addMoreFunds; //Declaring string variables
    bool balanceFirstSet = false, itemSelected = false; //Declaring boolean variables
    DisplayMenuFull(); //Display the entire menu
    cout << "--------------------------------------" << endl;
    Instructions(); //Display the instructions to use
    cout << endl;
    
    while(true) //Infinite loop to ask user to purchase items unless exited
    {
        cout << "Choose item to purchase? (1 - " << combinedVectorSize << ")" << endl << "Or Option (M, B, T, E)" << endl; //Asking user to select item
        cin >> itemUserSelects; //Storing input in item user selects
        cin.clear();
        cin.ignore(256, '\n');
        //Clearing console for next input
        
        //If the user chooses E the program will exit/loop will break
        if(itemUserSelects == "E" || itemUserSelects == "e")
        {
            cout << endl << endl << "Thank you for using our machine" << endl;
            break;
        }
        
        //If the user has selected a item and needs suggestion
        if(itemSelected == true)
        {
            //Try catch to run suggestion
            //Can return Threading errors as vectors overlap on the same thread
            try {
                string tempItemNameUserSelects = combinedVector[stoi(itemUserSelects)];
                string tempItemCategoryName = (getItemCategoryName(stoi(itemUserSelects)));
                
                //Suggesting item and sending in the Item Name of user selection and the item category name from selection.
                string tempSuggestItem = suggestItem(tempItemNameUserSelects, tempItemCategoryName);
                
                //If the Suggested item return not null
                if(tempSuggestItem != "")
                {
                    //Output the suggestion
                    cout << endl << endl << "We have suggested: " << tempSuggestItem << endl << endl;
                }
                throw;
                
            } catch (exception) { //Catch error and continue execution
            }
        }
        
        if(isNumber(itemUserSelects)) //If the input is a int number
        {
            //Check if the balance can meet a positive number and balance has not been set already
            if(CheckBalance(stoi(itemUserSelects)) && balanceFirstSet == false)
            {
                //Balance hasn't been set initially
                balanceFirstSet = true;
                getBalance(); //Prompt the user to input balance
            }
            else if (!CheckBalance(stoi(itemUserSelects)) && balanceFirstSet == true) //If balance is negative and balance has been initially set
            {
                //Balance has already been set and run out
                cout << "Your balance has run out!" << endl <<
                "Do you want to add more funds (y/n)" << endl;
                
                cin.clear();
                cin.ignore(256, '\n'); //Clear console
                
                cin >> addMoreFunds; //Does the user want to input more funds
                
                if (addMoreFunds == "y" || addMoreFunds == "Y") {
                    getBalance(); //If yes then get new balance
                }
                else {break;} //Exit program/break loop
            }
        }
        
        //If the input is a number put the number is not in the range of the menu items.
        if(isNumber(itemUserSelects) && (stoi(itemUserSelects) < 1 || stoi(itemUserSelects) > combinedVectorSize))
        {
            cout << endl << "Choose a number in the valid range" << endl;
            //Output to enter a nuber in the valid range
        }
        
        //If user input matches a menu option letter
        else if(checkOptions(itemUserSelects))
        {
            outputOptions(itemUserSelects); //Run options
        }
        
        //If not equal to a number and letter isn't in the menu options
        else if(!checkOptions(itemUserSelects) && !isNumber(itemUserSelects))
        {
            cout << endl << endl << "Please choose a letter in the valid range" << endl << endl;
            //Output to choose a letter in valid range
            //Valid range is the presented menu options
        }
        
        //Else if validation is all complete without errors
        else
        {
            selectedItem(stoi(itemUserSelects)); //Run selected item function sending in the user input as int
            itemSelected = true; //Item selected marked as true
        }
    }
}

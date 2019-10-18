#include <iostream>
using namespace std;

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date) {
    customerName = name;
    currentDate = date;
}

string ShoppingCart::GetCustomerName() const {
    return customerName;
}

string ShoppingCart::GetDate() const {
    return currentDate;
}


void ShoppingCart::AddItem(ItemToPurchase item) {
cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string name) {
int CartSize = cartItems.size();

for(int i = 0; i < cartItems.size(); i++) {
if (cartItems.at(i).GetName() == name){
cartItems.erase(cartItems.begin() + i);
}
if(CartSize == cartItems.size()){
  cout<<"There are no items in the cart."<<endl;
}
}
}

void ShoppingCart::ModifyItem(ItemToPurchase item){
    bool itemToModify = false;

    for (unsigned int i = 0; i < cartItems.size(); ++i){
        if (cartItems.at(i).GetName() == item.GetName()) {
            cartItems.at(i).SetQuantity(item.GetQuantity());
            itemToModify = true;
        }
    }

    if (!itemToModify) {
        cout << "Item not found in cart. Nothing modified.";
    }
    return;
}
    
int ShoppingCart::GetNumItemsInCart() {
    int size = 0;

    for (int i = 0; i < cartItems.size(); ++i){
         size += cartItems.at(i).GetQuantity();
    }

    return size;
}

double ShoppingCart::GetCostOfCart() {
    int sum = 0;

    for (unsigned int i = 0; i < cartItems.size(); ++i){
        sum = sum + (cartItems.at(i).GetPrice()*cartItems.at(i).GetQuantity());
    }
    return sum;
}


void ShoppingCart::PrintTotal() {
    unsigned i;
    int totalCost;

    totalCost = 0;

    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;

    if(cartItems.size() > 0) {
        for(i = 0; i < cartItems.size(); ++i) {
            cartItems.at(i).PrintItemCost();
        }
    }

    else {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }

    totalCost = GetCostOfCart();

    cout << endl << "Total: $" << totalCost << endl;
}

void ShoppingCart::PrintDescriptions() {
    unsigned i;

    cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
    cout << "Item Descriptions" << endl;

    if(cartItems.size() > 0) {
        for(i = 0; i < cartItems.size(); ++i) {
            cartItems.at(i).PrintItemDescription();
        }
    }

    else {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
}

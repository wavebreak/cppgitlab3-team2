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

}

void ShoppingCart::ModifyItem(ItemToPurchase item) {

        bool found = false;

        //Traverse the vector cartItems using a

        //for loop.

        for (vector<ItemToPurchase>::iterator itemList = cartItems.begin(); itemList != cartItems.end(); itemList++)

        {
            //If the current name of the list

            //matched with the required name.

            if ((*itemList).GetName() == item.GetName())

            {

                //If the name is found, then make

                //the boolean variable true.

                found = true;

                //Store the reference of the pointer

                //to object it to the item.

                ItemToPurchase& item = *itemList;

                //If the description is none, then

                //set the description.

                if (item.GetDescription() != "none")
                    item.SetDescription(item.GetDescription());

                //If the price is 0, then set the price

                //of the item.

                if (item.GetPrice() != 0)
                    item.SetPrice(item.GetPrice());

                //If the quantity is 0, then set the

                //quantity.

                if (item.GetQuantity() != 0)
                    item.SetQuantity(item.GetQuantity());

            }

        }

        //If the value of the variable found is not true,

        //then display an appropriate message.

        if (found != true)

        {

            cout << "Item not found in cart. ";

            cout << "Nothing modified." << endl;

        }

    }


int ShoppingCart::GetNumItemsInCart() {
    int size = 0;

    for (int i = 0; i < cartItems.size(); ++i){
         size += cartItems.at(i).GetQuantity();
    }

    return size;
}

double ShoppingCart::GetCostOfCart() {


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

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

}

void ShoppingCart::RemoveItem(string name) {

}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
    {
        bool found = false;
        //Traverse the vector cartItems using a loop
        for (auto & cartItem : cartItems) {
            if (cartItem.GetName() == item.GetName()) {
                found = true;
                ItemToPurchase &item = cartItem;
                if (item.GetDescription() != "none")
                    item.SetDescription(item.
                            GetDescription());
                if (item.GetPrice() != 0)
                    item.SetPrice(item.GetPrice());
                if (item.GetQuantity() != 0)
                    item.SetQuantity(item.GetQuantity());
            }
        }
        //If the value of the variable found is not true,
        if (!found) {
            cout << "Item not found in cart. Nothing modified." << endl;
        }
    }

    int ShoppingCart::GetNumItemsInCart() {

    }

    double ShoppingCart::GetCostOfCart() {

    }

    void ShoppingCart::PrintTotal() {
        unsigned i;
        int totalCost;

        totalCost = 0;

        cout << customerName << "'s Shopping Cart - " << currentDate << endl;
        cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;

        if (cartItems.size() > 0) {
            for (i = 0; i < cartItems.size(); ++i) {
                cartItems.at(i).PrintItemCost();
            }
        } else {
            cout << "SHOPPING CART IS EMPTY" << endl;
        }

        totalCost = GetCostOfCart();

        cout << endl << "Total: $" << totalCost << endl;
    }

    void ShoppingCart::PrintDescriptions() {
        unsigned i;

        cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
        cout << "Item Descriptions" << endl;

        if (cartItems.size() > 0) {
            for (i = 0; i < cartItems.size(); ++i) {
                cartItems.at(i).PrintItemDescription();
            }
        } else {
            cout << "SHOPPING CART IS EMPTY" << endl;
        }
    }
}
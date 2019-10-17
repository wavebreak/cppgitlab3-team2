#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

char PrintMenu(ShoppingCart& theCart){
   char menuOp;
   string name;
   string descr;
   int price;
   int quantity;
   
   cout << "MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl << endl;
   
   menuOp = ' ';
   
   while (menuOp != 'a' && menuOp != 'd' && menuOp != 'c' &&
         menuOp != 'i' && menuOp != 'o' && menuOp != 'q') {
      cout << "Choose an option:" << endl;
      cin >> menuOp;
   }
   
   switch(menuOp) {
      case 'a':
      {
          //add item to cart
         cin.ignore();
         
         cout << "ADD ITEM TO CART" << endl;
         cout << "Enter the item name:" << endl;
         getline(cin, name);
         
         cout << "Enter the item description:" << endl;
         getline(cin, descr);
      
         cout << "Enter the item price:" << endl;
         cin >> price;
      
         cout << "Enter the item quantity:" << endl;
         cin >> quantity;
         
         ItemToPurchase newItem(name, descr, price, quantity);
         theCart.AddItem(newItem);
         
         menuOp = ' ';
         cout << endl;
      }
      break;
      
      case 'd':
          //remove an item
          cin.ignore();

          cout << "REMOVE ITEM FROM CART" << endl;
          cout << "Enter name of item to remove:" << endl;
          getline(cin, name);

          theCart.RemoveItem(name);

          menuOp = ' ';
          cout << endl;

      break;
      
      case 'c':
      {
          //change item quantity
         cin.ignore();
         
         cout << "CHANGE ITEM QUANTITY" << endl;
         cout << "Enter the item name:" << endl;
         getline(cin, name);
         
         cout << "Enter the new quantity:" << endl;
         cin >> quantity;
         
         ItemToPurchase item;
         item.SetName(name);
         item.SetQuantity(quantity);
         
         theCart.ModifyItem(item);
         
         menuOp = ' ';
         cout << endl;
      }
      break;
      
      case 'i':
          //output item's description
         cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
         theCart.PrintDescriptions();
         
         menuOp = ' ';
         cout << endl;
      break;
      
      case 'o':
          //output shopping cart
         cout << "OUTPUT SHOPPING CART" << endl; 
         theCart.PrintTotal();
         
         menuOp = ' ';
         cout << endl;
      break;
   }
   
   return menuOp;
   
}

int main() {
   string custName;
   string today;
   char menuChoice;
   
   cout << "Enter customer's name:" << endl;
   getline(cin, custName);
   
   cout << "Enter today's date:" << endl;
   getline(cin, today);
   cout << endl;
   
   cout << "Customer name: " << custName << endl;
   cout << "Today's date: " << today << endl << endl;
   
   ShoppingCart myCart(custName, today);
   
   menuChoice = ' ';
   
   while(menuChoice != 'q') {
      menuChoice = PrintMenu(myCart);
   }
   
   return 0;
}
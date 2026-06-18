// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// class Menu
// {
// private:
//     string item;
//     int itemNo, price;

// public:
//     // constructor
//     Menu(int ItemNo, string Item, int Price)
//     {
//         item = Item;
//         itemNo = ItemNo;
//         price = Price;
//     }

//     string getItem() { return item; }

//     int getItemNo() { return itemNo; }

//     int getPrice() { return price; }
// };

// // cafe

// class Cafe
// {
// private:
// // allocating memory to menu items
//     vector<Menu> ve;

// public:
//     // add items used in constructor
//     add(int ItemNo, string Item, int Price)
//     {
//         // object for menu class
//         // |_______itemNo, itemName, itemPrice_______|
//         Menu menu(ItemNo, Item, Price);
//         ve.push_back(menu); // allocate memory
//     }

//     // order items from menu
//     order()
//     {
//         // display and get items 
//         for (int i = 0; i < ve.size(); i++)
//         {
//             cout << ve[i].getItemNo() << ". " << ve[i].getItem() << ": " << ve[i].getPrice() << endl;
//         }

//         int ord, quant;

//         std::cout << "\nEnter item number for order: ";
//         cin >> ord;
//         std::cout << "Enter quantity for item: ";
//         cin >> quant;

//         for (int i = 0; i < ve.size(); i++)
//         {
//             if (ord  == ve[i].getItemNo())
//             {
//                 int total = quant * ve[i].getPrice();
//                 cout << "Total bill is: " << total << endl;
//             }
//         }
//     }
// };

// int main()
// {
//     Cafe cafe;
//     // create menu
//     // |_______itemNo, itemName, itemPrice_______|
//     cafe.add(1, "Chicken Burger", 150);
//     cafe.add(2, "Znger Burger", 250);
//     cafe.add(3, "Potato Chips", 50);
//     cafe.add(4, "Juice", 100);

//     std::cout << " |_______Cafeteria Menu_______| \n"
//               << std::endl;
//     cafe.order();

//     return 0;
//     // cin.get();
//     system("Pause");

// }
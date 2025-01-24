#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

vector<string> Product;
vector<double> Quantity;
vector<double> Price;
int List = 0;
double Profit = 0;

void AddProduct() {
    string product;
    double quantity;
    double price;

    cout << endl << "Enter Product Name: ";
    cin >> product;
    cout << "Enter The Quantity of Product: ";
    cin >> quantity;
    cout << "Enter The Product Price: ";
    cin >> price;

    List += 1;
    Product.push_back(product);
    Quantity.push_back(quantity);
    Price.push_back(price);

    return;
}

void EditProduct() {
    string action;
    string choice;
    int list;
    string newproduct;
    double newquantity;
    double newprice;
    double newprofit;

cout << endl << "What to edit?" << endl << "[1] = Product change" << endl << "[2] = Change Investment" << endl << "; ";
cin >> action;
if (action == "1"){
    cout << endl << "What product would you like to change?" << endl << ": ";
    cin >> list;

    if (list > List) {
        cout << "That doesn't exist in the list" << endl;
        return;
    }

    cout << "What to change with " << Product[list - 1] << "?" << endl;
    cout << endl;
    cout << "[1] = Remove the Product" << endl;
    cout << "[2] = Change Product Name" << endl;
    cout << "[3] = Change Product Quantity" << endl;
    cout << "[4] = Change Product Price" << endl;
    cout << ": ";
    cin >> choice;

    if (choice == "1") {
        Product.erase(Product.begin() + list - 1);
        Quantity.erase(Quantity.begin() + list - 1);
        Price.erase(Price.begin() + list - 1);
        List -= 1;
    } else if (choice == "2") {
        cout << "What will be " << Product[list - 1] << " new Name?" << endl << ": ";
        cin >> newproduct;
        Product[list - 1] = newproduct;
    } else if (choice == "3") {
        cout << "What will be " << Product[list - 1] << " new Quantity?" << endl << ": ";
        cin >> newquantity;
        Quantity[list - 1] = newquantity;
        if (Quantity[list - 1] == 0) {
                Product.erase(Product.begin() + list - 1);
                Quantity.erase(Quantity.begin() + list - 1);
                Price.erase(Price.begin() + list - 1);
                List -= 1;
            }
    } else if (choice == "4") {
        cout << "What will be " << Product[list - 1] << " new Price?" << endl << ": ";
        cin >> newprice;
        Price[list - 1] = newprice;
    } else {
        cout << "!!!Invalid Action!!!" << endl;
    }
}else if (action == "2"){
    cout << "what is your new Investment: ";
            cin >> newprofit;
            Profit = newprofit;
            Profit *= -1;
            cout << endl;
} else {
    cout << "!!!Invalid Action!!!" << endl;
}

    return;
}

void ManageSales() {
    double bought;
    double profit;
    int list;


        cout << "What product have been bought?" << endl << "Enter the number on the list: ";
        cin >> list;
        cout << "How many have been bought?" << endl << ": ";
        cin >> bought;

        if (bought > Quantity[list - 1] || bought < 0) {
            cout << "!!!Invalid Input!!!";
        } else {
            Quantity[list - 1] -= bought;
            profit = bought * Price[list - 1];
            Profit += profit;

            if (Quantity[list - 1] == 0) {
                Product.erase(Product.begin() + list - 1);
                Quantity.erase(Quantity.begin() + list - 1);
                Price.erase(Price.begin() + list - 1);
                List -= 1;
            }
        }

cout << "Your Profit is ₱" << Profit << endl;

    return;
}

int main() {
    while (true) {
        string choice;

        cout << "<<<]Store Sales Managing System[>>>" << endl;

        if (!Product.empty()) {
            cout << "List - Product - Quantity - Price" << endl;
            for (int i = 0; i < List; i++) {
                cout << i + 1 << ". " << Product[i] << " - " << Quantity[i] << " - ₱" << Price[i] << endl;
            }
        } else {
            cout << "The Store is Currently Empty!!!" << endl;
            cout << "You Can't Manage your Sales yet!!!" << endl;
      while(Profit == 0){   
          if (Profit == 0){  
            cout << endl << "To Manage your Sales, Kindly Input your Starting Money" << endl;
            cout << "Investment: ";
            cin >> Profit;
            if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input" << endl;
        continue;
    }
            Profit *= -1;
            cout << endl;
            }
        }
        }

        cout << endl << "Choose Action" << endl;
        cout << "[1] = Add Product" << endl;
        cout << "[2] = Edit Storage" << endl;
        cout << "[3] = Manage Sales" << endl;
        cout << "Action: ";
        cin >> choice;

        if (choice == "1") {
            AddProduct();
        } else if (choice == "2") {
            EditProduct();
        } else if (choice == "3") {
            ManageSales();
        } else {
            cout << "!!!Invalid Action!!!" << endl;
        }
    }

    return 0;
}
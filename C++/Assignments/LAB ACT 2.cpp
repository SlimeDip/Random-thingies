#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Menu items and their prices
    const int MENU_SIZE = 4;
    string menuItems[MENU_SIZE] = {"Coffee", "Tea", "Sandwich", "Pastry"};
    double prices[MENU_SIZE] = {2.50, 1.75, 5.00, 3.00};
    
    // Variables for user input and total cost
    int choice = 0;
    int quantity = 0;
    double totalCost = 0.0;
    
    // Display the menu using a for loop
    cout << "Welcome to the Cafe!\n";
    cout << "Menu:\n";
    for (int i = 0; i < MENU_SIZE; ++i) {
        cout << i + 1 << ". " << menuItems[i] << " - $" << fixed << setprecision(2) << prices[i] << "\n";
    }

    // Ordering process using a while loop
    while (true) {
        cout << "\nEnter the number of the item you'd like to order (0 to finish): ";
        cin >> choice;
        
        if (choice == 0) {
            break; // Exit the loop if the user enters 0
        } 
        else if (choice <= MENU_SIZE && choice > 0) {
            cout << "Enter the quantity: ";
            cin >> quantity;

            if (quantity < 0) {
                cout << "Quantity cannot be negative. Please try again.\n";
                continue;
            }

            // Calculate the cost for the current item and add to total cost
            double itemCost = prices[choice - 1] * quantity;
            totalCost += itemCost;

            cout << "Added " << quantity << " " << menuItems[choice - 1] << "(s) to your order. Item cost: $" << fixed << setprecision(2) << itemCost << "\n";
            continue;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
            continue; // Skip the rest of the loop and prompt for input again
        }
    }

    // Output the total cost
    cout << "\nYour total order cost is: $" << fixed << setprecision(2) << totalCost << "\n";
    cout << "Thank you for ordering!\n";

    return 0;
}
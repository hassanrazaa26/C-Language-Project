#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int id;
    string name;
    double price;
};

class Supermarket {
private:
    vector<Item> items;

public:
    void addItem() {
        Item newItem;
        cout << "\nEnter Item ID: ";
        cin >> newItem.id;
        cout << "Enter Item Name: ";
        cin.ignore();
        getline(cin, newItem.name);
        cout << "Enter Item Price: $";
        cin >> newItem.price;
        items.push_back(newItem);
        cout << "\nItem added successfully!\n";
    }

    void editItem() {
        int itemId;
        cout << "\nEnter Item ID to Edit: ";
        cin >> itemId;

        auto it = find_if(items.begin(), items.end(), [itemId](const Item& item) {
            return item.id == itemId;
        });

        if (it != items.end()) {
            cout << "Enter New Item Name: ";
            cin.ignore();
            getline(cin, it->name);
            cout << "Enter New Item Price: $";
            cin >> it->price;
            cout << "\nItem edited successfully!\n";
        } else {
            cout << "\nItem not found!\n";
        }
    }

    void removeItem() {
        int itemId;
        cout << "\nEnter Item ID to Remove: ";
        cin >> itemId;

        auto it = find_if(items.begin(), items.end(), [itemId](const Item& item) {
            return item.id == itemId;
        });

        if (it != items.end()) {
            items.erase(it);
            cout << "\nItem removed successfully!\n";
        } else {
            cout << "\nItem not found!\n";
        }
    }

    void showItemDetails() {
        cout << "\nItem Details:\n";
        cout << setw(5) << "ID" << setw(20) << "Name" << setw(10) << "Price\n";
        cout << string(35, '-') << endl;

        for (const auto& item : items) {
            cout << setw(5) << item.id << setw(20) << item.name << setw(10) << "$" << fixed << setprecision(2) << item.price << endl;
        }
    }

    void generateBill() {
        int itemId, quantity;
        double total = 0;

        cout << "\nGenerate Bill:\n";
        cout << "Enter Item ID (0 to end): ";
        cin >> itemId;

        while (itemId != 0) {
            auto it = find_if(items.begin(), items.end(), [itemId](const Item& item) {
                return item.id == itemId;
            });

            if (it != items.end()) {
                cout << "Enter Quantity: ";
                cin >> quantity;
                total += it->price * quantity;
            } else {
                cout << "\nItem not found!\n";
            }

            cout << "Enter Item ID (0 to end): ";
            cin >> itemId;
        }

        cout << "\nTotal Bill: $" << fixed << setprecision(2) << total << "\n";
    }
};

int main() {
		cout<<" \n";
	cout<<"                ' W  E  L     C  O  M  E '\n";
	cout<<"                ``````````````````````````\n";

	cout<<"---------------------------------------------------------\n";
	cout<<"  Program  Devolper:    MOHAMMAD  HASSAN  RAZA \n";
	cout<<"---------------------------------------------------------\n";
	
    Supermarket supermarket;
    int choice;

    do {
        cout << "** Super Market Billing System **\n";
        cout<<"---------------------------------------------------------\n";
        cout << "1. Add Item\n";
        cout << "2. Edit Item\n";
        cout << "3. Remove Item\n";
        cout << "4. Show Item Details\n";
        cout << "5. Generate Bill\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                supermarket.addItem();
                break;
            case 2:
                supermarket.editItem();
                break;
            case 3:
                supermarket.removeItem();
                break;
            case 4:
                supermarket.showItemDetails();
                break;
            case 5:
                supermarket.generateBill();
                break;
            case 6:
                cout << "\nExiting Super Market Billing System. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 6);
cout<<endl;
system("Pause");
    return 0;
}

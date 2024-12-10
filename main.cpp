#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Item {
    string name;
    double price;
};

class BillGenerator {
private:
    vector<Item> items;
    double totalAmount;
    double discountPercentage;
    double gstRate;

public:
    BillGenerator() {
        totalAmount = 0.0;
        discountPercentage = 0.0;
        gstRate = 18;

        items.push_back({"Item A", 50.0});
        items.push_back({"Item B", 100.0});
        items.push_back({"Item C", 150.0});
        items.push_back({"Item D", 200.0});
    }

    void showItem() {
        cout << "\nAvailable Items:\n";
        for (int i = 0; i < items.size(); i++) {
            cout << i + 1 << ". " << items[i].name << " -$" << items[i].price << endl;
        }
    }

    void selectItems() {
        int choice, quantity;
        char moreItems;

        do {
            showItem();
            cout << "\nEnter the item number to add to bill: ";
            cin >> choice;

            if (choice < 1 || choice > items.size()) {
                cout << "Invalid choice! Please try again.\n";
                continue;
            }

            cout << "Enter quantity: ";
            cin >> quantity;

            totalAmount += items[choice - 1].price * quantity;

            cout << "Do you want to add more items? (Y/N): ";
            cin >> moreItems;
        } while (moreItems == 'Y' || moreItems == 'y');
    }

    void applyDiscount() {
        cout << "Enter discount percentage (if any, else 0): ";
        cin >> discountPercentage;
    }

    void applyTax() {
        double taxAmount = (totalAmount * gstRate) / 100;
        totalAmount += taxAmount;
    }

    void generateBill() {
        double discountAmount = (totalAmount * discountPercentage) / 100;
        totalAmount -= discountAmount;

        cout << "\n---------------------- BILL ----------------------\n";
        cout << fixed << setprecision(2);
        cout << "Total Amount (Before Discount and Tax): $" << totalAmount + discountAmount << endl;
        cout << "GST (" << gstRate << "%): +$" << (totalAmount + discountAmount) * gstRate / 100 << endl;
        cout << "---------------------------------------------------\n";
        cout << "Final Amount Due: $" << totalAmount << endl;
        cout << "---------------------- Thank You ----------------------";
    }

};

int main() {
    BillGenerator billGen;

    cout << "Welcome to the Bill Generator System!\n";

    billGen.selectItems();
    billGen.applyDiscount();
    billGen.applyTax();
    billGen.generateBill();

    return 0;
}
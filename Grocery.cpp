#include <iostream>
#include <string>

using namespace std;

// Structure to store product details
struct Product {
    int code;
    string name;
    float price;
    int quantity;
    Product* next;

    Product(int c, string n, float p, int q) : code(c), name(n), price(p), quantity(q), next(nullptr) {}
};

// Class to manage the grocery store system
class GroceryStore {
private:
    Product* head;

public:
    GroceryStore() : head(nullptr) {}

    void addProduct();
    void modifyProduct();
    void removeProduct();
    void listProducts();
    void generateBill();
};

// Function to add a new product
void GroceryStore::addProduct() {
    int code, quantity;
    string name;
    float price;

    cout << "Enter product code: ";
    cin >> code;
    cout << "Enter product name: ";
    cin >> name;
    cout << "Enter product price: ";
    cin >> price;
    cout << "Enter product quantity: ";
    cin >> quantity;

    Product* newProduct = new Product(code, name, price, quantity);
    newProduct->next = head;
    head = newProduct;

    cout << "Product added successfully.\n";
}

// Function to modify an existing product
void GroceryStore::modifyProduct() {
    int code;
    cout << "Enter product code to modify: ";
    cin >> code;

    Product* temp = head;
    while (temp != nullptr) {
        if (temp->code == code) {
            cout << "Enter new product name: ";
            cin >> temp->name;
            cout << "Enter new product price: ";
            cin >> temp->price;
            cout << "Enter new product quantity: ";
            cin >> temp->quantity;
            cout << "Product modified successfully.\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Product not found.\n";
}

// Function to remove a product
void GroceryStore::removeProduct() {
    int code;
    cout << "Enter product code to remove: ";
    cin >> code;

    Product* temp = head;
    Product* prev = nullptr;

    while (temp != nullptr && temp->code != code) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Product not found.\n";
        return;
    }

    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Product removed successfully.\n";
}

// Function to list all products
void GroceryStore::listProducts() {
    Product* temp = head;

    if (temp == nullptr) {
        cout << "No products available.\n";
        return;
    }

    cout << "Product Code\tName\t\tPrice\tQuantity\n";
    while (temp != nullptr) {
        cout << temp->code << "\t\t" << temp->name << "\t\t" << temp->price << "\t" << temp->quantity << "\n";
        temp = temp->next;
    }
}

// Function to generate a bill
void GroceryStore::generateBill() {
    int code, quantity;
    float total = 0;

    cout << "Enter product code to buy (-1 to end): ";
    cin >> code;

    while (code != -1) {
        cout << "Enter quantity: ";
        cin >> quantity;

        Product* temp = head;
        while (temp != nullptr) {
            if (temp->code == code) {
                if (temp->quantity >= quantity) {
                    temp->quantity -= quantity;
                    total += temp->price * quantity;
                    cout << "Added " << temp->name << " to bill.\n";
                } else {
                    cout << "Insufficient stock for " << temp->name << ".\n";
                }
                break;
            }
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Product not found.\n";
        }

        cout << "Enter product code to buy (-1 to end): ";
        cin >> code;
    }

    cout << "Total Bill Amount: " << total << "\n";
}

// Main function
int main() {
    GroceryStore store;
    int choice;

    do {
        cout << "\nGrocery Store Management System\n";
        cout << "1. Add Product\n";
        cout << "2. Modify Product\n";
        cout << "3. Remove Product\n";
        cout << "4. List Products\n";
        cout << "5. Generate Bill\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                store.addProduct();
                break;
            case 2:
                store.modifyProduct();
                break;
            case 3:
                store.removeProduct();
                break;
            case 4:
                store.listProducts();
                break;
            case 5:
                store.generateBill();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

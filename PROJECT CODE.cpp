#include <iostream>
using namespace std;

struct Book {
    int QUANTITY;
    string TITLE;
    string AUTHOR;
    string GENRE;
    double PRICE;
};

const int MAX_BOOKS = 10;
Book books[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Inventory is full, no space available\n";
        return;
    }

    cout << "Enter TITLE: ";
    cin >> books[bookCount].TITLE;  

    cout << "Enter AUTHOR: ";
    cin>> books[bookCount].AUTHOR;  

    cout << "Enter GENRE: ";
    cin>> books[bookCount].GENRE;  

    cout << "Enter QUANTITY: ";
    cin >> books[bookCount].QUANTITY;

    cout << "Enter PRICE: ";
    cin >> books[bookCount].PRICE;

    bookCount++;
    cout << "BOOKS ADDED IN INVENTORY\n";
}

void updateQuantity() {
    string TITLE;
    cout << "Enter the TITLE to update quantity: ";
    cin >> TITLE;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].TITLE == TITLE) {
            cout << "ENTER A NEW QUANTITY: ";
            cin >> books[i].QUANTITY;
            cout << "QUANTITY UPDATED\n";
            return ;
        }
    }

    cout << "INVALID CHOICE\n";
}

void calculateTotalValue()
 {
    double totalValue = 0;
    for (int i = 0; i < bookCount; i++) {
        totalValue += books[i].QUANTITY * books[i].PRICE;
    }

    cout << "TOTAL VALUE OF INVENTORY: $" << totalValue << "\n";
}

void searchByGenre() {
    string GENRE;
    cout << "ENTER GENRE: ";
    cin >> GENRE;  

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].GENRE == GENRE) {
            cout << "TITLE: " << books[i].TITLE << "\n";  
            cout << "AUTHOR: " << books[i].AUTHOR << "\n";  
            cout << "QUANTITY: " << books[i].QUANTITY << "\n";
            cout << "PRICE: $" << books[i].PRICE << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "NO BOOKS AVAILABLE IN MENTIONED GENRE\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n BOOK INVENTORY SYSTEM \n";
        cout << "1. ADD BOOK\n";
        cout << "2. UPDATE QUANTITY\n";
        cout << "3. CALCULATE INVENTORY VALUE\n";
        cout << "4. SEARCH GENRE\n";
        cout << "5. EXIT\n";
        cout << "ENTER CHOICE: ";
        cin >> choice;

        cin.ignore();  

        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            updateQuantity();
            break;
        case 3:
            calculateTotalValue();
            break;
        case 4:
            searchByGenre();
            break;
        case 5:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
              }
    }
     while(choice!=5);
     
return 0; 
}

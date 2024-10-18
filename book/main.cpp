#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <limits>
#include<regex>
using namespace std;
  string address, phone, card, name;
struct Book {
    string title;
    string author;
    double price;
};

bool isValidName(const string& str) {
    // Regular expression to match only uppercase and lowercase letters
    regex namePattern("^[a-zA-Z]+$");

    // Return true if the string matches the pattern, false otherwise
    return regex_match(str, namePattern);
}
bool isValidnum(const string& str) {
    // Regular expression to match only numbers 
    regex numPattern("^[0-9]+$");

    // Return true if the string matches the pattern, false otherwise
    return regex_match(str, numPattern);
}
// A collection of Fiction books and their prices
vector<Book> Fiction = {
    {" The Great Gatsby", "F. Scott Fitzgerald", 10.99},
    {" 1984", "George Orwell", 8.99},
    {" To Kill a Mockingbird", "Harper Lee", 12.99},
    {" Moby-Dick", "Herman Melville", 6.99},
    {" Pride and Prejudice", "Jane Austen", 10.99},
    {" The Catcher in the Rye", "J.D. Salinger", 8.99},
    {" The Lord of the Rings", "J.R.R. Tolkien", 12.99},
    {" Jane Eyre", "Charlotte Bronte", 6.99},
    {" The Hobbit", "J.R.R. Tolkien", 10.99},
    {" War and Peace", "Leo Tolstoy", 8.99}
};
// A collection of nonFictionBooks books and their prices
vector<Book> nonFictionBooks = {
    {" Sapiens: A Brief History of Humankind", "Yuval Noah Harari", 10.99},
    {" Educated", "Tara Westover", 8.99},
    {" The Immortal Life of Henrietta Lacks", "Rebecca Skloot", 12.99},
    {" Becoming", "Michelle Obama", 6.99},
    {" The Wright Brothers", "David McCullough", 10.99},
    {" The Diary of a Young Girl", "Anne Frank", 8.99},
    {" Into the Wild", "Jon Krakauer", 12.99},
    {" The Art of War", "Sun Tzu", 6.99},
    {" Guns, Germs, and Steel", "Jared Diamond", 10.99},
    {" Unbroken", "Laura Hillenbrand", 8.99}
};
// A collection of ChildrensBooks books and their prices
vector<Book> ChildrensBooks = {
    {" Where the Wild Things Are", "Maurice Sendak", 10.99},
    {" Harry Potter and the Sorcerer's Stone", "J.K. Rowling", 8.99},
    {" The Very Hungry Caterpillar", "Eric Carle", 12.99},
    {" Charlotte's Web", "E.B. White", 6.99},
    {" Green Eggs and Ham", "Dr. Seuss", 10.99},
    {" Goodnight Moon", "Margaret Wise Brown", 8.99},
    {" Alice's Adventures in Wonderland", "Lewis Carroll", 12.99},
    {" Matilda", "Roald Dahl", 6.99},
    {" The Lion, the Witch and the Wardrobe", "C.S. Lewis", 10.99},
    {" Anne of Green Gables", "L.M. Montgomery", 8.99}
};
// A collection of ScienceBooks books and their prices
vector<Book> ScienceBooks = {
    {" A Brief History of Time", "Stephen Hawking", 10.99},
    {" The Selfish Gene", "Richard Dawkins", 8.99},
    {" The Origin of Species", "Charles Darwin", 12.99},
    {" Cosmos", "Carl Sagan", 6.99},
    {" The Gene: An Intimate History", "Siddhartha Mukherjee", 10.99},
    {" Astrophysics for People in a Hurry", "Neil deGrasse Tyson", 8.99},
    {" Silent Spring", "Rachel Carson", 12.99},
    {" The Double Helix", "James D. Watson", 6.99},
    {" The Elegant Universe", "Brian Greene", 10.99},
    {" Why We Sleep", "Matthew Walker", 8.99}
};
// A collection of HistoryBooks books and their prices
vector<Book> HistoryBooks = {
    {" The Rise and Fall of the Third Reich", "William L. Shirer", 10.99},
    {" Team of Rivals: The Political Genius of Abraham Lincoln", "Doris Kearns Goodwin", 8.99},
    {" The Guns of August", "Barbara W. Tuchman", 12.99},
    {" 1776", "David McCullough", 6.99},
    {" Genghis Khan and the Making of the Modern World", "Jack Weatherford", 10.99},
    {" The Silk Roads: A New History of the World", "Peter Frankopan", 8.99},
    {" The Wright Brothers", "David McCullough", 12.99},
    {" A People's History of the United States", "Howard Zinn", 6.99},
    {" The Histories", "Herodotus", 10.99},
    {" The Diary of a Young Girl", "Anne Frank", 8.99}
};
//show the name of the book , author and price of book
void displayBooks(const vector<Book>& books)
{
    for (int i = 0; i < books.size(); i++)
    {

            cout << i + 1 << "- " << books[i].title << " by " << books[i].author
                 << ", Price: $" << books[i].price << endl<< endl;

    }
    cout << "--------------------------------------------------" << endl;
}
// To ensure that the user entered the correct number
int getValidChoice(int min, int max) {
    int choice;
    while (true)
    {
        cin >> choice;
        if (cin.fail() || choice < min || choice > max)
        {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << " Invalid input. Please enter a number between " << min << " and " << max << ": ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard any extra input
            return choice;
        }
    }
}

void buyBook() {
    double cart = 0;
    bool complete = false, buyAnother = false;

    do {
        cout << "   What type of books do you want?\n";
        cout << " 1- Fiction\n";
        cout << " 2- Non-Fiction\n";
        cout << " 3- Children's Books\n";
        cout << " 4- Science\n";
        cout << " 5- History\n";
        cout << "--------------------------------------------------" << endl;
        cout<<"Enter the number of the type of books you want"<<endl;
        int choice;
        vector<Book> selectedBooks;

        choice = getValidChoice(1, 5);

        switch (choice) {
            case 1: selectedBooks = Fiction; break;
            case 2: selectedBooks = nonFictionBooks; break;
            case 3: selectedBooks = ChildrensBooks; break;
            case 4: selectedBooks = ScienceBooks; break;
            case 5: selectedBooks = HistoryBooks; break;
        }
  system("cls");
        displayBooks(selectedBooks);

        cout << " Please enter the number of the book you want :\n ";
        int bookNumber;
        bookNumber = getValidChoice(1, selectedBooks.size());
          system("cls");
          cout << " Do you want to buy or borrow this book ? (1 for buy , 0 for borrow ) \n " ;
          int choice3 ;
            choice3  = getValidChoice(0, 1);
            if (choice3)
            {
                // To calculate the bill of you buy the book
                 cart += selectedBooks[bookNumber - 1].price;
                   system("cls");
        cout << " The book has been added to your cart.\n";
            }
        else
        {
             // To calculate the bill of you borrow the book
             cart +=( selectedBooks[bookNumber - 1].price)/10;
        cout << " The book has been added to your cart.\n";
        }
           system("cls");
        cout << " Do you want another book? (1 for Yes, 0 for No): \n";
        buyAnother = getValidChoice(0, 1);
   system("cls");
    }
    while (buyAnother);

    cout << " Do you want to complete your purchase? (1 for Yes, 0 for No): \n";
    complete = getValidChoice(0, 1);

    if (complete)
    {
          system("cls");

        cout << " Enter your name: ";
        cin.ignore();
        getline(cin, name);

        while (!isValidName(name) || name.empty()) {
            cout << "Invalid name. Please enter a valid name using only letters: ";
            getline(cin, name);
        }


         // the data of the user
        cout << " Enter your address: ";
        getline(cin, address);
         while (address.empty()) {
            cout << "Address cannot be empty. Please enter your address: ";
            getline(cin, address);
        }
        cout << " Enter your phone number: ";
        getline(cin, phone);
         while (!isValidnum(phone) || phone.length() != 11) {
            cout << "Invalid phone number. Please enter a valid 11-digit phone number: ";
            getline(cin, phone);
        }

        cout << " Enter your card number: ";
        getline(cin, card);
         while (!isValidnum(card) || card.length() != 16) {
            cout << "Invalid card number. Please enter a valid 16-digit card number: ";
            getline(cin, card);
        }

        cout << " Your total price = $" << cart << endl;
    }
    else {
        cout << "Transaction cancelled." << endl;
        buyBook();

}


}
int main()
{
    system("color 03");// Set console color
        cout << "\t\t\t***********************************************************************" << endl;
        cout << "\t\t\t*                                                                     *" << endl;
        cout << "\t\t\t*                      WELCOME TO THE EBOOK                           *" << endl;
        cout << "\t\t\t*                                                                     *" << endl;
        cout << "\t\t\t***********************************************************************" << endl << endl << endl << endl;
   buyBook() ;
     system("cls");
    cout<< " Your order will arrive within three days." << endl;

    return 0;
}

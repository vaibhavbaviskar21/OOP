#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}

    void input() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        if (price < 0) {
            throw invalid_argument("Price cannot be negative.");
        }
    }

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    Book() : pageCount(0) {}

    void input() {
        Publication::input();
        cout << "Enter page count: ";
        cin >> pageCount;
        if (pageCount < 0) {
            throw invalid_argument("Page count cannot be negative.");
        }
    }

    void display() const {
        Publication::display();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;

public:
    Tape() : playingTime(0.0) {}

    void input() {
        Publication::input();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
        if (playingTime < 0) {
            throw invalid_argument("Playing time cannot be negative.");
        }
    }

    void display() const {
        Publication::display();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book book;
    Tape tape;

    try {
        cout << "Enter details for the Book:\n";
        book.input();
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "\nEnter details for the Tape:\n";
        tape.input();
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\nBook Details:\n";
    book.display();

    cout << "\nTape Details:\n";
    tape.display();

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

// Class Publication
class publication {
private:
    string title;
    float price;

public:
    void add() {
        cout << "\nEnter the Publication information: " << endl;
        cout << "Enter Title of the Publication: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Price of Publication: ";
        cin >> price;
    }

    void display() const {
        cout << "\n--------------------------------------------------";
        cout << "\nTitle of Publication: " << title;
        cout << "\nPublication Price: " << price;
    }
};

// Class book inheriting publication
class book : public publication {
private:
    int page_count;

public:
    void add_book() {
        try {
            add();
            cout << "Enter Page Count of Book: ";
            cin >> page_count;
            if (page_count <= 0) {
                throw page_count;
            }
        } catch (int invalidPageCount) {
            cout << "\nInvalid Page Count (" << invalidPageCount << ")!!!";
            page_count = 0;
        }
    }

    void display_book() const {
        display();
        cout << "\nPage Count: " << page_count;
        cout << "\n--------------------------------------------------\n";
    }
};

// Class tape inheriting publication
class tape : public publication {
private:
    float play_time;

public:
    void add_tape() {
        try {
            add();
            cout << "Enter Play Duration of the Tape (in minutes): ";
            cin >> play_time;
            if (play_time <= 0) {
                throw play_time;
            }
        } catch (float invalidPlayTime) {
            cout << "\nInvalid Play Time (" << invalidPlayTime << " minutes)!!!";
            play_time = 0;
        }
    }

    void display_tape() const {
        display();
        cout << "\nPlay Time: " << play_time << " min";
        cout << "\n--------------------------------------------------\n";
    }
};

int main() {
    book b1[10]; // Array of book objects
    tape t1[10]; // Array of tape objects
    int ch, b_count = 0, t_count = 0;

    do {
        cout << "\n* * * * * PUBLICATION DATABASE SYSTEM * * * * *";
        cout << "\n--------------------MENU-----------------------";
        cout << "\n1. Add Information to Books";
        cout << "\n2. Add Information to Tapes";
        cout << "\n3. Display Books Information";
        cout << "\n4. Display Tapes Information";
        cout << "\n5. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            if (b_count < 10) {
                b1[b_count].add_book();
                b_count++;
            } else {
                cout << "\nBook database is full!";
            }
            break;
        case 2:
            if (t_count < 10) {
                t1[t_count].add_tape();
                t_count++;
            } else {
                cout << "\nTape database is full!";
            }
            break;
        case 3:
            if (b_count > 0) {
                cout << "\n* * * * BOOK PUBLICATION DATABASE SYSTEM * * * *";
                for (int j = 0; j < b_count; j++) {
                    b1[j].display_book();
                }
            } else {
                cout << "\nNo book records available!";
            }
            break;
        case 4:
            if (t_count > 0) {
                cout << "\n* * * * TAPE PUBLICATION DATABASE SYSTEM * * * *";
                for (int j = 0; j < t_count; j++) {
                    t1[j].display_tape();
                }
            } else {
                cout << "\nNo tape records available!";
            }
            break;
        case 5:
            cout << "\nExiting the program.";
            break;
        default:
            cout << "\nInvalid choice! Please try again.";
        }
    } while (ch != 5);

    return 0;
}

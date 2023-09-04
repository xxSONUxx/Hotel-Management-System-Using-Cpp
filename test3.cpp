#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Booking {
    int roomNumber;
    string guestName;
    string checkInDate;
    string checkOutDate;
};
//CREDITS : SONU KUMAR GUPTA, RITESH SAHANI, PRIYANKA MISHRA, MD ASTAFAR ALAM

void addBooking(vector<Booking>& bookings) {
    Booking booking;
    cout << "Enter Room Number: ";
    cin >> booking.roomNumber;
    cout << "Enter Guest Name: ";
    cin.ignore();
    getline(cin, booking.guestName);
    cout << "Enter Check-In Date (dd/mm/yyyy): ";
    cin >> booking.checkInDate;
    cout << "Enter Check-Out Date (dd/mm/yyyy): ";
    cin >> booking.checkOutDate;

    bookings.push_back(booking);
    cout << "Booking added successfully!" << endl;
}

void displayBookings(const vector<Booking>& bookings) {
    if (bookings.empty()) {
        cout << "No bookings found." << endl;
        return;
    }

    cout << "Room Number\tGuest Name\tCheck-In Date\tCheck-Out Date" << endl;
    for (const Booking& booking : bookings) {
        cout << booking.roomNumber << "\t\t" << booking.guestName << "\t\t"
             << booking.checkInDate << "\t\t" << booking.checkOutDate << endl;
    }
}

//CREDITS : SONU KUMAR GUPTA, RITESH SAHANI, PRIYANKA MISHRA, MD ASTAFAR ALAM

void updateBooking(vector<Booking>& bookings) {
    int roomNumber;
    cout << "Enter Room Number to update booking: ";
    cin >> roomNumber;
    bool found = false;

    for (Booking& booking : bookings) {
        if (booking.roomNumber == roomNumber) {
            cout << "Enter New Guest Name: ";
            cin.ignore();
            getline(cin, booking.guestName);
            cout << "Enter New Check-In Date (dd/mm/yyyy): ";
            cin >> booking.checkInDate;
            cout << "Enter New Check-Out Date (dd/mm/yyyy): ";
            cin >> booking.checkOutDate;
            cout << "Booking updated successfully!" << endl;
            found = true;
            break;
        
        }
    }

    if (!found) {
        cout << "Booking not found with Room Number: " << roomNumber << endl;
    }
}

void eraseBooking(vector<Booking>& bookings) {
    int roomNumber;
    cout << "Enter Room Number to erase booking: ";
    cin >> roomNumber;
    bool found = false;

    for (auto it = bookings.begin(); it != bookings.end(); ++it) {
        if (it->roomNumber == roomNumber) {
            bookings.erase(it);
            cout << "Booking erased successfully!" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Booking not found with Room Number: " << roomNumber << endl;
    }
}

//CREDITS : SONU KUMAR GUPTA, RITESH SAHANI, PRIYANKA MISHRA, MD ASTAFAR ALAM

void saveBookingsToFile(const vector<Booking>& bookings, const string& fileName) {
    ofstream outFile(fileName);

    for (const Booking& booking : bookings) {
        outFile << booking.roomNumber << "," << booking.guestName << ","
                << booking.checkInDate << "," << booking.checkOutDate << "\n";
    }

    outFile.close();
    cout << "Bookings saved to " << fileName << endl;
}

void loadBookingsFromFile(vector<Booking>& bookings, const string& fileName) {
    ifstream inFile(fileName);
    if (!inFile) {
        cout << "File not found or unable to open." << endl;
        return;
    }

    bookings.clear();

    string line;
    while (getline(inFile, line)) {
        Booking booking;
        size_t pos = 0;
        string token;
        int field = 0;
        while ((pos = line.find(",")) != string::npos) {
            token = line.substr(0, pos);
            switch (field) {
                case 0:
                    booking.roomNumber = stoi(token);
                    break;
                case 1:
                    booking.guestName = token;
                    break;
                case 2:
                    booking.checkInDate = token;
                    break;
                case 3:
                    booking.checkOutDate = token;
                    break;
            }
            line.erase(0, pos + 1);
            field++;
        }
        bookings.push_back(booking);
    }

    inFile.close();
    cout << "Bookings loaded from " << fileName << endl;
}

//CREDITS : SONU KUMAR GUPTA, RITESH SAHANI, PRIYANKA MISHRA, MD ASTAFAR ALAM

int main() {
    vector<Booking> bookings;
    string fileName = "bookings.txt";

    
    loadBookingsFromFile(bookings, fileName);

    int choice;
    do {
        cout << "*********************WELCOME TO HOTEL MANAGEMENT SYSTEM************************" << endl;
        cout << "****This HOTEL MANAGEMENT SYSTEM is deigned by students of IOEPC BCT Batch 2078 CD Section****" << endl;
        cout << "******CREDITS : SONU KUMAR GUPTA, RITESH SAHANI, PRIYANKA MISHRA, MD ASTAFAR ALAM ******" << endl;
        cout << "\nHotel Management System Menu:" << endl;
        cout << "1. Add Booking" << endl;
        cout << "2. Display Bookings" << endl;
        cout << "3. Update Booking" << endl;
        cout << "4. Erase Booking" << endl;
        cout << "5. Save Bookings to File" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBooking(bookings);
                break;
            case 2:
                displayBookings(bookings);
                break;
            case 3:
                updateBooking(bookings);
                break;
            case 4:
                eraseBooking(bookings);
                break;
            case 5:
                saveBookingsToFile(bookings, fileName);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

//CREDITS : SONU KUMAR GUPTA, RITESH SAHANI, PRIYANKA MISHRA, MD ASTAFAR ALAM

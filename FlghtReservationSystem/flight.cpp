#include <iostream>
#include <iomanip>
#include<conio.h>  // For getch()
#include <fstream>
#include<windows.h>  // For system("cls") and Sleep()
#include <string>
#include <ctime>  // For generating unique booking IDs
#include <sstream> // For converting data to strings
#include <vector> // Include for std::vector
#include <stdexcept> // Include for exceptions
using namespace std;


// Front Screen
void login()
{
	cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\n";
	cout << "\t\t\t\t\t _______________________________________________________________________________________\n";
	cout << "\t\t\t\t\t|                                           		                                |\n";
	cout << "\t\t\t\t\t|                                           		                                |\n";
	cout << "\t\t\t\t\t|                                           		                                |\n";
	cout << "\t\t\t\t\t|                                           		                                |\n";
	cout << "\t\t\t\t\t|                                           		                                |\n";
	cout << "\t\t\t\t\t|                                           		                                |\n";
	cout << "\t\t\t\t\t|                                        WELCOME TO                                     |\n";
	cout << "\t\t\t\t\t|                                                                                       |\n";
	cout << "\t\t\t\t\t|                                   FLIGHT RESERVATION SYSTEM                           |\n";
	cout << "\t\t\t\t\t|                                                                                       |\n";
	cout << "\t\t\t\t\t|                                                                                       |\n";
	cout << "\t\t\t\t\t|                                                                                       |\n";
	cout << "\t\t\t\t\t|                                                                                       |\n";
	cout << "\t\t\t\t\t|                                                          Made  By                     |\n";
	cout << "\t\t\t\t\t|                                                    Muhammad Hamza Butt                |\n";
	cout << "\t\t\t\t\t|_______________________________________________________________________________________|\n";
	cout << "\t\t\t\t\tPress any key to continue...";
	getch();
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading ||||||                                                  | 12% ....";
	Sleep(500);
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading |||||||||||||||||||||||||||||||||                       | 61% ....";
	Sleep(500);
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading ||||||||||||||||||||||||||||||||||||||||||||||||        | 95% ....";
	Sleep(500);
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading ||||||||||||||||||||||||||||||||||||||||||||||||||||||||| 100% ....";
	Sleep(2000);
}


// Constants for rows and columns in each class
const int FIRST_ROWS = 2, FIRST_COLS = 3;
const int BUSINESS_ROWS = 4, BUSINESS_COLS = 6;
const int ECONOMY_ROWS = 10, ECONOMY_COLS = 6; 



// Function declarations
void initializeSeats(char seats[][10], int rows, int cols);
void displaySeats(char seats[][10], int rows, int cols, const string &className, int aislePos1, int aislePos2);
bool bookSeat(char seats[][10], int rows, int cols, const string &className);
bool cancelSeat(char seats[][10], int rows, int cols, const string &className);
void displayFlights();
void adminMenu();
string generateBookingID(); // Declare generateBookingID





int main() {
	
	system("color 71");
	
    // Seat grids for each class
    char firstClassSeats[FIRST_ROWS][10];    
    char businessClassSeats[BUSINESS_ROWS][10];
    char economyClassSeats[ECONOMY_ROWS][10]; 
    
	login();
	system("cls");

    // Initialize seats to available ('O')
    initializeSeats(firstClassSeats, FIRST_ROWS, FIRST_COLS);
    initializeSeats(businessClassSeats, BUSINESS_ROWS, BUSINESS_COLS);
    initializeSeats(economyClassSeats, ECONOMY_ROWS, ECONOMY_COLS);

    int choice;
    while (true) {

        // Prompt user for action
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. View Flight Schedules" << endl;
        cout << "2. Book a Seat" << endl;
        cout << "3. Cancel a Seat" << endl;
        cout << "4. Admin Menu" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
        	case 1:
            	system("cls");
                displayFlights();
                break;
            case 2: {
                // Booking a seat
                
                 // Display seat availability
                displaySeats(firstClassSeats, FIRST_ROWS, FIRST_COLS, "First Class", 1, 2);
                displaySeats(businessClassSeats, BUSINESS_ROWS, BUSINESS_COLS, "Business Class", 2, 4);
                displaySeats(economyClassSeats, ECONOMY_ROWS, ECONOMY_COLS, "Economy Class", 3, -1);
                int classChoice;
                cout << "\nWhich class do you want to book a seat in?" << endl;
                cout << "1. First Class" << endl;
                cout << "2. Business Class" << endl;
                cout << "3. Economy Class" << endl;
                cout << "\nEnter your choice (1/2/3): ";
                cin >> classChoice;

                if (classChoice == 1) {
                    bookSeat(firstClassSeats, FIRST_ROWS, FIRST_COLS, "First Class");
                } else if (classChoice == 2) {
                    bookSeat(businessClassSeats, BUSINESS_ROWS, BUSINESS_COLS, "Business Class");
                } else if (classChoice == 3) {
                    bookSeat(economyClassSeats, ECONOMY_ROWS, ECONOMY_COLS, "Economy Class");
                } else {
                    cout << "Invalid choice! Please try again." << endl;
                }
                break;
            }
            case 3: {
                // Canceling a seat
                
                // Display seat availability
                displaySeats(firstClassSeats, FIRST_ROWS, FIRST_COLS, "First Class", 1, 2);
                displaySeats(businessClassSeats, BUSINESS_ROWS, BUSINESS_COLS, "Business Class", 2, 4);
                displaySeats(economyClassSeats, ECONOMY_ROWS, ECONOMY_COLS, "Economy Class", 3, -1);
                int classChoice;
                cout << "\nWhich class do you want to cancel a seat in?" << endl;
                cout << "1. First Class" << endl;
                cout << "2. Business Class" << endl;
                cout << "3. Economy Class" << endl;
                cout << "\nEnter your choice (1/2/3): ";
                cin >> classChoice;

                if (classChoice == 1) {
                    cancelSeat(firstClassSeats, FIRST_ROWS, FIRST_COLS, "First Class");
                } else if (classChoice == 2) {
                    cancelSeat(businessClassSeats, BUSINESS_ROWS, BUSINESS_COLS, "Business Class");
                } else if (classChoice == 3) {
                    cancelSeat(economyClassSeats, ECONOMY_ROWS, ECONOMY_COLS, "Economy Class");
                } else {
                    cout << "Invalid choice! Please try again." << endl;
                }
                break;
            }
            case 4:
            	system("cls");
                adminMenu();
                break;
            
			
			case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}

// Initialize seats to 'O' (available)
void initializeSeats(char seats[][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            seats[i][j] = 'O';
        }
    }
}

// Seats display
void displaySeats(char seats[][10], int rows, int cols, const string &className, int aislePos1, int aislePos2) {
    cout << "\n\n\n\n\t\t\t\t\t\t\t\t";
    cout << className << "\n"<<  endl;
    for (int i = 0; i < rows; ++i) {
        cout << "\t\t\t\t\t\t\t";
        cout << "Row " << setw(2) << i + 1 << ":   ";
        for (int j = 0; j < cols; ++j) {
            if (j == aislePos1 || j == aislePos2) cout << "| "; // Add aisle
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to generate a unique booking ID
string generateBookingID() {
    srand(time(0));
    int randomID = rand() % 100000;  // Generates a 5-digit random number
    stringstream ss;
    ss << "BK" << randomID;
    return ss.str();
}


// Booking a Seat
bool bookSeat(char seats[][10], int rows, int cols, const string& className) {
    int row, col;
    string name, cnic, contact;
    cout << "\nEnter the row (1-" << rows << ") and column (1-" << cols << ") to book: ";
    cin >> row >> col;

    if (row > 0 && row <= rows && col > 0 && col <= cols) {
        if (seats[row - 1][col - 1] == 'O') {
            cin.ignore();
            cout << "Enter your name: ";
            getline(cin, name);
            cout << "Enter your CNIC number: ";
            getline(cin, cnic);
            cout << "Enter your contact number: ";
            getline(cin, contact);

            string bookingID = generateBookingID();

            ofstream bookingFile("bookings.txt", ios::app); // Fixed: Use "bookings.txt"
            if (!bookingFile) {
                cerr << "Error: Unable to open booking file." << endl;
                return false;
            }

            bookingFile << bookingID << "," << name << "," << cnic << "," << contact
                << "," << className << "," << row << "," << col << endl;

            bookingFile.close();

            seats[row - 1][col - 1] = 'X';
            system("cls");
            displaySeats(seats, rows, cols, className, (className == "First Class") ? 1 : (className == "Business Class") ? 2 : 3, (className == "First Class") ? 2 : (className == "Business Class") ? 4 : -1);
            cout << "\n\n\n\t\t\t\t\t\tSeat booked successfully in " << className << "!" << endl;
            cout << "\t\t\t\t\t\tYour Booking ID: " << bookingID << endl;
            cout << "\t\t\t\t\t\tThank you for booking with us!\n\n\n" << endl;
            cout << "\n\t\t\t\t\t\tPress any key to continue...";
            getch();
            system("cls");
            return true;
        } else {
            cout << "Seat already booked! Please choose another seat." << endl;
            return false;
        }
    } else {
        cout << "Invalid seat selection. Please try again." << endl;
        return false;
    }
    system("cls");
}


// Canceling a Seat
bool cancelSeat(char seats[][10], int rows, int cols, const string &className) {
    string bookingID, name, cnic;
    cout << "Enter your Booking ID: ";
    cin >> bookingID;
    cin.ignore();
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your CNIC number: ";
    getline(cin, cnic);

    ifstream bookingFile("bookings.txt"); // Fixed: Use "bookings.txt"
    ofstream tempFile("temp.txt");
    bool bookingFound = false;

    if (!bookingFile || !tempFile) {
        cerr << "Error accessing booking file!" << endl;
        return false;
    }

    string line;
    while (getline(bookingFile, line)) {
        stringstream ss(line);
        string id, bookedName, bookedCNIC, contact, bookedClass;
        int bookedRow, bookedCol;

        getline(ss, id, ',');
        getline(ss, bookedName, ',');
        getline(ss, bookedCNIC, ',');
        getline(ss, contact, ',');
        getline(ss, bookedClass, ',');
        ss >> bookedRow >> bookedCol;

        if (id == bookingID && bookedName == name && bookedCNIC == cnic) {
            bookingFound = true;
            if (className == bookedClass) {
                seats[bookedRow - 1][bookedCol - 1] = 'O'; // Mark seat as available
                cout << "Booking successfully canceled!" << endl;
            } else {
                tempFile << line << endl; // Keep the line if the class doesn't match
            }
        } else {
            tempFile << line << endl; // Copy non-matching lines
        }
    }

    bookingFile.close();
    tempFile.close();

    if (bookingFound) {
        remove("bookings.txt");
        rename("temp.txt", "bookings.txt");
    } else {
        remove("temp.txt");
        cout << "Booking not found or details incorrect!" << endl;
    }

    return bookingFound;
}

// Display flight schedules
void displayFlights() {
    ifstream flightFile("flights.txt");
    if (!flightFile) {
        cerr << "Error: Unable to open flights file." << endl;
        return;
    }

    cout << "\nAvailable Flights:" << endl;
    string line;
    while (getline(flightFile, line)) {
        cout << line << endl;
    }

    flightFile.close();
}


// Admin menu to view bookings
void adminMenu() {
    const string ADMIN_USERNAME = "admin123";
    const string ADMIN_PASSWORD = "password456";

    string username, password;
    cout << "\nEnter admin username: ";
    cin >> username;
    cout << "Enter admin password: ";
    cin >> password;

    if (username != ADMIN_USERNAME || password != ADMIN_PASSWORD) {
        cout << "\nInvalid credentials! Returning to main menu." << endl;
        return;
    }

    int adminChoice;
    while (true) {
        cout << "\nAdmin Menu:" << endl;
        cout << "1. Add Flight" << endl;
        cout << "2. Remove Flight" << endl;
        cout << "3. View Bookings" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "\nEnter your choice (1-4): ";
        cin >> adminChoice;

        switch (adminChoice) {
            case 1: {
            	    // Add a new flight
                ofstream flightFile("flights.txt", ios::app);
                if (!flightFile) {
                    cerr << "Error: Unable to open flights file for writing." << endl;
                    break;
                }

                string airline, departure, arrival, dateTime;
                cout << "\nEnter Airline: ";
                getline(cin, airline);
                cout << "Enter Departure Airport: ";
                getline(cin, departure);
                cout << "Enter Arrival Airport: ";
                getline(cin, arrival);
                cout << "Enter Date and Time (DD-MM-YYYY HH:MM): ";
                getline(cin, dateTime);

                flightFile << airline << ", " << departure << " -> " << arrival << ", " << dateTime << endl;
                cout << "Flight added successfully!" << endl;

                flightFile.close();
                break;
            }
            case 2: {
                // Remove a flight
                ifstream flightFile("flights.txt");
                if (!flightFile) {
                    cerr << "Error: Unable to open flights file for reading." << endl;
                    break;
                }

                ofstream tempFile("temp.txt");
                if (!tempFile) {
                    cerr << "Error: Unable to create temporary file." << endl;
                    flightFile.close();
                    break;
                }

                string line, flightToRemove;
                cout << "\nEnter details of the flight to remove (exact match required): ";
                cin.ignore();
                getline(cin, flightToRemove);

                bool found = false;
                while (getline(flightFile, line)) {
                    if (line == flightToRemove) {
                        found = true;
                    } else {
                        tempFile << line << endl;
                    }
                }

                flightFile.close();
                tempFile.close();

                if (found) {
                    remove("flights.txt");
                    rename("temp.txt", "flights.txt");
                    cout << "Flight removed successfully!" << endl;
                } else {
                    remove("temp.txt");
                    cout << "Flight not found!" << endl;
                }

                break;
            }
            case 3: {
                ifstream bookingFile("bookings.txt");
                if (!bookingFile) {
                    cerr << "Error: Unable to open booking file." << endl;
                    break;
                }

                cout << "\nBookings List:" << endl;
                string line;
                while (getline(bookingFile, line)) {
                    cout << line << endl;
                }

                bookingFile.close();
                break;
            }
            case 4:
                return;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}



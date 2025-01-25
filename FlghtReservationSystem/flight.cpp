#include <iostream>
#include <iomanip>
using namespace std;

// Constants for rows and columns in each class
const int FIRST_ROWS = 2, FIRST_COLS = 4;
const int BUSINESS_ROWS = 4, BUSINESS_COLS = 6;
const int ECONOMY_ROWS = 10, ECONOMY_COLS = 6; 

// Function declarations
void initializeSeats(char seats[][10], int rows, int cols);
void displaySeats(char seats[][10], int rows, int cols, const string &className, int aislePos1, int aislePos2);
bool bookSeat(char seats[][10], int rows, int cols, int aislePos, const string &className);
bool cancelSeat(char seats[][10], int rows, int cols, int aislePos, const string &className);

int main() {
    // Seat grids for each class
    char firstClassSeats[FIRST_ROWS][10];    
    char businessClassSeats[BUSINESS_ROWS][10];
    char economyClassSeats[ECONOMY_ROWS][10]; 

    // Initialize seats to available ('O')
    initializeSeats(firstClassSeats, FIRST_ROWS, FIRST_COLS);
    initializeSeats(businessClassSeats, BUSINESS_ROWS, BUSINESS_COLS);
    initializeSeats(economyClassSeats, ECONOMY_ROWS, ECONOMY_COLS);

    int choice;
    while (true) {
        // Display seat availability
        displaySeats(firstClassSeats, FIRST_ROWS, FIRST_COLS, "First Class", 2, -1);
        displaySeats(businessClassSeats, BUSINESS_ROWS, BUSINESS_COLS, "Business Class", 2, 4);
        displaySeats(economyClassSeats, ECONOMY_ROWS, ECONOMY_COLS, "Economy Class", 3, -1);

        // Prompt user for action
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Book a seat" << endl;
        cout << "2. Cancel a seat" << endl;
        cout << "3. Exit" << endl;
        cout << "\n Enter your choice (1/2/3): ";
        cin >> choice;

        if (choice == 1) {
            // Booking a seat
            int classChoice;
            cout << "\nWhich class do you want to book a seat in?" << endl;
            cout << "1. First Class" << endl;
            cout << "2. Business Class" << endl;
            cout << "3. Economy Class" << endl;
            cout << "\nEnter your choice (1/2/3): ";
            cin >> classChoice;

            if (classChoice == 1) {
                bookSeat(firstClassSeats, FIRST_ROWS, FIRST_COLS, 2, "First Class");
            } 
			else if (classChoice == 2) {
                bookSeat(businessClassSeats, BUSINESS_ROWS, BUSINESS_COLS, 3, "Business Class");
            } 
			else if (classChoice == 3) {
                bookSeat(economyClassSeats, ECONOMY_ROWS, ECONOMY_COLS, 3, "Economy Class");
            } 
			else {
                cout << "Invalid choice! Please try again." << endl;
            }
        } 
		else if (choice == 2) {
            // Canceling a seat
            int classChoice;
            cout << "\nWhich class do you want to cancel a seat in?" << endl;
            cout << "1. First Class" << endl;
            cout << "2. Business Class" << endl;
            cout << "3. Economy Class" << endl;
            cout << "\nEnter your choice (1/2/3): ";
            cin >> classChoice;

            if (classChoice == 1) {
                cancelSeat(firstClassSeats, FIRST_ROWS, FIRST_COLS, 2, "First Class");
            } 
			else if (classChoice == 2) {
                cancelSeat(businessClassSeats, BUSINESS_ROWS, BUSINESS_COLS, 3, "Business Class");
            } 
			else if (classChoice == 3) {
                cancelSeat(economyClassSeats, ECONOMY_ROWS, ECONOMY_COLS, 3, "Economy Class");
            } 
			else {
                cout << "Invalid choice! Please try again." << endl;
            }
        } 
		else if (choice == 3) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        } 
		else {
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

// Booking of seat
bool bookSeat(char seats[][10], int rows, int cols, int aislePos, const string &className) {
    int row, col;
    cout << "\n Enter the row (1-" << rows << ") and column (1-" << cols << ") to book: ";
    cin >> row >> col;

    if (row > 0 && row <= rows && col > 0 && col <= cols) {
        if (col == aislePos + 1) {
            cout << "Invalid selection: This is an aisle, not a seat!" << endl;
            return false;
        }
        if (seats[row - 1][col - 1] == 'O') {
            seats[row - 1][col - 1] = 'X';  // Mark seat as booked
            cout << "Seat booked successfully in " << className << "!" << endl;
            return true;
        } 
		else {
            cout << "Seat already booked! Please choose another seat." << endl;
            return false;
        }
    } 
	else {
        cout << "Invalid seat selection. Please try again." << endl;
        return false;
    }
}

// Cancellation of seat 
bool cancelSeat(char seats[][10], int rows, int cols, int aislePos, const string &className) {
    int row, col;
    cout << "\n Enter the row (1-" << rows << ") and column (1-" << cols << ") to cancel: ";
    cin >> row >> col;

    if (row > 0 && row <= rows && col > 0 && col <= cols) {
        if (col == aislePos + 1) {
            cout << "Invalid selection: This is an aisle, not a seat!" << endl;
            return false;
        }
        if (seats[row - 1][col - 1] == 'X') {
            seats[row - 1][col - 1] = 'O';  // Mark seat as available
            cout << "Seat cancellation successful in " << className << "!" << endl;
            return true;
        } 
		else {
            cout << "Seat is already available! No booking to cancel." << endl;
            return false;
        }
    } 
	else {
        cout << "Invalid seat selection. Please try again." << endl;
        return false;
    }
}


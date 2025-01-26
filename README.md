# Flight Reservation System

This is a C++ console application that simulates a flight reservation system. Users can view available flights, book seats, cancel bookings, and administrators can manage flight information.

## Features

* **Flight Schedule Viewing:** Display flight information from a `flights.txt` file.
* **Seat Booking:** Book seats in First Class, Business Class, or Economy Class. Generates unique booking IDs and stores booking details in `bookings.txt`.
* **Booking Cancellation:** Allows users to cancel existing bookings using their booking ID, name, and CNIC.
* **Admin Menu:** Provides an interface for authorized users to:
    * Add new flights to `flights.txt`.
    * Remove existing flights from `flights.txt`.
    * View all bookings from `bookings.txt`.
* **Input Validation:** Robust input validation to handle incorrect user input and prevent program crashes.
* **Error Handling:** Uses exceptions (`try-catch`) for proper error handling, providing informative error messages to the user.
* **Screen Management:** Uses `system("cls")` to clear the console screen for a cleaner user interface.
* **Data Persistence:** Stores flight information in `flights.txt` and booking information in `bookings.txt`.

## Files

*   `flight.cpp`: The main C++ source code file.
*   `flights.txt`: Contains the flight schedule information (airline, departure, arrival, date/time). Each flight is on a separate line, with comma-separated values. Example: `PIA, Karachi -> Lahore, 25-12-2024 10:00`
*   `bookings.txt`: Stores booking details (booking ID, name, CNIC, contact, class, row, column). Each booking is on a separate line, with comma-separated values. Example: `BK12345,John Doe,1234567890123,03001234567,First Class,1,2`

## Compilation (Dev-C++)

1.  Create a new Console Application project in Dev-C++.
2.  Add `flight.cpp`, `flights.txt`, and `bookings.txt` to your project.
3.  Compile the project (F9).

## Running the Program

Run the executable file generated after compilation.

## Usage

The program starts with a welcome screen. The main menu provides options for:

*   **Viewing Flight Schedules**
*   **Booking a Seat**
*   **Canceling a Seat**
*   **Admin Menu** (requires username and password)
*   **Exiting**

Follow the on-screen prompts for each option.

## Key Implementation Detail (2D Arrays):

When passing 2D arrays to functions in C++, the second dimension (number of columns) must be specified in the function declaration and definition. This is why the function signatures use `char seats[][10]`.

## Error Handling

Exceptions (`try-catch`) are used for error handling.


## Author
Muhammad Hamza Butt

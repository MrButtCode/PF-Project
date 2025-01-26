# PF-Project

# Flight Reservation System

This is a console-based Flight Reservation System implemented in C++.

## Features

*   View Flight Schedules
*   Book Seats (First Class, Business Class, EconomyClass)
*   Cancel Bookings
*   Admin Menu (Add/Remove Flights, View Bookings)
*   Input Validation
*   Error Handling (Exceptions)
*   Data Persistence (flights.txt, bookings.txt)

## Files

*   `flight.cpp`: The main source code.
*   `flights.txt`: Flight information (Airline, Departure -> Arrival, Date Time).
*   `bookings.txt`: Booking details (BookingID, Name, CNIC, Contact, Class, Seating(Row, Column)).

## Compilation (Dev-C++)

1.  Create a new Console Application project.
2.  Add `flight.cpp`, `flights.txt`, and `bookings.txt` to the project.
3.  Compile (F11).

## Execution

Run the executable.

## Usage

Follow the on-screen menu prompts.

## Key Implementation Detail (2D Arrays):

When passing 2D arrays to functions in C++, the second dimension (number of columns) must be specified in the function declaration and definition. This is why the function signatures use `char seats[][10]`.

## Error Handling

Exceptions (`try-catch`) are used for error handling.

## Author

Muhammad Hamza Butt

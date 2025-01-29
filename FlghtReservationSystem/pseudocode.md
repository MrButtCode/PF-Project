Main Program:

     START
    Display welcome screen

    WHILE user has not exited
      Display Main Menu
		  GET user choice
      
			IF choice == 1
         Call displayFlights()
      ELSE IF choice == 2
         Call bookFlight()
      ELSE IF choice == 3
         Call cancelFlight()
      ELSE IF choice == 4
         Call adminMenu()
      ELSE IF choice == 5
         EXIT program
      ELSE
         Display "Invalid choice!"
      ENDIF
    ENDWHILE
    STOP


displayFlights():

    OPEN "flights.txt" in read mode
    IF file cannot be opened
       THROW error "Unable to open flights file"
    ENDIF

    FOR each line in the file
       Display flight details
    ENDFOR
    CLOSE file

bookFlight():

    Display available flights by calling displayFlights()
    Prompt user for flight index and validate input

    IF flight index is invalid
       Display error message and return
    ENDIF

    Prompt user for seat class and validate input
    Prompt user for name, CNIC, and contact number
    Generate unique booking ID

    OPEN "bookings.txt" in append mode
    IF file cannot be opened
        THROW error "Unable to open bookings file"
    ENDIF

    WRITE booking details (ID, name, CNIC, contact, class, flight index) to file
    CLOSE file
    Display confirmation message

cancelFlight():

    Prompt user for Booking ID, name, and CNIC
    OPEN "bookings.txt" in read mode
    OPEN "temp.txt" in write mode

    IF file cannot be opened
        THROW error "Unable to open bookings file"
    ENDIF

    FOR each line in the file
        IF line matches user input
            Mark booking as found
        ELSE
            WRITE line to "temp.txt"
        ENDIF
    ENDFOR

    CLOSE all files
    IF booking is found
        RENAME "temp.txt" to "bookings.txt"
        Display "Booking canceled successfully"
    ELSE
        DELETE "temp.txt"
        Display "Booking not found"
    ENDIF

adminMenu():

    Prompt for admin username and password
        (username: admin123, password: password456)
       
    IF credentials are invalid
        Display error and return
    ENDIF

    WHILE in admin menu
        Display admin options (Add Flight, Remove Flight, View Bookings)
        GET admin choice

        IF choice == 1
            Prompt for flight details
            APPEND new flight to "flights.txt"
        ELSE IF choice == 2
            Display flights
            Prompt for flight to remove
            REMOVE selected flight from "flights.txt"
        ELSE IF choice == 3
            Display all bookings by reading "bookings.txt"
        ELSE IF choice == 4
            RETURN to main menu
        ELSE
            Display "Invalid choice!"
        ENDIF
    ENDWHILE



 

//
// Created by honda on 4/20/2022.
//

#include "TheaterTest.h"

void TheaterTest::attemptToSeatZero() {

    if(theater.findSeats("R001 0") == -1)
        cout << "Test 1 Passed" << endl;
    else
        cout << "Test 1 Failed" << endl;

}

void TheaterTest::confirmFirstCustomerSeating() {
    theater.findSeats("R999 5");
    vector<string> seats = {"F14", "F15", "F16", "F17", "F18"};

    if(theater.getReservations().at("R999") == seats)
        cout << "Test 2 Passed" << endl;
    else
        cout << "Test 2 Failed" << endl;

}

void TheaterTest::confirmInsufficientSeating() {
    int retValue = theater.findSeats("R222 30");
    if(retValue == -2)
        cout << "Test 3 Passed" << endl;
    else
        cout << "Test 3 Failed" << endl;

}

TheaterTest::TheaterTest(MovieTheater theaterInput) {
    theater = theaterInput;
    attemptToSeatZero();
    confirmFirstCustomerSeating();
    confirmInsufficientSeating();
}

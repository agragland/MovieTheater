//
// Created by honda on 4/20/2022.
//

#ifndef MOVIETHEATER_THEATERTEST_H
#define MOVIETHEATER_THEATERTEST_H

#include "MovieTheater.h"


class TheaterTest {

private:
    MovieTheater theater;

    void attemptToSeatZero();
    void confirmFirstCustomerSeating();
    void confirmConsecutiveSeats();
    void confirmInsufficientSeating();

public:
    TheaterTest(MovieTheater theaterInput);
};


#endif //MOVIETHEATER_THEATERTEST_H

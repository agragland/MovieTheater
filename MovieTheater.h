//
// Created by Andrew Ragland on 4/20/2022.
//

#ifndef MOVIETHEATER_MOVIETHEATER_H
#define MOVIETHEATER_MOVIETHEATER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


class MovieTheater {
private:
    int rows = 10;
    int columns = 20;
    int numSeats = rows * columns;

    int buffer = 3;

    vector<vector<string>> seats = vector<vector<string>>(rows, vector<string>(columns, "s"));
    vector<int> remainingSeats = vector<int> (10, 20);
    unordered_map<string, vector<string>> reservations;

    static vector<string> splitString(string, char);

    string rowColToString(int, int) const;

public:
    MovieTheater();

    int findSeats(string reservation);

    bool findValidSeats(vector<string>, string, int, int);

    int findLastIndex(vector<string>);

    unordered_map<string, vector<string>> getReservations() {
        return reservations;
    }
};


#endif //MOVIETHEATER_MOVIETHEATER_H

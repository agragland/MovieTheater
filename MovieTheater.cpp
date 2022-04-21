//
// Created by honda on 4/20/2022.
//

#include "MovieTheater.h"

#include <utility>

string MovieTheater::rowColToString(int rowInd, int colInd) const  {
    if(rowInd < rows && colInd < columns)
    {
        string rowString("ABCDEFGHIJ");
        char output = rowString[rowInd];
        string ret;
        ret += output;
        ret += to_string(colInd+1);
        return ret;
    }

    return "null";
}



//UTILITY FUNCTION TO SPLIT INPUT STRINGS
vector<string> MovieTheater::splitString(string str, char separator) {

    vector<string> words; //create a data structure to store each word
    string word; //create a variable that will expand to store each word
    int pos = 0;

    while((pos = str.find(separator)) != string::npos)
    {
        word = str.substr(0, pos);
        words.push_back(word);
        str.erase(0, pos + 1);
    }
    words.push_back(str);
    return words;
}


//START PUBLIC FUNCTIONS
int MovieTheater::findSeats(string reservation) {
    vector<string> input = splitString(move(reservation), ' ');
    string reservationNo = input[0];
    int seatCount = stoi(input[1]);

    if(seatCount < 1)
        return -1;

    //Book Seats Starting From Row J -- row index: 9
    bool foundSeats = false;
    for(int i = rows-1; i >= 0; i--)
    {
        foundSeats = findValidSeats(seats[i], reservationNo, seatCount, i);
        if(foundSeats)
        {
            foundSeats = false;
            break;
        }
    }
    if(!foundSeats)
        return -2;


    return 0;
}

bool MovieTheater::findValidSeats(vector<string> row, string reservationNo, int seatCount, int rowIndex) {

    //CASE EMPTY ROW

    if(remainingSeats[rowIndex] <= seatCount)
    {
        return false;
    }
    else
    {
        auto rev_it = reservations.find(reservationNo);
        if(rev_it == reservations.end())
        {
            vector<string> revSeats;
            int offset = findLastIndex(move(row));
            if((offset + buffer + seatCount) >= columns)
            {
                return false;
            }
            else
            {
                for(int i = 0; i < seatCount; i++)
                {
                    if(offset == 0)
                    {
                        seats[rowIndex][i+offset] = "o";
                        revSeats.push_back(rowColToString(rowIndex,i+offset));
                    }
                    else
                    {
                        seats[rowIndex][i+offset+buffer] = "o";
                        revSeats.push_back(rowColToString(rowIndex,i+offset+buffer));
                    }
                    remainingSeats[rowIndex]--;
                }
                reservations.emplace(make_pair(reservationNo,revSeats));
                return true;
            }
        }
    }


    return false;
}

int MovieTheater::findLastIndex(vector<string> row) {

    for(int i = columns-1; i >= 0; i--)
    {
        if(row[i] == "o")
        {
            return i+1;
        }
    }
    return 0;
}


MovieTheater::MovieTheater() = default;



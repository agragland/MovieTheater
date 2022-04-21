#include "MovieTheater.h"
#include "TheaterTest.h"
#include <fstream>
#include <sstream>
#include <filesystem>

void writeOutput(unordered_map<string, vector<string>> reservations)
{
    fstream outputFile;
    outputFile.open("output.txt", ios::out);
    if(outputFile.is_open())
    {
        for(auto reservation : reservations)
        {
            outputFile << reservation.first << ": ";
            for(int j = 0; j < reservation.second.size() - 1; j++)
            {
                outputFile << reservation.second.at(j) << ",";
            }
            outputFile << reservation.second.at(reservation.second.size()-1) << "\n";
        }

        outputFile.close();
    }

    cout << "File stored in output.txt" << endl;

}


int main(int argc, char** argv) {
    if(argc > 1)
    {
        fstream inputFile;
        inputFile.open(argv[1], ios::in);
        MovieTheater theater;
        if(inputFile.is_open())
        {
            string line;
            while(getline(inputFile, line))
            {
                int ret = theater.findSeats(line);
            }
            inputFile.close();
        }

        unordered_map<string, vector<string>> reservations = theater.getReservations();
        writeOutput(reservations);
        TheaterTest test(theater);

    }



    return 0;
}

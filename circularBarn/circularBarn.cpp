#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream input("cbarn.in");   // Input file
    ofstream output("cbarn.out"); // Output file

    int roomAmount = 0, cowAmount = 0;
    input >> roomAmount; // Read the number of rooms

    vector<int> cowInRoom(roomAmount, 0);
    for (int i = 0; i < roomAmount; i++)
    {
        input >> cowInRoom[i]; // Read the number of cows in each room
        cowAmount += cowInRoom[i];
    }

    int minNum = 10000000; // Initialize to a large value

    for (int j = 0; j < roomAmount; j++)
    {
        int tempCowAmount = cowAmount, total = 0;

        for (int i = 0; i < roomAmount; i++)
        {
            tempCowAmount -= cowInRoom[i];
            total += tempCowAmount;
        }

        int temp = cowInRoom[0];
        cowInRoom.erase(cowInRoom.begin());
        cowInRoom.push_back(temp);

        minNum = min(total, minNum);
    }

    output << minNum << endl; // Write the result to the output file

    input.close();  // Close the input file
    output.close(); // Close the output file

    return 0;
}

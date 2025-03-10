/*
ID: gokuche3
TASK: gift1
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Redirect input and output
    ifstream infile("gift1.in");
    ofstream outfile("gift1.out");

    int NP = 1;
    infile >> NP;

    map<int, std::string> people;
    map<int, int> cash;
    for (int i = 1; i <= NP; i++)
    {
        infile >> people[i];
        cash[i] = 0;
    }

    string giver;
    string currentReciver;
    int giftAmount = 0;
    int reciverNum = 0;
    int reciverGifted = 0;

    for (int i = 1; i <= NP; i++) // np rounds of giver
    {
        infile >> giver >> giftAmount >> reciverNum;
        if (reciverNum != 0)
        {
            reciverGifted = giftAmount / reciverNum;
            giftAmount = reciverGifted * reciverNum;
            for (int j = 1; j <= reciverNum; j++) // inputting the reciver
            {
                infile >> currentReciver;
                for (int k = 1; k <= NP; k++)
                {
                    if (currentReciver == people[k])
                    {
                        cash[k] += reciverGifted;
                    }
                }
            }
        }

        for (int k = 1; k <= NP; k++)
        {
            if (giver == people[k])
            {
                cash[k] -= giftAmount;
            }
        }
    }

    for (int i = 1; i <= NP; i++)
    {
        outfile << people[i] << " " << cash[i] << endl;
    }

    // Close the file streams
    infile.close();
    outfile.close();
}

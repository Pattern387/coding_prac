/*
ID: gokuche3
TASK: ride
LANG: C++
*/

#include <fstream>
#include <string>

int letterToNumber(char c)
{
    return c - 'A' + 1;
}

int calculateMod47(const std::string &name)
{
    long long product = 1;
    for (char c : name)
    {
        product *= letterToNumber(c);
    }
    return product % 47;
}

int main()
{
    std::ifstream fin("ride.in");
    std::ofstream fout("ride.out");

    std::string cometName, groupName;

    fin >> cometName;
    fin >> groupName;

    int cometMod = calculateMod47(cometName);
    int groupMod = calculateMod47(groupName);

    if (cometMod == groupMod)
    {
        fout << "GO" << std::endl;
    }
    else
    {
        fout << "STAY" << std::endl;
    }

    return 0;
}

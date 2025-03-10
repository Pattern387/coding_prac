#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int CowNum = 0;
    scanf("%d", &CowNum);
    vector<int> _shuffle(CowNum, 0);
    vector<int> _id(CowNum, 0);

    for (int i = 0; i <= CowNum - 1; i++)
    {
        scanf("%d", &_shuffle[i]);
    }

    for (int i = 0; i <= CowNum - 1; i++)
    {
        scanf("%d", &_id[i]);
    }

    for (int i = 1; i <= CowNum; i++)
    {
        for (int j = 0; j <= CowNum - 1; j++)
        {
            if (i == _shuffle[j])
            {
                printf("%d\n", _id[j]);
            }
        }
    }

    return 0;
}
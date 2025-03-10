#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int cowNum = 0;
    scanf("%d", &cowNum);
    vector<int> startT(cowNum, 0);
    vector<int> endT(cowNum, 0);
    vector<int> bucketsNeeded(cowNum, 0);
    vector<int> timeStamp(1000, 0);

    int currentBucket = 0;
    int maxBucket = 0;

    for (int i = 0; i <= cowNum - 1; i++)
    {
        scanf("%d %d %d", &startT[i], &endT[i], &bucketsNeeded[i]);
        timeStamp[startT[i]] += bucketsNeeded[i];
        timeStamp[endT[i]] -= bucketsNeeded[i];
    }
    for (int i = 0; i <= 1000 - 1; i++)
    {
        currentBucket += timeStamp[i];
        maxBucket = max(maxBucket, currentBucket);
    }
    cout << maxBucket;

        return 0;
}
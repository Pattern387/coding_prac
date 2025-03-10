#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 200005;
int testCases, arraySize;
int inputArray[MAX_SIZE], originalArray[MAX_SIZE], stackArray[MAX_SIZE], lastOccurrence[MAX_SIZE], stackTop;
int segmentTree[MAX_SIZE * 4], maxSegmentTree[MAX_SIZE * 4];
vector<int> valueIndices[MAX_SIZE];
int tempIndex, previous[MAX_SIZE], queueArray[MAX_SIZE];

#define midIndex ((left + right) >> 1)
#define leftChild (currentNode << 1)
#define rightChild (currentNode << 1 | 1)

void buildSegmentTree(int currentNode, int left, int right)
{
    segmentTree[currentNode] = 0;
    if (left == right)
    {
        maxSegmentTree[currentNode] = inputArray[left];
        return;
    }
    buildSegmentTree(leftChild, left, midIndex);
    buildSegmentTree(rightChild, midIndex + 1, right);
    maxSegmentTree[currentNode] = max(maxSegmentTree[leftChild], maxSegmentTree[rightChild]);
}

int querySegmentTree(int currentNode, int left, int right, int queryLeft, int queryRight)
{
    if (queryLeft <= left && queryRight >= right)
        return segmentTree[currentNode];
    if (queryRight <= midIndex)
        return querySegmentTree(leftChild, left, midIndex, queryLeft, queryRight);
    if (queryLeft > midIndex)
        return querySegmentTree(rightChild, midIndex + 1, right, queryLeft, queryRight);
    return querySegmentTree(leftChild, left, midIndex, queryLeft, queryRight) + querySegmentTree(rightChild, midIndex + 1, right, queryLeft, queryRight);
}

int queryMaxSegmentTree(int currentNode, int left, int right, int queryLeft, int queryRight)
{
    if (queryLeft > right)
        return -10000000000;
    if (queryLeft <= left && queryRight >= right)
        return maxSegmentTree[currentNode];
    if (queryRight <= midIndex)
        return queryMaxSegmentTree(leftChild, left, midIndex, queryLeft, queryRight);
    if (queryLeft > midIndex)
        return queryMaxSegmentTree(rightChild, midIndex + 1, right, queryLeft, queryRight);
    return max(queryMaxSegmentTree(leftChild, left, midIndex, queryLeft, queryRight), queryMaxSegmentTree(rightChild, midIndex + 1, right, queryLeft, queryRight));
}

void deleteElement(int currentNode, int left, int right, int key)
{
    segmentTree[currentNode]--;
    if (left == right)
        return;
    if (key <= midIndex)
        deleteElement(leftChild, left, midIndex, key);
    else
        deleteElement(rightChild, midIndex + 1, right, key);
}

void addElement(int currentNode, int left, int right, int key)
{
    segmentTree[currentNode]++;
    if (left == right)
        return;
    if (key <= midIndex)
        addElement(leftChild, left, midIndex, key);
    else
        addElement(rightChild, midIndex + 1, right, key);
}

int main()
{
    cin >> testCases;
    while (testCases--)
    {
        cin >> arraySize;
        memset(lastOccurrence, 0, sizeof(lastOccurrence));
        for (int i = 1; i <= arraySize; i++)
        {
            cin >> originalArray[i];
            inputArray[i] = originalArray[i];
            valueIndices[inputArray[i]].push_back(i);
            previous[i] = 0;
        }
        buildSegmentTree(1, 1, arraySize);
        tempIndex = stackTop = 0;
        for (int i = 1; i <= arraySize; i++)
        {
            while (tempIndex && inputArray[queueArray[tempIndex]] < inputArray[i])
                tempIndex--;
            previous[i] = queueArray[tempIndex];
            queueArray[++tempIndex] = i;
        }
        int resultIndex = 0;
        for (int i = arraySize; i >= 1; i--)
        {
            for (auto index : valueIndices[i])
            {
                if (previous[index] == index - 1)
                    continue;
                if (queryMaxSegmentTree(1, 1, arraySize, previous[index] + 1, index - 1) < queryMaxSegmentTree(1, 1, arraySize, index + 1, arraySize))
                    continue;
                resultIndex = index;
                break;
            }
            if (resultIndex)
                break;
        }
        if (resultIndex)
        {
            for (int i = 1; i <= previous[resultIndex]; i++)
                inputArray[i] = originalArray[i];
            inputArray[previous[resultIndex] + 1] = originalArray[resultIndex];
            for (int i = previous[resultIndex] + 2; i <= resultIndex; i++)
                inputArray[i] = originalArray[i - 1];
            for (int i = resultIndex + 1; i <= arraySize; i++)
                inputArray[i] = originalArray[i];
        }
        for (int i = 1; i <= arraySize; i++)
            addElement(1, 1, arraySize, inputArray[i]);
        for (int i = 1; i <= arraySize; i++)
        {
            if (inputArray[i] == arraySize)
                stackArray[++stackTop] = inputArray[i];
            else
            {
                if (querySegmentTree(1, 1, arraySize, inputArray[i] + 1, arraySize) == 0)
                    stackArray[++stackTop] = inputArray[i];
            }
            deleteElement(1, 1, arraySize, inputArray[i]);
        }
        for (int i = 1; i < stackTop; i++)
            cout << stackArray[i] << " ";
        cout << stackArray[stackTop] << "\n";
        for (int i = 1; i <= arraySize; i++)
            valueIndices[i].clear();
    }

    return 0;
}
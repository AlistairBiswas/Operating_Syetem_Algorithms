#include <bits/stdc++.h>
using namespace std;

void First_Fit(int total_holes,vector<int>& memoryBlockSize,int total_requests, vector<int>& memoryRequests)
{

    int flag=0;
    int sum = 0;
    vector<int> allocationStatus(total_requests, -1);

    for (int i = 0; i < total_requests; i++)
    {
        for (int j = 0; j < total_holes; j++)
        {
            if (memoryBlockSize[j] >= memoryRequests[i])
            {
                allocationStatus[i] = j+1;
                memoryBlockSize[j] -= memoryRequests[i];
                break;
            }
        }

        if (allocationStatus[i] == -1)
        {
            flag = 1;
            for (int k = 0; k < total_holes; k++)
            {
                sum += memoryBlockSize[k];
            }
        }
    }

    cout << "Process No.\tProcess Size\tMemory" << endl;
    for (int i = 0; i < total_requests; i++)
    {
        cout << " " << i + 1 << "\t\t" << memoryRequests[i] << "\t\t";
        if (allocationStatus[i] != -1)
        {
            cout << allocationStatus[i];
        }
        else
        {
            cout << "Can't be allocated";
        }
        cout << endl;
    }

    if (flag == 1)
    {
        cout << "External Fragmentation: " << sum << endl;
    }
    else cout << "No External Fragmentation" << endl;
}

void Best_Fit(int total_holes,vector<int>& memoryBlockSize,int total_requests, vector<int>& memoryRequests)
{

    int flag=0;
    int sum = 0;
    vector<int> allocationStatus(total_requests, -1);

    for (int i = 0; i < total_requests; i++)
    {
        int temp=INT_MAX,pos;
        for (int j = 0; j < total_holes; j++)
        {
            if (memoryBlockSize[j] >= memoryRequests[i] && temp>memoryBlockSize[j])
            {
                pos = j;
                temp=memoryBlockSize[j];
            }
        }
        memoryBlockSize[pos] -= memoryRequests[i];
        allocationStatus[i]=pos+1;
        if (allocationStatus[i] == -1)
        {
            flag = 1;
            for (int k = 0; k < total_holes; k++)
            {
                sum += memoryBlockSize[k];
            }
        }
    }

    cout << "Process No.\tProcess Size\tMemory" << endl;
    for (int i = 0; i < total_requests; i++)
    {
        cout << " " << i + 1 << "\t\t" << memoryRequests[i] << "\t\t";
        if (allocationStatus[i] != -1)
        {
            cout << allocationStatus[i];
        }
        else
        {
            cout << "Can't be allocated";
        }
        cout << endl;
    }

    if (flag == 1)
    {
        cout << "External Fragmentation: " << sum << endl;
    }
    else cout << "No External Fragmentation" << endl;
}

int main()
{
    int numOfMemoryBlocks,numOfMemoryRequests;

    cout << "Enter the number of memory blocks: ";
    cin >> numOfMemoryBlocks;

    vector<int> memoryBlockSize(numOfMemoryBlocks);
    cout << "Enter block list: ";
    for(int i=0; i<numOfMemoryBlocks; i++)
        cin >> memoryBlockSize[i];

    cout << "Enter the number of memory request: ";

    cin >> numOfMemoryRequests;
    vector<int> memoryRequests(numOfMemoryRequests);
    cout << "Enter memory request list: ";
    for(int i=0; i<numOfMemoryRequests; i++)
        cin >> memoryRequests[i];

    cout << "First Fit" << endl;
    First_Fit(numOfMemoryBlocks,memoryBlockSize,numOfMemoryRequests, memoryRequests);

    cout << "Best Fit" << endl;
    Best_Fit(numOfMemoryBlocks,memoryBlockSize,numOfMemoryRequests, memoryRequests);

    return 0;
}
/*
5
50 200 70 115 15
10
100 10 35 15 23 6 25 55 88 40
*/

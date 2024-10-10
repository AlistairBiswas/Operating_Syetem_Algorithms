#include <bits/stdc++.h>
using namespace std;

int FIFOPageReplacement(vector<int>& pageRequests, int numFrames)
{
    vector<int> pageFrame;
    queue<int>pageQueue;
    int numOfpageFaults = 0;


    for (int i = 0; i < pageRequests.size(); i++)
    {
        int page = pageRequests[i];

        int flag=0;
        for(int i=0; i<pageFrame.size(); i++)
        {
            if(pageFrame[i]==page)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            numOfpageFaults++;
            if (pageQueue.size() == numFrames)
            {
                int oldestPage = pageQueue.front();
                pageQueue.pop();
                pageQueue.push(page);
                pageFrame.push_back(page);
                pageFrame.erase(pageFrame.begin());
            }
            else
            {
                pageQueue.push(page);
                pageFrame.push_back(page);
            }
        }
    }

    return numOfpageFaults;
}

int OptimalPageReplacement(vector<int>& pageRequests, int numFrames)
{
    vector<int> pageFrame;

    int numOfpageFaults = 0;


    for (int i = 0; i < pageRequests.size(); i++)
    {
        int page = pageRequests[i];

        int flag=0;
        for(int j=0; j<pageFrame.size(); j++)
        {
            if(pageFrame[j]==page)
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            numOfpageFaults++;
            if (pageFrame.size() == numFrames)
            {

                int n1=pageFrame[0],n2=pageFrame[1],n3=pageFrame[2];
                int track=0;

                for(int k=i+1; k<pageRequests.size(); k++)
                {
                    if(n1==pageRequests[k])
                    {
                        n1=k;
                        track=1;
                        break;
                    }
                }
                if(!track)
                    n1=INT_MAX;

                track=0;
                for(int k=i+1; k<pageRequests.size(); k++)
                {
                    if(n2==pageRequests[k])
                    {
                        n2=k;
                        track=1;
                        break;
                    }
                }
                if(!track)
                    n2=INT_MAX;

                track=0;
                for(int k=i+1; k<pageRequests.size(); k++)
                {
                    if(n3==pageRequests[k])
                    {
                        n3=k;
                        track=1;
                        break;
                    }
                }
                if(!track)
                    n3=INT_MAX;

                if(n1>n2 && n1>n3)
                    pageFrame[0]=page;
                else if(n2>n1 && n2 > n3)
                    pageFrame[1]=page;
                else pageFrame[2]=page;
            }
            else
            {
                pageFrame.push_back(page);
            }
        }
    }

    return numOfpageFaults;
}

int main()
{
    vector<int> pageRequests = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int numFrames = 3;
    int numPages = 8;


    int pageRequestSize=pageRequests.size();
    int fifoPageFaults = FIFOPageReplacement(pageRequests, numFrames);
    double fifoPageFaultRate = fifoPageFaults / (double)pageRequestSize * 100;

    int optimalPageFaults = OptimalPageReplacement(pageRequests, numFrames);
    double optimalPageFaultRate = optimalPageFaults / (double)pageRequestSize * 100;

    cout << "Number of page fault using FIFO Page replacement Algorithm: " << fifoPageFaults << endl;
    cout << "Page Fault Rate using FIFO: " << fifoPageFaultRate << "%" << endl;



    cout << "\nNumber of page fault using Optimal Page replacement Algorithm: " << optimalPageFaults << endl;
    cout << "Page Fault Rate using Optimal: " << optimalPageFaultRate << "%" << endl;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int LRU_algo(int pRef, int refString[], int frame)
{
    int fault = 0;
    int pageFrames[frame], ref_no = 0, frame_no= 0, past[frame];
    for (int i = 0; i < frame; i++)
    {
        pageFrames[i] = -1;
    }
    while (frame_no< frame)
    {
        pageFrames[frame_no] = refString[ref_no];
        past[frame_no] = ref_no;
        frame_no++;
        ref_no++;
        fault++;
    }
    while (ref_no < pRef)
    {
        bool pageFault = false;
        for (int i = 0; i < frame; i++)
        {

            if (refString[ref_no] != pageFrames[i])
            {
                pageFault = true;
            }
            else
            {
                past[i] = ref_no;
                pageFault = false;
                break;
            }
        }
        if (pageFault)
        {
            frame_no= 0;
            for (int i = 1; i < frame; i++)
            {
                if (past[i] < past[frame_no] )
                    frame_no= i;
            }
            past[frame_no] = ref_no;
            cout<<refString[ref_no]<<" --> "<<pageFrames[frame_no] <<endl;
            pageFrames[frame_no] = refString[ref_no];
            fault++;
        }
        ref_no++;
    }
    return fault;
}


void faultRate(int fault, int pRef)
{
    int rate = round(100 * (double)fault/ pRef);
    cout << "Page Fault Rate: " << rate << "%" << endl;
}

int main()
{
    cout << "Number of pages: ";
    int page;
    cin >> page;
    cout << "Number of page References: ";
    int pRef;
    cin >> pRef;
    cout << "Reference String: ";
    int refString[pRef];
    for (int i = 0; i < pRef; i++)
    {
        cin >> refString[i];
    }
    cout << "Number of Memory  Frame: ";
    int frame;
    cin >> frame;
    int LRU = LRU_algo(pRef, refString, frame);

    cout << "Number of page fault using LRU Page replacement Algorithm: " << LRU << endl;
    faultRate(LRU, pRef);

    return 0;
}
/*
6
22
7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
3
*/

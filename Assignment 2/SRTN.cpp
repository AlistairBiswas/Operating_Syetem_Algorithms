#include<bits/stdc++.h>
using namespace std;

int main()
{
    int np, tCpuTime = 0;
    cout << "Enter the number of process: ";
    cin >> np;

    vector<int>cpuTime(np);
    cout << "Enter the CPU times: ";
    for(int i=0; i<np; i++)
    {
        cin >> cpuTime[i];
        tCpuTime += cpuTime[i];
    }

    vector<int>arrivalTime(np);
    cout << "Enter the Arrival times: ";
    for(int i=0; i<np; i++)
        cin >> arrivalTime[i];

    vector<pair<int, int>>Process;
    for(int i=0; i<np; i++)
        Process.push_back(make_pair(arrivalTime[i], cpuTime[i]));
    sort(Process.begin(), Process.end());

    for(int i=0; i<Process.size(); i++)
        cout << Process[i].first << " " << Process[i].second << endl;

    vector<int>visited(np);
    for (int i=0; i<np; i++)
    {
        visited[i] = Process[i].second;
    }

    double gantt = 0, twt = 0, ttt = 0, wt = 0, tt = 0, temp = 0, pp = 0;

    vector<pair<int, int>>gChart;
    vector<int>g;

    g.push_back(0);

    for (int i=0; i<tCpuTime; i++)
    {
        int min = INT_MAX, position = 0;
        for (int j=0; j<np; j++)
        {
            if (Process[j].first <= i)
            {
                if (visited[j] != 0 && min > visited[j])
                {
                    min = visited[j];
                    position = j;
                }
            }
            else
                break;
        }
        if (temp == position)
            visited[position] -= 1;
        else
        {
            g.push_back(i);
            visited[position] -= 1;
            gChart.push_back(make_pair(i-pp, temp+1));
            temp = position;
            pp = i;
        }

        if (i == tCpuTime-1)
        {
            g.push_back(tCpuTime);
            gChart.push_back(make_pair(i-pp, position+1));
        }
    }

    cout << "\nGantt Chart : ";
    cout << g[0];

    for (int i=0; i<g.size(); i++)
    {
        for (int j=0; j<gChart[i-1].first; j++)
        {
            cout << "--";
            if (j == gChart[i-1].first/2)
                cout << "p" << gChart[i-1].second;
        }
        cout << g[i];
    }
    cout << endl;

    for (int i=1; i<=np; i++)
    {
        wt = 0, gantt = Process[i-1].first;
        for (int j=0; j<g.size(); j++)
        {
            if (gChart[j].second == i)
            {
                wt += g[j]-gantt;
                gantt = gChart[j].second + g[j];
            } 
        }
        tt = wt + Process[i-1].second;
        twt += wt;
        ttt += tt;
        cout << "Process " << i+1 << ": " << "Waiting Time:" << wt << " Turnaround Time:" << tt << endl;
    }

    double awt = twt/np;
    double att = ttt/np;

    cout << "Average Waiting time : " << awt << endl;
    cout << "Average Turnarount time : " << att << endl;

    return 0;
}
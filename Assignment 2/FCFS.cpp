#include<bits/stdc++.h>
using namespace std;

int main()
{
    int np;
    cout << "Enter the number of process: ";
    cin >> np;

    vector<int>cpuTime(np);
    cout << "Enter the CPU times: ";
    for(int i=0; i<np; i++)
        cin >> cpuTime[i];

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

    double gantt = 0, twt = 0, ttt = 0, wt = 0, tt = 0;

    vector<int>gChart;
    vector<int>g;

    for(int i=0; i<np; i++)
    {
        wt = gantt - Process[i].first;
        tt = wt + Process[i].second;
        gantt += Process[i].second;
        gChart.push_back(Process[i].second);
        g.push_back(gantt);
        twt += wt;
        ttt += tt;
        cout << "Process " << i+1 << ": " << "Waiting Time:" << wt << " Turnaround Time:" << tt << endl;
    }

    cout << "\nGantt Chart : ";
    cout << 0;
    for(int i=0; i<gChart.size(); i++)
    {
        for (int j=0; j<gChart[i]; j++)
        {
            cout << "--";
            if (j == gChart[i]/2)
                cout << "p" << i+1;
        }
        cout << g[i];
    }
    cout << endl;

    double awt = twt/np;
    double att = ttt/np;

    cout << "Average Waiting time : " << awt << endl;
    cout << "Average Turnarount time : " << att << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Activity
{
    int start_time;
    int end_time;
    int index;
};

vector <Activity> v;

bool compare (Activity a, Activity b)
{
    return a.end_time < b.end_time;
}
int main ()
{
    int t; cin >> t;
    int i=0;
    while (t--) {
        Activity ac;
        cin >> ac.start_time >> ac.end_time;
        ac.index=++i;
        v.push_back(ac);

    }
    int classAttend = 0;

    sort (v.begin(), v.end(), compare);

    int currentTime = 0;

    for (auto[s,e,i]: v) {
        if (s>=currentTime) {
            currentTime=e+2;
            classAttend++;
            cout << "Class No. " << i << " Attended" << endl;
        }
    }
    cout << "Total Class Attended: " << classAttend << endl;
}

/*

10
0 6
3 5
0 4
4 6
7 11
8 10 9 22
7 8
8 16
13 16

*/

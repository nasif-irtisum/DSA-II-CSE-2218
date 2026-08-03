#include <bits/stdc++.h>
using namespace std;

pair <int, int> secondMin(vector <int> v)
{
    if (v.size()==1) {
        return {v[0], INT_MAX};
    }
    vector <int> leftHalf, rightHalf;

    for (int i=0; i<v.size()/2; i++) leftHalf.push_back(v[i]);
    for (int i=v.size()/2; i<v.size(); i++) rightHalf.push_back(v[i]);

    pair <int, int> left = secondMin(leftHalf);
    pair <int, int> right = secondMin(rightHalf);

    int smallest, secondSmallest;

    if (left.first < right.first) {
        smallest = left.first;
        secondSmallest = min(right.first, left.second);
    }
    else {
        smallest = right.first;
        secondSmallest=min(right.second, left.first);
    }
    return {smallest, secondSmallest};
}
int main ()
{
    int t; cin >> t;
    vector <int> v;
    while (t--) {
        int num; cin >> num;
        v.push_back(num);
    }
    if (v.size()<2) {
        cout << "Second largest element not possible!" << endl;
        return 0;
    }
    pair <int, int> ans = secondMin(v);

    cout << ans.second << endl;
}

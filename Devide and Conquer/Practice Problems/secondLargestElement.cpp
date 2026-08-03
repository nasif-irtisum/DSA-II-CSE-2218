#include <bits/stdc++.h>
using namespace std;

pair <int, int> secondMax (vector <int> v)
{
    if (v.size()==1) {
        return {v[0], INT_MIN};
    }
    vector <int> leftHalf, rightHalf;

    for (int i=0; i<v.size()/2; i++) leftHalf.push_back(v[i]);
    for (int i=v.size()/2; i<v.size(); i++) rightHalf.push_back(v[i]);

    pair <int, int> left = secondMax(leftHalf);
    pair <int, int> right = secondMax(rightHalf);

    int largest, secondLargest;

    if (left.first > right.first) {
        largest = left.first;
        secondLargest= max (right.first, left.second);
    }
    else {
        largest = right.first;
        secondLargest=max(right.second, left.first);
    }
    return {largest, secondLargest};
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
    pair <int, int> ans = secondMax(v);

    cout << ans.second << endl;
}

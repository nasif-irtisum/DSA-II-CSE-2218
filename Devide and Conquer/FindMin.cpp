#include <bits/stdc++.h>
using namespace std;
int findMin (vector <int> v)
{
    if (v.size()==1) return v[0];

    vector <int> left, right;

    for (int i=0; i<v.size()/2; i++) {
        left.push_back(v[i]);
    }
    for (int i=v.size()/2; i<v.size(); i++) {
        right.push_back(v[i]);
    }

    int leftMin = findMin(left), rightMin = findMin(right);

    return min (leftMin, rightMin);
}
int main ()
{
    int n; cin >> n;
    vector <int> v;
    while (n--) {
        int value; cin >> value;
        v.push_back(value);
    }
    cout << findMin(v) << endl;
}

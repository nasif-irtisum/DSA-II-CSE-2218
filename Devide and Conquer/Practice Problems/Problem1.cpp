#include <bits/stdc++.h>
using namespace std;
struct Result
{
    int minValue;
    int maxValue;
};
Result findMinMax (vector <int> v)
{
    if (v.size()==1) return {v[0], v[0]};

    vector <int> left, right;

    for (int i=0; i<v.size()/2; i++) left.push_back(v[i]);
    for (int i=v.size()/2; i<v.size(); i++) right.push_back(v[i]);

    Result leftVal = findMinMax (left);
    Result rightVal = findMinMax(right);

    Result combined;
    combined.maxValue = max (rightVal.maxValue, leftVal.maxValue);
    combined.minValue = min (rightVal.minValue, leftVal.minValue);

    return combined;
}
int main ()
{
    int t; cin >> t;
    vector <int> v;
    while (t--) {
        int value; cin >> value;
        v.push_back(value);

    }
    Result res = findMinMax(v);
    cout << res.maxValue << endl;
    cout << res.minValue << endl;
}

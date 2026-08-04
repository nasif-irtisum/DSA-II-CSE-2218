#include <bits/stdc++.h>
using namespace std;

int prefixSum (vector <int> v)
{
    int sum = 0, runningSum =0;

    for (int i=0; i<v.size(); i++) {
        runningSum += v[i];
        sum = min (sum, runningSum);
    }
    return sum;
}
int suffixSum (vector <int> v)
{
    int sum = 0, runningSum =0;

    for (int i=v.size()-1; i>=0; i--) {
        runningSum += v[i];
        sum = min (sum, runningSum);
    }
    return sum;
}
int minSum (vector <int> v)
{
    if (v.size()==1) return min (v[0], INT_MAX);

    vector <int> leftHalf, rightHalf;

    for (int i=0; i<v.size()/2; i++) leftHalf.push_back(v[i]);
    for (int i=v.size()/2; i<v.size(); i++) rightHalf.push_back(v[i]);

    int leftAns = minSum(leftHalf);
    int rightAns = minSum(rightHalf);

    int preSum = prefixSum(rightHalf);
    int suffSum = suffixSum(leftHalf);

    return min ({leftAns, rightAns, (preSum+suffSum)});
}
int main ()
{
    int n; cin >> n;
    vector <int> v;
    while (n--) {
        int value; cin >> value;
        v.push_back(value);
    }
    cout << minSum(v) << endl;
}

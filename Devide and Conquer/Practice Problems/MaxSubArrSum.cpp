#include <bits/stdc++.h>
using namespace std;

int prefixSum (vector <int> v)
{
    int sum = INT_MIN, runningSum =0;

    for (int i=0; i<v.size(); i++) {
        runningSum += v[i];
        sum = max (sum, runningSum);
    }
    return sum;
}
int suffixSum (vector <int> v)
{
    int sum = INT_MIN, runningSum =0;

    for (int i=v.size()-1; i>=0; i--) {
        runningSum += v[i];
        sum = max (sum, runningSum);
    }
    return sum;
}
int maxSum (vector <int> v)
{
    if (v.size()==1) return max (v[0], INT_MIN);

    vector <int> leftHalf, rightHalf;

    for (int i=0; i<v.size()/2; i++) leftHalf.push_back(v[i]);
    for (int i=v.size()/2; i<v.size(); i++) rightHalf.push_back(v[i]);

    int leftAns = maxSum(leftHalf);
    int rightAns = maxSum(rightHalf);

    int preSum = prefixSum(rightHalf);
    int suffSum = suffixSum(leftHalf);

    return max ({leftAns, rightAns, (preSum+suffSum)});
}
int main ()
{
    int n; cin >> n;
    vector <int> v;
    while (n--) {
        int value; cin >> value;
        v.push_back(value);
    }
    cout << maxSum(v) << endl;
}

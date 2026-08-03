#include <bits/stdc++.h>
using namespace std;

int suffixSum (vector <int> v)
{
    int sum=0, runnig_sum =0;
    for (int i=v.size()-1; i>=0; i--) {
        runnig_sum+= v[i];
        sum = max (sum, runnig_sum);
    }
    return sum;
}
int prefixSum (vector <int> v)
{
    int sum = 0, runnig_sum = 0;
    for (int i=0; i<v.size(); i++) {
        runnig_sum+= v[i];
        sum = max (sum, runnig_sum);
    }
    return sum;
}

int getMaxSum (vector <int> v)
{
    if (v.size()==1) return max (v[0], 0);

    vector <int> leftHalf, rightHalf;

    for (int i=0; i<v.size ()/2; i++) leftHalf.push_back(v[i]);
    for (int i=v.size()/2; i<v.size(); i++) rightHalf.push_back(v[i]);

    int leftRes = getMaxSum(leftHalf);
    int rightRes = getMaxSum(rightHalf);

    int leftSuf = suffixSum(leftHalf);
    int rightPref = prefixSum(rightHalf);

    return max ({leftRes, rightRes, (leftSuf+rightPref)});
}
int main ()
{
    int n; cin >> n;
    vector <int> v;
    while (n--) {
        int value; cin >> value;
        v.push_back(value);
    }
    cout << getMaxSum(v) << endl;

}

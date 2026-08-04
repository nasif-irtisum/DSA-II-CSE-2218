#include <bits/stdc++.h>
using namespace std;
int suffix(vector<int> v)
{
    int mul=1, runningMul = 1;
    for (int i=v.size()-1; i>=0; i--) {
        if (v[i]==0) return 0;
        runningMul *= v[i];
        mul = max(mul, runningMul);
    }

    return mul;
}
int prefix(vector<int> v)
{
    int mul=1, runningMul = 1;
    for (int i=0; i<v.size(); i++) {
        if (v[i]==0) return 0;
        runningMul *= v[i];
        mul = max(mul, runningMul);
    }

    return mul;
}

int getMax (vector<int>v) {
    if (v.size()==1) return v[0]*1;

    vector <int> leftHalf, rightHalf;

    for (int i=0; i<v.size()/2; i++) leftHalf.push_back(v[i]);
    for (int i=v.size()/2; i<v.size(); i++) rightHalf.push_back(v[i]);

    int left = getMax (leftHalf);
    int right = getMax (rightHalf);

    int leftSuf = suffix(leftHalf);
    int rightPref = prefix(rightHalf);
    return max({left, right, (leftSuf*rightPref)});
}
int main ()
{
    int t; cin >> t;
    if (t==2) {
        int a,b; cin >> a >> b;
        cout << a*b << endl;
        return 0;
    }
    vector<int>v;
    while (t--) {
        int num; cin >> num;
        v.push_back(num);
    }
    cout << getMax (v) << endl;
}

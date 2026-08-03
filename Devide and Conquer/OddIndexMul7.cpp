#include <bits/stdc++.h>
using namespace std;

int findOddinMul7 (vector <int> v, int l, int r)
{
    if (l==r) {
        if (l%2==1 and v[l]%7==0) return v[l];
        else return 0;
    }
    int mid = l + (r-l)/2;

    int left = findOddinMul7(v, l, mid);
    int right = findOddinMul7(v, mid+1, r);

    return left+right;
}
int main ()
{
    int n; cin >> n;
    vector <int> v;
    while (n--) {
        int value; cin >> value;
        v.push_back(value);
    }
    cout << findOddinMul7(v,0, v.size()-1) << endl;
}

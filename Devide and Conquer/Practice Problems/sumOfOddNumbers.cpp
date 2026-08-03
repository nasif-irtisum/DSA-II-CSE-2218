#include <bits/stdc++.h>
using namespace std;
int sumOdd (vector <int> v, int l, int r)
{
    if (l==r) {
        if (v[l]%2==1) return v[l];
        return 0;
    }
    int mid = l + (r-l)/2;

    int left = sumOdd(v, l, mid);
    int right = sumOdd(v, mid+1, r);

    return left+right;
}
int main ()
{
    int t; cin >> t;
    vector <int> v;
    while (t--) {
        int num; cin >> num;
        v.push_back(num);
    }
    cout << sumOdd(v, 0, v.size()-1) << endl;

}

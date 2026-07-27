#include <bits/stdc++.h>
using namespace std;

int findOdd (vector <int> v, int low, int high)
{
    if (low==high) {
        if (v[low]%2==1) return 1;
        else return 0;
    }

    int mid = low + (high-low)/2;

    int leftCnt = findOdd(v, low, mid);
    int rightCnt = findOdd (v, mid+1, high);

    return leftCnt + rightCnt;
}

int main ()
{
    int n; cin >> n;
    vector <int> v;
    while (n--) {
        int value; cin >> value;
        v.push_back(value);
    }
    cout << findOdd(v,0, v.size()-1) << endl;

}


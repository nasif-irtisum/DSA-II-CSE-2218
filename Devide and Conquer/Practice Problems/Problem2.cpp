#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+2;
int checker[N] = {0};
vector <int> mergeVectors (vector <int> a, vector <int> b)
{
    int i=0,j=0;
    a.push_back(INT_MAX); b.push_back(INT_MAX);
    vector <int> ret;
    while (a[i]!=INT_MAX or b[j]!=INT_MAX) {
        if (a[i]<b[j]) {
            ret.push_back(a[i]);
            i++;
        }
        else {
            ret.push_back(b[j]);
            j++;
        }
    }
    return ret;
}

vector <int> mergeSort (vector <int> v)
{
    if (v.size()==1) return v;

    vector <int> left, right;

    for (int i=0; i<v.size()/2; i++) left.push_back(v[i]);
    for (int i=v.size()/2; i<v.size(); i++) right.push_back(v[i]);

    left = mergeSort(left);
    right = mergeSort(right);

    return mergeVectors(left, right);
}

int main ()
{
    int t; cin >> t;
    vector <int> v;
    while (t--) {
        int value; cin >> value;
        v.push_back(value);
        checker[value]++;

    }
    auto vec = mergeSort(v);

    for (auto i : vec) {
        if (checker[i]>0) {
            cout << vec[i] << " ";
            checker [i] = 0;
        }
    }

}

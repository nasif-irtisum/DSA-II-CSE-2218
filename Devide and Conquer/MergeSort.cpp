#include <bits/stdc++.h>
using namespace std;

vector <int> mergeTwoVectors (vector <int> a, vector <int> b)
{
    a.push_back(INT_MAX); b.push_back(INT_MAX);
    int i =0, j=0; vector <int> ret;

    while (!(a[i]==INT_MAX and b[j]==INT_MAX)) {
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
    if (v.size ()==1) return v;

    vector <int> leftHalf, rightHalf;
    for (int i=0; i<v.size()/2; i++) leftHalf.push_back(v[i]);
    for (int i=v.size()/2; i<v.size(); i++) rightHalf.push_back(v[i]);

    leftHalf = mergeSort(leftHalf);
    rightHalf = mergeSort(rightHalf);

    return mergeTwoVectors(leftHalf, rightHalf);
}
int main ()
{
    vector <int> v = {4, 3, -1, 2, 7, 0};
    auto result = mergeSort(v);
    for(auto x : result)
       cout << x << " ";
    cout << endl;
}

#include <bits/stdc++.h>
using namespace std;

int div7 (vector <int> v)
{
    if (v.size()==1) {
        if (v[0]%7==0) return v[0];
        else return 0;
    }
    vector <int> leftHalf, rightHalf;

    for (int i=0; i<v.size()/2; i++) leftHalf.push_back(v[i]);
    for (int i=v.size()/2; i<v.size(); i++) rightHalf.push_back(v[i]);

    int left = div7 (leftHalf), right = div7 (rightHalf);

    return left + right;
}
int main ()
{
    int t; cin >> t;
    vector<int>v;
    while (t--) {
        int num; cin >> num;
        v.push_back(num);
    }
    cout << div7 (v) << endl;
}

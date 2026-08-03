#include <bits/stdc++.h>
using namespace std;

int sumEven (vector <int> v)
{
    if (v.size()==1) {
        if (v[0]%2==0) return v[0];
        else return 0;
        }
        vector <int> leftHalf, rightHalf;

        for (int i=0; i<v.size()/2; i++) leftHalf.push_back(v[i]);
        for (int i=v.size()/2; i<v.size(); i++) rightHalf.push_back(v[i]);

        int left = sumEven(leftHalf), right = sumEven(rightHalf);

        return left + right;

}
int main ()
{
    int t; cin >> t;
    vector <int> v;
    while (t--) {
        int num; cin >> num;
        v.push_back(num);
    }
    cout << sumEven(v) << endl;

}

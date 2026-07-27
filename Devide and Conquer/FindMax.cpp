#include <bits/stdc++.h>
using namespace std;

int findMax (vector <int> v)
{
    if (v.size()==1) return v[0];

    vector <int> leftHalf, rightHalf;

    for (int i=0; i<v.size()/2; i++)
        leftHalf.push_back(v[i]);

    for (int i=v.size()/2; i<v.size(); i++)
        rightHalf.push_back(v[i]);

    int leftAns = findMax(leftHalf);
    int rightAns = findMax (rightHalf);

    return max(leftAns, rightAns);

}
int main ()
{
    int n; cin >> n;
    vector <int> v;
    while (n--) {
        int value; cin >> value;
        v.push_back(value);
    }
    cout << findMax(v) << endl;
}

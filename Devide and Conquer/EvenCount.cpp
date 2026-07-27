#include <bits/stdc++.h>
using namespace std;

int evenCount (vector <int> v, int left, int right)
{
    if (left==right){
        if (v[left]%2==0) return 1;
        else return 0;
    }

    int mid = left + (right-left)/2;

    int leftCount = evenCount(v, left, mid);
    int rightCount = evenCount(v, mid+1, right);

    return leftCount + rightCount;
}



int main ()
{
    int n; cin >> n;
    vector <int> v;
    while (n--) {
        int value; cin >> value;
        v.push_back(value);
    }
    cout << evenCount(v,0, v.size()-1) << endl;

}

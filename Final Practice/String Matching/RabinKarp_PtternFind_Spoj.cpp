#include <bits/stdc++.h>
using namespace std;
int hashValue(string str)
{
    int res = 0;
    for (int s: str) {
        res+=s;
    }
    return res;
}

void rabinCarp(string text, string pattern)

{
    vector <int> indices;
    int n = text.size(), m = pattern.size();
    int patternHash = hashValue(pattern);
    int windowHash = hashValue(text.substr(0, pattern.size()));
    for (int i=0; i<n-m+1; i++) {
        if(patternHash==windowHash) {
            if (pattern==text.substr(i, pattern.size())) {
                indices.push_back(i+1);
            }
        }

        if (i<=n-m) windowHash = windowHash- text[i] + text[i+m];

    }
    if (indices.size()==0) {
        cout << "Not Found" << endl;
        return;
    }
    cout << indices.size () << endl;
    for (int i=0; i<indices.size(); i++) {
        if (indices.size()-1==i) cout << indices[i] << endl;
        else cout << indices [i] << " ";
    }
}

int main ()
{
    int t; cin >> t;
    while (t--) {
        string text, pattern; cin >> text >> pattern;
        rabinCarp(text, pattern);
    }
}

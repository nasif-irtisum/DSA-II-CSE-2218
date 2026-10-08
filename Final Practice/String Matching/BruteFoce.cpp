#include <bits/stdc++.h>
using namespace std;

void stringMatching (string text, string pattern)
{
    vector <int> indices;
    int n = text.size(), m= pattern.size();
    for (int i=0; i<n-m+1; i++) {
        string window = text.substr(i, pattern.size());
        if (pattern==window) indices.push_back(i);
    }
    cout << indices.size() << endl;
    for (int i=0; i<indices.size(); i++) {
        if (indices.size()-1==i) cout << indices[i] << endl;
        else cout << indices [i] << " ";
    }
}
int main ()
{
    string text = "";
    string pattern = "";
    cin >> text;
    cin >> pattern;

    //cout << hashValue(text) << "---" << hashValue(pattern);
    stringMatching(text, pattern);
}

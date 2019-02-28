#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

string a[100005];
map<string, int> mp;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < a[i].size(); j++) {
            mp[a[i].substr(j)]++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << mp[a[i]] << endl;
    }
}
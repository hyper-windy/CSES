#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long s = 0;
    for (int i = 1; i < n; ++i) {
        int a;
        cin >> a;
        s += a;
    }

    cout << n * (n + 1) / 2  - s << '\n';
}
#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxX = 1e6 + 100;
const int maxN = 100 + 10;
const int base = 1e9 + 7;

int n, x;
int a[maxN];
int f[maxX];

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> x;
    for (int i = 0; i < n; ++i) 
        cin >> a[i];

    f[0] = 1;
    for (int j = 0; j < n; ++j)
        for (int i = 1; i <= x; ++i) 
            if (i - a[j] >= 0) f[i] = (f[i] + f[i - a[j]])%base;

    cout << f[x] << '\n';
}

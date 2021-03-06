#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;

multiset<int> s;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    int res = 0;
    while (n--) {
        int a; cin >> a;

        auto it = s.upper_bound(a);
        if (it != s.end()) 
            s.erase(it);
        else
            ++res;

        s.insert(a);
    }
    cout << s.size() << '\n';
}
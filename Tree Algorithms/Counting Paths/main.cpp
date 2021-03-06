#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
const int maxN = 2e5 + 100;
const int maxLN = 25;
 
template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
 
int n;
vector<int> adj[maxN];

int h[maxN];
int asc[maxN][maxLN];

int pb[maxN], pe[maxN];
int res[maxN];
 
void DFS(int u = 1, int p = 0) {
    asc[u][0] = p;
    for (int i = 1; i < maxLN; ++i)
        asc[u][i] = asc[asc[u][i - 1]][i - 1];
 
    for (int v: adj[u])
        if (v != p) {
            h[v] = h[u] + 1;
            DFS(v, u);
        }
}
 
int lca(int x, int y) {
    if (h[x] > h[y]) 
        swap(x, y);
 
    for (int i = maxLN - 1; i >= 0; --i) 
        if (h[asc[y][i]] >= h[x])
            y = asc[y][i];
    if (x == y)
        return x;
 
    for (int i = maxLN - 1; i >= 0; --i)
        if (asc[x][i] != asc[y][i]) {
            x = asc[x][i];
            y = asc[y][i];
        }
 
    return asc[x][0];
}

void DFS_res(int u, int p, int& pc) {
    int opc = pc += pb[u];

    for (int v: adj[u])
        if (v != p) {
            DFS_res(v, u, pc);
        }

    pc -= pe[u];
    res[u] += opc - pc;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int m;
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    h[1] = 1;
    DFS();

    while (m--) {
        int x, y;
        cin >> x >> y;
        int a = lca(x, y);
        if (x == a) {
            ++pb[x];
            ++pe[y];
        }
        else if (y == a) {
            ++pb[y];
            ++pe[x];
        }
        else {
            pb[a] += 2;
            --res[a];
            ++pe[x];
            ++pe[y];
        }
    }

    int pc = 0;
    DFS_res(1, 0, pc);

    for (int i = 1; i <= n; ++i)
        cout << res[i] << ' ';
}
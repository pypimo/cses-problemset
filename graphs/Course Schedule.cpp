#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxN = 1e5+10;
int vis[maxN], pos[maxN];
vector<ll> adj[maxN], st;

void dfs(ll node) {
    vis[node]=1;
    for (auto it : adj[node]) {
        if (!vis[it]) dfs(it);
    }
    st.push_back(node);
} 

bool cycle(ll n) {
    for (int i=0; i<n; i++) {
        pos[st[i]]=i;
    }
    for (int u=1; u<=n; u++) {
        for (auto v : adj[u]) {
            if (pos[u]>=pos[v]) return true;
        }
    }
    return false;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m;
    cin >> n >> m;
 
    // dfs on a directed graph
    for (int i=0; i<m; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (ll i=1; i<=n; i++) {
        if (!vis[i]) dfs(i);
    }
    reverse(st.begin(), st.end());
    if (cycle(n)) cout << "IMPOSSIBLE";
    else {
        for (auto x : st) cout << x << " ";
    }

    return 0;
}

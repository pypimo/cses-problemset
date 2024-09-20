#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxN = 1e5+10;
vector<ll> path;
ll vis[maxN], pathVis[maxN];
vector<ll> adj[maxN];
ll stop=-1;

bool dfs(ll node) {
    vis[node]=1;
    pathVis[node]=1;
    for (auto it : adj[node]) {
        if (!vis[it] && dfs(it)) {
            if (stop!=-1) {
                path.push_back(node);
                if (node==stop) stop=-1;
            } 
            return true;
        } else if (pathVis[it]) {
            stop = it;
            path.push_back(it);
            path.push_back(node);
            return true;
        }
    }
    pathVis[node]=0;
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
        if (path.size()) break;
    }

    if (!path.size()) cout << "IMPOSSIBLE";
    else {
        cout << path.size() << '\n';
        for (int i=path.size()-1; i>=0; i--) 
            cout << path[i] << " ";
    }
    
    return 0;
}

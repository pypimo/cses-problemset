#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+10;
vector<int> adj[maxN];
vector<int> vis(maxN);

bool dfs(int node, int parent, vector<int>& path) {
    vis[node]=1;
    path.push_back(node);
    for (auto it: adj[node]) {
        if (vis[it] && it!=parent) {
            path.push_back(it);
            return true;
        } else if (!vis[it] && dfs(it, node, path)) return true;
    }
    path.pop_back();
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // print a cycle using DFS
    int n,m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> path;
    for (int i=1; i<=n; i++) {
        if (!vis[i] && dfs(i, -1, path)) break;
    }

    int sz = path.size();
    if (!sz) cout << "IMPOSSIBLE";
    else {
        int ind=-1;
        for (int i=0; i<sz-1; i++) {
            if (path[i]==path[sz-1])  ind=i;
        }
        cout << sz-ind << '\n';
        for (int i=ind; i<sz; i++) cout << path[i] << ' ';
    }
    

    return 0;
}

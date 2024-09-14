#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
vector<ll> adj[100010];
ll vis[100010];
vector <ll> v;
 
void dfs(ll node) {
    vis[node]=1;
    for (auto next: adj[node]) {
        if (!vis[next]) dfs(next);
    }
    return;
}
 
int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
    ll n, m, a, b;
    cin >> n >> m;
    
    while(m--) {
        cin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    
    for (ll i=1; i<=n; i++) {
        if (!vis[i]) {
            dfs(i);
            v.push_back(i);
        }
    }
    
    cout << v.size()-1 << '\n';
    if (v.size()>1) {
        for (ll i=0; i<v.size()-1; i++) {
            cout << v[i] << " " << v[i+1] << '\n';
        }
    }
     
    return 0;
}

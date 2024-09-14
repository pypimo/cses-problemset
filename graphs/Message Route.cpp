#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const ll maxN = 200010;
ll vis[maxN];
vector <ll> adj[maxN]; 
ll path[maxN];
vector <ll> v;
 
void bfs(ll node) {
    queue <ll> q;
    vis[node]=1;
    q.push(node);
    while (!q.empty()) {
        ll curr = q.front();
        q.pop();
        for (auto x: adj[curr]) {
            if (!vis[x]) {
                vis[x]=1;
                path[x] = curr;
                q.push(x);
            }
        }
    }
}
 
void findpath(ll node) {
    v.push_back(node);
    if (node==1) return;
    findpath(path[node]);
}
 
int main(){
    
    ll n, m, a, b;
    cin >> n >> m;
    
    for (ll i=0; i<m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    
    bfs(1);
    if (!vis[n]) cout << "IMPOSSIBLE";
    else {
        findpath(n);
        cout << v.size() << '\n';
        for (ll i=v.size()-1; i>=0; i--) {
            cout << v[i] << " ";
        }
    }
 
    return 0;
}

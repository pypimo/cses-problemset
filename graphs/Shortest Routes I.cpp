#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxN = 1e5+10;
vector<pair<ll,ll>> adj[maxN];
vector<ll> dist(maxN, LLONG_MAX);

void dijkstra(ll start) {
    priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq; //min heap
    pq.push({0ll,start});
    while(!pq.empty()) {
        ll node = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if (d>=dist[node]) continue;
        dist[node]=d;
        for (auto it : adj[node]) {
            ll u =  it.first, du = it.second;
            if (d+du<dist[u]) pq.push({d+du, u});
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // implement dijkstra
    ll n,m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
    }

    dijkstra(1ll);

    for (int i=1; i<=n; i++) {
        cout << dist[i] <<  " ";
    }

    return 0;
}

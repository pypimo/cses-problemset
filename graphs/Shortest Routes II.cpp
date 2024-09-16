#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
vector<vector<ll>> dist(510, vector<ll>(510, LLONG_MAX));
ll n,m;
 
void floydWarshall() {
    // no self loops
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i==j) dist[i][j]=0;
        }
    }
    // shortest dist
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
 
    // no paths
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (dist[i][j]==LLONG_MAX) dist[i][j]=-1;
        }
    }
}
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll q;
    cin >> n >> m >> q;
    for (int i=0; i<m; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;
        dist[u][v]=min(dist[u][v], wt);
        dist[v][u]=min(dist[v][u], wt);
    }
 
    floydWarshall();
 
    while(q--) {
        ll a, b;
        cin >> a >> b;
        cout << dist[a][b] << '\n';
    }
 
    return 0;
}

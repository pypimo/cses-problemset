#include <bits/stdc++.h>
using namespace std;
 
vector<int> X = {-1,0,0,+1};
vector<int> Y = {0,-1,+1,0};
 
int n,m, rooms=0;
char mat[1001][1001];
int vis[1001][1001];
 
void dfs(int x, int y) {
    if (x<0 || x>=n || y<0 || y>=m) return;
    if (vis[x][y] || mat[x][y]=='#') return;
    vis[x][y]=1;
    for (int i=0; i<4; i++) {
        dfs(x+X[i],y+Y[i]);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
 
 
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat[i][j]=='.' && !vis[i][j]) {
                rooms++;
                dfs(i,j);
            } 
        }
    }  
 
    cout << rooms;  
 
    return 0;
}

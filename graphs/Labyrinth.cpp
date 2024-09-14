#include <bits/stdc++.h>
using namespace std;
 
vector<int> X = {-1,0,0,+1};
vector<int> Y = {0,-1,+1,0};
vector<string> D = {"D", "R", "L", "U"};
 
int n,m, destX, destY;
// vector<vector<char>> mat(1000, vector<char>(1000));
// vector<vector<int>> vis(1000, vector<int>(1000,1000000));
int vis[1000][1000];
char mat[1000][1000];
 
void bfs(int startX, int startY) {
    queue<pair<int,int>> q;
    q.push({startX, startY});
    vis[startX][startY]=0;
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i=0; i<4; i++) {
            int dirX = x + X[i], dirY = y+Y[i];
            if (dirX>=0 && dirX<n && dirY>=0 && dirY<m && vis[dirX][dirY]==10000000 && mat[dirX][dirY]!='#') {
                vis[dirX][dirY]=1+vis[x][y];
                if (x==destX && y==destY) return;
                q.push({dirX, dirY});
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            vis[i][j]=10000000;
        }
    }
    int x=0,y=0;
 
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> mat[i][j];
            if (mat[i][j]=='A') {
                x=i; y=j;
            }
            if (mat[i][j]=='B') {
                destX=i; destY=j;
            }
        }
    }
    bfs(x,y);
 
    if (vis[destX][destY]==10000000) cout << "NO";
    else {
        cout << "YES\n";
        string ans="";
 
        while(destX!=x || destY!=y) {
  
            for (int i=0; i<4; i++) {
                int dirX = destX + X[i], dirY = destY+Y[i];
                if (dirX>=0 && dirX<n && dirY>=0 && dirY<m && vis[dirX][dirY]==vis[destX][destY]-1) {
                    ans +=D[i];
                    destX=dirX; destY=dirY;
                    // cout << destX << " " << destY << ' ';
                    // cout << vis[destX][destY] << '\n';
                    break;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n" << ans;
    }
 
    return 0;
}

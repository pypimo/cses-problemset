#include<bits/stdc++.h>
using namespace std;

const int maxN = 1010;
int dist[maxN][maxN];
char mat[maxN][maxN];

vector<int> dirR = {-1,0,0,+1};
vector<int> dirC = {0,-1,+1,0};
vector<string> dir = {"D","R","L","U"};
int n,m;

string path="";
void findPath(int i, int j) {
    // cout << i <<  " " << j << " " <<  dist[i][j]<< "\n";
    if (dist[i][j]==0) return;
    for (int k=0; k<4; k++) {
        int row = i+dirR[k], col = j+dirC[k];
        if (row>=0 && row<n && col>=0 && col<m && dist[row][col]==dist[i][j]-1) {
            path += dir[k];
            return findPath(row, col);
        }
    }
}

bool bfs(queue<pair<int,int>> q) {
    while(!q.empty()) {
        int sz = q.size();
        while(sz-- ) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (dist[i][j]!=-1 && (i==0 || i==n-1 || j==0 || j==m-1)){
                findPath(i,j);
                return true;
            } 

            for (int k=0; k<4; k++) {
                int row = dirR[k]+i, col=dirC[k]+j;
                if (row<0 || row>=n || col<0 || col>=m || mat[row][col]!='.' || dist[row][col]<1000000) continue;
                if (dist[i][j]==-1) dist[row][col]=-1;
                else dist[row][col]=1+dist[i][j];
                q.push({row,col});
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    queue<pair<int,int>> q;

    // monsters
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            dist[i][j]=1000000;
            cin >> mat[i][j];
            if (mat[i][j]=='M') {
                dist[i][j]=-1; 
                q.push({i,j});
            }
        }
    }

    // player
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat[i][j]=='A') {
                dist[i][j]=0;
                q.push({i,j});
            }
        }
    }

    if (!bfs(q)) cout << "NO";
    else {
        reverse(path.begin(), path.end());
        cout << "YES\n" << path.size();
        if (path.size()) cout << "\n" << path;
    }

    return 0;
}

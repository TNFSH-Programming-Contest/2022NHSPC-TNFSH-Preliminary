// simple search
// rr7
#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int n, m, rreq[N], creq[N], rcnt[N], ccnt[N], has_sol;
char G[N][N];

int legal(int i, int j)
{
    if (j == m && rreq[i] != rcnt[i])
        return 0;
    if (i == n && creq[j] != ccnt[j])
        return 0;
    return 1;
}

int can(int i, int j)
{
    if (G[i][j] == 'T')
        return 0;
    if (G[i+1][j]=='A'||G[i][j+1]=='A'||G[i-1][j]=='A'||G[i][j-1]=='A')
        return 0;
    if (G[i+1][j]!='T'&&G[i][j+1]!='T'&&G[i-1][j]!='T'&&G[i][j-1]!='T')
        return 0;
    return 1;
}

void dfs(int i, int j)
{
    if (has_sol) return;

    if (i==n+1 && j==1)
    {
        has_sol = 1;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                cout << G[i][j];
            }
            cout << endl;
        }
        exit(0);
    }
    else
    {
        int x = (i-1)*m+j+1, ni = (x-1)/m+1, nj = (x%m==0? m : x%m);

        if (legal(i, j)) dfs(ni, nj);
        if (can(i,j))
        {
            char tmp = 'A';
            swap(G[i][j], tmp);
            rcnt[i]++;
            ccnt[j]++;
            if (legal(i, j)) dfs(ni, nj);
            swap(G[i][j], tmp);
            rcnt[i]--;
            ccnt[j]--;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> rreq[i];
    for (int i=1; i<=m; i++) cin >> creq[i];
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            cin >> G[i][j];
        }
    }

    // dfs
    dfs(1,1);
    if (!has_sol)
    {
        cout << "QwQ\n";
    }
}
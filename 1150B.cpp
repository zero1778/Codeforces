#include <cstdio>
#include <algorithm>
#include <stack>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <cmath>

#define MAXN 100005
#define ll long long
#define ull unsigned long long
#define all(c) (c).begin(),(c).end()
#define sz(a) int((a).size())
#define pb push_back
#define io freopen("input.inp","r",stdin); //freopen("output.out","w",stdout);

using namespace std;
typedef pair <int,int> ii;
typedef pair <int,ii> iii;
int n, ans = 0,emp = 0;
int a[100][100];
int d[100][100],dem = 0 ;
int f[MAXN];
int Row[12] = {-1 , -1 ,-2 ,-2 , 1 , 1, 2, 2, 0 ,0,3 ,-3};
int Col[12] = {-2 , 2 ,-1 ,1 , -2 , 2, -1, 1, 3 ,-3,0 ,0};
bool ok[100][100];
bool Check(int x, int y)
{
    if (x < 2 || y < 2 || x > n - 1 || y > n - 1) return false;
    if (a[x + 1][y] + a[x - 1][y] + a[x][y + 1] + a[x][y - 1] != 4*a[x][y])  return false;
    if (ok[x + 1][y] || ok[x - 1][y] || ok[x][y + 1] || ok[x][y - 1])  return false;
    if (ok[x][y]) return false;
    return true;
}

void dfs1(int x, int y)
{
    int row[4] = {0 , 0 , -1, 1};
    int col[4] = {-1 , 1 , 0, 0};
    for (int i = 0 ; i < 4;i++)
    {
        int u = x + row[i];
        int v = y + col[i];
        if (u < 1 || v < 1 || u > n || v > n || (a[u][v] != 0)) continue;
        a[u][v] = emp;
        f[emp]++;
        dfs1(u,v);
    }
}

bool dfs(int x ,int y)
{
    if (x == 16 && y == 6)
    {
        int v  = 78;
    }
    if (ans == 0)
        return true;
    for (int i = 0 ; i < 12 ; i++)
    {
        int u = x + Row[i];
        int v = y + Col[i];
        if (Check(u, v))
        {
            int row[4] = {0 , 0 , -1, 1};
            int col[4] = {-1 , 1 , 0, 0};
            dem++;
            d[u][v] = dem;
            for (int k = 0 ; k < 4 ; k++) ok[u + row[k]][v + col[k]] = true;//,d[u + row[k]][v + col[k]] = dem;

            ok[u][v] = true;
            ans--;
            int t = dfs(u, v);
            if (t) return true;
            //ok[u][v] = false;
            //for (int k = 0 ; k < 4 ; k++) ok[u + row[k]][v + col[k]] = false;
        }
    }
    return false;
}

int main()
{
    io;
    cin.tie(NULL);
    cin >> n;
    for (int i = 1 ; i <= n ;i++)
        for (int j = 1 ; j <= n ;j++ )
        {
            char c;
            cin >> c;
            if (c == '#') a[i][j] = -1;
            else a[i][j] = 0;

        }

    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= n ; j++)
            if (a[i][j] == 0)
            {
                emp++;
                a[i][j] = emp;
                f[emp] = 1;
                dfs1(i,j);
                if (f[emp] % 5 != 0)
                {
                    cout << "NO";
                    exit(0);
                }
                else f[emp] /= 5;
            }
  /*  for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        if (a[i][j] == -1) cout << "."; else cout << a[i][j];
        cout << "\n";
    }*/
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= n ; j++)
            if (a[i][j] > 0 && Check(i, j))
            {
                ok[i][j] = true;
                ans = f[a[i][j]] - 1;
                int t = dfs(i,j);
                for (int i1 = 1 ; i1 <= n ; i1++)
                {
                    for (int j1 = 1 ; j1 <= n ; j1++)
                        if (d[i1][j1] == 0) cout << "."; else cout << char(d[i1][j1] + 64) ;

                    cout <<"\n";
                }
                if (!t)
                {
                    cout << "NO";
                    exit(0);
                }
            }

    cout << "YES";

	return 0;
}

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
#define io freopen("input.inp","r",stdin);

using namespace std;
typedef pair <int,int> ii;
typedef pair <int,ii> iii;
string s;
int n;
int main()
{
    io;
    cin >> s;
    cin >> n;
    string st = "";
    int tru = 0, cong = 0;
    vector <int> a,b;
    for (int i = 0 ; i < s.size() ; i++)
    {
        if (s[i] == '?') a.pb(i - 1 - tru),tru++;
        else
            if (s[i] == '*') a.pb(i - 1 - tru),b.pb( i - 1 - tru),tru++,cong++;
            else st += (char)s[i];
    }

    if ((n < st.size() - tru ) || ((n > st.size()) && (b.size() == 0))) {cout << "Impossible"; return 0;}

        if (n > st.size())
        {
            int res = n - st.size();
            int tg = 0;
            for (int i = 0 ; i < st.size() ;i++)
            {
                if ((i == b[tg]) && (tg <= res))
                {
                    for (int j = 0 ; j < res;j++) printf("%c",st[i]);
                    res = -1;
                }
                printf("%c",st[i]);
            }
        }
        else
            if (n < st.size())
            {
                int res = - n + st.size() - 1;
                int tg = 0;
                for (int i = 0 ; i < st.size() ;i++)
                {
                    if ((i == a[tg]) && (tg <= res))
                    {
                        //printf("%c",st[i]);
                        tg++;
                    }
                    else printf("%c",st[i]);
                }
            }
            else cout << st;

    return 0;
}

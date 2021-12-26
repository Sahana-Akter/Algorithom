#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> adjlist[10];//2d array vector  10 size means 10 rows vector
ll vis[10];
void DFS(ll source)
{
    if (vis[source] != -1)
        return;
    vis[source]=0;//visited
    for (int i = 0; i < adjlist[source].size(); i++)
    {
        if (vis[adjlist[source][i]] == 0)
            DFS(adjlist[source][i]);

    }
}
int main()
{
    memset(vis, -1, sizeof(vis));
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> adjlist[10];//2d array vector  10 size means 10 rows vector
ll vis[10];
void DFS(ll source)
{
    memset(vis, -1, sizeof(vis)); // -1 = unvisited
    vis[source]=0 ;// visited
    stack<ll>s;
    s.push(source);
    while(!s.empty())
    {
        ll v=s.top();
        s.pop();
        for (int i = 0; i < adjlist[v].size(); i++)
        {
            if (vis[adjlist[v][i]] == -1)
            {
                // vis[2] == -1?
                s.push(adjlist[v][i]);
               vis[adjlist[v][i]] = 0;

            }

        }
    }
}
int main()
{
    ll node,edge,x,y;
    cin>>node>>edge;
    while(edge--)
    {
        cin>>x>>y;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    DFS(1);
    /* for(int i = 1; i <= node; i++)
     {
         cout << i << " -> ";
         for(int j = 0; j < adjlist[i].size(); j++)
         {
             cout << adjlist[i][j] << " ";
         }
         cout << endl;
     } */
}



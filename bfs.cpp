#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> adjlist[10];//2d array vector  10 size means 10 rows vector
ll vis[10];
void BFS(ll source)
{
    memset(vis, -1, sizeof(vis)); // -1 = unvisited
    vis[source]=0 ;// visited
                queue<ll>q;
    q.push(source);
    while(!q.empty())
    {
        ll v=q.front();
        q.pop();
        for (int i = 0; i < adjlist[v].size(); i++)
        {
            if (vis[adjlist[v][i]] == -1)
            {
                // vis[2] == -1?
                q.push(adjlist[v][i]);
               // vis[adjlist[v][i]] = 0;
                vis[adjlist[v][i]] =vis[v]+1;//=0+1;// shortest part
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
    BFS(1);
    ll n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<"Shortest path from 1 is "<<vis[n]<<endl;
    }
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


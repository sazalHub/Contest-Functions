#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,vector<ll> >graph;
ll E,x,y,nodes;
map<ll,bool>vis;
map<ll,ll>level;
map<ll,bool>nds;

ll BFS()
{
    ll u,v,len;
    queue<ll>Q;
    Q.push(x);
    level[x]=0;
    vis[x]=true;
    ll sum = 0;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        len = graph[u].size();
        for (ll i=0;i<len;i++)
        {
            v = graph[u][i];
            if (!vis[v] && (level[u]+1)<=y)
            {
                sum++;
                vis[v] = true;
                level[v] = level[u] + 1;
                Q.push(v);
            }
        }
    }
    return sum+1;
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll caseno = 0;
    while(scanf("%lld",&E)==1 && E!=0)
    {
        graph.clear();
        nds.clear();
        nodes = 0;
        for (int i=0;i<E;i++)
        {
            scanf("%lld%lld",&x,&y);
            if (!nds[x])
                nds[x]=true,nodes++;
            if (!nds[y])
                nds[y]=true,nodes++;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        while(scanf("%lld%lld",&x,&y)==2 && x+y!=0)
        {
            vis.clear();
            level.clear();
            ll ans = BFS();
            ///cout<<ans<<" "<<nodes<<endl;
            printf("Case %lld: %lld nodes not reachable from node %lld with TTL = %lld.\n",++caseno,nodes-ans,x,y);
        }
    }
    return 0;
}

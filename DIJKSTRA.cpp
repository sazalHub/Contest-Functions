#include<bits/stdc++.h>
#define ll long long
#define MAX 999999999999
using namespace std;
ll V,E,u,v,cost,len,parent[100005],dist[100005];

struct NODE{
    ll node,cost;
}nodes,Nodes;
map<ll,vector<NODE> >graph;

bool operator<(NODE a,NODE b)
{
    return (a.cost>b.cost);
}

void DIJKSTRA()
{
    for (ll i=1;i<=V;i++)
        dist[i] = MAX,parent[i]=i;
    priority_queue<NODE>Q;
    nodes.node = 1;
    nodes.cost = 0;
    dist[1] = 0;
    Q.push(nodes);
    while(!Q.empty())
    {
        nodes = Q.top();
        if (nodes.node==V) return;
        Q.pop();
        len = graph[nodes.node].size();
        for (ll i=0;i<len;i++)
        {
            Nodes = graph[nodes.node][i];
            if (dist[nodes.node]+Nodes.cost<dist[Nodes.node])
            {
                dist[Nodes.node] = dist[nodes.node]+Nodes.cost;
                Nodes.cost = dist[Nodes.node];
                parent[Nodes.node] = nodes.node;
                Q.push(Nodes);
            }
        }
    }
}

int main ()
{
    while(scanf("%lld%lld",&V,&E)==2)
    {
        graph.clear();
        for (ll i=0;i<E;i++)
        {
            scanf("%lld%lld%lld",&u,&v,&cost);
            nodes.node = v;
            nodes.cost = cost;
            graph[u].push_back(nodes);
            nodes.node = u;
            graph[v].push_back(nodes);
        }
        DIJKSTRA();
        if (dist[V]==MAX)
            printf("-1\n");
        else
        {
            vector<ll>ans;
            ll temp = V;
            while(parent[temp]!=temp)
                ans.push_back(temp),temp = parent[temp];
            ans.push_back(1);
            len = ans.size();
            for (ll i=len-1;i>=0;i--)
            {
                printf("%lld",ans[i]);
                if (i>=1)
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}

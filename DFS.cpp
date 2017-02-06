#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,vector<ll> >graph;
bool visited[100010];

void DFS(ll idx)
{
    visited[idx] = true;
    ll len = graph[idx].size();
    for (ll i=0;i<len;i++)
    {
        ll v = graph[idx][i];
        if (!visited[v])
            DFS(v);
    }
}

int main ()
{
    ll V,E;
    scanf("%lld%lld",&V,&E);
    for (ll i=0;i<E;i++)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    memset(visited,false,sizeof(visited));
    for (ll i=1;i<=V;i++)
        if (!visited[i])
            DFS(i);
    return 0;
}

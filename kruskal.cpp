#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
    ll from,to,weight;
}edges[100005];
ll N,parent[100005],E;

ll find_root(ll r)
{
    if (parent[r]==r)
        return r;
    return parent[r] = find_root(parent[r]);
}

bool cmp(node a,node b)
{
    return (a.weight<b.weight);
}

ll KRUSKAL()
{
    sort(edges,edges+E,cmp);
    ///for (ll i=0;i<E;i++)
        ///cout<<edges[i].weight<<" "<<edges[i].from<<" "<<edges[i].to<<endl;
    for (ll i=1;i<=N;i++)
        parent[i] = i;
    ll ans = 0;
    ///cout<<"start"<<endl;
    for (ll i=0;i<E;i++)
    {
        ll fromr = find_root(edges[i].from);
        ll tor = find_root(edges[i].to);
        if (fromr!=tor)
        {
            ///parent[fromr]=parent[tor];
            parent[parent[edges[i].from]]=parent[parent[edges[i].to]];
            ans+=edges[i].weight;
        }
    }
    return ans;
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    freopen("edges.txt","r",stdin);
    while(cin>>N>>E)
    {
        for (ll i=0;i<E;i++)
            cin>>edges[i].from>>edges[i].to>>edges[i].weight;
        ll ans = KRUSKAL();
        cout<<ans<<endl;
    }
    return 0;
}

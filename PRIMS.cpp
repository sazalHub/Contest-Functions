#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
    ll to,weight;
};

ll N,E,cost[100005];
bool visited[100005];
map<ll,vector<node> >nodes;
priority_queue<node>PQ;

bool operator<(node a, node b)
{
    return a.weight>b.weight;
}

ll PRIMS()
{
    for (ll i=1;i<=N;i++)
        cost[i]=INT_MAX,visited[i]=0;
    cost[1] = 0;
    node nn;
    nn.to = 1,nn.weight=0;
    PQ.push(nn);
    ll ans = 0;
    while(!PQ.empty())
    {
        node tmp = PQ.top();
        PQ.pop();
        if (visited[tmp.to]==1)
            continue;
        visited[tmp.to]=1;
        ans+=tmp.weight;
        for (ll i=0;i<nodes[tmp.to].size();i++)
        {
            node tm = nodes[tmp.to][i];
            if (visited[tm.to]==1)
                continue;
            if (tm.weight<cost[tm.to])
            {
                nn.to = tm.to,nn.weight = tm.weight;
                PQ.push(nn);
                cost[tm.to] = tm.weight;
            }
        }
    }
    return ans;
}

int main ()
{
    freopen("edges.txt","r",stdin);
    ll x,y,w;
    node nd;
    while(cin>>N>>E)
    {
        ///cout<<N<<" "<<E<<endl;
        for (ll i=0;i<E;i++)
        {
            cin>>x>>y>>w;
            nd.to = y,nd.weight = w;
            nodes[x].push_back(nd);
            nd.to = x;
            nodes[y].push_back(nd);
        }

        ll ans = PRIMS();
        cout<<ans<<endl;
    }
    return 0;
}

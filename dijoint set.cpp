#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll parent[100],Rank[100];

ll find_root(ll r)
{
    return parent[r]==r ? r:parent[r] = find_root(parent[r]);
}

void Union(ll i,ll j)
{
    ll iroot = find_root(i);
    ll jroot = find_root(j);
    if (iroot==jroot)
        return;
    if (Rank[iroot]<Rank[jroot])
        parent[iroot] = jroot;
    else
    {
        parent[jroot] = iroot;
        Rank[iroot]++;
    }
}

int main ()
{
    memset(Rank,0,sizeof(Rank));
    for (ll i=0;i<11;i++)
        parent[i] = i;
    Union(0,1);
    Union(2,5);
    Union(3,5);
    Union(9,6);
    Union(1,6);
    Union(10,7);
    Union(8,7);
    ll i,j;
    while(cin>>i>>j)
    {
        if (find_root(i)==find_root(j))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool vis[10000005];
ll len;
vector<ll>primes;
void PrimeGenerator()
{
    primes.push_back(2);
    for (ll i=3;i<=4000;i+=2)
    {
        if (!vis[i])
        {
            primes.push_back(i);
            for (ll j=i*i;j<=4000;j+=2*i)
                vis[j] = true;
        }
    }
    len = primes.size();
    ///cout<<primes[len-1]<<endl;
}

int main ()
{
    PrimeGenerator();
    ll cases,N,esum,osum,div;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld",&N);
        if (N==0)
        {
            printf("0\n");
            continue;
        }
        esum = 1,osum = 1;
        ll tmp = N;
        for (ll i=0;tmp!=1 && primes[i]*primes[i]<=tmp;i++)
        {
            ll cnt = 0;
            while(tmp%primes[i]==0)
            {
                cnt++;
                tmp/=primes[i];
            }
            if (cnt>0)
            {
                ll tesum = 1,tosum = 1,t;
                ll st = 1;
                if (primes[i]==2)
                    tesum=0;
                t = primes[i];
                for (;st<=cnt;st++)
                    tesum+=t,tosum+=t,t*=primes[i];
                esum*=tesum;
                if (primes[i]!=2)
                    osum*=tosum;
            }
        }
        if (tmp>1)
        {
            if (tmp==2)
                esum*=2;
            else
                esum*=(1+tmp);
            if (tmp!=2)
                osum*=(1+tmp);
        }
        if (N%2==1)
            esum = 0;
        printf("%lld %lld\n",esum,osum);
    }
    return 0;
}



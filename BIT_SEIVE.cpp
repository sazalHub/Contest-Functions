#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX 100000100
ll a[MAX/64+100];
ll primes[5761558],len;

void Bit_Seive()
{
    ll lmt = sqrt(MAX);
	for (ll i=3;i<=lmt;i+= 2)
    {
		if(!(a[i/64]&(1LL<<(i%64))))
		{
			for(ll j=i*i;j<MAX;j+=2*i)
				a[j/64] |= (1LL<<(j%64));
		}
	}

	primes[(len=0)++] = 2;
	for (ll i = 3; i <= MAX; i += 2)
		if(!(a[i/64] & (1LL<<(i%64))))
			primes[len++] = i;
	for (ll i=0;i<10;i++)
        cout<<primes[i]<<endl;
}

int main ()
{
    Bit_Seive();
}

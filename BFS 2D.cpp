#include<bits/stdc++.h>
#define ii int
using namespace std;
ii fx[8] = {-2,-1,1,2,2,1,-1,-2};
ii fy[8] = {1,2,2,1,-1,-2,-2,-1};
ii lr,lc,dr,dc;
bool visited[9][9];
ii level[9][9];
char str1[5],str2[5];

void BFS()
{
    queue<ii>Q;
    Q.push(lc),Q.push(lr);
    visited[lr][lc] = true;
    level[lr][lc] = 0;
    while(!Q.empty())
    {
        ii c = Q.front();
        Q.pop();
        ii r = Q.front();
        Q.pop();
        ///cout<<r<<" "<<c<<endl;
        for (ii i=0;i<8;i++)
        {
            ii tx = r + fx[i];
            ii ty = c + fy[i];
            if ((tx>0 && tx<9) && (ty>0 && ty<9) && !visited[tx][ty])
            {
                visited[tx][ty] = true;
                level[tx][ty] = level[r][c] + 1;
                Q.push(ty),Q.push(tx);
            }
        }
    }
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ///getchar();
    map<char,ii>save;
    save['a']=1,save['b']=2,save['c']=3,save['d']=4;
    save['e']=5,save['f']=6,save['g']=7,save['h']=8;

    while(scanf("%s%s",&str1,&str2)==2)
    {
        ///getchar();
        ///cout<<str1<<" "<<str2<<endl;
        lr = str1[1] - 48,lc = save[str1[0]];
        dr = str2[1] - 48,dc = save[str2[0]];
        ///cout<<lr<<" "<<lc<<endl;
        ///cout<<dr<<" "<<dc<<endl;
        memset(visited,false,sizeof(visited));
        ///memset(level,0,sizeof(level));
        BFS();
        printf("To get from %s to %s takes %d knight moves.\n",str1,str2,level[dr][dc]);
    }
    return 0;
}

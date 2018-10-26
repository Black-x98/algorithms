#include<cmath>
#include<cctype>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<iterator>
#include<iostream>
#include<algorithm>


using namespace std;

int K[30001][301];

int val[305], wt[305];

int maximum(int a,int b)
{
    return (a>b)? a:b;
}


int knapSack(int W,int n)
{

    if(n==0||W==0)
    {
        return 0;
    }

    if(K[W][n]!=-1)
    {
        return K[W][n];
    }

    int s1=-1,s2=-1;

    s2=knapSack(W,n-1);

    if(wt[n]<=W)
    {
        s1=knapSack(W-wt[n],n-1)+val[n];

    }

    return  K[W][n] = maximum(s1,s2);
}


main()
{
    int t,n,W,i,j;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&W);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&wt[i]);
        }
        for(i=1; i<=n; i++)
        {
            scanf("%d",&val[i]);
        }

        memset(K,-1,sizeof(K));

        printf("%d\n",knapSack(W,n));
    }

    return 0;
}

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

long long K[305][30005];

int maximum(int a,int b)
{
    return (a>b)? a:b;
}

long long knapSack(int W,int wt[],int val[],int n)
{
    //printf("Recursing with %d items and %d more capacity left\n",n,W);

    if(n==0||W==0)
    {
        //printf("1st condition\n");
        return 0;
    }

    if(K[n][W]!=-1){
        //printf("2nd condition\n");
        return K[n][W];
    }



    else if(wt[n]>W)
    {
        //printf("3rd condition\n");
        return K[n][W]=knapSack(W,wt,val,n-1);
    }

    else
    {
        //printf("4th condition\n");
        //printf("testing for %d-th item weighted %d\n",n,wt[n]);
        return K[n][W]=maximum(knapSack(W,wt,val,n-1),knapSack(W-wt[n],wt,val,n-1)+val[n]);
    }

}

main()
{
    int t,n,W,i,j;
    int val[305], wt[305];
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

        printf("%lld\n",knapSack(W,wt,val,n));
    }

    return 0;
}

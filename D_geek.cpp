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

#define inf 400005

int K[30001][301];

bool flag;

int val[305], wt[305];

int minimum(int a,int b)
{
    return (a<b)? a:b;
}


int coin_change(int A,int n,int taken[],int cnt){
    if(flag==true){
        K[A][n]=cnt;
        return cnt;
    }

    int s1=inf, s2=inf;

    if(A<=0||n==0){
        flag=true;
        K[A][n]=cnt;
        return cnt;
    }

    if(K[A][n]!=-1){
        K[A][n]=cnt;
        return cnt;
    }

    if(val[n]<=A&&taken[n]==false){
        taken[n]=true;
        s1=coin_change(A-val[n],n-1,taken,cnt+1);
        cnt=s1;
    }

    else{
        s2=coin_change(A,n-1,taken,cnt);
        cnt=s2;
    }

    K[A][n]=cnt;

    return cnt;
}


main()
{
    int t,n,A,i,j;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&A);

        for(i=1; i<=n; i++)
        {
            scanf("%d",&val[i]);
        }

        memset(K,-1,sizeof(K));

        int taken[n+1];

        memset(taken,false,sizeof(taken));

        flag=false;

        printf("%d\n",coin_change(A,n,taken,0));
    }

    return 0;
}

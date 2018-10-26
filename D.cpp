#include<cmath>
#include<cctype>
#include<cstdio>
#include<string.h>
#include<cstdlib>
#include<iostream>
#include<algorithm>


using namespace std;

#define inf 400005

int K[30001][301];

int number=0;

int flag=0;

int val[305], wt[305];


int coin_change(int A,int n,int cnt){
    printf("count == %d\nAmount left %d\nscanning coin %d\n",cnt,A,n);
    if(flag==1){
        return cnt;
    }

    int s1=inf, s2=inf;

    if(A<=0||n==number){
        flag=1;
        return cnt;
    }

    if(A>=val[n]){
        s1=coin_change(A-val[n],n+1,cnt+1);
    }
    printf("\nSWITCHING BRANCHES!!!!\n");
    s2=coin_change(A,n+1,cnt);

    return K[A][n]=min(s1,s2);

}


main()
{
    int t,n,A,i,j;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&A);

        number=n;

        for(i=1; i<=n; i++)
        {
            scanf("%d",&val[i]);
        }


        flag=0;

        printf("%d\n",coin_change(A,1,0));
    }

    return 0;
}

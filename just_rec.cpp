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

int val[305], wt[305];

int minimum(int a,int b)
{
    return (a<b)? a:b;
}


int rec(int cnt){
    printf("Recurring on %d\n",cnt);

    if(cnt==100){
        return cnt;
    }

    rec(cnt+1);
}


main()
{
    int t,n,A,i,j;

    scanf("%d",&t);

    printf("%d\n",rec(t));


    return 0;
}


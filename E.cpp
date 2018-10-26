
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



int maximum(int a,int b){
    return (a>b)? a:b;
}

long long knapSack(int W,int wt[],int val[],int n)
{
   int i,w;
   long long K[n+1][W+1];
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = maximum(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}

main(){
    int t,n,W,i,j;
    int val[305], wt[305];
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&W);
        for(i=0;i<n;i++){
            scanf("%d",&wt[i]);
        }
        for(i=0;i<n;i++){
            scanf("%d",&val[i]);
        }
        printf("%lld\n",knapSack(W,wt,val,n));
    }

    return 0;
}



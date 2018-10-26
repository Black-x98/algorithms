#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdlib.h>

using namespace std;

int matrix[300][30000]={0};


int maximum(int x,int y){
    return (x>y)?x:y;
}


int knapsack(int W,int wt[],int val[],int n){
    if(W==0||n==0){
        return 0;
    }
    int take=0,dontTake=0;
    if(matrix[n][W]!=0){
        return matrix[n][W];
    }
    if(n==0){
        if(wt[0]<=W){
            matrix[n][W] = val[0];
            return val[0];
        }
        else{
            matrix[n][W] = 0;
            return 0;
        }
    }

    if(wt[n]<=W){
        take = val[n] + knapsack(W-wt[n],wt,val,n-1);
    }

    dontTake=knapsack(W,wt,val,n-1);

    matrix[n][W]=maximum(take,dontTake);

    return matrix[n][W];
}

main(){
    int t,n,W,i,j;
    int val[300], wt[300];
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&W);
        for(i=0;i<n;i++){
            scanf("%d",&wt[i]);
        }
        for(i=0;i<n;i++){
            scanf("%d",&val[i]);
        }
        printf("%d\n",knapsack(W,wt,val,n));
        for(i=0;i<n;i++){
            for(j=0;j<W;j++){
                matrix[i][j]=0;
            }
        }
    }

    return 0;
}


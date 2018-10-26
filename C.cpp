#include <stdio.h>

using namespace std;

int arr[300][300];


int max(int x,int y){

    if(x>y){
        return x;
    }
    else{
        return y;
    }
}

int maxCost(int cost[][300],int N,int M){
    int i,j;
    int tc[N+1][M+1];
    tc[0][0]=cost[0][0];

    for(i=1;i<=N;i++){
        tc[i][0] = tc[i-1][0] + cost[i][0];
    }

    for(j=1;j<=M;j++){
        tc[0][j] = tc[0][j-1] + cost[0][j];
    }

    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            tc[i][j]=max(tc[i-1][j],tc[i][j-1]) + cost[i][j];
        }
    }
    return tc[N-1][M-1];
}



int main(){
   int T,M,N,i,j,k;
   int cost=0;
   scanf("%d",&T);
   while(T--){
       scanf("%d %d",&N,&M);
       for(i=0;i<N;i++){
           for(j=0;j<M;j++){
                scanf("%d",&arr[i][j]);
           }
       }
       cost=maxCost(arr,N,M);
       printf("%d\n",cost);
   }
   return 0;

}

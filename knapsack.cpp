
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


#define inf (1<<29)
#define ii64 long long
#define MX 33


ii64 dp[MX];
int visited[MX];

int maximum(int a,int b){
    return (a>b)? a:b;
}

int knapSack(int W,int wt[],int val[],int n){
    int i,w;
    int K[n+1][W+1];

    for(i=0;i<=n;i++){
        for(w=0;w<=W;w++){
            if(i==0||w==0){
                K[i][w]=0;
            }
            else if(wt[i-1]<=w){
                K[i][w]=maximum(val[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]);
            }
            else{
                K[i][w]=K[i-1][w];
            }
        }
    }

    return K[n][W];
}


main(){
    int t,n;
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int W = 50;
    n = sizeof(val)/sizeof(val[0]);
    printf("%d",knapSack(W,wt,val,n));
    return 0;
}


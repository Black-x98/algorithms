#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int maximum(long long int a, long long int b){ return (a>b)?a:b; }

long long int knapSack(int S,int N, long long int weight[], long long int value[]){
    int i,w;
    long long int K[N+1][S+1];
    for(i=0;i<=N;i++){
        for(w=0;w<=S;w++){
            if(i==0||w==0){
                K[i][w]=0;
            }
            else if(weight[i-1]<=w){
                K[i][w] = maximum(value[i-1]+K[i-1][w-weight[i-1]],K[i-1][w]);
            }
            else{
                K[i][w]=K[i-1][w];
            }
        }
    }
    return K[N][S];
}


int main() {

    int S,N,K,i,t;
    cin>>t;
    while(t--){
        cin>>N>>K;
        long long int weight[N+1], value[N+1], res;
        for(i=0;i<N;i++){
            cin>>weight[i];
        }
        for(i=0;i<N;i++){
            cin>>value[i];
        }
        res=knapSack(S,N,weight,value);
        printf("%lld\n",res);
    }

	return 0;
}


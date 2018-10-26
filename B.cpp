#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<iterator>
#include<iostream>
#include<algorithm>
#include<cassert>
#include<ctime>

using namespace std;


#define inf (1<<29)
#define ii64 long long
#define MX 33


ii64 dp[MX][2];
int visited[MX][2];

ii64 DP_func(int n,int pre_tile){
    if(n==0) return 1;

    if(visited[n][pre_tile]==1) return dp[n][pre_tile];


    ii64 result=0;

    if(pre_tile==false){
        result+=DP_func(n-1,true);
    }
    result+=DP_func(n-1,false);
    result+=DP_func(n-1,false);

    visited[n][pre_tile]=1;
    return dp[n][pre_tile] = result;

}


main(){
    int t,n;
    ii64 result;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(visited,0,sizeof(visited));
        result=DP_func(n,false);
        printf("%lld\n",result);
    }
    return 0;
}


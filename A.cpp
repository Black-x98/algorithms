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


ii64 dp[MX];
int visited[MX];

ii64 DP_func(int n){
    if(n==0) return 1;

    if(visited[n]==1) return dp[n];

    visited[n]=1;

    ii64 result=0;

    result+=DP_func(n-1);
    result+=DP_func(n-1);
    result+=DP_func(n-1);

    return dp[n] = result;

}


main(){
    int t,n;
    ii64 result;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(visited,0,sizeof(visited));
        result=DP_func(n);
        printf("%lld\n",result);
    }
    return 0;
}

#include<cmath>
#include<cctype>
#include<cstdio>
#include<string.h>
#include<cstdlib>
#include<iostream>
#include<algorithm>


using namespace std;

#define INT_MAX 400005

int K[30001][301];

int number=0;

int flag=0;

int coins[305], wt[305];


int minCoins( int m, int V)
{
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result
    int table[V+1];

    // Base case (If given value V is 0)
    table[0] = 0;

    // Initialize all table values as Infinite
    for (int i=1; i<=V; i++)
        table[i] = INT_MAX;

    // Compute minimum coins required for all
    // values from 1 to V
    for (int i=1; i<=V; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<m; j++)
          if (coins[j] <= i)
          {
              int sub_res = table[i-coins[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }
    return table[V];
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
            scanf("%d",&coins[i]);
        }


        flag=0;

        printf("%d\n",coin_change(A,1,0));
    }

    return 0;
}

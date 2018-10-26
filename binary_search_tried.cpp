#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


bool BS(int arr[], int s, int e, int target){
    int i,j,k;
    bool exist;
    int m;
    if(e-s<1){
        return false;
    }
    m=(s+e)/2;
    if(target==arr[m]){
        return true;
    }
    else if(target<arr[m]){
        exist=BS(arr,s,m,target);
        if(exist==true){
            return true;
        }
    }
    else if(target>arr[m]){
        exist=BS(arr,m+1,e,target);
        if(exist==true){
            return true;
        }
    }

}

int main(){
    int i,j,k;

    int arr[] = {1,2,3,5,6,7,8,9,10,11,12,14,15,17,19,21,22,33,41};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is:\n");
    for(i=0;i<arr_size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    int target=-1;

    printf("Enter the target value:\n");
    scanf("%d",&target);

    bool exist = false;
    exist = BS(arr,0,arr_size-1,target);

    if(exist==true){
        printf("Found\n");
    }
    else{
        printf("Not found\n");
    }
    return 0;
}


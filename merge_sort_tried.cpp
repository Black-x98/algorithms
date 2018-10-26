#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


void merge(int arr[], int l, int m, int r){
    int i,j,k;
    int size_l = m-l+1;
    int size_r = r-m;

    int Left[size_l], Right[size_r];

    for(i=0;i<size_l;i++){
        Left[i] = arr[l+i];
    }
    for(j=0;j<size_r;j++){
        Right[j] = arr[m+1+j];
    }

    i=0;
    j=0;
    k=l;

    while(i<size_l && j<size_r){
        if(Left[i]<Right[j]){
            arr[k++]=Left[i++];
        }
        else{
            arr[k++]=Right[j++];
        }
    }

    while(i<size_l){
        arr[k++]=Left[i++];
    }

    while(j<size_r){
        arr[k++]=Right[j++];
    }

}


void merge_sort(int arr[], int l, int r){
    if(l<r){
        int m = l+ (r-l)/2;

        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}
int main(){
    int i,j,k;

    int arr[] = {12,11,13,5,6,7,66,5,2,11,2,44,7,90,9,12,16,11};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is:\n");
    for(i=0;i<arr_size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    merge_sort(arr,0,arr_size-1);

    printf("Sorted array is:\n");
    for(i=0;i<arr_size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

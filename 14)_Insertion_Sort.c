#include<stdio.h>

void insertionsort(int arr[], int size){
    int i,j,key;
    for(i=1;i<=(size-1);i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void printarray(int arr[], int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d, ",arr[i]);
    }
}

int main(){
    int size;
    printf("Enter size: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter Array: ");
    for(int i=0;i<size;i++){
        scanf("%d, ",&arr[i]);
    }
    insertionsort(arr,size);
    printarray(arr,size);
}


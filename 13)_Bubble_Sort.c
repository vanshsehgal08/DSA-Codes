#include<stdio.h>


int swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;   
}

void bubblesort(int arr[],int size){
    for(int i=0;i<size-1;i++){ //For number of passes
        for(int j=0;j<size-i-1;j++){ //For number of comparisons
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
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
    bubblesort(arr,size);
    printarray(arr,size);
}




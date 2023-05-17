#include<stdio.h>

int swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;   
}

void selectionsort(int arr[],int size){
    int i,j,minindex,temp;
    for(i=0;i<size-1;i++){
        minindex=i;
        for(j=i+1;j<=(size-1);j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        swap(&arr[minindex],&arr[i]);
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
    selectionsort(arr,size);
    printarray(arr,size);

}
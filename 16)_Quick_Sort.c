#include <stdio.h>

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;   
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do{
        while (A[i] <= pivot){
            i++;
        }
        while (A[j] > pivot){
            j--;
        }
        if (i < j)
            swap(&A[i],&A[j]);
    } while (i < j);

    // Swap A[low] and A[j]
    swap(&A[low],&A[j]);
    return j;
}

void quickSort(int A[], int low, int high){
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high); 
        quickSort(A, low, partitionIndex - 1);  // sort left subarray 
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    int size;
    printf("Enter size: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter Array: ");
    for(int i=0;i<size;i++){
        scanf("%d, ",&arr[i]);
    }    
    quickSort(arr, 0, size - 1);
    printArray(arr, size);
    return 0;
}

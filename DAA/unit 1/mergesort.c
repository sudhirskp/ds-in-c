#include<stdio.h>
#include<stdlib.h>
void Merge(int A[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1], R[n2 + 1];
    for(int i = 0; i < n1; i++){
        L[i] = A[p + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = A[q + j + 1];
    }
    int i=0;
    int j=0;
    int k=p;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        A[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        A[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int A[], int p, int r){
    if(p < r){
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

int main(){

    int A[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(A) / sizeof(A[0]);
    MergeSort(A, 0, n - 1);
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
}
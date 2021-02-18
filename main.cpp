#include <iostream>
#include <bits/stdc++.h> 
#include <stdlib.h>     /* srand, rand */
#include <math.h>       /* pow */
#include <chrono>
using namespace std; 
using namespace std::chrono;


  
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
} 

int main()  {
    
    int n = 1000, x; 
    int arr[n];
    for (int i = 0; i < n; i++) { 
        x = rand() % 20; 
        arr[i] = pow(2,x);
    } 

    //cout<<"Arreglo original: ";
    //printArray(arr,n);
    //cout << endl;
    
    //sort por inserción
    cout<<"InsertionSort: "; 
    auto start = high_resolution_clock::now(); 
    insertionSort(arr, n); 
    auto stop = high_resolution_clock::now(); 
    //printArray(arr, n);
    auto duration = duration_cast<nanoseconds>(stop - start); 
    cout << "Time taken by function: "
         << duration.count() << " nanoseconds" << endl;

    //sort por intercalación
    cout<<"MargeSort: "; 
    start = high_resolution_clock::now();
    mergeSort(arr,0,n-1); 
    stop = high_resolution_clock::now(); 
    //printArray(arr, n);
    duration = duration_cast<nanoseconds>(stop - start); 
    cout << "Time taken by function: "
         << duration.count() << " nanoseconds" << endl;
  

  
    return 0;  
} 

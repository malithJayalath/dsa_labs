#include <iostream>
#include <bits/stdc++.h>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
  int maximum = root;
  int lft = 2*root + 1;
  int rgt = 2*root + 2;

  if(lft < n && arr[lft] > arr[maximum]){
      maximum = lft;
  }
  if(rgt < n && arr[rgt] > arr[maximum]){
   maximum = rgt;
  }
  if (maximum != root) {
        swap(arr[root], arr[maximum]);
        heapify(arr, n, maximum);
  }
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
  
   // extracting elements from heap one by one
   for (int i=n-1; i>=0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   clock_t time_req;
   int heap_arr[] = {4,17,3,12,9,6, 6, 90, 2, 8, 23, 31, 87};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   time_req = clock();
   heapSort(heap_arr, n);
   time_req = clock() - time_req;
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);

   cout << "Time taken is : " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
}

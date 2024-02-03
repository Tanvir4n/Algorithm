void selection_sort(vector<int>&arr){
    
    int n=arr.size();
    int swaps=0;
    
    for(int i=0; i<n-1; i++){                   // Find the minimum element in the unsorted part of the array
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);            // Swap the found minimum element with the first element of the unsorted part
        swaps++;
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Number of swaps needed: "<<swaps<<endl;
}

/*

time complexity 

Best-case: O(n2), best case occurs when the array is already sorted. (where n is the number of integers in an array)

Average-case: O(n2), the average case arises when the elements of the array are in a disordered or random order, without a clear ascending or descending pattern.

Worst-case: O(n2), The worst-case scenario arises when we need to sort an array in ascending order, but the array is initially in descending order.

Space Complexity: O(1), as no extra space is required for the Selection sort algorithm
*/
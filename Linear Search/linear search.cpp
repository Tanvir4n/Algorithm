int linear_search(int n, int arr[], int target){
    for(int i=0; i<n; i++){
        if(arr[i] == target){
            return i;                               // Return the index if target is found
        }
    }
    return -1;                                      // Return -1 if target is not found
}


/*
Time Complexity
Best Case: O(1)
y
|
|__________
|          x

Worst Case: O(n); here n is the length of the array
y
|
|   /
|  /
| /
|/
--------- x

If the array is sorted, consider using binary search for a 
more efficient search with a time complexity of O(log n).
y
|
|     
|    
|   ___
|  /   ----
| /
|/
-----------x

*/

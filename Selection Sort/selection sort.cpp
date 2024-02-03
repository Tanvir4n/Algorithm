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

time complexity O(n^2)

*/
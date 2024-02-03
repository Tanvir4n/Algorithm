void bubble_sort(int n, int arr[]){
int swaps=0;
for(int i=0; i<n-1; i++){
    for(int j=0; j<n-i-1; j++){
        if(arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]);
                swaps++;                //number of swaps needed to sort the array
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<swaps<<endl;
}

/*

time complexity

The best time complexity of bubble sort is O(n), and this occurs when the array is already sorted.

average/worst time complexity is O(n²)


*/

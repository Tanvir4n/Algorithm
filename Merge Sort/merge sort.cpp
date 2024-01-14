void merge(vector<int>& arr, int left, int mid, int right){

    int i=left;
    int j=mid+1;
    int k=left;

    while(i<=mid && j<=right){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            j++;
            k++;
        }
        
    }
}

void merge_sort(vector<int>& arr, int left, int right){
    if(left < right){
        // Same as (left + right) / 2, but avoids overflow for large left and right
        int mid=left+(right-left) / 2;

        // Sort first and second halves
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

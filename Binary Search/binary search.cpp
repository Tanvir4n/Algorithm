int binary_search(int n, int target, int arr[]){
    int left = 0;
    int right = arr.size() - 1;                            //-1 to access the last element where index started from 0

    while(left <= right){
        int mid = (left + right) / 2;

        // Check if the target is present at the middle
        if(arr[mid] == target){
            return mid;
        }

        // If target is greater, ignore the left half
        if(arr[mid] < target){
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else{
            right = mid - 1;
        }
    }

    // If we reach here, then the element was not present
    return -1;
}

/*

Best case = O(1)
y
|
|__________
|          x
Worst case = O(logn)
Average case = O(logn)
y
|
|     
|     ____
|   /     ----
|  /          
| /
|/
------------------x

*/

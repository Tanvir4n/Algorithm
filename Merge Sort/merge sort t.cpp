#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right){
    vector<int> temp(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= right){
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(k = 0; k < temp.size(); k++){
        arr[left + k] = temp[k];
    }
}

void merge_sort(vector<int>& arr, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main(){
    
    int t;
    cin>>t;
    vector<int>arr(t);
    
    cout<<"Enter array elements: ";
    for(int i=0; i<t; i++){
        cin>>arr[i];
    }

    cout << "Given array is \n";
    for(int i = 0; i < t; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Perform merge sort
    merge_sort(arr, 0, t - 1);

    cout << "Sorted array is \n";
    for(int i = 0; i < t; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

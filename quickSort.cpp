#include<iostream>
#include <vector>
using namespace std;

int partition(int arr[], int st, int end){

    int idx = st-1; int pivot = arr[end];

    for(int j=st; j<end; j++){
        if(arr[j] < pivot){
            idx++;
            swap(arr[idx], arr[j]);
        }
    }

    idx++;
    swap(arr[idx], arr[end]);
    return idx;

}

void quicksort(int arr[], int st, int end){

    if(st<end){
        int pvtidx = partition(arr, st, end);
        quicksort(arr, st, pvtidx-1);
        quicksort(arr, pvtidx+1, end);
    }
}

int main(){

    int n;
    cout <<"Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    quicksort(arr.data(), 0, n-1);

    cout<<"Sorted Elements are: "<<endl;
    for(int i=0; i<n; i++){
        cout << arr[i]<<" ";
    }
    return 0;

}
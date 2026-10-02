#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int st, int mid, int end){

    int i = st; int j = mid +1;
    vector<int>temp;

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
        temp.push_back(arr[i]);
        i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    
    for(int idx=0; idx<temp.size(); idx++){
        arr[idx+st] = temp[idx];
    }

}

void mergesort(int arr[], int st, int end){

    if(st<end){
        int mid = st+(end-st)/2;
        mergesort(arr, st, mid);//left half
        mergesort(arr, mid+1, end);//right half

        merge(arr, st, mid, end);
    }
}

int main(){
    int n;
    cout << "Enter the size of Array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter Elelments :"<< endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    mergesort(arr.data(), 0, n-1);

    cout <<"Elements are: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;

}
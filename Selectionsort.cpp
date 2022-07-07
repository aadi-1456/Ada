#include<iostream>
using namespace std;

void selectionsort(int *a,int n){
    int temp;
    for(i=0;i<n-1;i++){
        int min=a[i];
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
                min=j;
            }
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    selectionsort(a,n);
    cout<<"Sorted array\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}


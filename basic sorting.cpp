#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//6,2,3,2,11
//1)2,6,
//2)2,3,6
//3)2,3,2,6
//4)2,3,2,6,11

//
//2,2,3,5
void bsort(vector<int>&arr,int n){
    int c=0;
    for(int i=0;i<n-1;i++){
        bool f=0;
        
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                f=1;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                //swap(arr[j],arr[j+1]);
            }
        }
        if(f==0){
            break;
        }
        c++;
    }
    cout<<c<<endl;
}

//insertion sort
//2,6,3,2,11
//2,6,6,2,11
//2,6,6,2,11
//2,3,6,2,11
void isort(vector<int>&arr,int n){
    int ct=0;
   for(int i=1;i<n;i++){
     int key=arr[i];
     int j=i-1;
     while(j>=0 && arr[j]>=key){
         arr[j+1]=arr[j];
         j--;
     }
     arr[j+1]=key;
     ct++;
     cout<<ct<<":"<<endl;
     for(int x:arr){
         cout<<x<<" ";
     }
     cout<<endl;
         
   }
}

//selection sort
//2,6,3,2,11
//2
//2,2
//2,2,3
//2,2,3,6
//2,2,3,6,11
void ssort(vector<int>&arr,int n){
    int ct=0;
    for(int i=0;i<n-1;i++){
        int mn=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mn]){
                mn=j;
            }
        }
        swap(arr[mn],arr[i]);
        ct++;
        cout<<ct<<":"<<endl;
        for(int x:arr){
         cout<<x<<" ";
        }
        cout<<endl;
    }
}

int main() {
    vector<int>arr={2,1,3,5,4};
    //bsort(arr,5);
    //isort(arr,5);
    ssort(arr,5);
    for(int x:arr){
        cout<<x<<" ";
    }
	return 0;
}
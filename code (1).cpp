#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//tc: O(N* LOG N)
//SC : O(N);
void merge(vector<int>&v,int l,int m,int h){
    int ls=m-l+1;
    int rs=h-m;
    vector<int>la(m-l+1,0);
    vector<int>ra(h-m,0);
    for(int i=0;i<m-l+1;i++){
        la[i]=v[l+i];
    }
    for(int j=0;j<h-m;j++){
        ra[j]=v[m+1+j];
    }
    int i1=0,i2=0,i=0;
    while(i1<ls && i2<rs){
        if(la[i1] <= ra[i2]){
            v[l+i]=la[i1];
            i1++;
        }
        else{
            v[l+i]=ra[i2];
            i2++;
        }
        i++;
    }
    while(i1<ls){
        v[l+i]=la[i1];
          i++,i1++;
    }
    while(i2<rs){
        v[l+i]=ra[i2];
          i++,i2++;
    }
    
}

void mergesort(vector<int>&v,int l,int h){
    if(l>=h){
        return ;
    }
    else{
        int m=(l+h)/2;
        mergesort(v,l,m);
        mergesort(v,m+1,h);
        merge(v,l,m,h);
    }
    
}

int main() {
	vector<int>v={32,27,43,3,9,82,21};
	mergesort(v,0,v.size()-1);
	for(int x:v){
	    cout<<x<<" ";
	}
	return 0;
}
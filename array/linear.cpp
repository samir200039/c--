#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,4,5,6,7,9};
    int n= sizeof(arr)/sizeof(arr[0]);
    int k,ans=-1;
    cout<<"enter your key"<<""<<endl;
    cin>>k;
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            ans=i;
            cout<<"element found at"<<"  "<<ans<<"  "<<"position"<<endl;
        }
    
    }
    return 0;
}

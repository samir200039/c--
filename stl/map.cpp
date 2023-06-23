#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int ,string>mp;
    mp[3]="Alice";
    mp[1]="Bob";
    mp[2]="Charlie";
    mp[2]="ron";
    mp[1]="Alice";

    cout<<"ordered map :\n";
    for(const auto& pair: mp){
        cout<<pair.first<<":"<<pair.second<<"\n";
    }


    return 0;
}

// Ordered Map:
// 1: Alice
// 2: Ron
// 3: Alice

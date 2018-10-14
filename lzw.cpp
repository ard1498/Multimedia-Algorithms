#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1;
    cout<<"\nenter the string :";
    cin>>s1;

    //ENCODER MAP
    unordered_map<string,int> mp;
    
    //DECODER MAP
    unordered_map<int,string> dec;
    
    int j = 256;
    string p ="";
    int i = 0,l = 0;
    vector<int> op;

    while(l != s1.length()){
        p = s1.substr(i,l-i+1);
        if(mp.find(p)==mp.end()){
            if(p.length() == 1){
                mp[p]=p[0];
                dec[p[0]] = p;
            }
            else{
                mp[p]=j;
                dec[j] = p;
                j++;
            }
            cout<<p<<":"<<mp[p]<<"\n";
            op.push_back(mp[p]);
            i = l+1;
            l = l+1;
        }
        else{
            if(l == s1.length()-1){
                op.push_back(mp[s1.substr(i,l-i+1)]);
            }
            l++;
        }
    }

    cout<<endl;
    for(int i = 0;i < op.size();i++){
        cout<<op[i];
    }
    cout<<endl;
    //DECODING...........................
    for(int i = 0;i < op.size();i++){
        cout<<dec[op[i]];
    }
    cout<<endl;
}
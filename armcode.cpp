#include<bits/stdc++.h>
using namespace std;

struct Node{
    double prob,rangefrom,rangeto;
};

int main(){
    unordered_map<char,Node> alphas;
    //unordered_map<char,double> rangefrom;
    //unordered_map<char,double> rangeto;

    double val;
    char letter;
    int n;
    cout<<"\nenter the no of letters in dictionary:";
    cin>>n;
    cout<<"\nenter the alphabets with their probabilities(like A 0.1):";
    double J = 0;
    for(int i = 0;i < n;i++){
        cin>>letter>>val;
        alphas[letter].prob = val; 
        alphas[letter].rangefrom = J;
        alphas[letter].rangeto = J + val;
        //cout<<"\nrangefrom of "<<letter<<":"<<J;
        //cout<<"\nrangeto of "<<letter<<":"<<J+val<<endl;
        J = alphas[letter].rangeto;
    }
    cout<<endl;
    string s1;
    cout<<"\nenter the string :";
    cin>>s1;
    //encoding here.......
    cout<<endl<<"\t\t\tEncoding";
    cout<<endl<<"Symbol\t\t\tlowV\t\t"<<"highV\t\t"<<"diff";
    double lowV = 0.0,highV = 1.0,diff = 1.0,t;
    for(int i = 0;i < s1.size();i++){
        cout<<endl<<s1[i]<<"\t\t\t"<<lowV<<"\t\t"<<highV<<"\t\t"<<diff;
        t = lowV;
        lowV = t + (diff*alphas[s1[i]].rangefrom);
        highV = t + (diff*alphas[s1[i]].rangeto);
        diff = highV - lowV;
        //cout<<endl<<lowV;
    }
    cout<<endl<<lowV;
    cout<<endl<<"\t\t\tDecoding";
    cout<<endl<<"code\t\t\toutput\t\trangefrom\t\trangeto";
    double code = lowV;
    string op;
    bool flag = false;
    while(op.size() != s1.size()){
        for(auto it = alphas.begin();it != alphas.end();it++){
            char ch = it->first;
            if(code >= alphas[ch].rangefrom && code < alphas[ch].rangeto){
                op.push_back(ch);
                code = (code - alphas[ch].rangefrom) / (alphas[ch].rangeto - alphas[ch].rangefrom);
                cout<<endl<<code<<"\t\t\t"<<ch<<"\t\t"<<alphas[ch].rangefrom<<"\t\t"<<alphas[ch].rangeto;
                break;
            }
        }
    }
    cout<<endl<<op;
    return 0;
}
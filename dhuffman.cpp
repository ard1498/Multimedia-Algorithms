#include<bits/stdc++.h>
using namespace std;

struct Node{
    char c;
    Node* left;
    Node* right;
    int freq;

    Node(char c1){
        left = NULL;
        right = NULL;
        c = c1;
        freq = 0;
    }

    Node(Node* L,Node* R){
        left = L;
        right = R;
        freq = L->freq + R->freq;
    }
};

struct compare{
    bool operator()(Node* a,Node* b){
        return a->freq < b->freq;
    }
};

void generatecode(Node* root,map<char,string> &table,string code){
    if(root->left != NULL){
        //code.push_back(0);
        
        generatecode(root->left,table,code+'0');
    }
    if(root->right != NULL){
        //code.push_back(1);
        generatecode(root->right,table,code+'1');
    }
    if(root->left == NULL && root->right == NULL){
        table[root->c] = code;
    }

    /*
    if(code.size()){
        code.pop_back();
    }*/
}

int main(){
    string s;
    cout<<"\nenter the string:";
    cin>>s;
    //vector<int> code;
    string code = "";
    map<char,string> table;
    map<int,int> nfreq;
    

    list<Node*> t;
    Node* r1 = new Node('$');
    r1->freq = 1;
    t.push_back(r1);

    for(int i = 0;i < s.size();i++){
        char cr = s[i];

        if(nfreq.find(cr) == nfreq.end()){
            cout<<"\ncur symbol is :"<<s[i];
            nfreq[cr]++;
            Node* nn = new Node(cr);
            nn->freq = nfreq[cr];
            t.push_back(nn);
            t.sort(compare());
        }
        
        else{
            for(auto itr = t.begin();itr != t.end();itr++){
                Node* cur = *itr;
                if(cur->c == cr){
                    cur->freq++;
                    nfreq[cr]++;
                    t.sort(compare());
                }
            }
        }

        list<Node*> tree = t;
        while(tree.size() > 1){
            tree.sort(compare());
            Node* l = tree.front();
            tree.pop_front();
            Node* r = tree.front();
            tree.pop_front();
            Node* nr = new Node('$');
            nr->freq = l->freq + r->freq;
            nr->left = l;
            nr->right = r;
            tree.push_front(nr);
        }

        Node* root = tree.back();
        generatecode(root,table,code);

        for(auto i = table.begin();i != table.end();i++){
            cout<<"\n"<<i->first<<"\t"<<i->second;
        }

        cout<<"\n";
    }

    return 0;
}

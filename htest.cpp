#include<cstdlib>
#include<iostream>
#include<utility>
#include<math.h>
#include<vector>
#include<queue>
#include<fstream>
#include<cstring>
#include<map>
#include<algorithm>

using namespace std;

struct node{
int freq;
string c;
node* left;
node* right;
};
struct node_comparison 
{
    bool operator () ( const node* a, const node* b ) const 
    {
        return a->freq >= b->freq;
    }
};
priority_queue<node *, vector<node *>,node_comparison > pq;


node* root=NULL;
void printLevelOrder(node *root) ;
void encode(node* k, string s, map<string,string> & final);


void inorder(node* root){
node* temp;
temp=root;

	if (temp!=NULL)
	{
		inorder(temp->left);
		cout << temp->c <<" : "<<temp->freq<<endl;
		inorder(temp->right);
	}
}







void createtrees(int x , string a){
node* n = new node;
n->freq=x;
n->c=a;
n->left=NULL;
n->right=NULL;
pq.push(n);
}

bool compare(node* o1, node* o2)
{
return (o1->freq <= o2->freq );
}


 


void Codes(node* t, int arr[], int top)
{
    // Assign 0 to left edge and recur
    if (t->left)
    {
        arr[top] = 1;
        Codes(t->left, arr, top + 1);
    }
 
    // Assign 1 to right edge and recur
    if (t->right)
    {
        arr[top] = 0;
        Codes(t->right, arr, top + 1);
    }
 
    // If this is a leaf node, then it contains one of the input
    // characters, print the character and its code from arr[]
    if (t->left==NULL && t->right==NULL && strlen((t->c).c_str()))
    {
    cout<<t->c<<":";
    for (int i = 0; i < top; ++i)
    cout<< arr[i];
    cout<<"\n";
    }
}

void encode(node* k, string s, map<string,string> & final)
{
  if(k!=NULL){
	encode(k->left,s+"1",final); 
	encode(k->right,s+"0",final); 
	if(k->left==NULL && k->right==NULL)
		final[k->c]=s;
}
}



map<string,int>list;
map<string,int>::iterator ii;
int main(){

string ch;
fstream fin("text.txt", fstream::in);
while (fin >> ch) {
++list[ch];
}





cout<<"map 1"<<endl;

for(ii=list.begin(); ii!=list.end(); ++ii){
cout<<ii->first<<" : "<<ii->second<<endl;
}



int x;string a;

for(ii=list.begin(); ii!=list.end(); ++ii){
a=ii->first;
x=ii->second;
createtrees(x,a);
}

cout<<"\n \n \n";


int tempx;
node* cur;
string tempc;
int m=0;
while(pq.size()>1){

node* test = pq.top();
pq.pop();
cout<<test->c<<test->freq<<endl;
//test->left=NULL;
//test->right=NULL;
node* min2= pq.top();
pq.pop();
cout<<min2->c<<min2->freq<<endl;
node* temp = new node;
temp->freq=test->freq+min2->freq;
cout<<temp->freq<<"\t";
temp->c=test->c+min2->c;
cout<<temp->c<<endl;
temp->left=test;
temp->right=min2;
pq.push(temp);
cout<<"size:"<<pq.size()<<"\n";

}
root=pq.top();
pq.pop();
cout<<pq.size();

cout<<"tree\n";
inorder(root);
cout<<"\n\n\n\n";
cout<<"\n\n\n\n";
int arr[100];
string s;
int f;
node* t;
t=root;

cout<<"the tree traversal codes\n\n";
Codes(t,arr,0);
string cl;
node* k;
k=root;
int l;
map<string,string>final;
map<string,string>::iterator fi;
cout<<"huffman codes"<<endl;

string g;
encode(k,g,final);

for(fi=final.begin(); fi!=final.end(); ++fi){
cout<<fi->first<<" : "<<fi->second<<endl;
}

while (fin >> ch) {

for(fi=final.begin(); fi!=final.end(); ++fi){
if(ch==fi->first)
cout<<"yes";
}


}
return 0;
}



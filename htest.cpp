#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<fstream>
#include<cstring>
#include<map>
#include<algorithm>
#include<deque>
#include<vector>

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


deque<node *> trees;
deque<node *>::iterator q;
node* root=NULL;
void printLevelOrder(node *root) ;

node* cmt(node* test, node* min2){
node* p = new node;
p->freq=test->freq+min2->freq;
cout<<"p1->fre "<<p->freq<<"\t";
p->c=test->c+min2->c;
cout<<"p1->c "<<p->c<<endl;
if(root==NULL){
p->left=test;
p->right=min2;
root=p;
return p;
}
else{
p->left=test;
p->right=min2;

}
root=p;
return p;
}





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

void inorder1(node* root){
node* temp;
temp=root;

		cout << temp->c <<" : "<<temp->freq<<endl;
		cout << temp->left->c <<" : "<<temp->left->freq<<endl;
	cout << temp->right->c <<" : "<<temp->right->freq<<endl;
//		cout << temp->left->left->c <<" : "<<temp->left->left->freq<<endl;
		cout << temp->left->right->c <<" : "<<temp->left->right->freq<<endl;
		cout << temp->right->left->c <<" : "<<temp->right->left->freq<<endl;
		cout << temp->right->right->c <<" : "<<temp->right->right->freq<<endl;
}









void createtrees(int x , string a){
node* n = new node;
n->freq=x;
n->c=a;
n->left=NULL;
n->right=NULL;
trees.push_back(n);
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
 

void Copycodes(node* t, int arr[], int top, map<string,int> list)
{
    // Assign 0 to left edge and recur
    if (t->left)
    {
        arr[top] = 1;
        Copycodes(t->left, arr, top + 1,list);
    }
 
    // Assign 1 to right edge and recur
    if (t->right)
    {
        arr[top] = 0;
        Copycodes(t->right, arr, top + 1,list);
    }
 int sum=0;
    // If this is a leaf node, then it contains one of the input
    // characters, print the character and its code from arr[]
    if (t->left==NULL && t->right==NULL && strlen((t->c).c_str()))
    {
    cout<<t->c<<":";
    for (int i = 0; i < top; ++i)
    {sum+=(pow(10,i)*arr[i]);
cout<<sum;
list[t->c]=sum;
    cout<<"\n";
    }
}
}



void encode(node* t, int arr[], int top,string cl)
{
    if (t->left )
    {
        arr[top] = 1;
        encode(t->left, arr, top + 1,cl);
    }
 
    // Assign 1 to right edge and recur
    if (t->right )
    {
        arr[top] = 0;
        encode(t->right, arr, top + 1,cl);
    }
 
    // If this is a leaf node, then it contains one of the input
    // characters, print the character and its code from arr[]
    if (t->left==NULL && t->right==NULL && strcmp((t->c).c_str(),cl.c_str())==1)
    {
        
    for (int i = 0; i < top; ++i)
   cout<<"\n"; 
}
}



map<string,int>list;
int main(){

map<string,int>::iterator ii;
vector<string> store;
string ch;
fstream fin("text.txt", fstream::in);
while (fin >> ch) {
++list[ch];

store.push_back(ch);
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

cout<<"the queue"<<endl;

for(int l=0;l<trees.size();l++){
cout<<trees[l]->c<<"\t"<<trees[l]->freq<<endl;
}


sort(trees.begin(),trees.end(),compare);
cout<<"after sorting\n";
for(int l=0;l<trees.size();l++){
cout<<trees[l]->c<<"\t"<<trees[l]->freq<<endl;
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
Codes(t,arr,0);
string cl;
cout<<"the encoded\n\n";
node* k;

for(int st=0;st<store.size();st++)
{cl=store[st];
k=root;
encode(k,arr,0,cl);
}


list.clear();
cout<<"map 1"<<endl;
Copycodes(t,arr,0,list);



for(ii=list.begin(); ii!=list.end(); ++ii){
cout<<ii->first<<" : "<<ii->second<<endl;
}



return 0;
}



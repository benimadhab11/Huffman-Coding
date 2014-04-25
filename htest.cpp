#include<cstdlib>
#include<iostream>
#include<utility>
#include<math.h>
#include<vector>
#include<queue>
#include<fstream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

struct node{
int freq;
char c;
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







void createtrees(int x , char a){
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
    if (t->left==NULL && t->right==NULL)
    {
    cout<<t->c<<":";
    for (int i = 0; i < top; ++i)
    cout<< arr[i];
    cout<<"\n";
    }
}

void encode(node* k, string s, map<char,string> & final)
{
  if(k!=NULL){
	encode(k->left,s+"1",final); 
	encode(k->right,s+"0",final); 
	if(k->left==NULL && k->right==NULL)
		final[k->c]=s;
}
}



map<char,int>::iterator ii;
int main(){

char ch;/*
fstream fin("text.txt", fstream::in);
while (fin >> ch) {
++list[ch];
}*/

cout<<"map 2"<<endl;

fstream inText( "text.txt", ios::in );
map<char, int> list;
   //Count letters
string test="";
while( ( ch = inText.get() ) && inText.good() )
{
test=test+ch;
++list[ch];
}   //Display counted letters
for( map<char, int>::iterator tt = list.begin(); tt != list.end(); ++tt )
    //  if( it->first == '\n' )
      //   cout << "New lines: " << it->second << " times\n";
      //else
cout << "'" << tt->first << "'" << ": " << tt->second << " times\n";
cout<<"\ntest\n";



cout<<"map 1"<<endl;

for(ii=list.begin(); ii!=list.end(); ++ii){
cout<<ii->first<<" : "<<ii->second<<endl;
}





int x;char a;

for(ii=list.begin(); ii!=list.end(); ++ii){
a=ii->first;
x=ii->second;
createtrees(x,a);
}

cout<<"\n \n \n";


int tempx;
node* cur;
char tempc;
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
char s;
int f;
node* t;
t=root;

cout<<"the tree traversal codes\n\n";
Codes(t,arr,0);
char cl;
node* k;
k=root;
int l;
map<char,string>final;
map<char,string>::iterator fi;
cout<<"huffman codes\n"<<endl;

string g;
encode(k,g,final);
for(fi=final.begin(); fi!=final.end(); ++fi){
cout<<fi->first<<":"<<fi->second<<endl;
}
string decode="";

cout<<"\n \n \nencoding. . .\n\n\n";
for(int kkk=0;kkk<test.size();kkk++){
for(fi=final.begin(); fi!=final.end(); ++fi){
if(test[kkk]==(*fi).first){
decode=decode+fi->second;
}
}
}

cout<<decode;

string encode="";
string temp="";
cout<<"\n\n\n";
cout<<"decoding . . .\n";
for(int j=0;j<decode.size();j++){
temp=temp+decode[j];
for(fi=final.begin(); fi!=final.end(); ++fi){
if(temp==(*fi).second){
cout<<fi->first;
temp="";
break;
}

}
}

cout<<encode;



   return 0;
}



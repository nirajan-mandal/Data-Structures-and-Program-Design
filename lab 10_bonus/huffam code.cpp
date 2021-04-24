/*Nirajan Mandal 04/28/2008
This program implements the huffman tree..the output of the program gives the codes of the symbols
and the averagae weighted length of the code.

To modify the code for some other language make three changes to the program.
1) change n (global integer, a constant) to the number of symbols that will be used
2) in the function make_nodes, replace string alpha with teh symbols that will be used
3) in the function make_nodes, replace int f[n] with the frequency of the corresponding symbols 
         in the string alpha
*/         

#include <iostream>
template<class elemType>
struct nodeType
{
   elemType	           info;            //this will store the frequency
   nodeType<elemType>  *llink;
   char     mid;                        //this will store the symbol, if the node does not have
   nodeType<elemType>  *rlink;          //a symbol, '_' will be assigned 
};
using namespace std;

void make_nodes(nodeType<int> *a[]);
//function to make nodes for all the symbols
//precondition: takes an array that stores pointers of type nodeType<int> 
//postcondition: the array contains pointers to nodes corresponding to each symbol
void build_tree(nodeType<int> *a[]);
//function to
//precondition:
//postcondition:
void sort(nodeType<int> *a[]);
//function to sort the array accordig to frequency of the nodes
//precondition: takes an array 
//postcondition: the array is sorted
void swap(nodeType<int> *a[], int p, int q);
//function to swap position of pointers at location p and q 
int min_loc(nodeType<int> *a[], int x, int y);
//function to find the minimum frequency of the array and returns its location
void print(nodeType<int> *p, string s, int & su, int & f);
//function to print the symbols and its codes...
//the function also finds the sum of the frequency and the sum of frequency*length of codes 
//of all the symbols

const int n=27;  //global interger.. this is the total number of symbols in the tree

int main()
{
   string s;                //string to store 1's and 0's for the code
   int sum_f_l=0, sum_f=0;  //variable to used to find average weighted code length
   nodeType<int> *all[n];   //n nodes are delcared
   make_nodes(all);   
   build_tree(all);
   cout<<"symbol\t"<<"freq.\t"<<"code\t"<<endl;
   cout<<"----------------------------"<<endl;
   print(all[n-1], s, sum_f_l, sum_f);
   cout<<"----------------------------"<<endl;
   cout<<"\naverage weighted code length: "<<(double)sum_f_l/sum_f<<endl<<endl;
   
   system("PAUSE");
return 0;
}

void build_tree(nodeType<int> *a[])
{
    for(int i=0; i<n-1; i++)
    {
           sort(a);
           nodeType<int> *newNode;
           newNode = new nodeType<int>;
           newNode->info = a[i]->info + a[i+1]->info;
           newNode->mid='_';
           newNode->llink = a[i];
           newNode->rlink = a[i+1];
           //cout<<a[i]->info<<" "<<a[i+1]->info<<" insert "<<i<<"   "<<i+1<<endl;
           a[i+1]=newNode;
     } 
     nodeType<int> *newNode;
     newNode = new nodeType<int>; 
     newNode->info = a[n-1]->llink->info + a[n-1]->rlink->info;
     newNode->mid='_';
     newNode->llink = a[n-1]->llink;
     newNode->rlink = a[n-1]->rlink;
     a[n-1]=newNode;
}//end build_tree
void print(nodeType<int> *p, string s, int & su, int & f)
{
    if(p != NULL)
	{
		if(p->mid!='_')
        {
           cout<<p->mid<<"\t"<<p->info<<"\t"<<s<<endl;
           su+=(p->info)*(s.length());
           //cout<<su<<" ";
          f+=p->info;
           //cout<<f<<endl;
        }
        s+='0';   
		print(p->llink, s, su, f);
		s=s.erase(s.length()-1, 1)+'1';
		print(p->rlink, s, su, f);
	}
}//end print
void make_nodes(nodeType<int> *a[])
{
   string alpha="zxqjkvbpgywmfculdhrsnioate ";  //given symbols and the frequency are given below         
   int f[n]={1,1,1,1,5,8,13,15,15,16,18,20,21,22,23,32,32,47,48,51,57,57,63,64,80,103,186};
   //string alpha="abcdefg";   //test data
   //int f[n]={6,5,4,1,2,2,3};
   for(int i=0; i<n; i++)
   {
           nodeType<int> *newNode;
           newNode = new nodeType<int>;
           newNode->info = f[i];
           newNode->mid=alpha[i];
           newNode->llink = NULL;
           newNode->rlink = NULL;
           a[i]=newNode;
        }
}//end make_nodes
void sort(nodeType<int> *a[])
{
    for(int i=0; i<n; i++)
        swap(a, i, min_loc(a, i, n));    
}//end sort  
void swap(nodeType<int> *a[], int p, int q)
{
     nodeType<int> *temp;
     temp=a[p];
     a[p]=a[q];
     a[q]=temp;
}//end swap     
int min_loc(nodeType<int> *a[], int x, int y)
{
    int min=a[x]->info;
    int index=x;
    for(int i=x+1; i<y; i++)   
    {
            if(a[i]->info<min)
            { 
               min=a[i]->info;
               index=i;
               }
      }
      return index;
}//end min_loc       


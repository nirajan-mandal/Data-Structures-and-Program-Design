#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main()
{

	bSearchTreeType<int>  treeRoot, otherTreeRoot;
	//int a[9]={60,50, 70, 30, 58, 80, 46, 77, -999};
	//int i=0;
	int num;//=a[i];

	cout<<"Enter numbers ending with -999"<<endl;
	cin>>num;

	while(num != -999)
	{
        treeRoot.insert(num);
		//i++;
		//num=a[i];
		cin>>num;
	}

	cout<<endl<<"Tree nodes in inorder: ";
	treeRoot.inorderTraversal();
	cout<<endl;
   
    cout<<"Number of Nodes: "
		<<treeRoot.treeNodeCount()<<endl;
     
	cout<<"Number of Leaves: "
		<<treeRoot.treeLeavesCount()<<endl;
	cout<<"Number of single Parents: "
		<<treeRoot.singleParent()<<endl;
  	
	cout<<endl;

    system("pause");
	return 0;
}

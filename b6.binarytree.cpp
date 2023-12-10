#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node* left;
		node* right;
};

class BST
{
	public:
		node* root;
		BST()
		{
	 		root = NULL;
		}

		void create_tree();
		void inorder(node*);
		void preorder(node*);
		void postorder(node*);
		void search_element();
		int height(node *root);
		void mirror(node *root);
		void smallest();
		void greatest();
};

void BST::create_tree()
{
	node* new_node, *temp;
	new_node = new node;
	cout<<"Enter Data: ";
	cin>>new_node->data;
	new_node->left = NULL;
	new_node->right = NULL;
	bool flag = true;

	if(root == NULL)
		root = new_node;
	else
	{
	    temp = root;
	    while(flag)
	    {
	        if(new_node->data < temp->data)
	        {
	            if(temp->left == NULL)
	            {
	                temp->left = new_node;
	                flag = false;
	            }
	    	       else
	    	       {
	    	           temp = temp->left;

	    	       }
	        }
    	       else if(new_node->data > temp->data)
    	       {
    	           if(temp->right==NULL)
    	           {
    	               temp->right = new_node;
    	               flag = false;
    	           }
    	           else
    	           {
    	               temp = temp->right;
    	           }
    	       }
    	       else
    	       {
    	           cout<<"Data Already Exist";
    	           flag = false;
    	       }

	  }
    }
}

void BST::inorder(node *temp)
{
	if(temp != NULL)
	{
		inorder(temp->left);
		cout<<temp->data<<endl;
		inorder(temp->right);
	}
}

void BST::preorder(node *temp)
{
	if(temp != NULL)
	{
		cout<<temp->data<<endl;
		preorder(temp->left);
		preorder(temp->right);
	}
}

void BST::postorder(node *temp)
{
	if(temp != NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->data<<endl;
	}
}

void BST::search_element()
{
	node *temp;
	int flag=0,key;
	cout<<"Enter key u want to search";
	cin>>key;
	if(root==NULL)
	    cout<<"Tree is empty";
	else
	{
	    temp=root;
	    while(flag==0)
	    {
	        if(key==temp->data)
	        {
	            cout<<"Key is present";
	            flag=1;
	        }
	        else if(key<temp->data)
	        {
	            if(temp->left != NULL)
	                temp=temp->left;
	            else
	            {
	                cout<<"Key is not present";
	                flag=1;
	            }
	        }
	        else if(key>temp->data)
	        {
	            if(temp->right != NULL)
	                temp=temp->right;
	            else
	            {
	                cout<<"Key is not present";
	                flag=1;
	            }

	       }
	    }
	}

}

int BST::height(node *root)
{
    int left_height, right_height;
    if(root==NULL)
    {
        return(0);
    }
    else if(root->left==NULL && root->right==NULL)
    {
        return(0);
    }
    left_height=height(root->left);
    right_height=height(root->right);
    if(left_height>right_height)
    {
        return(left_height + 1);
    }
    else
    {
        return(right_height + 1);
    }
}

void BST::mirror(node *root)
{
    node *temp;
    if(root != NULL)
    {
        temp=root->left;
        root->left=root->right;
        root->right=temp;
        mirror(root->left);
        mirror(root->right);
    }
}

void BST::smallest()
{
    node *temp;
    temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    cout<<"Smallest element is:"<<temp->data;
}

void BST::greatest()
{
    node *temp;
    temp=root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    cout<<"Smallest element is:"<<temp->data;
}

int main()
{
	BST obj;

	int ch;
	bool flag = true;
	while(flag)
	{
		cout<<endl<<endl;
		cout<<"---------------- Menu -------------------"<<endl;
		cout<<"1.Create Binary Tree"<<endl;
		cout<<"2.Display by Inorder"<<endl;
		cout<<"3.Display by Preorder"<<endl;
		cout<<"4.Display by Postorder"<<endl;
          cout<<"5.Search for node"<<endl;
          cout<<"6.height of tree"<<endl;
          cout<<"7.mirror image of tree"<<endl;
          cout<<"8.smallest element in tree"<<endl;
          cout<<"9.greatest element in tree"<<endl;
		cout<<"10.Exit"<<endl;
		cout<<"Enter Your Choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				obj.create_tree();
				break;

			case 2:
                    cout<<"INORDER:\n";
				obj.inorder(obj.root);
				break;

			case 3:
                    cout<<"PREORDER:\n";
				obj.preorder(obj.root);
				break;

            case 4:
                    cout<<"POSTORDER:\n";
				obj.postorder(obj.root);
				break;

                  case 5:
				obj.search_element();
				break;

			case 6:
				obj.height(obj.root);
				break;

            case 7:
		        cout<<"Before mirror image:";
		        obj.inorder(obj.root);
                obj.mirror(obj.root);
		        cout<<"After mirror image:";
		        obj.inorder(obj.root);
                break;

		     case 8:
                obj.smallest();
                break;

		     case 9:
                obj.greatest();
                break;

		     case 10:
                cout<<"EXIT";
                break;
		}
	}
	return 0;
}

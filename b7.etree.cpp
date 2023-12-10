 #include<iostream>
using namespace std;

class node
{
public:
    char data;
    node *left;
    node *right;
};

class stack
{
public:
    node *a[20];
    int top;
    stack()
    {
        top=-1;
    }
    void push(node *temp)
    {
        if(top<=20)
        {
            a[++top]=temp;
        }
        else
        {
            cout<<"Stack is full";
        }
    }
    node *pop()
    {
        if(top!=-1)
        {
            return(a[top--]);
        }
        else
        {
            cout<<"Stack is empty";
        }
        return 0;
    }
};

class Etree
{
public:
    node *root;
    Etree()
    {
        root=NULL;
    }
    void createTree();
    void prefix(node *temp);
    void infix(node *temp);
    void postfix(node *temp);
    void Delete(node *temp);
    void non_rec_postorder(node *top);
};

void Etree :: createTree()
{
    stack s;
    int i=0;
    string postfixexp;
    cout<<"Enter postfix expression:";
    cin>>postfixexp;
    char ch;
    ch=postfixexp[i];

    while(ch!='\0')
    {
        node *nn;
        nn=new node();
        nn->left=NULL;
        nn->right=NULL;
        nn->data=ch;

        if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        {
            nn->right=s.pop();
            nn->left=s.pop();
            s.push(nn);
        }
        else
        {
            s.push(nn);
        }
        ch=postfixexp[i++];
    }
    root=s.pop();
}

void Etree :: prefix(node *temp)
{
    if(temp!=NULL)
    {
        cout<<temp->data;
        prefix(temp->left);
        prefix(temp->right);
    }
}

void Etree :: infix(node *temp)
{
    if(temp!=NULL)
    {
        infix(temp->left);
        cout<<temp->data;
        infix(temp->right);
    }
}

void Etree :: postfix(node *temp)
{
    if(temp!=NULL)
    {
        postfix(temp->left);
        postfix(temp->right);
        cout<<temp->data;
    }
}

void Etree::non_rec_postorder(node *top)
{
    stack s1,s2;
    node *T=top;
    cout<< "\n Postfix Expression is : ";
    s1.push(T);
    while(s1.top!=-1)
    {
        T=s1.pop();
        s2.push(T);
        if(T->left!=NULL)
            s1.push(T->left);
        if(T->right!=NULL)
            s1.push(T->right);
    }
    while(s2.top!=-1)
    {
        top=s2.pop();
        cout<<top->data;
    }
}


void  Etree :: Delete(node *temp)
{
    if(temp == NULL)
        return;
    Delete(temp->left);
    Delete(temp->right);
    cout<<"Deleted node is:"<<temp->data<<endl;
    free(temp);
}
int main()
{
	int ch;

	Etree e1;
	do
	{
		cout<<endl;
		cout<<"---------------- Menu -------------------"<<endl;
		cout<<"1.Create Expression Tree"<<endl;
		cout<<"2.Display prefix"<<endl;
		cout<<"3.Display infix"<<endl;
		cout<<"4.Display postfix"<<endl;
		cout<<"5.Delete node"<<endl;
		cout<<"6.Display non recurrsion postfix"<<endl;
		cout<<"7.Exit"<<endl;
		cout<<"Enter Your Choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				e1.createTree();
			   break;

			case 2:
				e1.prefix(e1.root);
			   break;

			case 3:
				e1.infix(e1.root);
			   break;

			case 4:
				e1.postfix(e1.root);
			   break;

			case 5:
			    e1.Delete(e1.root);
			    break;
            case 6:
                e1.non_rec_postorder(e1.root);
                break;
            case 7:
			   cout<<"EXIT";
				break;
		}
	}while(ch!=7);
	return 0;
}

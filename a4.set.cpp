#include<iostream>
using namespace std;

class Set
{
public:
    int a[10];
    int cnt;
	Set()
	{
         cnt=0;
	}
    void add();
    void display();
    Set unionSet(Set B);
    Set intersection(Set B);
    Set minus(Set B);
    int search(int key);
    void remove();
    int subset(Set B);
};

void Set :: add()
{
	cout<<"Enter number of elements:";
	cin>>cnt;
	cout<<"Enter "<<cnt<<" elements:";
	for(int i=0;i<cnt;i++)
	{
		cin>>a[i];
	}
}

void Set :: display()
{
	cout<<"\nElements are:";
	for(int i=0;i<cnt;i++)
	{
		cout<<a[i]<<" ";
	}
}

Set Set :: unionSet(Set B)
{
	Set temp;
	int flag=0;
	for(int i=0;i<cnt;i++)
	{
		temp.a[temp.cnt++]=a[i];
	}
	for(int i=0;i<B.cnt;i++)
	{
		flag=temp.search(B.a[i]);
		if(flag==0)
		{
			temp.a[temp.cnt++]=B.a[i];
		}
	}
	return(temp);
}

Set Set :: intersection(Set B)
{
	int flag;
     Set temp;
	for(int i=0;i<cnt;i++)
	{
		flag=B.search(a[i]);
		if(flag==1)
		{
			temp.a[temp.cnt++]=a[i];
		}
	}
	return(temp);
}

Set Set :: minus(Set B)
{
	int flag;
     Set temp;
	for(int i=0;i<cnt;i++)
	{
		flag=B.search(a[i]);
		if(flag==0)
		{
			temp.a[temp.cnt++]=a[i];
		}
	}
	return(temp);
}

int Set :: search(int key)
{
	for(int i=0;i<cnt;i++)
	{
		if(a[i]==key)
		{
			return 1;
		}
	}
	return 0;
}

void Set :: remove()
{
	int key;
	cout<<"Enter the element u want to delete:";
	cin>>key;
	for(int i=0;i<cnt;i++)
	{
		if(key==a[i])
		break;
	}
	for(int i;i<cnt;i++)
	{
		a[i]=a[i+1];
	}
	cnt--;
}

int Set :: subset(Set B)
{
	int i;
	for(i=0;i<B.cnt;i++)
	{
		if(search(B.a[i])==0)
		{
			cout<<"B is not the subset of A";
			break;
		}
	}
	if(i==B.cnt)
	{
		cout<<"B is subset of A";
	}
}

int main()
{
	Set A,B,C;
	int ch,key,ele;
	bool flag = true;
	while(flag)
	{
		cout<<endl<<endl;
		cout<<"---------------- Menu -------------------"<<endl;
		cout<<"1.Add"<<endl;
		cout<<"2.Union"<<endl;
		cout<<"3.Intersection"<<endl;
        cout<<"4.Minus"<<endl;
        cout<<"5.Search element"<<endl;
		cout<<"6.Remove element"<<endl;
		cout<<"7.Subset"<<endl;
		cout<<"8.Exit"<<endl;
		cout<<"Enter Your Choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				A.add();
				B.add();
				break;

			case 2:
                	C=A.unionSet(B);
			     A.display();
			     B.display();
			     C.display();
				break;

			case 3:
                C=A.intersection(B);
				C.display();
				break;

               case 4:
				C=A.minus(B);
				C.display();
				break;

			case 5:
				cout<<"\nEnter data to search :";
				cin>>key;
				flag=A.search(key);
				if(flag==1)
				{
					cout<<"Key Found";
				}
				else
				{
					cout<<"Key Not Found";
				}
				break;

			case 6:
				A.remove();
				A.display();
				break;

            case 7:
				A.subset(B);
				break;

			case 8:
				cout<<"EXIT";
				flag = false;
		          break;
		}
	}
	return 0;
}

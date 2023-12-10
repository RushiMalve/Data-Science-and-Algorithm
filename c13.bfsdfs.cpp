#include<iostream>
using namespace std;

class Queue
{
	public:
		int f,r;
		int arr[20];
		Queue()
		{
			f = 0;
			r = 0;
		}

		void enqueue(int k)
		{
			if (r != 20)
			{
				arr[r++] = k;
			}
			else
			{
				cout<<"Queue is full "<<endl;
			}
		}

		int dequeue()
		{
			if (r != f)
			{
				return (arr[f++]);
			}
			else
			{
				cout<<"Queue is empty"<<endl;
			}
		}
};

class Stack
{
	public:
		int top;
		int arr[20];
		Stack()
		{
			top = -1;
		}

		void push(int k)
		{
			if (top != 20)
			{
				arr[++top] = k;
			}

			else
			{
				cout<<"Stack is Full"<<endl;
			}
		}

		int pop()
		{
			if(top != -1)
			{
				return (arr[top--]);
			}
			else
			{
				cout<<"Stack is empty"<<endl;
			}
		}
};

class graph
{
	public:
		int vertix_cnt;
		int ver[20];
		int adj_mat[20][20];
		int visited_arr[20];
		int cnt;
		int curr_ver;

		void create_adjmat();
		void display_adjmat();
		int search(int k);
		void display(string s);
		void DFS();
		void BFS();
};

void graph :: create_adjmat()
{
	cout<<"Enter the total number of nodes :"<<endl;
	cin>>vertix_cnt;
	cout<<"Enter the values of nodes :"<<endl;
	for (int i=1; i<=vertix_cnt; i++)
	{
		cin>>ver[i];
	}
	cout<<"Enter 1 if edge is present else 0 "<<endl;
	for(int i= 1 ; i<=vertix_cnt; i++)
	{
		for (int j=1; j<=vertix_cnt; j++)
		{
			cout<<"Node "<<ver[i]<<"and "<<ver[j]<<" :";
			cin>>adj_mat[i][j];
		}
	}
}

void graph :: display_adjmat()
{
	cout<<"Adjacency matrix :"<<endl;
	cout<<"  ";
	for (int i=1; i<=vertix_cnt; i++)
	{
		cout<<ver[i]<<" ";
	}
	cout<<endl;

	for (int i=1 ; i<= vertix_cnt; i++)
	{
		cout<<ver[i]<<" ";
		for (int j=1; j<= vertix_cnt; j++)
		{
			cout<<adj_mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

int graph :: search(int k)
{
	for (int i=0; i<cnt; i++)
	{
		if (visited_arr[i] == k)
		{
			return 1;
		}
	}
	return 0;
}

void graph :: display(string s)
{
	cout<<"\t"<<s<<" Traversal :"<<endl;
	for (int i=0 ; i<cnt; i++)
	{
		cout<<visited_arr[i]<<" ";
	}
	cout<<endl;
}


void graph :: DFS()
{
	Stack s;
	int flag,i,j;
	cout<<"Enter starting vertix :";
	cin>>curr_ver;
	cnt = 0;
	flag = 0;
	s.push(curr_ver);
	visited_arr[cnt++] = curr_ver;
	curr_ver = s.pop();

	for(i = curr_ver; i<=vertix_cnt;)
	{
		if (flag == 0)
		{
			for (j = 1; j<= vertix_cnt;j++)
			{
				if(adj_mat[i][j] == 1)
				{
					s.push(j);
				}
				flag = 1;
			}
		}

		curr_ver = s.pop();

		if(search(curr_ver) == 0)
		{
			visited_arr[cnt++] = curr_ver;
			flag = 0;
		}

		i = curr_ver;
		if(cnt == vertix_cnt)
		{
			break;
		}
	}
	display("DFS");

}


void graph :: BFS()
{
	Queue q;
	int flag,i,j;
	cout<<"Enter starting vertix :";
	cin>>curr_ver;
	cnt = 0;
	flag = 0;
	q.enqueue(curr_ver);
	visited_arr[cnt++] = curr_ver;
	curr_ver = q.dequeue();

	for(i = curr_ver; i<=vertix_cnt;)
	{
		if (flag == 0)
		{
			for (j = 1; j<= vertix_cnt;j++)
			{
				if(adj_mat[i][j] == 1)
				{
					q.enqueue(j);
				}
				flag = 1;
			}
		}

		curr_ver = q.dequeue();

		if(search(curr_ver) == 0)
		{
			visited_arr[cnt++] = curr_ver;
			flag = 0;
		}

		i = curr_ver;
		if(cnt == vertix_cnt)
		{
			break;
		}
	}
	display("BFS");
}

int main()
{
	graph obj;
	obj.create_adjmat();
	obj.display_adjmat();

	obj.DFS();
	obj.BFS();

}

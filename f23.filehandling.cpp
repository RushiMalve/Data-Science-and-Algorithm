#include<iostream>
#include<fstream>
using namespace std;

class data
{
    public:
    int rno;
    char name[20];
    char div[10];
    char add[25];
};

class StudentDataBase
{
    public:
    data obj;
    ofstream o;
    ifstream i;
    fstream io;
    void create();
    void display();
    void search(int);
    void deleteinfo(int);
};

void StudentDataBase::create()
{
    o.open("DataBase.dat",ios::app|ios::binary);
    cout<<"\nEnter Roll No.: ";cin>>obj.rno;
    cout<<"Enter Name    : ";cin>>obj.name;
    cout<<"Enter Divsion : ";cin>>obj.div;
    cout<<"Enter Address : ";cin>>obj.add;
    o.write((char*)&obj,sizeof(obj));
    o.close();
}

void StudentDataBase::search(int x)
{
    i.open("DataBase.dat",ios::in|ios::binary);
    while(i.read((char *)&obj,sizeof(obj)))
    {
        if(obj.rno==x)
        {
            cout<<"Entry Found"<<endl;
            cout<<"\tRoll No.\tName\t\t\tDivsion\tAddress"<<endl<<endl;
            cout<<"\t"<<obj.rno<<"\t\t"<<obj.name<<"\t\t\t"<<obj.div<<"\t\t"<<obj.add<<endl;
            break;
        }
        else
        {
            cout<<"Entry not Found!!"<<endl;
            break;
        }
    }
    i.close();
}

void StudentDataBase::deleteinfo(int x)
{
    o.open("temp.dat",ios::out|ios::binary);
    i.open("DataBase.dat",ios::in|ios::binary);
    while(i.read((char *)&obj,sizeof(obj)))
    {
        if(obj.rno!=x)
        {
            o.write((char *)&obj,sizeof(obj));
        }
    }
    o.close();
    i.close();
    remove("DataBase.dat");
    rename("temp.dat","DataBase.dat");
}

void StudentDataBase::display()
{
    i.open("DataBase.dat",ios::in|ios::binary);
    cout<<"\tRoll No.\tName\t\t\tDivision\tAddress"<<endl<<endl;
    while(i.read((char *)&obj,sizeof(obj)))
    {
        cout<<"\t"<<obj.rno<<"\t\t"<<obj.name<<"\t\t\t"<<obj.div<<"\t\t"<<obj.add<<endl;
    }
    i.close();
}

int main()
{
    remove("DataBase.dat");
    StudentDataBase o;
    int ch,var,n;
    do
    {
        cout<<"\n***Menu***";
        cout<<"\n1.Create Record";
        cout<<"\n2.Display";
        cout<<"\n3.Search";
        cout<<"\n4.Delete";
        cout<<"\n5.Exit";
        cout<<"\nEnter Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"How many records u want to store:";
                cin>>n;
            	cout<<"\nEnter Record of "<<n<<" Students :\n";
            	for(int i=0;i<n;i++)
            	{
                	o.create();
                }
                break;

            case 2:
                o.display();
                break;

            case 3:
                cout<<"\nEnter Roll No. to be Searched : ";
                cin>>var;
                o.search(var);
                break;
            case 4:
                cout<<"\nEnter Roll No. to be Deleted : ";
                cin>>var;
                o.deleteinfo(var);
                cout<<"\nRecord Deleted Successfully!";
                break;
            default:
                cout<<"\nEnter Vaild opition!";
                break;
        }
    }while(ch!=5);

    return 0;
}

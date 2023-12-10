#include<iostream>
using namespace std;

class hashing
{
public:
    long int mobile,hashtable[10],i=0;
    int l=0,q=0;
    hashing()
    {
        for(int i=0;i<10;i++)
            hashtable[i]=-1;
    }
    void linear();
    void quadratic();
    void display();
};

void hashing :: linear()
{
    int index;
    cout<<"Enter mobile number:";
    cin>>mobile;
    index=mobile%10;
    if(hashtable[index]==-1)
    {
        hashtable[index]=mobile;
    }
    else
    {
        while(hashtable[index]!=-1)
        {
            index=(index+1)%10;
            l++;
        }
        hashtable[index]=mobile;
    }
    cout<<"Number of comparisions in  linear are:"<<l<<endl;
}

void hashing :: quadratic()
{
    int index;
    cout<<"Enter mobile number:";
    cin>>mobile;
    index=mobile%10;
    if(hashtable[index]==-1)
    {
        hashtable[index]=mobile;
    }
    else
    {
        int u,k,j=1;
        u=mobile%10;
        while(j<10)
        {
            k=(u+(j*j)%10);
            if(hashtable[k]==-1)
            {
                hashtable[k]=mobile;
                break;
            }
            else
            {
                j++;
            }
            q++;
        }
    }
    cout<<"Number of comparisions in  quadratic are:"<<q<<endl;

}

void hashing :: display()
{
    cout<<"Hashtable"<<endl;
    for(int i=0;i<10;i++)
            cout<<i<<"    "<<hashtable[i]<<endl;
}

int main()
{
    hashing h1;
    int ch;

    do
    {
        cout<<"MENU\n1.LINEAR PROBING\n2.QUADRATIC PROBING\n3.DISPLAY\n4.EXIT\n";
        cout<<"ENTER CHOICE : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            h1.linear();
            break;
        case 2:
            h1.quadratic();
            break;
        case 3:
            h1.display();
            break;
        case 4:
            cout<<"EXIT";
            break;
        }
    }while(ch!=4);
}

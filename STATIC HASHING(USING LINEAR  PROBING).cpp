#include<iostream>
#define MAX 10
using namespace std;
void display();
void insert(int,int);
int find(int);
int search(int);
void del(int);
int a[MAX],count=0;
int main( )
{
	int key,adval,v,s,d,ad;
	char ans;
	for(int i=0;i<MAX;i++)
	a[i]=-1;
	do
	{
		cout<<"1.INSERT"<<"    "<<"2.SEARCH"<<"     "<<"3.DELETE"<<"     "<<"4.DISPLAY"<<endl;
		cout<<"ENTER YOUR CHOICE:"<<endl;
		cin>>v;
		switch(v)
		{
			case 1:
				cout<<"ENTER KEY VALUE FOR INSERTION INTO HASH TABLE:";
				cin>>key;
				adval=find(key);
	            insert(key,adval);
				break;
                                                          case 2:
				cout<<"ENTER THE KEY FOR SEARCHING:"<<endl;
				cin>>s;
				ad=search(s);
				if(ad!=100)
				cout<<s<<"   "<<"IS FOUND AT"<<"  "<<ad<<"  "<<"ADDRESS LOCATION IN HASH IN HASH TABLE:"<<endl;
				else
				cout<<"ELEMENT IS NOT IN THE HASH TABLE:"<<endl;
				break;
			case 3:
				cout<<"ENTER THE ELEMENT TO BE DELETED:"<<endl;
				cin>>d;
				del(d);
				break;
			case 4:
				display();
				break;
			default:		
				cout<<"WRONG CHOICE:"<<endl;
				break;
		}			
                            	cout<<"DO YOU WANT TO CONTINUE(Y/N):"<<endl;
		cin>>ans;
                    }while(ans=='y');
                    return 0;
}
int find(int key)
{
	int adval;
	adval=key%MAX;
	return(adval);
}
void insert(int key,int adval)
{
	if(a[adval]==-1)
	{
		a[adval]=key;
	    count=count+1;
	}
	else
	{
		if(count==MAX)
		{
			cout<<"HASH TABLE IS FULL:";
			display( );
		}
		else
		{
			int k=1,i=1,z;
			while(k<MAX)
			{
				z=((key%MAX)+i)%MAX;
				i=i+1;
				k=k+1;
				if(a[z]==-1)
				{
					a[z]=key;
					count=count+1;
					break;
				}             
			}
		}
	}
}
void display()
{
	for(int i=0;i<MAX;i++)
	cout<<i<<"    "<<a[i]<<endl;
}
int search(int key)
{	int z,flag=0;
	z=find(key);
	if(a[z]==key)
	{
		flag=1;
		return z;
	}
	else
	{
		int k=1,i=1;
		while(k<MAX)
		{
			z=((key%MAX)+i)%MAX;
			i=i+1;
			k=k+1;
			if(a[z]==key)
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==1)
	return z;
	else
	return 100;
}
void del(int key)
{
	int b;
	b=search(key);
	if(b!=100)
	a[b]=0;
	else
	cout<<"THERE IS NO SUCH KEY IN HASH TABLE:"<<endl;
}                                                     

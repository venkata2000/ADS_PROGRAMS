#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node *left,*right;
};
class form
{
	public:
	int n,r[20],d[20],temp,h=0;
	char c[20];
	node* arr[20];
	form()
	{
		for(int i=0;i<=n;i++)
		r[i]=d[i]=999;
		for(int i=0;i<20;i++)
		arr[i]=NULL;
	}
	void insert();
	int minimum();
	void decode();
};
int form::minimum()
{
	int min=999,pos;
	for(int i=0;i<=temp;i++)
		if(d[i]<min)
		{
			min=d[i];
			pos=i;
		}
	d[pos]=999;
	return min;
}
void form::insert()
{
    int k=0;
    while(k<n)
    {
	    int x1=minimum(),x2=minimum();
		if(x1!=999 && x2!=999)
		{
		node* newnode1=new node;node* newnode2=new node;node* newnode=new node;
		newnode1->left=NULL;newnode1->right=NULL;newnode2->left=NULL;newnode2->right=NULL;newnode1->data=x1;
		newnode2->data=x2;newnode->left=newnode1;newnode->right=newnode2;newnode->data=(x1+x2);
		arr[h]=newnode;
		h++;
		temp++;
		d[temp]=(x1+x2);
		}k++;
	}
}
void form::decode()
{
    int stk[20];
    int i=0;
    while(i<n)
    {
    	int k=0;
    	node* currnode=arr[k];
        int x=r[i],top=0,first=x;
        cout<<x<<":";
        while(k<h)
        {
            node* currnode=arr[k];
            if(((currnode->left)->data==(currnode->right)->data)&&(currnode->left)->data==first)
            {
            	 top=top+1;
                stk[top]=0;
                x=currnode->data;
			}
           else if((currnode->right)->data==x)
            {
                top=top+1;
                stk[top]=1;
                x=currnode->data;
            }
            else if((currnode->left)->data==x)
            {
                top=top+1;
                stk[top]=0;
                x=currnode->data;
            }k++;
        }i++;
        for(int j=top;j>0;j--)
        cout<<stk[j];
        cout<<"  ";
    }
}
int main()
{
	form hf;
	cout<<"enter no.of elements:";
	cin>>hf.n;
	cout<<"enter elements:";
	for(int i=0;i<hf.n;i++)
	{
		cin>>hf.c[i]>>hf.r[i];
		hf.d[i]=hf.r[i];
		hf.temp=i;
	}
	hf.insert();
	hf.decode();
	return 0;
}

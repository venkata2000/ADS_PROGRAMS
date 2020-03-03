#include<iostream>
using namespace std;
class binaryheap
{
	public:
	int a[50],count=0,b=0;
	void insert(int);
	void deletion();
	void display();
	void vertex_pos(int);
	void swap(int*,int*);
};
void binaryheap::insert(int x)
{
	if(count==0)
	{
		b++;
		a[b]=x;count++;
	}
	else
	{
		b++;
		a[b]=x;count++;
		int i=1,m=b/2,n=b;
		while(i<count)
		{
			if((a[n]>a[m]) && m!=0)
			{
				swap(&a[n],&a[m]);
				n=n/2;m=m/2;
				i++;
			}
			else
			break;
		}
	}
}
void binaryheap::deletion()
{
    int c[20],t,j=1,k=1;
    for(int i=1;i<=count;i++)
    c[i]=a[i];
    swap(&c[1],&c[count]);
    b--;
    count--;
    while(j<=count)
    {
        int r;
        if(j!=1)
        j=j/2;
        if(c[2*j]<c[(2*j)+1] && ((2*j)+1)<=count)
        r=(2*j)+1;
        else if((2*j)==count ||(2*j)<=count)
        r=(2*j);
        if(c[j]<c[r] && ((2*j)+1)<=count && (2*j)<=count)
        	swap(&c[j],&c[r]);
        else
        break;
        j=2*r;
    }
    for(int i=1;i<=count;i++)
    a[i]=c[i];
}
void binaryheap::display()
{
    for(int i=1;i<=count;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
void binaryheap::vertex_pos(int x)
{
    int k,flag=0;
    for(int i=1;i<=count;i++)
    if(a[i]==x)
    {
    k=i;flag=1;
    break;
    }
    if(flag==1 && k==1)
    cout<<"IT IS ROOT ELEMENT AND IT IS AT FIRST POSITION:"<<endl;
    else if(flag==1)
    cout<<x<<"is at"<<k<<"position and its parent is"<<(k/2)<<endl;
    else
    cout<<"ELEMENT NOT FOUND:"<<endl;
}
void binaryheap::swap(int* x,int* y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
}
int main()
{
    int s,m,f;
    char ans;
	binaryheap bh;
	do
	{
	    cout<<"ENTER YOUR CHOICE:"<<endl;
	    cout<<"1.INSERT"<<" "<<"2.DELETION"<<" "<<"3.DISPLAY"<<" "<<"4.FIND_POS"<<endl;
	    cin>>s;
	    switch(s)
	    {
	        case 1:
	            cout<<"ENTER ELEMENT TO INSERT:";
	            cin>>m;
	            bh.insert(m);break;
	            
	        case 2:
	            bh.deletion();break;
	        case 3:
	            bh.display();break;
	        case 4:
	             cout<<"ENTER ELEMENT TO FIND ITS POSITION:";
	            cin>>f;
	            bh.vertex_pos(f);break;
	    }cout<<"DO YOU WANT TO CONTINUE(y/n):";
	    cin>>ans;
	}while(ans=='y');
	return 0;
}					

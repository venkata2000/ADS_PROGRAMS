#include<iostream>
using namespace std;
int chminvertex(int[],int,int[]);
int d[10],visited[10],cost[10][10];
int main()
{
	int nv,ne,i,j,k,c,sv;
	cout<<"ENTER NUMBER OF VERTICES:"<<endl;
	cin>>nv;
	cout<<"ENTER NUMBER OF EDGES:"<<endl;
	cin>>ne;
	cout<<"ENETE EDGES AND THEIR COST:"<<endl;
	for(k=1;k<=ne;k++)
	{
		cin>>i>>j>>c;
		cost[i][j]=c;
		cost[j][i]=c;
	}
	for(i=1;i<=nv;i++)
	{
		for(j=1;j<=nv;j++)
		{
			if(cost[i][j]==0)
			{
				cost[i][j]=999;
			}
		}
	}
	for(i=1;i<=nv;i++)
	d[i]=999;
	cout<<"ENTER SOURCE VERTEX:"<<endl;
	cin>>sv;
	d[sv]=0;
	k=1;
	while(k<nv)
	{
		int p;
		p=chminvertex(d,nv,visited);
		visited[p]=1;
		for(int i=1;i<=nv;i++)
		{
			if(d[p]+cost[p][i]<d[i] && visited[i]!=1)
			{
				d[i]=d[p]+cost[p][i];
			}
		}k++;
	}
	for(int i=1;i<=nv;i++)
	cout<<"THE LENGTH FROM"<<"  "<<sv<<"  "<<"------>"<<i<<"is"<<d[i]<<endl;
	return 0;
}
int chminvertex(int d[],int nv,int visited[])
{
	int min=999,m;
	for(int i=1;i<=nv;i++)
	{
		if(d[i]<min && visited[i]!=1)
		{
			min=d[i];
			m=i;
		}
	}
	return m;
}

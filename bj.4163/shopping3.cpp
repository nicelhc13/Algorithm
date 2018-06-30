#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define N 100050
#define M 15
#define INF 9999999999
struct Edge
{
	    int u,v,w,next;
} edge[3*N];
int cnt,head[N];
int dis[M][M],d[N];
int c[M],s,n;
int vis[N],ans;
void init()
{
	cnt=0;
	memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w)
{
	edge[cnt].u=u,edge[cnt].v=v;
	edge[cnt].w=w,edge[cnt].next=head[u];
	head[u]=cnt++;
}
void spfa(int id)
{
	queue<int>que;
	memset(vis,0,sizeof(vis));
	for(int i=0; i<n; i++)
		d[i]= i==id?0:INF;
	que.push(id);
	while(!que.empty())
	{
		int u=que.front();
		que.pop();
		vis[u]=0;
		for(int i=head[u]; i!=-1; i=edge[i].next)
		{
			int v=edge[i].v,w=edge[i].w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				if(!vis[v])
				{
					que.push(v);
					vis[v]=1;
				}
			}
		}
	}
}
void dfs(int u,int step,int now)
{
	if(step==s)
	{
		ans=min(ans,now+dis[u][0]);
		return;
	}
	for(int i=0;i<=s;i++)
	{
		if(i==u) continue;
		if(!vis[i]&&dis[u][i]<INF)
		{
			vis[i]=1;
			dfs(i,step+1,now+dis[u][i]);
			vis[i]=0;
		}
	}
}
int main()
{
	int T;
	int m,u,v,w;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d %d",&n,&m);
		while(m--)
		{
			scanf("%d %d %d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		scanf("%d",&s);
		c[0]=0;
		for(int i=1; i<=s; i++)
			scanf("%d",&c[i]);
		for(int i=0; i<=s; i++)
		{
			spfa(c[i]);
			for(int j=0; j<=s; j++)
				dis[i][j]=d[c[j]];
		}
		memset(vis,0,sizeof(vis));
		ans=INF;
		vis[0]=1;
		dfs(0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}

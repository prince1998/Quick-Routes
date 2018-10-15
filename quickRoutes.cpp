#include<iostream>
using namespace std;
#include<string.h>
#include<cstdio>
#define IN 999
#define N 10

int n, cost[10][10];
int dijkstra(int source, int target);
int dijkstra2(int source);

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int allAreOne(int selected[]){

    for(int i =1;i<=n;i++){

        if(selected[i]==0)
            return 0;
    }

    return 1;

}
int dijsktra2(int source)
{
    int dist[N],prev[N],selected[N],i,m,min,start,d,j,targettemp;
    char path[100];
    for(i=1;i< N;i++)
    {
        dist[i] = IN;
        prev[i] = -1;
        selected[i]=0;
    }
    start = source;
    selected[start]=1;
    dist[start] = 0;
    prev[start] = -1;
    while(allAreOne(selected) !=1)
    {
        min = IN;
        m = 0;
        for(i=1;i<= n;i++)
        {
            d = dist[start] + cost[start][i];
            if(d< dist[i] && selected[i]==0)
            {
                dist[i] = d;
                prev[i] = start;
            }
            if(min>dist[i] && selected[i]==0)
            {
                min = dist[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
    }
    j = 0;
    cout<<"Distance from :\n";
    for(i = 1 ;i <= n ; i ++){
        cout<<i<<" : "<<dist[i]<<"\t";
    }
    cout<<"\n";
return 0;
}
int dijsktra(int source,int target)
{
    int dist[N],prev[N],selected[N],i,m,min,start,d,j,targettemp;
    char path[100];
    for(i=1;i< N;i++)
    {
        dist[i] = IN;
        prev[i] = -1;
        selected[i]=0;
    }
    start = source;
    selected[start]=1;
    dist[start] = 0;
    prev[start] = -1;
    while(selected[target] == 0)
    {
        min = IN;
        m = 0;
        for(i=1;i<= n;i++)
        {
            d = dist[start] + cost[start][i];
            if(d< dist[i] && selected[i]==0)
            {
                dist[i] = d;
                prev[i] = start;
            }
            if(min>dist[i] && selected[i]==0)
            {
                min = dist[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
    }
    j = 0;
    targettemp=target;
    while(prev[targettemp] != -1)
    {
        path[j++] = targettemp+'0';
        path[j++] = '>';
        targettemp = prev[targettemp];
    }
    path[j]= source + '0';
    path[j+1]='\0';
    strrev(path);

    cout<<"target"<<target<<"\n";
    cout<<"\nShortest Path: "<<dist[target]<<"\n";
    cout<<"And the path is : "<<"\n";
    cout<<path<<"\n";
    return dist[target];
}
void input()
{
    cout<<"\nEnter the number of cities:";
    cin>>n;
    cout<<"\nEnter the matrix:\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==i)
            {
                cost[i][j]=0;
                cout<<"If there is no connection between cities then enter 999 "<<endl;
                cout<<"Enter value for:["<<i<<"]["<<j<<"]="<<cost[i][j]<<endl;
                break;
            }
            cout<<"Enter value for:["<<i<<"]["<<j<<"]:";
            cin>>cost[i][j];
            cout<<"\n";
            cost[j][i]=cost[i][j];
        }
    }
}
void display()
{
    cout << "\t";
    for(int i = 1; i <= n; i++){
        cout<<i<<"\t";
    }
    cout << "\n";
    for(int i=1;i<=n;i++)
    {
        cout<<i<<"\t";
        for(int j=1;j<=n;j++)
        {
            cout<<cost[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

int main()
{
    input();
    display();
    int co,source, target,choice;
    cout<<"Menu : \n";
    cout<<"1.) Shortest Distance and path between source and destination \n";
    cout<<"2.) Shortest Distance between source and every other destination point \n ";
    cin>>choice;
    if(choice==1){
        cout<<"\nEnter The Source:";
        cin>>source;
        cout<<"\nEnter The target";
        cin>>target;
        co=dijsktra(source,target);
    }

    else{

        cout<<"\nEnter The Source:";
        cin>>source;
        co=dijsktra2(source);
    }
}

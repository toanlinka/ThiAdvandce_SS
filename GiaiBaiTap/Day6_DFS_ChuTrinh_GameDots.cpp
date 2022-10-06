#include <iostream>
 
using namespace std;
 
char a[50][50];
int b[50][50],c[50][50];
int n,m,i,j,index;
bool flag;
 
bool valid(int i,int j){ return i>=0 && i<n && j>=0 && j<m ? 1 : 0;}
 
void dfs(int i,int j,int x,int y){
     int dx[]={1,-1,0,0};
     int dy[]={0,0,1,-1};
     
     for(int l=0;l<4;l++){
      int x1=i+dx[l],y1=j+dy[l];
       if(valid(x1,y1) && a[i][j]==a[x1][y1])
        if(b[x1][y1]!=index)
         b[x1][y1]=index,dfs(x1,y1,i,j);
        else if(c[x1][y1]!=index && x1!=x && y1!=y)
         flag=1;
       }
     c[i][j]=index;  
    }
 
int main(){
    cin>>n>>m;
    
    for(i=0;i<n;i++){
      for(j=0;j<m;j++)
        cin>>a[i][j];
    }
    
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
         if(flag){
           cout<<"Yes";
           return 0;
         }
         
         b[i][j]=index=j+i*m;
         dfs(i,j,i,j);
      }
    }
   
    cout<<"No";
    return 0;
}

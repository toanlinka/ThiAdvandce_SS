#include <stdio.h>

typedef struct{
	int x, y;
}Point;
const int MAX = 100000;
typedef struct
{
	int front, real, count;
	Point data[MAX];
}Queue;
void initQueue(Queue &Q)
{
	Q.front = Q.count = 0;
	Q.real = -1;
}
int isEmptyQueue(Queue &Q)
{
	if(!Q.count)return 1;
	return 0;
}
void Push(Queue &Q, Point value)
{
	Q.data[(++Q.real)%MAX] = value;
	Q.count++;
}
Point Pop(Queue &Q)
{
	Point value = Q.data[Q.front];
	Q.front = (Q.front++)%MAX;
	Q.count--;
	return value;
}
char matrix[1002][1002];
int visited[1002][1002];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int row, col, traps;
Queue cats;

Point get_next_point(int x, int y)
{
	Point value;
	value.x = x;
	value.y = y;
	matrix[x][y]=='N'?value.x--:matrix[x][y]=='S'?value.x++:matrix[x][y]=='W'?value.y--:value.y++;
	return value;
}

void BFS(int x, int y)
{
	initQueue(cats);
	Point value;
	traps++;
	value.x = x; value.y = y;
	visited[x][y] = 1;
	Push(cats, value);
	while(!isEmptyQueue(cats))
	{
		value = Pop(cats);
		for(int i=0; i<4; i++)
		{
			int tempx = value.x + dx[i];
			int tempy = value.y + dy[i];
			// nhung thang vi pham toa do k xet
			if(tempx<0||tempx>=row||tempy<0||tempy>=col||visited[tempx][tempy]!=0)continue;
			Point temp = get_next_point(tempx, tempy);
			if(temp.x!=value.x||temp.y!=value.y)continue;
			visited[tempx][tempy] = 1;
			temp.x = tempx; temp.y = tempy;
			Push(cats, temp);
		}
		Point nextP = get_next_point(value.x, value.y);// tim thang tiep theo, neu chua tham cho no vao Queue
			if(nextP.x>=0&&nextP.x<row&&nextP.y>=0&&nextP.y<col&&visited[nextP.x][nextP.y]==0)
			{
				visited[nextP.x][nextP.y] = 1;
				Push(cats,nextP);
			}
	}
}

int main()
{
	scanf("%d %d", &row, &col);
	for(int i=0; i<row; i++)
		scanf("%s", &matrix[i]);
	traps = 0;
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
		{
			if(visited[i][j]==0)BFS(i,j);
		}
	printf("%d\n", traps);
	return 0;
}

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector < vector<pair<int, int> > > F;
int visited[50001];
int result = 0, check_index = 0;
void DFS(int node, int dis)
{
	if(result<dis)
	{
			result = dis; check_index = node;
	}
	visited[node] = 1;
	for(int i=0; i<F[node].size(); i++)
	{
		if(visited[F[node][i].first]==0)
			DFS(F[node][i].first, dis+F[node][i].second);
	}
	visited[node] = 0;	
}
int main()
{
	int nTestCase;
	scanf("%d", &nTestCase);
	for(int test=0; test<nTestCase; test++)
	{
		int nCity, start, end, dis;
		scanf("%d", &nCity);
		F = vector < vector<pair<int, int> > >(nCity + 1);
		for(int st=1; st<nCity; st++)
		{
			scanf("%d %d %d", &start, &end, &dis);
			F[start].push_back(make_pair(end, dis));
			F[end].push_back(make_pair(start, dis));
		}
		result = 0; check_index = 0;
		DFS(1,0);
		result = 0;
		DFS(check_index, 0);
		printf("%d\n", result);
	}
	return 0;
}

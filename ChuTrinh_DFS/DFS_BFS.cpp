/*Chu trinh tren do thi vo huong*/

#include <bits/stdc++.h>
using namespace std;

int n, m, st, en;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void inp(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}


bool DFS(int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			parent[v] = u;
			if(DFS(v)) return true;
		}
		else if(v != parent[u]){
			return true;
		}
	}
	return false;
}

bool BFS(int u){
	visited[u] = true;
	queue<int> q;
	q.push(u);
	while(! q.empty()){
		int v = q.front(); q.pop();
		for(int x : adj[v]){
			if(!visited[x]){
				q.push(x); visited[x] = true; parent[x] = v;
			}
			else if(x != parent[v]){
				return true;
			}
		}
	}
	return false;
}


int main(){
	inp();
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			if(DFS(i)){
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}


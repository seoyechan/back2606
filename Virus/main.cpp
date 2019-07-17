#include <stdio.h>
#include <vector>
#include <queue>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

int computer, network;


typedef struct pos
{
	int start, end;
};

int compare(pos x, pos y)
{
	return x.start > y.start;
}

int main()
{
	pos network_inf[5000] = { 0, };
	int network_chek_arr[101] = { 0, };
	vector <int> vec_arr[5000];
	

	scanf("%d %d", &computer, &network);

	for (int i = 0; i < network; i++){
		vec_arr[0].push_back(0);
		scanf("%d %d", &network_inf[i].start, &network_inf[i].end);
	}
	
	for (int i = 0; i < network; i++){
		vec_arr[network_inf[i].start].push_back(network_inf[i].end);
	}
	int cur = 0;
	int next = 0;
	int virus_com = 1;
	queue <int> bfs_q;
	bfs_q.push(1);
	network_chek_arr[1] = 1;

	while (!bfs_q.empty())
	{
		cur = bfs_q.front();
		bfs_q.pop();

		for (int i = 0; i < vec_arr[cur].size(); i++){
			next = vec_arr[cur][i];
			if (!network_chek_arr[next]){
				bfs_q.push(next);
				network_chek_arr[next] = 1;
				virus_com++;
			}
		}
	}
	


	
	return 0;
}
#include <stdio.h>
#include <vector>
#include <queue>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

int computer, network;


typedef struct pos
{
	int node;
};


int main()
{
	int start, end = 0;
	int network_chek_arr[101] = { 0, };
	vector <pos> computer_v[101];

	scanf("%d %d", &computer, &network);

	for (int i = 0; i < network; i++){
		scanf("%d %d", &start, &end);
		computer_v[start].push_back({ end });
		computer_v[end].push_back({ start });
	}

	int cur = 0;
	int virus_com = 0;
	queue <int> bfs_q;
	bfs_q.push(1);
	network_chek_arr[1] = 1;

	while (!bfs_q.empty())
	{
		cur = bfs_q.front();
		bfs_q.pop();

		for (int i = 0; i < computer_v[cur].size(); i++){
			if (!network_chek_arr[computer_v[cur][i].node]){
				network_chek_arr[computer_v[cur][i].node] = 1;
				bfs_q.push(computer_v[cur][i].node);
				virus_com++;
			}
		}
	}

	printf("%d\n", virus_com);

	return 0;
}
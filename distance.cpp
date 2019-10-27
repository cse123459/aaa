// distance vector
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int dist[6];
	int from[6];
};

int main()
{
	int n, i, j, k;
	cout << "Enter the number of nodes: ";
	cin >> n;
	
	node DVR[n]; // distance vector routing
	
	cout << "Enter the cost matrix" << endl;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			int temp_cost;
			cin >> temp_cost;
			
			DVR[i].dist[j] = temp_cost;
			DVR[i].from[j] = j;
		}
	}
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			for(k = 0; k < n; k++)
			{
				if(DVR[i].dist[j] > DVR[i].dist[k] + DVR[k].dist[j])
				{
					DVR[i].dist[j] = DVR[j].dist[i] = DVR[i].dist[k] + DVR[k].dist[j];
					DVR[i].from[j] = DVR[j].from[i] = k;
				}
			}
		}
	}
	
	cout << endl << "Output of distance vector algorithm "<< endl; 
	
	for(i = 0; i < n; i++)
	{
		cout << "\nFor Router " << i+1 << endl;
		for(j = 0; j < n; j++)
			cout << "node " << j+1 << " via " << DVR[i].from[j]+1 << " Distance " << DVR[i].dist[j] << endl;
	}
	
	return 0;
}

#include <iostream>
#include <utility>
using namespace std;

bool visitedNODES[5] = { false };

void DFS_ALGO (int i, int adjacency_matrix[5][5], int n)
{
  for (int j = 0; j < n; j++)
    {
      if (adjacency_matrix[i][j] == 1)
	{
	  if (visitedNODES[j] == true)
	    continue;
	  visitedNODES[j] = true;
      char t = 'A' + j;
	  cout << t << "->";
	  DFS_ALGO (j, adjacency_matrix, 5);
	}
    }
}

bool isConnected (int n, int adjacency_matrix[5][5])
{
  visitedNODES[0] = true;
  cout << "A" << "->";
  DFS_ALGO (0, adjacency_matrix, n);
  for (int i = 0; i < 5; i++)
    {
      if (visitedNODES[i] == false)
	return false;
    }
  return true;
}
int main ()
{
  int adjacency_matrix[5][5] = 
  {
    {0, 1, 1, 0, 1},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {1, 1, 0, 0, 0}
  };
  if(isConnected (5, adjacency_matrix) )
  cout<<"\nConnected\n" ;
  else
  cout<<"\nDisconnected\n";
  return 0;
}

#include <iostream>
#include <unordered_set>
#include <queue>
#include <utility>
using namespace std;
unordered_set < int >visitedNODES;
void BFS_ALGO (int n, int adjacency_matrix[5][5], int STARTINGnode)
{
  queue < int >q;
  q.push (STARTINGnode);
  cout << STARTINGnode << "->";
  visitedNODES.insert (STARTINGnode);
  while (q.size () != 0)
    {
      int i = q.front ();
      q.pop ();
      for (int start = 0; start < 5; start++)
	{
	  if (adjacency_matrix[i][start] == 1)
	    {
	      if (visitedNODES.find (start) != visitedNODES.end ())
		continue;
	      q.push (start);
	      cout << start << "->";
	      visitedNODES.insert (start);
	    }
	}
    }
}

int main ()
{
  int adjacency_matrix[5][5] = 
  {
    {0, 1, 1, 0, 0},
    {0, 0, 1, 1, 1},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0}
  };
  int STARTINGnode;
  cout<<"ENTER the STARTING NODE : ";
  cin >> STARTINGnode;
  BFS_ALGO (5, adjacency_matrix, STARTINGnode);
  return 0;
}

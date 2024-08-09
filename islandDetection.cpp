// island detection problem...
// in the given N * M array, ground element is represented as 1 while water element is represented as 0
// find out the sizes of islands in the array

// an acquaintance asked me this problem and here goes my response to it.
// written by H.H. Yoo


#include <iostream>
#include <vector>

#define H_SIZE	10
#define V_SIZE	10

using namespace std;

void GridSearch(int grd[][H_SIZE], int det[][H_SIZE], int x, int y, int* size);

int main(void)
{
	// input
	int grid[V_SIZE][H_SIZE] = {
		{1, 1, 0, 0, 0, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 0, 1, 1, 1, 0, 1},
		{0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
		{0, 1, 1, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
		{0, 1, 1, 0, 0, 0, 1, 1, 1, 0},
		{0, 1, 1, 1, 0, 0, 1, 1, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0}
	};

	int visitInfo[V_SIZE][H_SIZE];

	for (int i = 0; i < V_SIZE; ++i)
	{
		for (int j = 0; j < H_SIZE; ++j)
		{
			visitInfo[i][j] = 0;
		}
	}
	
	int size;

	vector<int> sizes;
	for (int i = 0; i < V_SIZE; ++i)
	{
		for (int j = 0; j < H_SIZE; ++j)
		{
			size = 0;
			GridSearch(grid, visitInfo, j, i, &size);
			if (size != 0)
			{
				sizes.push_back(size);
			}
		}
	}

	cout << "there are " << sizes.size() << " islands in the given array." << endl;
	cout << "the sizes of islands : " << endl;
	for (auto it = sizes.begin(); it != sizes.end(); ++it)
	{
		cout << *it << ", ";
	}
	cout << endl;


	return 0;
}

void GridSearch(int grd[][H_SIZE], int det[][H_SIZE], int x, int y, int* size)
{
	// escape condition
	if (x < 0 || x >= H_SIZE || y < 0 || y >= V_SIZE)	// outside of the boundary
	{
		return;
	}
	if (det[y][x] == 1)		// do not consider the cell having already been visited...
	{
		return;			
	}
	else
	{
		det[y][x] = 1;		// marks the current visit info. status as 'visited'
	}

	if (grd[y][x] == 0)	// if the current cell is in the water
	{
		return;
	}

	(*size)++;

	// designate the neighbor cells of the current cell
	GridSearch(grd, det, x - 1, y, size);			// left cell
	GridSearch(grd, det, x + 1, y, size);			// right cell
	GridSearch(grd, det, x, y - 1, size);			// upper cell
	GridSearch(grd, det, x, y + 1, size);			// lower cell
}



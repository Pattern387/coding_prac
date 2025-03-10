#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Cow
{

	char direction;
	int x, y, grassAte;
	bool stop;
};

int main()
{
	int cow = 0;
	cin >> cow;
	vector<Cow> cows(cow);
	int maxX = 0, maxY = 0;

	for (int i = 0; i < cow; i++)
	{
		cows[i].grassAte = 0;
		cows[i].stop = false;
		cin >> cows[i].direction >> cows[i].x >> cows[i].y;
		maxX = max(maxX, cows[i].x);
		maxY = max(maxY, cows[i].y);
	}

	// Initialize the map with default size maxX+1 and maxY+1
	vector<vector<int>> mapGrass(maxX, vector<int>(maxY, 0));

	// Default everything in the map to 0
	for (int x = 0; x <= maxX - 1; x++)
	{
		for (int y = 0; y <= maxY - 1; y++)
		{
			mapGrass[x][y] = 0;
		}
	}
	int maxL;
	maxL = max(maxX, maxY);
	int count = 1;
	while (1)
	{

		for (int i = 0; i < cow; i++)
		{
			if (cows[i].stop == false)
			{
				if (cows[i].direction == 'E')
				{
					cows[i].x++;
				}
				if (cows[i].direction == 'W')
				{
					cows[i].x--;
				}
				if (cows[i].direction == 'S')
				{
					cows[i].y--;
				}
				if (cows[i].direction == 'N')
				{
					cows[i].y++;
				}

				if (i >= 0 && i < cows.size() &&
					(cows[i].x - 1) >= 0 && (cows[i].x - 1) < mapGrass.size() &&
					(cows[i].y - 1) >= 0 && (cows[i].y - 1) < mapGrass[0].size() &&
					mapGrass[cows[i].x - 1][cows[i].y - 1] == 0)
				{
					mapGrass[cows[i].x - 1][cows[i].y - 1] = count;
					cows[i].grassAte++;
				}
				else if (i >= 0 && i < cows.size() &&
						 (cows[i].x - 1) >= 0 && (cows[i].x - 1) < mapGrass.size() &&
						 (cows[i].y - 1) >= 0 && (cows[i].y - 1) < mapGrass[0].size() &&
						 mapGrass[cows[i].x - 1][cows[i].y - 1] == count)
				{
					mapGrass[cows[i].x - 1][cows[i].y - 1] = count;
					cows[i].grassAte++;
				}
				else if (i >= 0 && i < cows.size() &&
						 (cows[i].x - 1) >= 0 && (cows[i].x - 1) < mapGrass.size() &&
						 (cows[i].y - 1) >= 0 && (cows[i].y - 1) < mapGrass[0].size() &&
						 mapGrass[cows[i].x - 1][cows[i].y - 1] != count)
				{
					cows[i].stop = true;
				}
				else
				{
					cows[i].stop = true;
					cows[i].grassAte = -1;
				}
			}
			else
			{
				continue;
			}
		}

		if (count == maxL + 1)
		{
			break;
		}
		count++;
	}

	for (int i = 0; i <= cow - 1; i++)
	{
		if (cows[i].grassAte != -1)
		{
			cout << cows[i].grassAte << endl;
		}
		else
		{
			cout << "Infinity" << endl;
		}
	}

	return 0;
}

				else if (i >= 0 && i < cows.size() &&
						 (cows[i].x - 1) != 0 && (cows[i].x - 1) < mapGrass.size() &&
						 (cows[i].y - 1) != 0 && (cows[i].y - 1) < mapGrass[0].size())
				{
					if (cows[i].x == 0 || cows[i].y == 0)
					{
						mapGrass[cows[i].x - 1][cows[i].y - 1] = count;
						cows[i].grassAte++;
					}
				}
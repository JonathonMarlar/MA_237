#include <iostream>
using namespace std;

int addMod(int a, int b, int mod);

int main(int argc, char** argv)
{
	int move_set[9][10] = {
		{1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
		{0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
		{1, 0, 0, 1, 1, 0, 1, 0, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
		{0, 0, 1, 0, 1, 1, 0, 0, 1, 1},
		{0, 0, 0, 1, 0, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 1, 0, 1, 1, 0}
	};

	// row echelon form
	for (int i = 0; i < 9; i++)
	{
		if (move_set[i][i] > 0)
		{
			for (int j = i + 1; j < 9; j++)
			{
				if (move_set[j][i] > 0)
				{
					// add rows
					for (int k = i; k < 10; k++)
					{
						move_set[j][k] = addMod(move_set[i][k], move_set[j][k], 2);
					}
				}
			}
		}
		else
		{
			for (int j = i + 1; j < 8; j++)
			{
				if (move_set[j][i] > 0)
				{
					// add rows
					for (int k = i; k < 10; k++)
					{
						move_set[i][k] = addMod(move_set[i][k], move_set[j][k], 2);
					}
					break;
				}
			}
			i--;
		}
	}

	// we have to make it reduced row echelon to give the right answer
	for (int i = 8; i >= 0; i--)
	{
		// um...
		for (int j = i-1; j >= 0; j--)
		{
			if (move_set[j][i] > 0)
			{
				// add rows
				for (int k = 0; k < 10; k++)
				{
					move_set[j][k] = addMod(move_set[i][k], move_set[j][k], 2);
				}
			}
		}
	}

	// pretty printer
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << move_set[i][j] << " ";
		}
		cout << "\n";
	}

	// system("PAUSE");
	return 0;
}

int addMod(int a, int b, int mod)
{
	return (a + b) % mod;
}
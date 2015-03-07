#include <iostream>
using namespace std;

const int MODULO = 2;

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
		// if the current diagonal is a 1, great! We need it to add to the other
		// rows to make them 0
		if (move_set[i][i] > 0)
		{
			// j will look through each row, while i represents the diagonal's column
			for (int j = i + 1; j < 9; j++)
			{
				// if j isn't 0, we gotta make it 0.
				if (move_set[j][i] > 0)
				{
					// add the i row to the j row to make it 0
					for (int k = 0; k < 10; k++)
					{
						move_set[j][k] = addMod(move_set[i][k], move_set[j][k], MODULO);
					}
				}
			}
		}
		else
		{
			// if the diagonal is 0, we gotta make it 1 somehow.
			// j will start from i, the diagonoal, and move to find a row that has 1.
			for (int j = i + 1; j < 8; j++)
			{
				if (move_set[j][i] > 0)
				{
					// Once we've found it, add that row to the i row and break outta here!
					for (int k = 0; k < 10; k++)
					{
						move_set[i][k] = addMod(move_set[i][k], move_set[j][k], MODULO);
					}
					break;
				}
			}
			// This is necessary because now the diagonal has a 1. We can't just skip over it.
			i--;
		}
	}

	// we have to make it reduced row echelon to give the right answer
	for (int i = 8; i >= 0; i--)
	{
		// So starting from the bottom-right corner and going up, we'll add in Zn to
		// make everything all 0 to the right of the diagonal 1's
		for (int j = i-1; j >= 0; j--)
		{
			if (move_set[j][i] > 0)
			{
				// We add the i and j rows to zero out that column
				for (int k = 0; k < 10; k++)
				{
					move_set[j][k] = addMod(move_set[i][k], move_set[j][k], MODULO);
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
#include <iostream>
using namespace std;

int addMod(int a, int b, int mod);
void printMatrix(int* moveset);

int main()
{
	int move_set[9][9] = {
		{ 1, 1, 0, 1, 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 0, 1, 1, 0, 0, 0 },
		{ 1, 0, 0, 1, 0, 0, 1, 0, 0 },
		{ 0, 1, 0, 1, 1, 1, 0, 1, 0 },
		{ 0, 0, 1, 0, 0, 1, 0, 0, 1 },
		{ 0, 0, 0, 1, 1, 0, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 1, 1 },
		{ 0, 0, 0, 0, 1, 1, 0, 1, 1 }
	};

	int start_board[9] = { 1, 0, 0, 1, 0, 0, 1, 0, 0 };

	int button_press = 0;

	cout << "Starting Board: \n\n";
	printMatrix(start_board);

	while (button_press >= 0)
	{
		cout << "Enter the button to press: ";
		cin >> button_press;

		for (int i = 0; i < 9; i++)
		{
			start_board[i] = addMod(start_board[i], move_set[button_press-1][i], 2);
		}

		printMatrix(start_board);
	}

	system("PAUSE");
	return 0;
}

int addMod(int a, int b, int mod)
{
	return (a + b) % mod;
}

void printMatrix(int* moveset)
{
	for (int i = 0; i < 9; i++)
	{
		cout << moveset[i] << " ";
		if ((i + 1) % 3 == 0)
			cout << endl;
	}
	cout << endl; // an extra space for cleanliness
}
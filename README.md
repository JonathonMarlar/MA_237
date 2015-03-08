# MA_237

This repository is for software projects associated with MA 237 - Linear Algebra.

## RowEchCal.cpp

RowEchCal.cpp is an implementation of the light square game. It takes the moves that the player can make and stores them as a vector. They are lined up into columns, from square 1 to square 9, into a 9x9 matrix. The tenth column represents the starting point of the game (so we're basically making an augmented matrix). This code will then convert the matrix down to reduced row echelon form. The tenth matrix, once in reduced row echelon form, will show what buttons need to be pressed in order to solve the game.

For instance, say that we ran the code and the last column ended up being:
1
0
0
1
0
1
0
0
0

This tells us that buttons 1, 4, and 6 need to be pushed in order to win the game.

Currently this works in Z of 2, but not Z of 3.

## LightSquareGame.cpp

This is just the game in a playable format. You enter which button you want pressed (1 through 9) and the affected squares will change automagically. This was built to check the answer that RowEchCal.cpp gave.
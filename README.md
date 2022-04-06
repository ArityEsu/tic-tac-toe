# tic-tac-toe
tic-tac-toe game that allows two players ("X" and "O") in C++
Basic: Start out by displaying an empty game board, and ask for the move of player one.
Redraw the board after every move. Alternate moves between player one and player two.
Don't worry about checking for win/lose or keeping score. (max 25 points).

Medium: After each move, determine whether the move is valid.
Was that space already occupied? Also determine whether: player 1 won, player 2 won, nobody won (play can continue) or nobody won and play is over (a "cat's game"). 
Hint: to determine if a game is won, first check 3 rows, then 3 columns, then diagonal (/) then diagonal (\).
There are 8 ways to win. One way to determine a cat's game is to count the number of unused spots remaining on the board. 
If nobody won, and there are no open spots, you have a cat's game. There are many clever ways to determine win/loss/cats status. (max 28 points).

More: After the game ask the user if he/she wants to continue.
Play as many games as the user desires. Keep score of how many games each player won. Provide percentage of win/loss/cats for both players. (max 30 points).

Most: Try using direct screen addressing. 
See textbook, pages 464 - 470 (7ed), pages 484 - 490 (8ed), pages 486 - 492 (9ed), pages 492-498 (10ed).
This uses a screen handle to locate the cursor directly on the screen. This provides much flexibility on drawing output.
Simple character-based games use this technique.
You can also change the color of the character - see page 374 (7ed), page 392 (8ed), page 392 (9ed), page 396 (10ed).
Use an enumerated type to name the colors and avoid "magic numbers".
This makes the code more self-documenting. (max 34 points: 2 extra for direct cursor addressing; 2 extra for using color.).

Further consideration:
Once the game is working, one could enhance the game so the player plays the computer.
The computer can use a random number generator to generate legal moves. Can you make the computer "smarter" than just generating random valid moves?
Consider making the computer play itself, without any input or output during the game. 
The program keeps track of game results.
What if the computer plays itself 10 times? 100 times? 1000 times? 1 billion times? 
How many times did computer player 1 win? Computer player 2? How many cat's games? What does this tell you about the game of tic-tac-toe?
This method is called Monte Carlo simulation, and allows programmers to develop winning game strategies.
Created by AG

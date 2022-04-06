#Created by AG
#include <iostream>
#include <string>

using namespace std;

class Board
{
private:
    char board[3][3];

public:
    Board() {}

    void SetBoard()
    {
        int num = 1;
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                board[row][col] = '0' + num;
                num++;
            }
        }
    }
    void PrintBoard()
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (col < 2)
                {
                    cout << board[row][col] << "  |  ";
                }
                else
                {
                    cout << board[row][col] << endl;
                }
            }
        }
    }
    void PlayerTurn(char num, char Player)
    {

        bool WrongMove = true;
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (board[row][col] == num)
                {
                    board[row][col] = Player;
                    WrongMove = false;
                }
            }
        }
        if (WrongMove == true) { cout << "Sorry, invalid entry. Please enter valid number!\n"; }
    }


    bool CheckResult(char Player, bool winner)
    {
        for (int row = 0; row < 3; row++)
        {
            if (board[row][0] == board[row][1] && board[row][1] == board[row][2])
                winner = true;
        }
        for (int col = 0; col < 3; col++)
        {
            if (board[0][col] == board[1][col] && board[1][col] == board[2][col])
                winner = true;
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            winner = true;
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            winner = true;
        }
        if (winner == true)
        {
            cout << "CONGRATULATIONS PLAYER " << Player << " YOU HAVE WON THE GAME!\n" << endl;
        }
        return winner;
    }
    bool CheckDraw(bool draw)
    {
        int num = 1;
        int counter = 0;

        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (board[row][col] == '0' + num)
                {
                    counter++;
                }
                num++;
            }
        }
        if (counter < 1)
        {
            cout << "No one won\n";
            draw = true;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        return draw;
    }
};

int main()
{
    char doAgain;
    bool winner = false, done = false, draw = false;
    char Player = 'O', num;
    int countX = 0, countO = 0;
    cout << "WELCOME TO Tic-Tac-Toe GAME\n" << endl;

    Board Tic_Tac_Toe_Game;
    Tic_Tac_Toe_Game.SetBoard();
    do {
        if (Player == 'X')
        {
            Player = 'O';
        }
        else
        {
            Player = 'X';
        }
        Tic_Tac_Toe_Game.PrintBoard();
        cout << "\nPlayer \"" << Player << "\" turn: ";
        while (cin >> num and (num >= 1 and num <= 9)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        Tic_Tac_Toe_Game.PlayerTurn(num, Player);
        winner = Tic_Tac_Toe_Game.CheckResult(Player, winner);
        draw = Tic_Tac_Toe_Game.CheckDraw(draw);
        if (winner == true)
        {
            Tic_Tac_Toe_Game.PrintBoard();
            if (Player == 'O') {
                countO++;
            }
            else if (Player == 'X') {
                countX++;

            }
            else {
            }
            cout << "DO you wanna play again!(Y/N) ";
            cin >> doAgain;
            if (doAgain == 'Y' || doAgain == 'y') {
                cout << "New Game starting...\n\n";
                Tic_Tac_Toe_Game.SetBoard();
                winner = false;
            }
            else
                break;
        }
    } while (!done);
    double percentage_of_X{ 0 }, percentage_of_O{}, percentage_of_Tie{};
    percentage_of_X = countO / (countO + countX + percentage_of_Tie) * 100;
    percentage_of_O = countX / (countO + countX + percentage_of_Tie) * 100;
    percentage_of_Tie = draw / (countO + countX + percentage_of_Tie) * 100;
    cout << "Player O have won " << countO << " (" << percentage_of_X << "%)" << endl;
    cout << "Player X have won " << countX << " (" << percentage_of_O << "%)" << endl;
    cout << "TIE " << draw << " (" << percentage_of_Tie << "%)" << endl;

    return 0;
}

/*
WELCOME TO Tic-Tac-Toe GAME

1  |  2  |  3
4  |  5  |  6
7  |  8  |  9

Player "X" turn: 1
X  |  2  |  3
4  |  5  |  6
7  |  8  |  9

Player "O" turn: 2
X  |  O  |  3
4  |  5  |  6
7  |  8  |  9

Player "X" turn: 3
X  |  O  |  X
4  |  5  |  6
7  |  8  |  9

Player "O" turn: 4
X  |  O  |  X
O  |  5  |  6
7  |  8  |  9

Player "X" turn: 5
X  |  O  |  X
O  |  X  |  6
7  |  8  |  9

Player "O" turn: 6
X  |  O  |  X
O  |  X  |  O
7  |  8  |  9

Player "X" turn: 9
CONGRATULATIONS PLAYER X YOU HAVE WON THE GAME!

X  |  O  |  X
O  |  X  |  O
7  |  8  |  X
DO you wanna play again!(Y/N) y
New Game starting...

1  |  2  |  3
4  |  5  |  6
7  |  8  |  9

Player "O" turn: 2
1  |  O  |  3
4  |  5  |  6
7  |  8  |  9

Player "X" turn: 1
X  |  O  |  3
4  |  5  |  6
7  |  8  |  9

Player "O" turn: 5
X  |  O  |  3
4  |  O  |  6
7  |  8  |  9

Player "X" turn: 3
X  |  O  |  X
4  |  O  |  6
7  |  8  |  9

Player "O" turn: 7
X  |  O  |  X
4  |  O  |  6
O  |  8  |  9

Player "X" turn: 7
Sorry, invalid entry. Please enter valid number!
X  |  O  |  X
4  |  O  |  6
O  |  8  |  9

Player "O" turn: 6
X  |  O  |  X
4  |  O  |  O
O  |  8  |  9

Player "X" turn: 9
X  |  O  |  X
4  |  O  |  O
O  |  8  |  X

Player "O" turn: 8
CONGRATULATIONS PLAYER O YOU HAVE WON THE GAME!

X  |  O  |  X
4  |  O  |  O
O  |  O  |  X
DO you wanna play again!(Y/N) y
New Game starting...

1  |  2  |  3
4  |  5  |  6
7  |  8  |  9

Player "X" turn: 1
X  |  2  |  3
4  |  5  |  6
7  |  8  |  9

Player "O" turn: 2
X  |  O  |  3
4  |  5  |  6
7  |  8  |  9

Player "X" turn: 3
X  |  O  |  X
4  |  5  |  6
7  |  8  |  9

Player "O" turn: 4
X  |  O  |  X
O  |  5  |  6
7  |  8  |  9

Player "X" turn: 5
X  |  O  |  X
O  |  X  |  6
7  |  8  |  9

Player "O" turn: 6
X  |  O  |  X
O  |  X  |  O
7  |  8  |  9

Player "X" turn: 9
CONGRATULATIONS PLAYER X YOU HAVE WON THE GAME!

X  |  O  |  X
O  |  X  |  O
7  |  8  |  X
DO you wanna play again!(Y/N) n
Player O have won 1 (33.3333%)
Player X have won 2 (66.6667%)
TIE 0 (0%)

--------------------------------
Process exited after 98.82 seconds with return value 0
Press any key to continue . . .

*/

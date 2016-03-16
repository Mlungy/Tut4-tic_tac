// Tic tac toe game in C++

#include <iostream>
#include <ctime>
#include <cstdlib>
#define X "X"
#define O "O"
using namespace std;

// The structure that controls the functioning of the class tictac
typedef struct player
{
	int *n;
	char *shape;
};

// Tic Tac class definition and declaration
class TicTac
{
public:
	void TTT();
	void first();
	void display();
	bool islegal(int, int);
	void move(int, int, player);
	bool isover();
	bool iswinner();
	void winner();
private:
	player human, pc;
	char *board[3][3];
};

// The contructor
void TicTac::TTT()         //Constructor
{
	//player human,pc;
	human.shape = X;              //By default, human plays first and has X symbol
	*human.n = 1;
	pc.shape = O;
	*pc.n = 2;
	//initialise board
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			board[i][j] = NULL;
		}
	}

}

// Human plays first
void TicTac::first()
{
	int r = rand() % 100 + 1;
	unsigned seed = time(0);

	if (r>50)
	{
		cout << "Human goes first" << endl;
		*human.n = 1;
		*pc.n = 2;
	}
	else if (r <= 50)
	{
		cout << "Computer goes first" << endl;
		*pc.n = 1;
		*human.n = 2;
	}
}

// Display the score
void TicTac::display()
{
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl
		<< "-----------" << endl
		<< " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl
		<< "-----------" << endl
		<< " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}


bool TicTac::islegal(int x, int y)
{
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			if (board[i][j] == X || board[i][j] == O)
			{
				return true;
			}
			else return false;
		}
	}
}

void TicTac::move(int x, int y, player p)
{
	if (islegal(x, y) && p.shape == X)
	{
		board[x][y] = X;
	}
	else if (islegal(x, y) && p.shape == O)
	{
		board[x][y] = O;
	}
}

bool TicTac::isover()
{
	int count = 0;
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			if (board[i][j] != NULL)
			{
				++count;
			}
		}
	}
	if (count == 9)
	{
		return true;
	}
	else return false;
}


bool TicTac::iswinner()
{
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
		return true;
	else if (board[2][0] == board[1][1] && board[2][0] == board[0][2])
		return true;
	else if (board[0][0] == board[0][1] && board[0][0] == board[0][2])
		return true;
	else if (board[1][0] == board[1][1] && board[1][0] == board[1][2])
		return true;
	else if (board[2][0] == board[2][1] && board[2][0] == board[2][2])
		return true;
	else if (board[0][0] == board[1][0] && board[0][0] == board[2][0])
		return true;
	else if (board[0][1] == board[1][1] && board[0][1] == board[2][1])
		return true;
	else if (board[0][2] == board[1][2] && board[0][2] == board[2][2])
		return true;
	else
		return false;
}

void TicTac::winner()
{
	if (iswinner() && human.shape == X)
	{
		cout << "You Won\n";
	}
	else if (iswinner() && pc.shape == O)
	{
		cout << "You Loose, Pc wins\n";
	}
}



int main()
{
	TicTac d;
	//  d.first();
	d.display();
	system("pause");
	return 0;
}

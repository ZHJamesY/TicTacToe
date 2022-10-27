// Player select position at index showned below:
// 1 2 3
// 4 5 6
// 7 8 9
#include <iostream>
#include <stdlib.h>


// Global variables

const char X = 'X';
const char O = 'O';
const int win_methods = 8;
const int SIZE = 3;
char game_board[SIZE][SIZE];


void starting();
bool Update_Game_Board(char position, int *player, int *moves);
void In_Game(int *totalMoves, int *Player);
bool Is_Winning(char *winner);
void display(int *initial_player, int moves, bool won);

int main()
{
    int totalMoves = SIZE * SIZE;
    int Player = -1;
    starting();
    In_Game(&totalMoves, &Player);
    system("pause"); // Avoid exe window terminate immediately
    
    return 0;
}


void starting()
{
    int position = 1;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            game_board[i][j] = '0' + position;
            position++;
        }
    }
}

// 0: X, 1: O, displaying game board
void display(int *initial_player, int moves, bool won)
{
    std::cout<<"\n";
    std::cout<<"------------------------------------------\n";
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cout<<game_board[i][j] <<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
    if(*initial_player == -1)
    {
        char player;
        std::cout<<"Select first player (X or O): ";
        std::cin>>player;
        if(player == 'X' || player == 'x')
        {
            *initial_player = 0;
        }
        else if(player == 'O' || player == 'o')
        {
            *initial_player = 1;
        }
    }
    else if(*initial_player == 0 && moves > 0 && won == false)
    {
        std::cout<<"Player X's term, ";
    }
    else if(*initial_player == 1 && moves > 0 && won == false)
    {
        std::cout<<"Player O's term, ";
    }
}

// Update game board and return true
bool Update_Game_Board(char position, int *player, int *moves)
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(game_board[i][j] == position)
            {
                if(*player == 0)
                {
                    game_board[i][j] = 'X';
                    *player = 1;
                    return true;
                }
                else if(*player == 1)
                {
                    game_board[i][j] = 'O';
                    *player = 0;
                    return true;
                }
            }
        }
    }
    return false;
}

// Game loop
void In_Game(int *totalMoves, int *Player)
{
    bool isWon = false;
    char position = '0';
    char winner = 'X';
    display(Player, *totalMoves, isWon);

    while(!isWon && (*totalMoves > 0))
    {
        std::cout<<"Pick your position: ";
        std::cin>>position;

        // clear screen
        system("CLS"); 
        if(Update_Game_Board(position, Player, totalMoves) == false)
        {
            std::cout<<"\nInvalid position, try again.\n";
        }
        else
        {
            (*totalMoves)--;
        }
        
        if(Is_Winning(&winner))
        {
            isWon = true;
            std::cout<<"\nPlayer " <<winner <<" won!\n";
        }
        display(Player, *totalMoves, isWon);
        
    }
    std::cout<<"\n-------------- GAME OVER -----------------\n";
}

// Win conditions
bool Is_Winning(char *winner)
{
    if(game_board[0][0] == game_board[0][0] && game_board[0][1] == game_board[0][0] && game_board[0][2] == game_board[0][0])
    {
        *winner = game_board[0][0];
        return true;
    }
    else if(game_board[0][0] == game_board[0][0] && game_board[1][1] == game_board[0][0] && game_board[2][2] == game_board[0][0])
    {
        *winner = game_board[0][0];
        return true;
    }
    else if(game_board[0][0] == game_board[0][0] && game_board[1][0] == game_board[0][0] && game_board[2][0] == game_board[0][0])
    {
        *winner = game_board[0][0];
        return true;
    }
    else if(game_board[0][1] == game_board[0][1] && game_board[1][1] == game_board[0][1] && game_board[2][1] == game_board[0][1])
    {
        *winner = game_board[0][1];
        return true;
    }
    else if(game_board[0][2] == game_board[0][2] && game_board[1][2] == game_board[0][2] && game_board[2][2] == game_board[0][2])
    {
        *winner = game_board[0][2];
        return true;
    }
    else if(game_board[0][2] == game_board[0][2] && game_board[1][1] == game_board[0][2] && game_board[2][0] == game_board[0][2])
    {
        *winner = game_board[0][2];
        return true;
    }
    else if(game_board[1][0] == game_board[1][0] && game_board[1][1] == game_board[1][0] && game_board[1][2] == game_board[1][0])
    {
        *winner = game_board[1][0];
        return true;
    }
    else if(game_board[2][0] == game_board[2][0] && game_board[2][1] == game_board[2][0] && game_board[2][2] == game_board[2][0])
    {
        *winner = game_board[2][0];
        return true;
    }
    return false;
}
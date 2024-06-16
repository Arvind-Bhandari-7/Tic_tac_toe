#include <iostream> 
#include <limits> // Required for numeric_limits
using namespace std; 
  
// Function to draw the Tic-Tac-Toe board 
void drawBoard(char board[3][3]) 
{ 
    cout << "-------------\n"; 
    for (int i = 0; i < 3; i++) { 
        cout << "| "; 
        for (int j = 0; j < 3; j++) { 
            cout << board[i][j] << " | "; 
        } 
        cout << "\n-------------\n"; 
    } 
} 
  
// Function to check for a win 
bool checkWin(char board[3][3], char player) 
{ 
    // Check rows, columns, and diagonals 
    for (int i = 0; i < 3; i++) { 
        if (board[i][0] == player && board[i][1] == player 
            && board[i][2] == player) 
            return true; 
        if (board[0][i] == player && board[1][i] == player 
            && board[2][i] == player) 
            return true; 
    } 
    if (board[0][0] == player && board[1][1] == player 
        && board[2][2] == player) 
        return true; 
    if (board[0][2] == player && board[1][1] == player 
        && board[2][0] == player) 
        return true; 
    return false; 
} 
  
int main() 
{ 
    // Initialize the board and players 
    char board[3][3] = { { ' ', ' ', ' ' }, 
                         { ' ', ' ', ' ' }, 
                         { ' ', ' ', ' ' } }; 
    char player = 'X'; 
    int row, col; 
    int turn = 0; // Declare and initialize turn here 
  
    cout << "Welcome to Tic-Tac-Toe!\n"; 
  
    // Game loop 
    bool gameOn = true; // Add a flag to track game status
    while (gameOn) { 
        // Draw the board 
        drawBoard(board); 
  
        // Prompt for valid input 
        while (true) { 
            cout << "Player " << player 
                 << ", enter row (0-2) and column (0-2): "; 
            if (!(cin >> row >> col) || row < 0 || row > 2 
                || col < 0 || col > 2) { 
                cout << "Invalid input. Please enter valid row and column numbers.\n";
                // Clear input buffer to prevent infinite loop
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (board[row][col] != ' ') { 
                cout << "That cell is already occupied. Please choose another.\n"; 
            } 
            else { 
                break; // Valid input, exit the loop. 
            } 
        } 
  
        // Make the move 
        board[row][col] = player; 
  
        // Check for a win after making a move 
        if (checkWin(board, player)) { 
            drawBoard(board); 
            cout << "Player " << player << " wins!\n"; 
            gameOn = false; // Exit the loop after a win. 
        } 
        else if (++turn == 9) { // Increment turn count and check for draw
            drawBoard(board);
            cout << "It's a draw!\n";
            gameOn = false;
        }
        else {
            // Switch to the other player 
            player = (player == 'X') ? 'O' : 'X'; 
        }
    } 
  
    return 0; 
}
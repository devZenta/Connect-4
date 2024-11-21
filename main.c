#include <stdio.h>

int checkNull(char gameBoard[6][7]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (gameBoard[i][j] == '.') {
                return 0;
            }
        }
    }
    return 1;
}

int victoryCheck(char gameBoard[6][7], char player) {

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (gameBoard[i][j] == player &&
                gameBoard[i][j + 1] == player &&
                gameBoard[i][j + 2] == player &&
                gameBoard[i][j + 3] == player) {
                return 1;
                }
        }
    }

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameBoard[j][i] == player &&
                gameBoard[j + 1][i] == player &&
                gameBoard[j + 2][i] == player &&
                gameBoard[j + 3][i] == player) {
                return 1;
                }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (gameBoard[i][j] == player &&
                gameBoard[i + 1][j + 1] == player &&
                gameBoard[i + 2][j + 2] == player &&
                gameBoard[i + 3][j + 3] == player) {
                return 1;
                }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 3; j < 7; j++) {
            if (gameBoard[i][j] == player &&
                gameBoard[i + 1][j - 1] == player &&
                gameBoard[i + 2][j - 2] == player &&
                gameBoard[i + 3][j - 3] == player) {
                return 1;
                }
        }
    }

    return 0;
}

void displayGameBoard(char tab[6][7]) {
    printf("\n");

    for (int i = 0; i < 6; i++) {
        printf(" |");
        for (int j = 0; j < 7; j++) {
            printf(" %c |", tab[i][j]);
        }
        printf("\n");

        printf("  ");
        for (int j = 0; j < 7; j++) {
            printf("--- ");
        }
        printf("\n");
    }
}

void play(char gameBoard[6][7], char users[2][50]) {
    int player = 0;
    int column;
    char currentPlayer;

    while (1) {

        currentPlayer = (player == 0) ? '0' : 'X';

        printf("-------------------------------------------------");
        printf("\n");
        printf("              %s it's your turn", users[player]);
        printf("\n");
        printf("-------------------------------------------------");
        printf("\n");
        displayGameBoard(gameBoard);

        while (1) {

            printf("which column ");
            printf("\n");
            scanf("%d", &column);
            printf("\n");

            if (column < 1 || column > 7) {
                printf("Invalid position! Please choose a line and column between 1 and 7.\n");
                continue;
            }

            column--;

            int line = 5;
            while (line >= 0 && (gameBoard[line][column] == '0' || gameBoard[line][column] == 'X')) {
                line--;
            }

            if (line < 0) {
                printf("This column is full! Try another column.\n");
                continue;
            }

            gameBoard[line][column] = currentPlayer;
            break;
        }

        if (victoryCheck(gameBoard, currentPlayer)) {
            displayGameBoard(gameBoard);
            printf("Congratulations %s, you won!\n", users[player]);
            break;
        }

        if (checkNull(gameBoard)) {
            displayGameBoard(gameBoard);
            printf("It's a null! No winner this time.\n");
            break;
        }

        player = (player == 0) ? 1 : 0;
    }
}

int main(void) {

    int playAgain = 1;

    while (playAgain) {

        printf("----------------- Configuration -----------------");
        printf("\n");

        char gameBoard[6][7];

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                gameBoard[i][j] = '.';
            }
        }

        int nbPlayers = 2;

        char usernames[nbPlayers][50];

        for (int i = 0; i < nbPlayers; i++) {
            printf("Username of player %d ?", i + 1);
            printf("\n");
            scanf("%49s", usernames[i]);
        }

        printf("\n");
        printf("------------------ Game Start -------------------");

        printf("\n");
        displayGameBoard(gameBoard);
        play(gameBoard, usernames);

        printf("Do you want to play again? (1 = Yes, 0 = No): ");
        scanf("%d", &playAgain);

    }


    return 0;
}
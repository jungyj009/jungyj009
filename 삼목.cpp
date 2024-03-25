
#include <iostream>

using namespace std;

// 빙고판을 초기화
void resetBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = '-';
        }
    }
}

// 빙고판을 출력
void printBoard(const char board[3][3]) {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// 플레이어가 선택한 위치에 'o' 또는 'x'를 입력
bool placeMark(char board[3][3], int row, int col, char mark) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-') {
        return false;
    }
    board[row][col] = mark;
    return true;
}

// 빙고 게임의 승자를 확인
char checkWinner(const char board[3][3]) {
    // 가로, 세로, 대각선으로 'o' 또는 'x'가 연속으로 있는지 확인
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // 아직 승자가 없는 경우
    return '-';
}

int main() {
    char board[3][3];
    resetBoard(board);

    char currentPlayer = 'o';
    bool gameFinished = false;

    while (!gameFinished) {
        printBoard(board);

        // 현재 플레이어가 입력할 위치 받기
        int row, col;
        cout << "사용자 " << currentPlayer << " 원하는 좌표를 입력하세요(ex 2 1) : ";
        cin >> row >> col;

        // 입력한 위치에 표시하기
        if (placeMark(board, row, col, currentPlayer)) {
            // 승자 확인하기
            char winner = checkWinner(board);
            if (winner != '-') {
                cout << "사용자1 " << winner << " 승리!" << endl;
                gameFinished = true;
            }
            else {
                // 플레이어 교체
                currentPlayer = (currentPlayer == 'o') ? 'x' : 'o';
            }
        }
        else {
            cout << "다시 입력하세요" << endl;
        }
    }

    return 0;
}

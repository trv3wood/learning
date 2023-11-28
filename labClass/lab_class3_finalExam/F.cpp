/*在中国象棋中，炮是按照一定规则进行移动的。对于一个给定的位置，炮每次移动之后可以到达的位置如下图所示
炮在棋盘上移动遵循以下三个原则
1. 正常情况下，只能沿着上下左右四个方向直线移动，遇到己方或者对方棋子就停止
2. 当吃对方棋子时，己方和对方的棋子中间必须是沿着上下左右只间隔1个棋子 （间隔的棋子可以是己方或者对方的）
3. 不能吃自家棋子

输入
输入炮棋子位置x,y
再输入10*9的棋盘数组，用空格隔开，其中0表示空白，1表示本方棋子，2表示对方棋子
输出
当前情况下，炮棋子能移动到的位置用3标记，输出棋盘，注意输出时不需要以空格分隔
样例输入 Copy
3 4
0 0 2 2 2 0 0 0 0
0 0 0 0 2 2 0 0 0
0 0 0 0 2 0 0 0 0
0 0 0 0 1 0 0 1 0
0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
1 0 0 1 0 1 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0
样例输出 Copy
002220000
000032000
000020000
333313310
000030000
001030000
000030000
100131000
000030000
000010000*/
#include <bits/stdc++.h>
using namespace std;
int x, y = 0;
bool withinRange(int x, int y) {
    return x >= 0 && x < 10 && y >= 0 && y < 9;
}
int main() {
    vector<vector<int>> board(10, vector<int>(9, 0));
    
    while(cin >> x >> y) {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 9; j++) {
                cin >> board[i][j];
            }
        }
        int moveX = x;
        int moveY = y;
        //占空位
        // up
        while(withinRange(moveX - 1, y)) {
            moveX--;
            if(board[moveX][moveY] == 0) {
                board[moveX][moveY] = 3;
            } else if(board[moveX][moveY] == 1 || board[moveX][moveY] == 2) {
                break;
            }
        }
        //down
        moveX = x;
        moveY = y;
        while(withinRange(moveX + 1, y)) {
            moveX++;
            if(board[moveX][moveY] == 0) {
                board[moveX][moveY] = 3;
            } else if(board[moveX][moveY] == 1 || board[moveX][moveY] == 2) {
                break;
            }
        }
        //left
        moveX = x;
        moveY = y;
        while(withinRange(x, moveY - 1)) {
            moveY--;
            if(board[moveX][moveY] == 0) {
                board[moveX][moveY] = 3;
            } else if(board[moveX][moveY] == 1 || board[moveX][moveY] == 2) {
                break;
            }
        }
        //right
        moveX = x;
        moveY = y;
        while(withinRange(x, moveY + 1)) {
            moveY++;
            if(board[moveX][moveY] == 0) {
                board[moveX][moveY] = 3;
            } else if(board[moveX][moveY] == 1 || board[moveX][moveY] == 2) {
                break;
            }
        }
        //吃子
        //遍历所在行
        for(int i = 0; i < 9; i++) {
            if(board[x][i] == 2) {
                //只间隔一个棋子 1或2
                if(i < y) {
                    int count = 0;
                    for(int j = i + 1; j < y; j++) {
                        if(board[x][j] != 0) {
                            count++;
                        }
                    }
                    if(count == 1) {
                        board[x][i] = 3;
                    }
                } else {
                    int count = 0;
                    for(int j = y + 1; j < i; j++) {
                        if(board[x][j] != 0) {
                            count++;
                        }
                    }
                    if(count == 1) {
                        board[x][i] = 3;
                    }
                }
            }
        }
        //遍历所在列
        for(int i = 0; i < 10; i++) {
            if(board[i][y] == 2) {
                //只间隔一个棋子 1或2
                if(i < x) {
                    int count = 0;
                    for(int j = i + 1; j < x; j++) {
                        if(board[j][y] != 0) {
                            count++;
                        }
                    }
                    if(count == 1) {
                        board[i][y] = 3;
                    }
                } else {
                    int count = 0;
                    for(int j = x + 1; j < i; j++) {
                        if(board[j][y] != 0) {
                            count++;
                        }
                    }
                    if(count == 1) {
                        board[i][y] = 3;
                    }
                }
            }
        }
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 9; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }
    }

}       
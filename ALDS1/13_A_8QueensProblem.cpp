#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Queen {
private:
    const int size = 8;
    vector<bool> colFlags; // 列方向のクイーン配置フラグ
    vector<bool> diaPosFlags; // 斜め方向のクイーン配置フラグ
    vector<bool> diaNegFlags; // 斜め方向のクイーン配置フラグ
    vector<int> queenPos; // それぞれの行のクイーンの配置位置

public:
    Queen(int size)
        : size(size), colFlags(size, false),
          diaPosFlags(size, false), diaNegFlags(size, false), queenPos(size, -1) {}

    // 8クイーン問題に従って、クイーンを配置する
    bool recursePutQueen(int y = 0) {
        if (y == size) {
            return true;
        }
        if (queenPos[y] != -1) {
            return recursePutQueen(y + 1);
        }

        for (int x = 0; x < size; x++) {
            if (colFlags[x] || diaPosFlags[y + x] || diaNegFlags[y - x + size - 1]) continue;
            // クイーンを配置
            putQueen(x, y);
            if (recursePutQueen(y + 1)) return true;
            removeQueen(x, y);
        }

        return false;
    }

    // クイーンを配置
    void putQueen(int x, int y) {
        queenPos[y] = x;
        colFlags[x] = diaPosFlags[y + x] = diaNegFlags[y - x + size - 1] = true;
    }

    // 配置してあるクイーンを削除
    bool removeQueen(int x, int y) {
        if (queenPos[y] != x) return false;
        queenPos[y] = -1;
        colFlags[x] = diaPosFlags[y + x] = diaNegFlags[y - x + size - 1] = false;

        return true;
    }

    // クイーンの配置位置を出力
    void printBoard() {
        for (auto p = queenPos.begin(); p != queenPos.end(); p++) {
            if (*p == -1) {
                for (int i = 0; i < size; i++) cout << ".";
                cout << endl;
                continue;
            }
            for (int i = 0; i < *p; i++) cout << ".";
            cout << "Q";
            for (int i = *p + 1; i < size; i++) cout << ".";
            cout << endl;
        }
    }

    // クイーンを配置し、結果を出力
    void run() {
        if (recursePutQueen(0)) {
            printBoard();
        } else {
            cout << "failed" << endl;
        }
    }
};

int main() {
    auto queen = Queen(8);

    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        int x, y;
        cin >> y >> x;
        queen.putQueen(x, y);
    }

    queen.run();
}
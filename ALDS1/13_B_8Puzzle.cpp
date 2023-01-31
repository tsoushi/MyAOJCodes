#include <vector>
#include <iostream>
#include <map>
#include <queue>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::map;
using std::queue;
using std::swap;

#define X_SIZE 3
#define Y_SIZE 3
#define SIZE (X_SIZE * Y_SIZE)

struct Pos {
    int x;
    int y;

    int toFlat() {
        return x + X_SIZE * y;
    }

    Pos operator + (const Pos &right) const {
        return Pos(x + right.x, y + right.y);
    }

    Pos(int x, int y) : x(x), y(y) {}
    Pos(int flat)
        : x(flat % X_SIZE), y(flat / X_SIZE) {}
};

struct Puzzle {
    int field[SIZE];
    int stepCount = 0;

    Pos getSpacePos() {
        for (int i = 0; i < SIZE; i++) {
            if (field[i] == 0) return Pos(i);
        }
        return Pos(-1, -1);
    }

    bool operator < (const Puzzle &right) const {
        for (int i = 0; i < SIZE; i++) {
            if (field[i] == right.field[i]) continue;
            return field[i] < right.field[i];
        }

        return false;
    }

    bool isCorrect() {
        for (int i = 0; i < SIZE; i++) {
            if (field[i] != (i + 1) % SIZE) return false;
        }

        return true;
    }

    void print() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << field[i * 3 + j] << " ";
            }
            cout << endl;
        }
        cout << endl;

    }
};


int bfs(Puzzle initial) {
    queue<Puzzle> q;
    map<Puzzle, bool> cache;

    q.push(initial);
    cache[initial] = true;

    while (!q.empty()) {
        Puzzle puz;
        puz = q.front(); q.pop();

        if (puz.isCorrect()) return puz.stepCount;

        Pos spacePos = puz.getSpacePos();
        for (Pos deltaPos : { Pos(0, -1), Pos(1, 0), Pos(0, 1), Pos(-1, 0) }) {
            Pos targetPos = spacePos + deltaPos;

            if (targetPos.x < 0 || targetPos.y < 0 || targetPos.x >= X_SIZE || targetPos.y >= Y_SIZE) continue;

            Puzzle newPuz = puz;
            
            swap(newPuz.field[spacePos.toFlat()], newPuz.field[targetPos.toFlat()]);

            if (!cache[newPuz]) {
                cache[newPuz] = true;
                newPuz.stepCount += 1;
                q.push(newPuz);
            }
        }
    }

    return -1;
}

int main() {
    Puzzle puzzle;

    for (int i = 0; i < SIZE; i++) {
        cin >> puzzle.field[i];
    }

    cout << bfs(puzzle) << endl;
}
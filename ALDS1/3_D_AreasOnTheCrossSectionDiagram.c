#include <stdio.h>
#include <stdlib.h>

// 水たまり構造体
typedef struct {
    int leftSideIndex; // 左端のインデックス
    int area; // 面積
} Puddle;

int main() {
    int leftSideStack[20000]; // '\'が出現したインデックスを保持するスタック
    int leftSideStackTail = 0;
    Puddle puddles[10000]; // 水たまりのスタック
    int puddlesTail = 0;
    char inStr[20000];
    int areaSum = 0;

    scanf("%s", inStr);

    for (int i = 0;; i++) {
        if (inStr[i] == '\\') {
            leftSideStack[leftSideStackTail++] = i;
        }
        else if (inStr[i] == '/' && leftSideStackTail > 0) {
            int leftSideIndex = leftSideStack[--leftSideStackTail]; // 直近の'\'のインデックスを取得する
            int area = i - leftSideIndex;
            areaSum += area;

            // 水たまりの統合を行う
            //     現在処理中の水たまりの左端より右側にある水たまりは統合を行う
            while (puddlesTail && puddles[puddlesTail - 1].leftSideIndex > leftSideIndex) {
                area += puddles[--puddlesTail].area;
            }
            puddles[puddlesTail].leftSideIndex = leftSideIndex;
            puddles[puddlesTail++].area = area;
        }
        else if (inStr[i] == '\0') break;
    }

    // 結果を出力
    printf("%d\n", areaSum);
    printf("%d", puddlesTail);
    for (int i = 0; i < puddlesTail; i++) {
        printf(" %d", puddles[i].area);
    }
    printf("\n");

    return 0;
}

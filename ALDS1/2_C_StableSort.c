#include <stdio.h>

typedef struct {
    int number;
    char mark;
} Card;

void bubbleSort(Card *, int);
void selectionSort(Card *, int);
int isStable(Card *, Card*, int);
void printCards(Card *, int);
int eqCard(Card, Card);

int main() {
    char buf[2];
    Card inCards[36];
    Card outCards[36];
    int length;

    scanf("%d", &length);
    for (int i = 0; i < length; i++) {
        scanf("%s", buf);

        inCards[i].mark = buf[0];
        inCards[i].number = buf[1] - '0';
    }

    // バブルソート
    for (int i = 0; i < length; i++) outCards[i] = inCards[i]; // 配列コピー
    bubbleSort(outCards, length);
    printCards(outCards, length);
    if (isStable(inCards, outCards, length)) printf("Stable\n");
    else printf("Not stable\n");

    // 選択ソート
    for (int i = 0; i < length; i++) outCards[i] = inCards[i]; // 配列コピー
    selectionSort(outCards, length);
    printCards(outCards, length);
    if (isStable(inCards, outCards, length)) printf("Stable\n"); 
    else printf("Not stable\n");

    return 0;
}

// バブルソート
void bubbleSort(Card *array, int length){
    int flag = 1;

    while (flag){
        flag = 0;
        for (int i = 0; i < length-1; i++){
            if (array[i].number > array[i+1].number){
                Card buf = array[i];
                array[i] = array[i+1];
                array[i+1] = buf;
                flag = 1;
            }
        }
    }
}

// 選択ソート
void selectionSort(Card *array, int length){
    for(int i = 0; i < length; i++){
        int minIndex = i;

        for (int j = i; j < length; j++){
            if (array[j].number < array[minIndex].number){
                minIndex = j;
            }
        }
        if (i != minIndex){
            Card buf = array[i];
            array[i] = array[minIndex];
            array[minIndex] = buf;
        }
    }    
}

// stable sort 判定
int isStable(Card *in, Card *out, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            for (int a = 0; a < length; a++) {
                for (int b = a + 1; b < length; b++) {
                    if (in[i].number == in[j].number && eqCard(in[i], out[b]) && eqCard(in[j], out[a])) {
                        return 0;
                    }
                }
            }
        }
    }

    return 1;
}

// カードの配列をprintする
void printCards(Card *array, int length) {
    for (int i = 0; i < length; i++) {
        if (i != 0) printf(" ");
        printf("%c%d", array[i].mark, array[i].number);
    }
    printf("\n");
}

// 2つのカードが等しいか調べる
int eqCard(Card a, Card b) {
    if (a.number == b.number && a.mark == b.mark) return 1;
    else return 0;
}

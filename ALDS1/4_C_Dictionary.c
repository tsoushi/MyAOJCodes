#include <stdio.h>
#include <string.h>

int dict[244140625];

int charToInt(char ch) {
    if (ch == 'A') return 1;
    else if (ch == 'C') return 2;
    else if (ch == 'G') return 3;
    else if (ch == 'T') return 4;
}

int getKey(char str[]) {
    int value = 0;
    int p = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        value += p*charToInt(str[i]);
        p *= 5;
    }

    return value;
}

int main() {
    int length;
    char command[7], str[13];

    scanf("%d", &length);
    for (int i = 0; i < length; i++) {
        scanf("%s %s", command, str);

        if (command[0] == 'i') {
            dict[getKey(str)] = 1;
        } else {
            if (dict[getKey(str)] == 1) printf("yes\n");
            else printf("no\n");
        }
    }

    return 0;
}
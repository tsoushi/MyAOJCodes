#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int H;
    int tree[251];

    cin >> H;

    // input
    for (int i = 1; i <= H; i++) cin >> tree[i];

    // output
    for (int i = 1; i <= H; i++) {
        cout << "node " << i << ": ";
        cout << "key = " << tree[i] << ", ";
        if (i != 1) cout << "parent key = " << tree[i / 2] << ", ";
        if (i * 2 <= H) cout << "left key = " << tree[i * 2] << ", ";
        if (i * 2 + 1 <= H) cout << "right key = " << tree[i * 2 + 1] << ", ";
        cout << endl;
    }

    return 0;
}
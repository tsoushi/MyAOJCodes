#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Node {
    int parent = -1;
    int left = -1;
    int right = -1;
};

void preorder(Node *tree, int index) {
    if (index == -1) return;
    cout << " " << index;
    preorder(tree, tree[index].left);
    preorder(tree, tree[index].right);
}

void inorder(Node *tree, int index) {
    if (index == -1) return;
    inorder(tree, tree[index].left);
    cout << " " << index;
    inorder(tree, tree[index].right);
}

void postorder(Node *tree, int index) {
    if (index == -1) return;
    postorder(tree, tree[index].left);
    postorder(tree, tree[index].right);
    cout << " " << index;
}

int main() {
    int n;
    Node tree[25];
    int rootIndex;

    // 木の入力
    cin >> n;
    for (int i = 0; i < n; i++) {
        int index;
        cin >> index;
        cin >> tree[index].left >> tree[index].right;

        tree[tree[index].left].parent = index;
        tree[tree[index].right].parent = index;
    }

    // rootノードを探索
    for (int i = 0; i < n; i++) {
        if (tree[i].parent == -1) {
            rootIndex = i;
            break;
        }
    }

    // 出力
    cout << "Preorder" << endl;
    preorder(tree, rootIndex); cout << endl;
    cout << "Inorder" << endl;
    inorder(tree, rootIndex); cout << endl;
    cout << "Postorder" << endl;
    postorder(tree, rootIndex); cout << endl;

    return 0;
}
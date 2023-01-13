#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Node {
    int parent = -1;
    int depth;
    int height = -1;
    int degree;
    int sibling = -1;
    int left = -1;
    int right = -1;
};

// 再帰的に深さを計算し構造体に代入
// tree: 木構造の配列
// root: 再帰の起点となるインデックス（rootノードのインデックス）
// depth: 再帰的に呼び出す際に使用する（rootで指定したノードの深さ）
void setDepth(Node *tree, int root, int depth = 0) {
    tree[root].depth = depth;

    if (tree[root].left != -1) setDepth(tree, tree[root].left, depth + 1);
    if (tree[root].right != -1) setDepth(tree, tree[root].right, depth + 1);
}

// 再帰的に高さを計算し構造体に代入
void setHeight(Node *tree, int leaf, int height = 0) {
    if (tree[leaf].height < height) tree[leaf].height = height;
    if (tree[leaf].parent != -1) setHeight(tree, tree[leaf].parent, height + 1);
}

int main() {
    int n;
    Node tree[25];
    int rootIndex;

    // 木の入力
    cin >> n;
    for (int i = 0; i < n; i++) {
        int index, left, right;
        cin >> index;
        cin >> left >> right;
        tree[index].left = left;
        tree[index].right = right;

        tree[index].degree = (left == -1 ? 0 : 1) + (right == -1 ? 0 : 1);

        if (left != -1) {
            tree[left].parent = index;
            tree[left].sibling = right;
        }
        if (right != -1) {
            tree[right].parent = index;
            tree[right].sibling = left;
        }
    }

    // rootノードを探索
    for (int i = 0; i < n; i++) {
        if (tree[i].parent == -1) {
            rootIndex = i;
            break;
        }
    }

    // 深さを計算
    setDepth(tree, rootIndex);

    // 高さを計算
    for (int i = 0; i < n; i++) {
        if (tree[i].left == -1 && tree[i].right == -1) setHeight(tree, i);
    }

    // 出力
    for (int i = 0; i < n; i++) {
        cout << "node " << i << ": ";
        cout << "parent = " << tree[i].parent << ", ";
        cout << "sibling = " << tree[i].sibling << ", ";
        cout << "degree = " << tree[i].degree << ", ";
        cout << "depth = " << tree[i].depth << ", ";
        cout << "height = " << tree[i].height << ", ";

        if (tree[i].parent == -1) {
            cout << "root";
        } else if (tree[i].left == -1 && tree[i].right == -1) {
            cout << "leaf";
        } else {
            cout << "internal node";
        }

        cout << endl;
    }

    return 0;
}
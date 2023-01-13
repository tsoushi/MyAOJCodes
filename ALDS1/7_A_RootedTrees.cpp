#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Node {
    int parent = -1;
    int depth;
    int child = -1;
    int sibling = -1;
};

// 再帰的に深さを計算し構造体に代入
// tree: 木構造の配列
// root: 再帰の起点となるインデックス（rootノードのインデックス）
// depth: 再帰的に呼び出す際に使用する（rootで指定したノードの深さ）
void setDepth(Node *tree, int root, int depth = 0) {
    tree[root].depth = depth;

    if (tree[root].sibling != -1) setDepth(tree, tree[root].sibling, depth);
    if (tree[root].child != -1) setDepth(tree, tree[root].child, depth + 1);
}

int main() {
    int n;
    Node tree[100000];
    int rootIndex;

    // 木の入力
    cin >> n;
    for (int i = 0; i < n; i++) {
        int index, numChild;
        cin >> index >> numChild;

        int leftSibling = -1;
        for (int j = 0; j < numChild; j++) {
            int childIndex;
            cin >> childIndex;

            tree[childIndex].parent = index;
            if (leftSibling == -1) {
                // 1つ目の子は親ノードのchildとして登録する
                tree[index].child = childIndex;
            } else {
                // 2つ目以降は1つ前の子のsiblingとして登録する
                tree[leftSibling].sibling = childIndex;
            }
            leftSibling = childIndex;
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

    // 出力
    for (int i = 0; i < n; i++) {
        cout << "node " << i << ": ";
        cout << "parent = " << tree[i].parent << ", ";
        cout << "depth = " << tree[i].depth << ", ";
        if (tree[i].parent == -1) {
            cout << "root, ";
        } else if (tree[i].child == -1) {
            cout << "leaf, ";
        } else {
            cout << "internal node, ";
        }

        cout << "[";
        for (int index = tree[i].child; index != -1; index = tree[index].sibling) {
            if (index != tree[i].child) cout << ", ";
            cout << index;
        }
        cout << "]" << endl;
    }

    return 0;
}
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class BinaryTree {
private:
    struct Node {
        int key;
        Node *parent = nullptr;
        Node *left = nullptr;
        Node *right = nullptr;

        Node(int key) : key(key) {};
    };

    static void printInorder(Node *node) {
        if (node == nullptr) return;
        if (node->left != nullptr) printInorder(node->left);
        cout << " " << node->key;
        if (node->right != nullptr) printInorder(node->right);
    }

    static void printPreorder(Node *node) {
        if (node == nullptr) return;
        cout << " " << node->key;
        if (node->left != nullptr) printPreorder(node->left);
        if (node->right != nullptr) printPreorder(node->right);
    }

    static Node *find(Node *node, int key) {
        if (node == nullptr) return nullptr;
        if (key < node->key) return find(node->left, key);
        else if (node->key == key) return node;
        else return find(node->right, key);
    }

    static void debugPrint(Node *node) {
        if (node == nullptr) return;
        cout << node->key << " : ";
        if (node->left != nullptr) cout << node->left->key;
        cout << " | ";
        if (node->right != nullptr) cout << node->right->key;
        cout << endl;

        debugPrint(node->left);
        debugPrint(node->right);

    }
public:
    Node *root = nullptr;

    bool isExists(int key) {
        return find(root, key) != nullptr;
    }

    void deleteKey(int key) {
        Node *target = find(root, key);
        if (target == nullptr) return;
        else deleteNode(target);
    }

    static Node *minimum(Node *node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    static Node *successor(Node *node) {
        if (node->right != nullptr) return minimum(node->right);

        Node *y = node->parent;
        while (y != nullptr && node == y->right) {
            node = y;
            y = y->parent;
        }
        return y;
    }

    void deleteNode(Node *target) {
        Node *x;
        Node *y;
        if (target->left == nullptr || target->right == nullptr) y = target;
        else y = successor(target);

        if (y->left != nullptr) x = y->left;
        else x = y->right;

        if (x != nullptr) x->parent = y->parent;
        if (y->parent == nullptr) root = x;
        else if (y == y->parent->left) y->parent->left = x;
        else y->parent->right = x;

        if (y != target) target->key = y->key;
    }

    void insert(int key) {
        Node *z = new Node(key);
        Node *y = nullptr;
        Node *x = this->root;

        while (x != nullptr) {
            y = x;
            if (z->key < x->key) x = x->left;
            else x = x->right;
        }
        z->parent = y;

        if (y == nullptr) this->root = z;
        else if (z->key < y->key) y->left = z;
        else y->right = z;
    }



    void print() {
        printInorder(root);
        cout << endl;
        printPreorder(root);
        cout << endl;
    }

    void debugPrint() {
        debugPrint(root);
    }
};

int main() {
    BinaryTree tree;
    int numCommand;
    cin >> numCommand;

    for (int i = 0; i < numCommand; i++) {
        string command;
        cin >> command;
        if (command[0] == 'i') {
            int key;
            cin >> key;
            tree.insert(key);
        } else if (command[0] == 'f') {
            int key;
            cin >> key;
            if (tree.isExists(key)) cout << "yes";
            else cout << "no";
            cout << endl;
        } else if (command[0] == 'd') {
            int key;
            cin >> key;
            tree.deleteKey(key);
        } else {
            tree.print();
        }
    }
}
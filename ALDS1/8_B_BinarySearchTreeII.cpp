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

    static bool find(Node *node, int key) {
        if (node == nullptr) return false;
        if (key < node->key) return find(node->left, key);
        else if (node->key == key) return true;
        else return find(node->right, key);
    }

public:
    Node *root = nullptr;

    bool find(int key) {
        return find(root, key);
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
            if (tree.find(key)) cout << "yes";
            else cout << "no";
            cout << endl;
        } else {
            tree.print();
        }
    }
}
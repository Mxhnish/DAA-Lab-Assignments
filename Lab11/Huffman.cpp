
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char d, int f) {
        data = d;
        freq = f;
        left = right = NULL;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " : " << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    cout << "Enter character and frequency:\n";

    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        cin >> ch >> freq;

        pq.push(new Node(ch, freq));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    Node* root = pq.top();

    cout << "\nHuffman Codes:\n";
    printCodes(root, "");

    return 0;
}

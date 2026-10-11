//Dhhruv Goyal, 25/DA/021
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare
{
    bool operator()(Node* a, Node* b)
    {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
        cout << root->ch << " : " << code << endl;
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main()
{
    int n;
    cout << "Enter number of characters: ";
    cin >> n;
    char ch;
    int freq;
    priority_queue<Node*, vector<Node*>, Compare> pq;
    cout << "Enter character and frequency:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> ch >> freq;
        pq.push(new Node(ch, freq));
    }
    while (pq.size() > 1)
    {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* parent = new Node('$',
                                left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    cout << "Huffman Codes:\n";
    printCodes(pq.top(), "");
    return 0;
}
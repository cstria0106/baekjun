#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
    int index;
    Node *parent;
    vector<Node *> children;

    explicit Node(int i) {
        this->index = i;
        this->parent = nullptr;
    }

    int count_leaf_nodes() {
        if (children.empty()) return 1;

        int count = 0;
        for (Node *child : children) {
            count += child->count_leaf_nodes();
        }

        return count;
    }

    bool operator==(const Node &other) {
        return this->index == other.index;
    }

    ~Node() {
        for (Node *child: children) {
            delete child;
        }
    }
};

int main() {
    int n;
    cin >> n;

    Node *root = new Node(-1);
    vector<Node *> nodes;

    for (int i = 0; i < n; i++) {
        Node *node;
        node = new Node(i);
        nodes.push_back(node);
    }

    for (int i = 0; i < n; i++) {
        Node *node = nodes[i];

        int parent_index;
        cin >> parent_index;

        if (parent_index == -1) {
            root->children.push_back(node);
            node->parent = root;
        } else {
            nodes[parent_index]->children.push_back(node);
            node->parent = nodes[parent_index];
        }
    }

    int to_delete;
    cin >> to_delete;

    auto e = find(nodes[to_delete]->parent->children.begin(),
                  nodes[to_delete]->parent->children.end(),
                  nodes[to_delete]);
    nodes[to_delete]->parent->children.erase(e);
    delete nodes[to_delete];
    nodes.erase(nodes.begin() + to_delete);

    int count = 0;

    for (Node *parent: root->children) {
        count += parent->count_leaf_nodes();
    }

    cout << count << endl;


}
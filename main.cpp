#include <iostream>
#include <string>

using namespace std;

class Squirrel {
private:
    string name;

public:
    Squirrel(string name) {
        this->name = name;
    }

    string get_name() {
        return this->name;
    }
};

class Node {
private:
    Squirrel* data;
    Node* left_child;
    Node* right_child;

public:
    Node(Squirrel* squirrel) {
        data = squirrel;
        left_child = nullptr;
        right_child = nullptr;
    }

    void set_left(Node* left) {
        left_child = left;
    }

    void set_right(Node* right) {
        right_child = right;
    }

    Node* left() {
        return left_child;
    }

    Node* right() {
        return right_child;
    }

    Squirrel* get_data() {
        return data;
    }
};

void traverse_pre_order(Node* node) {
    if (node == nullptr) return;

    cout << node->get_data()->get_name() << " ";
    traverse_pre_order(node->left());
    traverse_pre_order(node->right());
}

int main() {
    Squirrel cheeks("Cheeks");
    Squirrel squeaks("Squeaks");
    Squirrel fluffybutt("Mr. Fluffy Butt");

    Node node_one(&cheeks);
    Node node_two(&squeaks);
    Node node_three(&fluffybutt);

    node_one.set_left(&node_two);
    node_one.set_right(&node_three);

    cout << "Pre-order traversal of the tree: ";
    traverse_pre_order(&node_one);
    cout << endl;

    Node* retrieved_left = node_one.left();
    Node* retrieved_right = node_one.right();

    cout << "Left child of node_one: " << retrieved_left->get_data()->get_name() << endl;
    cout << "Right child of node_one: " << retrieved_right->get_data()->get_name() << endl;

    return 0;
}

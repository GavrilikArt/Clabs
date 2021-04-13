#pragma once

struct Node {
    Node& operator=(const Node node) {
      data = node.data;
      left = node.left;
      right = node.right;
    }
    short int count = 1;
    char data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(const char &x, Node* l, Node* r): data(x), left(l), right(r) {}
};
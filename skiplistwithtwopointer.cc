//
// Created by chuande on 2021/5/27.
//
#include <vector>
#include <cstdlib>

struct Node {
    Node *right, *down;
    int val;

    Node(Node *right, Node *left, int val)
            : right(right), down(left), val(val) {
    }
};

class Skiplist {
    Node *head;

public:
    Skiplist() {
        head = new Node(nullptr, nullptr, 0);
    }

    bool search(int num) {
        Node *p = head;

        while (p) {
            while (p->right and p->right->val < num) p = p->right;

            if (!p->right or p->right->val > num) p = p->down;
            else return true;
        }

        return false;
    }

    void add(int num) {
        std::vector<Node *> insert_points;

        Node *p = head;
        while (p) {
            while (p->right and p->right->val < num) p = p->right;
            insert_points.push_back(p);
            p = p->down;
        }

        Node *down_node = nullptr;
        bool insert_up = true;
        while (insert_up and !insert_points.empty()) {
            Node *ins = insert_points.back();
            insert_points.pop_back();

            ins->right = new Node(ins->right, down_node, num);
            down_node = ins->right;

            insert_up = ((rand() & 1) == 0);
        }

        if (insert_up) {
            head = new Node(new Node(nullptr, down_node, num), head, 0);
        }
    }

    bool erase(int num) {
        Node *p = head;
        bool seen = false;
        while (p) {
            while (p->right and p->right->val < num) p = p->right;
            if (!p->right or p->right->val > num) p = p->down;
            else {
                seen = true;
                Node *find = p->right;
                p->right = find->right;
                p = p->down;
                delete find;
            }
        }
        return seen;
    }
};

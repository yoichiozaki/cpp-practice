#include <bits/stdc++.h>
using namespace std;

struct node {
    int key;
    node *prev, *next;
};
using node = struct node;

node *nil; // 番兵

void init() {
    nil = (node *)malloc(sizeof(node));
    nil->prev = nil;
    nil->next = nil;
}

node* search(int key) {
    node *current = nil->next;
    while (current != nil && current->key != key) {
        current = current->next;
    }
    return current;
}

void delete_node(node *target) {
    if (target == nil ) return;
    target->prev->next = target->next;
    target->next->prev = target->prev;
    free(target);
}

void delete_first_node() {
    delete_node(nil->next);
}

void delete_last_node() {
    delete_node(nil->prev);
}

void delete_key(int key) {
    delete_node(search(key));
}

void insert(int key) {
    node *x = (node *)malloc(sizeof(node));
    x->key = key;
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

void print_list() {
    node *current = nil->next;
    int isf = 0;
    while (1) {
        if (current == nil) break;
        if (isf++ > 0) {
            cout << " ";
        }
        cout << current->key;
        current = current->next;
    }
    cout << endl;
}

int main() {
    int key, n, i;
    int size = 0;
    char command[20];
    int np = 0, nd = 0;
    scanf("%d", &n);
    init();
    for (i = 0; i < n; i++) {
        scanf("%s%d", command, &key);
        if (command[0] == 'i') {
            insert(key);
            np++;
            size++;
        } else if (command[0] == 'd') {
            if (strlen(command) > 6) {
                if (command[6] == 'F') {
                    delete_first_node();
                } else if (command[6] == 'L') {
                    delete_last_node();
                }
            } else {
                delete_key(key);
                nd++;
            }
            size--;
        }
    }

    print_list();
    return 0;
}
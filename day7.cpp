#include <iostream>
#include <array>
#include <numeric>
#include <algorithm>

#define SIZE 1024

typedef struct node {
    std::string name;
    bool dir; 
    int size;
    struct node *children[SIZE];
    struct node *parent;
} node_t;

void print_tree(node_t *node) {
    std::cout << node->name << "\n";
    if (node->dir) {
        for (int i = 0; i < SIZE && node->children[i] != NULL; i++) {
            print_tree(node->children[i]);
        }
    }
}

int calculate_sizes(node_t *node) {
    if (!(node->dir)) {
        return node->size;
    }

    node->size = 0;
    for (int i = 0; i < SIZE && node->children[i] != NULL; i++) {
        node->size += calculate_sizes(node->children[i]);
    }

    return node->size; 
}

// #define MAX_SIZE 100000
#define MAX_SIZE 70000000

void get_valid(node_t *node, std::vector<node_t *>& valid) {
    if (node->size <= MAX_SIZE && node->dir) {
        valid.push_back(node);
    }

    for (int i = 0; i < SIZE && node->children[i] != NULL; i++) {
        get_valid(node->children[i], valid);
    }
}

int main(void) {
    node_t* curr_node = new node_t;
    std::string curr_str = "";
    std::getline(std::cin, curr_str);
    node_t *base_node = curr_node;

    while (true) {
        if (curr_str == "") break;

        // std::cout << curr_str;
        if (curr_str == "$ cd /") {
            curr_node->name = "/";
            curr_node->dir = true;
            std::getline(std::cin, curr_str);
            continue; 
        }

        if (curr_str == "$ ls") {
            // std::cout << "hi!!!" << curr_str << "\n";
            int i = 0; 
            while (std::getline(std::cin, curr_str)) {
                if (curr_str.substr(0, 3) == "dir") {
                    curr_node->children[i] = new node_t;
                    curr_node->children[i]->name = curr_str.substr(4, curr_str.size());
                    curr_node->children[i]->dir = true;
                    curr_node->children[i]->parent = curr_node;
                } else if (curr_str.c_str()[0] != '$' && curr_str != "") {
                    curr_node->children[i] = new node_t;
                    curr_node->children[i]->size = stoi(curr_str.substr(0, curr_str.find(' ')));
                    curr_node->children[i]->dir = false;
                    curr_node->children[i]->name = curr_str.substr(curr_str.find(' ') + 1, curr_str.size());
                    curr_node->children[i]->parent = curr_node;
                } else {
                    break;
                }
                i++;
            }
        } else if (curr_str.substr(0, 4) == "$ cd") {
            std::string dirname = curr_str.substr(5, curr_str.size());
            if (dirname == "..") {
                curr_node = curr_node->parent;
            } else {
                for (int i = 0; i < SIZE; i++) {
                    if (curr_node->children[i] == NULL) {
                        std::cout << "wtf\n";
                        return 0;
                    }
                    // std::cout << curr_node->children[i]->name << " " << dirname << " " << (curr_node->children[i]->name == dirname) << "\n";
                    if (curr_node->children[i]->name == dirname) {
                        curr_node = curr_node->children[i];
                        break;
                    }
                }
            }
            std::getline(std::cin, curr_str);
        }
    }

    print_tree(base_node);
    calculate_sizes(base_node);
    std::cout << base_node->size << "\n";

    auto valid = std::vector<node_t *>();
    get_valid(base_node, valid);

    int total = 0;
    for (node_t *node: valid) {
        total += node->size;
    }

    std::cout << total << "\n";

    std::sort(valid.begin(), valid.end(), [](node_t *a, node_t *b) {
        return a->size < b->size;
    });

    int amount_remaining = 70000000 - base_node->size;
    int amount_needed = 30000000;
    int amount_left =  amount_needed - amount_remaining;

    for (node_t *node: valid) {
        if (node->size > amount_left) {
            std::cout << node->size << "\n";
            break; 
        }
    }




}
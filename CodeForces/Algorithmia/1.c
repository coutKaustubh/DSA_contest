#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct Node {
    char data;
    Color color;
    struct Node *left, *right;
} Node;

Node *createNode(char data, Color color) {
    Node *n = malloc(sizeof(Node));
    n->data = data;
    n->color = color;
    n->left = n->right = NULL;
    return n;
}

void showCase(const char *caseName) {
    printf("Deletion Case: %s\n", caseName);
}

int main() {
    showCase("Case 1: Node is Red (simple remove)");
    showCase("Case 2: Node is Black with Red child (replace with child)");
    showCase("Case 3: Node is Black with Black children (fix double black)");
    return 0;
}

#include "source.h"

int main() {
    Tree tree(10);
    tree.output();
    tree.push_to(11);
    tree.output();
    cout << '\n';
    tree.push_to(12);
    tree.output();
    cout << '\n';
    tree.push_to(13);
    tree.output();
    cout << '\n';
    tree.push_to(14);
    tree.output();
    cout << '\n';
    tree.push_to(15);
    tree.output();
    cout << '\n';
    tree.push_to(16);
    tree.output();
    cout << '\n';
    return 0;
}

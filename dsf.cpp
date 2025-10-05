#include <vector>
using std::vector;

struct dsf {
    struct parent_node {
        int parent;
        int size = 1;

        parent_node(int parent) : parent(parent) {}
    };

    vector<parent_node> nodes {};

    explicit dsf(int size) {
        for (int i = 0; i < size; i++) {
            nodes.emplace_back(i);
        }
    }

    bool is_root(int i) {
        return nodes[i].parent == i;
    }

    int size_root(int i) {
        int root = find_set(i);
        return nodes[root].size;
    }

    int find_set(const int& i) {
        if (is_root(i))
            return i;

        return find_set(nodes[i].parent);
        
    }
    // False if i and j were already in union
    bool union_set(const int& i, const int& j, int*root=nullptr) {
        int root_i = find_set(i);
        int root_j = find_set(j);
        if (root_i == root_j)
            return false;

        if (nodes[root_i].size >= nodes[root_j].size) {
            nodes[root_j].parent = root_i;
            nodes[root_i].size += nodes[root_j].size;
            if (root)
                *root = root_i;
        } else {
            nodes[root_i].parent = root_j;
            nodes[root_j].size += nodes[root_i].size;
            if (root)
                *root = root_j;
        }

        return true;
    }
};
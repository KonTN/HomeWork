#pragma once

#include <vector>
#include <map>
#include <string>

class Tree
{
    public:
        Tree(Tree* root);
        Tree* add_branch();
        Tree* get_root();
        std::vector<Tree> get_subtree_recursive();
        std::vector<Tree> get_subtree();

        std::string vilagerName;
    private:
        void rec_pass(Tree* root, std::vector<Tree>& branches);
        Tree* myRoot;
        std::vector<Tree> subTrees;
};
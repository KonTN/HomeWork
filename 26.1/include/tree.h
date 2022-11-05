#pragma once

#include <list>
#include <map>
#include <string>

class Tree
{
    public:
        Tree(Tree* root);
        Tree* add_branch();
        Tree* get_root();
        std::list<Tree> get_subtree_recursive();
        std::list<Tree> get_subtree();

        std::string vilagerName;
    private:
        void rec_pass(Tree* root, std::list<Tree>& branches);
        Tree* myRoot;
        std::list<Tree> subTrees;
};
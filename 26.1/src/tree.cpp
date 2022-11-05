#include <tree.h>


Tree::Tree(Tree* root)
{
    myRoot = root;
    subTrees.clear();
}

Tree* Tree::add_branch()
{
    Tree dummyTree(this);
    subTrees.push_back(dummyTree);
    return &subTrees.back();
}

std::list<Tree> Tree::get_subtree()
{
    return subTrees;
}

std::list<Tree> Tree::get_subtree_recursive()
{
    std::list<Tree> retV;
    rec_pass(this, retV);
    return retV;
}

void Tree::rec_pass(Tree* root, std::list<Tree>& branches)
{
    if (root->get_subtree().empty())
    {
        return;
    }

    for (Tree & t : root->get_subtree())
    {
        branches.push_back(t);
        rec_pass(&t,branches);
    }
}

Tree* Tree::get_root()
{
    return myRoot;
}






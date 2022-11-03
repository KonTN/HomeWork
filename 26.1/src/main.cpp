#include <iostream>
#include <tree.h>

void print_tree(Tree &wood, int tree_num)
{
    Tree tree = wood.get_subtree()[tree_num];
    std::cout << "root" << "->" << "\n";
    for (Tree &big_branch : tree.get_subtree())
    {
        std::cout << "    " << big_branch.vilagerName;
        if (!big_branch.get_subtree().empty()) std::cout << "->" << "\n";
        else std::cout << "\n";

        for (Tree &small_branch : big_branch.get_subtree())
        {
            std::cout << "        " << small_branch.vilagerName << "\n";
        }
    }
}

int main(int, char**) {
    // init
    Tree wood(nullptr);
    srand(time(nullptr));
    
    // starting tree colonization 
    std::cout << "Please specify the names of the inhabited elves" << std::endl;
    std::cout << "('None' for empty houses)" << std::endl << std::endl;   
    for (int i = 0; i < 1; i++) // 5 trees
    {
        std::cout << i+1 << " tree:" << std::endl;
        Tree* tree = wood.add_branch();
        for (int j = 0; j < 3+rand()%3; j++) // big branches;
        {
            Tree* bigBranch = tree->add_branch();
            std::cout << "please enter elf name: ";
            std::string elfName;
            std::cin >> elfName;
            bigBranch->vilagerName = elfName;
            print_tree(wood,i);
            for (int k  = 0; k < 2+rand()%2; k++ ) // medium branches;
            {
                Tree* medBranch = bigBranch->add_branch();
                std::cout << "please enter elf name: ";
                std::cin >> elfName;
                medBranch->vilagerName = elfName;
                print_tree(wood,i);
            }
        }
        print_tree(wood,i);
    }
    for (int i = 0 ; i < wood.get_subtree().size(); i++)
    {
        std::cout << i+1 << " Tree:\n";
        print_tree(wood,i);
    }
    std::cout << "\nPlease enter elf name to find his neighbors: ";
    std::string name;
    std::cin >> name;

    Tree* foundBranch;
    for (Tree &t : wood.get_subtree_recursive())
    {
        if ((t.vilagerName == name)&&(name != "None"))
        {
            std::cout << "found neighbors: ";

            if (t.get_subtree().empty())
            {
                foundBranch = t.get_root();
                std::cout << foundBranch->vilagerName << " ";
            }
            else
            {
                foundBranch = &t;
            }

            for (Tree &tr : foundBranch->get_subtree())
            {
                if ((tr.vilagerName != "None")&&(tr.vilagerName != name))
                {
                    std::cout << tr.vilagerName << " ";
                }
            }
            std::cout << std::endl;
            return 0;
        } 
    }

    std::cout << "Can't find any '" << name << "' elf" << std::endl;
}   












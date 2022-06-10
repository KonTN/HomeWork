#include <iostream>
#include <tree.h>
int main(int, char**) {
    // init
    Tree myTree(nullptr);
    srand(time(NULL));
    
    // starting tree colonization 
    std::cout << "Please specify the names of the inhabited elves" << std::endl;
    std::cout << "('None' for empty houses)" << std::endl << std::endl;   
    for (int i = 0; i < 1; i++) // 5 trees
    {
        std::cout << i+1 << " tree:" << std::endl;
        Tree* tree = myTree.add_branch();
        for (int j = 0; j < 3+rand()%3; j++) // big branches;
        {
            Tree* bigBranch = tree->add_branch();

            std::cout << "\t";
            std::string elfName;
            std::cin >> elfName;
            bigBranch->vilagerName = elfName;

            for (int k  = 0; k < 2+rand()%2; k++ ) // medium branches;
            {
                Tree* medBranch = bigBranch->add_branch();

                std::cout << "\t\t";
                std::string elfName;
                std::cin >> elfName;
                medBranch->vilagerName = elfName;
            }
        }
    }

    std::cout << "Please enter elf name to find his neghbors: ";
    std::string name;
    std::cin >> name;

    Tree* foundBranch = nullptr;
    for (Tree t : myTree.get_subtree_recursive())
    {
        if ((t.vilagerName == name)&&(name != "None"))
        {
            foundBranch = t.get_root();
            
            std::cout << "found neghbors: ";
            for (Tree t : foundBranch->get_subtree())
            {
                if ((t.vilagerName != "None")&&(t.vilagerName != name))
                {
                    std::cout << t.vilagerName << " ";
                }
            }
            std::cout << std::endl;
            return 0;
        } 
    }

    std::cout << "Can't find any '" << name << "' elfs" << std::endl;
}   












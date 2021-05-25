#include "BinaryTree.h"


int main()
{
    BinaryTree SmallTree;
    SmallTree.Add(3, "Dudich");
    SmallTree.Add(1, "Ermolovich");
    SmallTree.Add(5, "Snetko");
    SmallTree.Add(2, "Pushkov");
    SmallTree.Add(7, "Mazur-Grabovskiy");
    SmallTree.Add(4, "Dashkovskiy");
    SmallTree.Add(11, "Durdachnik");
    SmallTree.PrintLNR();
    cout << endl;
    SmallTree.PrintTask('K');
    return 0;
}

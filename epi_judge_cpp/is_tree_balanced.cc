#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
struct Rslt {
    bool bal;
    int h;
};
Rslt isBal(const unique_ptr<BinaryTreeNode<int>> &nd)
{
    if(nd== nullptr)
    {
        return {true,-1};
    } else
    {
        Rslt rr = isBal(nd->right);
        if(!rr.bal)
            return {false,-1};
        Rslt lr = isBal(nd->left);
        if(!lr.bal)
            return {false,-1};
        if(std::abs(rr.h - lr.h) > 1)
            return {false,-1};
        else
            return {true,std::max(rr.h,lr.h)+1};
    }
}
bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  return isBal(tree).bal;
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}

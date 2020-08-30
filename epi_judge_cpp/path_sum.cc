#include <memory>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
bool sumHelp(const unique_ptr<BinaryTreeNode<int>> &nd, int parSum, int w)
{
    if(nd == nullptr)
    {
        if(parSum == w)
            return true;
        else
            return false;
    } else {
        if(sumHelp(nd->left,parSum+nd->data,w))
            return true;
        if(sumHelp(nd->right,parSum+nd->data,w))
            return true;
        return false;
    }
}

bool HasPathSum(const unique_ptr<BinaryTreeNode<int>>& tree,
                int remaining_weight) {
  // TODO - you fill in here.
  return sumHelp(tree,0,remaining_weight);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree", "remaining_weight"};
  return GenericTestMain(args, "path_sum.cc", "path_sum.tsv", &HasPathSum,
                         DefaultComparator{}, param_names);
}

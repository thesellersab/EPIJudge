#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
int sumHelper(const unique_ptr<BinaryTreeNode<int>> &nd, int parSum )
{
    if(nd == nullptr)
        return parSum;
    else
    {
        if(nd->right== nullptr && nd->left == nullptr)
            return (2*parSum + nd->data);
        else if(nd->right == nullptr)
        {
            return sumHelper(nd->left,2*parSum+nd->data);
        }
        else if(nd->left == nullptr)
        {
            return sumHelper(nd->right,2*parSum+nd->data);
        } else{
            return sumHelper(nd->left,2*parSum+nd->data) + sumHelper(nd->right,2*parSum+nd->data);
        }
    }
}
int SumRootToLeaf(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  return sumHelper(tree,0);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "sum_root_to_leaf.cc", "sum_root_to_leaf.tsv",
                         &SumRootToLeaf, DefaultComparator{}, param_names);
}

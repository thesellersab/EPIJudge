#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
bool isSym(const unique_ptr<BinaryTreeNode<int>> &r, const unique_ptr<BinaryTreeNode<int>> &l)
{
    if(r== nullptr && l== nullptr)
        return true;
    if(r!= nullptr && l!= nullptr)
    {
        return r->data == l->data &&
        isSym(l->left,r->right) && isSym(l->right,r->left);
    }
    return false;
}
bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  if(tree==nullptr)
      return true;
  else
      return isSym(tree->right, tree->left);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_symmetric.cc", "is_tree_symmetric.tsv",
                         &IsSymmetric, DefaultComparator{}, param_names);
}

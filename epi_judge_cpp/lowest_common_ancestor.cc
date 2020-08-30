#include <memory>

#include "binary_tree_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::unique_ptr;
struct Rslt {
    BinaryTreeNode<int> *nd;
    int cnt;
};
Rslt lcaHelp(const unique_ptr<BinaryTreeNode<int>>& nd,
             const unique_ptr<BinaryTreeNode<int>> &a,
             const unique_ptr<BinaryTreeNode<int>> &b)
{
    if(nd== nullptr){
        return {nullptr,0};
    }
    else{
        auto right = lcaHelp(nd->right,a,b);
        if(right.cnt==2)
            return right;
        auto left = lcaHelp(nd->left,a,b);
        if(left.cnt==2)
            return left;
        int cnt = right.cnt + left.cnt;
        if(nd->data == a->data)
            cnt++;
        if(nd->data == b->data)
            cnt++;
        if(cnt==2)
            return {nd.get(),cnt};
        else
            return {nullptr,cnt};
    }
}
BinaryTreeNode<int>* Lca(const unique_ptr<BinaryTreeNode<int>>& tree,
                         const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
  // TODO - you fill in here.
  return lcaHelp(tree,node0,node1).nd;
}
int LcaWrapper(TimedExecutor& executor,
               const unique_ptr<BinaryTreeNode<int>>& tree, int key0,
               int key1) {
  const unique_ptr<BinaryTreeNode<int>>& node0 = MustFindNode(tree, key0);
  const unique_ptr<BinaryTreeNode<int>>& node1 = MustFindNode(tree, key1);

  auto result = executor.Run([&] { return Lca(tree, node0, node1); });

  if (!result) {
    throw TestFailure("Result can not be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree", "key0", "key1"};
  return GenericTestMain(args, "lowest_common_ancestor.cc",
                         "lowest_common_ancestor.tsv", &LcaWrapper,
                         DefaultComparator{}, param_names);
}

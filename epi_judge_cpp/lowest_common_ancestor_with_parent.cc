#include "binary_tree_with_parent_prototype.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
int getDepth(const BinaryTreeNode<int>* ptr)
{
    int d = 0;
    while(ptr->parent){
        d++;
        ptr = ptr->parent;
    }
    return d;
}
BinaryTreeNode<int>* Lca(const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
  // TODO - you fill in here.
  auto ptr0 = node0.get();
  auto ptr1 = node1.get();
  int d0 = getDepth(ptr0);
  int d1 = getDepth(ptr1);
  if(d0 > d1)
  {
      int t = d0 - d1;
      while(t > 0)
      {
          ptr0 = ptr0->parent;
          t--;
      }
  } else{
      int t = d1 - d0;
      while(t > 0)
      {
          ptr1 = ptr1->parent;
          t--;
      }

  }
  while(ptr1 != ptr0)
  {
      ptr0=ptr0->parent;
      ptr1=ptr1->parent;
  }
  return ptr0;
}
int LcaWrapper(TimedExecutor& executor,
               const unique_ptr<BinaryTreeNode<int>>& tree, int key0,
               int key1) {
  const unique_ptr<BinaryTreeNode<int>>& node0 = MustFindNode(tree, key0);
  const unique_ptr<BinaryTreeNode<int>>& node1 = MustFindNode(tree, key1);

  auto result = executor.Run([&] { return Lca(node0, node1); });

  if (!result) {
    throw TestFailure("Result can not be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree", "key0", "key1"};
  return GenericTestMain(args, "lowest_common_ancestor_with_parent.cc",
                         "lowest_common_ancestor.tsv", &LcaWrapper,
                         DefaultComparator{}, param_names);
}

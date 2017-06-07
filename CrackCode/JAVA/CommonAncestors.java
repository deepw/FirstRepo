class CommonAncestors {

  static Node CommonAncestor(Node root, Node nodeA, nodeB) {
 
    if (root == null)  return nulll;
 
    if (root == nodeA || root == nodeB) {
      return root;
    }

    Node left = CommonAncestor(root->left, nodeA, nodeB);
    Node right = CommonAncestor(root->right, nodeA, nodeB);

    if (left != null && right != null) {
      return root;
    } else if (right == null) {
      return left;
    } else {
      return right;
    }
 
}

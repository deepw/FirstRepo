/* Check if a tree is a Binary Tree */

public class ValidateBinary {
  
  boolean checkBinary(Node root, int min, int max) {
    if (root == null) {
      return true;
    }

    if (root->data > max || root->data < min) {
      return false;
    } else {
      return (checkBinary(root->left, min, root->value) && checkBinary(root->right, root->value, max));
    }
  }


}

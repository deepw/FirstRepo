#include <stdio.h>

find_deepest (Node *root, Node **maxn, int *maxd, int depth) {
	if (!root) return;
	if (depth > maxd) {
		*maxn = root;
		maxd = depth;
	}
	find_deepest (root->left, maxn, maxd, depth+1);
	find_deepest (root->right, maxn, maxd, depth+1);
}




std::pair getLCSForDeepestNodesBottomUp(node *root) ----> This is O(N) Solution
{
    if (root == nullptr)
        return{ 0, nullptr };
    std::pair lh = getLCSForDeepestNodesBottomUp(root->left);
    std::pair rh = getLCSForDeepestNodesBottomUp(root->right);

    if (lh.first == rh.first || (lh.first == 0 && rh.first == 1) || (rh.first == 0 && lh.first == 1))
        return{ 1 + std::max(lh.first, rh.first), root };
    if (lh.first > rh.first)
        return{ 1 + lh.first, lh.second };
    return{ 1 + rh.first, rh.second };
}



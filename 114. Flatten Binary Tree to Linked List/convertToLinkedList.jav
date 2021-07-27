/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    public void flatten(TreeNode root) {
        if (root == null)
            return;
        TreeNode l = root.left, r = root.right;
        if (l != null) {
            flatten(l);
            root.right = l;
            root.left = null;
            while (l.right != null)
                l = l.right;
            l.right = r;
        }
        if (r != null) {
            flatten(r);
        }
    }
}


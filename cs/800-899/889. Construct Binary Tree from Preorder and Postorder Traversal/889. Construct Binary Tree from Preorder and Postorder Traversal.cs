using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _889.Construct_Binary_Tree_from_Preorder_and_Postorder_Traversal
{
    public class Solution
    {
        /**
        * Definition for a binary tree node.
        */
        public class TreeNode
        {
            public int val;
            public TreeNode left;
            public TreeNode right;
            public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
            {
                this.val = val;
                this.left = left;
                this.right = right;
            }
        }

        public void printTree(TreeNode root)
        {
            Queue<TreeNode> q = new Queue<TreeNode>() {};
            q.Enqueue(root);
            List<int> bfs = new List<int>();
            while (q.Count > 0)
            {
                TreeNode node = q.Dequeue();
                bfs.Add(node.val);
                if (node.left != null) { q.Enqueue(node.left); }
                if (node.right != null) { q.Enqueue(node.right); }
            }
            Console.WriteLine(string.Join(" ", bfs));
        }

        public TreeNode ConstructFromPrePost(int[] preorder, int[] postorder)
        {
            TreeNode r = new TreeNode(preorder[0]);
            if (preorder.Length == 1)
            {
                return r;
            }

            int leftInPost = Array.IndexOf(postorder, preorder[1]);
            int[] leftPostorder = new int[leftInPost + 1];
            int[] leftPreorder = new int[leftInPost + 1];
            Array.Copy(preorder, 1, leftPreorder, 0, leftPreorder.Length);
            Array.Copy(postorder, 0, leftPostorder, 0, leftPostorder.Length);
            r.left = ConstructFromPrePost(leftPreorder, leftPostorder);

            if (leftInPost == postorder.Length - 2) // only half tree
            {
                return r;
            }

            int[] rightPreorder = new int[preorder.Length - 1 - leftPreorder.Length];
            int[] rightPostorder = new int[postorder.Length - 1 - leftPostorder.Length];
            Array.Copy(preorder, 1 + leftPreorder.Length, rightPreorder, 0, rightPreorder.Length);
            Array.Copy(postorder, leftPostorder.Length, rightPostorder, 0, rightPostorder.Length);
            r.right = ConstructFromPrePost(rightPreorder, rightPostorder);

            return r;
        }

        static void Main(string[] args)
        {
            Solution sol = new Solution();
            int[] preorder = new int[] { 1, 2, 4, 5, 3, 6, 7 };
            int[] postorder = new int[] { 4, 5, 2, 6, 7, 3, 1 };
            TreeNode r = sol.ConstructFromPrePost(preorder, postorder);
            sol.printTree(r);

            preorder = new int[] { 1, 2, 4, 5};
            postorder = new int[] { 4, 5, 2, 1 };
            r = sol.ConstructFromPrePost(preorder, postorder);
            sol.printTree(r);
        }
    }
}

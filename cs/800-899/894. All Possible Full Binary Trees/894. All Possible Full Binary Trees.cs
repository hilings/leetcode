using System;
using System.Collections.Generic;

namespace _894.All_Possible_Full_Binary_Trees
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

    public class Solution
    {
        public IList<TreeNode> AllPossibleFBT(int n)
        {
            IList<TreeNode> r = new List<TreeNode>();
            if (n % 2 == 0)
            {
                return r;
            }
            if (n == 1)
            {
                r.Add(new TreeNode(0));
                return r;
            }

            for (int i = 1; i < n; i += 2)
            {
                IList<TreeNode> listLeft = AllPossibleFBT(i);
                IList<TreeNode> listRight = AllPossibleFBT(n - 1 - i);
                foreach (TreeNode left in listLeft)
                {
                    foreach (TreeNode right in listRight)
                    {
                        TreeNode root = new TreeNode(0, left, right);
                        r.Add(root);
                    }
                }
            }
            return r;
        }

        static public List<int?> TreeSerialize(TreeNode root)
        {
            List<int?> nodes = new List<int?>();
            if (root == null)
            {
                return nodes;
            }

            Queue<TreeNode> q = new Queue<TreeNode>();
            q.Enqueue(root);
            while (q.Count > 0)
            {
                TreeNode node = q.Dequeue();
                if (node == null)
                {
                    nodes.Add(null);
                }
                else
                {
                    nodes.Add(node.val);
                    q.Enqueue(node.left);
                    q.Enqueue(node.right);
                }
            }
            while (nodes.Count > 0 && nodes[nodes.Count - 1] == null)   // Remove trailing nulls
            {
                nodes.RemoveAt(nodes.Count - 1);
            }

            List<string> nodesStr = new List<string>();
            foreach (int? node in nodes)
            {
                nodesStr.Add(node == null ? "null" : node.ToString());
            }
            Console.WriteLine(string.Join(", ", nodesStr));
            return nodes;
        }

        static void Main(string[] args)
        {
            Solution sol = new Solution();
            int n = 7;
            IList<TreeNode> r = sol.AllPossibleFBT(n);
            /*
             * [
             *  [0,0,0,null,null,0,0,null,null,0,0],
             *  [0,0,0,null,null,0,0,0,0],
             *  [0,0,0,0,0,0,0],
             *  [0,0,0,0,0,null,null,null,null,0,0],
             *  [0,0,0,0,0,null,null,0,0]
             * ]
             */
            foreach (TreeNode node in r)
            {
                TreeSerialize(node);
            }
            Console.WriteLine();

            n = 3;
            r = sol.AllPossibleFBT(n);
            /*
             * [
             *  [0,0,0]
             * ]
             */
            foreach (TreeNode node in r)
            {
                TreeSerialize(node);
            }
        }
    }
}

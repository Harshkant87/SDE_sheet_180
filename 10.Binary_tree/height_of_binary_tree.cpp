// recursive method:

int heightOfBinaryTree(TreeNode<int> *root)
{
	// Write your code here.
    if(!root) return 0;

    return 1 + max(heightOfBinaryTree(root -> left), heightOfBinaryTree(root -> right));
}

//iterative or level order traversal method: 

public class tUf {
    private static int levelOrder( TreeNode root ){
        if( root == null ){
            return 0;
        }

        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.addLast(root);

        int level = 0;

        while( queue.size() > 0 ){
            int size = queue.size();

            while( size-- > 0 ){
                TreeNode remNode = queue.removeFirst();
                if( remNode.left != null ){
                    queue.addLast( remNode.left );
                }
                if( remNode.right != null ){
                        queue.addLast( remNode.right );
                }
            }

            level++;
        }

        return level;
    }  
}
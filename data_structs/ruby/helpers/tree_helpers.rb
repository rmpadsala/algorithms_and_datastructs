module TreeHelpers
  def self.inorder_traversal(node)
    unless node.nil?
      inorder_traversal(node.left)
      p node.key
      inorder_traversal(node.right)
    end
  end

  def self.preorder_traversal(node)
    unless node.nil?
      p node.key
      preorder_traversal(node.left)
      preorder_traversal(node.right)
    end
  end

  def self.postorder_traversal(node)
    unless node.nil?
      postorder_traversal(node.left)
      postorder_traversal(node.right)
      p node.key
    end
  end

  def self.levelorder_traversal(node)
    unless node.nil?
      queue = [node]
      while queue.any?
        item = queue.shift
        p item.key
        queue << item.left unless item.left.nil?
        queue << item.right unless item.right.nil?
      end
    end
  end
end

module Containers
  module Associative
    class Bst
      class TreeNode
        attr_accessor :left, :right, :value, :key

        def initialize(key, value, left=nil, right=nil)
          @key = key
          @value = value
          @left = left
          @right = right
        end
      end

      attr_accessor :root

      def insert(key, value)
        @root = insert_(key, value, @root)
      end

      def remove(key)
        @root = remove_(key, @root)
      end

      def inorder
        inorder_(@root)
      end

      def preorder
        preorder_(@root)
      end

      def postorder
        postorder_(@root)
      end

      def levelorder
        levelorder_(@root)
      end

      def leaf?(node)
        node.left == nil && node.right == nil
      end

      def min(node)
        return node if node.left.nil?
        min(node.left)
      end

      def max(node)
        return node if node.right.nil?
        max(node.right)
      end

      def get(key)
        get_(key, @root)
      end
      alias_method :[], :get

      private
        def inorder_(node)
          return if node.nil?
          inorder_(node.left)
          p node.key
          inorder_(node.right)
        end

        def preorder_(node)
          return if node.nil?
          p node.key
          preorder_(node.left)
          preorder_(node.right)
        end

        def postorder_(node)
          return if node.nil?
          postorder_(node.left)
          postorder_(node.right)
          p node.key
        end

        def levelorder_(node)
          return if node.nil?
          queue = [node]
          while queue.any?
            item = queue.shift
            puts item.key
            queue << item.left unless item.left.nil?
            queue << item.right unless item.right.nil?
          end
        end

        def get_(key, node)
          return nil if node.nil?

          val = nil
          if key < node.key
            val = get_(key, node.left)
          elsif key > node.key
            val = get_(key, node.right)
          else
            val = node.value
          end
          val
        end

        def insert_(key, value, node)
          return TreeNode.new(key, value) if node.nil?

          if (key < node.key)
            node.left = insert_(key, value, node.left)
          elsif (key > node.key)
            node.right = insert_(key, value, node.right)
          else
            # overwrite value if key is same
            node.value = value
          end
          node
        end

        def delete_min_(node)
          return node.right if node.left.nil?

          node.left = delete_min_(node.left)
          node
        end

        def remove_(key, node)
          return nil if node.nil?

          if key < node.key
            node.left = remove_(key, node.left)
          elsif key > node.key
            node.right = remove_(key, node.right)
          else
            return node.right if node.left.nil?
            return node.left if node.right.nil?

            del_node = node
            node = min(del_node.right)
            node.right = delete_min_(del_node.right)
            node.left = del_node.left
          end
          node
        end
    end
  end
end

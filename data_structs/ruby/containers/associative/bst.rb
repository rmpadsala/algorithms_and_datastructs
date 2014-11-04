module Containers
  module Associative
    class Bst
      class TreeNode
        attr_accessor :left, :right, :value, :key

        def initialize(value, left=nil, right=nil)
          @value = value
          @left = left
          @right = right
          # @key = key
        end
      end

      attr_accessor :root

      def insert(value)
        @root = insert_(value, @root)
      end

      def remove(value)
        @root = remove_(value, @root)
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

      private
        def inorder_(node)
          return if node.nil?
          inorder_(node.left)
          p node.value
          inorder_(node.right)
        end

        def preorder_(node)
          return if node.nil?
          p node.value
          preorder_(node.left)
          preorder_(node.right)
        end

        def postorder_(node)
          return if node.nil?
          postorder_(node.left)
          postorder_(node.right)
          p node.value
        end

        def insert_(value, node)
          return TreeNode.new(value) if node.nil?

          if (value < node.value)
            node.left = insert_(value, node.left)
          elsif (value > node.value)
            node.right = insert_(value, node.right)
          else
            # handle equal
          end
          node
        end

        def delete_min_(node)
          return node.right if node.left.nil?

          node.left = delete_min_(node.left)
          node
        end

        def remove_(value, node)
          return nil if node.nil?

          if value < node.value
            node.left = remove_(value, node.left)
          elsif value > node.value
            node.right = remove_(value, node.right)
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

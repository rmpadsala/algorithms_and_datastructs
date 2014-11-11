require 'ostruct'

module Algorithms
  module TreeProcessing
    class TreeHeight
      def self.height(tree, iterative=false)
        return -1 if tree.nil?
        iterative ? height_iterative(tree.root) : height_recursive(tree.root)
      end

      def self.height_recursive(node)
        return -1 if node.nil?

        return [height_recursive(node.left), height_recursive(node.right)].max + 1
      end

      def self.height_iterative(node)
        return -1 if node.nil?

        # enque first node
        queue = [node]
        height = -1

        while true
          size = queue.size

          return height if size == 0

          height += 1

          while size > 0
            item = queue.shift # dequeue element
            unless item.left.nil?
              queue << item.left
            end

            unless item.right.nil?
              queue << item.right
            end
            size -= 1
          end
        end
      end

      private_class_method :height_iterative, :height_recursive

    end
  end
end

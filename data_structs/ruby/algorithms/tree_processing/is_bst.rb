module Algorithms
  module TreeProcessing
    class IsBst
      def self.bst?(tree)
        root = tree.root

        validate?(root, nil, nil)
      end

      def self.validate?(node, min, max)
        return true if node.nil?

        p "key: #{node.key}, min: #{min}, max: #{max}"

        return false if min != nil && node.key <= min
        return false if max != nil && node.key >= max

        return validate?(node.left, min, node.key) &&
               validate?(node.right, node.key, max)
      end

      private_class_method :validate?
    end
  end
end

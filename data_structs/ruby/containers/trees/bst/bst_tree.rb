require_relative '../tree'

class BstTree < Tree
  class Node
    attr_accessor :value, :left, :right

    def initialize(value, left=nil, right=nil)
      @value = value
      @left = left
      @right = right
    end

    def leaf_node?
      @left.nil? && @right.nil?
    end
  end

  attr_accessor :root, :size

  def initialize
    @size = 0
    @root = nil
  end

  def insert(value)
    insert_(value, @root)
  end

  def find(value)
    find_(value, @root)
  end

  def remove(value)
    remove_(value, @root, nil)
  end

  def empty?
    @root.nil?
  end

  private
    def find_smallest(node)
      smallest = node
      while smallest.left
        smallest = smallest.left
      end
      smallest
    end

    def leaf_node?(node)
      node.leaf_node?
    end

    def root?(node)
      node.value == @root.value
    end

    def make_node_(value)
      @size += 1
      Node.new(value)
    end

    def insert_(value, node)
      if empty?
        @root = make_node_(value)
      elsif value < node.value
        if node.left.nil?
          node.left = make_node_(value)
        else
          insert_(value, node.left)
        end
      elsif value > node.value
        if node.right.nil?
          node.right = make_node_(value)
        else
          insert_(value, node.right)
        end
      else
        raise "Key #{value} already exists"
      end
    end

    def find_(value, node)
      if empty? == false
        if node.value == value
          return true
        elsif value < node.value && node.left != nil
          return find_(value, node.left)
        elsif value > node.value && node.right != nil
          return find_(value, node.right)
        end
      end
      return false
    end

    def delete_node_(value, node, parent, left_child)
      if leaf_node?(node)
        # case-1: element is leaf node
        left_child ? parent.left = node.left : parent.right = node.right
        node = nil
        @size -= 1
      elsif node.left.nil?
        # case-2: either left/right child is nil
        left_child ? parent.left = node.right : parent.right = node.right
        node = nil
        @size -= 1
      elsif node.right.nil?
        # case-2: either left/right child is nil
        left_child ? parent.left = node.left : parent.right = node.left
        node = nil
        @size -= 1
      else
        # case-3: no childs are nil
        smallest = find_smallest(node.right)
        remove_(smallest.value, node, parent)
        node.value = smallest.value
      end
    end

    def remove_(value, node, parent)
      if empty? == false
        if value == node.value
          delete_node_(value, node, parent, false)
        elsif value < node.value && node.left != nil
          if value == node.left.value
            delete_node_(value, node.left, node, true)
          else
            remove_(value, node.left, node)
          end
        elsif value > node.value && node.right != nil
          if value == node.right.value
            delete_node_(value, node.right, node, false)
          else
            remove_(value, node.right, node)
          end
        else
          raise "Remove:: Key #{value} not found"
        end
      else
        raise "Tree is empty"
      end
    end
end

require_relative '../tree'

class BstTree < Tree
  class Node
    attr_reader :value, :left, :right

    def initialize(value, left=nil, right=nil)
      @value = value
      @left = left
      @right = right
    end
  end

  def initialize
    super
  end

  def size
    raise "No implementation exception"
  end

  def insert
    raise "No implementation expception"
  end

  def remove
    raise "No implementation exception"
  end
end

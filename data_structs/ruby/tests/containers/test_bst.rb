require_relative "../../containers/trees/bst/bst_tree"
require "test/unit"

class TestBst < Test::Unit::TestCase
  def test_methods
    obj = BstTree.new
    assert_equal(true, obj.respond_to?(:size))
    assert_equal(true, obj.respond_to?(:insert))
    assert_equal(true, obj.respond_to?(:remove))
    assert_equal(true, obj.respond_to?(:empty?))
    assert_equal(false, obj.respond_to?(:insert_))
  end

  def test_empty
    obj = BstTree.new
    assert_equal(true, obj.empty?)
    assert_equal(0, obj.size)
    assert_nil(obj.root)
  end

  def test_insert_root
    obj = BstTree.new
    obj.insert(10)
    assert_equal(false, obj.empty?)
    assert_not_nil(obj.root)
    assert_nil(obj.root.right)
    assert_nil(obj.root.left)
  end

  def test_insert_left
    obj = BstTree.new
    obj.insert(10)
    obj.insert(9)
    obj.insert(8)
    obj.insert(7)
    assert_equal(false, obj.empty?)
    assert_equal(9, obj.root.left.value)
    assert_equal(8, obj.root.left.left.value)
    assert_equal(7, obj.root.left.left.left.value)
    assert_nil(obj.root.left.left.left.left)
    assert_nil(obj.root.left.left.left.left)
  end

  def test_insert_right
    obj = BstTree.new
    obj.insert(10)
    obj.insert(11)
    obj.insert(12)
    obj.insert(13)
    assert_equal(false, obj.empty?)
    assert_equal(11, obj.root.right.value)
    assert_equal(12, obj.root.right.right.value)
    assert_equal(13, obj.root.right.right.right.value)
    assert_nil(obj.root.right.right.right.right)
    assert_nil(obj.root.right.right.right.left)
  end

  def test_insert
    obj = BstTree.new
    obj.insert(10)
    obj.insert(7)
    obj.insert(6)
    obj.insert(8)
    obj.insert(13)
    obj.insert(11)
    obj.insert(14)
    assert_equal(false, obj.empty?)
    assert_equal(7, obj.root.left.value)
    assert_equal(13, obj.root.right.value)
    assert_equal(6, obj.root.left.left.value)
    assert_equal(8, obj.root.left.right.value)
    assert_equal(11, obj.root.right.left.value)
    assert_equal(14, obj.root.right.right.value)
  end

  def test_size
    obj = BstTree.new
    obj.insert(10)
    obj.insert(7)
    obj.insert(6)
    obj.insert(8)
    obj.insert(13)
    obj.insert(11)
    obj.insert(14)
    assert_equal(7, obj.size)
  end

  def test_find
    obj = BstTree.new
    obj.insert(10)
    obj.insert(7)
    obj.insert(6)
    obj.insert(8)
    obj.insert(13)
    obj.insert(11)
    obj.insert(14)
    assert_equal(true, obj.find(13))
    assert_equal(true, obj.find(8))
    assert_equal(true, obj.find(6))
    assert_equal(false, obj.find(15))
    assert_equal(false, obj.find(2))
  end

  def test_remove
    obj = BstTree.new
    obj.insert(10)
    obj.insert(7)
    obj.insert(6)
    obj.insert(8)
    obj.insert(9)
    obj.insert(13)
    obj.insert(11)
    obj.insert(14)

    assert_equal(true, obj.find(9))
    obj.remove(9)
    assert_equal(false, obj.find(9))

    assert_equal(true, obj.find(8))
    obj.remove(8)
    assert_equal(false, obj.find(8))

    assert_equal(true, obj.find(7))
    obj.remove(7)
    assert_equal(false, obj.find(7))

    assert_equal(true, obj.find(14))
    obj.remove(14)
    assert_equal(false, obj.find(14))

    assert_equal(true, obj.find(13))
    obj.remove(13)
    assert_equal(false, obj.find(13))

    assert_equal(10, obj.root.value)
    assert_equal(6, obj.root.left.value)
    assert_equal(11, obj.root.right.value)
  end

  def test_remove_2_childern
    obj = BstTree.new
    obj.insert(9)
    obj.insert(6)
    obj.insert(7)
    obj.insert(8)
    obj.insert(5)
    obj.insert(14)
    obj.insert(11)
    obj.insert(12)
    obj.insert(10)
    obj.insert(13)
    obj.insert(15)
    obj.insert(17)

    assert_equal(12, obj.size)
    obj.remove(11)
    assert_equal(false, obj.find(11))
    assert_equal(11, obj.size)

    obj.remove(9)
    assert_equal(10, obj.size)
    assert_equal(10, obj.root.value)
    assert_equal(14, obj.root.right.value)
    assert_equal(6, obj.root.left.value)
  end
end

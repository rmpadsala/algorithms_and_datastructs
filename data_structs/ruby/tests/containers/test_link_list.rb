require_relative "../../containers/list/link_list"
require_relative "../../containers/list/list_node"
require "test/unit"

class TestLinkList < Test::Unit::TestCase
  def test_methods
    obj = LinkList.new
    assert_equal(true, obj.respond_to?(:insert_end))
    assert_equal(true, obj.respond_to?(:insert_front))
    assert_equal(true, obj.respond_to?(:remove))
    assert_equal(true, obj.respond_to?(:empty?))
  end

   def test_empty
    obj = LinkList.new
    assert_equal(nil, obj.head)
    assert_equal(nil, obj.tail)
    assert_equal(true, obj.empty?)
  end

  def test_insert_end_empty_list
    obj = LinkList.new
    assert_nil(obj.head)
    assert_nil(obj.tail)

    obj.insert_end(10)
    assert_not_nil(obj.head)
    assert_not_nil(obj.tail)
    assert_equal(false, obj.empty?)
  end

  def test_insert_front_empty_list
    obj = LinkList.new
    assert_nil(obj.head)
    assert_nil(obj.tail)

    obj.insert_end(10)
    assert_not_nil(obj.head)
    assert_not_nil(obj.tail)
    assert_equal(false, obj.empty?)
  end

  def test_insert_end
    obj = LinkList.new
    obj.insert_end(10)
    obj.insert_end(11)
    assert_equal(10, obj.head.value)
    assert_equal(obj.tail, obj.head.next)
    assert_equal(11, obj.tail.value)
    assert_nil(obj.tail.next)
  end

  def test_insert_front
    obj = LinkList.new
    obj.insert_end(10)
    obj.insert_front(11)
    assert_equal(11, obj.head.value)
    assert_equal(obj.tail, obj.head.next)
    assert_equal(10, obj.tail.value)
    assert_nil(obj.tail.next)
  end

  def test_remove
    obj = LinkList.new
    obj.insert_end(10)
    obj.insert_front(11)
    obj.insert_end(12)
    obj.insert_end(19)
    obj.insert_front(12)
    assert_equal(12, obj.head.value)
    assert_equal(19, obj.tail.value)
    obj.remove(10)
    assert_nil(obj.find(15))
  end

  def test_remove_front
    obj = LinkList.new
    obj.insert_end(10)
    obj.insert_front(11)
    obj.insert_end(19)
    obj.insert_front(12)
    assert_equal(12, obj.head.value)
    assert_equal(19, obj.tail.value)
    obj.remove(12)
    assert_nil(obj.find(15))
    assert_equal(11, obj.head.value)
    assert_equal(10, obj.head.next.value)
  end

  def test_remove_back
    obj = LinkList.new
    obj.insert_end(10)
    obj.insert_front(11)
    obj.insert_end(19)
    obj.insert_end(12)
    obj.insert_end(15)
    assert_equal(11, obj.head.value)
    assert_equal(15, obj.tail.value)
    obj.remove(15)
    assert_nil(obj.find(15))
    assert_equal(12, obj.tail.value)
  end

  def test_include
    obj = LinkList.new
    obj.insert_end(10)
    obj.insert_front(11)
    obj.insert_end(12)
    obj.insert_end(19)
    assert_not_nil(obj.find(11))
    assert_nil(obj.find(16))
  end

  private
end

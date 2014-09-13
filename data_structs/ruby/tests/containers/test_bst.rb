require_relative "../../containers/trees/bst/bst_tree"
require "test/unit"

class TestBst < Test::Unit::TestCase
  def test_methods
    obj = BstTree.new
    assert_equal(true, obj.respond_to?(:size))
    assert_equal(true, obj.respond_to?(:insert))
    assert_equal(true, obj.respond_to?(:remove))
  end
end

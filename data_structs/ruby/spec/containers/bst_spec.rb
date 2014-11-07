require "spec_helper"

describe "Bst" do
  before :each do
    @bst_object = Containers::Associative::Bst.new
  end

  describe ".class_methods" do
    it "should respond to class methods" do
      expect(Containers::Associative::Bst).to respond_to(:leaf?)
    end
  end

  describe ".instance_methods" do
    it "should respond to instance methods" do
      expect(@bst_object).to respond_to(:root)
      expect(@bst_object).to respond_to(:insert)
      expect(@bst_object).to respond_to(:remove)
      expect(@bst_object).to respond_to(:min)
      expect(@bst_object).to respond_to(:max)
      expect(@bst_object).to respond_to(:get)
      expect(@bst_object).to respond_to(:[])
      expect(@bst_object).to respond_to(:delete_min)
    end
  end

  describe ".insert" do
    context "insert into empty tree" do
      it "should insert element correctly in empty tree" do
        @bst_object.insert(10, 10)
        expect(@bst_object.root).not_to be_nil
        expect(@bst_object.root.left).to be_nil
        expect(@bst_object.root.right).to be_nil
        expect(@bst_object.root.key).to eq(10)
        expect(@bst_object.root.value).to eq(10)
      end
    end

    context "insert into nonemtpy tree" do
      before { @bst_object.insert(10, 10) }
      it "should insert elements correctly" do

        @bst_object.insert(6, 6)
        @bst_object.insert(15, 15)

        expect(@bst_object.root).not_to be_nil
        expect(@bst_object.root.left).not_to be_nil
        expect(@bst_object.root.right).not_to be_nil
        expect(@bst_object.root.key).to eq(10)
        expect(@bst_object.root.value).to eq(10)
        expect(@bst_object.root.left.key).to eq(6)
        expect(@bst_object.root.left.value).to eq(6)
        expect(@bst_object.root.left.left).to be_nil
        expect(@bst_object.root.left.right).to be_nil

        expect(@bst_object.root.right.key).to eq(15)
        expect(@bst_object.root.right.value).to eq(15)
        expect(@bst_object.root.right.left).to be_nil
        expect(@bst_object.root.right.right).to be_nil

        @bst_object.insert(3,3)
        @bst_object.insert(8,8)
        @bst_object.insert(12,12)
        @bst_object.insert(14,14)
        @bst_object.insert(20,20)
        expect(@bst_object.min(@bst_object.root).key).to eq(3)
        expect(@bst_object.max(@bst_object.root).key).to eq(20)
      end
    end
  end

end

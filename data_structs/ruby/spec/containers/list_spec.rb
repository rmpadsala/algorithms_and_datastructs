require "spec_helper"

describe LinkList do
  before :each do
    @list_obj = LinkList.new
  end

  describe ".instance_methods" do
    it "should respond to instance_methods" do
      expect(@list_obj).to respond_to(:insert_front)
      expect(@list_obj).to respond_to(:insert_end)
      expect(@list_obj).to respond_to(:remove)
      expect(@list_obj).to respond_to(:empty?)
      expect(@list_obj).to respond_to(:find)
    end
  end

  describe ".empty" do
    it "should verify emptyness and set head n' tail pointer to nil" do
      expect(@list_obj.head).to be_nil
      expect(@list_obj.tail).to be_nil
      expect(@list_obj.empty?).to equal(true)
    end
  end

  describe ".insert_end" do
    context "empty_list" do
      it "should insert and set head n' tail pointer to same element" do
        @list_obj.insert_end(10)
        expect(@list_obj.head).not_to be_nil
        expect(@list_obj.tail).not_to be_nil
        expect(@list_obj.head).to equal(@list_obj.tail)
        expect(@list_obj.empty?).to equal(false)
      end
    end

    context "non_empty_list" do
      before do
        @list_obj.insert_end(10)
        @list_obj.insert_end(11)
      end
      it "should insert and set head n' tail pointer to same element" do
        expect(@list_obj.head.value).to equal(10)
        expect(@list_obj.tail.value).to equal(11)
        expect(@list_obj.head.next).to equal(@list_obj.tail)
        expect(@list_obj.tail.next).to be_nil
      end
    end
  end

  describe ".insert_front" do
    context "empty_list" do
      it "should insert and set head n' tail pointer to same element" do
        @list_obj.insert_front(10)
        expect(@list_obj.head).not_to be_nil
        expect(@list_obj.tail).not_to be_nil
        expect(@list_obj.head).to equal(@list_obj.tail)
        expect(@list_obj.empty?).to equal(false)
      end
    end

    context "non_empty_list" do
      before do
        @list_obj.insert_front(10)
        @list_obj.insert_front(11)
      end
      it "should insert and set head n' tail pointer to same element" do
        expect(@list_obj.head.value).to equal(11)
        expect(@list_obj.tail.value).to equal(10)
        expect(@list_obj.head.next).to equal(@list_obj.tail)
        expect(@list_obj.tail.next).to be_nil
      end
    end
  end

  describe ".find" do
    before do
      @list_obj.insert_front(10)
      @list_obj.insert_front(11)
      @list_obj.insert_end(15)
      @list_obj.insert_front(17)
      @list_obj.insert_end(18)
      @list_obj.insert_front(19)
    end

    it "should return element node if found" do
      node = @list_obj.find(15)
      expect(node).not_to be_nil
      expect(node.value).to be(15)
    end

    it "should return nil if not found" do
      node = @list_obj.find(35)
      expect(node).to be_nil
    end
  end

  describe ".remove" do
    before do
      @list_obj.insert_front(10)
      @list_obj.insert_front(11)
      @list_obj.insert_end(15)
      @list_obj.insert_front(17)
      @list_obj.insert_end(18)
      @list_obj.insert_front(19)
      @list_obj.insert_front(30)
      @list_obj.insert_end(48)
      @list_obj.insert_front(49)
    end

    it "should remove node from front" do
      expect(@list_obj.head.value).to be(49)
      expect(@list_obj.head.next.value).to be(30)
      @list_obj.remove(49)
      expect(@list_obj.head.value).to be(30)
      expect(@list_obj.head.next.value).to be(19)
    end

    it "should remove node from back" do
      expect(@list_obj.tail.value).to be(48)
      expect(@list_obj.tail.next).to be_nil
      @list_obj.remove(48)
      expect(@list_obj.tail.value).to be(18)
      expect(@list_obj.tail.next).to be_nil
    end

    it "should remove node from middle" do
      node = @list_obj.find(10)
      expect(node.value).to be(10)
      @list_obj.remove(10)
      node = @list_obj.find(10)
      expect(node).to be_nil
    end
  end
end

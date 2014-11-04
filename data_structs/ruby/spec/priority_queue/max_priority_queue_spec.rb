require 'spec_helper'

describe "MaxPriorityQueue" do
  before :each do
    @object = Algorithms::MaxPriorityQueue.new
  end

  describe "instance_methods" do
    it "should respond to instance methods" do
      expect(@object).to respond_to(:empty?)
      expect(@object).to respond_to(:priority_q)
      expect(@object).to respond_to(:insert)
      expect(@object).to respond_to(:delete_max)
      expect(@object.private_methods.include?(:promote)).to be true
      expect(@object.private_methods.include?(:demote)).to be true
    end
  end
end

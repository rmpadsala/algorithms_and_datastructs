require "spec_helper"

describe "undirect_graph" do
  describe ".instance_methods" do
    before { @undirected_g = Graphs::Undirected::Graph.new(5) }
    it "should respond to instance methods" do
      expect(@undirected_g).to respond_to(:vertices)
      expect(@undirected_g).to respond_to(:edges)
      expect(@undirected_g).to respond_to(:add_edge)
      expect(@undirected_g).to respond_to(:vertices)
    end
  end
end

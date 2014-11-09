require "spec_helper"

describe "undirected_graph" do
  before :each do
    @undirected_g = Graphs::Undirected::Graph.new(5)
  end

  describe ".instance_methods" do
    it "should respond to instance methods" do
      expect(@undirected_g).to respond_to(:vertices)
      expect(@undirected_g).to respond_to(:edges)
      expect(@undirected_g).to respond_to(:add_edge)
      expect(@undirected_g).to respond_to(:vertices)
    end
  end

  describe ".add_edge, .adj" do
    it "should add edge from v to w" do
      @undirected_g.add_edge(1,2)
      @undirected_g.add_edge(2,3)

      expect(@undirected_g.adj(1)).to eq([2])
      expect(@undirected_g.adj(2)).to eq([1,3])
      expect(@undirected_g.adj(3)).to eq([2])
    end
  end

  describe ".edges" do
    it "should set correct number of edges" do
      @undirected_g.add_edge(1,2)
      @undirected_g.add_edge(2,3)
      expect(@undirected_g.edges).to eq(2)
    end
  end
end

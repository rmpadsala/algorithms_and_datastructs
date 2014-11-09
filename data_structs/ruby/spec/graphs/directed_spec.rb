require "spec_helper"

describe "directed_graph" do
  before :each do
    @directed_g = Graphs::Directed::Graph.new(5)
  end

  describe ".instance_methods" do
    it "should respond to instance methods" do
      expect(@directed_g).to respond_to(:vertices)
      expect(@directed_g).to respond_to(:edges)
      expect(@directed_g).to respond_to(:add_edge)
      expect(@directed_g).to respond_to(:vertices)
    end
  end

  describe ".add_edge, .adj" do
    it "should add edge from v to w" do
      @directed_g.add_edge(1,2)
      @directed_g.add_edge(2,3)

      expect(@directed_g.adj(1)).to eq([2])
      expect(@directed_g.adj(2)).to eq([3])
    end
  end

  describe ".edges" do
    it "should set correct number of edges" do
      @directed_g.add_edge(1,2)
      @directed_g.add_edge(2,3)
      expect(@directed_g.edges).to eq(2)
    end
  end
end

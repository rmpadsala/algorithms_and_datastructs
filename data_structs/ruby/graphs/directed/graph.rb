module Graphs
  module Directed
    class Graph
      attr_reader :vertices, :edges

      def initialize(v)
        @vertices = v
        @edges = 0
        @adj = []
        v.times { @adj << [] }
      end

      def add_edge(v, w)
        @adj[v] << w
        @edges += 1
      end

      def adj(v)
        @adj[v]
      end

      # duplicate graph

    end
  end
end

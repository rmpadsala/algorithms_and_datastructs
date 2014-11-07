module Graphs
  module Undirected
    class Graph
      attr_reader :vertices, :edges

      def initialize(v)
        @vertices = v
        @edges = 0
        @adj = []
        v.times { @adj << [] }
      end

      def add_edge(v, w)
        validate(v)
        validate(w)

        @adj[v] << w
        @adj[w] << v
        @edges += 1
      end

      def adj(v)
        validate(v)

        @adj[v]
      end

      def print
        @adj.each_with_index do |v, i|
          v.each do |e|
            p "#{i}->#{e}"
          end
        end
      end
      # duplicate graph
      private
        def validate(v)
          raise "out of bound expception" if v < 0 || v >= vertices
        end
    end
  end
end

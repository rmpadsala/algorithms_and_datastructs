module Algorithms
  module GraphProcessing
    class DepthFirstSearch

      def initialize(graph, source)
        @marked = []
        @edge_to = []
        graph.vertices.times { @marked << false }
        dfs(graph, source)
      end

      private

        def dfs(g, v)
          @marked[v] = true
          g.adj(v).each_with_index do |neighbour, index|
            unless @marked[index]
              @marked[index] = true
              dfs(g, neighbour)
              @edge_to[index] = v
            end
          end
        end
    end
  end
end

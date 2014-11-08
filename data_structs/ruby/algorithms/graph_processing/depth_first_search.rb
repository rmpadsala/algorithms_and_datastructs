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
          g.adj(v).each do |neighbour|
            unless @marked[neighbour]
              @marked[neighbour] = true
              p "before: dfs(g, #{neighbour})"
              dfs(g, neighbour)
              p "after: dfs(g, #{neighbour}), #{neighbour} = #{v}"
              @edge_to[neighbour] = v
            end
          end
        end
    end
  end
end

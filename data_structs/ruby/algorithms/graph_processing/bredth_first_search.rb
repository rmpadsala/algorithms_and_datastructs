module Algorithms
  module GraphProcessing
    class BredthFirstSearch

      def initialize(graph, source)
        @marked = []
        @edge_to = []
        graph.vertices.times { @marked << false }
        bfs(graph, source)
      end

      private

        def bfs(g, v)
          queue = [v]
          @marked[v] = true
          while queue.any?
            item = queue.shift
            g.adj(item).each do |neighbour|
              unless @marked[neighbour]
                queue << neighbour
                @marked[neighbour] = true
                @edge_to[neighbour] = item
              end
            end
          end
        end
    end
  end
end

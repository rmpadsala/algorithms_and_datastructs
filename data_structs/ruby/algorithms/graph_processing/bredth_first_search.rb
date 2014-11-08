module Algorithms
  module GraphProcessing
    class BredthFirstSearch

      def initialize(graph, source)
        @marked = []
        @edge_to = []
        @distance_to = []
        graph.vertices.times { @marked << false }
        bfs(graph, source)
      end

      private

        def bfs(g, v)
          queue = [v]
          @marked[v] = true

          count = 0
          while queue.any?
            item = queue.shift # pop item
            count += 1
            g.adj(item).each do |neighbour|
              unless @marked[neighbour]
                queue << neighbour
                @marked[neighbour] = true
                @edge_to[neighbour] = item
                @distance_to[neighbour] = count
              end
            end
          end
        end
    end
  end
end

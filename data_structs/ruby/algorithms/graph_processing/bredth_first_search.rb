module Algorithms
  module GraphProcessing
    class BredthFirstSearch

      def initialize(graph, source)
        @source = source
        @marked = []
        @edge_to = []
        @distance_to = []
        graph.vertices.times { @marked << false }
        bfs(graph, source)
      end

      def path?(v)
        @marked[v]
      end

      def path_to(v)
        path = []
        if path?(v)
          vertex = v
          while vertex != @source
            path << vertex
            vertex = @edge_to[vertex]
          end
          path << @source
        end
        path
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

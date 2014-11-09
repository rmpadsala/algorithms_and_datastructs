module Algorithms
  module GraphProcessing
    class ConnectedComponents
      attr_reader :count

      def initialize(g)
        @marked = []
        @components = []
        @count = -1
        g.vertices.times { @marked << false }

        index = 0
        g.vertices.times {
          unless @marked[index]
            dfs(g, index)
            @count += 1
          end
          index += 1
        }
      end

      def id(v)
        @components[v]
      end

      def connected?(v, w)
        @components[v] == @components[w]
      end

      private

        def dfs(g, v)
          @marked[v] = true
          @components[v] = @count

          g.adj(v).each do |neighbour|
            unless @marked[neighbour]
              @marked[neighbour] = true
              dfs(g, neighbour)
            end
          end
        end
    end
  end
end

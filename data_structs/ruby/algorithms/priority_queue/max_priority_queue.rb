require_relative '../../utils/utils'

module Algorithms
  class MaxPriorityQueue
    # include Utils

    attr_reader :priority_q

    def initialize
      @queue = [nil]
    end

    def size
      @queue.size
    end

    def empty?
      @queue.empty?
    end

    def priority_q
      @queue
    end

    def insert(item)
      @queue << item
      promote(@queue.size-1)
    end

    def delete_max
      raise "queue is empty" if empty?
      max = @queue[1]
      @queue[1], @queue[size-1] = @queue[size-1], @queue[1]
      @queue.pop # remove last element
      demote(1)
      max
    end

    private
      def compare(left, right)
        left <=> right
      end

      def less(left, right)
        compare(left, right) < 0
      end

      def promote(k)
        while (k > 1 && less(@queue[k/2], @queue[k]))
          @queue[k/2], @queue[k] = @queue[k], @queue[k/2]
          k = k/2
        end
      end

      def demote(k)
        while (2*k <= size)
          j = 2*k
          p "comparing #{j} and #{j + 1}"
          j += 1 if (j < size - 1  && less(@queue[j], @queue[j+1]))

          if less(@queue[k], @queue[j])
            @queue[k], @queue[j] = @queue[j], @queue[k]
          else
            break
          end
          k = j
        end
      end
  end
end

require_relative '../../utils/utils.rb'

module Algorithms
  class MergeSort
    include Utils

    def self.sort(collection, recursive=true)
      recursive ?
        RecursiveSort.new(collection, self).sort :
        IterativeSort.new(collection, self).sort
    end

    def self.merge(collection, aux_ary, low, mid, high)
      # duplicate entire array
      for i in low..high
        aux_ary[i] = collection[i]
      end

      # merge two arrays
      i = low
      j = mid + 1
      for k in low..high
        if i > mid
          collection[k] = aux_ary[j]
          j += 1
        elsif j > high
          collection[k] = aux_ary[i]
          i += 1
        elsif less(aux_ary[i], aux_ary[j])
          collection[k] = aux_ary[i]
          i += 1
        else
          collection[k] = aux_ary[j]
          j += 1
        end
      end
      collection
    end

    private
      class RecursiveSort
        def initialize(collection, parent)
          @collection = collection
          @parent = parent
        end

        def sort_impl(collection, aux_ary, low, high)
          return if low >= high

          mid = low + (high-low)/2
          sort_impl(collection, aux_ary, low, mid)
          sort_impl(collection, aux_ary, mid+1, high)
          @parent.merge(collection, aux_ary, low, mid, high)
        end

        def sort
          return [] unless @collection.kind_of?(Array)
          aux_ary = Array.new(@collection)
          sort_impl(@collection, aux_ary, 0, @collection.size-1)
          @collection
        end
      end

      class IterativeSort
        def initialize(collection, parent)
          @collection = collection
          @parent = parent
        end

        def sort
          return [] unless @collection.kind_of?(Array)
          # aux_ary = Array.new(@collection)
          # sort_impl(@collection, aux_ary, 0, @collection.size-1)
          @collection
        end
      end
  end
end

require_relative '../../utils/utils.rb'

module Algorithms
  class QuickSort
    include Utils

    def self.sort(collection)
      return unless collection.kind_of?(Array)
      # random shuffle first
      collection.shuffle
      sort_impl(collection, 0, collection.size-1)
      collection
    end

    def self.sort_impl(collection, low, high)
      return if low >= high

      pivot = partition(collection, low, high)
      sort_impl(collection, low, pivot-1)
      sort_impl(collection, pivot+1, high)
    end

    def self.partition(collection, low, high)
      return 0 unless collection.any?

      lo = collection[low]
      i = low
      j = high + 1

      while true
        i += 1
        while less(collection[i], lo)
          i += 1
          break if i == high
        end

        j -= 1
        while less(lo, collection[j])
          j -= 1
          break if j == low
        end

        break if i >= j

        collection[i], collection[j] = collection[j], collection[i]
      end

      collection[j], collection[low] = collection[low], collection[j]
      j
    end

    private_class_method :partition
  end

  class QuickSort3Way < QuickSort
  end

  class QuickSortMedianOf3 < QuickSort
  end
end

require_relative '../../utils/utils.rb'

module Algorithms
  class SelectionSort
    include Utils

    def self.sort(collection)
      min = 0

      for i in 0..collection.size-2
        min = i
        for j in i+1..collection.size-1
          min = j if less(collection[j], collection[min])
        end
        collection[i], collection[min] = collection[min], collection[i]
      end
      collection
    end
  end
end

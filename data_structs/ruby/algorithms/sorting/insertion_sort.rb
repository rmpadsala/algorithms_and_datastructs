require_relative '../../utils/utils.rb'

module Algorithms
  class InsertionSort
    include Utils

    def self.sort(collection)
      for i in 1..collection.size-1
        (i).downto(1) do |j|
          break if less(collection[j], collection[j-1]) == false
          collection[j], collection[j-1] = collection[j-1], collection[j]
        end
      end
      collection
    end
  end
end

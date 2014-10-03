require_relative "../../utils/utils.rb"

module Algorithms
  class ShellSort
    include Utils

    def self.sort(collection)
      return [] unless collection.kind_of?(Array)

      h = 1
      size = collection.size
      while h < size/3
        h = 3*h + 1
      end

      while h >= 1
        for i in h..size-1
          j = i
          while j >= h
            if less(collection[j], collection[j-h])
              collection[j], collection[j-h] = collection[j-h], collection[j]
            end
            j -= h
          end
        end
        h = h/3
      end
      collection
    end
  end
end

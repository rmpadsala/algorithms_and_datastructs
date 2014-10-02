module Utils
  module ClassMethods
    def compare(left, right)
      left <=> right
    end

    def less(left, right)
      compare(left, right) < 0
    end

    def sorted?(collection, low=nil, high=nil)
      return false unless collection.kind_of?(Array)
      low ||= 0
      high ||= collection.size-1
      sorted = true
      for i in low+1..high
        return false if collection[i] < collection[i-1]
      end
      sorted
    end
  end

  def self.included(base)
    base.extend(ClassMethods)
  end
end

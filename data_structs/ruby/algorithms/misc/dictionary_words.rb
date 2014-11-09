# { i, like, sam, sung, samsung, mobile, ice, cream, icecream, man, go, mango}

# Input:  ilike
# Output: [i, like]

# Input:  ilikesamsung
# Output: [i, like, sam, sung, samsung]

module Algorithms
  class DictionaryWords

    DICTIONARY = %w{i like sam sung samsung mobile ice cream icecream man go mango}

    attr_reader :words

    def initialize(in_string)
      index = 0
      @words = []
      while index < in_string.length
        @words = dictionary_words_(in_string.slice(index, in_string.length), @words)
        index += 1
      end
    end

    private
      def dictionary_words_(input, out)
        return out if input.empty?

        out << input if DICTIONARY.include?(input) && out.include?(input) == false
        dictionary_words_(input.slice(0, input.length-1), out)
      end

  end
end

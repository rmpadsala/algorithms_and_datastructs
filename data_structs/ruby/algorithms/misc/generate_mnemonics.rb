module Algorithms
  class GenerateMnemonics
    NUMBER_TO_CHARS = {
      1=> '1',
      2=> 'abc2',
      3=> 'def3',
      4=> 'ghi4',
      5=> 'jkl5',
      6=> 'mno6',
      7=> 'pqrs7',
      8=> 'tuv8',
      9=> 'wxyz9',
      0=> '0'
    }

    def initialize(number)
      number_s = number.to_s
      @first = number_s.slice(0)
      @rest = number_s.slice(1, number_s.length)
    end

    def mnemonics
      out = NUMBER_TO_CHARS[@first.to_i].chars.map { |c| c }

      @rest.each_char do |c|
        ret = []
        mapped_letters = NUMBER_TO_CHARS[c.to_i]
        out.each do |item|
          mapped_letters.each_char do |m_c|
            ret << "#{item}#{m_c}"
          end
        end
        out = ret
      end
      out
    end

    def mnemonics_recursive
      out = NUMBER_TO_CHARS[@first.to_i].chars.map { |c| c }
      mnemonics_recursive_(@rest, out)
    end

    private
      def mnemonics_recursive_(string, out)
        return out if string.empty?

        first = string.slice(0)
        mapped_letters = NUMBER_TO_CHARS[first.to_i]

        out.map! do |item|
          mapped_letters.chars.map { |c| "#{item}#{c}" }
        end.flatten!

        mnemonics_recursive_(string.slice(1, string.length), out)
      end

  end
end

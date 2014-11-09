module Algorithms
  class GenerateMnemonics
    NUMBER_TO_CHARS = {
      1=> '1',
      2=> 'abc',
      3=> 'def',
      4=> 'ghi',
      5=> 'jkl',
      6=> 'mno',
      7=> 'pqrs',
      8=> 'tuv',
      9=> 'wxyz',
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

  end
end

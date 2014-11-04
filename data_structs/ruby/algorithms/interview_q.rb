# I would like to have a program that takes in a phone number, and returns the 'mnemonics' that might be associated with it. Mnemonics are letters that people can use to remember numbers, such as 555-4 PIZZA

# The following numeric-to-character correspondances exist:

# 1 - ''
# 2 - abc
# 3 - def
# 4 - ghi
# 5 - jkl
# 6 - mno
# 7 - pqrs
# 8 - tuv
# 9 - wxyz
# 0 - ''

# Numbers can also stand for themselves.  How would you build this?

number_to_chars = {
  1=> '',
  2=> 'abc',
  3=> 'def',
  4=> 'ghi',
  5=> 'jkl',
  6=> 'mno',
  7=> 'pqrs',
  8=> 'tuv',
  9=> 'wxyz',
  0=> ''
}

# number: 345
# output: dgj, dgk, dgl, dhj, dhk, dhl, dij, dik, dil,
# egj, egk, egl, ehj, ehk, ehl, eij, eik, eil, fgj, fgk,
# fgl, fhj, fhl, fhk, fij, fik, fil

def generate_mnemonics(number)
  ret = []
  number_to_chars = {
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
  number.to_s.each_char do |n|
    out = []
    prefix = number_to_chars[n.to_i]
    puts prefix
    prefix.each_char do |p|
      puts p
      if ret.any?
        ret.each do |str|
          str += p
          out << str
        end
      else
        out << p
      end
      p out
    end
    ret = out
  end
  ret
end

generate_mnemonics(345)

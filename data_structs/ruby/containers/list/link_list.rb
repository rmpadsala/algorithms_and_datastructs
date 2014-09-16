class LinkList
  attr_accessor :head, :tail

  def initialize(head=nil, tail=nil)
    @head = head
    @tail = tail
  end

  def empty?
    @head == nil && @tail == nil
  end

  def insert_end(value)
    node = ListNode.new(value)

    if empty?
      @head = node
      @tail = node
    else
      @tail.next = node
      @tail = node
    end
  end

  def insert_front(value)
    node = ListNode.new(value)

    if empty?
      @head = node
      @tail = node
    else
      node.next = @head
      @head = node
    end
  end

  def remove(value)
    if empty? == false
      if @head.value == value

        if @head.next == nil
          @head = nil
        else
          node = @head
          @head = @head.next
          node = nil
        end
      else
        prev = @head
        current = @head

        while current
          if current.value == value
            break
          end
          prev = current
          current = current.next
        end

        prev.next = current.next
        @tail = prev if current.next == nil
        current = nil
      end
    end
  end

  def find(value)
    node = @head
    while node
      if node.value == value
        return node
      end
      node = node.next
    end
    nil
  end

  def print
    node = @head
    array = []
    while node
      array << "#{node.value}"
      node = node.next
    end

    puts "#{array.join('->')}"
  end

end

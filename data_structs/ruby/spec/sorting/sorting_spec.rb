require 'spec_helper'

describe "Sorting" do
  before :each do
    @collection = [10, 11, 25, 98, 46, 35, 22, 54, 47]
  end

  describe "#selection_sort" do
    it "should correctly sort elements" do
      sorted_collection = Algorithms::SelectionSort.sort(@collection)
      expect(Algorithms::SelectionSort.sorted?(sorted_collection)).to be true
    end
  end

  describe "#insertion_sort" do
    it "should correctly sort elements" do
      sorted_collection = Algorithms::InsertionSort.sort(@collection)
      expect(Algorithms::InsertionSort.sorted?(sorted_collection)).to be true
    end
  end

  describe "#merge_sort" do
    it "should correctly sort elements" do
      @collection + [88, 3, 5, 7, 102]
      sorted_collection = Algorithms::MergeSort.sort(@collection)
      expect(Algorithms::MergeSort.sorted?(sorted_collection)).to be true
    end
  end
end

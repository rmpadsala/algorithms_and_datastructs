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

  describe "#shell_sort" do
    it "should correctly sort elements" do
      @collection + [3, 88, 102]
      sorted_collection = Algorithms::ShellSort.sort(@collection)
      expect(Algorithms::ShellSort.sorted?(sorted_collection)).to be true
    end
  end

  describe "#shell_sort" do
    it "should correctly sort elements" do
      @collection = [46, 71, 73, 77, 68, 18, 67, 60, 84, 46, 43, 29, 46]
      sorted_collection = Algorithms::QuickSort.sort(@collection)
      expect(Algorithms::QuickSort.sorted?(sorted_collection)).to be true
    end
  end
end

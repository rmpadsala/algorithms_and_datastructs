# load all the classes


DIR_PATHS = ["./containers/sequence",
  "./containers/associative",
  "./algorithms/sorting",
  "./algorithms/priority_queue",
  "./graphs/directed",
  "./graphs/undirected",
  "./spec/helpers"
]

DIR_PATHS.each do |path|
  rb_all = Dir["#{path}/*.rb"]
  rb_all.each do |file|
    require file
  end
end


# load all the classes


DIR_PATHS = ["./containers/list",
  "./containers/trees/bst",
  "./algorithms/sorting",
  "./spec/helpers"
]

DIR_PATHS.each do |path|
  rb_all = Dir["#{path}/*.rb"]
  rb_all.each do |file|
    require file
  end
end


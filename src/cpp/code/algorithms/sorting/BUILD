cc_library(
    name = "array_utils",
    srcs = ["array_utils.cpp"],
    hdrs = ["array_utils.h"],
)

cc_binary(
    name = "bubble_sort",
    srcs = ["bubble_sort.cpp"],
    deps = [
        ":array_utils",
    ]
)

cc_binary(
    name = "selection_sort",
    srcs = ["selection_sort.cpp"],
    deps = [
        ":array_utils",
    ],
)

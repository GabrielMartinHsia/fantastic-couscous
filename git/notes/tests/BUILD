from multiprocessing.pool import RUN


load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "tests",
    srcs = glob(["**/*.cc"]),
    deps = [
        "//src/lib:CPPLib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "grader_tests",
    srcs = glob(["**/*grader_test.cc"]),
    deps = [
        "//src/lib:CPPLib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "q2_student_test",
    srcs = ["q2_student_test.cc"],
    deps = [
        "//src/lib:CPPLib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "test_intersect",
    srcs = ["test_intersect.cc"],
    deps = [
        "//src/lib:CPPLib",
        "@com_google_googletest//:gtest_main",
    ],
)
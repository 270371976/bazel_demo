load("@rules_cc//cc:defs.bzl", "cc_proto_library") 
load("@rules_proto//proto:defs.bzl", "proto_library") 
package(default_visibility = ["//visibility:public"]) 

cc_proto_library( 
    name = "msg_cc_pb", 
    deps = [":msg"], 
) 

proto_library( 
    name = "msg", 
    srcs = ["msg.proto"], 
) 


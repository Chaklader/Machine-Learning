#!/usr/bin/env sh

TOOLS=./build/tools

$TOOLS/caffe train \
    --solver=examples/cifar10/cifar10_caffenet_solver.prototxt\
    --weights=models/bvlc_reference_caffenet/bvlc_reference_caffenet.caffemodel
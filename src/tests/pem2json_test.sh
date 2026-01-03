#!/bin/bash

cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug
cp sample_cert.pem build/
cd build && make && ./pem2json_test
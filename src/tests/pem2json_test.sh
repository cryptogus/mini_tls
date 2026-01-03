#!/bin/bash

cmake -B build -S .
cd build && make && ./pem2json_test
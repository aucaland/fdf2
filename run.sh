#!/bin/bash
make
valgrind --show-leak-kinds=all --leak-check=full --track-fds=yes --verbose --show-mismatched-frees=yes --log-file=valgrind-out.log ./fdf test_maps/42.fdf


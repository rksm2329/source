#!/bin/bash

task="automata"
memory=1048576 # 1024 MB
stack_size=1048576  # 1024 MB

ulimit -v "${memory}"
ulimit -s "${stack_size}"
"./${task}"

verilator -Wno-UNUSED -Wno-WIDTH -y ../IP/Core --cc Core.v --exe main.cpp
make -j -C obj_dir/ -f VCore.mk VCore

CC = /opt/riscv64/bin/riscv64-unknown-elf-gcc
ELFSIZE = /opt/riscv64/bin/riscv64-unknown-elf-size
OBJCOPY = /opt/riscv64/bin/riscv64-unknown-elf-objcopy

CFLAGS = -I./ -I/simple -O2 -DITERATIONS=4000 -mabi=ilp32 -march=rv32im -mno-div -static -fno-common -funroll-loops -finline-functions --param max-inline-insns-auto=20 -falign-functions=4 -falign-jumps=4 -falign-loops=4
LDFLAGS = -Tlink.ld --specs=nano.specs -nostartfiles -fno-builtin-printf

SRCS =  core_main.c core_list_join.c core_matrix.c core_state.c core_util.c simple/core_portme.c


.PHONY: all
all: mem_init_generate

coremark.elf: $(SRCS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	$(ELFSIZE) $@

mem_init/sys_onchip_memory2_0.hex: coremark.elf
	$(OBJCOPY) -O binary --gap-fill 0 $< mem_init/sys_onchip_memory2_0.bin
	mem_init/bin2hex_2 mem_init/sys_onchip_memory2_0.bin mem_init/sys_onchip_memory2_0.hex

.PHONY: mem_init_generate
mem_init_generate: mem_init/sys_onchip_memory2_0.hex


.PHONY: clean
clean:
	rm -f *.elf mem_init/*.hex mem_init/*.bin

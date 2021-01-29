CC = /opt/riscv64/bin/riscv64-unknown-elf-gcc
ELFSIZE = /opt/riscv64/bin/riscv64-unknown-elf-size
OBJCOPY = /opt/riscv64/bin/riscv64-unknown-elf-objcopy

CFLAGS =  -Os -mabi=ilp32 -march=rv32i
LDFLAGS = -Tlink.ld -fno-builtin-printf --specs=nano.specs -nostartfiles

SRCS =  main.c


.PHONY: all
all: mem_init_generate

main.elf: $(SRCS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	$(ELFSIZE) $@

mem_init/sys_onchip_memory2_0.hex: main.elf
	$(OBJCOPY) -O binary --gap-fill 0 $< ../mem_init/sys_onchip_memory2_0.bin
	$(OBJCOPY) -O verilog --gap-fill 0 $< ../mem_init/sys_onchip_memory2_0.vh
	./bin2hex_2 ../mem_init/sys_onchip_memory2_0.bin ../mem_init/sys_onchip_memory2_0.hex

.PHONY: mem_init_generate
mem_init_generate: mem_init/sys_onchip_memory2_0.hex


.PHONY: clean
clean:
	rm -f *.elf

CC = /opt/riscv64/bin/riscv64-unknown-elf-gcc
ELFSIZE = /opt/riscv64/bin/riscv64-unknown-elf-size
OBJCOPY = /opt/riscv64/bin/riscv64-unknown-elf-objcopy

CFLAGS = -I./ -O2 -mabi=ilp32 -march=rv32im -mno-div
LDFLAGS = -Tlink.ld --specs=nano.specs -nostartfiles -fno-builtin-printf

SRCS =  main.c


.PHONY: all
all: mem_init_generate

main.elf: $(SRCS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	$(ELFSIZE) $@

mem_init/sys_onchip_memory2_0.hex: main.elf
	$(OBJCOPY) -O binary --gap-fill 0 $< mem_init/sys_onchip_memory2_0.bin
	mem_init/bin2hex_2 mem_init/sys_onchip_memory2_0.bin mem_init/sys_onchip_memory2_0.hex

.PHONY: mem_init_generate
mem_init_generate: mem_init/sys_onchip_memory2_0.hex


.PHONY: clean
clean:
	rm -f *.elf mem_init/*.hex mem_init/*.bin

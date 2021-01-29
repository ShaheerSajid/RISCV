CC = /opt/riscv64/bin/riscv64-unknown-elf-gcc
ELFSIZE = /opt/riscv64/bin/riscv64-unknown-elf-size
OBJCOPY = /opt/riscv64/bin/riscv64-unknown-elf-objcopy

CFLAGS = -O3 -mabi=ilp32 -march=rv32i -static -DTIME -DNOENUM -Wno-implicit -fno-common -falign-functions=4
LDFLAGS = -Tlink.ld -fno-builtin-printf --specs=nosys.specs -nostartfiles

SRCS = dhry_1.c dhry_2.c


.PHONY: all
all: mem_init_generate

dhry.elf: $(SRCS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	$(ELFSIZE) $@

mem_init/sys_onchip_memory2_0.hex: dhry.elf
	$(OBJCOPY) -O binary --gap-fill 0 $< ../../mem_init/sys_onchip_memory2_0.bin
	$(OBJCOPY) -O verilog --gap-fill 0 $< ../../mem_init/sys_onchip_memory2_0.vh
	./bin2hex_2 ../../mem_init/sys_onchip_memory2_0.bin ../../mem_init/sys_onchip_memory2_0.hex

.PHONY: mem_init_generate
mem_init_generate: mem_init/sys_onchip_memory2_0.hex


.PHONY: clean
clean:
	rm -f *.elf

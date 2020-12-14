CC = /opt/riscv64/bin/riscv64-unknown-elf-gcc
ELFSIZE = /opt/riscv64/bin/riscv64-unknown-elf-size
OBJCOPY = /opt/riscv64/bin/riscv64-unknown-elf-objcopy

CFLAGS = -O3 -mabi=ilp32 -march=rv32im -mno-div -finline-functions -static -DTIME -DNOENUM -Wno-implicit -fno-builtin-printf -fno-common -falign-functions=4 -fno-builtin-printf
LDFLAGS = -Tlink.ld --specs=nano.specs -nostartfiles

SRCS = dhry_1.c dhry_2.c strcmp.S


.PHONY: all
all: mem_init_generate

dhry.elf: $(SRCS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	$(ELFSIZE) $@

mem_init/sys_onchip_memory2_0.hex: dhry.elf
	$(OBJCOPY) -O binary --gap-fill 0 $< mem_init/sys_onchip_memory2_0.bin
	mem_init/bin2hex_2 mem_init/sys_onchip_memory2_0.bin mem_init/sys_onchip_memory2_0.hex

.PHONY: mem_init_generate
mem_init_generate: mem_init/sys_onchip_memory2_0.hex


.PHONY: clean
clean:
	rm -f *.elf mem_init/*.hex mem_init/*.bin

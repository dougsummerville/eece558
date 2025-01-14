flashled.uf2: flashled.elf
	python3 tools/elf2uf2.py $<
flashled.elf: flashled.c
	arm-none-eabi-gcc -Os  -std=c99 -ffreestanding -nostartfiles -mcpu=cortex-m33 -T pico2.ld flashled.c -o flashled.elf
clean:
	-rm flashled.uf2 flashled.elf

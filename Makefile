EMU = demul.exe
SCR = ./tool/scramble
CDI = ./tool/cdi4dc
ISO = mkisofs

CC  = sh-elf-gcc
CXX = sh-elf-g++
AS  = sh-elf-as
LD  = sh-elf-ld
AR  = sh-elf-ar
OBJ = sh-elf-objcopy
NM  = sh-elf-nm

ARFLAGS   = rv
ASFLAGS   = -little
CFLAGS    = -ml -m4-single -fomit-frame-pointer -nostartfiles -Wl,-Ttext=0x8C010000
CXX_FLAGS = -std=c++17 $(CFLAGS)


all: src/crt0.s src/main.cpp
	$(CXX) $(CXX_FLAGS) $^ -o a.out
	$(OBJ) -R .stack -O binary a.out a.bin
	$(SCR) a.bin ./disc/1ST_READ.BIN
	$(ISO) -V EVAL_DISC -G IP.BIN -J -r -l -o test.iso disc
	$(CDI) test.iso test.cdi -d
	$(RM) a.out a.bin disc/1ST_READ.BIN test.iso
	$(EMU) -run=dc -image=test.cdi

.PHONY: clean
clean:
	$(RM) a.out a.bin disc/1ST_READ.BIN test.iso test.cdi
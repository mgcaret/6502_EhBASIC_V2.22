ACMD=java -jar ~/bin/AppleCommander-1.3.5-ac.jar
NULIB2=nulib2
BOOTDSK=~/vii_hd.2mg

.PHONY: all
all: ehbasic shk disk

emulate: boot.dsk ehbasic.po
	open boot.dsk ehbasic.po -a 'Virtual ]['

.phony: disk
disk: ehbasic.po

ehbasic.po: ehbasic
	$(ACMD) -pro140 ehbasic.po EHBASIC
	$(ACMD) -p ehbasic.po EHBASIC SYS < ehbasic

.phony: shk
shk: EHBASIC.SHK

EHBASIC.SHK: ehbasic
	cp -f ehbasic 'EHBASIC#FF0000'
	nulib2 -aue EHBASIC.SHK 'EHBASIC#FF0000'
	rm -f 'EHBASIC#FF0000'

ehbasic: ehbasic.o ehbasic.l
	ld65 -C ehbasic.l -m ehbasic.map -o ehbasic ehbasic.o

ehbasic.o: ehbasic.asm ehbasic-ca65.inc
	ca65 -o ehbasic.o -l ehbasic.lst ehbasic.asm

.PHONY: clean
clean:
	rm -f ehbasic.po ehbasic ehbasic.o *.map *.lst EHBASIC.SHK 'EHBASIC#FF0000'


#!/bin/bash
set -e -x
ca65 ehbasic.asm -l ehbasic.lst
ld65 -C ehbasic.l -m ehbasic.map -o ehbasic ehbasic.o


APPLE2 = 1                      ; enable Apple II mods
NO_INT = 1                      ; disable interrupt handling
LOW_TOKENS = 1                  ; enable tokens 1-31
; APPLE2_128K = 1               ; enable 128K Apple II

; Version of Apple ][ Port
VERSION = $01

NUM_FILE_BUFS = 2   ; default # of 1K buffers to reserve below memory
                    ; one more will be added for whatever we need to do

.feature labels_without_colons

; ProDOS equates
P8_GLOBAL     = $BF00
P8_MLI        = P8_GLOBAL       ; MLI entry point
P8_MEMTAB     = P8_GLOBAL+$58   ; Memory protection table
P8_DATE       = P8_GLOBAL+$90
P8_TIME       = P8_GLOBAL+$92
P8_FILE_LEVEL = P8_GLOBAL+$94   ; File level, see techref
P8_MACHID     = P8_GLOBAL+$98   ; Machine ID
P8_SLTBYT     = P8_GLOBAL+$99   ; 1 bits indicate slots with firmware
P8_PFIXPTR    = P8_GLOBAL+$9A   ; $00 = no prefix set
P8_IVERSION   = P8_GLOBAL+$FD   ; running interpreter version
P8_KVERSION   = P8_GLOBAL+$FF   ; ProDOS version

; Firmware equates
; U=undefined, V=a defined value, see docs
F8_INIT       = $FB2F   ; O:A=V,XY=U
F8_HOME       = $FC58   ; O:AY=U,X=X
F8_CLREOL     = $FC9C   ; O:AY=U,X=X
F8_WAIT       = $FCA8   ; O:A=$00,XY=XY
F8_KEYIN      = $FD1B   ; O:A=V,X=X,Y=U
F8_COUT1      = $FDF0   ; O:AXY=AXY
F8_MOVE       = $FE2C   ; O:AXY=U
F8_SETINV     = $FE80   ; O:AX=AX,Y=U
F8_SETNORM    = $FE84   ; O:AX=AX,Y=U
F8_SETKBD     = $FE89   ; O:AXY=U
F8_SETVID     = $FE93   ; O:AXY=U
F8_MONITOR    = $FF69   ; doesn't return

; Page 0 equates (not EhBASIC)
ZP_WNDLFT     = $20     ; window left
ZP_WNDWDTH    = $21     ; window width
ZP_WNDTOP     = $22     ; window top
ZP_WNDBTM     = $23     ; window bottom
ZP_CH         = $24     ; cursor horizontal
ZP_CV         = $25     ; cursor vertical
ZP_A1         = $3C     ; monitor addresses
ZP_A2         = $3E
ZP_A4         = $42
ZP_BASL       = $28     ; screen row base address
ZP_BASH       = $29
ZP_CSWL       = $36     ; Monitor display vector
ZP_CSWH       = $37
ZP_KSWL       = $38     ; Monitor keyboard vector
ZP_KSWH       = $39
ZP_RNDL       = $4E     ; updated by KEYIN
ZP_RNDH       = $4F     ; updated by KEYIN

; Page 3 equates
SOFTEV        = $3F2
POWERUP       = $3F4
CTRL_Y        = $3F8

; Hardware equates
KBD           = $C000
KBD_STROBE    = $C010

; value equates
MAGIC_A5      = $A5
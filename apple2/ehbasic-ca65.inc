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
F8_PLOT       = $F800   ; O:A=U,XY=XY     I:Y,A = XY coordinates
F8_PLOT1      = $F80E   ; O:A=U,XY=XY     I:Y=X coord, (ZP_GBASL) = row pointer
F8_HLINE      = $F819   ; O:AY=U,X=X      I:Y,A = XY start, ZP_H2 = end col
F8_VLINE      = $F828   ; O:AY=U,X=X      I:Y,A = XY start, ZP_H2 = end row
F8_CLRSCR     = $F832   ; O:AY=U,X=X      clear GR screen
F8_CLRTOP     = $F836   ; O:AY=U,X=X      clr GR screen, mixed mode
F8_GBASCALC   = $F847   ; O:A=V,XY=XY     A=rownum.  calculate (ZP_GBASL)

; text, keyboard
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
; NOTE EhBASIC uses $00-$13, $5B-$DB
; and with interrupt support, $DC-$E1

; Text & monitor stuff
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

; Graphics stuff
; $1A-$1B - Shape Pointer for DRAW
; $1C     - Last COLOR Used
ZP_GBASL      = $26
ZP_GBASH      = $27
ZP_H2         = $2C     ; Lo-Res HLIN Endpoint
ZP_V2         = $2D     ; Lo-Res VLIN Endpoint
ZP_MASK       = $2E
ZP_COLOR      = $30     ; Lo-res COLOR Value * 17
; $32     - Text Mask ($FF = Normal, $7F = Inverse, $3F = Flashing)
;$E0-$E1 - Horizontal Coordinate of HPLOT
;$E2     - Vertical Coordinate of HPLOT
;$E3     - Free Space
;$E4     - HCOLOR Value (0=0, 1=42, 2=85, 3=127, 4=128, 5=170, 6=213, 7=255)
;$E6     - High Byte of Address of First Byte of Where HGR is Plotted
;$E7     - SCALE Value (0 = 256)
;$E8-$E9 - Address of Shape Table
;$EA     - DRAW/XDRAW Collision Count


; Page 3 equates
SOFTEV        = $3F2
POWERUP       = $3F4
CTRL_Y        = $3F8

; Hardware equates
KBD           = $C000
KBD_STROBE    = $C010
SETALTCHAR    = $C00F

; value equates
MAGIC_A5      = $A5

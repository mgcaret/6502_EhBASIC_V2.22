APPLE2 = 1                      ; enable Apple II mods
NO_INT = 1                      ; disable interrupt handling
LOW_TOKENS = 1                  ; enable tokens 1-31
MIXED_CASE = 1                  ; allow mixed-case keywords
; APPLE2_128K = 1               ; enable 128K Apple II

; Version of Apple ][ Port
VERSION = $01

.feature labels_without_colons

; ProDOS equates
P8_GLOBAL     = $BF00
P8_MLI        = P8_GLOBAL       ; MLI entry point
P8_DEVNUM     = P8_GLOBAL+$30   ; Last used device
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

; Hi-res Graphics
F0_HGR2       = $F3D8   ; set hgr2 mode and clear hires
F0_HGR        = $F3E2   ; set hgr mode and clear hires
F0_HCLR       = $F3F2   ; clear hires screen
F0_BKGND      = $F3F6   ; clear to color
F0_HPOSN      = $F411   ; I:YX=H,A=V  position hgr cursor
F0_HPLOT0     = $F457   ; I:YX=H,A=V  plot point
F0_HLINRL     = $F530   ; I:AX=dX,Y=dY  plot +/i current position
F0_HGLIN      = $F53A   ; I:AX=X,Y=Y  draw line to
F0_HFIND      = $F5CB   ; Calc X and Y coord from GBASL/H & horizontal and mask

; Lo-res Graphics
; U=undefined, V=a defined value, see docs
F0_GR         = $F390
F0_TEXT       = $F399
F8_PLOT       = $F800   ; O:A=U,XY=XY     I:Y,A = XY coordinates
F8_PLOT1      = $F80E   ; O:A=U,XY=XY     I:Y=X coord, (ZP_GBASL) = row pointer
F8_HLINE      = $F819   ; O:AY=U,X=X      I:Y,A = XY start, ZP_H2 = end col
F8_VLINE      = $F828   ; O:AY=U,X=X      I:Y,A = XY start, ZP_V2 = end row
F8_CLRSCR     = $F832   ; O:AY=U,X=X      clear GR screen
F8_CLRTOP     = $F836   ; O:AY=U,X=X      clr GR screen, mixed mode
F8_GBASCALC   = $F847   ; O:A=V,XY=XY     A=rownum.  calculate (ZP_GBASL)
F8_SCRN       = $F871   ; 

; text, keyboard, game
F8_PREAD      = $FB1E   ; O:A=U,X=X,Y=V   I:X=0-3
F8_INIT       = $FB2F   ; O:A=V,XY=U
F8_TABV       = $FB5B   ;
F8_ADVANCE    = $FBF4   ; 
F8_BELL1      = $FBDD   ; O:A=U,X=X,Y=0
F8_CLREOP     = $FC42
F8_HOME       = $FC58   ; O:AY=U,X=X
F8_LF         = $FC66   ; 
F8_SCROLL     = $FC70   ; 
F8_CLREOL     = $FC9C   ; O:AY=U,X=X
F8_UP         = $FC1A
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
; NOTE EhBASIC uses $00-$13, $5B-$DB, $EF-$FF
; and with interrupt support, $DC-$E1

; Text & monitor stuff
ZP_WNDLFT     = $20     ; window left
ZP_WNDWDTH    = $21     ; window width
ZP_WNDTOP     = $22     ; window top
ZP_WNDBTM     = $23     ; window bottom
ZP_CH         = $24     ; cursor horizontal
ZP_CV         = $25     ; cursor vertical
ZP_TXTMASK    = $32     ; $FF = Normal, $7F = Inverse, $3F = Flashing
ZP_PROMPT     = $33
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
ZP_SHAPE1     = $1A     ; shape & fill pointer
ZP_SHAPE1L    = ZP_SHAPE1
ZP_SHAPE1H    = $1B
ZP_HGR_BITS   = $1C     ; hi res color
ZP_GBASL      = $26
ZP_GBASH      = $27
ZP_H2         = $2C     ; Lo-Res HLIN Endpoint
ZP_V2         = $2D     ; Lo-Res VLIN Endpoint
ZP_MASK       = $2E
ZP_COLOR      = $30     ; Lo-res COLOR Value * 17
ZP_HCURSOR_X  = $E0
ZP_HCURSOR_XL = ZP_HCURSOR_X
ZP_HCURSOR_XH = $E1     ; Horizontal Coordinate of HPLOT
ZP_HCURSOR_V  = $E2     ; Vertical Coordinate of HPLOT
;$E3     - unused
ZP_SCREEN     = $E3     ; it's used now, sucker!
ZP_HCOLOR     = $E4     ; HCOLOR Value (0=0, 1=42, 2=85, 3=127, 4=128, 5=170, 6=213, 7=255)
ZP_HGRPAGE    = $E6     ; $20 or $40
ZP_SCALE      = $E7     ; SCALE Value (0 = 256)
ZP_SHAPEL     = $E8
ZP_SHAPEH     = $E9     ; Address of Shape Table
ZP_DRAWCOL    = $EA     ; DRAW/XDRAW Collision Count

; Page 3 equates
SOFTEV        = $3F2
POWERUP       = $3F4
CTRL_Y        = $3F8

; Hardware equates
KBD           = $C000   ; R
STORE80OFF    = $C000   ; W
STORE80ON     = $C001   ; W
RDMAINRAM     = $C002   ; W
RDCARDRAM     = $C003   ; W
WRMAINRAM     = $C004   ; W
WRCARDRAM     = $C005   ; W
SETSLOTCXROM  = $C006   ; W
SETINTCXROM   = $C007   ; W
SETSTDZP      = $C008   ; W
SETALTZP      = $C009   ; W
SETINTC3ROM   = $C00A   ; W
SETSLOTC3ROM  = $C00B   ; W
CLR80VID      = $C00C   ; W
SET80VID      = $C00D   ; W
CLRALTCHAR    = $C00E   ; W
SETALTCHAR    = $C00F   ; W
KBD_STROBE    = $C010   ; R or risk losing keystrokes
RDLCBANK2     = $C011
RDLCRAM       = $C012
RDRAMRD       = $C013
RDRAMWRT      = $C014
RDCXROM       = $C015
RDALTZP       = $C016
RDC3ROM       = $C017
RD80STORE     = $C018
RDVBL         = $C019
RDTEXT        = $C01A
RDMIXED       = $C01B
RDPAGE2       = $C01C
RDHIRES       = $C01D
RDALTCHAR     = $C01E
RD80VID       = $C01F
SPKR          = $C030
TXTCLR        = $C050   ; Graphics on
TXTSET        = $C051
MIXCLR        = $C052
MIXSET        = $C053
TXTPAGE1      = $C054
TXTPAGE2      = $C055
LORES         = $C056
HIRES         = $C057
DHIRESON      = $C05E
DHIRESOFF     = $C05F
TAPEIN        = $C060   ; //e
BUTN3         = $C060   ; //c (40/80), IIgs
BUTN0         = $C061
BUTN1         = $C062
BUTN2         = $C063

; value equates
MAGIC_A5      = $A5

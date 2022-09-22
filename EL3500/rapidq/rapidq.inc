' RAPIDQ.INC  -- Include file for RAPID-Q by William Yu
'             -- attach a $INCLUDE "RAPIDQ.INC"
'             -- to all your programs, or just extract what you need.


$IFNDEF __RQINC

$DEFINE __RQINC
$DEFINE __QBCOLOR

'------------------------- Useful variables -------------------------
CONST False = 0
CONST True = 1

'-- Control Alignments
CONST alNone = 0
CONST alTop = 1
CONST alBottom = 2
CONST alLeft = 3
CONST alRight = 4
CONST alClient = 5           '-- Expand to fit client

'-- Text Alignments
CONST taLeftJustify = 0
CONST taRightJustify = 1
CONST taCenter = 2


CONST SND_SYNC = 0           '-- Synchronous playback (Wait for sound to finish)
CONST SND_ASYNC = 1          '-- Asynchronous playback (Like background play).
CONST SND_LOOP = 8           '-- Loop sound
Const SND_NODEFAULT = &H2
Const SND_NOSTOP = &H10
Const SND_MEMORY = &H4

'-- BASIC Colors
CONST clBlack = 0
CONST clWhite = &HFFFFFF
CONST clBlue = &HFF0000
CONST clGreen = &H00FF00
CONST clRed = &H0000FF
CONST clPurple = &HFF00FF
const clYellow=&H00FFFF

'-- System colors
CONST clScrollBar = -2147483648
CONST clBackGround = -2147483647
CONST clActiveCaption = -2147483646
CONST clInActiveCaption = -2147483645
CONST clMenu = -2147483644
CONST clWindow = -2147483643
CONST clWindowFrame = -2147483642
CONST clMenuText = -2147483641
CONST clWindowText = -2147483640
CONST clCaptionText = -2147483639
CONST clActiveBorder = -2147483638
CONST clInActiveBorder = -2147483637
CONST clAppWorkSpace = -2147483636
CONST clHilight = -2147483635
CONST clHilightText = -2147483634
CONST clBtnFace = -2147483633
CONST clBtnShadow = -2147483632
CONST clGrayText = -2147483631
CONST clBtnText = -2147483630
CONST clInActiveCaptionText = -2147483629
CONST clBtnHighlight = -2147483628
CONST cl3DDkShadow = -2147483627
CONST cl3DLight = -2147483626
CONST clInfoText = -2147483625
CONST clInfoBk3DDkShadow = -2147483624
CONST clNone = 536870911
CONST clDefault = 536870912

'-- Mouse Shift States, True if Shift% AND ss<State>
CONST ssShift = 256
CONST ssCtrl = 16
CONST ssAlt = 1

'-- MessageDlg Message Types
CONST mtWarning = 0
CONST mtError = 1
CONST mtInformation = 2
CONST mtConfirmation = 3
CONST mtCustom = 4

'-- MessageDlg Message Buttons (NOT QBUTTON)
CONST mbYes = 1          ' YES Button
CONST mbNo = 2           ' NO Button
CONST mbOK = 4           ' OK Button
CONST mbCancel = 8       ' etc. etc.
CONST mbHelp = 16
CONST mbAbort = 32
CONST mbRetry = 64
CONST mbIgnore = 128
CONST mbAll = 256

'-- MessageDlg Return Values: See ModalResult of QButton


'------------------------- QFONT Variables --------------------------
'-- Font Styles
CONST fsBold = 0
CONST fsItalic = 1
CONST fsUnderline = 2
CONST fsStrikeOut = 3

'-- Font Pitch
CONST fpDefault = 0           '-- Depends on the font specified
CONST fpVariable = 1          '-- Characters in font have different widths
CONST fpFixed = 2             '-- Characters in font have same widths

'-- Font Character sets
CONST ANSI_CHARSET = 0        '-- ANSI characters
CONST DEFAULT_CHARSET = 1
CONST SYMBOL_CHARSET = 2      '-- Standard symbol set
CONST MAC_CHARSET = 77        '-- Macintosh characters
CONST SHIFTJIS_CHARSET = 128  '-- Japanese shift-jis characters
CONST HANGEUL_CHARSET = 129
CONST JOHAB_CHARSET = 130
CONST GB2312_CHARSET = 134
CONST CHINESEBIG5_CHARSET = 136
CONST GREEK_CHARSET = 161
CONST TURKISH_CHARSET = 162
CONST VIETNAMESE_CHARSET = 163
CONST HEBREW_CHARSET = 177
CONST ARABIC_CHARSET = 178
CONST BALTIC_CHARSET = 186
CONST RUSSIAN_CHARSET = 204
CONST THAI_CHARSET = 222
CONST EASTEUROPE_CHARSET = 238
CONST OEM_CHARSET = 255       '-- Depends on the codepage of the OS


'------------------------- QFORM Variables --------------------------
'-- Window States
CONST wsNormal = 0
CONST wsMinimized = 1
CONST wsMaximized = 2

'-- Form Styles
CONST fsNormal = 0
CONST fsMDIChild = 1
CONST fsMDIForm = 2
CONST fsStayOnTop = 3

'-- Border Styles
CONST bsNone = 0              '-- No visible border line, Not resizeable
CONST bsSingle = 1            '-- Single-line border, Not resizeable
CONST bsSizeable = 2          '-- Standard resizeable border
CONST bsDialog = 3            '-- Dialog, not resizeable
CONST bsToolWindow = 4        '-- like bsSingle but with a smaller caption
CONST bsSizeToolWin = 5       '-- like bsSizeable with a smaller caption

'-- Keyboard Shift States
CONST CtrlDown = 1
CONST AltDown = 16
CONST ShiftDown = 256

'-- Border Icons
CONST biSystemMenu = 0
CONST biMinimize = 1
CONST biMaximize = 2
CONST biHelp = 3

'-- Close Actions
CONST caNone = 0              '-- Don't close the form
CONST caHide = 1              '-- Just hide the form
CONST caFree = 2
CONST caClose = caFree        '-- Close form
CONST caMinimize = 3          '-- Minimize instead of closing


'------------------------- QLABEL Variables -------------------------
'-- Text Layout
CONST tlTop = 0
CONST tlCenter = 1
CONST tlBottom = 2

'-- Label Style
CONST lsNone = 0
CONST lsRaised = 1
CONST lsRecessed = 2


'------------------------- QPANEL Variables -------------------------
'-- Bevel Style
CONST bvNone = 0
CONST bvLowered = 1
CONST bvRaised = 2

'-- Bevel Border
CONST bpNone = 0         '-- No visible border
CONST bpSingle = 1       '-- Single-line border


'------------------------- QEDIT Variables --------------------------
'-- CharCase
CONST ecNormal = 0       '-- Text of the edit box displays in mixed case
CONST ecUpperCase = 1    '-- Text of the edit box displays in uppercase
CONST ecLowerCase = 2    '-- Text of the edit box displays in lowercase


'----------------------- QCOMBOBOX Variables ------------------------
'-- ComboBox Styles
CONST csDropDown = 0           '-- Drop-down list with an edit box
CONST csSimple = 1             '-- Edit box with no list.
CONST csDropDownList = 2       '-- Drop-down list without an edit box
CONST csOwnerDrawFixed = 3     '-- Owner draw fixed
CONST csOwnerDrawVariable = 4  '-- Owner draw variable


'---------------------- QFILESTREAM Variables -----------------------
'-- File Mode
CONST fmCreate = 65535
CONST fmOpenRead = 0
CONST fmOpenWrite = 1
CONST fmOpenReadWrite = 2

'-- Offsets
CONST soFromBeginning = 0       '-- Seek (offset) from Beginning
CONST soFromCurrent = 1         '-- Seek (offset) from Current position
CONST soFromEnd = 2             '-- Seek (offset) from End

'-- Read/Write Numbers
CONST Num_BYTE   = 1            '-- ie. PRINT File.ReadNum(Num_SINGLE)
CONST Num_SHORT  = 2
CONST Num_WORD   = 3
CONST Num_LONG   = 4
CONST Num_DWORD  = 5
CONST Num_SINGLE = 6
CONST Num_DOUBLE = 8


'----------------------- QRICHEDIT Variables ------------------------
'-- Scroll Bars
CONST ssNone = 0
CONST ssHorizontal = 1
CONST ssVertical = 2
CONST ssBoth = 3


'---------------------- MODALRESULT Variables -----------------------
'-- Default ModalResults
CONST mrNone = 0
CONST mrOK = 1
CONST mrCancel = 2
CONST mrAbort = 3
CONST mrRetry = 4
CONST mrIgnore = 5
CONST mrYes = 6
CONST mrNo = 7
CONST mrAll = 8
CONST mrNoToAll = 9
CONST mrYesToAll = 10


'------------------------ QBUTTON Variables -------------------------
'-- Bitmap Alignment
CONST blBMPLeft = 0
CONST blBMPRight = 1
CONST blBMPTop = 2
CONST blBMPBottom = 3

'-- Button Kind
CONST bkCustom = 0              '-- None
CONST bkOK = 1                  '-- Check Bitmap
CONST bkCancel = 2              '-- X Bitmap
CONST bkHelp = 3                '-- ? Bitmap
CONST bkYes = 4
CONST bkNo = 5
CONST bkClose = 6
CONST bkAbort = 7
CONST bkRetry = 8
CONST bkIgnore = 9
CONST bkAll = 10


'------------------------ CURSORS Variables -------------------------
CONST crDefault = 0        ' Normal pointer
CONST crNone = -1
CONST crArrow = -2
CONST crCross = -3
CONST crIBeam = -4
CONST crSize = -5
CONST crSizeNESW = -6
CONST crSizeNS = -7
CONST crSizeNWSE = -8
CONST crSizeWE = -9
CONST crUpArrow = -10
CONST crHourGlass = -11
CONST crDrag = -12
CONST crNoDrop = -13
CONST crHSplit = -14
CONST crVSplit = -15
CONST crMultiDrag = -16
CONST crSQLWait = -17
CONST crNo = -18
CONST crAppStart = -19
CONST crHelp = -20
CONST crHandPoint = -21


'--------------------- QFILELISTBOX Variables -----------------------
'-- FileTypes
CONST ftReadOnly = 0     '-- Display files with read-only attribute
CONST ftHidden = 1       '--   "       "     "  hidden attribute
CONST ftSystem = 2       '-- Displays system files
CONST ftVolumeID = 3     '-- Displays the volume name
CONST ftDirectory = 4    '-- Displays directories
CONST ftArchive = 5      '-- Display files with archive attribute
CONST ftNormal = 6       '-- Display files with no special attributes


'---------------------- QSCROLLBAR Variables ------------------------
'-- Kind
CONST sbHorizontal = 0
CONST sbVertical = 1

'-- ScrollCode
CONST scLineUp = 0
CONST scLineDown = 1
CONST scPageUp = 2
CONST scPageDown = 3
CONST scPosition = 4
CONST scTrack = 5
CONST scTop = 6
CONST scBottom = 7
CONST scEndScroll = 8


'----------------------- QIMAGELIST Variables -----------------------
'-- Draw styles
CONST dsFocused = 0      '-- Draws the image blending 25% with the system
                         '   highlight color. This only affects imagelists
                         '   which contain masks.
CONST dsSelected = 1     '-- Draws the image blending 50%
CONST dsNormal = 2       '-- Draws the image using the color specified in
                         '   the BkColor property
CONST dsTransparent = 3  '-- Draws using the mask regardless of the BkColor
                         '   setting

'-- Image type
CONST itImage = 0        '-- Draw image
CONST itMask = 1         '-- Draw image mask


'------------------ QLISTVIEW/QTREEVIEW Variables -------------------
'-- Sort Type
CONST stNone = 0         '-- Sort Type: None
'CONST stData = 1
CONST stText = 2
'CONST stBoth = 3

'-- QLISTVIEW View Style
CONST vsIcon = 0         '-- View Style: Full sized icon, text on bottom
CONST vsSmallIcon = 1    '-- Small icons, text aligned to the right
CONST vsList = 2         '-- Same as above (nevermind this)
CONST vsReport = 3       '-- Each item appears on its own line with information
                         '-- arranged in columns

'----------------------- QTRACKBAR Variables ------------------------
CONST tbHorizontal = 0   '-- TrackBar Orientation
CONST tbVertical = 1

CONST tmBottomRight = 0  '-- Tickmark placement
CONST tmTopLeft = 1
CONST tmBoth = 2

CONST tsNone = 0         '-- Track bar displays no tick marks
CONST tsAuto = 1         '-- Track bar displays tick marks automatically
                         '   for each increment in its range
CONST tsManual = 2       '-- Track bar displays a tick mark at either end


'---------------------- QSTRINGGRID Variables -----------------------
CONST goFixedVertLine = 0
CONST goFixedHorzLine = 1
CONST goVertLine = 2
CONST goHorzLine = 3
CONST goRangeSelect = 4
CONST goDrawFocusSelected = 5
CONST goRowSizing = 6
CONST goColSizing = 7
CONST goRowMoving = 8
CONST goColMoving = 9
CONST goEditing = 10
CONST goTabs = 11
CONST goRowSelect = 12
CONST goAlwaysShowEditor = 13
CONST goThumbTracking = 14

'-- ColumnStyles
CONST gcsList = 0
CONST gcsEllipsis = 1
CONST gcsNone = 2


'----------------------- QOUTLINE Variables -------------------------
'-- Outline Style
CONST osText = 0
CONST osPlusMinusText = 1
CONST osPictureText = 2
CONST osPlusMinusPictureText = 3
CONST osTreeText = 4
CONST osTreePictureText = 5

'-- Outline options
CONST ooDrawTreeRoot = 0         '-- First item is connected to the root item
CONST ooDrawFocusRect = 1        '-- Draw focus retangle around selected item
CONST ooDrawStretchBitmaps = 2   '-- Stretch bitmap to fit size of item


'------------------------ QGAUGE Variables --------------------------
'-- Kinds
CONST gkText = 0
CONST gkHorizontalBar = 1
CONST gkVerticalBar = 2
CONST gkPie = 3
CONST gkNeedle = 4


'----------------- QBITMAP/QCANVAS/QIMAGE Variables -----------------
'-- CopyMode
'CONST cmBlackness = 0     ' Fill Destination rectange on the canvas with black
'CONST cmDstInvert = 1
'CONST cmMergeCopy = 2
'CONST cmMergePaint = 3
'CONST cmNotSrcCopy = 4
'CONST cmNotSrcErase = 5
'CONST cmPatCopy = 6
'CONST cmPatInvert = 7
'CONST cmPatPaint = 8
'CONST cmSrcAnd = 9
'CONST cmSrcCopy = 10      ' Copies source image to the canvas
'CONST cmSrcErase = 11
'CONST cmSrcInvert = 12
'CONST cmSrcPaint = 13
'CONST cmWhiteness = 14    ' Fill Destination rectange on the canvas with white

'by: Lance (7/14/02 11:17:46 am)
' The CopyMode values in Rapidq.Inc are wrong.
'Here are the correct values.

CONST cmBlackness = &H42
CONST cmDstInvert = &H550009
CONST cmMergeCopy = &HC000CA
CONST cmMergePaint = &HBB0226
CONST cmNotSrcCopy = &H330008
CONST cmNotSrcErase = &H1100A6
CONST cmPatCopy = &HF00021
CONST cmPatInvert = &H5A0049
CONST cmPatPaint = &HFB0A09
CONST cmSrcAnd = &H8800C6
CONST cmSrcCopy = &HCC0020
CONST cmSrcErase = &H440328
CONST cmSrcInvert = &H660046
CONST cmSrcPaint = &HEE0086
CONST cmWhiteness = &HFF0062

'-- QBITMAP Pixel Formats
CONST pfDevice = 0
CONST pf1bit = 1
CONST pf4bit = 2
CONST pf8bit = 3
CONST pf15bit = 4
CONST pf16bit = 5
CONST pf24bit = 6
CONST pf32bit = 7

'-- QBITMAP TransparentMode
CONST tmAuto  = 0
CONST tmFixed = 1


'------------------------ QLISTBOX Variables ------------------------
'-- ListBox Styles
CONST lbStandard = 0           '-- All items are strings
CONST lbOwnerDrawFixed = 1     '-- Owner draw fixed
CONST lbOwnerDrawVariable = 2  '-- Owner draw variable


'------------------------ QCOMPORT Variables ------------------------
'-- Baud Rates
$IFDEF __COMPORT
CONST br110 = 0
CONST br300 = 1
CONST br600 = 2
CONST br1200 = 3
CONST br2400 = 4
CONST br4800 = 5
CONST br9600 = 6
CONST br14400 = 7
CONST br19200 = 8
CONST br38400 = 9
CONST br56000 = 10
CONST br57600 = 11
CONST br115200 = 12

'-- Stop bits
CONST sbOneStopBit = 0
CONST sbOne5StopBits = 1
CONST sbTwoStopBits = 2

'-- Parity
CONST prNone = 0
CONST prOdd = 1
CONST prEven = 2
CONST prMark = 3
CONST prSpace = 4
$ENDIF

'---------------------- QFONTDIALOG Variables -----------------------
'-- Font Options
CONST fdAnsiOnly = 0             '-- No weird symbols
CONST fdTrueTypeOnly = 1
CONST fdEffects = 2
CONST fdFixedPitchOnly = 3
CONST fdForceFontExist = 4
CONST fdNoFaceSel = 5
CONST fdNoOEMFonts = 6
CONST fdNoSimulations = 7
CONST fdNoSizeSel = 8
CONST fdNoStyleSel = 9
CONST fdNoVectorFonts = 10
CONST fdShowHelp = 11
CONST fdWysiwyg = 12
CONST fdLimitSize = 13
CONST fdScalableOnly = 14
CONST fdApplyButton = 15


'----------------------- QDIRTREE Variables -------------------------
'-- DirTypes
CONST dtReadOnly = 0
CONST dtHidden = 1
CONST dtSystem = 2
CONST dtNormal = 3
CONST dtAll = 4

'-- DriveTypes
CONST drtUnknown = 0
CONST drtRemovable = 1
CONST drtFixed = 2
CONST drtRemote = 3
CONST drtCDRom = 4
CONST drtRamDisk = 5


'------------------------ QSOCKET Variables -------------------------
'-- Protocols
CONST IPPROTO_IP   = 0        ' dummy for IP
CONST IPPROTO_ICMP = 1        ' control message protocol
CONST IPPROTO_IGMP = 2        ' group management protocol
CONST IPPROTO_TCP  = 6
CONST IPPROTO_PUP  = 12
CONST IPPROTO_UDP  = 17       ' user datagram protocol
CONST IPPROTO_IDP  = 22       ' xns idp
CONST IPPROTO_RAW  = 255      ' raw IP packet

'-- Socket Types
CONST SOCK_STREAM    = 1      ' stream socket
CONST SOCK_DGRAM     = 2      ' datagram socket
CONST SOCK_RAW       = 3      ' raw-protocol interface
CONST SOCK_RDM       = 4      ' reliably-delivered message
CONST SOCK_SEQPACKET = 5      ' sequenced packet stream

'-- Address families
CONST AF_UNSPEC    = 0        ' unspecified
CONST AF_UNIX      = 1        ' local to host (pipes, portals)
CONST AF_INET      = 2        ' internetwork: UDP, TCP, etc.
CONST AF_IMPLINK   = 3        ' arpanet imp addresses
CONST AF_PUP       = 4        ' pup protocols: e.g. BSP
CONST AF_CHAOS     = 5        ' mit CHAOS protocols
CONST AF_IPX       = 6        ' IPX and SPX
CONST AF_NS        = 6        ' XEROX NS protocols
CONST AF_ISO       = 7        ' ISO protocols
CONST AF_OSI       = AF_ISO
CONST AF_ECMA      = 8        ' european computer manufacturers
CONST AF_DATAKIT   = 9        ' datakit protocols
CONST AF_CCITT     = 10       ' CCITT protocols, X.25 etc
CONST AF_SNA       = 11       ' IBM SNA
CONST AF_DECnet    = 12       ' DECnet
CONST AF_DLI       = 13       ' Direct data link interface
CONST AF_LAT       = 14       ' LAT
CONST AF_HYLINK    = 15       ' NSC Hyperchannel
CONST AF_APPLETALK = 16       ' AppleTalk
CONST AF_NETBIOS   = 17       ' NetBios-style addresses
CONST AF_VOICEVIEW = 18       ' VoiceView
CONST AF_FIREFOX   = 19       ' FireFox
CONST AF_UNKNOWN1  = 20       ' What?
CONST AF_BAN       = 21       ' Banyan


'----------------------- QHEADER Variables --------------------------
'-- Header Styles
CONST hsText = 0
CONST hsOwnerDraw = 1


'--------------------- QSTRINGLIST Variables ------------------------
'-- Duplicates
CONST dupIgnore = 0
CONST dupAccept = 1
CONST dupError = 2


'-------------------- QOLECONTAINER Variables -----------------------
'-- Size Mode
CONST smClip = 0              '-- Clip parts that don't fit inside
CONST smCenter = 1            '-- Center object within the container
CONST smScale = 2             '-- Scales or shrinks object to fit inside
CONST smStretch = 3           '-- Stretch to fill entire container
CONST smAutoSize = 4          '-- Sizes container to match size of object

'-- Object States
CONST osEmpty = 0
CONST osLoaded = 1
CONST osRunning = 2
CONST osOpen = 3
CONST osInPlaceActive = 4
CONST osUIActive = 5


'--------------------- STRF$ Format Variables -----------------------
CONST ffGeneral = 0
CONST ffExponent = 1
CONST ffFixed = 2
CONST ffNumber = 3


'------------------------- DIR$ Variables ---------------------------
'-- File Attributes
CONST faReadOnly  = 1
CONST faHidden    = 2
CONST faSysFile   = 4
CONST faVolumeID  = 8
CONST faDirectory = 16
CONST faArchive   = 32
CONST faAnyFile   = 63


'------------------------ PRINTER Variables -------------------------
'-- Orientations
CONST poPortrait  = 0
CONST poLandscape = 1


'---------------------------- QBColor -------------------------------

$IFDEF __QBCOLOR
DIM QBColor(0 TO 15) AS INTEGER
    QBColor(0) = 0               '-- Black
    QBColor(1) = &H800000        '-- Blue
    QBColor(2) = &H8000          '-- Green
    QBColor(3) = &H808000        '-- Cyan
    QBColor(4) = &H80            '-- Red
    QBColor(5) = &H800080        '-- Magenta
    QBColor(6) = &H8080          '-- Brown
    QBColor(7) = &HC0C0C0        '-- White
    QBColor(8) = &H808080        '-- Grey
    QBColor(9) = &HFF0000        '-- Light Blue
    QBColor(10) = &HFF00         '-- Light Green
    QBColor(11) = &HFFFF00       '-- Light Cyan
    QBColor(12) = &HFF           '-- Light Red
    QBColor(13) = &HFF00FF       '-- Light Magenta
    QBColor(14) = &HFFFF         '-- Yellow
    QBColor(15) = &HFFFFFF       '-- Bright White
$ENDIF ' __QBCOLOR

$ENDIF ' __RQINC

'
' RAPIDQ2.INC   -- updated Include file for RAPID-Q compiler by William Yu
'               -- attach a $INCLUDE "RAPIDQ2.INC" in place of RAPIDQ.INC
'               -- to all your programs. If you find this file too big, extract what you need.
'               -- You are allowed to freely distribute and modify this code as needed
'               -- No waranties or guarantees for this this code! Use AS IS.
'
'
'			This file is important for updating the language!!
'			***********************************************************
'			**  Last updated by JohnK, 4/2006   (version 1.2c)  *******
'			***********************************************************
'

$IFNDEF __RQINC						'don't reload old RapidQ.inc
$DEFINE __RQINC


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

$IFNDEF __WIN32API				   'windows 32 constants for sound media
      CONST SND_SYNC = 0           '-- Synchronous playback (Wait for sound to finish)
      CONST SND_ASYNC = 1          '-- Asynchronous playback (Like background play).
      CONST SND_LOOP = 8           '-- Loop sound
      CONST SND_NODEFAULT = &H2
      CONST SND_NOSTOP = &H10
      CONST SND_MEMORY = &H4
$ENDIF

'-- BASIC Colors
      CONST clBlack = 0
      CONST clWhite = &HFFFFFF
      CONST clBlue = &HFF0000
      CONST clGreen = &H00FF00
      CONST clRed = &H0000FF
      CONST clPurple = &HFF00FF
      CONST clYellow=&H00FFFF

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


'---- Mouse Buttons ------------
	CONST MouseRtButton = 1
	CONST MouseLtButton = 0


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
$IFNDEF __WIN32API
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
$ENDIF

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
'by: Lance (7/14/02 11:17:46 am)
' The CopyMode values in original Rapidq.Inc are wrong.
'Here are the correct Ternary raster operations
'  
      CONST cmBlackness = &H42			' dest = BLACK  ' Fill Destination rectange on Qimage/Qcanvas with black
      CONST cmDstInvert = &H550009		' dest = (NOT dest)
      CONST cmMergeCopy = &HC000CA		' dest = (source AND pattern)
      CONST cmMergePaint = &HBB0226		' dest = (NOT source) OR dest
      CONST cmNotSrcCopy = &H330008		' dest = (NOT source)
      CONST cmNotSrcErase = &H1100A6	' dest = (NOT src) AND (NOT dest)
      CONST cmPatCopy = &HF00021		' dest = pattern
      CONST cmPatInvert = &H5A0049		' dest = pattern XOR dest
      CONST cmPatPaint = &HFB0A09		' dest = DPSnoo

      CONST cmSrcAnd = &H8800C6			' dest = source AND dest
      CONST cmSrcCopy = &HCC0020		' dest = source		     ' Copies source image to the Qimage/Qcanvas
      CONST cmSrcErase = &H440328		' dest = source AND (NOT dest )
      CONST cmSrcInvert = &H660046		' dest = source XOR dest
      CONST cmSrcPaint = &HEE0086		' dest = source OR dest
      CONST cmWhiteness = &HFF0062		' dest = WHITE ' Fill Destination rectange on Qimage/Qcanvas with white

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
       CONST sbOneStopBits = 1
       CONST sbTwoStopBits = 2

'-- Parity
       CONST prNone = 0
       CONST prOdd = 1
       CONST prEven = 2
       CONST prMark = 3
       CONST prSpace = 4

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
$IFNDEF __QBCOLOR
$DEFINE __QBCOLOR
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

$ENDIF		'RQINC	'old rapidQ.inc





'********************************************************************************
'--------------------------------------------------------------------------
'--------------- RapidQ2 extensions, declarations that improve   ----------
'--------------- functionality of the language and fix some bugs ----------
'----------------  This section includes USEFUL WINDOWS 32 API CALLS ------
'--------------------------------------------------------------------------
'9/2005 by JohnK
'*********************************************************************************
'

'********************************************************************************
' turn off extensions if you need to for debugging reasons, or whatever
'********************************************************************************
$IFDEF __EXTENSIONS_OFF
   $DEFINE __RQ2WIN32API			'turn off windows 32 API calls/constants
   $DEFINE __RQINC2					'turn off rapidQ2
$ENDIF


$IFDEF __WIN32API
  $DEFINE __RQ2WIN32API				'the new or old windows.inc loaded?
$ENDIF

'----------------------------------------------------------------------------------------
'---------------------- Windows 32 API functions and constants ----------------------
'
'   load up Windows Constants and API Call declarations, these follow the 
'  standard windows naming conventions so documentation can be found at the
'  microsoft website www.msdn.microsoft.com. Do not duplicate them via Alias !!!
'
'----------------------------------------------------------------------------------------


$IFNDEF __RQ2WIN32API
$DEFINE __RQ2WIN32API			'rapidq2 windows api calls




CONST GWL_HWNDPARENT = (-8)                   'Minimize to task bar
CONST GWL_WNDPROC = -4
CONST GWL_STYLE = -16
CONST HWND_DESKTOP = 0
CONST HWND_TOPMOST = -1
CONST HWND_NOTOPMOST = -2
$DEFINE HWND_TOP  0
$DEFINE HWND_BOTTOM  1


$DEFINE SWP_NOSIZE  &H1
$DEFINE SWP_NOMOVE  &H2
$DEFINE SWP_NOZORDER  &H4
$DEFINE SWP_NOACTIVATE  &H10
$DEFINE SWP_SHOWWINDOW  &H40
$DEFINE SWP_NOSENDCHANGING  &H400  'Don't send WM_WINDOWPOSCHANGING */


$DEFINE NIM_ADD 0
$DEFINE NIM_MODIFY 1
$DEFINE NIM_DELETE 2
$DEFINE NIF_MESSAGE 1
$DEFINE NIF_ICON 2
$DEFINE NIF_TIP 4

' Windows Messages for use in WinProc. This is a very small list of all
' possible messages. All messages values less than &H400 are reserved.
' you can make your own private Window Messages if larger than &H400
' to be safe you should allow some already used between &H400 - &H500

$DEFINE WM_ACTIVATE &H0006
' WM_ACTIVATE state values
$DEFINE     WA_INACTIVE     0
$DEFINE     WA_ACTIVE       1
$DEFINE     WA_CLICKACTIVE  2
$DEFINE     WM_SETFOCUS     &H0007
$DEFINE     WM_KILLFOCUS    &H0008

$DEFINE WM_KEYFIRST        &H100
$DEFINE WM_KEYDOWN         &H100
$DEFINE WM_KEYUP           &H101
$DEFINE WM_CHAR            &H102
$DEFINE WM_DEADCHAR        &H103
$DEFINE WM_SYSKEYDOWN      &H104
$DEFINE WM_SYSKEYUP        &H105
$DEFINE WM_SYSCHAR         &H106
$DEFINE WM_SYSDEADCHAR     &H107
$DEFINE WM_KEYLAST         &H108
$DEFINE WM_INITDIALOG      &H110
$DEFINE WM_COMMAND         &H111
$DEFINE WM_SYSCOMMAND      &H112
$DEFINE WM_TIMER           &H113
$DEFINE WM_HSCROLL         &H114
$DEFINE WM_VSCROLL         &H115
$DEFINE WM_DRAWITEM        &H2B
$DEFINE WM_MEASUREITEM     &H2C
$DEFINE WM_INITMENU        &H116
$DEFINE WM_INITMENUPOPUP   &H117
$DEFINE WM_MENUSELECT      &H11Fg
$DEFINE WM_MENUCHAR        &H120
$DEFINE WM_ENTERIDLE       &H121

$DEFINE WM_CTLCOLORMSGBOX  &H132
$DEFINE WM_CTLCOLOREDIT    &H133
$DEFINE WM_CTLCOLORLISTBOX &H134
$DEFINE WM_CTLCOLORBTN     &H135
$DEFINE WM_CTLCOLORDLG     &H136
$DEFINE WM_CTLCOLORSCROLLBAR     &H137
$DEFINE WM_CTLCOLORSTATIC  &H138

$DEFINE WM_MOUSEFIRST      &H200
$DEFINE WM_MOUSEMOVE       &H200
$DEFINE WM_LBUTTONDOWN     &H201
$DEFINE WM_LBUTTONUP       &H202
$DEFINE WM_LBUTTONDBLCLK   &H203
$DEFINE WM_RBUTTONDOWN     &H204
$DEFINE WM_RBUTTONUP       &H205
$DEFINE WM_RBUTTONDBLCLK   &H206
$DEFINE WM_MBUTTONDOWN     &H207
$DEFINE WM_MBUTTONUP       &H208
$DEFINE WM_MBUTTONDBLCLK   &H209
$DEFINE WM_MOUSEWHEEL      &H20A
$DEFINE WM_MOUSELAST       &H20A

$DEFINE WM_DROPFILES  &H233
$DEFINE WM_TRAYICON   &H590
$DEFINE SC_MINIMIZE   61472

$DEFINE WM_USER       &H400

Type LARGE_INTEGER
   LowPart  As DWORD
   HighPart As DWORD
End Type 


TYPE POINTAPI
    X AS LONG
    Y AS LONG
END TYPE


Type RECT
  Left As Long
  Top As Long
  Right As Long
  Bottom As Long
End Type


'  Object Definitions for EnumObjects() for QbitmapEx
$DEFINE OBJ_PEN     1
$DEFINE OBJ_BRUSH     2
$DEFINE OBJ_DC     3
$DEFINE OBJ_METADC     4
$DEFINE OBJ_PAL     5
$DEFINE OBJ_FONT     6
$DEFINE OBJ_BITMAP     7
$DEFINE OBJ_REGION     8
$DEFINE OBJ_METAFILE     9
$DEFINE OBJ_MEMDC     10
$DEFINE OBJ_EXTPEN     11
$DEFINE OBJ_ENHMETADC     12
$DEFINE OBJ_ENHMETAFILE     13


' Predefined Clipboard Formats
$DEFINE CF_TEXT     1
$DEFINE CF_BITMAP     2
$DEFINE CF_METAFILEPICT     3
$DEFINE CF_SYLK     4
$DEFINE CF_DIF     5
$DEFINE CF_TIFF     6
$DEFINE CF_OEMTEXT     7
$DEFINE CF_DIB     8
$DEFINE CF_PALETTE     9
$DEFINE CF_PENDATA     10
$DEFINE CF_RIFF     11
$DEFINE CF_WAVE     12
$DEFINE CF_UNICODETEXT     13
$DEFINE CF_ENHMETAFILE     14



'------------------------------------------------------------
'--Windows form manipulation USER32 
'

Type WNDCLASSEX
    cbSize 		As Long
    style 		As Long
    lpfnWndProc As Long
    cbClsExtra 	As Long
    cbWndExtra 	As Long
    hInstance 	As Long
    hIcon 		As Long
    hCursor 	As Long
    hbrBackground As Long
    lpszMenuName As Long 	'String ptr
    lpszClassName As Long	'String ptr
    hIconSm As Long
End Type


' Window Styles
CONST WS_OVERLAPPED = &H0&
CONST WS_POPUP = &H80000000
CONST WS_CHILD = &H40000000
CONST WS_MINIMIZE = &H20000000
CONST WS_VISIBLE = &H10000000
CONST WS_DISABLED = &H8000000
CONST WS_CLIPSIBLINGS = &H4000000
CONST WS_CLIPCHILDREN = &H2000000
CONST WS_MAXIMIZE = &H1000000
CONST WS_CAPTION = &HC00000                  '  WS_BORDER Or WS_DLGFRAME
CONST WS_BORDER = &H800000
CONST WS_DLGFRAME = &H400000
CONST WS_VSCROLL = &H200000
CONST WS_HSCROLL = &H100000
CONST WS_SYSMENU = &H80000
CONST WS_THICKFRAME = &H40000
CONST WS_GROUP = &H20000
CONST WS_TABSTOP = &H10000
Const WS_EX_MDICHILD=&H40

CONST WS_MINIMIZEBOX = &H20000
CONST WS_MAXIMIZEBOX = &H10000
CONST WS_OVERLAPPEDWINDOW=(WS_OVERLAPPED OR WS_CAPTION OR WS_SYSMENU OR WS_THICKFRAME OR WS_MINIMIZEBOX OR WS_MAXIMIZEBOX)



'--------------Windows user32 form related functions -------------------
' used in many QFORM, QFormMDI,  QDOCKFORM
'
' SendMessage is already a keyword in RapidQ but is probably not a function... So use this for return values
DECLARE FUNCTION SendMessageAPI Lib "user32" Alias "SendMessageA" (hwnd As Long, wMsg As Long, wParam As Long, lParam As Long) As Long


DECLARE FUNCTION AnyPopup Lib "user32" Alias "AnyPopup" () As Long
DECLARE FUNCTION BringWindowToTop Lib "user32" Alias "BringWindowToTop" (ByVal hwnd As Long) As Long
Declare Function RegisterClassEx LIB "User32" ALIAS "RegisterClassExA" (pcWndClassEx AS WNDCLASSEX) AS LONG
Declare Function EnumChildWindows LIB "User32" ALIAS "EnumChildWindows" (hWndParent AS LONG,lpEnumFunc AS LONG,lParam AS LONG) AS LONG
Declare Function CreateWindowEx LIB "User32" ALIAS "CreateWindowExA" (dwExStyle AS LONG,lpClassName AS STRING,lpWindowName AS STRING,dwStyle AS LONG,x AS LONG,y AS LONG,nWidth AS LONG,nHeight AS LONG,hWndParent AS LONG,hMenu AS LONG,hInstance AS LONG,lpParam AS LONG) AS LONG
Declare Function DefMDIChildProc LIB "User32" ALIAS "DefMDIChildProcA" (hWnd AS LONG,uMsg AS LONG,wParam AS LONG,lParam AS LONG) AS LONG
Declare Function GetClassName LIB "User32" ALIAS "GetClassNameA" (hwnd AS LONG, lpClassName AS LONG, nMaxCount AS LONG) AS LONG
Declare Function SetProp LIB "User32" ALIAS "SetPropA" (hwnd AS LONG,lpString AS STRING,hData AS LONG) AS LONG
Declare Function GetProp LIB "User32"  ALIAS "GetPropA" (hwnd AS LONG,lpString AS STRING) AS LONG
Declare Function GetClientRect LIB "User32" ALIAS "GetClientRect" (hwnd AS LONG,lpRect AS QRECT) AS LONG
Declare Function MoveWindow LIB "User32" ALIAS "MoveWindow" (hwnd AS LONG,x AS LONG,y AS LONG,nWidth AS LONG,nHeight AS LONG,bRepaint AS LONG) AS LONG
DECLARE FUNCTION GetFocus LIB "user32" ALIAS "GetFocus"() AS LONG
DECLARE FUNCTION GetParent Lib "user32" Alias "GetParent" (hwnd As Long) As Long
DECLARE FUNCTION GetWindowRect Lib "user32" Alias "GetWindowRect" (ByVal hwnd As Long, lpRect As QRECT) As Long
DECLARE FUNCTION GetWindowText Lib "user32" Alias "GetWindowTextA" (ByVal hwnd As Long, ByVal lpString As Long, ByVal cch As Long) As Long
DECLARE FUNCTION GetWindowTextLength Lib "user32" Alias "GetWindowTextLengthA" (ByVal hwnd As Long) As Long
DECLARE FUNCTION GetCapture LIB "USER32" ALIAS "GetCapture" () AS LONG
DECLARE FUNCTION DrawEdge LIB "USER32" ALIAS "DrawEdge" (hdc AS LONG, qrc AS QRECT, edge AS LONG, grfFlags AS LONG) AS LONG
DECLARE FUNCTION DrawFrameControl LIB "USER32" ALIAS "DrawFrameControl" (hdc AS LONG, qrc AS QRECT, utype AS LONG, ustate AS LONG) AS LONG
DECLARE FUNCTION DrawCaption LIB "USER32" ALIAS "DrawCaption" (hwnd AS LONG, hdc AS LONG, qrc AS QRECT, uFlags AS LONG) AS LONG
DECLARE FUNCTION IsIconic Lib "user32" Alias "IsIconic" (ByVal hwnd As Long) As Long
DECLARE FUNCTION IsWindowVisible Lib "user32" Alias "IsWindowVisible" (ByVal hwnd As Long) As Long
DECLARE FUNCTION IsZoomed Lib "user32" Alias "IsZoomed" (ByVal hwnd As Long) As Long
DECLARE FUNCTION RemoveProp Lib "user32" Alias "RemovePropA" (ByVal hwnd As Long, ByVal lpString As String) As Long
DECLARE FUNCTION ReleaseCapture LIB "user32" ALIAS "ReleaseCapture" () AS LONG
DECLARE FUNCTION SetCapture LIB "USER32" ALIAS "SetCapture" (hwnd AS LONG) AS LONG
DECLARE FUNCTION SetClassLong Lib "user32" Alias "SetClassLongA" (hwnd As Long,nIndex As Long,dwNewLong As Long) As Long
DECLARE FUNCTION SetFocus LIB "User32" ALIAS "SetFocus" (hwnd AS LONG) AS LONG
DECLARE FUNCTION SetParent Lib "user32" Alias "SetParent" (hWndChild As Long,hWndNewParent As Long) As Long
DECLARE FUNCTION SetForegroundWindow Lib "user32" Alias "SetForegroundWindow" (ByVal hwnd As Long) As Long
DECLARE FUNCTION SetWindowText Lib "user32" Alias "SetWindowTextA" (ByVal hwnd As Long, ByVal lpString As String) As Long
DECLARE FUNCTION ShowWindow Lib "user32" Alias "ShowWindow" (hwnd As Long,nCmdShow As Long) As Long
DECLARE FUNCTION CallWindowProc Lib "user32.dll" Alias "CallWindowProcA" (lpPrevWndFunc As Long, hwnd As Long, Msg As Long, wParam As Long, lParam As Long) As Long

' enable / disable mouse and keyboard input to a specified window or control.fEnable = enable/disable flag
DECLARE FUNCTION EnableWindow Lib "user32" Alias "EnableWindow" (ByVal hwnd AS LONG, ByVal fEnable AS LONG) AS LONG  'If window was previously disabled, the return value is nonzero
DECLARE SUB SetWindowPos Lib "User32"  ALIAS "SetWindowPos"_
	(ByVal hWnd As Long,_
	 ByVal hWndInsertAfter As Long,_
	 ByVal X As Long,_
	 ByVal Y As Long,_
	 ByVal cx As Long, ByVal cy As Long, ByVal wFlags As Long)


DECLARE FUNCTION GetWindowLong LIB "USER32" ALIAS "GetWindowLongA" (hwnd AS LONG, type AS LONG) AS LONG
DECLARE FUNCTION SetWindowLong LIB "user32" ALIAS "SetWindowLongA" (hWnd AS LONG,nIndex AS LONG, dwNewLong AS LONG) AS LONG
DECLARE SUB ClientToScreen LIB "USER32" ALIAS "ClientToScreen" (hwnd AS LONG, lpPoint AS LONG)
DECLARE FUNCTION DefWindowProc LIB "USER32" ALIAS "DefWindowProcA" (hwnd AS LONG, msg as long, wparam as long, lparam as long) AS LONG



'------------------Windows SHell32 functions------------------------
'----------------- Use for QFORM extension -----------------------
'---

DECLARE SUB DragAcceptFiles LIB "SHELL32" ALIAS "DragAcceptFiles" (hWnd AS LONG, Accept AS LONG)
DECLARE SUB DragFinish LIB "SHELL32" ALIAS "DragFinish" (hDrop AS LONG)
DECLARE FUNCTION DragQueryFile LIB "SHELL32" ALIAS "DragQueryFileA" (hDrop AS LONG, iFile AS LONG, lpszFile AS LONG, cch AS LONG) AS LONG
DECLARE FUNCTION DragQueryPoint LIB "SHELL32" ALIAS "DragQueryPoint" (hDrop AS LONG, lppt AS POINTAPI) AS LONG
DECLARE FUNCTION Shell_NotifyIcon Lib "SHELL32" ALIAS "Shell_NotifyIconA" (ByVal dwMessage As Long, lpData As QNOTIFYICONDATA) As Long
DECLARE FUNCTION ShellExecute LIB "shell32.dll" ALIAS "ShellExecuteA" (ByVal hwnd AS LONG, ByVal lpOperation AS STRING, ByVal lpFile AS STRING, ByVal lpParameters AS STRING, ByVal lpDirectory AS STRING, ByVal nShowCmd AS LONG) AS LONG



'----------------- Use for Mouse / Key extension -----------------------
'---
'mouse routines
CONST MOUSEEVENTF_MOVE 		= &H1			'relative move by mickeys
CONST MOUSEEVENTF_ABSOLUTE	= &H8000 		'absolute move position
DECLARE SUB mouse_event Lib "user32" ALIAS "mouse_event"(ByVal dwFlags As Long, ByVal dx As Long, ByVal dy As Long, ByVal cButtons As Long, ByVal dwExtraInfo As Long)
'this moves the mouse:
DECLARE FUNCTION SetCursorPos Lib "user32" Alias "SetCursorPos" (ByVal x As Long, ByVal y As Long) As Long
'sample code SetCursorPos(xPos, yPos)



' Virtual Keys, Standard Set
$DEFINE VK_LBUTTON    &H1
$DEFINE VK_RBUTTON    &H2
$DEFINE VK_CANCEL    &H3
$DEFINE VK_MBUTTON    &H4             '  NOT contiguous with L RBUTTON
$DEFINE VK_BACK    &H8
$DEFINE VK_TAB    &H9
$DEFINE VK_CLEAR    &HC
$DEFINE VK_RETURN    &HD
$DEFINE VK_SHIFT    &H10
$DEFINE VK_CONTROL    &H11
$DEFINE VK_MENU    &H12
$DEFINE VK_PAUSE    &H13
$DEFINE VK_CAPITAL    &H14
$DEFINE VK_ESCAPE    &H1B
$DEFINE VK_SPACE    &H20
$DEFINE VK_PRIOR    &H21
$DEFINE VK_NEXT    &H22
$DEFINE VK_END    &H23
$DEFINE VK_HOME    &H24
$DEFINE VK_LEFT    &H25	'left arrow
$DEFINE VK_UP    &H26		'up arrow
$DEFINE VK_RIGHT    &H27	'etc
$DEFINE VK_DOWN    &H28
$DEFINE VK_SELECT    &H29
$DEFINE VK_PRINT    &H2A
$DEFINE VK_EXECUTE    &H2B
$DEFINE VK_SNAPSHOT    &H2C
$DEFINE VK_INSERT    &H2D
$DEFINE VK_DELETE    &H2E
$DEFINE VK_HELP    &H2F

' VK_A thru VK_Z are the same as their ASCII equivalents: 'A' thru 'Z'
' VK_0 thru VK_9 are the same as their ASCII equivalents: '0' thru '9'
$DEFINE VK_0    &H30
$DEFINE VK_1    &H31
$DEFINE VK_2    &H32
$DEFINE VK_3    &H33
$DEFINE VK_4    &H34
$DEFINE VK_5    &H35
$DEFINE VK_6    &H36
$DEFINE VK_7    &H37
$DEFINE VK_8    &H38
$DEFINE VK_9    &H39
$DEFINE VK_A    &H41
$DEFINE VK_B    &H42
$DEFINE VK_C    &H43
$DEFINE VK_D    &H44
$DEFINE VK_E    &H45
$DEFINE VK_F    &H46
$DEFINE VK_G    &H47
$DEFINE VK_H    &H48
$DEFINE VK_I    &H49
$DEFINE VK_J    &H4A
$DEFINE VK_K    &H4B
$DEFINE VK_L    &H4C
$DEFINE VK_M    &H4D
$DEFINE VK_N    &H4E
$DEFINE VK_O    &H4F
$DEFINE VK_P    &H50
$DEFINE VK_Q    &H51
$DEFINE VK_R    &H52
$DEFINE VK_S    &H53
$DEFINE VK_T    &H54
$DEFINE VK_U    &H55
$DEFINE VK_V    &H56
$DEFINE VK_W    &H57
$DEFINE VK_X    &H58
$DEFINE VK_Y    &H59
$DEFINE VK_Z    &H5A


$DEFINE VK_NUMPAD0    &H60
$DEFINE VK_NUMPAD1    &H61
$DEFINE VK_NUMPAD2    &H62
$DEFINE VK_NUMPAD3    &H63
$DEFINE VK_NUMPAD4    &H64
$DEFINE VK_NUMPAD5    &H65
$DEFINE VK_NUMPAD6    &H66
$DEFINE VK_NUMPAD7    &H67
$DEFINE VK_NUMPAD8    &H68
$DEFINE VK_NUMPAD9    &H69
$DEFINE VK_MULTIPLY    &H6A
$DEFINE VK_ADD    &H6B
$DEFINE VK_SEPARATOR    &H6C
$DEFINE VK_SUBTRACT    &H6D
$DEFINE VK_DECIMAL    &H6E
$DEFINE VK_DIVIDE    &H6F
$DEFINE VK_F1    &H70
$DEFINE VK_F2    &H71
$DEFINE VK_F3    &H72
$DEFINE VK_F4    &H73
$DEFINE VK_F5    &H74
$DEFINE VK_F6    &H75
$DEFINE VK_F7    &H76
$DEFINE VK_F8    &H77
$DEFINE VK_F9    &H78
$DEFINE VK_F10    &H79
$DEFINE VK_F11    &H7A
$DEFINE VK_F12    &H7B
$DEFINE VK_F13    &H7C
$DEFINE VK_F14    &H7D
$DEFINE VK_F15    &H7E
$DEFINE VK_F16    &H7F
$DEFINE VK_F17    &H80
$DEFINE VK_F18    &H81
$DEFINE VK_F19    &H82
$DEFINE VK_F20    &H83
$DEFINE VK_F21    &H84
$DEFINE VK_F22    &H85
$DEFINE VK_F23    &H86
$DEFINE VK_F24    &H87

$DEFINE VK_NUMLOCK   &H90
$DEFINE VK_SCROLL    &H91

'
'   VK_L VK_R - left and right Alt, Ctrl and Shift virtual keys.
'   Used only as parameters to GetAsyncKeyState() and GetKeyState().
'   No other API or message will distinguish left and right keys in this way.
'  /
$DEFINE VK_LSHIFT    &HA0
$DEFINE VK_RSHIFT    &HA1
$DEFINE VK_LCONTROL  &HA2
$DEFINE VK_RCONTROL  &HA3
$DEFINE VK_LMENU     &HA4
$DEFINE VK_RMENU     &HA5

'	ascii codes are the same as their virtual key codes
'Non-blocking keyboard check in GUI
DECLARE FUNCTION GetKeyState Lib "user32" Alias "GetKeyState" (ByVal nVirtKey As Long) As Integer



'------------------  Graphics extenstions QBITMAP/ QIMAGE / QCANVAS 
'----  

$DEFINE OPAQUE 2
$DEFINE TRANSPARENT 1

Type TBITMAP
  bmType 		As LONG
  bmWidth 		As LONG
  bmHeight 		As LONG
  bmWidthBytes	As LONG
  bmPlanes 		As WORD
  bmBitsPixel 	As WORD
  bmBits 		As LONG
End Type


'  Pen Styles
$DEFINE PS_SOLID   0
$DEFINE PS_DASH   1                    '  -------
$DEFINE PS_DOT   2                     '  .......
$DEFINE PS_DASHDOT   3                 '  _._._._
$DEFINE PS_DASHDOTDOT   4              '  _.._.._
$DEFINE PS_NULL   5
$DEFINE PS_INSIDEFRAME   6
$DEFINE PS_USERSTYLE   7
$DEFINE PS_ALTERNATE   8
$DEFINE PS_STYLE_MASK   &HF


' type mixmode
$DEFINE R2_BLACK 1
$DEFINE R2_NOTMERGEPEN 2
$DEFINE R2_MASKNOTPEN 3
$DEFINE R2_NOTCOPYPEN 4
$DEFINE R2_MASKPENNOT 5
$DEFINE R2_NOT 6
$DEFINE R2_XORPEN 7
$DEFINE R2_NOTMASKPEN 8
$DEFINE R2_MASKPEN 9
$DEFINE R2_NOTXORPEN 10
$DEFINE R2_NOP 11
$DEFINE R2_MERGENOTPEN 12
$DEFINE R2_COPYPEN 13
$DEFINE R2_MERGEPENNOT 14
$DEFINE R2_MERGEPEN 15
$DEFINE R2_WHITE 16


' Stock Logical Objects
$DEFINE WHITE_BRUSH   0
$DEFINE LTGRAY_BRUSH   1
$DEFINE GRAY_BRUSH   2
$DEFINE DKGRAY_BRUSH   3
$DEFINE BLACK_BRUSH   4
$DEFINE NULL_BRUSH   5
$DEFINE HOLLOW_BRUSH   5
$DEFINE WHITE_PEN   6
$DEFINE BLACK_PEN   7
$DEFINE NULL_PEN   8
$DEFINE OEM_FIXED_FONT   10
$DEFINE ANSI_FIXED_FONT   11
$DEFINE ANSI_VAR_FONT   12
$DEFINE SYSTEM_FONT   13
$DEFINE DEVICE_DEFAULT_FONT   14
$DEFINE DEFAULT_PALETTE   15
$DEFINE SYSTEM_FIXED_FONT   16
$DEFINE STOCK_LAST   16


$DEFINE DI_MASK &H1
$DEFINE DI_IMAGE &H2
Const DI_NORMAL = DI_MASK Or DI_IMAGE



'  Ternary raster operations (DWORD)
CONST SRCCOPY = &HCC0020 		'dest = source
CONST SRCPAINT = &HEE0086        'dest = source OR dest
CONST SRCAND = &H8800C6  		'dest = source AND dest
CONST SRCINVERT = &H660046       'dest = source XOR dest
CONST SRCERASE = &H440328        'dest = source AND (NOT dest )
CONST NOTSRCCOPY = &H330008      'dest = (NOT source)
CONST NOTSRCERASE = &H1100A6     'dest = (NOT src) AND (NOT dest)
CONST MERGECOPY = &HC000CA       'dest = (source AND pattern)
CONST MERGEPAINT = &HBB0226      'dest = (NOT source) OR dest
CONST PATCOPY = &HF00021 		'dest = pattern
CONST PATPAINT = &HFB0A09        'dest = DPSnoo
CONST PATINVERT = &H5A0049       'dest = pattern XOR dest
CONST DSTINVERT = &H550009       'dest = (NOT dest)
CONST BLACKNESS = &H42 			'dest = BLACK
CONST WHITENESS = &HFF0062       'dest = WHITE




Const CCHDEVICENAME = 32
Const CCHFORMNAME = 32

TYPE DEVMODE
    dmDeviceName 		AS STRING * CCHDEVICENAME
    dmSpecVersion 		AS WORD
    dmDriverVersion 	AS WORD
    dmSize 				AS WORD
    dmDriverExtra 		AS WORD
    dmFields 			AS DWORD
	dmOrientation 		AS SHORT
    dmPaperSize 		AS SHORT
    dmPaperLength 		AS SHORT
    dmPaperWidth 		AS SHORT
    dmScale 			AS SHORT
    dmCopies 			AS SHORT
    dmDefaultSource 	AS SHORT
    dmPrintQuality 		AS SHORT
    dmColor 			AS SHORT
    dmDuplex 			AS SHORT
    dmYResolution 		AS SHORT
	dmTTOption 			AS SHORT
    dmCollate 			AS SHORT
    dmFormName 			AS STRING * CCHFORMNAME
    dmLogPixels 		AS WORD
    dmBitsPerPel 		AS DWORD
    dmPelsWidth 		AS DWORD
    dmPelsHeight 		AS DWORD
    dmDisplayFlags 		AS DWORD
    dmDisplayFrequency 	AS DWORD
END TYPE

'Display enumerations for Screen.SetResolution
$DEFINE EWX_LOGOFF 				 0
$DEFINE EWX_SHUTDOWN 			 1
$DEFINE EWX_REBOOT 				 2
$DEFINE EWX_FORCE 				 4
$DEFINE DM_BITSPERPEL 			 &H40000
$DEFINE DM_PELSWIDTH 			 &H80000
$DEFINE DM_PELSHEIGHT 			 &H100000
$DEFINE DM_DISPLAYFREQUENCY	 	 &H400000 
$DEFINE CDS_DYNAMIC 			 &H0
$DEFINE CDS_UPDATEREGISTRY	 	 &H1
$DEFINE CDS_TEST 				 &H4
$DEFINE CDS_FULLSCREEN 			 &H4
$DEFINE CDS_GLOBAL 				 &H8
$DEFINE CDS_SET_PRIMARY 		 &H10
$DEFINE CDS_RESET 				 &H40000000
$DEFINE CDS_SETRECT 			 &H20000000
$DEFINE CDS_NORESET 			 &H10000000
$DEFINE DISP_CHANGE_SUCCESSFUL	 0
$DEFINE DISP_CHANGE_RESTART 	 1
$DEFINE DISP_CHANGE_FAILED 		 -1
$DEFINE DISP_CHANGE_BADMODE 	 -2
$DEFINE DISP_CHANGE_NOTUPDATED	 -3
$DEFINE DISP_CHANGE_BADFLAGS 	 -4
$DEFINE DISP_CHANGE_BADPARAM 	 -5
$DEFINE ENUM_CURRENT_SETTINGS	 -1    'try 0 then call again with a non-zero to restore
$DEFINE ENUM_REGISTRY_SETTINGS	 -2

'  Device Parameters for GetDeviceCaps()
$DEFINE DRIVERVERSION    0      '  Device driver version
$DEFINE TECHNOLOGY    2         '  Device classification
$DEFINE HORZSIZE    4           '  Horizontal size in millimeters
$DEFINE VERTSIZE    6           '  Vertical size in millimeters
$DEFINE HORZRES    8            '  Horizontal width in pixels
$DEFINE VERTRES    10           '  Vertical width in pixels
$DEFINE BITSPIXEL    12         '  Number of bits per pixel
$DEFINE PLANES    14            '  Number of planes
$DEFINE NUMBRUSHES    16        '  Number of brushes the device has
$DEFINE NUMPENS    18           '  Number of pens the device has
$DEFINE NUMMARKERS    20        '  Number of markers the device has
$DEFINE NUMFONTS    22          '  Number of fonts the device has
$DEFINE NUMCOLORS    24         '  Number of colors the device supports
$DEFINE PDEVICESIZE    26       '  Size required for device descriptor
$DEFINE CURVECAPS    28         '  Curve capabilities
$DEFINE LINECAPS    30          '  Line capabilities
$DEFINE POLYGONALCAPS    32     '  Polygonal capabilities
$DEFINE TEXTCAPS    34          '  Text capabilities
$DEFINE CLIPCAPS    36          '  Clipping capabilities
$DEFINE RASTERCAPS    38        '  Bitblt capabilities
$DEFINE ASPECTX    40           '  Length of the X leg
$DEFINE ASPECTY    42           '  Length of the Y leg
$DEFINE ASPECTXY    44          '  Length of the hypotenuse

$DEFINE LOGPIXELSX    88        '  Logical pixels/inch in X
$DEFINE LOGPIXELSY    90        '  Logical pixels/inch in Y

$DEFINE SIZEPALETTE    104      '  Number of entries in physical palette
$DEFINE NUMRESERVED    106      '  Number of reserved entries in palette
$DEFINE COLORRES    108         '  Actual color resolution


'------ AlphaBlending  with microsoft imaging dll -----
'----
Const AC_SRC_OVER = &H00
Const AC_SRC_ALPHA = &H1

Type BLENDFUNCTION
  BlendOp 		As Byte
  BlendFlags 	As Byte
  SourceConstantAlpha As Byte
  AlphaFormat 	As Byte
End Type

Declare Function AlphaBlend Lib "msimg32.dll" Alias "AlphaBlend" _
(hdc1 As Long, X1 As integer, Y1 As integer, Width1 As integer, Height1 As integer,_
 hdc2 As Long, X2 As integer, Y2 As integer, Width2 As integer, Height2 As integer, BLEND As BLENDFUNCTION) As Long



'----Windows GDI functions
'
DECLARE FUNCTION CreateDC Lib "gdi32" Alias "CreateDCA" (_
	ByVal lpDriverName As String, _
	ByVal lpDeviceName As String, _
	ByVal lpOutput As String,_
	lpInitData As DEVMODE) AS LONG
DECLARE FUNCTION BitBlt Lib "gdi32.dll" Alias "BitBlt" (_
	ByVal hdcDest As Long,_
	ByVal nXDest As Long,_
	ByVal nYDest As Long,_
	ByVal nWidth As Long,_
	ByVal nHeight As Long,_
	ByVal hdcSrc As Long,_
	ByVal nXSrc As Long,_
	ByVal nYSrc As Long,_
	ByVal dwRop As Long) AS LONG


DECLARE FUNCTION CreateCompatibleBitmap Lib "gdi32" Alias "CreateCompatibleBitmap" (hdc As Long,nWidth As Long,nHeight As Long) As Long
DECLARE FUNCTION CreateCompatibleDC Lib "gdi32" Alias "CreateCompatibleDC" (hdc As Long) As Long
DECLARE FUNCTION CreatePen Lib "gdi32" Alias "CreatePen" (nPenStyle As Long, nWidth As Long, crColor As Long) As Long
DECLARE FUNCTION CreateSolidBrush Lib "gdi32" Alias "CreateSolidBrush" (crColor As Long) As Long
DECLARE FUNCTION DeleteDC Lib "gdi32" Alias "DeleteDC" (hdc As Long) As Long
DECLARE FUNCTION DeleteObject Lib "gdi32" Alias "DeleteObject" (hObject As Long) As Long
DECLARE FUNCTION Ellipse Lib "gdi32" Alias "Ellipse" (hdc As Long,X1 As Long,Y1 As Long,X2 As Long,Y2 As Long) As Long
DECLARE FUNCTION ExtFloodFill Lib "gdi32" Alias "ExtFloodFill" (hdc As Long,x As Long,y As Long,crColor As Long,wFillType As Long) As Long
DECLARE FUNCTION GetDeviceCaps LIB "gdi32.dll" ALIAS "GetDeviceCaps"(ByVal hdc AS LONG, ByVal nIndex AS LONG) AS LONG
DECLARE FUNCTION GetObject Lib "gdi32" Alias "GetObjectA" (hObject As Long,nCount As Long, lpObject AS TBITMAP) As Long
DECLARE FUNCTION GetCurrentObject Lib "gdi32" Alias "GetCurrentObject" (hdc As Long,uObjectType As Long) As Long
DECLARE FUNCTION GetPixel Lib "gdi32" Alias "GetPixel" (hdc as Long,x as Long,y as Long) as Long
DECLARE FUNCTION GetStockObject Lib "gdi32" Alias "GetStockObject" (nIndex As Long) As Long
DECLARE FUNCTION LineTo Lib "gdi32" Alias "LineTo" (hdc As Long,x As Long,y As Long) As Long
DECLARE FUNCTION MoveToEx Lib "gdi32" Alias "MoveToEx" (hdc As Long,x As Long,y As Long, lpPoint As long) As Long
DECLARE FUNCTION PatBlt Lib "gdi32" Alias "PatBlt" (hdc As Long,x As Long,y As Long,nWidth As Long,nHeight As Long,dwRop As Long) As Long
DECLARE FUNCTION Rectangle Lib "gdi32" Alias "Rectangle" (hdc As Long,X1 As Long,Y1 As Long,X2 As Long,Y2 As Long) As Long
DECLARE FUNCTION RoundRect Lib "gdi32" Alias "RoundRect" (hdc As Long,X1 As Long,Y1 As Long,X2 As Long,Y2 As Long,X3 As Long,Y3 As Long) As Long
DECLARE FUNCTION SelectObject Lib "gdi32" Alias "SelectObject" (hdc As Long,hObject As Long) As Long
DECLARE FUNCTION SetROP2 Lib "gdi32" Alias "SetROP2" (hdc As Long,nDrawMode As long) As Long
DECLARE FUNCTION SetBkMode Lib "gdi32" Alias "SetBkMode" (hdc As Long,nBkMode As Long) As Long
DECLARE FUNCTION StretchBlt Lib "gdi32" Alias "StretchBlt" (hdc As Long,x As Long,y As Long,nWidth As Long,nHeight As Long,hSrcDC As Long,xSrc As Long,ySrc As Long,nSrcWidth As Long,nSrcHeight As Long,dwRop As Long) As Long





'---------Windows User32 functions
'
DECLARE FUNCTION GetDesktopWindow Lib "user32" Alias "GetDesktopWindow" () AS LONG
'DECLARE FUNCTION DrawIcon Lib "user32" Alias "DrawIcon" (hdc As Long,x As Long,y As Long,hIcon As Long) As Long
DECLARE FUNCTION DrawIconEx Lib "user32" Alias "DrawIconEx" (hdc As Long,xLeft As Long,yTop As Long,hIcon As Long,cxWidth As Long,cyWidth As Long,istepIfAniCur As Long,hbrFlickerFreeDraw As Long,diFlags As Long) As Long
DECLARE FUNCTION LoadImage Lib "user32" ALIAS "LoadImageA" (hInst AS LONG,lpsz AS STRING, dwImageType AS LONG,dwDesiredWidth AS LONG, dwDesiredHeight AS LONG,dwFlags AS LONG) AS LONG
DECLARE FUNCTION EnumDisplaySettings LIB "user32" ALIAS "EnumDisplaySettingsA" (byref DeviceName AS STRING, byval iModeNum AS DWORD, byref DevMo AS DevMode) AS LONG
DECLARE FUNCTION ChangeDisplaySettings LIB "user32" ALIAS "ChangeDisplaySettingsA" (DevMo AS DevMode, ByVal dwFlags AS LONG) AS LONG
DECLARE FUNCTION ExitWindowsEx LIB "user32" ALIAS "ExitWindowsEx" (ByVal uFlags AS LONG, ByVal dwReserved AS LONG) AS LONG
DECLARE FUNCTION GetDC LIB "user32.dll" ALIAS "GetDC"(ByVal hwnd AS LONG) AS LONG
DECLARE FUNCTION ReleaseDC LIB "user32.dll" ALIAS "ReleaseDC"(ByVal hwnd AS LONG, ByVal hdc AS LONG) AS LONG
DECLARE FUNCTION SetActiveWindow Lib "USER32" Alias "SetActiveWindow" (hWnd as integer) as integer
DECLARE FUNCTION SystemParametersInfo Lib "user32" Alias "SystemParametersInfoA" (uAction as Long,uParam as Long,lpvParam as Long,fuWinIni as Long) as Long


DECLARE SUB RtlMoveMemory Lib "kernel32.dll" Alias "RtlMoveMemory" (byref Destination AS LONG, byref Source AS LONG, Length AS LONG)



'priority classess for setting the priority of your application, default is NORMAL_PRIORITY_CLASS
	$DEFINE IDLE_PRIORITY_CLASS              &H40     'very slow, for occasional running
	$DEFINE BELOW_NORMAL_PRIORITY_CLASS      &H4000   'Win2000, NT, XP+ only!!!
	$DEFINE NORMAL_PRIORITY_CLASS            &H20		'normal
	$DEFINE ABOVE_NORMAL_PRIORITY_CLASS      &H8000   'Win2000, NT, XP+ only!!!
	$DEFINE HIGH_PRIORITY_CLASS              &H80     'careful, other programs suffer
	$DEFINE REALTIME_PRIORITY_CLASS          &H100    'CAUTION!! REALTIME mouse,no keyboard, no disk, you own the CPU!

DECLARE FUNCTION SetPriorityClass  Lib "kernel32" ALIAS "SetPriorityClass"  (ByVal hProcess As Long, ByVal dwPriorityClass As Long) As Long
DECLARE FUNCTION GetPriorityClass  Lib "kernel32" ALIAS "GetPriorityClass"  (ByVal hProcess As Long) As Long
DECLARE FUNCTION GetCurrentProcess Lib "kernel32" ALIAS  "GetCurrentProcess" () As Long

DECLARE FUNCTION GetDriveType Lib "kernel32" Alias "GetDriveTypeA" (nDrive As String) As Long
DECLARE FUNCTION GetDiskFreeSpaceEx LIB "kernel32" ALIAS "GetDiskFreeSpaceExA"_
	 (lpRootPathName AS STRING, lpFreeBytesAvailableToCaller AS LONG,_
	 lpTotalNumberOfBytes AS LONG, lpTotalNumberOfFreeBytes AS LONG) AS LONG


'--------------- QMenuEx windows API -------------------
$DEFINE ODT_MENU      1%
$DEFINE ODS_SELECTED  1%
$DEFINE ODS_GRAYED    2%
$DEFINE ODS_DISABLED  4%
$DEFINE ODS_CHECKED   8%
$DEFINE ODS_FOCUS     &H10%
$DEFINE ODS_DEFAULT   &H20%
$DEFINE ODS_COMBOBOXEDIT      &H1000%

$DEFINE MF_BYCOMMAND   0
$DEFINE MF_BYPOSITION  &H400
$DEFINE MF_OWNERDRAW   &H100
$DEFINE MF_GRAYED      &H1
$DEFINE MF_DISABLED    &H2
$DEFINE MF_STRING      0
$DEFINE MF_BITMAP      4
$DEFINE MF_HILITE      &H80

$DEFINE COLOR_MENU          4 'Menu
$DEFINE COLOR_MENUTEXT      7 'Window Text
$DEFINE COLOR_HIGHLIGHT     13 'Selected item background
$DEFINE COLOR_HIGHLIGHTTEXT 14 'Selected menu item
$DEFINE COLOR_GRAYTEXT      17 'Grey text, of zero if dithering is used.


$DEFINE MIIM_STATE      &H1
$DEFINE MIIM_ID          &H2
$DEFINE MIIM_SUBMENU      &H4
$DEFINE MIIM_CHECKMARKS  &H8
$DEFINE MIIM_DATA      &H20
$DEFINE MIIM_TYPE      &H10

$DEFINE MFT_BITMAP        &H4
$DEFINE MFT_MENUBARBREAK  &H20
$DEFINE MFT_MENUBREAK     &H40
$DEFINE MFT_OWNERDRAW     &H100
$DEFINE MFT_RADIOCHECK    &H200
$DEFINE MFT_RIGHTJUSTIFY  &H4000
$DEFINE MFT_RIGHTORDER    &H2000
$DEFINE MFT_SEPARATOR     &H800
$DEFINE MFT_STRING        &H0
$DEFINE MFS_CHECKED       &H8
$DEFINE MFS_DEFAULT       &H1000
$DEFINE MFS_DISABLED      &H2
$DEFINE MFS_ENABLED       &H0
$DEFINE MFS_GRAYED        &H1
$DEFINE MFS_HILITE        &H80
$DEFINE MFS_UNCHECKED     &H0
$DEFINE MFS_UNHILITE      &H0

     TYPE MEASUREITEMSTRUCT
      CtlType AS LONG
      CtlID AS LONG
      itemID AS LONG
      itemWidth AS LONG
      itemHeight AS LONG
      itemData AS DWORD
     END TYPE

     TYPE DRAWITEMSTRUCT		'offset
      CtlType 		AS LONG		'0
      CtlID 		AS LONG		'4
      itemID 		AS LONG		'8
      itemAction 	AS LONG
      itemState 	AS LONG
      hwndItem 		AS LONG
      hDC 			AS LONG
      left 			AS LONG
      top 			AS LONG
      right 		AS LONG
      bottom 		AS LONG		'40
      itemData 		AS DWORD	'44
     END TYPE

     TYPE MENUITEMINFO
      cbSize AS LONG
      fMask AS LONG
      fType AS LONG
      fState AS LONG
      wID AS LONG
      hSubMenu AS LONG
      hbmpChecked AS LONG
      hbmpUnchecked AS LONG
      dwItemData AS LONG
      dwTypeData AS LONG
      cch AS LONG
     END TYPE


Declare Function GetSysColor Lib "user32" Alias "GetSysColor" (nIndex As Long) As Long
DECLARE FUNCTION GetMenu LIB "user32" ALIAS "GetMenu" (hWnd AS LONG) AS LONG
DECLARE FUNCTION GetMenuItemInfo LIB "user32.dll" ALIAS "GetMenuItemInfoA" (ByVal hMenu AS LONG, ByVal uItem AS LONG, ByVal fByPosition AS LONG, lpmii AS MENUITEMINFO) AS LONG
DECLARE FUNCTION SetMenuItemInfo LIB "user32.dll" ALIAS "SetMenuItemInfoA" (ByVal hMenu AS LONG, ByVal uItem AS LONG, ByVal fByPosition AS LONG, lpmii AS MENUITEMINFO) AS LONG
DECLARE FUNCTION InsertMenuItem LIB "user32.dll" ALIAS "InsertMenuItemA" (ByVal hMenu AS LONG, ByVal uItem AS LONG, ByVal fByPosition AS LONG, lpmii AS MENUITEMINFO) AS LONG
DECLARE FUNCTION ModifyMenu LIB "USER32" ALIAS "ModifyMenuA" (hMenu AS LONG,uPosition AS LONG,uFlags AS LONG,uIDNewItem AS LONG,lpNewItem AS LONG) AS LONG
'DECLARE FUNCTION DestroyMenu Lib "user32" Alias "DestroyMenu" (ByVal hMenu As Long) As Long

TYPE CHOOSECOLOR
     lStructSize 	AS LONG
     hWndOwner 		AS LONG
     hInstance 		AS LONG
     rgbResult 		AS LONG
     lpCustColors(1 TO 16) AS LONG
     Flags 			AS DWORD
     lCustData 		AS LONG
     lpfnHook 		AS LONG
     lpTemplateName AS LONG
END TYPE

'Flags for CHOOSECOLOR.Flags (see QColorDialog box)
$DEFINE CC_RGBINIT          &H1
$DEFINE CC_FULLOPEN         &H2
$DEFINE CC_PREVENTFULLOPEN  &H4
$DEFINE CC_SHOWHELP         &H8
$DEFINE CC_ENABLEHOOK       &H10
$DEFINE CC_ENABLETEMPLATE   &H20
$DEFINE CC_ENABLETEMPLATEHANDLE        &H40
$DEFINE CC_SOLIDCOLOR       &H80
$DEFINE CC_ANYCOLOR         &H100


'Flags for OPENFILENAME.Flags (see QFileDialog box)
CONST OFN_READONLY                 =  &H00000001  
CONST OFN_OVERWRITEPROMPT          =  &H00000002  'display the overwrite warning
CONST OFN_HIDEREADONLY             =  &H00000004  'hide the Open as Readonly checkbox
CONST OFN_NOCHANGEDIR              =  &H00000008  'return to original director if the user changed the directory while searching
CONST OFN_SHOWHELP                 =  &H00000010
CONST OFN_ENABLEHOOK               =  &H00000020
CONST OFN_ENABLETEMPLATE           =  &H00000040
CONST OFN_ENABLETEMPLATEHANDLE     =  &H00000080
CONST OFN_NOVALIDATE               =  &H00000100
CONST OFN_ALLOWMULTISELECT         =  &H00000200   'multiple file select, should have OFN_EXPLORER = 1 for long filenames
CONST OFN_EXTENSIONDIFFERENT       =  &H00000400
CONST OFN_PATHMUSTEXIST            =  &H00000800
CONST OFN_FILEMUSTEXIST            =  &H00001000
CONST OFN_CREATEPROMPT             =  &H00002000
CONST OFN_SHAREAWARE               =  &H00004000
CONST OFN_NOREADONLYRETURN         =  &H00008000
CONST OFN_NOTESTFILECREATE         =  &H00010000
CONST OFN_NOLONGNAMES              =  &H00040000
CONST OFN_EXPLORER                 =  &H00080000	'explorer like browser
CONST OFN_NODEREFERENCELINKS       =  &H00100000
CONST OFN_LONGNAMES                =  &H00200000



TYPE OPENFILENAME
	lStructSize 	AS DWORD	'Specifies the length, in bytes, of the structure. 
	hwndOwner 		AS LONG		'any valid window handle, or it can be NULL if the dialog box has no owner
	hInstance 		AS LONG		'for OFN_ENABLETEMPLATEHANDLE or ENABLETEMPLATE  flags
	lpstrFilter 	AS LONG		'pointer to string containing pairs of filter strings, ("*.TXT;*.DOC;*.BAK"), no spaces!
	lpstrCustomFilter AS LONG	'null or pointer to a pair of null-terminated filter strings for preserving the filter pattern chosen by the user
	nMaxCustFilter 	AS DWORD	'the size, in bytes of the buffer identified by lpstrCustomFilter
	nFilterIndex 	AS DWORD	'index of the currently selected filter in the File Types 
	lpstrFile 		AS LONG		'Pointer to string of the file name to initialize control,can be multple if OFN_ALLOWMULTISELECT  set, _
								'first char must be NULL if no initialization. Returns drive designator, path, file name, and extension of the selected file. 
	nMaxFile 		AS DWORD	'size in bytes of lpstrFile should be >256 chars
	lpstrFileTitle 	AS LONG		'Pointer to string that receives the file name and extension (without path information) of the selected file. This member can be NULL
	nMaxFileTitle 	AS DWORD	'size in bytes of lpstrFileTitle
	lpstrInitialDir AS LONG		'pointer to string containing directory, different effect on different OS versions!
	lpstrTitle 		AS LONG		'pointer to string containing title
	flags 			AS DWORD	'
	nFileOffset 	AS SHORT	'zero-based offset, number of chars  to the 1st character of the file name in lpstrFile (not path)
	nFileExtension 	AS SHORT	'zero-based offset, number of chars  to the 1st character of the file extension in lpstrFile (not path)
	lpstrDefExt 	AS LONG		'pointer to string to append as filename extension if the user fails to type an extension- only 3 characters are used, should not contain a period (.)
	lCustData 		AS LONG		'AS LPARM
	lpfnHook 		AS LONG		'AS LPOFNHOOKPROC, pointer to callback function
	lpTemplateName 	AS LONG		'pointer to string that names a dialog template resource in the module identified by the hInstance member
'#if (_WIN32_WINNT >= 0x0500)
'  void *        pvReserved;
'  DWORD         dwReserved;
'  DWORD         FlagsEx;
'#endif // (_WIN32_WINNT >= 0x0500)
END TYPE


DECLARE FUNCTION ChooseColorDlg LIB "COMDLG32" ALIAS "ChooseColorA" (CC AS CHOOSECOLOR) AS LONG
DECLARE FUNCTION GetSaveFileName LIB "COMDLG32" ALIAS "GetSaveFileNameA" (pOpenfilename AS OPENFILENAME) AS LONG
DECLARE FUNCTION GetOpenFileName LIB "COMDLG32" ALIAS "GetOpenFileNameA" (pOpenfilename AS OPENFILENAME) AS LONG

'Error codes from CommDlgExtendedError
$DEFINE CDERR_DIALOGFAILURE   &HFFFF%   

$DEFINE CDERR_GENERALCODES   &H0%
$DEFINE CDERR_STRUCTSIZE   &H1%
$DEFINE CDERR_INITIALIZATION   &H2%   
$DEFINE CDERR_NOTEMPLATE   &H3%
$DEFINE CDERR_NOHINSTANCE   &H4%
$DEFINE CDERR_LOADSTRFAILURE   &H5%   
$DEFINE CDERR_FINDRESFAILURE   &H6%
$DEFINE CDERR_LOADRESFAILURE   &H7%
$DEFINE CDERR_LOCKRESFAILURE   &H8%
$DEFINE CDERR_MEMALLOCFAILURE   &H9%
$DEFINE CDERR_MEMLOCKFAILURE   &HA%
$DEFINE CDERR_NOHOOK   &HB%
$DEFINE CDERR_REGISTERMSGFAIL   &HC%


DECLARE FUNCTION CommDlgExtendedError Lib "comdlg32.dll" Alias "CommDlgExtendedError" () As Long






'**************************************************************
'**************************************************************
'***   
'***  'Win32 Communications User Defined Types       **********
'***  'use for COMPORT extension                     **********
'**************************************************************
'**************************************************************

'Structure containing time-out parameters for a communications device
     TYPE COMMTIMEOUTS
      ReadIntervalTimeout AS DWORD
      ReadTotalTimeoutMultiplier AS DWORD
      ReadTotalTimeoutConstant AS DWORD
      WriteTotalTimeoutMultiplier AS DWORD
      WriteTotalTimeoutConstant AS DWORD
     END TYPE

'Device Control Block
'Structure that defines the control settings for a serial communications device
     TYPE DCB
      DCBlength AS DWORD        'sizeof DCB
      BaudRate AS DWORD         'current baud rate
      DCBflags AS DWORD         'fBinary            1 bit binary mode, no EOF check
                                  'fParity            1 bit enable parity checking
                                  'fOutxCtsFlow       1 bit CTS output flow control (hardware flow control setting)
                                  'fOutxDsrFlow       1 bit DSR output flow control (hardware flow control setting)
                                  'fDtrControl        2 bit DTR flow control type (hardware flow control setting)
                                  'fDsrSensitivity    1 bit DSR sensitivity (hardware flow control setting)
                                  'fTXContinueOnXoff  1 bit XOFF continues Tx (software flow control setting)
                                  'fOutX              1 bit XON/XOFF out flow control (software flow control setting)
                                  'fInX               1 bit XON/XOFF in flow control (software flow control setting)
                                  'fErrorChar         1 bit enable error replacement
                                  'fNull              1 bit enable null stripping
                                  'fRtsControl        2 bit RTS flow control (hardware flow control setting)
                                  'fAbortOnError      1 bit abort on error (hardware flow control setting)
                                  'fDummy2           17 bit reserved
      wReserved AS WORD         'reserved
      XonLim AS WORD            'transmit XON threshold (software flow control setting)
      XoffLim AS WORD           'transmit XOFF threshold (software flow control setting)
      ByteSize AS BYTE          'number of bits/byte, 4-8
      Parity AS BYTE            '0-4=no,odd,even,mark,space
      StopBits AS BYTE          '0,1,2=1,1.5,2
      XonChar AS BYTE           'Tx and Rx XON character (software flow control setting)
      XoffChar AS BYTE          'Tx and Rx XOFF character (software flow control setting)
      ErrorChar AS BYTE         'error replacement character
      EofChar AS BYTE           'end of input character
      EvtChar AS BYTE           'received event character
      wReserved1 AS WORD        'reserved; do not use
     END TYPE

'Structure containing current Comm Port State
     TYPE COMSTAT
      COMSTATflags AS DWORD     'fCtsHold           1 bit Specifies whether waiting for CTS signal
                                  'fDsrHold           1 bit Specifies whether waiting for DSR signal
                                  'fRlsHold           1 bit Specifies whether waiting for RLSD signal
                                  'fXoffHold          1 bit Specifies whether waiting because XOFF character was received
                                  'fXoffSent          1 bit Specifies whether waiting because XOFF character was transmitted
                                  'fEof               1 bit Specifies whether EOF char has been received
                                  'fTxim              1 bit character queued for transmission because of TransmitCommChar
                                  'fReserved         25 bit Reserved
      cbInQue AS DWORD          'number of bytes received but not yet read
      cbOutQue AS DWORD         'number of bytes remaining to be transmitted
     END TYPE

'Win32 File Handling User Defined Types

'Structure that contains the security descriptor for an object
'not currently used by us
     TYPE SECURITYATTRIBUTES
      nLength AS DWORD
      lpSecurityDescriptor AS LONG
      bInheritHandle AS LONG
     END TYPE

'Structure containing info used in Overlapped (asynchronous) I/O
'not currently used by us
     TYPE OVERLAPPED
      Internal AS LONG
      InternalHigh AS LONG
      offset AS DWORD
      OffsetHigh AS DWORD
      hEvent AS LONG
     END TYPE

'DCB Constants
'Parity
     CONST NOPARITY              = 0
     CONST ODDPARITY             = 1
     CONST EVENPARITY            = 2
     CONST MARKPARITY            = 3
     CONST SPACEPARITY           = 4
'StopBits
     CONST ONESTOPBIT            = 0
     CONST ONE5STOPBITS          = 1
     CONST TWOSTOPBITS           = 2

'PurgeCOM constants
'dwFlags
     CONST PURGE_RXABORT         = &H2
     CONST PURGE_RXCLEAR         = &H8
     CONST PURGE_TXABORT         = &H1
     CONST PURGE_TXCLEAR         = &H4

'Win32 File Handling Constants

'dwDesired Access Constants
     CONST GENERIC_READ          = &H80000000
     CONST GENERIC_WRITE         = &H40000000
'dwShareMode Constants
     CONST FILE_SHARE_READ       = &H1
     CONST FILE_SHARE_WRITE      = &H2
'dwCreationDisposition Constants
     CONST CREATE_NEW            = 1
     CONST CREATE_ALWAYS         = 2
     CONST OPEN_EXISTING         = 3
     CONST OPEN_ALWAYS           = 4
     CONST TRUNCATE_EXISTING     = 5
'dwFlagsAndAttributes
     CONST FILE_ATTRIBUTE_NORMAL = &H80

'Win32 Error Constants
     CONST FORMAT_MESSAGE_ALLOCATE_BUFFER  = &H100
     CONST FORMAT_MESSAGE_FROM_SYSTEM      = &H1000
     CONST LANG_NEUTRAL                    = &H0
     CONST SUBLANG_DEFAULT                 = &H1
     CONST ERROR_BAD_USERNAME              = 2202&

'Error Message Constants
     CONST ERROR_OPEN_PORT                 = "There was an error opening the Comm Port.  "
     CONST ERROR_PORT_BUFFERS              = "There was an error creating the Comm Port Buffers.  "
     CONST ERROR_PURGE_BUFFERS             = "There was an error purging old data from the Comm Port Buffers.  "
     CONST ERROR_TIMEOUTS                  = "There was an error setting the Comm Port timeouts.  "
     CONST ERROR_RETRIEVE_PORTSETTINGS     = "There was an error retrieving the existing Comm Port settings.  "
     CONST ERROR_CHANGING_PORTSETTINGS     = "There was an error changing the Comm Port settings.  "
     CONST ERROR_CLOSING_PORT              = "There was an error closing the Comm Port.  "
     CONST ERROR_WRITING_PORT              = "There was an error writing data to the Comm Port.  "
     CONST ERROR_SENDING_DATA              = "Could not send all the data in time specified.  Try increasing your wait time."
     CONST ERROR_GETTING_PORT_STATUS       = "There was an error getting the Comm Ports current status.  "
     CONST ERROR_READING_PORT              = "There was an error reading data from the Comm Port.  "

'Win32 Function Declarations

'Suspends the execution of the current thread for the specified interval.
     DECLARE SUB SLEEP.ms LIB "kernel32" ALIAS "Sleep" (dwMilliseconds AS DWORD)

'Win32 Error Messages
'for setting null value for Qdebug
Declare Sub SetLastError Lib "kernel32" Alias "SetLastError" (ByVal dwErrCode As Long)
Declare Function WSAGetLastError Lib "WSOCK32" ALIAS "WSAGetLastError" () As Long

'Several Win32 functions set an error code if they fail.  This retrieves them.
'Note, If a function succeeds, it may not set this code.  If you retrieve it
'after a function succeeds, it may return an error code for a previous function that failed.
DECLARE FUNCTION GetLastError LIB "kernel32" ALIAS "GetLastError" () AS DWORD 
                  'Returns last error code value
                  'See http://msdn.microsoft.com/library/default.asp?url=/library/en-us/debug/errlist_7oz7.asp
                  'for what codes mean

'Converts GetLastError codes to string messages.
     DECLARE FUNCTION FormatMessage LIB "kernel32" ALIAS "FormatMessageA" _
      (dwFlags AS DWORD, _                            '[IN] Specifies aspects of the formatting process and how to interpret lpSource
      lpSource AS LONG, _                       '[IN] Specifies the location of the message definition
      dwMessageId AS DWORD, _                         '[IN] Specifies the message identifier for the requested message
      dwLanguageId AS DWORD, _                        '[IN] Specifies the language identifier for the requested message
      BYREF lpBuffer AS STRING, _                     '[OUT] Pointer to a buffer for the formatted message
      nSize AS DWORD, _                               '[IN] specifies the max number of characters that can be stored in the output buffer
      lpArguments AS LONG) _                      '[IN] Pointer to an array of values that are used as insert values in the formatted message
      AS LONG                                       ''If function succeeds, returns non-zero. If function fails, returns 0.

'Win32 Communication Functions

' Initializes the communications parameters for a specified
' communications device.
     DECLARE FUNCTION SetupComm LIB "kernel32" ALIAS "SetupComm"_
      (hFile AS LONG,_                                '[IN] Handle to open Comm device
      dwInQueue AS DWORD,_                           '[IN] specifies number of bytes of input buffer
      dwOutQueue AS DWORD) _                         '[IN] specifies number of bytes of output buffer
      AS LONG                                     'If function succeeds, returns non-zero. If function fails, returns 0.

' Discards all characters from the output or input buffer of a
' specified communications resource. It can also terminate
' pending read or write operations on the resource.
     DECLARE FUNCTION PurgeComm LIB "kernel32" ALIAS "PurgeComm"_
      (hFile AS LONG, _                               '[IN] Handle to open Comm device
      dwFlags AS DWORD) _                            '[IN] Action to perform flag
      AS LONG                                     'If function succeeds, returns non-zero. If function fails, returns 0.

' Sets the time-out parameters for all read and write operations on a
' specified communications device.
     DECLARE FUNCTION SetCommTimeouts LIB "kernel32" ALIAS "SetCommTimeouts"_
      (hFile AS LONG,_                                '[IN] Handle to open Comm device
      lpCommTimeouts AS COMMTIMEOUTS) _              '[IN] Structure containing timeout values
      AS LONG                                     'If function succeeds, returns non-zero. If function fails, returns 0.

'Retrieves current Device Control Block (DCB)
     DECLARE FUNCTION GetCommState LIB "kernel32" ALIAS "GetCommState" _
      (hFile AS LONG, _                               '[IN] Handle to open Comm device
      lpDCB AS DCB) _                                 '[OUT] Pointer to structure containing config info
      AS LONG                                     'If function succeeds, returns non-zero. If function fails, returns 0.

'Sets Device Control Block (DCB)
     DECLARE FUNCTION SetCommState LIB "kernel32" ALIAS "SetCommState" _
      (hFile AS LONG, _                               '[IN] Handle to open Comm device
      lpDCB AS DCB) _                                 '[IN] Pointer to structure containing config info
      AS LONG                                     'If function succeeds, returns non-zero. If function fails, returns 0.

' Retrieves information about a communications error and reports
' the current status of a communications device. Clears the
' device's error flag to enable additional input and output
' (I/O) operations.
     DECLARE FUNCTION ClearCommError LIB "kernel32" ALIAS "ClearCommError" _
      (hFile AS LONG,_                                '[IN] Handle to open Comm device
      BYREF lpErrors AS DWORD,_                      '[OUT] Pointer to var to be filled with a mask indicating the type of error
      lpStat AS COMSTAT) _                           '[OUT] Pointer to structure containing devices status info
      AS LONG                                     'If function succeeds, returns non-zero. If function fails, returns 0.

'Win32 File Handling Functions

'Create or open a new Comm device/file
     DECLARE FUNCTION CreateFile LIB "kernel32" ALIAS "CreateFileA"_
      (lpFileName AS STRING, _                        '[IN] String that specifies name of object to create or open
      dwDesiredAccess AS DWORD, _                     '[IN] Specifies type of access to object
      dwShareMode AS DWORD, _                         '[IN] Specifies how object is to be shared
      lpSecurityAttributes AS SECURITYATTRIBUTES, _   '[IN] Pointer to Structure that determines whether object can be inherited by child processes
      dwCreationDisposition AS DWORD, _               '[IN] Specifies which action to take on files that exist/do not exist
      dwFlagsAndAttributes AS DWORD,_                 '[IN] Specifies the file attributes and flags
      hTemplateFile AS LONG) _                        '[IN] handle to template that supplies file attributes
      AS LONG                                     'If successful, returns handle to object/file created

' Writes data to a file
' We are not using Overlapped (asynchronous) I/O
     DECLARE FUNCTION WriteFile LIB "kernel32" ALIAS "WriteFile"_
      (hFile AS LONG, _                               '[IN] Handle to open Comm device/file
      lpBuffer AS STRING, _                    '[IN] Pointer to buffer containing the data to be written to Comm device/file
      nNumberOfBytesToWrite AS DWORD, _              '[IN] Specifies number of bytes to write to file
      BYREF lpNumberOfBytesWritten AS DWORD, _       '[OUT] Pointer to var containing number of bytes written
      lpOverlapped AS OVERLAPPED) _                  '[IN] Pointer to structure containing info if Comm device/file was opened in Overlapped mode.
      AS LONG                                       'If function succeeds, returns non-zero. If function fails, returns 0.

'Alternative write file, that handles asynchronous writing, so your program can do other things while writing to Comm device
'	 DECLARE FUNCTION WriteFileEx LIB "kernel32" ALIAS "WriteFileEx"_
'      (hFile AS LONG, _                             '[IN] Handle from CreateFile API (Comm device/file), must have been created with the FILE_FLAG_OVERLAPPED flag and with GENERIC_WRITE 
'      BYREF lpBuffer AS STRING, _                   '[IN] Pointer to buffer containing the data to be written to Comm device/file
'      nNumberOfBytesToWrite AS DWORD, _             '[IN] Specifies number of bytes to write to file
'      lpOverlapped AS OVERLAPPED) _                 '[IN] Pointer to structure containing info if Comm device/file was opened in Overlapped mode
'      BYVAL lpCompletionRoutine AS LONG)_	          '[IN] Pointer to completion routine, nested structure...
'      AS LONG                                       'If function succeeds, returns non-zero. If function fails, returns 0.


'Reads data from a file
'We are not using Overlapped (asynchronous) I/O
     DECLARE FUNCTION ReadFile LIB "kernel32" ALIAS "ReadFile"_
      (hFile AS LONG, _                               '[IN] Handle to open Comm device/file
      BYREF lpBuffer AS STRING, _                    '[OUT] Pointer to buffer that receives data from Comm device/file
      nNumberOfBytesToRead AS DWORD, _               '[IN] Specifies number of bytes to be read from file
      BYREF lpNumberOfBytesRead AS DWORD, _          '[OUT] Specifies number of bytes read from file
      lpOverlapped AS OVERLAPPED) _                  '[IN] Pointer to structure containing info if Comm device/file was opened in Overlapped mode.
      AS LONG                                     'If function succeeds, returns non-zero. If function fails, returns 0.

     DECLARE FUNCTION CloseHandle LIB "kernel32" ALIAS "CloseHandle" _
      (hObject AS LONG) _                             '[IN/OUT] Handle to open Comm device/file
      AS LONG                                     'If function succeeds, returns non-zero. If function fails, returns 0.
                                       'If function succeeds, returns non-zero. If function fails, returns 0.

'alternate API allows asynch I/O but lets an application perform other processing during a file read operation.
     DECLARE FUNCTION ReadFileEx Lib "kernel32" Alias "ReadFileEx"_
      (BYVAL hFile AS LONG, _                         '[IN] Handle to open Comm device/file
       BYREF lpBuffer AS STRING, _                    '[OUT] Pointer to buffer that receives data from Comm device/file, not use this buffer until the read operation is completed.
       BYVAL nNumberOfBytesToRead AS DWORD, _         '[IN] Specifies number of bytes to be read from file
       lpOverlapped AS OVERLAPPED,_                   '[IN] Pointer to structure containing info if Comm device/file was opened in Overlapped mode.
       BYVAL lpCompletionRoutine AS LONG)_            '[IN] address of the routine for after completion
      AS LONG                                         'If function succeeds, returns non-zero. If function fails, returns 0.


' **** Windows API calls for Qsystem components *****
TYPE OSVERSIONINFO  
    dwOSVersionInfoSize 	As Long  
    dwMajorVersion 			As Long  
    dwMinorVersion 			As Long  
    dwBuildNumber 			As Long  
    dwPlatformId 			As Long  
    szCSDVersion 			As String * 128  
END TYPE  

$DEFINE  VER_PLATFORM_WIN32s   0  
$DEFINE  VER_PLATFORM_WIN32_WINDOWS   1  
$DEFINE  VER_PLATFORM_WIN32_NT   2  
Declare Function GetVersionEx Lib "kernel32.dll" Alias "GetVersionExA" (lpVersionInformation As OSVERSIONINFO) As Long  



$DEFINE AC_LINE_OFFLINE         &H0
$DEFINE AC_LINE_ONLINE          &H1
$DEFINE AC_LINE_BACKUP_POWER    &H2
$DEFINE AC_LINE_UNKNOWN         &HFF
$DEFINE BATTERY_FLAG_HIGH       &H1
$DEFINE BATTERY_FLAG_LOW        &H2
$DEFINE BATTERY_FLAG_CRITICAL   &H4
$DEFINE BATTERY_FLAG_CHARGING   &H8
$DEFINE BATTERY_FLAG_NO_BATTERY &H80
$DEFINE BATTERY_FLAG_UNKNOWN    &HFF
$DEFINE BATTERY_PERCENTAGE_UNKNOWN   &HFF
$DEFINE BATTERY_LIFE_UNKNOWN    &HFFFF

Type SYSTEM_POWER_STATUS
        ACLineStatus 		As Byte
        BatteryFlag 		As Byte
        BatteryLifePercent 	As Byte
        Reserved1 			As Byte
        BatteryLifeTime 	As Long
        BatteryFullLifeTime As Long
End Type

Declare Function GetSystemPowerStatus Lib "kernel32" Alias "GetSystemPowerStatus" (lpSystemPowerStatus As SYSTEM_POWER_STATUS) As Long
Declare Function SetSystemPowerState Lib "kernel32" Alias "SetSystemPowerState" (ByVal fSuspend As Long, ByVal fForce As Long) As Long
Declare Function SetSuspendState Lib "Powrprof" Alias "SetSuspendState" (ByVal Hibernate As Long, ByVal ForceCritical As Long, ByVal DisableWakeEvent As Long) As Long


Type MEMORYSTATUS
        dwLength As Long
        dwMemoryLoad As Long
        dwTotalPhys As Long
        dwAvailPhys As Long
        dwTotalPageFile As Long
        dwAvailPageFile As Long
        dwTotalVirtual As Long
        dwAvailVirtual As Long
End Type

Declare Sub GlobalMemoryStatus Lib "kernel32" ALIAS "GlobalMemoryStatus" (lpBuffer As MEMORYSTATUS)

' GetSystemMetrics() codes
$DEFINE SM_CXSCREEN   0
$DEFINE SM_CYSCREEN   1
$DEFINE SM_CXVSCROLL   2
$DEFINE SM_CYHSCROLL   3
$DEFINE SM_CYCAPTION   4
$DEFINE SM_CXBORDER   5
$DEFINE SM_CYBORDER   6
$DEFINE SM_CXDLGFRAME   7
$DEFINE SM_CYDLGFRAME   8
$DEFINE SM_CYVTHUMB   9
$DEFINE SM_CXHTHUMB   10
$DEFINE SM_CXICON   11
$DEFINE SM_CYICON   12
$DEFINE SM_CXCURSOR   13
$DEFINE SM_CYCURSOR   14
$DEFINE SM_CYMENU   15
$DEFINE SM_CXFULLSCREEN   16
$DEFINE SM_CYFULLSCREEN   17
$DEFINE SM_CYKANJIWINDOW   18
$DEFINE SM_MOUSEPRESENT   19
$DEFINE SM_CYVSCROLL   20
$DEFINE SM_CXHSCROLL   21
$DEFINE SM_DEBUG   22
$DEFINE SM_SWAPBUTTON   23
$DEFINE SM_RESERVED1   24
$DEFINE SM_RESERVED2   25
$DEFINE SM_RESERVED3   26
$DEFINE SM_RESERVED4   27
$DEFINE SM_CXMIN   28
$DEFINE SM_CYMIN   29
$DEFINE SM_CXSIZE   30
$DEFINE SM_CYSIZE   31
$DEFINE SM_CXFRAME   32
$DEFINE SM_CYFRAME   33
$DEFINE SM_CXMINTRACK   34
$DEFINE SM_CYMINTRACK   35
$DEFINE SM_CXDOUBLECLK   36
$DEFINE SM_CYDOUBLECLK   37
$DEFINE SM_CXICONSPACING   38
$DEFINE SM_CYICONSPACING   39
$DEFINE SM_MENUDROPALIGNMENT   40
$DEFINE SM_PENWINDOWS   41
$DEFINE SM_DBCSENABLED   42
$DEFINE SM_CMOUSEBUTTONS   43
$DEFINE SM_CMETRICS   44
CONST SM_CXSIZEFRAME =  SM_CXFRAME
CONST SM_CYSIZEFRAME =  SM_CYFRAME
CONST SM_CXFIXEDFRAME = SM_CXDLGFRAME
CONST SM_CYFIXEDFRAME = SM_CYDLGFRAME
$DEFINE SM_NETWORK   63
$DEFINE SM_SLOWMACHINE   73
$DEFINE SM_MOUSEWHEELPRESENT   75
$DEFINE SM_CXVIRTUALSCREEN   78
$DEFINE SM_CYVIRTUALSCREEN   79
$DEFINE SM_CMONITORS   80
$DEFINE SM_SAMEDISPLAYFORMAT   81

Declare Function GetSystemMetrics Lib "user32" Alias "GetSystemMetrics" (ByVal nIndex As Long) As Long

'multiple Callbacks fix for custom components
Declare Function GetProcessHeap Lib "kernel32" Alias "GetProcessHeap" () As Long
Declare Function HeapAlloc Lib "kernel32" Alias "HeapAlloc" (ByVal hHeap As Long, ByVal dwFlags As Long, ByVal dwBytes As Long) As Long

' ===========  for shutdown ===============

Type LUID
    LowPart As Long
    HighPart As Long
End Type

Type LUID_AND_ATTRIBUTES
    ' pLuid As LUID
    LowPart as Long
    HightPart as Long
    Attributes As Long
End Type

Type TOKEN_PRIVILEGES
    PrivilegeCount As Long      ' Privileges(1) As LUID_AND_ATTRIBUTES
    LowPart as long
    HighPart as long
    Attributes as long
End Type

$DEFINE TOKEN_ADJUST_PRIVILEGES &H20
$DEFINE TOKEN_QUERY &H8
$DEFINE SE_PRIVILEGE_ENABLED &H2

Declare Function OpenProcessToken Lib "advapi32" Alias "OpenProcessToken" _
    (ProcessHandle As Long, _
    DesiredAccess As Long, _
    TokenHandle As Long) As Long

Declare Function LookupPrivilegeValue Lib "advapi32" Alias "LookupPrivilegeValueA" _
    (lpSystemName As String, _
    lpName As String, _
    lpLuid As LUID) As Long

Declare Function AdjustTokenPrivileges Lib "advapi32" Alias "AdjustTokenPrivileges" _
    (TokenHandle As Long, _
    DisableAllPrivileges As Long, _
    NewState As TOKEN_PRIVILEGES, _
    BufferLength As Long, _
    PreviousState As TOKEN_PRIVILEGES, _
    ReturnLength As Long) As Long



$ENDIF		'__RQ2WIN32API  end of Windows declarations in RapidQ2







'====================================================================================================================
'====================================================================================================================
'-----------------------------  RapidQ2 Extensions --------------------------------------------------------------
' Hopefully this will be a standard way to add new keywords to RapidQ 
' Not all previous custom components are included, just the ones that are main parts of RapidQ language
'JohnK   (9/2005)
'
' (documentation of most extensions by our good French friend, D. Glodt
'******************************************************************************
'
'--------------------------------------------------------------------------
'=======================================================================================================


$IFNDEF __RQINC2
$DEFINE __RQINC2			'don't reload this include
'
$DEFINE BOOLEAN LONG		'need this line for extended types


'
'****************************************************************************************
'
'  JPG, GIF Graphics libraries through External DLL. This sets up forward declarations,
'  these are libraries that other RQ coders usually have around. Be sure to get the
'  latest version of the DLL
'****************************************************************************************
'
  $IFNDEF __WIN32API
    Declare Function LoadLibrary Lib "kernel32" Alias "LoadLibraryA" (ByVal lpLibFileName As String) As Long
  $ENDIF

	'signal nviewlib.dll is present
	DEFINT NViewLibPresent = 0
	NViewLibPresent = LoadLibrary("nviewlib.dll")		'returns DLL handle, don't use 'LIBRARYINST("nviewlib.dll")
	IF NViewLibPresent <> 0 THEN
	NViewLibPresent = 1
	'Load JPG/GIF functions are replaced by the new "NViewLoad" - you do not have to check the extension any more,
	'the new function does everything!  Jpeg and GIF files are detected by parsing the file,
	'the file extension does not have to be jpg, jif, or gif (DLL by K. Nishita.)
	'old versions:
	'Declare Function Load_JPG 			Lib "nviewlib.dll" Alias "Load_JPG" (FileName As String,Progress As Integer) As Long
	'Declare Function Load_GIF 			Lib "nviewlib.dll" Alias "Load_GIF" (FileName As String,Progress As Integer) As Long
	Declare Function NViewSetLanguage 	Lib "nviewlib.dll" Alias "NViewLibSetLanguage" (Language As String) As Integer
	Declare Function NViewLoad 			Lib "nviewlib.dll" Alias "NViewLibLoad" (FileName As String,Progress As Integer) As Long
	Declare Function NViewGetHeight		Lib "nviewlib.dll" Alias "GetHeight" () As Integer
	Declare Function NViewGetWidth		Lib "nviewlib.dll" Alias "GetWidth" () As Integer
	Declare Function NViewSaveAsJPG 	Lib "nviewlib.dll" Alias "NViewLibSaveAsJPG" (Quality As Integer,FileName As String) As Integer
	UNLOADLIBRARY("nviewlib.dll")
	END IF

	'need this library for reliable jpg loading, can also load ico bmp, gif, wmf and emf formats
	IF LoadLibrary("jpeg.dll") <> 0 THEN		'returns DLL handle, don't use 'LIBRARYINST("nviewlib.dll")
	 NViewLibPresent = 2
     DECLARE FUNCTION JpegDLL_LoadImageFile LIB "jpeg.dll" ALIAS "LoadImageFile" (hWnd AS LONG, file$ AS STRING) AS INTEGER
     DECLARE FUNCTION JpegDLL_ImageHeight LIB "jpeg.dll" ALIAS "ImageHeight" (hImg AS LONG) AS INTEGER
     DECLARE FUNCTION JpegDLL_ImageWidth LIB "jpeg.dll" ALIAS "ImageWidth" (hImg AS LONG) AS INTEGER
	 UNLOADLIBRARY("jpeg.dll")
	END IF
'********************************************************************************************************





'********************************************************************************************************
' multiple custom components that use a WndProc need to call this function and have the code 
' run in this function too.   Documentation:
' The CallBack Forwarder Code will be Generated in an allocated memory space, the pointer to that
' space is returned by the function. 
' ForwardTo a function pointer to our callback funtion (+ one one : first = CallBack Index you choose)
' CBIndex a user choosen number to identify this CallBack forwarder
'   Code contribution by Jacques Phillip and Paul Ludgate
' --------------------------------------------------------------------------------\

FUNCTION gRQ2_SetNewCallBack (ForwardTo AS LONG, CBIndex AS LONG) AS LONG
  DEFLNG hProcessHeap = GetProcessHeap
  DEFLNG ptrForwarder = HeapAlloc (hProcessHeap, 12, 36)
  DIM mTmp AS QMEMORYSTREAM
  WITH mTmp
'     .Size = 36
'     .Position = 0  
'     .WriteNum(&H1024448B, 4)    ' mov  eax, [esp+16]
'     .WriteNum(&H50      , 1)    ' push eax
'     .WriteNum(&H1024448B, 4)    ' mov  eax, [esp+16]
'     .WriteNum(&H50      , 1)    ' push eax
'     .WriteNum(&H1024448B, 4)    ' mov  eax, [esp+16]
'     .WriteNum(&H50      , 1)    ' push eax
'     .WriteNum(&H1024448B, 4)    ' mov  eax, [esp+16]
'     .WriteNum(&H50      , 1)    ' push eax
'     .WriteNum(&H68      , 1)    ' push ...
'     .WriteNum(CBIndex   , 4)    ' ... CBIndex
'     .WriteNum(&HB8      , 1)    ' mov  eax, ...
'     .WriteNum(&Forwardto, 4)    ' ... ForwardTo
'     .WriteNum(&HD0FF    , 2)    ' call eax
'     .WriteNum(&H000010C2, 4)    ' ret  16
'     memcpy (ptrForwarder, .Pointer, 36)

' Jaques modified code
    .Size = 14
    .Position = 0
    .WriteNum(&H58 , 1)         ' pop Eax
    .WriteNum(&H68 , 1)         ' push ...
    .WriteNum(CBIndex , 4)      ' ... CBIndex
    .WriteNum(&H50 , 1)         ' push eax
    .WriteNum(&HB8 , 1)         ' mov eax, ...
    .WriteNum(&Forwardto, 4)    ' ... ForwardTo
    .WriteNum(&HE0FF , 2)       ' jmp eax
     memcpy (ptrForwarder, .Pointer, 14)
  END WITH
  Result = ptrForwarder
END FUNCTION



'  *************************  one FUNCTION gets all custom callbacks  *************************
$IFNDEF __MAXCALLBACKS
    $DEFINE __MAXCALLBACKS 24
$ENDIF

DECLARE FUNCTION gRQ2_MasterWndProc(iFuncIndex AS LONG, hwnd AS LONG, uMsg AS LONG, wParam AS LONG, lParam AS LONG) AS LONG

'globals to have several custom components (QFormEx, etc) in one application
DEFINT gRQ2_WndProcNum                   'global for keeping track of number of WndProcs
DEFINT gRQ2_lpMasterWndProc              'pointer to the global wndProc function
DEFINT gRQ2_WndProc(1 TO __MAXCALLBACKS) 'global for all instance WndProc address (max 100)
    'must do this to avoid compile time error
    For gRQ2_WndProcNum = 1 to __MAXCALLBACKS
        BIND gRQ2_WndProc(gRQ2_WndProcNum) TO gRQ2_MasterWndProc
    Next gRQ2_WndProcNum
    gRQ2_WndProcNum = 0                 'reset as temp var
    gRQ2_lpMasterWndProc = CODEPTR(gRQ2_MasterWndProc)      'set the address of the wndProc
'********************************************************************************************************






'====================================================================================================================
' -----------------  QFORMEX  version 1.9b   ----------------------------------
' John K.
'This component adds to the QformEx.inc component by  By D.Glodt (c) ---------
'====================================================================================================================

Declare Sub OnDrag_eventTemplate(file as string)
Declare Sub OnTrayClick_eventTemplate
Declare Sub OnTrayDblClick_eventTemplate
Declare Sub OnMinimise_eventTemplate
Declare Sub OnMouseWheel_eventTemplate(MouseRotation AS INTEGER, Xpos AS LONG, Ypos AS LONG, Shift AS INTEGER)
Declare Sub OnLostFocus_eventTemplate
Declare Sub OnGetFocus_eventTemplate

TYPE QFormEx EXTENDS QFORM
  PRIVATE:
    TrayIcon 		AS QNOTIFYICONDATA
    pOldProc 		AS LONG
    MyWndProc       AS LONG
    ThisFuncPtr     AS LONG
    flagWinProc 	AS boolean
    flagTrayIcon 	AS boolean
    virtual 		AS qform
    FrmTimer        AS QTIMER
    IconAnimCount   AS INTEGER

  PUBLIC:
    DragZone 		AS QRect
    DragEnable 		AS boolean PROPERTY SET SetDragEnable
    FormStyle 		AS integer PROPERTY SET SetFormStyle
    TrayICO         AS QIMAGELIST                           'add a BMP, ICO file, or ICO handle
    TrayIconHint    AS STRING  PROPERTY SET SetTrayIconHint
    TrayIconIndex   AS INTEGER PROPERTY SET SetTrayIconIndex
    TrayIconUpdate  AS INTEGER PROPERTY SET SetTrayIconUpdate

		'"hooks" into the Windows message stream via WindowProc
    OnDrag 			AS EVENT(OnDrag_eventTemplate)
    OnTrayClick		AS EVENT(OnTrayClick_eventTemplate)
    OnTrayDblClick	AS EVENT(OnTrayDblClick_eventTemplate)
    OnMinimise 		AS EVENT(OnMinimise_eventTemplate)
	OnMouseWheel 	AS EVENT(OnMouseWheel_eventTemplate)
    OnLostFocus     AS EVENT(OnLostFocus_eventTemplate)
    OnGetFocus      AS EVENT(OnGetFocus_eventTemplate)

 WITH QFormEX
 PRIVATE:

  '============================================
  ' Procedure to get windows messaging "winproc" needs 5 param to match RQ2 masterWndProc
  '============================================
  FUNCTION WindowProc (hwnd AS LONG, uMsg AS LONG, wParam AS LONG, lParam AS LONG, tmp as long) AS LONG
    DIM Point AS POINTAPI
    DIM i as integer
    DIM FileNam as string' : FileNam = SPACE$(256) no help, neither is global, or This.FileNam
    DIM Count as integer
    DIM Length as integer
    DIM MouseKeys As Long
    DIM MouseRotation As Long
    DIM MouseXpos As Long
    DIM MouseYpos As Long

   SELECT CASE uMsg
     CASE WM_DROPFILES
       DragQueryPoint(wParam,Point)
       if Point.X >= .DragZone.Left AND Point.Y >= .DragZone.Top and _
          Point.X < .DragZone.Right AND Point.Y < .DragZone.Bottom then
          Count = DragQueryFile(wParam,&HFFFFFFFF, 0&, 0&)
          FOR i = 0 to Count-1
              Length = DragQueryFile(wParam, i, 0&, 0&)
              FileNam = space$(Length +1)
              DragQueryFile(wParam, i, VARPTR(FileNam), Length+1)
              if .OnDrag <> 0 then CALLFUNC(QFormEx.OnDrag, FileNam)
           next i
       end if
       DragFinish(wParam)

     CASE WM_ACTIVATE, WM_KILLFOCUS             ' immediately before it loses the keyboard focus
        i = (wParam AND &HFFFF)                 'save computation
        IF (.OnLostFocus <> 0 ) AND (i = WA_INACTIVE) THEN
           CALLFUNC QFormEx.OnLostFocus
        END IF
        IF (.OnGetFocus <> 0) AND (i = WA_CLICKACTIVE OR i = WA_ACTIVE) THEN
           CALLFUNC QFormEx.OnGetFocus
        END IF
        QFormEx.WindowProc=CallWindowProc(QFormEx.pOldProc,hwnd,uMsg,wParam,lParam)


     CASE WM_SYSCOMMAND
        IF .OnMinimise <> 0 THEN
            IF wParam=SC_MINIMIZE and .flagTrayIcon=true THEN CALLFUNC QFormEx.OnMinimise
			RESULT = 0
        ELSE
          RESULT = CallWindowProc(QFormEx.pOldProc,hwnd,uMsg,wParam,lParam)
        END IF

     CASE WM_TRAYICON
      IF uMsg=WM_TRAYICON THEN
        IF (lParam AND &HFFFF)=WM_RBUTTONUP THEN
          if .OnTrayClick <> 0 then CALLFUNC QFormEx.OnTrayClick
        ELSEIF (lParam AND &HFFFF)=WM_LBUTTONDBLCLK THEN
          if .OnTrayDblClick <> 0 then CALLFUNC QFormEx.OnTrayDblClick
        END IF
      END IF


     CASE WM_MOUSEWHEEL
       IF .OnMouseWheel <> 0 THEN
          	MouseKeys = wParam AND &HFFFF
          	MouseRotation =SGN(wParam)		'more stable than wParam \ &H780000	'65536 * 120 (MouseDelta constant)
          	MouseXpos = lParam AND &HFFFF
          	MouseYpos = lParam / &HFFFF
		   CALLFUNC(QFormEx.OnMouseWheel,MouseRotation, MouseXpos, MouseYpos, MouseKeys)
		END IF

     CASE ELSE
         QFormEx.WindowProc=CallWindowProc(QFormEx.pOldProc,hwnd,uMsg,wParam,lParam)
     END SELECT
  End Function

 '========================================================
 ' take over the WndProc to dispatch windows messages
 '========================================================
  SUB GrabWindowProc()
    if .flagWinProc=false then
        'set this forms wndproc to the global RapidQ2 window handler
        IF QFormEx.Handle THEN
            INC gRQ2_WndProcNum             'set the index #
            'new address to function that forwards to MasterWndProc, Function is an allocated heap space
            .MyWndProc = gRQ2_SetNewCallBack(gRQ2_lpMasterWndProc, gRQ2_WndProcNum) 
            QFormEx.pOldProc=SetWindowLong(QFormEx.handle,GWL_WNDPROC, QFormEx.MyWndProc)   'subclass
            BIND gRQ2_WndProc(gRQ2_WndProcNum) TO QFormEx.WindowProc 
            .flagWinProc=true
        END IF
      end if
  END SUB


  '=============================================================================
  ' Allow form to minimize onto TaskBar, removed flag var since it was useless
  '=============================================================================
  SUB TaskBar()
      setwindowlong(QFormEx.handle,GWL_HWNDPARENT,HWND_DESKTOP)
      setwindowlong(application.handle,GWL_HWNDPARENT,QFormEx.handle)
      .GrabWindowProc
  END SUB

  PUBLIC:

  SUB RemoveTaskBar()       'just in case you don't want to minimize to task bar
    SetParent(QFormEx.Handle, QFormEx.virtual.handle)
  END SUB


  '============================================
  ' Form style, only fsNormal and fsStayOnTop supported 
  '  updated 4/2006, was QFormEx.Parent = virtual.Handle causes problems
  '============================================
  Property Set SetFormStyle(FStyle as integer)
    if FStyle = fsStayOnTop then
      QFormEx.formStyle = FStyle
      SetWindowPos(QFormEx.Handle, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE OR SWP_NOMOVE)
    else
      QFormEx.formStyle = FStyle
      SetWindowPos(QFormEx.Handle, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOSIZE OR SWP_NOMOVE)
    end if
  End Property
  

  '============================================
  ' Proprieté Acceptation de dépose fichier
  '============================================
  PROPERTY SET SetDragEnable(flag as boolean)
    DragAcceptFiles(QFormEx.Handle,flag)
    QFormEx.GrabWindowProc
  END PROPERTY


  '=============================================
  ' Méthode AddTrayIcon
  '=============================================
  Sub AddTrayIcon
    .TrayIcon.hWnd=QFormEx.Handle
    .TrayIcon.uID=Application.hInstance
    .TrayIcon.uFlags=NIF_MESSAGE OR NIF_ICON OR NIF_TIP
    .TrayIcon.uCallBackMessage=WM_TRAYICON
    IF .TrayICO.Count = 0 THEN 
         .TrayIcon.hIcon= QForm.Icon'Application.Icon
    ELSE
        QFormEx.Virtual.Icon = QFormEx.TrayICO.GetICO(0)        'need this to transfer right format
        .TrayIcon.hIcon = QformEx.Virtual.Icon                  'virtual is not shown, so use as temp storage
    END IF
    .TrayIcon.szTip=QFormEx.TrayIconHint
    Shell_NotifyIcon(NIM_ADD,QFormEx.TrayIcon)
    .GrabWindowProc
    .flagTrayIcon=true
  End Sub

  '=============================================
  ' Méthode DelTrayIcon
  '=============================================
  Sub DelTrayIcon
    Shell_NotifyIcon(NIM_DELETE,QFormEx.TrayIcon)
    QFormEx.flagTrayIcon=false
  End Sub  

  '=============================================
  ' Méthode ModifyTrayIcon
  '=============================================
  Sub ModifyTrayIcon
    Shell_NotifyIcon(NIM_MODIFY,QFormEx.TrayIcon)
  End Sub  

  '============================================
  ' Set a new hint
  '============================================
  PROPERTY SET SetTrayIconHint(NewStr AS STRING)
    QFormEx.TrayIconHint = NewStr + CHR$(0)
    IF QFormEx.flagTrayIcon THEN QFormEx.ModifyTrayIcon
  END PROPERTY

  '============================================
  ' If there are multiple tray icons then animate them
  '============================================
  PROPERTY SET SetTrayIconUpdate(newSpeed AS INTEGER)
    .TrayIconUpdate = newSpeed
    .FrmTimer.Interval = newSpeed
    IF newSpeed = 0 THEN .FrmTimer.Enabled = False ELSE .FrmTimer.Enabled = True 
  END PROPERTY

  '============================================
  ' pick one of multiple tray icons
  '============================================
  SUB SetTrayIconIndex(TheIndex AS INTEGER)
    IF TheIndex < = .TrayICO.Count THEN
        .Virtual.Icon = .TrayICO.GetICO(TheIndex - 1)    'need this to transfer right format
        .TrayIcon.hIcon = .Virtual.Icon                  'virtual is not shown, so use as temp storage
	    IF QFormEx.flagTrayIcon THEN QFormEx.ModifyTrayIcon
        .TrayIconIndex = TheIndex
	END IF
  END SUB


  '=========================================
  ' overwrite Center Method to fix inherited bug
  '=========================================
  Sub Center
	QFormEx.Left = Screen.Width\2 - QFormEx.Width\2
	QFormEx.Top= Screen.Height\2 - QFormEx.Height\2
  End Sub


 PRIVATE:
  SUB IcoAnimate()
    INC .IconAnimCount
    IF .IconAnimCount > .TrayICO.Count  - 1 THEN .IconAnimCount = 0
    .Virtual.Icon = .TrayICO.GetICO(.IconAnimCount)        'need this to transfer right format
    .TrayIcon.hIcon = .Virtual.Icon                         'virtual is not shown, so use as temp storage
	IF QFormEx.flagTrayIcon THEN QFormEx.ModifyTrayIcon
  END SUB


 PUBLIC:
  EVENT OnShow
       .GrabWindowProc
	   .TaskBar		'automatically minimize to TaskBar
        IF (.TrayICO.Count > 1) AND (.TrayIconUpdate > 0) THEN 
            .FrmTimer.Interval = .TrayIconUpdate
            .FrmTimer.Enabled = True
            .FrmTimer.OnTimer = QFormEx.IcoAnimate
        END IF
'        .InheritOnShow  'doesn't work
  END EVENT

  EVENT OnClose
    IF .flagTrayIcon THEN .DelTrayIcon
    .FrmTimer.Enabled = False
  END EVENT

 END WITH

  CONSTRUCTOR
    flagWinProc = false
    TrayIconHint = Application.Title+CHR$(0)
    FrmTimer.Enabled = False
    IconAnimCount = 0
    TrayIconUpdate = 2000       'every 2 seconds
  END CONSTRUCTOR

END TYPE





'====================================================================================================================
' QFormMDI  -- multiple document interface, D. Glodt
' Class QFormMDI Version 1.1 John Kelly
'
' This object re-uses the windows api constants 
'====================================================================================================================

'styles
$DEFINE MDI_EX_MDICHILD   &H40
$DEFINE MDI_CHILD         &H40000000
$DEFINE MDI_VISIBLE       &H10000000
$DEFINE MDI_OVERLAPPED    &H0
$DEFINE MDI_CAPTION       &HC00000
$DEFINE MDI_SYSMENU       &H80000
$DEFINE MDI_THICKFRAME    &H40000
$DEFINE MDI_MINIMIZEBOX   &H20000
$DEFINE MDI_MAXIMIZEBOX   &H10000
Const MDI_OVERLAPPEDWINDOW=(MDI_OVERLAPPED OR MDI_CAPTION OR MDI_SYSMENU OR MDI_THICKFRAME OR MDI_MINIMIZEBOX OR MDI_MAXIMIZEBOX)

'messages
$DEFINE MDI_MOVE        &H3
$DEFINE MDI_CLOSE       &H10
$DEFINE MDI_CREATE      &H1
$DEFINE MDI_DESTROY     &H2
$DEFINE MDI_SIZE        &H5
$DEFINE MDI_SYSCOMMAND  &H112
$DEFINE MDI_MDIDESTROY  &H221
$DEFINE MDI_MDIRESTORE  &H223
$DEFINE MDI_MDIMAXIMIZE &H225
$DEFINE MDI_MDITILE     &H226
$DEFINE MDI_MDICASCADE  &H227
$DEFINE MDI_MDIICONARRANGE    &H228
$DEFINE MDI_MDIACTIVATE &H222
$DEFINE MDI_MDISETMENU  &H230
$DEFINE MDI_MDINEXT     &H224
$DEFINE MDI_MDIGETACTIVE      &H229
$DEFINE MDI_CHILDACTIVATE     &H22
$DEFINE MDI_TILE_VERTICAL     &H0
$DEFINE MDI_TILE_HORIZONTAL   &H1

$DEFINE MDI_HWND_DESKTOP    0
$DEFINE MDI_USEDEFAULT    &H80000000
$DEFINE MDI_MINIMIZE    &HF020
$DEFINE MDI_MAXIMIZE      &HF030
CONST MDI_HWNDPARENT =   -8
CONST MDI_HICON      =   -14
$DEFINE MDI_COLOR_WINDOW    5
$DEFINE MDI_COLOR_BACKGROUND    1
$DEFINE MDI_COLOR_WINDOWFRAME    6
$DEFINE MDI_COLOR_APPWORKSPACE    12
$DEFINE MDI_COLOR_HIGHLIGHT    13

'Events
Declare Sub OnChildClose_eventTemplate(handleChild as long,index as integer,titleChild as string)
Declare Sub OnChildActive_eventTemplate(handleChild as long,index as integer,titleChild as string)
Declare Sub OnChildResize_eventTemplate(handleChild as long,index as integer,titleChild as string)


TYPE QFormMDI EXTENDS QFORM
  Private:
    hClient         as long
    hChild(1024)    as long
    hComponent      as long
    ClassName       as string
    ChildClass      AS WNDCLASSEX
    Rect            AS QRECT
    style           as long

  Public:
    ChildCaption as string 		PROPERTY SET SetChildCaption
    ChildHandle as long 		PROPERTY SET SetChildHandle
    ComponentIndex as integer 	PROPERTY SET SetComponentIndex
    ChildTop as short 			PROPERTY SET SetChildTop
    ChildLeft as short 			PROPERTY SET SetChildLeft
    ChildWidth as short 		PROPERTY SET SetChildWidth
    ChildHeight as short 		PROPERTY SET SetChildHeight
    MdiMenu as long 			PROPERTY SET SetMdiMenu
    ChildMax as integer 		PROPERTY SET SetChildMax
    ChildCount as integer		PROPERTY SET SetChildCount
    ChildState as integer 		PROPERTY SET SetChildState
    ChildIcon as long 			PROPERTY SET SetChildIcon
    ChildResult as integer
    OnChildClose as 			EVENT(OnChildClose_eventTemplate)
    OnChildActive as 			EVENT(OnChildActive_eventTemplate)
    OnChildResize as 			EVENT(OnChildResize_eventTemplate)
  
  Private:

  '========================================================
  ' Fonction callback recherche handle fenetre client MDI
  '========================================================
  Function EnumClient(hWnd as long, lParam as long) as long
    dim Buffer as string
    dim lpBuf  as long

    Buffer=Space$(255)
    lpBuf = VARPTR(Buffer)
    IF GetClassName(hWnd, lpBuf, 255) THEN
        if INSTR(UCASE$(Buffer),"MDICLIENT") then QFormMDI.hClient=hWnd
        Result=True
    END IF
  End Function

  '========================================================
  ' Fonction callback recherche handle fenetre fille MDI
  '========================================================
  Function EnumChild(hWnd as long,lParam as long) as long
    dim Buffer as string
   dim lpBuf  as long

    Buffer=Space$(255)
    lpBuf = VARPTR(Buffer)
    GetClassName(hWnd, lpBuf, 255)
    if INSTR(UCASE$(Buffer),"MDICHILD") then
      if QFormMDI.ChildCount>0 then
        if hwnd<>QFormMDI.hChild(QFormMDI.ChildCount-1) then
          QFormMDI.hChild(QFormMDI.ChildCount)=hWnd
          QFormMDI.ChildCount++
        end if
      else
        QFormMDI.hChild(QFormMDI.ChildCount)=hWnd
        QFormMDI.ChildCount++
      end if
    end if
    Result=true
  End Function

  '========================================================
  ' Procedure adaptation dimentions fenetre fille MDI
  '========================================================
  Sub GetSizeChild(hwnd as long)
    dim Rc as QRect
    dim Rw as QRect
    dim borderX as short
    dim borderY as short
    dim top as short
    dim left as short

    GetClientRect(QFormMDI.hClient,Rc)
    GetWindowRect(QFormMDI.hClient,Rw)
    top=Rw.top
    left=Rw.left
    borderX=((Rw.Right-Rw.Left)-Rc.Right)/2
    borderY=((Rw.Bottom-Rw.Top)-Rc.Bottom)/2
    GetWindowRect(hWnd,Rw)
    QFormMDI.ChildLeft=Rw.Left-(left+borderX)
    QFormMDI.ChildTop=Rw.Top-(top+borderY)
    QFormMDI.ChildWidth=Rw.Right-Rw.Left
    QFormMDI.ChildHeight=Rw.Bottom-Rw.Top
  End Sub

  '========================================================
  ' Fonction retourne etat fenetre fille MDI
  '========================================================
  Function GetState(hwnd as long) as short
    if isIconic(hwnd) then
      result=1
    elseif isZoomed(hwnd) then
      result=2
    else
      result=0
    end if
  End Function

  '========================================================
  ' Fonction retourne le texte caption d'une fenetre MDI
  '========================================================
  Function GetTextChild(hwnd as long) as string
    dim size as integer
    dim buffer as string    

    size=GetWindowTextLength(hwnd)
    buffer=Space$(size)+chr$(0)
    size=GetWindowText(hwnd,buffer,Len(buffer))
    result=Left$(buffer,size)
  End Function
  
public:
  '========================================================
  ' Procedure de fenetre enfant MDI
  '========================================================
  Function ChildProc(hWnd as long,uMsg as long,wParam as long,lParam as long, tmp AS LONG) as long
    Select Case uMsg
    Case MDI_CREATE
      SetParent(QFormMDI.hComponent,hWnd)
      ShowWindow(QFormMDI.hComponent,true)
      SetProp(hWnd,"EditHandle",QFormMDI.hComponent)
      SetProp(hWnd,"EditIndex",QFormMDI.ComponentIndex)
      QFormMDI.ChildCount++
      if QFormMDI.MdiMenu>0 then SendMessage(QFormMDI.hClient,MDI_MDISETMENU,0,QFormMDI.MdiMenu)
      Result=DefMDIChildProc(hWnd,uMsg,wParam,lParam)
    Case MDI_SIZE
      QFormMDI.hComponent=GetProp(hWnd,"EditHandle")
      QFormMDI.ComponentIndex=GetProp(hWnd,"EditIndex")
      QFormMDI.ChildCaption=QFormMDI.GetTextChild(hwnd)
      GetClientRect(hWnd,QFormMDI.Rect)
      MoveWindow(QFormMDI.hComponent,0,0,QFormMDI.Rect.Right,QFormMDI.Rect.Bottom,True)
      QFormMDI.GetSizeChild(hwnd)
      if QFormMDI.OnChildResize<>0 then CALLFUNC(QFormMDI.OnChildResize,hwnd,QFormMDI.ComponentIndex,QFormMDI.ChildCaption)
      Result=DefMDIChildProc(hWnd,uMsg,wParam,lParam)
    Case MDI_MDIACTIVATE
      QFormMDI.ChildHandle=hWnd
      QFormMDI.ChildCaption=QFormMDI.GetTextChild(hwnd)
      QFormMDI.GetSizeChild(hwnd)
      SetFocus(GetProp(lParam,"EditHandle"))
      QFormMDI.ComponentIndex=GetProp(hWnd,"EditIndex")
      QFormMDI.ChildState=QFormMDI.GetState(hwnd)
      if QFormMDI.OnChildActive<>0 then CALLFUNC(QFormMDI.OnChildActive,hwnd,QFormMDI.ComponentIndex,QFormMDI.ChildCaption)
      Result=DefMDIChildProc(hWnd,uMsg,wParam,lParam)
    Case MDI_CLOSE
      QFormMDI.ChildResult=True
      QFormMDI.ChildCaption=QFormMDI.GetTextChild(hwnd)
      QFormMDI.ComponentIndex=GetProp(hWnd,"EditIndex")
      if QFormMDI.OnChildClose<>0 then CALLFUNC(QFormMDI.OnChildClose,hwnd,QFormMDI.ComponentIndex,QFormMDI.ChildCaption)
      if QFormMDI.ChildResult>0 then
        Result=DefMDIChildProc(hWnd,uMsg,wParam,lParam)
      else
        Result=False
      end if
    Case MDI_DESTROY
      QFormMDI.hComponent=GetProp(hWnd,"EditHandle")
      MoveWindow(QFormMDI.hComponent,0,0,0,0,0)
      ShowWindow(QFormMDI.hComponent,false)
      SetParent(QFormMDI.hComponent,QFormMDI.handle)
      QFormMDI.ChildCount--
      Result=DefMDIChildProc(hWnd,uMsg,wParam,lParam)
    Case MDI_MOVE
      QFormMDI.GetSizeChild(hwnd)
      Result=DefMDIChildProc(hWnd,uMsg,wParam,lParam)
    Case else
      if QFormMDI.ChildCount>0 then
        QFormMDI.ChildState=QFormMDI.GetState(hwnd)
      end if
      Result=DefMDIChildProc(hWnd,uMsg,wParam,lParam)
    End Select
  End Function

  Public:

  '========================================================
  ' Proprieté nombre max fenetre fille MDI
  '========================================================
  Property Set SetChildMax(number as integer)
    if number<=1024 then QFormMDI.ChildMax=number
  End Property

  '========================================================
  ' Proprieté icon fenetre fille MDI
  '========================================================
  Property Set SetChildIcon(handle as long)
    if QFormMDI.ChildCount>0 then
      SetClassLong(QFormMDI.ChildHandle,MDI_HICON,handle)
    else
      QFormMDI.ChildClass.hIcon=handle
      QFormMDI.ChildClass.hIconSm=handle
    end if
  End Property

  '========================================================
  ' Proprieté caption fenetre fille MDI active
  '========================================================
  Property Set SetChildCaption(caption as string)
    if QFormMDI.ChildCount>0 then
      QFormMDI.ChildCaption=caption
      SetWindowText(QFormMDI.ChildHandle,QFormMDI.ChildCaption)
    end if
  End Property  

  '========================================================
  ' Proprieté handle fenetre fille MDI active
  '========================================================
  Property Set SetChildHandle(handle as long)
    'lecture uniquement
  End Property  

  '========================================================
  ' Proprieté index composant fenetre fille MDI active
  '========================================================
  Property Set SetComponentIndex(index as integer)
    'lecture uniquement
  End Property  

  '========================================================
  ' Proprieté top fenetre fille MDI active
  '========================================================
  Property Set SetChildTop(top as short)
    if QFormMDI.ChildCount>0 then
      QFormMDI.ChildTop=top
      MoveWindow(QFormMDI.ChildHandle,QFormMDI.ChildLeft,QFormMDI.ChildTop,QFormMDI.ChildWidth,QFormMDI.ChildHeight,True)
    end if
  End Property  

  '========================================================
  ' Proprieté left fenetre fille MDI active
  '========================================================
  Property Set SetChildLeft(left as short)
    if QFormMDI.ChildCount>0 then
      QFormMDI.ChildLeft=left
      MoveWindow(QFormMDI.ChildHandle,QFormMDI.ChildLeft,QFormMDI.ChildTop,QFormMDI.ChildWidth,QFormMDI.ChildHeight,True)
    end if
  End Property  

  '========================================================
  ' Proprieté width fenetre fille MDI active
  '========================================================
  Property Set SetChildWidth(width as short)
    if QFormMDI.ChildCount>0 then
      QFormMDI.ChildWidth=width
      MoveWindow(QFormMDI.ChildHandle,QFormMDI.ChildLeft,QFormMDI.ChildTop,QFormMDI.ChildWidth,QFormMDI.ChildHeight,True)
    end if
  End Property  

  '========================================================
  ' Proprieté height fenetre fille MDI active
  '========================================================
  Property Set SetChildHeight(height as short)
    if QFormMDI.ChildCount>0 then
      QFormMDI.ChildHeight=height
      MoveWindow(QFormMDI.ChildHandle,QFormMDI.ChildLeft,QFormMDI.ChildTop,QFormMDI.ChildWidth,QFormMDI.ChildHeight,True)
    end if
  End Property  

  '========================================================
  ' Proprieté handle menu fenetre fille MDI
  '========================================================
  Property Set SetMdiMenu(MenuHandle as long)
      if MenuHandle>0 then QFormMDI.MdiMenu=MenuHandle
  End Property  

  '========================================================
  ' Proprieté nombre fenetre fille MDI
  '========================================================
  Property Set SetChildCount(index as integer)
    'lecture uniquement
  End Property  

  '========================================================
  ' Proprieté etat fenetre fille MDI active
  '========================================================
  Property Set SetChildState(state as integer)
    if QFormMDI.ChildCount>0 then
      QFormMDI.ChildState=state
      if state=1 then
        SendMessage(QFormMDI.ChildHandle,MDI_SYSCOMMAND,MDI_MINIMIZE,0)
      elseif state=2 then
        SendMessage(QFormMDI.hClient,MDI_MDIMAXIMIZE,QFormMDI.ChildHandle,0)
        SetFocus(GetProp(QFormMDI.ChildHandle,"EditHandle"))
      else
        SendMessage(QFormMDI.hClient,MDI_MDIRESTORE,QFormMDI.ChildHandle,0)
        SetFocus(GetProp(QFormMDI.ChildHandle,"EditHandle"))
      end if
    end if
  End Property  
  
  '========================================================
  ' Méthode addition d'une fenetre fille MDI
  '========================================================
  Sub AddChild(handle as long,Title as string,index as integer,Left as short,Top as short,Width as short,Height as short,DefaultSize as boolean)
    dim lpEnumChild as long     'callback address (redirected)
    'init client MDI

    if QFormMDI.hClient=0 then
      QFormMDI.ChildClass.cbSize=SIZEOF(QFormMDI.ChildClass)
        ' ====== correct codeptr bug by redirecting window messaging =======
      INC gRQ2_WndProcNum
      BIND gRQ2_WndProc(gRQ2_WndProcNum) TO QFormMDI.ChildProc
      QFormMDI.ChildClass.lpfnWndProc = gRQ2_SetNewCallBack(gRQ2_lpMasterWndProc, gRQ2_WndProcNum) 
        '====================================================================
      QFormMDI.ChildClass.hbrBackground=MDI_COLOR_WINDOWFRAME
      QFormMDI.ChildClass.lpszClassName=VARPTR(QFormMDI.ClassName)
      'QFormMDI.ChildClass.hinstance=application.hinstance
      RegisterClassEx(QFormMDI.ChildClass)
        'don't need to redirect this temporary Codeptr unless you are using one with 2 params
      EnumChildWindows(QFormMDI.Handle,CODEPTR(QFormMDI.EnumClient),0)
    end if

    if QFormMDI.ChildCount<QFormMDI.ChildMax and handle<>0 then
      QFormMDI.hComponent=handle
      QFormMDI.ComponentIndex=index
      QFormMDI.style=MDI_CHILD OR MDI_VISIBLE OR MDI_OVERLAPPEDWINDOW
      if DefaultSize=True then
        'QFormMDI.hChild(QFormMDI.ChildCount)=CreateWindowEx(MDI_EX_MDICHILD,QFormMDI.ClassName,Title,QFormMDI.style,MDI_USEDEFAULT,MDI_USEDEFAULT,MDI_USEDEFAULT,MDI_USEDEFAULT,QFormMDI.hClient,0,application.hinstance,0)
        QFormMDI.hChild(QFormMDI.ChildCount)=CreateWindowEx(MDI_EX_MDICHILD,QFormMDI.ClassName,Title,QFormMDI.style,MDI_USEDEFAULT,MDI_USEDEFAULT,MDI_USEDEFAULT,MDI_USEDEFAULT,QFormMDI.hClient,0,0,0)
      else
        'QFormMDI.hChild(QFormMDI.ChildCount)=CreateWindowEx(MDI_EX_MDICHILD,QFormMDI.ClassName,Title,QFormMDI.style,Left,Top,Width,Height,QFormMDI.hClient,0,application.hinstance,0)
        QFormMDI.hChild(QFormMDI.ChildCount)=CreateWindowEx(MDI_EX_MDICHILD,QFormMDI.ClassName,Title,QFormMDI.style,Left,Top,Width,Height,QFormMDI.hClient,0,0,0)
      end if
    end if
  End Sub

  '========================================================
  ' Méthode fermeture fenetre fille MDI active
  '========================================================
  Sub CloseChild
    if QFormMDI.ChildCount>0 then
      QFormMDI.ChildResult=True
      QFormMDI.ChildHandle=SendMessageAPI(QFormMDI.hClient,MDI_MDIGETACTIVE,0,0)
      QFormMDI.ComponentIndex=GetProp(QFormMDI.ChildHandle,"EditIndex")
      QFormMDI.ChildCaption=QFormMDI.GetTextChild(QFormMDI.ChildHandle)
      if QFormMDI.OnChildClose<>0 then CALLFUNC(QFormMDI.OnChildClose,QFormMDI.CHildHandle,QFormMDI.ComponentIndex,QFormMDI.ChildCaption)
      if QFormMDI.ChildResult>0 then
        SendMessage(QFormMDI.hClient,MDI_MDIDESTROY,QFormMDI.ChildHandle,0)
      end if
      if QFormMDI.ChildCount>0 then
        QFormMDI.ChildHandle=SendMessageAPI(QFormMDI.hClient,MDI_MDIGETACTIVE,0,0)
        QFormMDI.ComponentIndex=GetProp(QFormMDI.ChildHandle,"EditIndex")
        QFormMDI.ChildCaption=QFormMDI.GetTextChild(QFormMDI.ChildHandle)
        QFormMDI.ChildState=QFormMDI.GetState(QFormMDI.ChildHandle)
        QFormMDI.GetSizeChild(QFormMDI.ChildHandle)
        SetFocus(GetProp(QFormMDI.ChildHandle,"EditHandle"))
      end if
    end if
  End Sub

  '========================================================
  ' Méthode fermeture fenetres fille MDI
  '========================================================
  Sub CloseAllChild 
    dim i as integer

    if QFormMDI.ChildCount>0 then
      QFormMDI.ChildCount=0
        'don't need to redirect this temporary Codeptr unless you are using one with 2 params
      EnumChildWindows(QFormMDI.hClient,CODEPTR(QFormMDI.EnumChild),0)
      if QFormMDI.ChildCount>1 then
        for i=0 to QFormMDI.ChildCount-1
          QFormMDI.ChildResult=True
          QFormMDI.ComponentIndex=GetProp(QFormMDI.hChild(i),"EditIndex")
          QFormMDI.ChildCaption=QFormMDI.GetTextChild(QFormMDI.hChild(i))
          if QFormMDI.OnChildClose<>0 then CALLFUNC(QFormMDI.OnChildClose,QFormMDI.hChild(i),QFormMDI.ComponentIndex,QFormMDI.ChildCaption)
          if QFormMDI.ChildResult>0 then
            SendMessage(QFormMDI.hClient,MDI_MDIDESTROY,QFormMDI.hChild(i),0)
          end if
        next i
      else
        if QFormMDI.ChildCount>0 then
          QFormMDI.ChildResult=True
          QFormMDI.ComponentIndex=GetProp(QFormMDI.hChild(0),"EditIndex")
          QFormMDI.ChildCaption=QFormMDI.GetTextChild(QFormMDI.hChild(0))
          if QFormMDI.OnChildClose<>0 then CALLFUNC(QFormMDI.OnChildClose,QFormMDI.hChild(0),QFormMDI.ComponentIndex,QFormMDI.ChildCaption)
          if QFormMDI.ChildResult>0 then
            SendMessage(QFormMDI.hClient,MDI_MDIDESTROY,QFormMDI.hChild(0),0)
          end if
        end if
      end if
      if QFormMDI.ChildCount>0 then
        QFormMDI.ChildHandle=SendMessageAPI(QFormMDI.hClient,MDI_MDIGETACTIVE,0,0)
        QFormMDI.ComponentIndex=GetProp(QFormMDI.ChildHandle,"EditIndex")
        QFormMDI.ChildCaption=QFormMDI.GetTextChild(QFormMDI.ChildHandle)
        QFormMDI.ChildState=QFormMDI.GetState(QFormMDI.ChildHandle)
        QFormMDI.GetSizeChild(QFormMDI.ChildHandle)
        SetFocus(GetProp(QFormMDI.ChildHandle,"EditHandle"))
      end if
    end if
  End Sub

  '========================================================
  ' Méthode mise en cascade des fenetres fille MDI
  '========================================================
  Sub CascadeChild
    if QFormMDI.ChildCount>0 then
      SendMessage(QFormMDI.hClient,MDI_MDICASCADE,0,0)
    end if
  End Sub

  '========================================================
  ' Méthode mise en horizontale fenetres fille MDI
  '========================================================
  Sub SetHorzChild
    if QFormMDI.ChildCount>0 then
      SendMessage(QFormMDI.hClient,MDI_MDITILE,MDI_TILE_HORIZONTAL,0)
    end if
  End Sub

  '========================================================
  ' Méthode mise en verticale fenetres fille MDI
  '========================================================
  Sub SetVertChild
    if QFormMDI.ChildCount>0 then
      SendMessage(QFormMDI.hClient,MDI_MDITILE,MDI_TILE_VERTICAL,0)
    end if
  End Sub

  '========================================================
  ' Méthode arrangement des fenetres fille MDI en icone
  '========================================================
  Sub IconArrangeChild
    if QFormMDI.ChildCount>0 then
      SendMessage(QFormMDI.hClient,MDI_MDIICONARRANGE,0,0)
    end if
  End Sub

  '========================================================
  ' Méthode reduit en icone les fenetres fille MDI
  '========================================================
  Sub MinimizeAllChild
    dim i as integer

    if QFormMDI.ChildCount>0 then
      QFormMDI.ChildCount=0
        'don't need to redirect this temporary Codeptr unless you are using one with 2 params
      EnumChildWindows(QFormMDI.hClient,CODEPTR(QFormMDI.EnumChild),0)
      for i=0 to QFormMDI.ChildCount-1
        SendMessage(QFormMDI.hChild(i),MDI_SYSCOMMAND,MDI_MINIMIZE,0)
      next i
      if QFormMDI.ChildCount>0 then
        QFormMDI.ChildHandle=SendMessageAPI(QFormMDI.hClient,MDI_MDIGETACTIVE,0,0)
        QFormMDI.ComponentIndex=GetProp(QFormMDI.ChildHandle,"EditIndex")
        QFormMDI.ChildCaption=QFormMDI.GetTextChild(QFormMDI.ChildHandle)
        QFormMDI.ChildState=QFormMDI.GetState(QFormMDI.ChildHandle)
        QFormMDI.GetSizeChild(QFormMDI.ChildHandle)
        SetFocus(GetProp(QFormMDI.ChildHandle,"EditHandle"))
      end if
    end if
  End Sub

  '========================================================
  ' Méthode met en taille maxi les fenetres fille MDI
  '========================================================
  Sub MaximizeAllChild
    dim i as integer

    if QFormMDI.ChildCount>0 then
      QFormMDI.ChildCount=0
        'don't need to redirect this temporary Codeptr unless you are using one with 2 params
      EnumChildWindows(QFormMDI.hClient,CODEPTR(QFormMDI.EnumChild),0)
      for i=0 to QFormMDI.ChildCount-1
        SendMessage(QFormMDI.hClient,MDI_MDIMAXIMIZE,QFormMDI.hChild(i),0)
      next i
      if QFormMDI.ChildCount>0 then
        QFormMDI.ChildHandle=SendMessageAPI(QFormMDI.hClient,MDI_MDIGETACTIVE,0,0)
        QFormMDI.ComponentIndex=GetProp(QFormMDI.ChildHandle,"EditIndex")
        QFormMDI.ChildCaption=QFormMDI.GetTextChild(QFormMDI.ChildHandle)
        QFormMDI.ChildState=QFormMDI.GetState(QFormMDI.ChildHandle)
        QFormMDI.GetSizeChild(QFormMDI.ChildHandle)
        SetFocus(GetProp(QFormMDI.ChildHandle,"EditHandle"))
      end if
    end if
  End Sub

  '========================================================
  ' Méthode restauration taille des fenetres fille MDI
  '========================================================
  Sub RestoreChild
    dim i as integer

    if QFormMDI.ChildCount>0 then
      QFormMDI.ChildCount=0
        'don't need to redirect this temporary Codeptr unless you are using one with 2 params
      EnumChildWindows(QFormMDI.hClient,CODEPTR(QFormMDI.EnumChild),0)
      for i=0 to QFormMDI.ChildCount-1
        SendMessage(QFormMDI.hClient,MDI_MDIRESTORE,QFormMDI.hChild(i),0)
      next i
      if QFormMDI.ChildCount>0 then
        QFormMDI.ChildHandle=SendMessageAPI(QFormMDI.hClient,MDI_MDIGETACTIVE,0,0)
        QFormMDI.ComponentIndex=GetProp(QFormMDI.ChildHandle,"EditIndex")
        QFormMDI.ChildCaption=QFormMDI.GetTextChild(QFormMDI.ChildHandle)
        QFormMDI.ChildState=QFormMDI.GetState(QFormMDI.ChildHandle)
        QFormMDI.GetSizeChild(QFormMDI.ChildHandle)
        SetFocus(GetProp(QFormMDI.ChildHandle,"EditHandle"))
      end if
    end if
  End Sub

  '========================================================
  ' Méthode active la fenetre fille MDI suivante
  '========================================================
  Sub ActiveNextChild
    if QFormMDI.ChildCount>0 then
      SendMessage(QFormMDI.hClient,MDI_MDINEXT,QFormMDI.ChildHandle,False)
    end if
  End Sub

  '========================================================
  ' Méthode active la fenetre fille MDI précedente
  '========================================================
  Sub ActivePreviousChild
    if QFormMDI.ChildCount>0 then
      SendMessage(QFormMDI.hClient,MDI_MDINEXT,QFormMDI.ChildHandle,True)
    end if
  End Sub

  '========================================================
  ' Méthode retourne index titre fenetre fille MDI 
  '========================================================
  Function GetChild(title as string) as integer
    dim i as integer
    dim index as integer

    if QFormMDI.ChildCount>0 then
      QFormMDI.ChildCount=0
        'don't need to redirect this temporary Codeptr unless you are using one with 2 params
      EnumChildWindows(QFormMDI.hClient,CODEPTR(QFormMDI.EnumChild),0)
      index=0
      for i=0 to QFormMDI.ChildCount-1
        if title=QFormMDI.GetTextChild(QFormMDI.hChild(i)) then index=i
      next i
      result=index
    else
      result=0
    end if
  End Function

  '========================================================
  ' Méthode retourne l'existence titre fenetre fille MDI 
  '========================================================
  Function ChildExist(title as string) as boolean
    dim i as integer
    dim exist as integer

    if QFormMDI.ChildCount>0 then
      QFormMDI.ChildCount=0
        'don't need to redirect this temporary Codeptr unless you are using one with 2 params
      EnumChildWindows(QFormMDI.hClient,CODEPTR(QFormMDI.EnumChild),0)
      exist=False
      for i=0 to QFormMDI.ChildCount-1
        if title=QFormMDI.GetTextChild(QFormMDI.hChild(i)) then exist=True
      next i
      result=exist
    else
      result=False
    end if
  End Function


  '========================================================
  ' Méthode active la fenetre fille MDI par index
  '========================================================
  Sub ActiveChild(index as integer)
    if QFormMDI.ChildCount>0 then
      SendMessage(QFormMDI.hClient,MDI_MDIACTIVATE,QFormMDI.hChild(index),0)
    end if
  End Sub

  '========================================================
  ' Méthode retourne etat associé MDI d'un composant 
  '========================================================
  Function FreeChild(handle as long) as boolean
    if GetParent(handle)=QFormMDI.handle then
      result=True
    else
      result=False
    end if
  End Function
  
  '=============================================================================
  ' méthode application dans barre outil bureau lors de la reduction fenetre
  '=============================================================================
  Sub SetDeskBar
    SetWindowLong(QFormMDI.handle,MDI_HWNDPARENT,MDI_HWND_DESKTOP)
    SetWindowLong(application.handle,MDI_HWNDPARENT,QFormMDI.handle)
  End Sub
    
  Constructor
    FormStyle=2
    Color=-2147483636
    ChildMax=1024
    ClassName="MDIChild"
    hClient=0
    ChildCount=0
  End Constructor
END TYPE







'====================================================================================================================
'--   QDOCKFORM is similar to QForm but can dock, it really extends a QPANEL
'--- original by Ben Laws (c) 2004  
'--- Modified for Win32API (windows.inc) compatibility by JohnK and fixed minor bug Version 1.0.1
'====================================================================================================================
$IFNDEF __QDF_INC
$DEFINE __QDF_INC


CONST sc_rsize=&hF002
CONST sc_lsize=&hF001
CONST sc_usize=&hF003
CONST sc_ulsize=&hF004
CONST sc_ursize=&hF005
CONST sc_dsize=&hF006
CONST sc_dlsize=&hF007
CONST sc_drsize=&hF008

'DECLARE SUB QDF_OnPaint_EventTemplate
DECLARE SUB OnPaint_eventTemplate
DECLARE SUB OnDock_eventTemplate(Docked AS INTEGER, Alt AS INTEGER)
DECLARE SUB OnClose_eventTemplate


TYPE QDFPANEL EXTENDS QPANEL
  'Disable old methods / functions by overriding them and making them private
  Private:
    Alignment AS BYTE
    BevelInner AS BYTE
    BevelOuter AS BYTE
    BevelWidth AS BYTE
    BorderStyle AS BYTE
    Caption AS BYTE
    ClientHeight AS BYTE
    ClientWidth AS BYTE
    Color AS BYTE
    Cursor AS BYTE
    Hint AS BYTE
    ShowHint AS BYTE
    Visible AS BYTE
END TYPE

TYPE QDOCKFORM EXTENDS QPANEL
  'Disable old methods / functions by overriding them and making them private
  Private:
    Left AS BYTE
    Top AS BYTe
    Alignment AS BYTE
    BevelInner AS BYTE
    BevelOuter AS BYTE
    BevelWidth AS BYTE
    BorderStyle AS BYTE
    'Caption AS BYTE ... see below
    ClientHeight AS BYTE
    ClientWidth AS BYTE
    Color AS BYTE
    Cursor AS BYTE
    Hint AS BYTE
    ShowHint AS BYTE
    'Visible AS BYTE ... See below
    
  ' Newly defined...
  Private:
    MouseDown AS INTEGER
    PrevX AS INTEGER
    PrevY AS INTEGER
    TempPoint AS POINTAPI
    TempPoint2 AS POINTAPI
    TempWidth AS INTEGER
    TempMovedOnce AS INTEGER
    ByProg AS INTEGER
    TempImg AS QIMAGE
    TempHandle AS LONG
    TempRect AS QRECT
    AltPanel AS QDFPANEL
    CloseButton AS QCANVAS
    'Visible AS BYTE 'PROPERTY SET SetVisible
    CaptureHandle AS LONG
    
  Public:
    TitleColor AS LONG
    ST1_TitleBackground AS LONG
    DragCursor AS INTEGER
    AltAlign AS INTEGER
    Sizeable AS INTEGER
    Style AS INTEGER
    
    UndockedHeight AS INTEGER
    UndockedWidth AS INTEGER
    Caption AS STRING PROPERTY SET SetCaption
    Docked AS INTEGER PROPERTY SET DummyINT
    UndockedForm AS QFORM
    Panel AS QDFPANEL
    Canvas AS QCANVAS
    Client AS QPANEL
    DockStyle AS INTEGER
    UnDockStyle AS INTEGER
    Locked AS INTEGER PROPERTY SET SetLock
    CanClose AS INTEGER PROPERTY SET SetClose
    Closed AS INTEGER PROPERTY SET DummyINT
    AltDock AS INTEGER PROPERTY SET DummyINT
    
    OnDock AS EVENT(OnDock_eventTemplate)
    OnPaint AS EVENT(OnPaint_eventTemplate)
    OnClose AS EVENT(OnClose_eventTemplate)
    
    PROPERTY SET SetClose (action AS INTEGER)
        IF action > 0 THEN
            THIS.CanClose = 1
            THIS.CloseButton.Visible = 1
        ELSE
            THIS.CanClose = 0
            THIS.CloseButton.Visible = 0
        END IF
    END PROPERTY
    
    PROPERTY SET SetLock (lock AS INTEGER)
        IF lock > 0 THEN
            THIS.Locked = 1
            THIS.Canvas.Repaint
        ELSE
            THIS.Locked = 0
            THIS.Canvas.Repaint
        END IF
    END PROPERTY
    
    SUB Dock (Dock AS INTEGER) : WITH THIS
        IF .Style > 0 AND Dock = 2 THEN
            .Docked = 1
            .AltPanel.Visible = 1
            .Visible = 0
            .Panel.Parent = .AltPanel
            .ByProg = 1
            IF .Closed = 0 THEN
                .AltDock = 1
            ELSE
                .Closed = 0
            END IF
            .UndockedForm.Close
        ELSEIF Dock = 1 OR (.Style = 0 AND Dock = 2) THEN
            .Docked = 1
            .AltPanel.Visible = 0
            .Visible = 1
            .Panel.Parent = THIS
            .ByProg = 1
            IF .Closed = 0 THEN
                .AltDock = 0
            ELSE
                .Closed = 0
            END IF
            .UndockedForm.Close
        ELSE
            .Visible = 0
            .AltPanel.Visible = 0
            .UndockedForm.Width = .UndockedWidth
            .UndockedForm.Height = .UndockedHeight
            .UndockedForm.Left = (Screen.Width - .UndockedForm.Width)/ 2
            .UndockedForm.Top = (Screen.Height - .UndockedForm.Height)/ 2
            'Center loses the parent - which is annoying to get back again!
            .UndockedForm.Show
            .Panel.Parent = .UndockedForm
            IF .Closed = 0 THEN
                .AltDock = 0
            ELSE
                .Closed = 0
            END IF
            .Docked = 0
        END IF
    END WITH : END SUB
      
    PROPERTY SET DummyINT (dummy AS INTEGER)
        'READ ONLY
    END PROPERTY
    
    PROPERTY SET SetCaption (caption AS STRING)
        THIS.Caption = caption
        THIS.UndockedForm.Caption = Caption 
    END PROPERTY
    
    EVENT CloseButton.OnMouseDown : WITH THIS
        IF IIF(.Docked,.DockStyle,.UndockStyle) <> 10 THEN
            .CloseButton.Left = .Canvas.Width - 16 - 6
            .CloseButton.Top = 7
            .CloseButton.Width = 16
            .CloseButton.Height = 14
                
            .CloseButton.FillRect(0,0,16,16,-2147483633)
            .CloseButton.Rectangle(0,0,16,16,0)
            .CloseButton.Rectangle(1,1,15,15,-2147483632)
            
            .TempRect.left = 0
            .TempRect.top = 0
            .TempRect.right = .CloseButton.Width
            .TempRect.bottom = .CloseButton.Height
            DrawFrameControl(.CloseButton.Handle, THIS.TempRect,1, &H4000 OR 512)
        ELSE
            .CloseButton.Left = .Canvas.Width - 16 - 6
            .CloseButton.Top = 7
            .CloseButton.Width = 16
            .CloseButton.Height = 14
                
            .CloseButton.FillRect(0,0,16,16,-2147483633)
            .TempRect.left = 0
            .TempRect.top = 0
            .TempRect.right = .CloseButton.Width
            .TempRect.bottom = .CloseButton.Height

            DrawFrameControl(.CloseButton.Handle, THIS.TempRect,1, 512)
        END IF
    END WITH : END EVENT
    
    EVENT CloseButton.OnMouseUp : WITH THIS
        .CloseButton.Repaint
    END WITH : END EVENT
    
    EVENT CloseButton.OnClick : WITH THIS
        .Closed = 1
        IF .Docked = 0 OR .AltDock = 1 THEN
            .Dock(1)
        END IF
        .Visible = 0
        IF .OnClose <> 0 THEN CALLFUNC .OnClose
    END WITH : END EVENT
    
    SUB Close : WITH THIS
        .Closed = 1
        IF .Docked = 0 OR .AltDock = 1 THEN
            .Dock(1)
        END IF
        .Visible = 0
        IF .OnClose <> 0 THEN CALLFUNC .OnClose
    END WITH : END SUB
    
    EVENT Canvas.OnPaint
		DIM I AS INTEGER
		WITH THIS
        IF Super.BevelOuter <> 0 THEN Super.BevelOuter = 0
        IF .Docked = 1 THEN
            
            SELECT CASE .DockStyle
            CASE 0
                .Client.Align = 0
                .Client.Top = 25
                .Client.Left = 5
                .Client.Width = .Panel.Width - 10
                .Client.Height = .Panel.Height - 30

                .Canvas.Rectangle(2,2,.Canvas.Width - 2, .Canvas.Height - 2, -2147483632)
                .Canvas.Font.AddStyles(0)
                .Canvas.Line(3,12,.Canvas.Width - 4, 12, -2147483632)
                .Canvas.Line(3,14,.Canvas.Width - 4, 14, -2147483632)
                .Canvas.Line(3,16,.Canvas.Width - 4, 16, -2147483632)
                .Canvas.FillRect((.Canvas.Width - .Canvas.TextWidth(.Caption)) / 2 - 5,12, (.Canvas.Width - .Canvas.TextWidth(.Caption)) / 2 + .Canvas.TextWidth(.Caption) + 5, 17, -2147483633)
                .Canvas.TextOut((.Canvas.Width - .Canvas.TextWidth(.Caption)) / 2,5 + (18 - .Canvas.TextHeight(.Caption)) / 2,.Caption, .TitleColor, -1)
                
                IF .CanClose = 0 THEN
                    .CloseButton.Width = 0
                    .CloseButton.Height = 0
                ELSE
                    .Canvas.FillRect(.Canvas.Width - 16 - 10, 12, .Canvas.Width - 16 - 10 + 23, .Canvas.Width - 16 - 10 + 16, -2147483633)
                    .CloseButton.Left = .Canvas.Width - 16 - 6
                    .CloseButton.Top = 7
                    .CloseButton.Width = 16
                    .CloseButton.Height = 14
                
                    .TempRect.left = 0
                    .TempRect.top = 0
                    .TempRect.right = .CloseButton.Width
                    .TempRect.bottom = .CloseButton.Height
                    DrawFrameControl(.CloseButton.Handle, THIS.TempRect,1, &H4000)
                END IF
            CASE 1
                .Client.Align = 0
                .Client.Top = 25
                .Client.Left = 5
                .Client.Width = .Panel.Width - 10
                .Client.Height = .Panel.Height - 30
                
                .Canvas.Rectangle(2,2,.Canvas.Width - 2, .Canvas.Height - 2, -2147483632)
                .Canvas.Font.AddStyles(0)
                
                IF .Locked = 0 THEN
                    .Canvas.FillRect(5,5,.Canvas.Width - 5, 23, .ST1_TitleBackground)
                END IF
                .Canvas.TextOut(7,5 + (18 - .Canvas.TextHeight(.Caption)) / 2,.Caption, .TitleColor, -1)
                
                
                
                IF .CanClose = 0 THEN
                    .CloseButton.Width = 0
                    .CloseButton.Height = 0
                ELSE
                    .CloseButton.Left = .Canvas.Width - 16 - 6
                    .CloseButton.Top = 7
                    .CloseButton.Width = 16
                    .CloseButton.Height = 14
                
                    .TempRect.left = 0
                    .TempRect.top = 0
                    .TempRect.right = .CloseButton.Width
                    .TempRect.bottom = .CloseButton.Height
                    DrawFrameControl(.CloseButton.Handle, THIS.TempRect,1, &H4000)
                END IF
            CASE 2
                .Client.Align = 0
                .Client.Top = 25
                .Client.Left = 5
                .Client.Width = .Panel.Width - 10
                .Client.Height = .Panel.Height - 30
                
                .Canvas.Rectangle(2,2,.Canvas.Width - 2, .Canvas.Height - 2, -2147483632)
                
                .Canvas.Font.AddStyles(0)
                .Canvas.TextOut(7,5 + (18 - .Canvas.TextHeight(.Caption)) / 2,.Caption, .TitleColor, -1)
                
                IF .Locked = 0 THEN
                    FOR I = 1 TO ((.Canvas.Width - .Canvas.TextWidth(.Caption) - 14) / 4)
                        .Canvas.Draw(7 + .Canvas.TextWidth(.Caption) + 4 * I, 10,.TempImg.BMP)
                    NEXT
                END IF
                
                IF .CanClose = 0 THEN
                    .CloseButton.Width = 0
                    .CloseButton.Height = 0
                ELSE
                    .Canvas.FillRect(.Canvas.Width - 16 - 10, 6, .Canvas.Width - 16 - 10 + 23, .Canvas.Width - 16 - 10 + 16, -2147483633)
                    .CloseButton.Left = .Canvas.Width - 16 - 6
                    .CloseButton.Top = 7
                    .CloseButton.Width = 16
                    .CloseButton.Height = 14
                
                    .TempRect.left = 0
                    .TempRect.top = 0
                    .TempRect.right = .CloseButton.Width
                    .TempRect.bottom = .CloseButton.Height
                    DrawFrameControl(.CloseButton.Handle, THIS.TempRect,1, &H4000)
                END IF
            CASE 3
                .Client.Align = 0
                .Client.Top = 3
                .Client.Left = IIF(.Locked,3,15)
                .Client.Width = .Panel.Width - IIF(.Locked,4,16)
                .Client.Height = .Panel.Height - 6
                .Client.BevelOuter = 0
                .Canvas.Line(0,0,.Canvas.Width,0, -2147483632)
                .Canvas.Line(0,.Canvas.Height - 1,.Canvas.Width,.Canvas.Height - 1, -2147483634)
                .Canvas.Font.AddStyles(0)
                
                IF .Locked = 0 THEN
                    .Canvas.Line(5,3,5,.Canvas.Height - 3, -2147483632)
                    .Canvas.Line(7,3,7,.Canvas.Height - 3, -2147483632)
                    .Canvas.Line(9,3,9,.Canvas.Height - 3, -2147483632)
                END IF
            CASE 4
                .Client.Align = 0
                .Client.Top = 3
                .Client.Left = IIF(.Locked,3,15)
                .Client.Width = .Panel.Width - IIF(.Locked,4,16)
                .Client.Height = .Panel.Height - 6
                .Client.BevelOuter = 0
                .Canvas.Line(0,0,.Canvas.Width,0, -2147483632)
                .Canvas.Line(0,.Canvas.Height - 1,.Canvas.Width,.Canvas.Height - 1, -2147483634)
                .Canvas.Font.AddStyles(0)
                IF .Locked = 0 THEN
                    FOR I = 0 TO ((.Canvas.Height - 8)/ 12)
                        .Canvas.Draw(5, I * 12 + 4,.TempImg.BMP)
                    NEXT
                END IF
            CASE 5
                
                .Client.Align = 0
                .Client.Top = 3
                .Client.Left = IIF(.Locked,3,15)
                .Client.Width = .Panel.Width - IIF(.Locked,4,17)
                .Client.Height = .Panel.Height - 6
                .Client.BevelOuter = 0
                
                .Canvas.Line(0,0,.Canvas.Width,0, -2147483628)
                .Canvas.Line(0,0,0,.Canvas.Height, -2147483628)
                .Canvas.Line(0,.Canvas.Height - 1,.Canvas.Width,.Canvas.Height - 1, -2147483632)
                .Canvas.Line(.Canvas.Width - 1,0,.Canvas.Width - 1,.Canvas.Height, -2147483632)
                
                .Canvas.Font.AddStyles(0)
                
                IF .Locked = 0 THEN
                    .Canvas.Line(5,3,5,.Canvas.Height - 4, -2147483628)
                    .Canvas.Pset(6,3, -2147483628)
                    .Canvas.Line(7,3,7,.Canvas.Height - 4, -2147483632)
                    .Canvas.Pset(6,.Canvas.Height - 4, -2147483632)
                END IF
            CASE 6
                .Client.Align = 0
                .Client.Top = 3
                .Client.Left = IIF(.Locked,3,15)
                .Client.Width = .Panel.Width - IIF(.Locked,4,16)
                .Client.Height = .Panel.Height - 6
                .Client.BevelOuter = 0
                .Canvas.Line(0,0,.Canvas.Width,0, -2147483632)
                .Canvas.Line(0,.Canvas.Height - 1,.Canvas.Width,.Canvas.Height - 1, -2147483634)
                .Canvas.Font.AddStyles(0)
                IF .Locked = 0 THEN
                    FOR I = 0 TO ((.Canvas.Height - 8)/ 2)
                        .Canvas.Line(5, I * 2 + 4,8, I * 2 + 4, -2147483632)
                    NEXT
                END IF
            CASE 10
                .Client.Align = 0
                .Client.Top = 25
                .Client.Left = 5
                .Client.Width = .Panel.Width - 10
                .Client.Height = .Panel.Height - 30
                
                .Canvas.Rectangle(2,2,.Canvas.Width - 2, .Canvas.Height - 2, -2147483632)
                .Canvas.Font.AddStyles(0)
                
                .TempRect.left = 4
                .TempRect.top = 4
                .TempRect.right = .Canvas.Width - 4
                .TempRect.bottom = 24
                DrawCaption(.UndockedForm.Handle, .Canvas.Handle, THIS.TempRect, IIF(.Locked,&H8,&H8 OR &H1))
                
                IF .CanClose = 0 THEN
                    .CloseButton.Width = 0
                    .CloseButton.Height = 0
                ELSE
                    '.Canvas.FillRect(.Canvas.Width - 16 - 10, 6, .Canvas.Width - 16 - 10 + 23, .Canvas.Width - 16 - 10 + 16, -2147483633)
                    .CloseButton.Left = .Canvas.Width - 16 - 6
                    .CloseButton.Top = 7
                    .CloseButton.Width = 16
                    .CloseButton.Height = 14
                
                    .TempRect.left = 0
                    .TempRect.top = 0
                    .TempRect.right = .CloseButton.Width
                    .TempRect.bottom = .CloseButton.Height
                    DrawFrameControl(.CloseButton.Handle, THIS.TempRect,&H1, &H0)
                END IF
            CASE ELSE
                .Client.Align = 0
                .Client.Top = 25
                .Client.Left = 5
                .Client.Width = .Panel.Width - 10
                .Client.Height = .Panel.Height - 30

                .Canvas.Rectangle(2,2,.Canvas.Width - 2, .Canvas.Height - 2, -2147483632)
                .Canvas.Font.AddStyles(0)
                .Canvas.Line(3,12,.Canvas.Width - 4, 12, -2147483632)
                .Canvas.Line(3,14,.Canvas.Width - 4, 14, -2147483632)
                .Canvas.Line(3,16,.Canvas.Width - 4, 16, -2147483632)
                .Canvas.FillRect((.Canvas.Width - .Canvas.TextWidth(.Caption)) / 2 - 5,12, (.Canvas.Width - .Canvas.TextWidth(.Caption)) / 2 + .Canvas.TextWidth(.Caption) + 5, 17, -2147483633)
                .Canvas.TextOut((.Canvas.Width - .Canvas.TextWidth(.Caption)) / 2,5 + (18 - .Canvas.TextHeight(.Caption)) / 2,.Caption, .TitleColor, -1)
            END SELECT
        ELSE
            SELECT CASE .UnDockStyle
            CASE 0
                .Client.Align = 0
                .Client.Top = 25
                .Client.Left = 5
                .Client.Width = .Panel.Width - 10
                .Client.Height = .Panel.Height - 30

                .Canvas.Rectangle(0,0,.Canvas.Width, .Canvas.Height, -2147483632)
                '.Canvas.Rectangle(1,1,.Canvas.Width - 1, .Canvas.Height - 1, -2147483632)
                .Canvas.Rectangle(2,2,.Canvas.Width - 2, .Canvas.Height - 2, -2147483632)
                
                .Canvas.Font.AddStyles(0)
                .Canvas.Line(3,12,.Canvas.Width - 4, 12, -2147483632)
                .Canvas.Line(3,14,.Canvas.Width - 4, 14, -2147483632)
                .Canvas.Line(3,16,.Canvas.Width - 4, 16, -2147483632)
                .Canvas.FillRect((.Canvas.Width - .Canvas.TextWidth(.Caption)) / 2 - 5,12, (.Canvas.Width - .Canvas.TextWidth(.Caption)) / 2 + .Canvas.TextWidth(.Caption) + 5, 17, -2147483633)
                .Canvas.TextOut((.Canvas.Width - .Canvas.TextWidth(.Caption)) / 2,5 + (18 - .Canvas.TextHeight(.Caption)) / 2,.Caption, .TitleColor, -1)
                
                IF .CanClose = 0 THEN
                    .CloseButton.Width = 0
                    .CloseButton.Height = 0
                ELSE
                    .Canvas.FillRect(.Canvas.Width - 16 - 10, 12, .Canvas.Width - 16 - 10 + 23, .Canvas.Width - 16 - 10 + 16, -2147483633)
                    .CloseButton.Left = .Canvas.Width - 16 - 6
                    .CloseButton.Top = 7
                    .CloseButton.Width = 16
                    .CloseButton.Height = 14
                
                    .TempRect.left = 0
                    .TempRect.top = 0
                    .TempRect.right = .CloseButton.Width
                    .TempRect.bottom = .CloseButton.Height
                    DrawFrameControl(.CloseButton.Handle, THIS.TempRect,1, &H4000)
                END IF
            CASE 1
                .Client.Align = 0
                .Client.Top = 25
                .Client.Left = 5
                .Client.Width = .Panel.Width - 10
                .Client.Height = .Panel.Height - 30
                
                .Canvas.Rectangle(0,0,.Canvas.Width, .Canvas.Height, -2147483632)
                .Canvas.Rectangle(1,1,.Canvas.Width - 1, .Canvas.Height - 1, -2147483632)
                .Canvas.Rectangle(2,2,.Canvas.Width - 2, .Canvas.Height - 2, -2147483632)
                .Canvas.Font.AddStyles(0)
                
                .Canvas.FillRect(5,5,.Canvas.Width - 5, 23, .ST1_TitleBackground)
                .Canvas.TextOut(7,5 + (18 - .Canvas.TextHeight(.Caption)) / 2,.Caption, .TitleColor, -1)
                
                IF .CanClose = 0 THEN
                    .CloseButton.Width = 0
                    .CloseButton.Height = 0
                ELSE
                    .CloseButton.Left = .Canvas.Width - 16 - 6
                    .CloseButton.Top = 7
                    .CloseButton.Width = 16
                    .CloseButton.Height = 14
                    
                    .TempRect.left = 0
                    .TempRect.top = 0
                    .TempRect.right = .CloseButton.Width
                    .TempRect.bottom = .CloseButton.Height
                    DrawFrameControl(.CloseButton.Handle, THIS.TempRect,1, &H4000)
                END IF
            CASE 2
                .Client.Align = 0
                .Client.Top = 25
                .Client.Left = 5
                .Client.Width = .Panel.Width - 10
                .Client.Height = .Panel.Height - 30
                
                .Canvas.Rectangle(0,0,.Canvas.Width, .Canvas.Height, -2147483632)
                ''.Canvas.Rectangle(1,1,.Canvas.Width - 1, .Canvas.Height - 1, -2147483632)
                ''.Canvas.Rectangle(2,2,.Canvas.Width - 2, .Canvas.Height - 2, -2147483632)
                
                .Canvas.Font.AddStyles(0)
                .Canvas.TextOut(7,5 + (18 - .Canvas.TextHeight(.Caption)) / 2,.Caption, .TitleColor, -1)
                FOR I = 1 TO (.Canvas.Width - .Canvas.TextWidth(.Caption) - 14) / 4
                    .Canvas.Draw(7 + .Canvas.TextWidth(.Caption) + 4 * I, 10,.TempImg.BMP)
                NEXT
                
                IF .CanClose = 0 THEN
                    .CloseButton.Width = 0
                    .CloseButton.Height = 0
                ELSE
                    .Canvas.FillRect(.Canvas.Width - 16 - 10, 6, .Canvas.Width - 16 - 10 + 23, .Canvas.Width - 16 - 10 + 16, -2147483633)
                    .CloseButton.Left = .Canvas.Width - 16 - 6
                    .CloseButton.Top = 7
                    .CloseButton.Width = 16
                    .CloseButton.Height = 14
                    
                    .TempRect.left = 0
                    .TempRect.top = 0
                    .TempRect.right = .CloseButton.Width
                    .TempRect.bottom = .CloseButton.Height
                    DrawFrameControl(.CloseButton.Handle, THIS.TempRect,1, &H4000)
                END IF
            CASE 3
                .Client.Align = 0
                .Client.Top = 3
                .Client.Left = 15
                .Client.Width = .Panel.Width - 20
                .Client.Height = .Panel.Height - 6
                
                '.Canvas.Rectangle(0,0,.Canvas.Width, .Canvas.Height, -2147483632)
                ''.Canvas.Rectangle(1,1,.Canvas.Width - 1, .Canvas.Height - 1, -2147483632)
                '.Canvas.Rectangle(2,2,.Canvas.Width - 2, .Canvas.Height - 2, -2147483632)
                
                .TempRect.left = 0
                .TempRect.top = 0
                .TempRect.right = .Canvas.Width
                .TempRect.bottom = .Canvas.Height
                DrawEdge(.Canvas.Handle, THIS.TempRect, &H1 OR &H8, &H1 OR &H2 OR &H4 OR &H8 OR &H8000)
                
                .Canvas.Font.AddStyles(0)
                .Canvas.Line(5,3,5,.Canvas.Height - 3, -2147483632)
                .Canvas.Line(7,3,7,.Canvas.Height - 3, -2147483632)
                .Canvas.Line(9,3,9,.Canvas.Height - 3, -2147483632)
            CASE 4
                .Client.Align = 0
                .Client.Top = 3
                .Client.Left = 15
                .Client.Width = .Panel.Width - 20
                .Client.Height = .Panel.Height - 6
                .Client.BevelOuter = 0
                .Canvas.Rectangle(0,0,.Canvas.Width, .Canvas.Height, -2147483632)
                .Canvas.Rectangle(1,1,.Canvas.Width - 1, .Canvas.Height - 1, -2147483632)
                .Canvas.Font.AddStyles(0)

                .Canvas.Draw(5, (.Canvas.Height - (.TempImg.Height * 2)) / 2,.TempImg.BMP)
                .Canvas.Draw(5, (.Canvas.Height - (.TempImg.Height * 2 )) / 2 + 12,.TempImg.BMP)
                
                FOR I = 0 TO ((.Canvas.Height - 8)/ 12)
                    .Canvas.Draw(5, I * 12 + 4,.TempImg.BMP)
                NEXT
            CASE 5
            
                
                .Client.Align = 0
                .Client.Top = 3
                .Client.Left = 14
                .Client.Width = .Panel.Width - 17
                .Client.Height = .Panel.Height - 6
                
                '.Canvas.Rectangle(0,0,.Canvas.Width, .Canvas.Height, -2147483632)
                '.Canvas.Rectangle(1,1,.Canvas.Width - 1, .Canvas.Height - 1, -2147483632)
                '.Canvas.Rectangle(2,2,.Canvas.Width - 2, .Canvas.Height - 2, -2147483632)
                
                .TempRect.left = 0
                .TempRect.top = 0
                .TempRect.right = .Canvas.Width
                .TempRect.bottom = .Canvas.Height
                DrawEdge(.Canvas.Handle, THIS.TempRect, &H1 OR &H5, &H1 OR &H2 OR &H4 OR &H8)
                
                .Canvas.Font.AddStyles(0)
                
                .Canvas.Line(5,4,5,.Canvas.Height - 5, -2147483628)
                .Canvas.Pset(6,4, -2147483628)
                .Canvas.Line(7,4,7,.Canvas.Height - 5, -2147483632)
                .Canvas.Pset(6,.Canvas.Height - 5, -2147483632)
            CASE 6
                .UndockStyle = 1
                .Canvas.Repaint
            CASE 10
                .TempRect.left = 0
                .TempRect.top = 0
                .TempRect.right = .Canvas.Width
                .TempRect.bottom = .Canvas.Height
                DrawEdge(.Canvas.Handle, THIS.TempRect, &H1 OR &H5, &H1 OR &H2 OR &H4 OR &H8)
                
                .Client.Align = 0
                .Client.Top = 25
                .Client.Left = 5
                .Client.Width = .Panel.Width - 10
                .Client.Height = .Panel.Height - 30

                .Canvas.Font.AddStyles(0)
                
                .TempRect.left = 4
                .TempRect.top = 4
                .TempRect.right = .Canvas.Width - 5
                .TempRect.bottom = 24
                DrawCaption(.UndockedForm.Handle, .Canvas.Handle, THIS.TempRect, &H1 OR &H8)
                
                IF .CanClose = 0 THEN
                    .CloseButton.Width = 0
                    .CloseButton.Height = 0
                ELSE
                    '.Canvas.FillRect(.Canvas.Width - 16 - 10, 6, .Canvas.Width - 16 - 10 + 23, .Canvas.Width - 16 - 10 + 16, -2147483633)
                    .CloseButton.Left = .Canvas.Width - 16 - 6
                    .CloseButton.Top = 7
                    .CloseButton.Width = 16
                    .CloseButton.Height = 14
                
                    .CloseButton.FillRect(0,0,16,16,-2147483633)
                    '.CloseButton.Rectangle(0,0,16,16,0)
                    .TempRect.left = 0
                    .TempRect.top = 0
                    .TempRect.right = .CloseButton.Width
                    .TempRect.bottom = .CloseButton.Height
                    DrawFrameControl(.CloseButton.Handle, THIS.TempRect,1, 0)
                END IF
                '.Canvas.FillRect(4,4,.Canvas.Width - 5, 24, -2147483646)
                '.Canvas.TextOut(7,5 + (18 - .Canvas.TextHeight(.Caption)) / 2,.Caption, -2147483639, -1)
            END SELECT
        END IF
        IF .OnPaint <> 0 THEN CALLFUNC .OnPaint
    END WITH : END EVENT
    
    EVENT UndockedForm.OnShow : WITH THIS
    
    END WITH : END EVENT
    
    EVENT UndockedForm.OnClose (Action AS INTEGER) : WITH THIS
        IF .ByProg = 0 AND .CanClose = 0 THEN
            Action = 0
        ELSE
            IF .CanClose = 1 AND .ByProg = 0 THEN
                IF .OnClose <> 0 AND .Closed = 0 THEN CALLFUNC .OnClose
                .Closed = 1
            END IF
            .ByProg = 0
           ' Action = 0
            '.UndockedForm.Width = 0
            '.UndockedForm.Height = 0
            '.UndockedForm.Left = 0
            '.UndockedForm.Top = 0
        END IF
        'ShowWindow(GetParent(.Handle),1)
        
    END WITH : END EVENT
    
    EVENT Canvas.OnMouseDown (BTN AS INTEGER, X AS INTEGER, Y AS INTEGER): WITH THIS
        IF BTN = 1 THEN EXIT EVENT
        IF .Docked = 0 AND .Sizeable = 1 THEN
            IF X > -1 AND X < 4 AND Y > - 1 AND Y < 4 THEN
                ReleaseCapture
                SendMessage(.UndockedForm.Handle, wm_syscommand, sc_ulsize, 0)
                .UndockedWidth = .UndockedForm.Width
                .UndockedHeight = .UndockedForm.Height
            ELSEIF X > -1 AND X < 4 AND Y > 3 AND Y < .Canvas.Height - 4 THEN
                ReleaseCapture
                SendMessage(.UndockedForm.Handle, wm_syscommand, sc_lsize, 0)
                .UndockedWidth = .UndockedForm.Width
                .UndockedHeight = .UndockedForm.Height
            ELSEIF X > -1 AND X < 4 AND Y > .Canvas.Height - 5 AND Y < .Canvas.Height THEN
                ReleaseCapture
                SendMessage(.UndockedForm.Handle, wm_syscommand, sc_dlsize, 0)
                .UndockedWidth = .UndockedForm.Width
                .UndockedHeight = .UndockedForm.Height
            ELSEIF X > 3 AND X < .Canvas.Width - 4 AND Y > - 1 AND Y < 4 THEN
                ReleaseCapture
                SendMessage(.UndockedForm.Handle, wm_syscommand, sc_usize, 0)
                .UndockedWidth = .UndockedForm.Width
                .UndockedHeight = .UndockedForm.Height
            ELSEIF X > .Canvas.Width - 5 AND X < .Canvas.Width AND Y > - 1 AND Y < 4 THEN
                ReleaseCapture
                SendMessage(.UndockedForm.Handle, wm_syscommand, sc_ursize, 0)
                .UndockedWidth = .UndockedForm.Width
                .UndockedHeight = .UndockedForm.Height
            ELSEIF X > .Canvas.Width - 5 AND X < .Canvas.Width AND Y > 3 AND Y < .Canvas.Height - 4 THEN
                ReleaseCapture
                SendMessage(.UndockedForm.Handle, wm_syscommand, sc_rsize, 0)
                .UndockedWidth = .UndockedForm.Width
                .UndockedHeight = .UndockedForm.Height
            ELSEIF X > .Canvas.Width - 5 AND X < .Canvas.Width AND Y > .Canvas.Height - 5 AND Y < .Canvas.Height THEN
                ReleaseCapture
                SendMessage(.UndockedForm.Handle, wm_syscommand, sc_drsize, 0)
                .UndockedWidth = .UndockedForm.Width
                .UndockedHeight = .UndockedForm.Height
            ELSEIF X > 3 AND X < .Canvas.Width - 4 AND Y > .Canvas.Height - 5 AND Y < .Canvas.Height THEN
                ReleaseCapture
                SendMessage(.UndockedForm.Handle, wm_syscommand, sc_dsize, 0)
                .UndockedWidth = .UndockedForm.Width
                .UndockedHeight = .UndockedForm.Height
            END IF
        END IF
        IF IIF(.Docked > 0,.DockStyle,.UnDockStyle) < 3 OR IIF(.Docked > 0,.DockStyle,.UnDockStyle) > 9 THEN
            IF X > 4 AND X < .Canvas.Width - 4 AND Y > 3 AND Y < 24 AND .Locked = 0 THEN
                .MouseDown = 1
                .PrevX = X
                .PrevY = Y
                .CaptureHandle = GetCapture
            END IF
        ELSE
            IF X > 4 AND X < 15 AND Y > 3 AND Y < .Canvas.Height - 1 AND .Locked = 0 THEN
                .MouseDown = 1
                .PrevX = X
                .PrevY = Y
                .CaptureHandle = GetCapture
            END IF
        END IF
    END WITH : END EVENT
    
    EVENT Canvas.OnMouseUp (BTN AS INTEGER, X AS INTEGER, Y AS INTEGER): WITH THIS
        '.Sizing = 0
        IF btn = 0 THEN
            .MouseDown = 0
            .TempMovedOnce = 0
        END IF
    END WITH : END EVENT
    
    EVENT Canvas.OnMouseMove (X AS INTEGER, Y AS INTEGER): WITH THIS
        IF .MouseDown = 0 THEN 
            IF IIF(.Docked > 0,.DockStyle,.UnDockStyle) < 3 OR IIF(.Docked > 0,.DockStyle,.UnDockStyle) > 9 THEN
                IF X > 4 AND X < .Canvas.Width - 4 AND Y > 3 AND Y < 24 AND .Locked = 0 THEN
                    .Canvas.Cursor = .DragCursor
                ELSE
                    .Canvas.Cursor = 0
                END IF
            ELSE
                IF X > 4 AND X < 15 AND Y > 3 AND Y < .Canvas.Height - 1 AND .Locked = 0 THEN
                    .Canvas.Cursor = .DragCursor
                ELSE
                    .Canvas.Cursor = 0
                END IF
            END IF
            
            IF .Docked = 0 AND .Sizeable = 1 THEN
                IF X > -1 AND X < 4 AND Y > - 1 AND Y < 4 THEN
                    .Canvas.Cursor = -8
                ELSEIF X > -1 AND X < 4 AND Y > 3 AND Y < .Canvas.Height - 4 THEN
                    .Canvas.Cursor = -9
                ELSEIF X > -1 AND X < 4 AND Y > .Canvas.Height - 5 AND Y < .Canvas.Height THEN
                    .Canvas.Cursor = -6
                ELSEIF X > 3 AND X < .Canvas.Width - 4 AND Y > - 1 AND Y < 4 THEN
                    .Canvas.Cursor = -7
                ELSEIF X > .Canvas.Width - 5 AND X < .Canvas.Width AND Y > - 1 AND Y < 4 THEN
                    .Canvas.Cursor = -6
                ELSEIF X > .Canvas.Width - 5 AND X < .Canvas.Width AND Y > 3 AND Y < .Canvas.Height - 4 THEN
                    .Canvas.Cursor = -9
                ELSEIF X > .Canvas.Width - 5 AND X < .Canvas.Width AND Y > .Canvas.Height - 5 AND Y < .Canvas.Height THEN
                    .Canvas.Cursor = -8
                ELSEIF X > 3 AND X < .Canvas.Width - 4 AND Y > .Canvas.Height - 5 AND Y < .Canvas.Height THEN
                    .Canvas.Cursor = -7
                END IF
            END IF
        ELSE
            .TempPoint.X = 0
            .TempPoint.Y = 0
            ClientToScreen(.Handle, .TempPoint)
            .TempPoint2.X = 0
            .TempPoint2.Y = 0
            ClientToScreen(.AltPanel.Handle, .TempPoint2)
            IF (Screen.MouseX - .PrevX > .TempPoint.X + 30 OR Screen.MouseY - .PrevY > .TempPoint.Y + 30 OR Screen.MouseX - .PrevX < .TempPoint.X - 30 OR Screen.MouseY - .PrevY < .TempPoint.Y - 30) _
            AND (.Style <> 1 OR (.Style = 1 AND (Screen.MouseX - .PrevX > .TempPoint2.X + 30 OR Screen.MouseY - .PrevY > .TempPoint2.Y + 30 OR Screen.MouseX - .PrevX < .TempPoint2.X - 30 OR Screen.MouseY - .PrevY < .TempPoint2.Y - 30))) THEN
                
                .UndockedForm.Left = Screen.MouseX - .PrevX
                .UndockedForm.Top = Screen.MouseY - .PrevY
                .UndockedForm.Width = .UndockedWidth
                .UndockedForm.Height = .UndockedHeight
                'SetWindowLong(.Panel.Handle, (-16), GetWindowLong(.UndockedForm.Handle, (-16)))
                
                IF .TempMovedOnce = 0 AND .Align = 4 THEN 
                    .TempWidth = .Width
                    .Width = 0
                    .Visible = 1
                    .Visible = 0
                    .Width = .TempWidth
                    Super.Left = Super.Left - .Width
                    .TempMovedOnce = 1
                    
                    IF .AltAlign = 0 THEN
                    .AltPanel.Align = 3
                    .AltPanel.Width = 0
                    .AltPanel.Visible = 1
                    .AltPanel.Visible = 0
                    .AltPanel.Width = .TempWidth
                    END IF
                ELSEIF .TempMovedOnce = 0 AND .Align = 3 THEN
                    .TempWidth = .Width
                    .Width = 0
                    .Visible = 1
                    .Visible = 0
                    .Width = .TempWidth
                    .TempMovedOnce = 1
                    
                    IF .AltAlign = 0 THEN
                    .AltPanel.Align = 4
                    .AltPanel.Width = 0
                    .AltPanel.Visible = 1
                    .AltPanel.Visible = 0
                    .AltPanel.Width = .TempWidth
                    .AltPanel.Left = .AltPanel.Left - .Width
                    END IF
                ELSEIF .TempMovedOnce = 0 AND .Align = 1 THEN
                    .TempWidth = .Height
                    .Height = 0
                    .Visible = 1
                    .Visible = 0
                    .Height = .TempWidth
                    .TempMovedOnce = 1
                    
                    IF .AltAlign = 0 THEN
                    .AltPanel.Align = 2
                    .AltPanel.Height = 0
                    .AltPanel.Visible = 1
                    .AltPanel.Visible = 0
                    .AltPanel.Height = .TempWidth
                    .AltPanel.Top = .AltPanel.Top - .Height
                    END IF
                ELSEIF .TempMovedOnce = 0 AND .Align = 2 THEN
                    .TempWidth = .Height
                    .Height = 0
                    .Visible = 1
                    .Visible = 0
                    .Height = .TempWidth
                    Super.Top = Super.Top - .Height
                    .TempMovedOnce = 1
                    
                    IF .AltAlign = 0 THEN
                    .AltPanel.Align = 1
                    .AltPanel.Height = 0
                    .AltPanel.Visible = 1
                    .AltPanel.Visible = 0
                    .AltPanel.Height = .TempWidth
                    END IF
                ELSEIF .TempMovedOnce = 0 AND .Align = 5 AND .AltAlign <> 0 THEN
                    .TempMovedOnce = 1
                    .AltPanel.Align = 1
                    .AltPanel.Height = 0
                    .AltPanel.Visible = 1
                    .AltPanel.Visible = 0
                    .AltPanel.Height = .TempWidth
                END IF
                
                IF .AltAlign <> 0 THEN
                    .AltPanel.Align = .AltAlign
                    IF .TempMovedOnce = 1 AND .AltPanel.Align = 4 THEN
                        .TempWidth = .Width
                        .AltPanel.Width = 0
                        .AltPanel.Visible = 1
                        .AltPanel.Visible = 0
                        .AltPanel.Width = .TempWidth
                        .AltPanel.Left = .AltPanel.Left - .Width
                        .TempMovedOnce = 2
                    END IF
                
                    IF .TempMovedOnce = 1 AND .AltPanel.Align = 3 THEN
                        .TempWidth = .Width
                        .AltPanel.Width = 0
                        .AltPanel.Visible = 1
                        .AltPanel.Visible = 0
                        .AltPanel.Width = .TempWidth
                        .TempMovedOnce = 2
                    END IF
                
                    IF .TempMovedOnce = 1 AND .AltPanel.Align = 1 THEN
                        .TempWidth = .Height
                        .AltPanel.Height = 0
                        .AltPanel.Visible = 1
                        .AltPanel.Visible = 0
                        .AltPanel.Height = .TempWidth
                        .TempMovedOnce = 2
                    END IF
                
                    IF .TempMovedOnce = 1 AND .AltPanel.Align = 2 THEN
                        .TempWidth = .Height
                        .AltPanel.Height = 0
                        .AltPanel.Visible = 1
                        .AltPanel.Visible = 0
                        .AltPanel.Height = .TempWidth
                        .AltPanel.Top = .AltPanel.Top - .Height
                        .TempMovedOnce = 2
                    END IF
                END IF
                IF .Docked = 1 THEN
                    .UndockedForm.Show
                    .Panel.Parent = .UndockedForm
                    ReleaseCapture
                    SetCapture (.Panel.Handle)
                    .Docked = 0
                    .AltDock = 0
                    IF .OnDock <> 0 THEN CALLFUNC (.OnDock, 0, 0)
                END IF
                .Visible = 0
                .AltPanel.Visible = 0
            END IF
            IF .Docked = 0 THEN
                .UndockedForm.Left = Screen.MouseX - .PrevX
                .UndockedForm.Top = Screen.MouseY - .PrevY
                
                IF .UndockedForm.Left > .TempPoint.x - 29 AND .UndockedForm.Left < .TempPoint.x + 29 AND .UndockedForm.Top > .TempPoint.y - 29 AND .UndockedForm.Top < .TempPoint.y + 29 THEN
                    .Docked = 1
                     'ShowWindow(.Handle, 1)
                    .Visible = 1
                    .Panel.Parent = THIS
                    'ReleaseCapture
                    SetCapture (.Panel.Handle)
                    .ByProg = 1
                    IF .OnDock <> 0 THEN CALLFUNC (.OnDock, 1, 0)
                    .AltDock = 0
                    .UndockedForm.Close
                END IF
                
                IF .Style = 1 THEN
                    .TempPoint.X = 0
                    .TempPoint.Y = 0
                    ClientToScreen(.AltPanel.Handle, .TempPoint)
                    IF .UndockedForm.Left > .TempPoint.x - 29 AND .UndockedForm.Left < .TempPoint.x + 29 AND .UndockedForm.Top > .TempPoint.y - 29 AND .UndockedForm.Top < .TempPoint.y + 29 THEN
                        .Docked = 1
                         'ShowWindow(.Handle, 1)
                        .AltPanel.Visible = 1
                        .Panel.Parent = .AltPanel
                        'ReleaseCapture
                        SetCapture (.Panel.Handle)
                        .ByProg = 1
                        IF .OnDock <> 0 THEN CALLFUNC (.OnDock, 1, 1)
                        .AltDock = 1
                        .UndockedForm.Close
                    END IF
                END IF
            END IF    
        END IF
    END WITH : END EVENT
    
    
    
    CONSTRUCTOR
        
        UndockedHeight = 400
        UndockedWidth = 170
        
        Docked = 1
        Canvas.Align = 5
        Canvas.Parent = THIS.Panel
        BevelOuter = 0
        Panel.BevelOuter = 0
        Panel.Align = 5
        Align = 3
        AltPanel.Align = 4
        AltPanel.Visible = 0
        AltPanel.BevelOuter = 0
        AltPanel.Parent = THIS
        
        UndockedForm.BorderStyle = 0
        
        Client.Parent = THIS.Panel
        Client.Top = 25
        Client.Left = 5
        Client.Width = THIS.Panel.Width - 10
        Client.Height = THIS.Panel.Height - 30
        Client.BevelOuter = 2
        Panel.Parent = THIS
        CloseButton.Parent = THIS.Panel
        CloseButton.Width = 0
        CloseButton.Height = 0
        
        'MinWidth = 170
        'MinHeight = 250

        TempImg.FillRect(0,0,THIS.TempImg.Width, THIS.TempImg.Height, -2147483633)
        TempImg.FillRect(1,1,3,3,-2147483628)
        TempImg.FillRect(1,5,3,7,-2147483628)
        TempImg.FillRect(1,9,3,11,-2147483628)
        
        TempImg.FillRect(0,0,2,2,-2147483632)
        TempImg.FillRect(0,4,2,6,-2147483632)
        TempImg.FillRect(0,8,2,10,-2147483632)
        TempImg.Transparent = 1
        TempImg.Width = 3
        TempImg.Height = 11
        DragCursor = -21
        
        ST1_TitleBackground = -2147483632
        TitleColor = 0
        
    END CONSTRUCTOR
END TYPE

$ENDIF  '__QDF_INC







''====================================================================================================================
' --- QBITMAP extension 
' Class QBitmapEx Version 1.6 3/2005,  added alphablend and bitmap functions
'====================================================================================================================


'For AlphaBlend
DECLARE SUB BFMoveMemory Lib "kernel32.dll" Alias "RtlMoveMemory" (byref Destination AS LONG, byref Source AS BLENDFUNCTION, Length AS LONG)


    ' added property to TransparentMode (an inherited property but -1 added)
    ' -1 = AlphaTransparency already present
    '  0 = ChromaTransparency Auto
    '  1 = ChromaTransparency Fixed
$DEFINE tmAlpha -1


' Alpha Premultiply Routine in Array
DEFLNG AlphaPreMultiplyArray(0 TO 46) = { _
  &H000000C8, &H85087D8B, &H9C840FFF, &H8B000000, _
  &H67F70447, &H0FC08508, &H00009584, &H8BC18900, _
  &HFF85147F, &H0081840F, &H458B0000, &H79C08514, _
  &H035F8A2C, &H1B74DB84, &H74FFFB80, &H02478A16, _
  &H6788E3F6, &H01478A02, &H6788E3F6, &HF6078A01, _
  &H832788E3, &H754904C7, &HEBC031D8, &H0D078B5A, _
  &HFF000000, &HC7830789, &HF1754904, &H850C458B, _
  &H8B4474C0, &H478B087D, &H0867F704, &H7F8BC189, _
  &H14458B14, &H0475C085, &H09EB1F8B, &H81105D8B, _
  &H000000CB, &H39078BFF, &HC70675D8, &H00000007, _
  &H04C78300, &H31EE7549, &HB80CEBC0, &H000001E7, _
  &H3FB805EB, &HC9000020, &H000010C2 }


Type QBitmapEx EXTENDS QBITMAP
  PRIVATE:
    info as TBITMAP
    hpen as long
    hbrush as long
    oldpen as long
    oldbrush as long
  PUBLIC:
    PenStyle as long
    PenSize as integer
  

  '========================================
  ' méthode dessin d'icones
  '========================================
  Sub DrawIco(left as integer,top as integer,width as integer,height as integer,handle as long)
    DrawIconEx(QBitmapEx.handle,left,top,handle,width,height,0,0,DI_NORMAL)
  End Sub

  '================================================
  ' méthode copie le contenu dans le presse papier
  '================================================
  Sub CopyToClipboard
    dim hBitmap as integer
    dim bitmap as QBitmap 
    
    bitmap.bmp=THIS.bmp
    bitmap.pixelformat=0
    hBitmap=GetCurrentObject(bitmap.handle,OBJ_BITMAP)
    clipboard.open
    clipboard.clear
    clipboard.SetAsHandle(CF_BITMAP,hBitmap)
    clipboard.close
  End Sub

  '=============================================
  ' méthode colle une image du le presse papier
  '=============================================
  Sub PasteFromClipboard(x as short,y as short)
    dim hDC as integer
    dim hBitmap as integer
    dim hOldBitmap as integer

	'be sure pixelformat is declared to be compatible before running
	'if clipboard is stored with CF_DIB then it is converted for CF_BITMAP

    if clipboard.hasformat(CF_BITMAP) then		
      clipboard.open
      hBitmap=clipboard.GetAsHandle(CF_BITMAP)
      clipboard.close
      GetObject(hBitmap,SIZEOF(QBitmapEx.info),QBitmapEx.info)	'get the width,height of clipboard
      hDC=CreateCompatibleDC(QBitmapEx.handle)					'make a Device Context
      hOldBitmap=SelectObject(hDC,hBitmap)						'selects object into the device context
      BitBlt(QBitmapEx.handle,x,y,QBitmapEx.info.bmwidth,QBitmapEx.info.bmheight,hDC,0,0,SRCCOPY)
      SelectObject(hDC,hOldBitmap)
      DeleteDC(hDC)
    end if
  End Sub


  '===============================================
  ' méthode info largeur image du presse papier
  '===============================================
  Function GetWidthClipboard as integer
    dim hBitmap as integer

    if clipboard.hasformat(CF_BITMAP) then
      clipboard.open
      hBitmap=clipboard.GetAsHandle(CF_BITMAP)
      clipboard.close
      GetObject(hBitmap,SIZEOF(QBitmapEx.info),QBitmapEx.info)
      result=QBitmapEx.info.bmwidth
    end if
  End Function

  '===============================================
  ' méthode info hauteur image du presse papier
  '===============================================
  Function GetHeightClipboard as integer
    dim hBitmap as integer

    if clipboard.hasformat(CF_BITMAP) then
      clipboard.open
      hBitmap=clipboard.GetAsHandle(CF_BITMAP)
      clipboard.close
      GetObject(hBitmap,SIZEOF(QBitmapEx.info),QBitmapEx.info)
      result=QBitmapEx.info.bmheight
    end if
  End Function

  '===============================================
  ' méthode info image presente dans presse papier
  '===============================================
  Function CanPaste() as long
    result=clipboard.hasformat(CF_BITMAP)
  End Function


  '===============================================
  ' Return a pointer to the pixel data (Paul Ludgate)
  '===============================================
  FUNCTION Pointer AS LONG
	DIM hBM		AS LONG
	DIM hObj	AS LONG
	DIM lpInfo	AS STRING*24'LONG

		IF QBitmapEx.Width = 0 OR QBitmapEx.Height = 0 THEN 
			RESULT = 0
			GOTO EXIT_FUNCTION
		END IF
		hBM = GetCurrentObject(QBitmapEx.Handle, OBJ_BITMAP)	'handle to formatted bitmap in Device context
			IF hBM = 0 THEN RESULT = 0 : GOTO EXIT_FUNCTION
		hObj = GetObject(hBM, SIZEOF(QBitmapEx.Info), QBitmapEx.Info)
			IF hObj = 0 THEN RESULT = 0 : GOTO EXIT_FUNCTION
		RESULT = QBitmapEx.Info.bmBits
    EXIT_FUNCTION:                             'skip exit function memory leak
  END FUNCTION



  '========================================
  ' méthode trace un cercle vide
  '========================================
  Sub circle(x1 as integer,y1 as integer,x2 as integer,y2 as integer,c as long)
    QBitmapEx.hbrush=GetStockObject(NULL_BRUSH)
    QBitmapEx.oldbrush=SelectObject(QBitmapEx.handle,QBitmapEx.hbrush)
    QBitmapEx.hpen=CreatePen(QBitmapEx.PenStyle,QBitmapEx.PenSize,c)
    QBitmapEx.oldpen=SelectObject(QBitmapEx.handle,QBitmapEx.hpen)
    Ellipse(QBitmapEx.handle,x1,y1,x2,y2)
    SelectObject(QBitmapEx.handle,QBitmapEx.oldpen)
    SelectObject(QBitmapEx.handle,QBitmapEx.oldbrush)
    DeleteObject(QBitmapEx.hpen)
  End Sub

  '========================================
  ' méthode trace un cercle plein
  '========================================
  Sub circleFilled(x1 as integer,y1 as integer,x2 as integer,y2 as integer,c as long,fill as long)
    QBitmapEx.hpen=CreatePen(QBitmapEx.PenStyle,QBitmapEx.PenSize,c)
    QBitmapEx.hbrush=CreateSolidBrush(fill)
    QBitmapEx.oldpen=SelectObject(QBitmapEx.handle,QBitmapEx.hpen)
    QBitmapEx.oldbrush=SelectObject(QBitmapEx.handle,QBitmapEx.hbrush)
    Ellipse(QBitmapEx.handle,x1,y1,x2,y2)
    SelectObject(QBitmapEx.handle,QBitmapEx.oldpen)
    SelectObject(QBitmapEx.handle,QBitmapEx.oldbrush)
    DeleteObject(QBitmapEx.hpen)
    DeleteObject(QBitmapEx.hbrush)
  End Sub

  '========================================
  ' méthode trace un rectangle vide
  '========================================
  Sub rectangle(x1 as integer,y1 as integer,x2 as integer,y2 as integer,c as long)
    QBitmapEx.hbrush=GetStockObject(NULL_BRUSH)
    QBitmapEx.oldbrush=SelectObject(QBitmapEx.handle,QBitmapEx.hbrush)
    QBitmapEx.hpen=CreatePen(QBitmapEx.PenStyle,QBitmapEx.PenSize,c)
    QBitmapEx.oldpen=SelectObject(QBitmapEx.handle,QBitmapEx.hpen)
    Rectangle(QBitmapEx.handle,x1,y1,x2,y2)
    SelectObject(QBitmapEx.handle,QBitmapEx.oldpen)
    SelectObject(QBitmapEx.handle,QBitmapEx.oldbrush)
    DeleteObject(QBitmapEx.hpen)
  End Sub
  
  '==================================================
  ' méthode trace un rectangle vide au coins arrondi
  '==================================================
  Sub RoundRect(x1 as integer,y1 as integer,x2 as integer,y2 as integer,x3 as integer,y3 as integer,c as long)
    QBitmapEx.hbrush=GetStockObject(NULL_BRUSH)
    QBitmapEx.oldbrush=SelectObject(QBitmapEx.handle,QBitmapEx.hbrush)
    QBitmapEx.hpen=CreatePen(QBitmapEx.PenStyle,QBitmapEx.PenSize,c)
    QBitmapEx.oldpen=SelectObject(QBitmapEx.handle,QBitmapEx.hpen)
    RoundRect(QBitmapEx.handle,x1,y1,x2,y2,x3,y3)
    SelectObject(QBitmapEx.handle,QBitmapEx.oldpen)
    SelectObject(QBitmapEx.handle,QBitmapEx.oldbrush)
    DeleteObject(QBitmapEx.hpen)
  End Sub

  '==================================================
  ' méthode trace un rectangle plein au coins arrondi
  '==================================================
  Sub RoundRectFilled(x1 as integer,y1 as integer,x2 as integer,y2 as integer,x3 as integer,y3 as integer,c as long,fill as long)
    QBitmapEx.hpen=CreatePen(QBitmapEx.PenStyle,QBitmapEx.PenSize,c)
    QBitmapEx.hbrush=CreateSolidBrush(fill)
    QBitmapEx.oldpen=SelectObject(QBitmapEx.handle,QBitmapEx.hpen)
    QBitmapEx.oldbrush=SelectObject(QBitmapEx.handle,QBitmapEx.hbrush)
    RoundRect(QBitmapEx.handle,x1,y1,x2,y2,x3,y3)
    SelectObject(QBitmapEx.handle,QBitmapEx.oldpen)
    SelectObject(QBitmapEx.handle,QBitmapEx.oldbrush)
    DeleteObject(QBitmapEx.hpen)
    DeleteObject(QBitmapEx.hbrush)
  End Sub
    
  '==================================================
  ' méthode trace un rectangle plein
  '==================================================
  Sub rectangleFilled(x1 as integer,y1 as integer,x2 as integer,y2 as integer,c as long,fill as long)
    QBitmapEx.hpen=CreatePen(QBitmapEx.PenStyle,QBitmapEx.PenSize,c)
    QBitmapEx.hbrush=CreateSolidBrush(fill)
    QBitmapEx.oldpen=SelectObject(QBitmapEx.handle,QBitmapEx.hpen)
    QBitmapEx.oldbrush=SelectObject(QBitmapEx.handle,QBitmapEx.hbrush)
    Rectangle(QBitmapEx.handle,x1,y1,x2,y2)
    SelectObject(QBitmapEx.handle,QBitmapEx.oldpen)
    SelectObject(QBitmapEx.handle,QBitmapEx.oldbrush)
    DeleteObject(QBitmapEx.hpen)
    DeleteObject(QBitmapEx.hbrush)
  End Sub
  
  '==================================================
  ' méthode trace une ligne
  '==================================================
  Sub line(x1 as integer,y1 as integer,x2 as integer,y2 as integer,c as long)
    QBitmapEx.hpen=CreatePen(QBitmapEx.PenStyle,QBitmapEx.PenSize,c)
    QBitmapEx.oldpen=SelectObject(QBitmapEx.handle,QBitmapEx.hpen)
    MoveToEx(QBitmapEx.handle,x1,y1,0)
    LineTo(QBitmapEx.handle,x2,y2)
    SelectObject(QBitmapEx.handle,QBitmapEx.oldpen)
    DeleteObject(QBitmapEx.hpen)
  End Sub

  '==================================================
  ' méthode rempli une surface
  '==================================================
  Sub FillSurface(x as integer,y as integer,c as long)
    QBitmapEx.hbrush=CreateSolidBrush(c)
    QBitmapEx.oldbrush=SelectObject(QBitmapEx.handle,QBitmapEx.hbrush)
    ExtFloodFill(QBitmapEx.handle,x,y,QBitmapEx.pixel(x,y),1)
    SelectObject(QBitmapEx.handle,QBitmapEx.oldbrush)
    DeleteObject(QBitmapEx.hbrush)
  End Sub
    
  '==================================================
  ' méthode inverse les couleurs
  '==================================================
  Sub InvertColor(x as integer,y as integer,width as integer,height as integer)
    PatBlt(QBitmapEx.handle,x,y,Width,Height,DSTINVERT)
  End Sub

  '==================================================
  ' méthode effectue un miroir en x
  '==================================================
  Sub mirror(x as integer,y as integer,width as integer,height as integer)
    StretchBlt(QBitmapEx.handle,x+width,y,-Width,Height,QBitmapEx.handle,x,y,Width,Height,SRCCOPY)
  End Sub

  '==================================================
  ' méthode effectue un miroir en y
  '==================================================
  Sub flip(x as integer,y as integer,width as integer,height as integer)
    StretchBlt(QBitmapEx.handle,x,y+height,Width,-Height,QBitmapEx.handle,x,y,Width,Height,SRCCOPY)
  End Sub


    
  '==================================================
  'Method to load"Picture files|*.BMP;*.JPG;*.GIF;*.DIB;*.RLE;*.TGA;*.PCX" +
  ' format using jpeg.dll (for jpg or ico) or NviewLib (all others) , modified by johnK
  '==================================================
  Sub LoadOtherImage(FileName as string,Progress as boolean,Language as string)
   IF NViewLibPresent THEN					'dll support needed
    dim hDC as integer
    dim hBitmap as long
    dim hOldBitmap as integer
	dim FilExts as string

'	hDC = INSTR(LEN(FileName)-5, FileName, ".")				'reuse same var
'	FilExts = UCASE$(MID$(FileName, hDC, 4))				'ok to go beyond string end in RapidQ
	FilExts = UCASE$(RIGHT$(FileName, LEN(FileName) - RINSTR(FileName, ".") + 1))
	IF (NViewLibPresent = 2) AND INSTR(".JPG.JPEG.JIF.ICO", FilExts) THEN		'use jpeg.dll
	THIS.PixelFormat = pf24bit
		hBitmap = JpegDLL_LoadImageFile(0&, FileName)
		THIS.width=JpegDLL_ImageWidth(hBitmap)
		THIS.height=JpegDLL_ImageHeight(hBitmap)
	ELSE
		THIS.PixelFormat = pf24bit
	    NViewSetLanguage(language)
    	hBitmap=NViewLoad(FileName,Progress)
		THIS.width=NViewGetWidth()
		THIS.height=NViewGetHeight()
	END IF
	hDC = 0			'reset

    if hBitmap<>0 then
      hDC=CreateCompatibleDC(QBitmapEx.handle)
      hOldBitmap=SelectObject(hDC,hBitmap)
      BitBlt(QBitmapEx.handle,0,0,THIS.width,THIS.height,hDC,0,0,SRCCOPY)
      SelectObject(hDC,hOldBitmap)
      DeleteDC(hDC)
      DeleteObject(hBitmap)
    end if
   END IF
  End Sub


'  Sub AutoLoadImage(FileName as string)
'	DIM FileExts AS STRING
'
'	FileExts = UCASE$(RIGHT$(FileName, LEN(FileName) - RINSTR(FileName, ".") + 1))
'	IF (FileExts = "") OR (FileExts = ".BMP") THEN
'		This.LoadFromFile(FileName)
'	ELSE
'		This.LoadOtherImage(FileName, 0, "")
'	END IF
'  End Sub


  '==================================================
  ' méthode sauve le bitmap au format Jpg
  '==================================================
  Sub SaveAsJpg(FileName as string,Quality as Integer)
    dim hBitmap as integer
    dim path as string
    dim File as string
    dim bitmap as qbitmap

	IF NViewLibPresent AND (FileName<>"" ) THEN
      path=LEFT$(FileName,RINSTR(FileName,"\"))
      if DirExists(path) then
      	File=path+"temp.bmp"
      	bitmap.pixelformat = pf16bit
      	bitmap.width=THIS.width
      	bitmap.height=THIS.height
      	bitmap.draw(0,0,THIS.bmp)
      	bitmap.pixelformat = pf24bit
        bitmap.SaveToFile(File)
        hBitmap=NViewLoad(File,false)
        NViewSaveAsJPG(Quality,FileName)
        DeleteObject(hBitmap)
        Kill File
      end if
    END IF
  End Sub



	'***** AlphaBlend upgraded to include AlphaPreMultiplyby Paul Ludgate  3/2005 ********
	'routines for 32 bit bitmaps finely tuned them for ultimate speed
	'by using RQASM. Function AlphaPreMultiply for alphablend which is required
	'for 32bit bitmaps using the alphabyte for the per pixel alphablend
	'you don't need to do AlphaPreMultiply, if already premultiplied
    'percentBlend Flag < 0 means perPixel AlphaBlending for 32 bpp BMPs
	' Returns 1 if succeed, if fail

  FUNCTION AlphaBlend(BMPDest AS QBITMAP, BMPSource AS QBITMAP, PercentBlend AS SINGLE) AS LONG
	DIM AlphaConst 	AS BYTE
    DIM BF 			AS BLENDFUNCTION
    DIM BFpointer	AS LONG
    DIM Rtn			AS LONG
    DIM aFormat		AS LONG
    'make QbitmapEX dimensions since it does not have Width or Height!!
    QBitmapEx.BMP =  BMPDest.BMP		' this is a shortcut
    IF PercentBlend < 0 THEN
      aFormat = AC_SRC_ALPHA			''AC_SRC_ALPHA for 32-bit with alpha bits
    ELSE
      aFormat = 0						' blend whole image by constant factor
    END IF
    AlphaConst= ROUND(ABS(255 * PercentBlend))
    WITH BF
      .BlendOp		= AC_SRC_OVER		'only 1 supported value
      .BlendFlags	= 0					'must be 0
      .SourceConstantAlpha = AlphaConst
      .AlphaFormat = aFormat
    END WITH
    BFMoveMemory(BFpointer, BF, SIZEOF(BF)) 'must use this for aligning structure!!!
    'Blend Destination with Source BMP
    IF aFormat = AC_SRC_ALPHA THEN			' process is destructive so make copy to work on
      DIM BMPTemp AS QBITMAP
      BMPTemp.BMP = BMPSource.BMP
      DIM bmInfo AS TBITMAP
      DIM hBM  AS LONG
      DIM hObj AS LONG
      IF BMPSource.PixelFormat = pf32bit THEN		' need to AlphaPreMultiply
        hBM = GetCurrentObject(BMPTemp.Handle, OBJ_BITMAP)
        hObj = GetObject(hBM, SIZEOF(bmInfo), bmInfo)
        Rtn = CallWindowProc(VARPTR(AlphaPreMultiplyArray(0)), bmInfo, 0, 0, -1)
      ELSE		' need to convert ChromaTransparency to AlphaTransparency
        BMPTemp.PixelFormat = pf32bit
        hBM = GetCurrentObject(BMPTemp.Handle, OBJ_BITMAP)
        hObj = GetObject(hBM, SIZEOF(bmInfo), bmInfo)
        Rtn = CallWindowProc(VARPTR(AlphaPreMultiplyArray(0)), bmInfo, _
        BMPSource.Transparent, BMPSource.TransparentColor, BMPSource.TransparentMode)
      END IF
      IF Rtn THEN
        SetLastError(Rtn)
        Rtn = 0
      ELSE
        Rtn = 1
      END IF
      Rtn = AlphaBlend(QBitmapEx.Handle, 0, 0, QBitmapEx.Width, QBitmapEx.Height, _
      BMPTemp.Handle, 0, 0, BMPTemp.Width, BMPTemp.Height, BFPointer)
      DeleteObject(hBM)		' clean up
    ELSE
      Rtn = AlphaBlend(QBitmapEx.Handle, 0, 0, QBitmapEx.Width, _
      QBitmapEx.Height, BMPSource.Handle, 0, 0, _
      BMPSource.Width, BMPSource.Height, BFPointer)
    END IF
    RESULT = Rtn
  END FUNCTION


  Constructor
    PenStyle=PS_SOLID
    PenSize=1
  End Constructor
END TYPE





'====================================================================================================================
' --- QIMAGE extension   version 1.1
'by D.Glodt (c)2000-2004, modified by John Kelly, 2005
'====================================================================================================================

TYPE QImageEx EXTENDS QIMAGE
  PRIVATE:
    bitmap as QBitmap

  PUBLIC:  
  '===================================================
  ' Méthode copie image dans presse papier
  '===================================================
  Sub CopyToClipboard(rect as QRECT)
    dim hDC as integer
    dim hBitmap as integer
    dim hOldBitmap as integer
    dim width as integer
    dim height as integer

    width=rect.right-rect.left
    height=rect.bottom-rect.top
    hDC=CreateCompatibleDC(QImageEx.handle)
    hBitmap=CreateCompatibleBitmap(QImageEx.handle,width,height)
    hOldBitmap=SelectObject(hDC,hBitmap)
    BitBlt(hDC,0,0,width,height,QImageEx.handle,rect.left,rect.top,SRCCOPY)
    clipboard.open
    clipboard.clear
    clipboard.SetAsHandle(CF_BITMAP,hBitmap)
    clipboard.close
    SelectObject(hDC,hOldBitmap)
    DeleteDC(hDC)
    DeleteObject(hBitmap)
  End Sub
  
  '===================================================
  ' Méthode colle image du presse papier
  '===================================================
  Sub PasteFromClipboard
    if clipboard.hasformat(CF_BITMAP) then
      clipboard.open
      QImageEx.handle=clipboard.GetAsHandle(CF_BITMAP)
      clipboard.close
    end if
  End Sub

  '===================================================
  ' Méthode charge et affiche un fichier bitmap
  '===================================================
  Sub LoadFromFile(FileName as string,width as short,height as short,real as boolean)
    if real then
      QImageEx.bitmap.bmp=FileName
      QImageEx.handle=LoadImage(Application.hInstance,fileName,0,QImageEx.bitmap.width,QImageEx.bitmap.height,&H10)
    else
      QImageEx.handle=LoadImage(Application.hInstance,fileName,0,width,height,&H10)
    end if
  End Sub

  '===================================================
  ' Méthode info image présente dans presse papier
  '===================================================
  FUNCTION CanPaste as boolean
    result=clipboard.hasformat(CF_BITMAP)
  END FUNCTION

  '==================================================
  ' méthode charge les formats dll
  '==================================================
  Sub LoadOtherImage(FileName as string,Progress as boolean,Language as string)
	DIM i 		AS INTEGER
	DIM FilExts AS STRING

	IF NViewLibPresent THEN                        'dll support needed
        if FileName<>"" and FileExists(FileName) then
		i = INSTR(LEN(FileName)-5, FileName, ".")	'find extension
		FilExts = UCASE$(MID$(FileName, i, 4))		'ok to go beyond string end in RapidQ
		IF (NViewLibPresent = 2) AND INSTR(".JPG.JPEG.JIF.ICO", FilExts) THEN		'use jpeg.dll
			THIS.handle = JpegDLL_LoadImageFile(0&, FileName)
			THIS.width = JpegDLL_ImageWidth(THIS.handle)
			THIS.height = JpegDLL_ImageHeight(THIS.handle)
		ELSE
			NViewSetLanguage(language)
      		THIS.handle = NViewLoad(FileName,Progress)
      		THIS.width = NViewGetWidth
      		THIS.height = NViewGetHeight
		END IF
        end if
    END IF
  End Sub    

END TYPE





'====================================================================================================================
' --- QCanvasEx, QCanvasEx version 1.2
'  much more than QBITMAP or QIMAGE
'====================================================================================================================

TYPE QCanvasEx EXTENDS QCANVAS

  PRIVATE:
'    info as TBITMAP
    hpen as long
    hbrush as long
    oldpen as long
    oldbrush as long

  PUBLIC:
    info as TBITMAP
    MixMode as long
    PenStyle as long
    PenSize as integer

  '========================================
  ' méthode dessin d'icones
  '========================================
  Sub DrawIco(left as integer,top as integer,width as integer,height as integer,handle as long)
    DrawIconEx(QCanvasEx.handle,left,top,handle,width,height,0,0,DI_NORMAL)
  End Sub
 
  '================================================
  ' méthode copie le contenu dans le presse papier
  '================================================
  Sub CopyToClipboard(rect as QRECT)
    dim hDC as integer
    dim hBitmap as integer
    dim hOldBitmap as integer
    dim width as integer
    dim height as integer

    width=rect.right-rect.left
    height=rect.bottom-rect.top
    hDC=CreateCompatibleDC(QCanvasEx.handle)
    hBitmap=CreateCompatibleBitmap(QCanvasEx.handle,width,height)
    hOldBitmap=SelectObject(hDC,hBitmap)
    BitBlt(hDC,0,0,width,height,QCanvasEx.handle,rect.left,rect.top,SRCCOPY)
    clipboard.open
    clipboard.clear
    clipboard.SetAsHandle(CF_BITMAP,hBitmap)
    clipboard.close
    SelectObject(hDC,hOldBitmap)
    DeleteDC(hDC)
    DeleteObject(hBitmap)
  End Sub
  
  '=============================================
  ' méthode colle une image du le presse papier
  '=============================================
  Sub PasteFromClipboard(x as short,y as short)
    dim hDC as integer
    dim hBitmap as integer
    dim hOldBitmap as integer

    if clipboard.hasformat(CF_BITMAP) then
      clipboard.open
      hBitmap=clipboard.GetAsHandle(CF_BITMAP)
      clipboard.close
      GetObject(hBitmap,SIZEOF(QCanvasEx.info),QCanvasEx.info)
      hDC=CreateCompatibleDC(QCanvasEx.handle)
      hOldBitmap=SelectObject(hDC,hBitmap)
      BitBlt(QCanvasEx.handle,x,y,QCanvasEx.info.bmwidth,QCanvasEx.info.bmheight,hDC,0,0,SRCCOPY)
      SelectObject(hDC,hOldBitmap)
      DeleteDC(hDC)
    end if
  End Sub

  '===============================================
  ' méthode info largeur image du presse papier
  '===============================================
  Function GetWidthClipboard as integer
    dim hBitmap as integer

    if clipboard.hasformat(CF_BITMAP) then
      clipboard.open
      hBitmap=clipboard.GetAsHandle(CF_BITMAP)
      clipboard.close
      GetObject(hBitmap,SIZEOF(QCanvasEx.info),QCanvasEx.info)
      result=QCanvasEx.info.bmwidth
    end if
  End Function

  '===============================================
  ' méthode info hauteur image du presse papier
  '===============================================
  Function GetHeightClipboard as integer
    dim hBitmap as integer

    if clipboard.hasformat(CF_BITMAP) then
      clipboard.open
      hBitmap=clipboard.GetAsHandle(CF_BITMAP)
      clipboard.close
      GetObject(hBitmap,SIZEOF(QCanvasEx.info),QCanvasEx.info)
      result=QCanvasEx.info.bmheight
    end if
  End Function

  '===============================================
  ' méthode info image presente dans presse papier
  '===============================================
  Function CanPaste as boolean
    result=clipboard.hasformat(CF_BITMAP)
  End Function

  '========================================
  ' méthode trace un cercle vide
  '========================================
  Sub circle(x1 as integer,y1 as integer,x2 as integer,y2 as integer,c as long)
    QCanvasEx.hbrush=GetStockObject(NULL_BRUSH)
    QCanvasEx.oldbrush=SelectObject(QCanvasEx.handle,QCanvasEx.hbrush)
    QCanvasEx.hpen=CreatePen(QCanvasEx.PenStyle,QCanvasEx.PenSize,c)
    QCanvasEx.oldpen=SelectObject(QCanvasEx.handle,QCanvasEx.hpen)
    SetROP2(QCanvasEx.handle,QCanvasEx.mixmode)
    Ellipse(QCanvasEx.handle,x1,y1,x2,y2)
    SelectObject(QCanvasEx.handle,QCanvasEx.oldpen)
    SelectObject(QCanvasEx.handle,QCanvasEx.oldbrush)
    DeleteObject(QCanvasEx.hpen)
  End Sub

  '========================================
  ' méthode trace un cercle plein
  '========================================
  Sub circleFilled(x1 as integer,y1 as integer,x2 as integer,y2 as integer,c as long,fill as long)
    QCanvasEx.hpen=CreatePen(QCanvasEx.PenStyle,QCanvasEx.PenSize,c)
    QCanvasEx.hbrush=CreateSolidBrush(fill)
    QCanvasEx.oldpen=SelectObject(QCanvasEx.handle,QCanvasEx.hpen)
    QCanvasEx.oldbrush=SelectObject(QCanvasEx.handle,QCanvasEx.hbrush)
    SetROP2(QCanvasEx.handle,QCanvasEx.mixmode)
    Ellipse(QCanvasEx.handle,x1,y1,x2,y2)
    SelectObject(QCanvasEx.handle,QCanvasEx.oldpen)
    SelectObject(QCanvasEx.handle,QCanvasEx.oldbrush)
    DeleteObject(QCanvasEx.hpen)
    DeleteObject(QCanvasEx.hbrush)
  End Sub

  '========================================
  ' méthode trace un rectangle vide
  '========================================
  Sub rectangle(x1 as integer,y1 as integer,x2 as integer,y2 as integer,c as long)
    QCanvasEx.hbrush=GetStockObject(NULL_BRUSH)
    QCanvasEx.oldbrush=SelectObject(QCanvasEx.handle,QCanvasEx.hbrush)
    QCanvasEx.hpen=CreatePen(QCanvasEx.PenStyle,QCanvasEx.PenSize,c)
    QCanvasEx.oldpen=SelectObject(QCanvasEx.handle,QCanvasEx.hpen)
    SetROP2(QCanvasEx.handle,QCanvasEx.mixmode)
    Rectangle(QCanvasEx.handle,x1,y1,x2,y2)
    SelectObject(QCanvasEx.handle,QCanvasEx.oldpen)
    SelectObject(QCanvasEx.handle,QCanvasEx.oldbrush)
    DeleteObject(QCanvasEx.hpen)
  End Sub
  
  '==================================================
  ' méthode trace un rectangle vide au coins arrondi
  '==================================================
  Sub RoundRect(x1 as integer,y1 as integer,x2 as integer,y2 as integer,x3 as integer,y3 as integer,c as long)
    QCanvasEx.hbrush=GetStockObject(NULL_BRUSH)
    QCanvasEx.oldbrush=SelectObject(QCanvasEx.handle,QCanvasEx.hbrush)
    QCanvasEx.hpen=CreatePen(QCanvasEx.PenStyle,QCanvasEx.PenSize,c)
    QCanvasEx.oldpen=SelectObject(QCanvasEx.handle,QCanvasEx.hpen)
    SetROP2(QCanvasEx.handle,QCanvasEx.mixmode)
    RoundRect(QCanvasEx.handle,x1,y1,x2,y2,x3,y3)
    SelectObject(QCanvasEx.handle,QCanvasEx.oldpen)
    SelectObject(QCanvasEx.handle,QCanvasEx.oldbrush)
    DeleteObject(QCanvasEx.hpen)
  End Sub

  '==================================================
  ' méthode trace un rectangle plein au coins arrondi
  '==================================================
  Sub RoundRectFilled(x1 as integer,y1 as integer,x2 as integer,y2 as integer,x3 as integer,y3 as integer,c as long,fill as long)
    QCanvasEx.hpen=CreatePen(QCanvasEx.PenStyle,QCanvasEx.PenSize,c)
    QCanvasEx.hbrush=CreateSolidBrush(fill)
    QCanvasEx.oldpen=SelectObject(QCanvasEx.handle,QCanvasEx.hpen)
    QCanvasEx.oldbrush=SelectObject(QCanvasEx.handle,QCanvasEx.hbrush)
    SetROP2(QCanvasEx.handle,QCanvasEx.mixmode)
    RoundRect(QCanvasEx.handle,x1,y1,x2,y2,x3,y3)
    SelectObject(QCanvasEx.handle,QCanvasEx.oldpen)
    SelectObject(QCanvasEx.handle,QCanvasEx.oldbrush)
    DeleteObject(QCanvasEx.hpen)
    DeleteObject(QCanvasEx.hbrush)
  End Sub
    
  '==================================================
  ' méthode trace un rectangle plein
  '==================================================
  Sub rectangleFilled(x1 as integer,y1 as integer,x2 as integer,y2 as integer,c as long,fill as long)
    QCanvasEx.hpen=CreatePen(QCanvasEx.PenStyle,QCanvasEx.PenSize,c)
    QCanvasEx.hbrush=CreateSolidBrush(fill)
    QCanvasEx.oldpen=SelectObject(QCanvasEx.handle,QCanvasEx.hpen)
    QCanvasEx.oldbrush=SelectObject(QCanvasEx.handle,QCanvasEx.hbrush)
    SetROP2(QCanvasEx.handle,QCanvasEx.mixmode)
    Rectangle(QCanvasEx.handle,x1,y1,x2,y2)
    SelectObject(QCanvasEx.handle,QCanvasEx.oldpen)
    SelectObject(QCanvasEx.handle,QCanvasEx.oldbrush)
    DeleteObject(QCanvasEx.hpen)
    DeleteObject(QCanvasEx.hbrush)
  End Sub
  
  '==================================================
  ' méthode trace une ligne
  '==================================================
  Sub line(x1 as integer,y1 as integer,x2 as integer,y2 as integer,c as long)
    QCanvasEx.hpen=CreatePen(QCanvasEx.PenStyle,QCanvasEx.PenSize,c)
    QCanvasEx.oldpen=SelectObject(QCanvasEx.handle,QCanvasEx.hpen)
    SetROP2(QCanvasEx.handle,QCanvasEx.mixmode)
    MoveToEx(QCanvasEx.handle,x1,y1,0)
    LineTo(QCanvasEx.handle,x2,y2)
    SelectObject(QCanvasEx.handle,QCanvasEx.oldpen)
    DeleteObject(QCanvasEx.hpen)
  End Sub

  '==================================================
  ' méthode rempli une surface
  '==================================================
  Sub FillSurface(x as integer,y as integer,c as long)
    QCanvasEx.hbrush=CreateSolidBrush(c)
    QCanvasEx.oldbrush=SelectObject(QCanvasEx.handle,QCanvasEx.hbrush)
    ExtFloodFill(QCanvasEx.handle,x,y,QCanvasEx.pixel(x,y),1)
    SelectObject(QCanvasEx.handle,QCanvasEx.oldbrush)
    DeleteObject(QCanvasEx.hbrush)
  End Sub
  
  '==================================================
  ' méthode affiche du texte, taken out of latest version???
  '==================================================
  Sub TextOut(x as integer,y as integer,s as string,fc as long,bc as long)
    SetBkMode(QCanvasEx.handle,TRANSPARENT)
    super.TextOut(x,y,s,fc,bc)
    SetBkMode(QCanvasEx.handle,OPAQUE)
  End Sub
  
  '==================================================
  ' méthode inverse les couleurs
  '==================================================
  Sub InvertColor(x as integer,y as integer,width as integer,height as integer)
    PatBlt(QCanvasEx.handle,x,y,Width,Height,DSTINVERT)
  End Sub

  '==================================================
  ' méthode effectue un miroir en x
  '==================================================
  Sub mirror(x as integer,y as integer,width as integer,height as integer)
    StretchBlt(QCanvasEx.handle,x+width,y,-Width,Height,QCanvasEx.handle,x,y,Width,Height,SRCCOPY)
  End Sub

  '==================================================
  ' méthode effectue un miroir en y
  '==================================================
  Sub flip(x as integer,y as integer,width as integer,height as integer)
    StretchBlt(QCanvasEx.handle,x,y+height,Width,-Height,QCanvasEx.handle,x,y,Width,Height,SRCCOPY)
  End Sub
    
  Constructor
    MixMode=R2_COPYPEN
    PenStyle=PS_SOLID
    PenSize=1
  End Constructor
End Type





'==============================================================================================
'COMPORT component, based on  ComPort.cmp by Pete Kleinschmidt,
'  and on VB code by David M. Hitchner, 'http://www.thescarms.com/vbasic/CommIO.asp
'Version 1.0, December 13, 2004   by JohnK

'==============================================================================================

'Forward Internal Declarations for events
     DECLARE SUB OnComError_EventTemplate (strErrorMessage AS STRING)
     DECLARE SUB OnOpen_EventTemplate
     DECLARE SUB OnClose_EventTemplate
     DECLARE SUB OnWriteString_EventTemplate
     DECLARE SUB OnReadString_EventTemplate



TYPE COMPORT EXTENDS QOBJECT

  'EVENTS
      OnComError    AS EVENT (OnComError_EventTemplate)
      OnOpen        AS EVENT (OnOpen_EventTemplate)
      OnClose       AS EVENT (OnClose_EventTemplate)
      OnWriteString AS EVENT (OnWriteString_EventTemplate)
      OnReadString  AS EVENT (OnReadString_EventTemplate)

	'Events not inherited, because COMPORT is blocking don't need these
'			OnBreak VOID A line break is detected, input and output is suspended until break is cleared
'			OnError -->onComError
'			OnRing VOID A ring signal is detected, used only with modems.
'			OnRxChar SUB (InQue AS INTEGER) A character(s) arrives in the input buffer.
'			OnTxEmpty VOID Output buffer is flushed 


  'PROPERTIES
      Handle            AS LONG
      Port              AS STRING
      BaudRate          AS DWORD
      DataBits          AS BYTE
      Parity            AS BYTE
      StopBits          AS BYTE
      ReadBufSize       AS DWORD
      WriteBufSize      AS DWORD
      BytesNotRead      AS DWORD	'same as InQue --number of bytes received but not yet read
      BytesNotWritten   AS DWORD	'same as OutQue -- number of bytes remaining to be transmitted
	  InQue				AS DWORD	PROPERTY SET GetInQue	'add for compatibility
	  OutQue			AS DWORD	PROPERTY SET GetOutQue	'and if user wants to check current status
      Connected         AS BYTE
         'properties not inherited
         'PendingIO INTEGER R  


  'Default property values
      CONSTRUCTOR
       Port            = "COM1"
       BaudRate        = 9600
       DataBits        = 8
       Parity          = NOPARITY
       StopBits        = 1
       ReadBufSize     = 1024
       WriteBufSize    = 1024
       BytesNotRead    = 0
       BytesNotWritten = 0
       Connected       = FALSE
      END CONSTRUCTOR


  'METHODS
		'not inherited are:
'				AbortAllIO SUB Aborts all asynchronous read/write operations
'				Read SUB Read(QFile/QMemoryStream, Count%, Wait%) Reads stream data from com port, Count% < 32000
'				WaitForLastIO SUB Blocks until last IO is completed
'				Write SUB Write(QFile/QMemoryStream, Count%, Wait%) Writes stream to com port, Count% < 32000
'

  'Method FormatError (Convert GetLastError codes to String messages)
PRIVATE:
   FUNCTION FormatError AS STRING
       DIM Buffer        AS STRING
       DIM lngRet        AS LONG

       Buffer=SPACE$(1024)

       lngRet=FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM, _
        0, _
        GetLastError(), _
        LANG_NEUTRAL, _
        Buffer, _
        LEN(Buffer), _
        0)
       Result=LEFT$(Buffer,lngRet)
   END FUNCTION

  'Method GetStatus
PRIVATE:
   SUB GetCommStatus
       DIM lngStatus     AS LONG
       DIM dwErrorFlags  AS DWORD
       DIM udtCommStat   AS COMSTAT

     'Clear any previous errors and get current status.
       lngStatus = ClearCommError(ComPort.Handle, _
        dwErrorFlags, _
        udtCommStat)

       IF lngStatus = 0 THEN
        IF ComPort.OnComError > 0 THEN
         CALLFUNC (ComPort.OnComError, ERROR_CHANGING_PORTSETTINGS & ComPort.FormatError)
        END IF
       ELSE
      'Set BytesNotWritten and BytesNotRead Property
        ComPort.BytesNotWritten = udtCommStat.cbOutQue
        ComPort.BytesNotRead    = udtCommStat.cbInQue
        ComPort.InQue  = udtCommStat.cbInQue
        ComPort.OutQue = udtCommStat.cbOutQue
       END IF
    END SUB

	PROPERTY SET GetInQue(myVoid AS DWORD)		'Read only
		Comport.GetCommStatus
	END PROPERTY

	PROPERTY SET GetOutQue(myVoid AS DWORD)		'Read only
		Comport.GetCommStatus
	END PROPERTY



  'Method Open Port
PUBLIC:
      SUB Open

       DIM udtCommTimeOuts AS COMMTIMEOUTS
       DIM udtDCB          AS DCB
       DIM lngStatus       AS LONG

    'Open the Comm Port
       ComPort.Handle = CreateFile(COMPORT.Port, _
        GENERIC_READ OR GENERIC_WRITE, _
        FILE_SHARE_READ OR FILE_SHARE_WRITE, _
        0&, _
        OPEN_EXISTING, _
        FILE_ATTRIBUTE_NORMAL, _
        0&)

       IF ComPort.Handle = -1 THEN
        IF ComPort.OnComError > 0 THEN
         CALLFUNC (ComPort.OnComError,ERROR_OPEN_PORT & ComPort.FormatError)
        END IF
        GOTO EXIT_SUB                      'don't do EXIT SUB, it will generate a memory leak!
       END IF

    'Setup device buffers (1K is default).
       lngStatus = SetupComm(ComPort.Handle,_
        ComPort.ReadBufSize,_
        ComPort.WriteBufSize)

       IF lngStatus = 0 THEN
        IF ComPort.OnComError > 0 THEN
         CALLFUNC (ComPort.OnComError, ERROR_PORT_BUFFERS & ComPort.FormatError)
        END IF
        GOTO EXIT_SUB                      'don't do EXIT SUB, it will generate a memory leak!
       END IF

    'Purge existing data in buffers.
       lngStatus = PurgeComm(ComPort.Handle,_
        PURGE_TXABORT OR PURGE_RXABORT OR PURGE_TXCLEAR OR PURGE_RXCLEAR)

       IF lngStatus = 0 THEN
        IF ComPort.OnComError > 0 THEN
         CALLFUNC (ComPort.OnComError, ERROR_PURGE_BUFFERS & ComPort.FormatError)
        END IF
        GOTO EXIT_SUB                      'don't do EXIT SUB, it will generate a memory leak!
       END IF

    ' Set serial port timeouts values.
       udtCommTimeOuts.ReadIntervalTimeout         = -1
       udtCommTimeOuts.ReadTotalTimeoutMultiplier  = 0
       udtCommTimeOuts.ReadTotalTimeoutConstant    = 1000
       udtCommTimeOuts.WriteTotalTimeoutMultiplier = 0
       udtCommTimeOuts.WriteTotalTimeoutMultiplier = 1000


       lngStatus = SetCommTimeouts(ComPort.Handle,_
        udtCommTimeOuts)

       IF lngStatus = 0 THEN
        IF ComPort.OnComError > 0 THEN
         CALLFUNC (ComPort.OnComError, ERROR_TIMEOUTS & ComPort.FormatError)
        END IF
        GOTO EXIT_SUB                      'don't do EXIT SUB, it will generate a memory leak!
       END IF

    'Get the current state (DCB) - we retain current values for
    'communication settings we don't explicitly set.
       lngStatus = GetCommState (ComPort.Handle, udtDCB)

       IF lngStatus = 0 THEN
        IF ComPort.OnComError > 0 THEN
         CALLFUNC (ComPort.OnComError, ERROR_RETRIEVE_PORTSETTINGS & ComPort.FormatError)
        END IF
        GOTO EXIT_SUB                      'don't do EXIT SUB, it will generate a memory leak!
       END IF

    'Set our Communications State
       udtDCB.BaudRate = ComPort.BaudRate
       udtDCB.ByteSize = ComPort.DataBits
       udtDCB.Parity   = ComPort.Parity
       udtDCB.StopBits = ComPort.StopBits

    'This changes our settings
       lngStatus = SetCommState (ComPort.Handle, udtDCB)

       IF lngStatus = 0 THEN
        IF ComPort.OnComError > 0 THEN
         CALLFUNC (ComPort.OnComError, ERROR_CHANGING_PORTSETTINGS & ComPort.FormatError)
        END IF
       ELSE
      'Set Connected Property
        ComPort.Connected = TRUE
      'Raise OnOpen Event
        IF ComPort.OnOpen > 0 THEN
         CALLFUNC ComPort.OnOpen
        END IF
       END IF

        EXIT_SUB:                      'work around for EXIT SUB memory leak!
      END SUB

PUBLIC:
	SUB PurgeIn ()		'Clears input buffer and stops all input functions
		PurgeComm(ComPort.Handle, PURGE_RXABORT OR PURGE_RXCLEAR)
	END SUB


	SUB PurgeOut		'Clears output buffer and stops all output functions 
		PurgeComm(ComPort.Handle, PURGE_TXABORT OR PURGE_TXCLEAR)
	END SUB


  'Method     Close COM Port
PUBLIC:
      SUB Close
       DIM lngStatus AS LONG

       lngStatus = CloseHandle (ComPort.Handle)
       IF lngStatus = 0 THEN
        IF ComPort.OnComError > 0 THEN
         CALLFUNC (ComPort.OnComError, ERROR_CLOSING_PORT & ComPort.FormatError)
        END IF
       ELSE
      'Set Connected Property
        ComPort.Connected = FALSE
      'Raise OnClose Event
        IF ComPort.OnClose > 0 THEN
         CALLFUNC ComPort.OnClose
        END IF
       END IF
      END SUB


  'Method Writestring
PUBLIC:
	SUB WriteString (strData AS STRING, intWait AS INTEGER)
       DIM lngStatus       AS LONG
       DIM dwBytesToWrite  AS DWORD
       DIM dwByesWritten   AS DWORD

    'Set number of bytes to be sent.
       dwBytesToWrite=LEN(strData)

    'Output the data.
       lngStatus = WriteFile(ComPort.Handle, _
        strData, _
        dwBytesToWrite, _
        dwByesWritten, _
        0&)

       IF lngStatus = 0 THEN
        	IF ComPort.OnComError > 0 THEN
        	  CALLFUNC (ComPort.OnComError, ERROR_WRITING_PORT & ComPort.FormatError)
	        END IF
       ELSE
	        IF intWait THEN SLEEP.ms(intWait)		'Wait for data to be written
	        ComPort.GetCommStatus	      		'any bytes still waiting to be written?

        IF Comport.BytesNotWritten = 0 THEN		'If all data has been sent Raise OnWriteString event
         IF ComPort.OnWriteString > 0 THEN
          CALLFUNC ComPort.OnWriteString
         END IF
        ELSE
         IF ComPort.OnComError > 0 THEN
          CALLFUNC (ComPort.OnComError, ERROR_SENDING_DATA)
         END IF
        END IF
       END IF

      END SUB


  'Method ReadString
PUBLIC:
      FUNCTION ReadString (dwRdSize AS DWORD, intWait AS INTEGER) AS STRING

       DIM lngStatus     AS LONG
       DIM dwBytesRead   AS DWORD
       DIM strReadBuffer AS STRING

    'Make enough space in memory for ReadFile to put data in.
       strReadBuffer=SPACE$(ComPort.ReadBufSize)

    'Read data from buffer
       lngStatus = ReadFile(Comport.Handle, _				'was myport.handle, corrected
        strReadBuffer, _
        dwRdSize, _
        dwBytesRead, _
        0&)

       IF lngStatus = 0 THEN
        IF ComPort.OnComError > 0 THEN
         CALLFUNC (ComPort.OnComError, ERROR_READING_PORT & ComPort.FormatError)
        END IF
       ELSE

        Result = LEFT$(strReadBuffer, dwBytesRead)	  'Set Return value for this Function
		IF intWait THEN SLEEP.ms(intWait)			  'Wait for more data to arrive in buffer
        ComPort.GetCommStatus		                  'Get number of bytes now waiting to be read
        IF ComPort.OnReadString > 0 THEN              'Raise OnReadString event
         CALLFUNC ComPort.OnReadString
        END IF

       END IF
      END FUNCTION
END TYPE


' Just get it over, QCOMPORT does nothing
$DEFINE QCOMPORT COMPORT


'*******************************************************
'*****  END QCOMPORT extension
'*******************************************************





$IFNDEF __QMENU_INC
$DEFINE __QMENU_INC

'============================================================================================================
' QMenuEx an extended component based on Qmenu.inc by Jordi Ramos and D. Glodt  
'   uses the Ownerdrawn methods to draw bitmaps on MenuItems, requires callback messages
'   Version 1.2,    by John Kelly
'============================================================================================================
Declare Sub QM_OnMouseHover_eventTemplate(Xpos AS LONG, Ypos AS LONG, Descript AS STRING)

DIM gRQ2_MeasureItem AS MEASUREITEMSTRUCT
DIM gRQ2_DrawItem AS DRAWITEMSTRUCT



TYPE QMenuEx EXTENDS QIMAGELIST

    PUBLIC:
       Font 			AS QFONT
       MaskColor        AS LONG
       BackColor 		AS LONG
       ForeColor 		AS LONG
       DisabledColor 	AS LONG
       HighLightColor   AS LONG
       HighLightTextColor AS LONG
       Outline          AS LONG
       FontSize			AS WORD PROPERTY SET Set_FontSize
       Transparent      AS INTEGER
       TransparentColor AS INTEGER
       OnMouseHover		AS EVENT(QM_OnMouseHover_eventTemplate)

    PRIVATE:
       MenuParent       AS LONG           'MenuItem holding the sub menu
       Bmp 				AS QBITMAP        'holds the bitmap for drawing
       TextBMP  		AS QBITMAP        'need this for bug fix
       hWnd 			AS INTEGER
       MyWndProc        AS LONG           'for redirecting WndProc
       pOldProc 		AS LONG           'pass messages
       flagWinProc		AS LONG	          'already hooked WndProc?
       image(1000) 	    AS QBITMAP        'which QlistItem?
       descp(1000) 		AS STRING         'menu help string
       DescripFlag		AS WORD
       LastMenu  		AS LONG
       LastCount        AS INTEGER
       Margin           AS INTEGER

WITH QmenuEx       

     SUB ShowDescription (wParam AS LONG, LParam AS LONG, ID AS LONG)
         IF (lParam = 0) and ((wParam AND &HFFFF) = &HFFFF) then    ' The system has closed the menu
        ELSE
            CALLFUNC(.OnMouseHover, Screen.MouseX, Screen.MouseY, .descp(ID))
        END IF
     END SUB

           
     SUB DrawText (clr AS INTEGER)
          DIM S AS STRING
          DIM I AS WORD
          DIM tLeft AS LONG
          dim X as integer
          dim Y as integer

        S=VARPTR$(gRQ2_DrawItem.itemData)
        X=.width + .Margin
        if INSTR(S,"&")>0 then
          .Font.AddStyles(2)
          .bmp.Font=.Font
          Y=((gRQ2_DrawItem.bottom-gRQ2_DrawItem.top)-.bmp.TextHeight(S))\2  
          .Font.DelStyles(2)
          .bmp.Font=.Font
        else
          Y=((gRQ2_DrawItem.bottom-gRQ2_DrawItem.top)-.bmp.TextHeight(S))\2  
        end if
        I=INSTR(S, "&")
        IF I THEN
          .bmp.TextOut(gRQ2_DrawItem.left+X,gRQ2_DrawItem.top+Y,LEFT$(S, I-1),clr,-1)
          .Font.AddStyles(2)
          .bmp.Font=.Font
          .bmp.TextOut(gRQ2_DrawItem.left+X+.bmp.TextWidth(LEFT$(S, I-1)),gRQ2_DrawItem.top+Y,MID$(S, I+1, 1),clr,-1)
          .Font.DelStyles(2)
          .bmp.Font=.Font
          S=S - "&"
          .bmp.TextOut(gRQ2_DrawItem.left+X+.bmp.TextWidth(LEFT$(S, I)),gRQ2_DrawItem.top+Y,MID$(S, I+1, LEN(S)),clr,-1)
        ELSE
          .bmp.TextOut(gRQ2_DrawItem.left+X,gRQ2_DrawItem.top+Y,S,clr,-1)
        END IF
     END SUB

'       =========================================================
'            Windows messages callback
'       needs 5 param to bind to the Callback forwarder
'       =========================================================
     FUNCTION WindowProc (hwnd AS LONG, uMsg AS LONG, wParam AS LONG, lParam AS LONG, tmp AS LONG) AS LONG
     DIM h AS LONG:	h = .Height - 1
     DIM S AS STRING

      SELECT CASE uMsg
         CASE WM_MEASUREITEM   'windows wants the dimensions of the ownerdraw menu
			MEMCPY(gRQ2_MeasureItem, lParam, SIZEOF(gRQ2_MeasureItem))	'lParam points to struct
            IF gRQ2_MeasureItem.CtlType = ODT_MENU THEN     'don't handle listboxes, etc.
                S = VARPTR$(gRQ2_MeasureItem.itemData)      'get caption
'                gRQ2_MeasureItem.itemWidth = .TextBMP.TextWidth(S) + .width + .Margin   'get full width of menu item
                gRQ2_MeasureItem.itemWidth = LEN(S) * .Font.Size * 0.6 + .width + .Margin   'get full width of menu item
'                IF .TextBMP.TextWidth(S) > .Height THEN .Height = .TextBMP.TextHeight(S)
                gRQ2_MeasureItem.itemHeight = .Height + 3     '-- your items.
                MEMCPY(lParam, gRQ2_MeasureItem, SIZEOF(gRQ2_MeasureItem))
                RESULT = -1
            ELSE
				QmenuEx.WindowProc = CallWindowProc(QmenuEx.pOldProc, hwnd, uMsg, wParam, lParam)
            END IF

         CASE WM_DRAWITEM 
			MEMCPY(gRQ2_DrawItem, lParam, SIZEOF(gRQ2_DrawItem))	'lParam points to struct
            IF gRQ2_DrawItem.CtlType = ODT_MENU THEN
              QmenuEx.ShowDescription (wParam, LParam, gRQ2_DrawItem.itemID)
               .Bmp.Handle = gRQ2_DrawItem.hDC
               IF (ODS_SELECTED AND gRQ2_DrawItem.itemState) <> 0 THEN
                  'blank background
                  .Bmp.FillRect(gRQ2_DrawItem.left+1,gRQ2_DrawItem.top,gRQ2_DrawItem.right,gRQ2_DrawItem.bottom, .HighLightColor)
                    'put up the bitmap before the text
'                  .Bmp.Draw (gRQ2_DrawItem.left+1,gRQ2_DrawItem.top+1,.GetBMP(.image(gRQ2_DrawItem.itemID)))
                  .Bmp.Draw (gRQ2_DrawItem.left+1,gRQ2_DrawItem.top+1,.image(gRQ2_DrawItem.itemID).BMP)
                  IF .Outline THEN          'nice little lines around the bitmap
                     .Bmp.Line (gRQ2_DrawItem.left,gRQ2_DrawItem.top,gRQ2_DrawItem.left+h,gRQ2_DrawItem.top, &HFFFFFF)
                     .Bmp.Line (gRQ2_DrawItem.left,gRQ2_DrawItem.top,gRQ2_DrawItem.left,gRQ2_DrawItem.top+h, &HFFFFFF)
                     .Bmp.Line (gRQ2_DrawItem.left,gRQ2_DrawItem.top+h,gRQ2_DrawItem.left+h+1,gRQ2_DrawItem.top+h, &H808080)
                     .Bmp.Line (gRQ2_DrawItem.left+h,gRQ2_DrawItem.top+h,gRQ2_DrawItem.left+h,gRQ2_DrawItem.top, &H808080)
                   END IF
                   if (ODS_DISABLED AND gRQ2_DrawItem.itemState) <> 0 then    'selected a disabled menu
                     .DrawText(.DisabledColor)
                   else
                      .DrawText(.HighLightTextColor)                        'or not
                   end if
              ELSEIF(ODS_DISABLED AND gRQ2_DrawItem.itemState) <> 0 THEN 
                   .bmp.FillRect(gRQ2_DrawItem.left,gRQ2_DrawItem.top,gRQ2_DrawItem.right,gRQ2_DrawItem.bottom,.BackColor)
'                   .bmp.Draw(gRQ2_DrawItem.left+1,gRQ2_DrawItem.top+1, .GetBMP(.image(gRQ2_DrawItem.itemID)))
                   .bmp.Draw(gRQ2_DrawItem.left+1,gRQ2_DrawItem.top+1, .image(gRQ2_DrawItem.itemID).BMP)
                   .DrawText(.DisabledColor)
              ELSE
                  .Bmp.FillRect(gRQ2_DrawItem.left,gRQ2_DrawItem.top,gRQ2_DrawItem.right,gRQ2_DrawItem.bottom, .BackColor)
'                  .Bmp.Draw(gRQ2_DrawItem.left+1,gRQ2_DrawItem.top+1,.GetBMP(.image(gRQ2_DrawItem.itemID)))
                  .Bmp.Draw(gRQ2_DrawItem.left+1,gRQ2_DrawItem.top+1,.image(gRQ2_DrawItem.itemID).BMP)
                  .DrawText(.ForeColor)
               END IF
              Result = -1
            ELSE 
               QmenuEx.WindowProc = CallWindowProc(QmenuEx.pOldProc, hwnd, uMsg, wParam, lParam)
            END IF

         CASE WM_MENUSELECT
            IF QmenuEx.DescripFlag THEN
               QmenuEx.ShowDescription wParam, LParam, gRQ2_DrawItem.itemID 
            END IF
            QmenuEx.WindowProc = CallWindowProc(QmenuEx.pOldProc, hwnd, uMsg, wParam, lParam)
         CASE ELSE
            QmenuEx.WindowProc = CallWindowProc(QmenuEx.pOldProc, hwnd, uMsg, wParam, lParam)
          END SELECT
    END FUNCTION

    SUB ClearDescription
       DIM i AS WORD
       FOR i = 1 TO 1000
            .descp(i) = " "
       NEXT i
    END SUB

       
 PUBLIC:
    SUB Init(Form AS QFORM)		'this replaces 'Set'
       IF .flagWinProc = FALSE THEN
          .hWnd = form.Handle
          INC gRQ2_WndProcNum
          BIND gRQ2_WndProc(gRQ2_WndProcNum) TO QmenuEx.WindowProc
          .MyWndProc = gRQ2_SetNewCallBack(gRQ2_lpMasterWndProc, gRQ2_WndProcNum) 
          .pOldProc = SetWindowLong(form.Handle, GWL_WNDPROC, .MyWndProc)
          .flagWinProc = TRUE
        END IF
    END SUB


    FUNCTION Close () AS LONG
        RESULT = SetWindowLong(QMenuEx.hWnd, GWL_WNDPROC, QMenuEx.pOldProc)
    END SUB

    PROPERTY SET Set_FontSize(NewSize AS WORD)
        DIM nHeight AS LONG
        IF NewSize > 4 THEN
           .Font.Size = NewSize
           .FontSize = NewSize
           .Bmp.Font.Size= NewSize		'gotta do all...
           nHeight = .Bmp.TextHeight("A")
           IF .Height < nHeight THEN .Height = nHeight + 2
        END IF
    END PROPERTY


    SUB Parent(TheMenuParent AS QMENUITEM)
        IF TheMenuParent.Handle <> 0 THEN .MenuParent = TheMenuParent.Handle
    END SUB


    SUB AddBMPFile(MenuItem AS QMENUITEM, FileName$)
        .image(MenuItem.Command).LoadFromFile(FileName$)
        .image(.LastMenu).Transparent = .Transparent
        .image(.LastMenu).TransparentColor = .TransparentColor
    END SUB

    SUB ICOFile (MenuItem AS QMENUITEM, FileName$)
        .AddICOFile(FileName$)
        .image(MenuItem.Command).BMP = .GetICO(.Count-1)
        .image(.LastMenu).Transparent = .Transparent
        .image(.LastMenu).TransparentColor = .TransparentColor
        .LastCount = .Count
    END SUB


    FUNCTION AddDescription(MenuItem AS QMENUITEM, descripcion AS STRING) AS LONG
        DIM S AS STRING
        DIM flag as integer
        DIM tmpBMP AS QBITMAP

        RESULT = 0
        IF QMenuEx.MenuParent = 0 THEN Showmessage "no menu Parent": GOTO EXIT_FUNCTION
          S = MenuItem.caption
          flag = MF_BYPOSITION + MF_OWNERDRAW
          if MenuItem.Enabled = false then flag = flag + MF_DISABLED
          ModifyMenu(QMenuEx.MenuParent, MenuItem.MenuIndex, flag, MenuItem.Command, VARPTR(S))
          IF .DescripFlag = 0 THEN .DescripFlag = 1
          .descp(MenuItem.Command)= descripcion
          .LastMenu = MenuItem.Command
          IF .LastCount < .Count THEN
             .LastCount = .Count
            'QimageList doesn't know its own size! Let's figure it out
             tmpBMP.Width = 30 : tmpBMP.Height = 30        'create the bmp this way with start values
            .Draw(tmpBMP, 0,0,.Count)                     'draw the last one
            .Width = tmpBMP.width                         'now resize the components to the image
            .Height = tmpBMP.Height
         END IF
      EXIT_FUNCTION:
    END FUNCTION


      '==============================================
      ' Méthode ajoute un bitmap a l'item menu 
      '==============================================
    FUNCTION MenuModify(item as Qmenuitem, picture as QIMAGE, descripcion AS STRING) AS LONG
          dim capn as string
          dim S as string
          dim flag as integer

          RESULT = 0
          IF .MenuParent = 0 THEN Showmessage "no menu Parent": GOTO EXIT_FUNCTION
          capn = item.caption
          flag = MF_BYPOSITION + MF_OWNERDRAW
          if item.Enabled = false then flag=flag + MF_DISABLED
          ModifyMenu(.MenuParent, item.MenuIndex, flag, Item.Command, VARPTR(capn))
          .LastMenu = Item.Command
          .image(.LastMenu).bmp=picture.bmp
          .Width = .image(.LastMenu).width      'set the component width/height
          .Height = .image(.LastMenu).Height
          .image(.LastMenu).Transparent = .Transparent
          .image(.LastMenu).TransparentColor = .TransparentColor
          IF .DescripFlag = 0 THEN .DescripFlag = 1
          .descp(Item.Command)= descripcion
          RESULT = 1
      EXIT_FUNCTION:
    END FUNCTION


      '==============================================
      ' Méthode supprime un bitmap de l'item menu 
      '==============================================
      Sub DelBitmap(item as Qmenuitem)
        dim s as string
        dim flag as integer
      
        s = item.caption
        flag = MF_BYPOSITION + MF_STRING
        if item.Enabled = false then flag = flag+MF_DISABLED
        ModifyMenu(.MenuParent, item.MenuIndex, flag, Item.Command, VARPTR(s))
      End Sub

END WITH      

    CONSTRUCTOR
      Transparent = True
      TransparentColor = 0
      DescripFlag = 0
      ClearDescription
      Height = 18               'GetSystemMetrics(SM_CYMENU)
      Width = 18                'GetSystemMetrics(SM_CYMENU)
      flagWinProc = FALSE
      BackColor = clMenu		'GetSysColor(COLOR_MENU)
      ForeColor = clMenuText	'GetSysColor(COLOR_MENUTEXT)
      DisabledColor = GetSysColor(COLOR_GRAYTEXT)
      HighLightColor = GetSysColor(COLOR_HIGHLIGHT)
      HighLightTextColor = clMenuText
      OutLine = False
      Margin = 9
      LastCount = 0
    END CONSTRUCTOR
END TYPE 
$ENDIF









'============================================================================================
'  Class QFILEDIAGLOG   an Open or Save sizeable file dialog box with overwrite warning
'  Version 1.0 
'  11/2004 original code adapted from RQDIALOG.INC by   BILL K  1-2003
'  by JohnK
'============================================================================================
'
$IFNDEF _RQDIALOGINC
$DEFINE _RQDIALOGINC

$DEFINE fdOpen  0
$DEFINE fdSave  1
CONST fdStrTerm$ = CHR$(0) + CHR$(0)
CONST fdMaxFiles = 256

TYPE QFILEDIALOG EXTENDS QOBJECT
  PRIVATE:
	tmpFileName		AS STRING
	tmpFilter		AS STRING
	tmpFileTitle	AS STRING		'output string
	OFN				AS OPENFILENAME

  PUBLIC:
	Parent			AS LONG			'Parent form handle, can be NULL
	Caption 		AS STRING		' default is "Open" or "Save"
	Filter			AS STRING		'*.*
	FilterIndex		AS INTEGER		'0 based
	InitialDir		AS STRING
	Mode			AS INTEGER		'enum fdOpen = Open (default),  fdSave = save,
	WarnIfOverWrite	AS INTEGER		'warning to overwrite?
	Filename		AS STRING
	FileTitle		AS STRING
	DefaultExt		AS STRING
	MultiSelect 	AS INTEGER
	SelCount 		AS INTEGER
	NoChangeDir		AS INTEGER
	Files(fdMaxFiles) AS STRING

 CONSTRUCTOR
	Parent			= 0						'Parent form handle, can be NULL
	Caption 		= "Open" + STRING$(243, 0)
	Filter			= "All Files|*.*" + STRING$(243, 0)
	FilterIndex		= 0
	InitialDir		= STRING$(256, 0)		'allocate a fixed memory
	Mode			= 0						'enum 0 = Open (default), 1 = save,
	WarnIfOverWrite	= 1						'warning to overwrite?
	Filename		= STRING$(1024, 0)		'allocate memory only once!
	tmpFileName 	= STRING$(1024, 0)
	DefaultExt		= STRING$(256,  0)		'no default extension
	MultiSelect 	= 0
	SelCount 		= 0
	NoChangeDir		= 0
 END CONSTRUCTOR


 FUNCTION Execute() AS LONG
  DIM FndSpace1 	AS INTEGER
  DIM FndSpace2 	AS INTEGER
  DIM StrLenth		AS INTEGER
  DIM MyHresult		AS LONG			'return result


  WITH QFILEDIALOG
	.OFN.lStructSize = SIZEOF(QfileDialog.OFN)
	.OFN.hwndOwner = .Parent
	.OFN.hInstance = 0
	'file filter string, ends wtih 2 null chars
	IF RIGHT$(QFILEDIALOG.Filter, 2) <> fdStrTerm$ THEN QFILEDIALOG.Filter = QFILEDIALOG.Filter + fdStrTerm$
	.tmpFilter = REPLACESUBSTR$(.Filter, "|", CHR$(0))	'set up for API delimiter
	.OFN.lpstrFilter = VARPTR(QfileDialog.tmpFilter)	'use temp filter for conditioning
	.OFN.nFilterIndex = .FilterIndex
	IF .FileName = "" THEN 
		.tmpFileName = String$(1024,0)					'max 1024 chars for file input names
	ELSE
		.tmpFileName = .FileName
		' buffer with null and make string large just in case multiple select (must be > 256)
		IF LEN(.FileName) < 1024 THEN .tmpFileName = .tmpFileName + String$(1024-LEN(QfileDialog.FileName),0)
	END IF
	.OFN.lpstrFile = VARPTR(QfileDialog.tmpFileName)		'set pointer to input filename
	.OFN.nMaxFile = LEN(QfileDialog.tmpFileName)			'num chars to expect
	.tmpFileTitle = String$(1024,0)							'string that gets the result,without path
	.OFN.nMaxFileTitle = 1024								'set length
	.OFN.lpstrFileTitle = VARPTR(QfileDialog.tmpFileTitle)	'set pointers
	IF QfileDialog.InitialDir <> "" THEN
		.OFN.lpstrInitialDir = VARPTR(QfileDialog.InitialDir)		
	ELSE
		.OFN.lpstrInitialDir = 0&
	END IF

	.OFN.lpstrTitle = VARPTR(QfileDialog.Caption)
	IF .DefaultExt <> "" THEN .OFN.lpstrDefExt = VARPTR(QfileDialog.DefaultExt)
	IF .WarnIfOverWrite THEN
		.OFN.flags =OFN_HIDEREADONLY OR OFN_OVERWRITEPROMPT
	ELSE
		.OFN.flags =OFN_HIDEREADONLY
	END IF
	IF .MultiSelect THEN .OFN.flags = .OFN.flags OR OFN_ALLOWMULTISELECT OR OFN_EXPLORER
	IF .NoChangeDir THEN .OFN.flags = .OFN.flags OR OFN_NOCHANGEDIR

	SELECT CASE .Mode
	  CASE = fdOpen
		MyHresult = GetOpenFileName(QfileDialog.OFN)
	  CASE = fdSave
		MyHresult = GetSaveFileName(QfileDialog.OFN)	'runs dialog box
	  CASE ELSE
		ShowMessage "Invalid Mode in FileDialog"
	END SELECT


	IF MyHresult <> 0 THEN								'returns 0 on CANCEL
'		.tmpFileName = STRING$(.OFN.nMaxFile, 0)		'can't reallocate string memory!
		MEMCPY(VARPTR(QfileDialog.tmpFileName), QfileDialog.OFN.lpstrFile, QfileDialog.OFN.nMaxFile) 'get string
		StrLenth = INSTR(QfileDialog.tmpFileName, fdStrTerm$)		'find null terminator
		.FileTitle = STRING$(.OFN.nMaxFileTitle, 32)				'allocate
		MEMCPY(VARPTR(QfileDialog.FileTitle), QfileDialog.OFN.lpstrFileTitle, QfileDialog.OFN.nMaxFile)
		.FileTitle = LEFT$(.FileTitle, (INSTR(.FileTitle, fdStrTerm$))-1)

		IF .MultiSelect THEN
			.tmpFileName = LEFT$(QfileDialog.tmpFileName, StrLenth)
			.tmpFileName = REPLACESUBSTR$(.tmpFileName, CHR$(0), CHR$(255)) 'prevent string termination
			FndSpace1 = 1: 	FndSpace2 = 0
			.SelCount = -1								'for 0 indexing
			DO
				FndSpace2 = INSTR(FndSpace1, .tmpFileName, CHR$(255))		'null doesn't work, trick w/chr 255
				IF FndSpace2 = 0 THEN
					 EXIT DO
				ELSE
					.SelCount++
					.Files(.SelCount) = MID$(.tmpFileName, FndSpace1, (FndSpace2 - FndSpace1))
					FndSpace1 = FndSpace2 + 1
					IF .SelCount > fdMaxFiles THEN EXIT DO		'too many files
				END IF
			LOOP UNTIL FndSpace2 >= StrLenth
			.FileName = ""
			FOR FndSpace1 = 1 TO StrLenth - 1					'strip out null terminators
				FndSpace2 = ASC(MID$(.tmpFileName,FndSpace1, 1))
				IF (FndSpace2 <> 0) AND (FndSpace2 <> 255) THEN .FileName = .FileName + CHR$(FndSpace2)
			NEXT FndSpace1
			IF .SelCount = 0 THEN					'just one file selected in multiselect
				.Files(1) = .FileTitle				'keep compatibile with multiselect
				.Files(0) = .FileName - .FileTitle	'0 index is path
				.SelCount = 1						'need to update file was picked
			END IF
			IF RIGHT$(.Files(0),1) <>"\" THEN .Files(0)= .Files(0) + "\"

		ELSE
			.FileName = LEFT$(QfileDialog.tmpFileName, StrLenth-1)		'take out extra null char
		END IF
	 END IF

	RESULT = MyHresult
   END WITH
  END FUNCTION

END TYPE
$ENDIF ' _RQDIALOGINC







'================================================================================================
' Type Qobject 
'7/2005
' Class QColorDialog version 1.3, original by D. Glodt?, updated for RQ2 by JohnK
'================================================================================================

$DEFINE cdNormal 0          
$DEFINE cdFullOpen 1        
$DEFINE cdNoFullOpen 2


TYPE QCOLORDIALOG EXTENDS QOBJECT
  PRIVATE:
    CC 				AS CHOOSECOLOR
    MyWndProc       AS LONG

  PUBLIC:
    Caption			AS STRING
    Color 			AS LONG
    Colors(1 TO 16) AS LONG
    Style 			AS LONG 
	Left 			AS LONG
	Top				AS LONG


  WITH QCOLORDIALOG
         'can't redirected WndProc using RQ2_MasterWndProc, why?
      Function HookProc(hWnd AS LONG, uMsg AS LONG, wParam AS LONG, lParam AS LONG) AS LONG
        dim R as QRECT

        if uMsg=WM_INITDIALOG then  ' all initializing is done inside 
          GetWindowRect(hWnd,R)    ' this if-then statement
          IF (.Left >= 0) OR (.Top >=0) THEN
               MoveWindow(hWnd, .Left, .Top, (R.Right-R.Left),(R.Bottom-R.Top),0) 
          ELSE
	          MoveWindow(hWnd,((Screen.Width-(R.Right-R.Left))/2),((Screen.Height-(R.Bottom-R.Top))/2),(R.Right-R.Left),(R.Bottom-R.Top),0) 
          END IF
          if LEN(.Caption) then SetWindowText(hWnd, QCOLORDIALOG.Caption)
                Result=true
          else
                Result = false
          end if
      End Function

      '==========================================
      ' Méthode affichage boite dialogue couleur
      '==========================================
      Function Execute AS LONG
        dim i as long

        .CC.lStructSize=SIZEOF(QCOLORDIALOG.CC)            
        .CC.hWndOwner = Application.Handle
        .CC.RGBResult=.Color
        for i=1 to 16
          .CC.lpCustColors(i)=.Colors(i)
        next i
        .CC.Flags=CC_RGBINIT
        Select Case .Style
        case cdFullOpen
          .CC.Flags =.CC.Flags OR CC_FULLOPEN 
        case cdNoFullOpen
          .CC.Flags =.CC.Flags OR CC_PREVENTFULLOPEN
        End Select
        IF (.Caption <> "") THEN
            .CC.Flags=.CC.Flags OR CC_ENABLEHOOK
            .CC.lpfnHook = CODEPTR(QCOLORDIALOG.HookProc)
'            INC gRQ2_WndProcNum
'            .MyWndProc = gRQ2_SetNewCallBack(gRQ2_lpMasterWndProc, gRQ2_WndProcNum) 
'            BIND gRQ2_WndProc(gRQ2_WndProcNum) TO QCOLORDIALOG.HookProc
'            .CC.lpfnHook = .MyWndProc
        END IF
        if ChooseColorDlg(.CC) <> 0 then
          for i=1 to 16
          .Colors(i)=.CC.lpCustColors(i)
          next i
          .Color=.CC.RGBResult
          Result=true
        else
          Result=false
        end if
      End Function
                    
      CONSTRUCTOR
        Caption=""
        Left = Screen.Width\3
        Top = Screen.Height\3
        Colors(1)=&H0
        Colors(2)=&H808080
        Colors(3)=&H000080
        Colors(4)=&H008080
        Colors(5)=&H008000
        Colors(6)=&H808000
        Colors(7)=&H800000
        Colors(8)=&H800080
        Colors(9)=&HFFFFFF
        Colors(10)=&HC0C0C0
        Colors(11)=&H0000FF
        Colors(12)=&H00FFFF
        Colors(13)=&H00FF00
        Colors(14)=&HFFFF00
        Colors(15)=&HFF0000
        Colors(16)=&HFF00FF
		Top = -1
		left = -1
      END CONSTRUCTOR
    END WITH
END TYPE






'================================================================================================
'  Class QDriveCombobox  By D Glodt
'  Add a combobox of drives to your form
'================================================================================================


TYPE QDriveComboBox EXTENDS QComboBox
  '=========================================
  ' méthode reception des lecteurs présents
  '=========================================
  SUB GetDrives
   dim ASC_A as integer
   dim ASC_Z as integer
   dim i as integer
   dim name as string
   
   ASC_A=65
   ASC_Z=ASC_A+25
   for i=ASC_A to ASC_Z
     if GetDriveType(Chr$(i)&":\")<>1 then
       name=chr$(i)+":\"
       QDriveComboBox.AddItems name
     end if
   next i
   QDriveComboBox.ItemIndex=0
  END SUB
  
  SUB AddItems		'these overwrite methods!
  END SUB
  
  SUB DelItems
  END SUB
  
  SUB Clear
  END SUB

  '-- Default values
  CONSTRUCTOR
  END CONSTRUCTOR
END TYPE  






'================================================================================================
' QAbout Object component 
' version 1.2 (D. Glodt)
' simple way to make an application "About" box
'=================================================================================================

Type QAbout EXTENDS QOBJECT
  private:
    form as QFORM
    BtOk as QBUTTON
    cadre as QGROUPBOX
    label1 as QLABEL
    label2 as QLABEL
    label3 as QLABEL
    label4 as QLABEL
    width as short
    height as short
    send as string
  public: 
    image as QIMAGE
    Caption as string
    AppName as string
    AppVersion as string
    text as string
    Email as string
    Web as string
    AppFont as QFont
    TextFont as QFont
    EmailFont as QFont
    WebFont as QFont
     
  '==================================
  ' Méthode affichage boite dialogue
  '==================================
  Sub Show
    with QAbout
      'definition image
      .image.parent=.cadre
      .image.top=15
      .image.left=10
      .image.autosize=true
      'definition label1
      .label1.autosize=true
      .label1.left=.image.left+.image.width+20
      .label1.font=.AppFont
      .label1.caption=.AppName
      if .AppVersion<>"" then
        if .AppName<>"" then .label1.caption=.label1.caption+chr$(13)
        .label1.caption=.label1.caption+"Version "+.AppVersion
      end if
      if .image.height>.label1.height then
        .label1.top=int((.image.height-.label1.height)/2)+.image.top
        .height=.image.top+.image.height
      else
        .label1.top=.image.top
        .height=.label1.top+.label1.height
      end if
      .label1.parent=.cadre
      'definition label2
      if .text<>"" then
        .label2.autosize=true
        .label2.font=.TextFont
        .label2.caption=.text
        .label2.left=10
        .label2.top=.height+10
        .height=.label2.top+.label2.height
        .label2.parent=.cadre
      end if
      'definition label3
      if .Email<>"" then
        .label3.autosize=true
        .label3.Font=.EmailFont
        if .label3.Font.Color=-2147483640 then .label3.Font.Color=&HFF0000
        .label3.Cursor=-21
        .label3.caption="Email:"+.Email
        .label3.left=10
        .label3.top=.height+10
        .height=.label3.top+.label3.height
        .label3.parent=.cadre
      end if
      'definition label4
      if .Web<>"" then
        .label4.autosize=true
        .label4.Font=.WebFont
        if .label4.Font.Color=-2147483640 then .label4.Font.Color=&HFF0000
        .label4.Cursor=-21
        .label4.caption="Web:"+.Web
        .label4.left=10
        .label4.top=.height+10
        .height=.label4.top+.label4.height
        .label4.parent=.cadre
      end if
      'definition cadre
      .cadre.top=5
      .cadre.left=10
      .width=(.label1.left+.label1.width)
      if .text<>"" then
        if (.label2.left+.label2.width)>.width then .width=(.label2.left+.label2.width)
      end if
      if .Email<>"" then
        if (.label3.left+.label3.width)>.width then .width=(.label3.left+.label3.width)
      end if
      if .Web<>"" then
        if (.label4.left+.label4.width)>.width then .width=(.label4.left+.label4.width)
      end if
      .width=.width+20
      .cadre.width=.width
      .cadre.height=.height+10
      .cadre.parent=.form
      .label2.left=(.width-.label2.width)/2
      .label3.left=(.width-.label3.width)/2
      .label4.left=(.width-.label4.width)/2
      'definition form
      .form.width=.cadre.left+.cadre.width+15
      .form.height=.cadre.top+.cadre.height+60
      .form.borderstyle=3
      .form.caption=.caption
      .form.center
      'definition bouton
      .BtOk.parent=.form
      .BtOk.caption="Ok"
      .BtOk.default=1
      .BtOk.top=.form.clientheight-.BtOk.height-5
      .BtOk.left=int((.form.clientwidth-.BtOk.width)/2)
      .form.showModal
    end with
  End Sub

  Event BtOk.OnClick
    QAbout.form.modalresult=1
  End Event

  Event label3.OnClick
    QAbout.send="mailto:"+QAbout.Email
    ShellExecute(0,"open",QAbout.send,"","",1)
  End Event

  Event label4.OnClick
    if instr(LCASE$(QAbout.Web),"http")=0 then
      QAbout.send="http://"+QAbout.Web
    else
      QAbout.send=QAbout.Web
    end if
    ShellExecute(0,"open",QAbout.send,"","",1)
  End Event

  Constructor
    image.transparent=true
    text=""
    Email=""
    Web=""
  End Constructor
END TYPE








'====================================================================================================================
'------- QDebug object , useful for debugging in loops  --------------
' JohnK, 12/2004
'Adapted from code by Pete Kleinschmidt and Michael Zito 1-5-2004, and Andrew Shelkovenko
' Method "Bug" left in
'======================================================================================================================
                                                                  'If window was not previously disabled, the return value is 0

TYPE QDebug EXTENDS QObject						'Begin defining our QDebug object
  PRIVATE:
	RowNum		AS INTEGER
	Redit		AS QRICHEDIT

  PUBLIC:
	Visible 	AS LONG 	PROPERTY SET Set_Visible
	Enabled		AS LONG 	PROPERTY SET Set_Enabled
	Form 		AS QFORM							'Create our Debug form
	TestSockets	AS INTEGER							'also use WSAGetLastError


	PROPERTY SET Set_Visible(VisibleValue AS LONG)   'Property Set for Visible property
   		IF VisibleValue = 1 THEN                      'If Visible property is set to True
      		THIS.Form.Show                         'Then show our Debug window
			THIS.Redit.Parent = THIS.Form
			EnableWindow(THIS.Form.Handle, THIS.Enabled)
	    ELSE                                          'Otherwise
		'	EnableWindow(THIS.Form.Handle, 1)
			THIS.Form.Close                        'Close the Debug window if it is open
		END IF
	END PROPERTY

	PROPERTY SET Set_Enabled(EnabledValue AS LONG)   '0 =  fixed/read-only, 1 = Debug window to move/close etc.
		THIS.Enabled = EnabledValue
		IF THIS.Form.Visible THEN EnableWindow(THIS.Form.Handle, THIS.Enabled)
	END PROPERTY
  
	SUB PrintWrap (StringToPrint AS STRING)             'wrap around text in form
		DIM RowHeight	AS INTEGER
		DIM NewStr 		AS STRING
		IF QDebug.Visible = 1 THEN                      'If Debug Visible property is True
			IF THIS.Form.Visible = 0 THEN THIS.Form.Show
			IF THIS.Redit.Visible THEN THIS.Redit.Visible= 0		'Print onto Form instead
			NewStr = StringToPrint + SPACE$(THIS.Form.ClientWidth)  'Clear out previous
			RowHeight = THIS.Form.TextHeight(NewStr)
			INC(THIS.RowNum, RowHeight)
			IF THIS.RowNum> (THIS.Form.ClientHeight - RowHeight) THEN THIS.RowNum = 0
			THIS.Form.TextOut(0, THIS.RowNum, NewStr, 0, &HFFFFFF)
			EnableWindow(THIS.Form.Handle, THIS.Enabled)
			DOEVENTS                                      'in case inside a loop
		END IF
	END SUB

	SUB PrintStr(StringToPrint AS STRING)                 		'Debug Str Print method
		IF QDebug.Visible = 1 THEN                        		'If Debug Visible property is True
			IF THIS.Form.Visible = 0 THEN
				THIS.Form.Show						  		'turn it on
				THIS.Redit.Parent = THIS.Form		  		'need to set parent
				THIS.Redit.Visible = 1		'Turn it back on
				THIS.Redit.Height  = THIS.Form.ClientHeight 'always resize
				THIS.Redit.Width   = THIS.Form.ClientWidth
			END IF
			THIS.Redit.AddStrings(StringToPrint)             'Add the value to our Richedit box
			THIS.Redit.SelStart=LEN(THIS.Redit.Text)         'Move the cursor to the last character in the RichEdit box
			'send message to richedit control to scroll so cursor is in view (&HB7 = EM_SCROLLCARET)
			SENDMESSAGE(THIS.Redit.handle, &HB7, 0, 0)
			EnableWindow(THIS.Form.Handle, THIS.Enabled) 'enable mouse and keyboard input to the Debug form.
			DOEVENTS                                          'Let Windows do stuff
		END IF
	END SUB

	SUBI Print(...)
		DIM TheWholeStr AS STRING
		DIM i AS INTEGER
		DIM j AS INTEGER

		TheWholeStr = ""
		j = ParamStrCount
		IF ParamValCount > ParamStrCount THEN j = ParamValCount	'more strings or variables?
		FOR i = 1 TO j
			IF i<= ParamStrCount THEN TheWholeStr = TheWholeStr + ParamStr$(i) + " "
			IF i<= ParamValCount THEN TheWholeStr = TheWholeStr + STR$(ParamVal(i)) + " "
		NEXT i
		THIS.PrintStr(TheWholeStr)
	END SUBI


	SUB Bug (StringToPrint AS STRING)		'keep compatible with previous release
		THIS.PrintStr(StringToPrint)
	END SUB

	SUB SetError(NewErr AS LONG)
		SetLastError(NewErr)
    END SUB
	
	FUNCTION ErrNum() AS DWORD				'get windows last error
		DIM Rtn AS DWORD

		IF THIS.TestSockets THEN
			Rtn = WSAGetLastError
		ELSE
			Rtn = GetLastError()
		END IF
		THIS.Print(Rtn)
		RESULT = Rtn
	END FUNCTION


    FUNCTION Err$		 AS STRING			'ripped off from format message
       DIM Buffer        AS STRING
       DIM lngRet        AS LONG

       Buffer=SPACE$(512)
       lngRet=FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM, _
        0&, _
        GetLastError(), _
        LANG_NEUTRAL, _
        @Buffer, _
        LEN(Buffer), _
        0&)
		THIS.Print(LEFT$(Buffer,lngRet))		
		RESULT = LEFT$(Buffer,lngRet)
   END FUNCTION


   CONSTRUCTOR
		RowNum = 0
		Visible = 1             'Default to Visible
		Enabled = 1				'User wants to scroll/close/etc.
		Form.AutoScroll = 1
		Form.Height = 600
		Form.Width = 180
		Form.Caption = "Debug"
		Redit.Scrollbars = 2	'ssVertical = 2, ssBoth = 3
		TestSockets = 0			'no testing of Win Sockets
		SetError(0&)			'clear out previous error
	END CONSTRUCTOR
END TYPE





'====================================================================================================================
'------- QlistviewEx object  Comma separated value (CSV) file and sorting support  --------------
' |                               |
' |   QlistviewEx Component by    |
' |                               |
' | Dreadsoft® Corporation        |
' | (manco un diritto riservato)  |
' | http://dreadsoft.too.it       |
' | dreadsoft@yahoo.it            |
' |                               |
' |  minor GLOBAL var modification|
' |  by JohnK, don't define       |
' |  variables at GLOBAL level!   |
' |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

'======================================================================================================================
TYPE Qlistviewex EXTENDS Qlistview
	ParentPanel 	as qpanel
	Header 			as qpanel
	ColHeader(100) 	as Qcoolbtn
	csv 			as qstringlist
	csvFile 		as string
	Separator 		as string
	Columns_count 	as integer
	FlatHeaders 	as integer

	'set properties for ParentPanel since this controls object
'	Parent			as QFORM	PROPERTY SET Set_Parent    'doesn't work...
	Top				as long		PROPERTY SET Set_Top
	Left			as long		PROPERTY SET Set_Left
	Width			as long		PROPERTY SET Set_Width
	Height			as long		PROPERTY SET Set_Height
	Visible			as long		PROPERTY SET Set_Visible



PRIVATE:
	lx				as integer	'were Global vars
	ly				as integer	'should keep them
	ix				as integer	'as private
	iy				as integer	'with component

PUBLIC:

CONSTRUCTOR
   with parentpanel
   .borderstyle = 0
   .bevelouter = 0
   end with

   with header
   .parent = Qlistviewex.parentpanel
   .height = 20
   .align = alTop
   .bevelouter = 0
   .borderstyle = 0
   end with

	Columns_Count = 0
	separator = ";"
	showcolumnheaders = 0
	FlatHeaders = 1
END CONSTRUCTOR

' The ParentPanel needs these set, not QlistViewEX
'  PROPERTY SET Set_Parent(Phandle AS QFORM)
'		THIS.parentpanel.Parent = Phandle
'  END PROPERTY

  PROPERTY SET Set_Top(mTop AS LONG)
		THIS.parentpanel.Top = mTop
  END PROPERTY

  PROPERTY SET Set_Left(mLeft AS LONG)
		THIS.parentpanel.Left = mLeft
  END PROPERTY

  PROPERTY SET Set_Width(mWidth AS LONG)
		THIS.parentpanel.Width = mWidth
  END PROPERTY

  PROPERTY SET Set_Height(mHeight AS LONG)
		THIS.parentpanel.Height = mHeight
  END PROPERTY

  PROPERTY SET Set_Visible(mVisible AS LONG)
		THIS.parentpanel.Visible = mVisible
  END PROPERTY


'============================================================
function FieldsCount as integer
	result = tally(Qlistviewex.csv.item(0), Qlistviewex.Separator) + 1
end function


'============================================================|
'Clear method is very slow if you use a lot of items,        |
'expecially if you select the last ones.                     |
Sub FastClear
defint oldviewstyle,oldfontsize
oldfontsize = Qlistviewex.font.size
oldviewstyle = Qlistviewex.viewstyle
    with QlistviewEx
    .viewstyle = 1
    .font.size = 1
    .clear
    .font.size = oldfontsize
    .viewstyle = oldviewstyle
    end with
end sub
'============================================================|
'Loading can be done ONLY from the CSV stringlist, so if you |
'want to load data from a File o a Qfilestream or            |
'Qmemorystream you'll have pass data to CSV and then call    |
'the load load function                                      |

sub load
QListviewEx.fastclear

dim field as string
qlistviewex.sorttype = 0
THIS.ly = Qlistviewex.csv.itemcount


for THIS.lx = 0 to (THIS.ly - 1)
    with qlistviewex
    field = field$(.CSV.item(.lx), .separator, 1)
    if field = "" then field = "-"

    .additems field
    .iy = .fieldscount

       for THIS.ix = 2 to THIS.iy
       field = field$(.CSV.item(THIS.lx), .separator, THIS.ix)
       if field = "" then field = "-"
       .addsubitem (THIS.lx, field)
       next
   end with
next
end sub
'============================================================|
sub loadfromcsvfile
	QlistviewEx.csv.loadfromfile(QlistviewEx.csvFile)
	QlistviewEx.load
end sub


'============================================================|
'Call this function passing a column header caption as       |
'variable                                                    |

sub Sortby (Criterium as string)
	THIS.iy = QlistviewEx.Fieldscount
	THIS.ly = QlistviewEx.Itemcount

   FOR THIS.ix = 0 to (THIS.iy - 1)
       if QlistviewEx.column(THIS.ix).caption = Criterium then
       IF THIS.ix <> 0 THEN
           with QlistviewEx
              .sorttype = 0
              THIS.lx = 0
              do
                  swap (.item(THIS.lx).caption, .subitem(THIS.lx, THIS.ix - 1))
                  inc(THIS.lx)
              loop until THIS.lx = (THIS.ly)
        
              .sorttype = 2
              .sorttype = 0
              THIS.lx = 0
              do
                  swap (.item(THIS.lx).caption, .subitem(THIS.lx, THIS.ix - 1))
                  inc(THIS.lx)
              loop until THIS.lx = (THIS.ly)
           end with
        ELSE
           QlistviewEx.sorttype = 2
        END IF
       End if
   NEXT THIS.ix
end sub


'============================================================|
'This sub can exclude unwanted items from list. You'll have  |
'to pass the column number (the first column is number 0) and|
'the string contained in the items you want to remove.       |
' ** Note ** it's NOT case sensitive                         |

Sub Exclude (Column as integer, Criterium as string)
Criterium = ucase$(criterium)

  if column = 0 then
  with QlistviewEx
  THIS.lx = 0
  THIS.ly = .itemcount
  do
    if ucase$(.item(THIS.lx).caption) = Criterium then
    .delitems(THIS.lx)
    dec(THIS.lx)
    dec(THIS.ly)
    end if
  inc(THIS.lx)
  loop until THIS.lx = THIS.ly
  end with
  else
  with QlistviewEx
  THIS.lx = 0
  THIS.ly = .itemcount
  do
    if ucase$(.subitem(THIS.lx, Column - 1)) = Criterium then
    .delitems(THIS.lx)
    dec(THIS.lx)
    dec(THIS.ly)
    end if
  inc(THIS.lx)
  loop until THIS.lx = THIS.ly
  end with
  end if
end sub
'============================================================|
'Called when user clicks on a column header                 |

sub columnclick (hcapt as qcoolbtn)
	Qlistviewex.sortby (hcapt.caption)
end sub



'============================================================|
'You'll have to call this sub every time you want to update  |
'QlistviewEx layout (so every time you change column caption,|
'width, etc...  Error with Parent control                    |
sub draw()
    qlistviewex.parent = Qlistviewex.parentpanel
    qlistviewex.align = alClient
    qlistviewex.viewstyle = 3
    qlistviewex.gridlines = 1

	THIS.ix = 0
	THIS.iy = Qlistviewex.Columns_Count
	if THIS.iy <> 0 then
	do
	 qlistviewex.ColHeader(THIS.ix).caption = qlistviewex.column(THIS.ix).caption
	 qlistviewex.ColHeader(THIS.ix).width = qlistviewex.column(THIS.ix).width
	 if THIS.ix = 0 then qlistviewex.ColHeader(THIS.ix).width = qlistviewex.column(THIS.ix).width + 2
	 qlistviewex.colheader(THIS.ix).parent = qlistviewex.header
	 qlistviewex.colheader(THIS.ix).align = alLeft
	 qlistviewex.colheader(THIS.ix).flat = qlistviewex.Flatheaders
	 qlistviewex.colheader(THIS.ix).onclick = Qlistviewex.columnclick
	inc(THIS.ix)
	loop until THIS.ix = THIS.iy
    end if
end sub


'============================================================|
'Use this to add columns, istead of the addcolumns method.   |
'Just pass columns names in a single string, separated by  a |
'"/" (See example)                                           |

sub addcol (coltoadd as string)
	THIS.lx = 0
	THIS.ly = (tally(coltoadd, "/") + 1)
	do
	 with QlistviewEx
	 .addcolumns field$(coltoadd, "/", THIS.lx + 1)
	 .Columns_count = (.Columns_count + 1)
	 end with
	inc(THIS.lx)
	loop until THIS.lx = THIS.ly
	QlistviewEx.draw
end sub


'============================================================|
' Update CSV Qstringlist with data contained in Qlistviewex. |
sub updatecsv
	dim stringtoadd as string
	THIS.lx = 0
	THIS.ly = QlistviewEx.itemcount
	THIS.iy = QlistviewEx.Fieldscount - 1
	QlistviewEx.csv.clear
	do
		with QlistviewEx
		stringtoadd = .item(THIS.lx).caption
		  THIS.ix = 0
 	 	 do
 		 stringtoadd = stringtoadd + .separator + .subitem(THIS.lx, THIS.ix)
 		 inc(THIS.ix)
 	  	loop until THIS.ix = THIS.iy
		stringtoadd = replacesubstr$(stringtoadd, (.separator + "-" + .separator), _
		(.separator + .separator))
		.csv.additems stringtoadd
		end with
		inc(THIS.lx)
	loop until THIS.lx = THIS.ly
end sub


'============================================================|
sub filter (Column as integer, criterium  as string)
	criterium = ucase$(criterium)
	THIS.lx = 0
	THIS.ly = QlistviewEx.itemcount
  do
     select case column
       case 0
          if ucase$(THIS.item(THIS.lx).caption) = criterium then
          else
          THIS.delitems(THIS.lx)
          dec(THIS.lx)
          dec(THIS.ly)
          end if
       case else
          if ucase$(THIS.subitem(THIS.lx, column - 1)) = criterium then
          else
          THIS.delitems(THIS.lx)
          dec(THIS.lx)
          dec(THIS.ly)
          end if
      end select
	inc(THIS.lx)
  loop until THIS.lx = THIS.ly
end sub



'============================================================|
sub SaveToCsvFile
    With QlistviewEx
    .updateCSV
    .csv.savetofile (.csvfile)
    end with
end sub


'============================================================|
sub SaveToFileAs
Dim ulvexdlg as Qsavedialog
if ulvexdlg.execute then
   with QlistviewEx
   .csv.savetofile (ulvexdlg.filename)
   end with
end if
end sub


'============================================================|
sub DirectSaveAs
  Dim dsavedlg as Qsavedialog
  dim tempfsstring as string

 if dsavedlg.execute then
   dim Direct_Save_FS as qfilestream
   Direct_Save_FS.open(dsavedlg.filename, 65535)
      with QlistviewEx
      THIS.lx = 0
      THIS.ly = .itemcount
      do
      tempfsstring = ""
      tempfsstring = .item(THIS.lx).caption

         THIS.iy = .fieldscount - 1
         THIS.ix = 0
         do
         tempfsstring = tempfsstring + .separator + .subitem(THIS.lx, THIS.ix)
         inc(THIS.ix)
         loop until THIS.ix = THIS.iy

      Direct_Save_FS.writeline(tempfsstring)
      inc(THIS.lx)
      loop until THIS.lx = THIS.ly
      end with
   Direct_Save_FS.close
  end if
end sub

END TYPE




'===========================================================================================|
' Printer Page Setup, added to RapidQ2 because of CodePtr handling
' Classe QPageSetup version 1.3
' original code D. Glodt, modified by John Kelly 8/2005
'===========================================================================================|

' these are renamed windows constants, to prevent conflicts
$DEFINE PSD_DEFAULTMINMARGINS   0
$DEFINE PSD_MINMARGINS   &H1
$DEFINE PSD_MARGINS   &H2
$DEFINE PSD_INTHOUSANDTHSOFINCHES   &H4
$DEFINE PSD_INHUNDREDTHSOFMILLIMETERS   &H8
$DEFINE PSD_DISABLEMARGINS   &H10
$DEFINE PSD_DISABLEPRINTER   &H20
$DEFINE PSD_NOWARNING   &H80
$DEFINE PSD_DISABLEORIENTATION   &H100
$DEFINE PSD_DISABLEPAPER   &H200
$DEFINE PSD_RETURNDEFAULT   &H400
$DEFINE PSD_SHOWHELP   &H800
$DEFINE PSD_ENABLEPAGESETUPHOOK   &H2000
$DEFINE PSD_ENABLEPAGESETUPTEMPLATE   &H8000
$DEFINE PSD_ENABLEPAGESETUPTEMPLATEHANDLE   &H20000
$DEFINE PSD_ENABLEPAGEPAINTHOOK   &H40000
$DEFINE PSD_DISABLEPAGEPAINTING   &H80000
$DEFINE PSD_NONETWORKBUTTON   &H200000
$DEFINE WM_INITDIALOG_PSD &H110


TYPE TPSD
  lStructSize AS LONG
  hWndOwner AS LONG
  hDevMode AS LONG
  hDevNames AS LONG
  Flags AS LONG
  ptPaperSizeX AS LONG
  ptPaperSizeY AS LONG
  rtMinMarginLeft AS LONG
  rtMinMarginTop AS LONG
  rtMinMarginRight AS LONG
  rtMinMarginBottom AS LONG
  rtMarginLeft AS LONG
  rtMarginTop AS LONG
  rtMarginRight AS LONG
  rtMarginBottom AS LONG
  hInstance AS LONG
  lParam AS LONG
  lpfnPageSetupHook AS LONG
  lpfnPagePaintHook AS LONG
  lpPageSetupTemplate AS LONG
  hPageSetupTemplate AS LONG
END TYPE



$IFNDEF __WIN32API				   'windows 32 definitions
  DECLARE FUNCTION PageSetupDlg LIB "COMDLG32" ALIAS "PageSetupDlgA" (Ptr AS TPSD) AS LONG
$ENDIF

Type QPageSetup EXTENDS QOBJECT
  Private:
    PSD AS TPSD
    MyWndProc AS LONG
  Public:
    Caption as string
    DisablePrinter as boolean
    DisablePaper as boolean
    DisableOrient as boolean
    DisableMargins as boolean
    Orientation as boolean PROPERTY SET SetOrientation
    MarginLeft as long PROPERTY SET SetMarginLeft
    MarginTop as long PROPERTY SET SetMarginTop
    MarginRight as long PROPERTY SET SetMarginRight
    MarginBottom as long PROPERTY SET SetMarginBottom
    PageWidth as long PROPERTY SET SetPageWidth
    PageHeight as long PROPERTY SET SetPageHeight


  Private:

  '=============================================
  ' Procédure boite de dialogue, 5 parameters to handle new WndProc
  '============================================= 
  Function HookProc(hWnd AS LONG, uMsg AS LONG, wParam AS LONG, lParam AS LONG, tmp as long) AS LONG
    dim R as QRECT

    if uMsg=WM_INITDIALOG_PSD then 
      GetWindowRect(hWnd,R)
      MoveWindow(hWnd,((Screen.Width-(R.Right-R.Left))/2),((Screen.Height-(R.Bottom-R.Top))/2),(R.Right-R.Left),(R.Bottom-R.Top),0) 
      if LEN(QPageSetup.Caption) then
        SetWindowText(hWnd,QPageSetup.Caption)
      end if
      Result=true
    else
      Result=false
    end if
  End Function

  Public:
  
  '=============================================
  ' Proprieté orientation page en lecture seule 
  '============================================= 
  PROPERTY SET SetOrientation(value as boolean)
  END PROPERTY
    
  '===============================================
  ' Proprieté valeur marge gauche 
  '=============================================== 
  PROPERTY SET SetMarginLeft(value as long)
    QPageSetup.PSD.rtMarginLeft=value*100
  END PROPERTY
    
  '===============================================
  ' Proprieté valeur marge haute 
  '=============================================== 
  PROPERTY SET SetMarginTop(value as long)
    QPageSetup.PSD.rtMarginTop=value*100
  END PROPERTY

  '===============================================
  ' Proprieté valeur marge droite 
  '=============================================== 
  PROPERTY SET SetMarginRight(value as long)
    QPageSetup.PSD.rtMarginRight=value*100
  END PROPERTY
   
  '===============================================
  ' Proprieté valeur marge basse 
  '=============================================== 
  PROPERTY SET SetMarginBottom(value as long)
    QPageSetup.PSD.rtMarginBottom=value*100
  END PROPERTY

  '===============================================
  ' Proprieté largeur page en lecture seule 
  '=============================================== 
  PROPERTY SET SetPageWidth(value as boolean)
  END PROPERTY
            
  '===============================================
  ' Proprieté hauteur page en lecture seule 
  '=============================================== 
  PROPERTY SET SetPageHeight(value as boolean)
  END PROPERTY

    
  '===========================================
  ' Méthode affichage mise en page imprimante
  '===========================================
  Function Execute as boolean
    QPageSetup.PSD.lStructSize = SIZEOF(QPageSetup.PSD)
    QPageSetup.PSD.hWndOwner=Application.handle
    QPageSetup.PSD.Flags=PSD_MARGINS+PSD_MINMARGINS
    if QPageSetup.Caption<>"" then
      QPageSetup.PSD.Flags=QPageSetup.PSD.Flags+PSD_ENABLEPAGESETUPHOOK
'      QPageSetup.PSD.lpfnPageSetupHook=CODEPTR(QPageSetup.HookProc)
      INC gRQ2_WndProcNum             'set the index #
      'new address to function that forwards to MasterWndProc, Function is an allocated heap space
      QPageSetup.PSD.lpfnPageSetupHook = gRQ2_SetNewCallBack(gRQ2_lpMasterWndProc, gRQ2_WndProcNum) 
      QPageSetup.MyWndProc = gRQ2_SetNewCallBack(gRQ2_lpMasterWndProc, gRQ2_WndProcNum) 
    ' QPageSetup.pOldProc=SetWindowLong(QPageSetup.handle,GWL_WNDPROC, QPageSetup.MyWndProc)   'subclass
      BIND gRQ2_WndProc(gRQ2_WndProcNum) TO QPageSetup.HookProc
     end if
    if QPageSetup.DisablePrinter then
      QPageSetup.PSD.Flags=QPageSetup.PSD.Flags+PSD_DISABLEPRINTER
    end if
    if QPageSetup.DisablePaper then
      QPageSetup.PSD.Flags=QPageSetup.PSD.Flags+PSD_DISABLEPAPER
    end if
    if QPageSetup.DisableOrient then
      QPageSetup.PSD.Flags=QPageSetup.PSD.Flags+PSD_DISABLEORIENTATION
    end if
    if QPageSetup.DisableMargins then
      QPageSetup.PSD.Flags=QPageSetup.PSD.Flags+PSD_DISABLEMARGINS
    end if
    if PageSetupDlg(QPageSetup.PSD) then
      QPageSetup.Execute=true
      QPageSetup.PageWidth=Round(QPageSetup.PSD.ptPaperSizeX/100)
      QPageSetup.PageHeight=Round(QPageSetup.PSD.ptPaperSizeY/100)
      if QPageSetup.PageWidth>QPageSetup.PageHeight then
        QPageSetup.Orientation=true
      else
        QPageSetup.Orientation=false
      end if
      QPageSetup.MarginLeft=QPageSetup.PSD.rtMarginLeft/100
      QPageSetup.MarginTop=QPageSetup.PSD.rtMarginTop/100
      QPageSetup.MarginRight=QPageSetup.PSD.rtMarginRight/100
      QPageSetup.MarginBottom=QPageSetup.PSD.rtMarginBottom/100
    else
      QPageSetup.Execute=false
    end if
  End Function
    
  Constructor
    Caption=""
    DisablePrinter=false
    DisablePaper=false
    DisableOrient=false
    DisableMargins=false
  End Constructor
End Type

'===============================================================================================






'====================================================================================================================
'------- APPLICATION object Commands extended --------------
'====================================================================================================================

FUNCTION Application.Path() AS STRING		'gets the program name without path
	DIM MyPath		AS STRING					'the path this program is running in
	DIM PathLen		AS INTEGER

	MyPath = Command$(0)
	MyPath = LEFT$(MyPath, LEN(MyPath) - LEN(Application.ExeName))	'extract path before exe name
	PathLen = LEN(MyPath)

	IF PathLen > 3 THEN							'dont remove slash from c:\ --sorry LINUX your on your own
		MyPath = LEFT$(MyPath, PathLen-1)		'else get rid of last slash in folder
	END IF
	RESULT = MyPath
END FUNCTION



FUNCTION Application.SetPriority(MyPriority AS LONG) AS LONG
	DIM hProcess As LONG			'application process handle
	DIM hR		 AS LONG
    hProcess = GetCurrentProcess    'retrieve the current thread and process
    hR = SetPriorityClass(hProcess, MyPriority)			'return 0 on FAIL
	RESULT = hR						'don't use Application.SetPriority = !!
END FUNCTION


FUNCTION Application.GetPriority() AS LONG
	DIM hProcess As LONG			'application process handle
	DIM hR		 AS LONG
    hProcess = GetCurrentProcess    'retrieve the current thread and process
	hR = GetPriorityClass(hProcess)	
	RESULT = hR						'don't use Application.GetPriority = !!
END FUNCTION




'===========================================================================================================
' QSYSTEM component --Windows System information for Rapid-Q, Version 1.0b
' by JohnK
'===========================================================================================================
$DEFINE sysHibernateAsk    1
$DEFINE sysHibernateForce  2
$DEFINE sysSleepAsk        3
$DEFINE sysSleepForce      4
'AC_LINE_OFFLINE = &H0
'AC_LINE_ONLINE = &H1
'AC_LINE_BACKUP_POWER = &H2
'AC_LINE_UNKNOWN = &HFF
'BATTERY_FLAG_HIGH = &H1
'BATTERY_FLAG_LOW = &H2
'BATTERY_FLAG_CRITICAL = &H4		'return values can be OR e.g, BATTERY_FLAG_CRITICAL | BATTERY_FLAG_CHARGING both set
'BATTERY_FLAG_CHARGING = &H8
'BATTERY_FLAG_NO_BATTERY = &H80
'BATTERY_FLAG_UNKNOWN = &HFF
'BATTERY_PERCENTAGE_UNKNOWN = &HFF
'BATTERY_LIFE_UNKNOWN = &HFFFF



TYPE QSYSTEM EXTENDS QOBJECT
  PRIVATE:
	rtn				AS LONG
	MemStats		AS MEMORYSTATUS
    ProcHandle      As Long
    MyFlag          As Long

  PUBLIC:
	MajorVersion	AS INTEGER
	MinorVersion	AS INTEGER
	ACLineStatus	AS INTEGER		'see constants
	PercentBattery	AS INTEGER		'range 0 - 100
	PowerStatus		AS INTEGER PROPERTY SET SetPowerStatus


  FUNCTION OSName$() AS STRING		'get OS version
	DIM OSV 	AS OSVERSIONINFO

	OSV.dwOSVersionInfoSize = SIZEOF(OSV)  
	THIS.rtn=GetVersionEx(OSV)
	IF THIS.rtn = 0 THEN RESULT = "ERROR" : GOTO EXIT_FUNCTION
    THIS.MajorVersion = OSV.dwMajorVersion 
    THIS.MinorVersion = OSV.dwMinorVersion 
	SELECT CASE OSV.dwPlatformId
		CASE VER_PLATFORM_WIN32_NT
		  IF OSV.dwMajorVersion > 5 THEN RESULT = "Newer than XP"
		  IF (OSV.dwMajorVersion = 5 AND OSV.dwMinorVersion = 2 ) THEN RESULT = "Windows Server 2003"
		  IF (OSV.dwMajorVersion = 5 AND OSV.dwMinorVersion = 1 ) THEN RESULT = "Windows XP"
		  IF (OSV.dwMajorVersion = 5 AND OSV.dwMinorVersion = 0 ) THEN RESULT = "Windows 2000"
		  IF OSV.dwMajorVersion <= 4 THEN RESULT = "Windows NT"
		CASE VER_PLATFORM_WIN32_WINDOWS
		  IF (OSV.dwMajorVersion = 4 AND OSV.dwMinorVersion = 90 ) THEN RESULT = "Windows ME"
		  IF (OSV.dwMajorVersion = 4 AND OSV.dwMinorVersion = 10 ) THEN RESULT = "Windows 98"
		  IF (OSV.dwMajorVersion = 4 AND OSV.dwMinorVersion = 0 ) THEN RESULT = "Windows 95"
		CASE VER_PLATFORM_WIN32s
		  RESULT = "Win32s"
		CASE ELSE
		  RESULT = "Not Windows"
	END SELECT
    EXIT_FUNCTION:          'fix memory leak for exit function
  END FUNCTION



  PROPERTY SET SetPowerStatus(TheStatus AS LONG)
'  FUNCTION GetPowerStatus() AS INTEGER			'can't return byte
	DIM powr	AS SYSTEM_POWER_STATUS
	IF TheStatus > 0 THEN
		'you must use  SetSystemPowerState(x,y) for pre-win98
		IF TheStatus = sysHibernateAsk THEN 
			IF MESSAGEDLG("Hibernate the compuer now (Save all data first)?", mtConfirmation, (mbYes OR mbNo), 0) = mrYes THEN THIS.rtn = SetSuspendState(0,0,0)		'last param disables wake if 1 !!
		END IF
		IF TheStatus = sysHibernateForce THEN THIS.rtn = SetSuspendState(0,1,0)
		IF TheStatus = sysSleepAsk THEN 
			IF MESSAGEDLG("Sleep the compuer now (Save all data first)?", mtConfirmation, (mbYes OR mbNo), 0) = mrYes THEN THIS.rtn = SetSuspendState(1,0, 0)
		END IF
		IF TheStatus = sysSleepForce THEN THIS.rtn = SetSuspendState(1,1,0)
	ELSE
		THIS.rtn = GetSystemPowerStatus(powr)
		IF THIS.rtn = 0 THEN
			RESULT = BATTERY_LIFE_UNKNOWN		'call crashed, give unknown result
		ELSE
			THIS.PowerStatus = INT(powr.BatteryFlag)
			THIS.ACLineStatus = powr.ACLineStatus
			THIS.PercentBattery = powr.BatteryLifePercent
		END IF
	END IF
  END PROPERTY
	

  FUNCTION PercentFreeMemory() AS DWORD
	GlobalMemoryStatus(THIS.MemStats)
	RESULT = 100-THIS.MemStats.dwMemoryLoad
  END FUNCTION

  FUNCTION AvailableMemory() AS DWORD
	GlobalMemoryStatus(THIS.MemStats)
	RESULT = THIS.MemStats.dwAvailPhys
  END FUNCTION

  FUNCTION TotalMemory() AS DWORD
	GlobalMemoryStatus(THIS.MemStats)
	RESULT = THIS.MemStats.dwTotalPhys
  END FUNCTION

  FUNCTION UsedMemory() AS DWORD
	GlobalMemoryStatus(THIS.MemStats)
	RESULT = THIS.MemStats.dwTotalPhys - THIS.MemStats.dwAvailPhys
  END FUNCTION

  FUNCTION PageFileMemory() AS DWORD
	GlobalMemoryStatus(THIS.MemStats)
	RESULT = THIS.MemStats.dwAvailPageFile
  END FUNCTION

	'Get available MegaBytes free space off drive, send in any folder, ie = "C:", or can be null
  FUNCTION DiskFreeSpace(RootPathName AS STRING) AS DOUBLE 		'returns 8 bytes
     Dim FreeBytesAvail As LARGE_INTEGER
     DIM TtlBytes 		As LARGE_INTEGER
     Dim TTlFree 		As LARGE_INTEGER
     Dim dblFreeSpace 	As Double

     RESULT = 0
     If GetDiskFreeSpaceEx(RootPathName, FreeBytesAvail, TtlBytes, TTlFree) Then
        If FreeBytesAvail.LowPart < 0 Then		'signed high bit?
            dblFreeSpace = FreeBytesAvail.HighPart * 2 ^ 32 + FreeBytesAvail.LowPart + 4294967296#
        Else
            dblFreeSpace = FreeBytesAvail.HighPart * 2 ^ 32 + FreeBytesAvail.LowPart
        End If
        RESULT = dblFreeSpace/1048576	'convert to MB
      End If
  END FUNCTION


' ****  system metrics wrapped up for ya  ****

  FUNCTION MouseWheelPresent() AS LONG		'mouse wheel
	DIM tmpStr AS STRING
	tmpStr = THIS.OSName$
	IF tmpStr <> "Windows 95" THEN		'need > win 95
		RESULT = GetSystemMetrics(SM_MOUSEWHEELPRESENT)
	ELSE
		RESULT = 0&
	END IF
  END FUNCTION

  FUNCTION ScrollBarWidth() AS LONG		'Vertical scroll width
    RESULT = GetSystemMetrics(SM_CXVSCROLL)
  END FUNCTION

  FUNCTION ScrollBarHeight() AS LONG		'Horizontal scroll height
    RESULT = GetSystemMetrics(SM_CYHSCROLL)
  END FUNCTION

  FUNCTION CaptionBarHeight() AS LONG		'Caption bar height"
    RESULT = GetSystemMetrics(SM_CYCAPTION)
   END FUNCTION

  FUNCTION WindowBorderWidth() AS LONG		'Window border width"
    RESULT = GetSystemMetrics(SM_CXBORDER)
  END FUNCTION

  FUNCTION WindowBorderHeight() AS LONG		'Window border height"
    RESULT = GetSystemMetrics(SM_CYBORDER)
  END FUNCTION

  FUNCTION IconWidth() AS LONG			'Icon width
    RESULT = GetSystemMetrics(SM_CXICON)
  END FUNCTION

  FUNCTION IconHeight() AS LONG			'Icon Height
    RESULT = GetSystemMetrics(SM_CYICON)
  END FUNCTION

  FUNCTION MenuBarHeight() AS LONG			'Menu bar height
    RESULT = GetSystemMetrics(SM_CYMENU)
  END FUNCTION

  FUNCTION NetworkPresent() AS LONG		'Network present flag
    RESULT = GetSystemMetrics(SM_NETWORK)
  END FUNCTION

  FUNCTION SlowProcessor() AS LONG	'Slow processor flag, in case you need a fast machine
    RESULT = GetSystemMetrics(SM_SLOWMACHINE)
  END FUNCTION


	'===========================================================================================================
	' Control panel code adapted from b_j0@yahoo.com, Thanks to Rudy Elyn (email: Rudy@vt4.net)
	' modifed to be easier by JohnK
	'===========================================================================================================
	'uses rundll32 <library (Shell32)>,Control_RunDLL <cplfile> (@)<which dialog>
	' optional comma and index to display the desired tab on the dialog! NOTE: if the cpl file dosen't take arguments, use    @0, comma, <index> 
	' Not all dialogs of the Control Panel have arguments. index starts at 1
	'args:
	' 1: the cpl file (located in the Windows System directory)
	' 2: the number (tag) of the applet located in the cpl file that you wish to run (prefixed with an "@" (at) sign); 
	'     the "tags" of each applet start at zero (I think!)
	' 3:  the tab to display when the applet is shown (if the applet has one)

  FUNCTION ShowControlPanel(PanelName AS STRING,index AS INTEGER) AS LONG
	DIM Keywd	AS STRING
	DIM PID		AS LONG

	KeyWd = UCASE$(LEFT$(PanelName,4))
	SELECT CASE KeyWd

	CASE = "MOUS"
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL main.cpl @0,"+str$(index), 5)
	CASE = "KEYB"
		if index >1 then index=0
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL main.cpl @1,"+str$(index), 5)
	CASE = "PRIN"
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL main.cpl @2", 5)
	CASE "FONT"
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL main.cpl @3", 5)
	CASE "DISP"
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL desk.cpl @0,"+str$(index), 5)
	CASE "TIME"
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL timedate.cpl @0", 5)
	CASE "DIAL", "TELE"
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL telephon.cpl @0,"+str$(index), 5)
	CASE "SYST"
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL sysdm.cpl @0"+str$(index), 5)
	CASE "ADD "
		IF (UCASE$(LEFT$(PanelName, 12) = "ADD NEW HARD")) THEN
			PID = Shell("rundll32.exe shell32.dll,Control_RunDLL sysdm.cpl @1", 5)
		END IF
		IF (UCASE$(LEFT$(PanelName, 12) = "ADD OR REMOV")) THEN
			PID = Shell("rundll32.exe shell32.dll,Control_RunDLL appwiz.cpl @0,"+str$(index), 5)
		END IF
	CASE "SCAN"
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL sticpl.cpl @0", 5)
	CASE "THEM"		'Themes
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL themes.cpl @0", 5)
	CASE "POWE"		'power management
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL powercfg.cpl @0,"+str$(index), 5)
	CASE "PASS"
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL password.cpl @0,"+str$(index), 5)
	CASE "MODE"	'modem
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL modem.cpl @0,"+str$(index), 5)
	CASE "MMDE"	'mmdevice
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL mmsys.cpl @0,"+str$(index), 5)
	CASE "SOUN"	'sounds
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL mmsys.cpl @1", 5)
	CASE "GAME"
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL joy.cpl @0,"+str$(index), 5)
	CASE "REGI"		'regional settings
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL intl.cpl @0,"+str$(index), 5)
	CASE "INTE"		'internet
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL inetcpl.cpl @0,"+str$(index), 5)
	CASE "USER"
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL inetcpl.cpl @1,"+str$(index), 5)
	CASE "ACCE"
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL access.cpl @0,"+str$(index), 5)
	CASE "FIRE"
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL firewall.cpl @0,"+str$(index), 5)
	CASE "NETS"
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL netsetup.cpl @0,"+str$(index), 5)
	CASE "DIRE"
		PID = Shell("rundll32.exe shell32.dll,Control_RunDLL directx.cpl @0,"+str$(index), 5)
	CASE ELSE
		PID = 0
	END SELECT
	RESULT = PID
  END FUNCTION


PRIVATE:

    SUB DoShutDown
        ' Grab the shutdown privilege - else reboot will fail
        DIM Thndl   As Long
        DIM MyLUID  As LUID
        DIM MyPriv  As TOKEN_PRIVILEGES
        DIM MyNewPriv As TOKEN_PRIVILEGES
        DIM ret     As long
        DIM pdword  As integer
    
        This.ProcHandle = GetCurrentProcess()
        ret = OpenProcessToken(This.ProcHandle, TOKEN_ADJUST_PRIVILEGES Or TOKEN_QUERY, @Thndl)
        ret = LookupPrivilegeValue("", "SeShutdownPrivilege", MyLUID)
        MyPriv.PrivilegeCount = 1
        MyPriv.Attributes = SE_PRIVILEGE_ENABLED
        MyPriv.LowPart = MyLUID.LowPart
        MyPriv.HighPart = MyLUID.HighPart
        ' Now to set shutdown privilege for my app
        pdword = 4 + (12 * MyNewPriv.PrivilegeCount)
        ret = AdjustTokenPrivileges(Thndl, False, MyPriv, 4 + (12 * MyPriv.PrivilegeCount), MyNewPriv,@pdword)
        ' Do the required action
        Ret = ExitWindowsEx(This.MyFlag, 0)
    END SUB

PUBLIC:
    SUB ShutDown
        This.MyFlag = EWX_SHUTDOWN
        This.DoShutDown
    END SUB

    SUB ShutDownForce
        This.MyFlag = EWX_FORCE or EWX_SHUTDOWN
        This.DoShutDown
    END SUB

    SUB LogOff
        This.MyFlag = EWX_LOGOFF
        This.DoShutDown
    END SUB

    SUB Reboot
        This.MyFlag = EWX_REBOOT
        This.DoShutDown
    END SUB


  CONSTRUCTOR
	SetPowerStatus(0)
	OSName$
    MyFlag = EWX_LOGOFF
  END CONSTRUCTOR
END TYPE




'====================================================================================================================
'------- SCREEN INTERNAL Commands extended --------------
'====================================================================================================================
FUNCTION Screen.MousePresent() AS LONG			'informs you if the Mouse is present
    RESULT = GetSystemMetrics(SM_MOUSEPRESENT)
END FUNCTION

FUNCTION Screen.MouseSwap() AS LONG		'Mouse buttons swapped flag
    RESULT = GetSystemMetrics(SM_SWAPBUTTON)
END FUNCTION

FUNCTION Screen.MouseButtons() AS LONG		'Number of mouse buttons
    RESULT = GetSystemMetrics(SM_CMOUSEBUTTONS)
END FUNCTION

FUNCTION Screen.SetMouseXY(X AS LONG, Y AS LONG) AS LONG	'these are for "compatibility" with Screen.Mouse
	RESULT = SetCursorPos(X, Y)
END FUNCTION

FUNCTION Screen.ClientWidth() AS LONG	'Full screen client area width
    RESULT = GetSystemMetrics(SM_CXFULLSCREEN)
END FUNCTION

FUNCTION Screen.ClientHeight() AS LONG	'Full screen client area height
    RESULT = GetSystemMetrics(SM_CYFULLSCREEN)
END FUNCTION

FUNCTION Screen.Monitors() AS LONG		'Returns the Number of monitors connected
    RESULT = GetSystemMetrics(SM_CMONITORS)
END FUNCTION


FUNCTION Screen.SetResolution(X AS DWORD, Y AS DWORD, bpp AS WORD, Freq AS DWORD) AS LONG
      DIM DevM AS DEVMODE
      DIM erg AS LONG

      RESULT = 0
      MEMSET(DevM,0,sizeof(DevM))       'Makes Sure Memory's Cleared
	  DevM.dmSize = sizeof(DevM)
      DevM.dmFields = DM_PELSWIDTH OR DM_PELSHEIGHT OR DM_BITSPERPEL
      DevM.dmPelsWidth = X
      DevM.dmPelsHeight = Y
      DevM.dmBitsPerPel = bpp
      IF Freq<> 0 THEN 
		DevM.dmFields = DevM.dmFields OR DM_DISPLAYFREQUENCY
		DevM.dmDisplayFrequency = Freq
      END IF

      erg = ChangeDisplaySettings(DevM, CDS_TEST)		'will it work OK?
      SELECT CASE erg
      CASE DISP_CHANGE_SUCCESSFUL
	   erg = ChangeDisplaySettings(devm, CDS_DYNAMIC)    'use for temporary change (most users want this)
'       erg = ChangeDisplaySettings(DevM, CDS_UPDATEREGISTRY)	'use this to change Registry
      CASE DISP_CHANGE_RESTART
		ShowMessage "You must restart your computer for new screen resolution setting."
	  CASE DISP_CHANGE_FAILED
		ShowMessage "Change Screen Resolution Failed"
	  CASE DISP_CHANGE_BADMODE
		ShowMessage "Invalid Screen Resolution parameters"
	  CASE ELSE
		ShowMessage "Undefined result: " + STR$(erg) + "  in SetResolution"
      END SELECT
	  RESULT = erg
END FUNCTION




FUNCTION Screen.GetPixelDepth() AS LONG
    DIM DC as integer
    DC=GetDC(0)
	RESULT = GetDeviceCaps(DC, BITSPIXEL)
    ReleaseDC(0,DC)
END FUNCTION



'new changed from QLISTVIEW, couldn't get single column control
FUNCTION Screen.EnumResolution(ListView AS QLISTBOX) AS LONG 
    DIM DevM As DevMode
	DIM fEnd As LONG,  iMode As LONG
    Dim TheRstr As String
    DEFSTR DeviceName = ""

	RESULT = 0         'set it in case of crash
    DevM.dmSize = SIZEOF(DevM)
    iMode = 0
    Do
        fEnd = EnumDisplaySettings(DeviceName, iMode, DevM)
        'The fields dmPelsWidth, dmPelsHeight, dmBitsPerPel are most useful
        TheRstr = STR$(DevM.dmPelsWidth) + " x " +_
				  STR$(DevM.dmPelsHeight) + " x " + STR$(DevM.dmBitsPerPel) + " BPP"
        ListView.AddItems(TheRstr)
        iMode++
    Loop Until (fEnd = 0)
	RESULT = 1
END FUNCTION




FUNCTION Screen.CaptureToBMP(TheRect AS QRECT, CapBitMap AS QBITMAP) AS LONG	'returns true if success
	DIM DeskhWnd 	AS LONG		'handle of desktop
	DIM DeskDC		AS LONG		'new device content to hold desktop graphics data
	DIM retrn		AS LONG
	DIM TmpForm		AS QFORM	'for some reason you must have a form here!!!
	
	DeskhWnd=GetDesktopWindow()
	DeskDC = CreateDC("DISPLAY", "", "", 0)		'' or try   DeskDC = CreateDC("", "", "", DevThing AS DEVMODE)
	IF TheRect.Bottom = 0 AND TheRect.Top = 0 AND TheRect.Right =  0 AND TheRect.Left = 0 THEN
		CapBitMap.Height= Screen.Height
		CapBitMap.Width	= Screen.Width				'if Rect not set use whole screen
	ELSE
		CapBitMap.Height = TheRect.Bottom - TheRect.Top
		CapBitMap.Width	= TheRect.Right - TheRect.Left
	END IF
	
	retrn =	BitBlt(CapBitMap.Handle,_		'capture bitmap handle
			0, 0,_							'origin on bitmap
			CapBitMap.Width,_				'
			CapBitMap.Height,_				'size it for our capture bitmap
			DeskDC,_						'DC = device context
			TheRect.Left, TheRect.Top,_		'origin on desktop to capture
			&HCC0020) 						'Raster operation copy source (SrcCopy)
	Screen.CaptureToBMP = retrn
	RESULT = retrn									'set a return value from function
	IF retrn = 0 THEN
		ShowMessage "Screen Capture Failed"
		GOTO EXIT_FUNCTION
	END IF
	TmpForm.Draw(0,0, CapBitMap.BMP)				'bug? must have this for calling form to get BMP
	TmpForm.Close									'discard it you don't need it
    EXIT_FUNCTION:          'fix memory leak for exit function
END FUNCTION




FUNCTION Screen.CaptureToFile(TheRect AS QRECT, OutFileName AS STRING) AS LONG
	DIM DeskhWnd 	AS LONG		'handle of desktop
	DIM DeskDC		AS LONG		'new device content to hold desktop graphics data
	DIM CapBitMap	AS QBITMAP	'to hold the BMP and handle
	DIM retrn		AS LONG
	
	DeskhWnd=GetDesktopWindow()
	DeskDC = CreateDC("DISPLAY", "", "", 0)
	IF TheRect.Bottom = 0 AND TheRect.Top = 0 AND TheRect.Right =  0 AND TheRect.Left = 0 THEN
		CapBitMap.Height= Screen.Height
		CapBitMap.Width	= Screen.Width				'if Rect not set use whole screen
	ELSE

		CapBitMap.Height = TheRect.Bottom - TheRect.Top
		CapBitMap.Width	= TheRect.Right - TheRect.Left
	END IF

	retrn =	BitBlt(CapBitMap.Handle,_		'capture bitmap handle
			0, 0,_							'origin on bitmap
			CapBitMap.Width,_				'
			CapBitMap.Height,_				'size it for our capture bitmap
			DeskDC,_						'DC = device context
			TheRect.Left, TheRect.Top,_		'origin on desktop to capture
			&HCC0020) 						'Raster operation copy source (SrcCopy)
	Screen.CaptureToFile = retrn
	IF retrn = 0 THEN
		ShowMessage "Screen Capture Failed"
		GOTO EXIT_FUNCTION
	END IF

	IF OutFileName <> "" THEN 
		CapBitMap.SaveToFile(OutFileName)
	END IF
    EXIT_FUNCTION:          'fix memory leak for exit function
END FUNCTION


FUNCTION Screen.GetPixel(x AS INTEGER, y AS INTEGER) AS LONG
    DIM DC as integer
    DIM color as long
    
    DC=GetDC(0)
    color=GetPixel(DC,x,y)
    ReleaseDC(0,DC)
    result=color
END FUNCTION





'=============================================
' Return Decimal integer from hex   (T. Morton)
'=============================================
function HexToDec(hex as string)as long
  dim bit as long
  dim valbit as integer
  dim i as integer
  dim value as integer
  
  hex=REVERSE$(hex)
  bit=1
  value=0
  for i=1 to len(hex)
    if mid$(hex,i,1)="A" then
      value=value+(10*bit)
    elseif mid$(hex,i,1)="B" then
      value=value+(11*bit)
    elseif mid$(hex,i,1)="C" then
      value=value+(12*bit)
    elseif mid$(hex,i,1)="D" then
      value=value+(13*bit)
    elseif mid$(hex,i,1)="E" then
      value=value+(14*bit)
    elseif mid$(hex,i,1)="F" then
      value=value+(15*bit)
    else
      value=value+(val(mid$(hex,i,1))*bit)
    end if
    if (bit*16)<2147483647 then bit=bit*16
  next i
  result=value
end function



' Return the pointer of user defined type in a long value
' use this if you need to type cast or pass the UDT address 
' as a value rather than BYREF

FUNCTIONI UDTPTR(...) AS LONG
	RESULT = ParamVal(1)
END FUNCTION

' =================== Fix CONVBASE$=======================

'***********   CONBASEx$  ***********************
'================================================
' handles up to 53 bits e.g.,
' PRINT CONVBASEx$("1FFFFFFFFFFFFF", 16, 2)
'================================================

FUNCTION CONVBASEx$(StrToConvert AS STRING, _
                  FromBase AS BYTE, _
                  ToBase AS BYTE) AS STRING
  DEFSTR WorkStr = UCASE$(LTRIM$(RTRIM$(StrToConvert)))
  DEFSTR DigitStr
  DEFLNG Digit, DigitVal
  DEFDBL DigitPwr
  DEFDBL Accum = 0
  FOR Digit = 0 TO LEN(WorkStr) - 1
    DigitStr = WorkStr[LEN(WorkStr) - Digit]
    DigitVal = VAL(CONVBASE$(DigitStr, FromBase, 10))
    Accum = Accum + DigitVal * FromBase ^ Digit
  NEXT
  IF Accum = 0 THEN Result = "0" : EXIT FUNCTION
  WorkStr = ""
  FOR Digit = 0 TO 99
    DigitPwr = ToBase ^ Digit
    IF INT(Accum / DigitPwr) = 0 THEN EXIT FOR  ' * (see below)
  NEXT
  FOR Digit = Digit - 1 TO 0 STEP - 1
    DigitPwr = ToBase ^ Digit
    DigitVal = INT(Accum / DigitPwr)
    IF DigitVal THEN
      WorkStr = WorkStr + CONVBASE$(STR$(DigitVal), 10, ToBase)
      Accum = Accum - DigitVal * DigitPwr
    ELSE
      WorkStr = WorkStr + "0"
    END IF
  NEXT
  Result = WorkStr
END FUNCTION


$DEFINE gRQ2_CONVBASE_Orig CONVBASE$ 
FUNCTIONI gRQ2_CONVBASEFixed(...) AS STRING
    DIM StrExpression AS STRING
    DIM fromBase      AS INTEGER
    DIM toBase        AS INTEGER
    DEFINT errFlag = 0

    StrExpression = UCASE$(ParamStr$(1))
    IF LEN(StrExpression) > 8 THEN 
        RESULT = CONVBASEx$(StrExpression, ParamVal(1), ParamVal(1))
    ELSE
        IF StrExpression = "FFFFFFFF" THEN errFlag = TRUE  'this will cause GPF
        fromBase = ParamVal(1)
        IF fromBase = 0 THEN errFlag = TRUE
        toBase = ParamVal(2)
        IF toBase = 0 THEN errFlag = TRUE
        IF errFlag THEN
             RESULT = "0"       'what to set here?
        ELSE
            RESULT = gRQ2_CONVBASE_Orig(StrExpression, fromBase, toBase)
        END IF
    END IF
END FUNCTIONI
$DEFINE CONVBASE$ gRQ2_CONVBASEFixed




' =====================================================================================
' Since only one CODEPTR is allowed for each application, you can have only one
' function for custom handling of windows messages ('hooking' or subclassing)
' all custom components that use a WndProc need to call this function 
' this will then call the correct WndProc by CALLFUNC that is BIND to the wndProc you want
' =====================================================================================
FUNCTION gRQ2_MasterWndProc(iFuncIndex AS LONG, hwnd AS LONG, uMsg AS LONG, wParam AS LONG, lParam AS LONG) AS LONG
       RESULT = CALLFUNC(gRQ2_WndProc(iFuncIndex), hwnd, uMsg, wParam, lParam, iFuncIndex)
END FUNCTION


'********************************************************************************
'********************************************************************************
'  Turn ON/OFF automatic inheritance of the extended types with the 
'  standard QOBJECT types (Qforms, Qbitmap, etc.). That way you leave 
'  the original code alone and the new added functions become automatic. 
'  This will interfere with dimensioning arrays of OBJECTS!!
'
'   To turn on automatic inheritance put in this line at the top of your code:
'    $DEFINE __EXTENSIONS_ON   'turn on all extensions
'
'
'$IFDEF __EXTEND_QFORM
'	'would like this to work, but crashes compiler, or is very unpredictable
'   $MACRO QFORM QFormEx		'pure crash
'	$DEFINE QFORM QFormEx       'unpredictable results
'$ENDIF
'********************************************************************************
'********************************************************************************


$ENDIF ' __RQINC2       'END of RapidQ.inc

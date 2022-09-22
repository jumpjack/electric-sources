'*******************************************************************
'  Direct3D retained mode include file for the RapidQ Compiler by William Yu
'    Last updated 4/2005,   by JohnK
'
'  THERE ARE NO WARANTIES OR GUARANTEES, Use at your own risk
'*********************************************************************
'
'
'
' ----------  Constants and definitions for DirectX under RapidQ -------
'  RapidQ comes from Delphi-X which uses a subset of Direct3D retained mode 
' calls but does not offer the full functionality of retained mode.
'
'
'
$TYPECHECK ON
$IFNDEF False
	$DEFINE False 0
$ENDIF
$IFNDEF True
	$DEFINE True 1
$ENDIF


$IFNDEF D3DVALUE
	$define D3DVALUE	SINGLE	'actual c declaration is float
$ENDIF

$IFNDEF D3DVECTOR
	TYPE D3DVECTOR
		X		AS SINGLE
		Y		AS SINGLE
		Z		AS SINGLE
	END TYPE
	$define LPD3DVECTOR		LONG		'pointer to structure
$ENDIF



' **** IMPORTANT, if you need all QD3DVECTOR values, use this instead!! *****
'The real implementation of QD3DVECTOR is a union between DVX &  X, DVY & Y, etc.
TYPE Q3DVECTOR
	DVX		AS SINGLE
	DVY		AS SINGLE
	DVZ		AS SINGLE
	X		AS SINGLE
	Y		AS SINGLE
	Z		AS SINGLE

END TYPE

'this makes more sense as a 3D vector has only 3 members
TYPE QD3DORIENTVECTOR
	X		AS SINGLE
	Y		AS SINGLE
	Z		AS SINGLE
	DVX		AS SINGLE
	DVY		AS SINGLE
	DVZ		AS SINGLE
END TYPE


TYPE QD3DRGBA			'different from DirectX D3DRGBA, which return DWORD types
	R		AS SINGLE
	G		AS SINGLE
	B		AS SINGLE
	A		AS SINGLE
END TYPE



CONST D3DGROUND_ZERO = 0	'Boris added this


'-- Wrap Types
CONST D3DRMWRAP_FLAT = 0			'projects the texture along one direction vector
CONST D3DRMWRAP_CYLINDER = 1		'projects the texture inward to center tangent with one vector
CONST D3DRMWRAP_SPHERE = 2			'projects the texture inward to center from a sphere
CONST D3DRMWRAP_CHROME = 3			'mesh normals to camera frame (not available in RapidQ) or other frame to calc texture coord
CONST D3DRMWRAP_SHEET = 4			'not documented by msdn
CONST D3DRMWRAP_BOX = 5				'tiles the bitmap?
'Type 				u coordinate						v coordinate 
'Flat 				1/w to cover width of object  		1/h to cover height of object exactly 
'Cylindrical 		1* 1/h to cover height of object  
'Spherical/chrome 	1* 									1* 
'*Values <> 1 may be used to wrap part of the texture or to tile it but may not be good at the seams.


'***********************************************************************************
'
'  Light types
'
'***********************************************************************************

'-- D3DRMLIGHTTYPE light types, use for QD3DLight.SetLightRGB(lightType, R, G, B)
CONST D3DRMLIGHT_AMBIENT = 0				'light homogenous in all directions
CONST D3DRMLIGHT_POINT = 1					'point source
CONST D3DRMLIGHT_SPOT = 2					'spotlight source. 
CONST D3DRMLIGHT_DIRECTIONAL = 3			'directional source
CONST D3DRMLIGHT_PARALLELPOINT = 4			'parallel source

'***********************************************************************************
'
'  set rendering quality for the meshbuilder
'
'***********************************************************************************
' - D3DRMSHADEMODE shading modes how do you fill in shading between vertices on the face?
CONST D3DRMSHADE_FLAT = 0
CONST D3DRMSHADE_GOURAUD = 1
CONST D3DRMSHADE_PHONG = 2
CONST D3DRMSHADE_MASK = 7
CONST D3DRMSHADE_MAX = 8

'-- fill in faces/vertex mode how do you fill the faces?
CONST D3DRMFILL_POINTS = 0
CONST D3DRMFILL_WIREFRAME = 64
CONST D3DRMFILL_SOLID = 128
CONST D3DRMFILL_MASK = 448
CONST D3DRMFILL_MAX = 512


' -- D3DRMLIGHTMODE lighting modes
CONST D3DRMLIGHT_OFF = 0 * D3DRMSHADE_MAX
CONST D3DRMLIGHT_ON = 1 * D3DRMSHADE_MAX
CONST D3DRMLIGHT_MASK = 7 * D3DRMSHADE_MAX
CONST D3DRMLIGHT_MAX = 8 * D3DRMSHADE_MAX


'-- Shade quality		use in QD3DMeshBuilder.SetQuality, can use above alone
CONST D3DRMRENDER_POINTS =		D3DRMSHADE_FLAT		+ D3DRMLIGHT_OFF	+ D3DRMFILL_POINTS
CONST D3DRMRENDER_WIREFRAME =	D3DRMSHADE_FLAT		+ D3DRMLIGHT_OFF	+ D3DRMFILL_WIREFRAME
CONST D3DRMRENDER_UNLITFLAT =	D3DRMSHADE_FLAT		+ D3DRMLIGHT_OFF	+ D3DRMFILL_SOLID
CONST D3DRMRENDER_FLAT =		D3DRMSHADE_FLAT		+ D3DRMLIGHT_ON		+ D3DRMFILL_SOLID
CONST D3DRMRENDER_GOURAUD =		D3DRMSHADE_GOURAUD	+ D3DRMLIGHT_ON		+ D3DRMFILL_SOLID
CONST D3DRMRENDER_PHONG =		D3DRMSHADE_PHONG	+ D3DRMLIGHT_ON		+ D3DRMFILL_SOLID
CONST D3DRMRENDER_MAX =			D3DRMSHADE_PHONG	+ D3DRMLIGHT_ON		+ D3DRMFILL_MAX

' IDirect3DRMDevice::GetWireframeOptions  API
CONST D3DRMWIREFRAME_CULL = 1 
CONST D3DRMWIREFRAME_HIDDENLINE = 2 

'*********************************************************************************

'-- Renderer modes		 use for QDXscreen.SetRenderMode, but they don't have any effect?
CONST D3DRMRENDERMODE_BLENDEDTRANSPARENCY = 1
CONST D3DRMRENDERMODE_SORTEDTRANSPARENCY = 2
CONST D3DRMRENDERMODE_LIGHTINMODELSPACE = 8
CONST D3DRMRENDERMODE_VIEWDEPENDENTSPECULAR = 16
CONST D3DRMRENDERMODE_DISABLESORTEDALPHAZWRITE = 32

'Most of the functionality of Direct3D would be through  D3DOP_STATERENDER opcodes
'This only works in Immediate Mode not in RapidQ's Retained Mode, so we are limited
' if you need more rendering options you will HAVE to go OpenGL, or other engine.


' the following constants are not described by rapidQ

' -- Textures definitions may not work
CONST D3DRMTEXTURE_FORCERESIDENT  = &H00000001 			'texture should be kept in video memory */
CONST D3DRMTEXTURE_STATIC  = &H02 						'texture will not change */
CONST D3DRMTEXTURE_DOWNSAMPLEPOINT  = &H00000004 		'point filtering should be used when downsampling
CONST D3DRMTEXTURE_DOWNSAMPLEBILINEAR  = &H00000008 	'bilinear filtering should be used when downsampling
CONST D3DRMTEXTURE_DOWNSAMPLEREDUCEDEPTH  = &H00000010 	'reduce bit depth when downsampling
CONST D3DRMTEXTURE_DOWNSAMPLENONE  = &H00000020 		'texture should never be downsampled
CONST D3DRMTEXTURE_CHANGEDPIXELS  = &H00000040 			'pixels have changed
CONST D3DRMTEXTURE_CHANGEDPALETTE  = &H00000080 		'palette has changed
CONST D3DRMTEXTURE_INVALIDATEONLY  = &H00000100 		'dirty regions are invalid

' texture quality (D3DRMTEXTUREQUALITY) use for QDXscreen.SetTextureQuality
CONST D3DRMTEXTURE_NEAREST = 0							'Choose the nearest pixel in the texture.  (default)
CONST D3DRMTEXTURE_LINEAR = 1							'Linearly interpolate the four nearest pixels. 
CONST D3DRMTEXTURE_MIPNEAREST = 2						'like D3DRMTEXTURE_NEAREST, but uses the mipmap instead of texture. 
CONST D3DRMTEXTURE_MIPLINEAR = 3						'Like D3DRMTEXTURE_LINEAR, but uses the appropriate mipmap instead of texture
CONST D3DRMTEXTURE_LINEARMIPNEAREST = 4					'Like D3DRMTEXTURE_MIPNEAREST, but interpolates between the two nearest mipmaps
CONST D3DRMTEXTURE_LINEARMIPLINEAR = 5					'Like D3DRMTEXTURE_MIPLINEAR, but interpolates between the two nearest mipmaps


' --Shadows
CONST D3DRMSHADOW_TRUEALPHA  = &H00000001 				'shadow should render without artifacts when true alpha is on


' --fog mode, use for QD3DFrame.FogMode and DXscreen.Fog...--fog color is a DWORD
CONST D3DRMFOG_LINEAR = 0								'linear between start and end */
CONST D3DRMFOG_EXPONENTIAL = 1							' density * exp(-distance) */
CONST D3DRMFOG_EXPONENTIALSQUARED = 2					'* density * exp(-distance*distance) */



' --- D3DRMFRAMECONSTRAINT  frame constrain for QD3DFrame.LookAt (F AS QD3DFrame, Constraint AS INTEGER) 
CONST D3DRMCONSTRAIN_Z = 0
CONST D3DRMCONSTRAIN_Y = 1
CONST D3DRMCONSTRAIN_X = 2


' -- Combination types  _D3DRMCOMBINETYPE, use for QD3DFrame.AddScale SUB (CombineType%, X#, Y#, Z#)
' Scales a frame's local transformation by (rvX, rvY, rvZ)
'Specifies how to combine the new scale with any current frame transformation. 
CONST D3DRMCOMBINE_REPLACE = 0		'in matrix replaces the frame's current matrix. 
CONST D3DRMCOMBINE_BEFORE = 1		'in matrix is multiplied with the frame's current matrix and precedes the current matrix in the calculation.
CONST D3DRMCOMBINE_AFTER = 2		'in matrix is multiplied with the frame's current matrix and follows the current matrix in the calculation.




'textures are obtained by QDXSCREEN.CreateTexture (Tex as QD3DTexture) or QD3DMeshBuilder.SetTexture only?
'There is a QD3DTexture object that should be the same as IDirect3DRMTexture but RapidQ doesn't support it

''Additional commands possible:
'
'QD3DANIMATION
'QDXSCREEN.CREATEANIMATION
'QD3DANIMATION.PARENT
'Example:
'DIM ANI AS QD3DANIMATION
'QDXSCREEN.CREATEANIMATION(ANI)
'ANI.PARENT = QDXscreen `-- no effect?
'ANI.PARENT = QD3Dframe `—causes strange things and changes the
'QD3Dframe settings!)
'--------------------------------------------------------------------

'QD3DANIMATIONSET
'QD3DANIMATIONSET.PARENT
'QDXSCREEN.CREATEANIMATIONSET
'Example:
'DIM AniSet AS QD3DANIMATIONSET
'QDXSCREEN.CREATEANIMATIONSET(AniSet)
'AniSet.PARENT = QDXscreen
'AniSet.Parent = QD3Dframe`—causes strange things and changes the
'QD3Dframe settings!)
'
'--------------------------------------------------------------------
'QDXSCREEN___FONT methods:
'QDXSCREEN.FONT.COLOR__
'QDXSCREEN.FONT.NAME___
'QDXSCREEN.FONT.SIZE___
'QDXSCREEN.FONT.ADDSTYLES__
'QDXSCREEN.FONT.DELSTYLES__
'QDXSCREEN.FONT.FONTCOUNT__
'QDXSCREEN.FONT.FONTNAME___
'QDXSCREEN.FONT.HANDLE_
'QDXSCREEN.FONT.CHARSET____
'QDXSCREEN.FONT.PITCH__
'QDXSCREEN.FONT.BOLD___
'QDXSCREEN.FONT.ITALIC_
'QDXSCREEN.FONT.UNDERLINE__
'QDXSCREEN.FONT.STRIKEOUT__
'


'************************************************************************
'WINDOWS COM API for Direct3D retained mode and substitues if fail


Declare Sub D3DRMVectorCrossProduct Lib "d3drm.dll" ALIAS "D3DRMVectorCrossProduct"_
	(ByRef d As D3DVECTOR, ByRef s1 As D3DVECTOR, ByRef s2 As D3DVECTOR)
	'returns result in d

DECLARE SUB CrossProduct(BYREF Norm AS QD3DVECTOR, BYREF a AS QD3DVECTOR, BYREF b AS QD3DVECTOR)
SUB CrossProduct(BYREF a AS QD3DVECTOR, BYREF b AS QD3DVECTOR, BYREF Norm AS QD3DVECTOR)
	'returns the Normal
	Norm.x = a.y * b.z - a.z * b.y 
	Norm.y = a.z * b.x - a.x * b.z 
	Norm.z = a.x * b.y - a.y * b.x 
END SUB


Declare Function D3DRMVectorDotProduct Lib "d3drm.dll" ALIAS "D3DRMVectorDotProduct" _
	(ByRef s1 As D3DVECTOR, ByRef s2 As D3DVECTOR) AS D3DVALUE

DECLARE FUNCTION VectorDotProduct(BYREF a AS QD3DVECTOR, BYREF b AS QD3DVECTOR) AS SINGLE
FUNCTION VectorDotProduct(BYREF a AS QD3DVECTOR, BYREF b AS QD3DVECTOR) AS SINGLE
	VectorDotProduct = a.x * b.x + a.y * b.y + a.z * b.z 
END FUNCTION



Declare Function D3DRMVectorNormalize Lib "d3drm.dll" ALIAS "D3DRMVectorNormalize"_
	(ByRef lpD3DVECTOR As D3DVECTOR ) AS LPD3DVECTOR

DECLARE SUB VectorNormalize(BYREF VecIn AS QD3DVECTOR)
SUB VectorNormalize(BYREF VecIn AS QD3DVECTOR)
	DIM VLength AS SINGLE
	VLength = VecIn.x * VecIn.x + VecIn.y * VecIn.y + VecIn.z * VecIn.z	'square
	If VLength = 0 Then VecIn.x = 0: VecIn.y = 0: VecIn.z = 0: EXIT SUB
	VLength = Sqr(VLength)
	VecIn.x = VecIn.x / VLength
	VecIn.y = VecIn.y / VLength
	VecIn.z = VecIn.z / VLength
END SUB


'these are in D3DRM.DLL but will do ok under rapidQ

DECLARE SUB VectorAdd(BYREF VectAdd AS QD3DVECTOR, BYREF a AS QD3DVECTOR, BYREF b AS QD3DVECTOR)
SUB VectorAdd(BYREF VectAdd AS QD3DVECTOR, BYREF a AS QD3DVECTOR, BYREF b AS QD3DVECTOR)
  VectAdd.x = a.x + b.x
  VectAdd.y = a.y + b.y
  VectAdd.z = a.z + b.z
END SUB


DECLARE SUB VectorSubtract(BYREF VectSub AS QD3DVECTOR, BYREF a AS QD3DVECTOR, BYREF b AS QD3DVECTOR)
SUB VectorSubtract(BYREF VectSub AS QD3DVECTOR, BYREF a AS QD3DVECTOR, BYREF b AS QD3DVECTOR)
  VectSub.x = a.x - b.x
  VectSub.y = a.y - b.y
  VectSub.z = a.z - b.z
END SUB



'
'
' -------  Custom Components that help direct 3d programs  -------
'
$DEFINE null ""


'========================================================================================================
'    QD3DCAMERA component version 1.1
'
' useful alternative to DXSCREEN.SetCameraXXXX
' 10/2004 JohnK
'========================================================================================================
TYPE QD3DCamera EXTENDS QOBJECT
	PRIVATE:
	PushMouseX		AS INTEGER
	PushMouseY		AS INTEGER

	PUBLIC:
	Pos				AS QD3DVECTOR				'xyz position
	Orient			AS QD3DOrientVector			'6 element vector for d3d retained mode camera
	Height			AS SINGLE					'offset in up direction
	ZoomFactor		AS SINGLE
	AngleX			AS INTEGER					'for holding of sin/cos integration in look-up tables
	AngleY			AS INTEGER					'and also for Up-Down vector from sin/cos look-up tables
	MouseDownButton	AS INTEGER					'signal which mouse button down for dynamic zooming
	MouseDownX		AS INTEGER					'where mouse is down for dynamic zooming
	MouseDownY		AS INTEGER					' and y
	MouseZooming	AS INTEGER					'signal mouse was used for zooming

	FUNCTION GetRadius() AS SINGLE				'vector length (radius) of the camera from origin
		QD3DCamera.GetRadius = SQR(QD3DCamera.Pos.x * QD3DCamera.Pos.x +_
							QD3DCamera.Pos.y * QD3DCamera.Pos.y +_
							QD3DCamera.Pos.z * QD3DCamera.Pos.z)
	END FUNCTION

	FUNCTION GetXZRadius() AS SINGLE			'radius in x-z plane of the camera from origin
		QD3DCamera.GetXZRadius = SQR(QD3DCamera.Pos.x * QD3DCamera.Pos.x +_
								QD3DCamera.Pos.z * QD3DCamera.Pos.z)
	END FUNCTION

	FUNCTION GetXYRadius() AS SINGLE			'radius in x-z plane of the camera from origin
		QD3DCamera.GetXYRadius = SQR(QD3DCamera.Pos.x * QD3DCamera.Pos.x +_
								QD3DCamera.Pos.y * QD3DCamera.Pos.y)
	END FUNCTION

	SUB Translate(dx AS SINGLE, dy AS SINGLE, dz AS SINGLE)
		QD3DCamera.Pos.x = QD3DCamera.Pos.x + dx
		QD3DCamera.Pos.y = QD3DCamera.Pos.y + dy
		QD3DCamera.Pos.z = QD3DCamera.Pos.z + dz
	END SUB

	SUB ZoomXZ(Mag AS SINGLE)
		QD3DCamera.Pos.x = QD3DCamera.Pos.x + (QD3DCamera.Orient.x * Mag)	'move forward by orientation
		QD3DCamera.Pos.z = QD3DCamera.Pos.z + (QD3DCamera.Orient.z * Mag)
	END SUB

	SUB Zoom(Mag AS SINGLE)
		QD3DCamera.Pos.x = QD3DCamera.Pos.x + (QD3DCamera.Orient.x * Mag)	'zoom forward/back by orientation
		QD3DCamera.Pos.z = QD3DCamera.Pos.z + (QD3DCamera.Orient.z * Mag)
		QD3DCamera.Pos.y = QD3DCamera.Pos.y + (QD3DCamera.Orient.y * Mag)
	END SUB


	SUB ResetView
		QD3DCamera.Orient.x = 0.0				'These vectors set the orientation of camera axis (-1 to 1)
		QD3DCamera.Orient.y = 0.0				'point straight down the z-axis
		QD3DCamera.Orient.z = 1.0				'since all others are 0 and z is 1
		QD3DCamera.Orient.dvx = 0.0			'this sets the "up" vector or roll
		QD3DCamera.Orient.dvy = 1.0			'camera is standing straight up
		QD3DCamera.Orient.dvz = 0.0			'this has no purpose, should be set to 0
		QD3DCamera.AngleX = 0
		QD3DCamera.AngleY = 0
	END SUB

	SUB FaceCamera(BYREF Orient AS QD3DOrientVector, ObjPosX AS SINGLE, ObjPosY AS SINGLE, ObjPosZ AS SINGLE)
		'Finds the angles required for orientation vectors to
		'face the camera. Also known as "Billboarding"
		DIM Delta		AS QD3DVECTOR
		DIM Radi		AS SINGLE

		Delta.X = ObjPosX - QD3DCamera.Pos.x		'vector difference in position between camera & object
		Delta.Y = ObjPosY - QD3DCamera.Pos.y
		Delta.Z = ObjPosZ - QD3DCamera.Pos.z
		Orient.dvx = QD3DCamera.Orient.dvx			'this sets the "up" vector or roll
		Orient.dvy = QD3DCamera.Orient.dvy			'camera is standing straight up
		Orient.dvz = QD3DCamera.Orient.dvz			'this has no purpose, should be set to 0
		Radi = SQR(Delta.x*Delta.x + Delta.y*Delta.y + Delta.z*Delta.z)		'get magnitude
		IF Radi < 0.01 THEN EXIT SUB				'too close don't change
		Orient.x = Delta.X/Radi
		Orient.z = Delta.z/Radi
		Orient.y = Delta.Y/Radi
	END SUB


	SUB Update (DxScrn AS QDXSCREEN)
		DxScrn.SetCameraPosition(QD3DCamera.Pos.x, QD3DCamera.Pos.y, QD3DCamera.Pos.z)
		DxScrn.SetCameraOrientation(QD3DCamera.Orient.x, QD3DCamera.Orient.y, QD3DCamera.Orient.z,_		'orientation axis vector
								  QD3DCamera.Orient.dvx, QD3DCamera.Orient.dvy, QD3DCamera.Orient.dvz)	'up axis vector
		'DxScrn.Render
		'DxScrn.Flip			'may not want these...
	END SUB

	SUB SaveMouse
		QD3DCamera.PushMouseX = QD3DCamera.MouseDownX		'store the original mouse location (Push/pop)
		QD3DCamera.PushMouseY = QD3DCamera.MouseDownY
	END SUB


	SUB RestoreMouse
		SetCursorPos(QD3DCamera.PushMouseX, QD3DCamera.PushMouseY)	'restore mouse by Win API
	END SUB


	CONSTRUCTOR
		Pos.x = 0.0					'
		Pos.y = 0.0					'set it to middle
		Pos.z = 0.0					'
		Orient.x = 0.0				'These vectors set the orientation of camera axis (-1 to 1)
		Orient.y = 0.0				'point straight down the z-axis
		Orient.z = 1.0				'since all others are 0 and z is 1
		Orient.dvx = 0.0			'this sets the "up" vector or roll
		Orient.dvy = 1.0			'camera is standing straight up
		Orient.dvz = 0.0			'this has no purpose, should be set to 0
		Height = 1.0				'offset camera from ground in y direction
		ZoomFactor = 1.0			'how much to zoom the camera
		AngleX = 0					'integers for look up of sin/cos tables
		AngleY = 0
		MouseDownButton = MouseNotDown		'signal no button, can't use false!!
		MouseDownX = 0
		MouseDownY = 0
		MouseZooming = False
	END CONSTRUCTOR
END TYPE





'========================================================================================================
'    QD3DPrimitive component version 1.1
'  
' make simple polygon mesh objects -- can't  extend a QD3DMeshbuilder
' 9/2005 JohnK
'========================================================================================================


TYPE QD3DPrimitive EXTENDS QOBJECT		'use for floor, sky box, clouds, boxes, pyramids, whatever
  PRIVATE:								'don't mess with these
	xc 	AS SINGLE						'quick draw center
	yc	AS SINGLE
	zc	AS SINGLE
	
  PUBLIC:
	Mesh			AS QD3DMESHBUILDER	'mesh holds all polygon faces,colors, material, render quality
	Frame			AS QD3DFRAME		'Frame for independent orientation, position
	RenderQuality	AS LONG				'Rendering quality of the Mesh (eg D3DRMRENDER_GOURAUD)
	TextureFile		AS STRING
	TexOriginX		AS SINGLE			'texture origin
	TexOriginY		AS SINGLE			'in model space
	TexOriginZ		AS SINGLE			'These are the first 3 args for the D3Dwrap function
	TexOriginU		AS SINGLE			'coordinates on bmp (u,v) for texture origin
	TexOriginV		AS SINGLE			'of the last args in D3Dwrap function
	TexScaleU		AS SINGLE			'u,v texture scaling, for whole mesh = 1/size mesh
	TexScaleV		AS SINGLE			'2nd to last args in D3Dwrap function
	TexWrapType		AS SHORT			'See wrap type codes above
	Color			AS QD3DRGBA			'rgb and alphablend
	DrawCenter		AS QD3DVector		'center for drawing primitives freely vary for each new polygon
	BoxSides		AS INTEGER			'number of sides for the MakeBox function
	ViewFromOutside	AS INTEGER			'poly faces orient outside the box
    Visible         AS INTEGER          'Flag any object / polygons created

	FUNCTION New() AS INTEGER
		WITH QD3DPrimitive
		.RenderQuality	= D3DRMRENDER_FLAT
		.TextureFile	= null
		.TexOriginX		= 0.0
		.TexOriginY		= 0.0
		.TexOriginZ		= 0.0
		.TexOriginU		= 0.0
		.TexOriginV		= 0.0
		.TexScaleU		= 1.0
		.TexScaleV		= 1.0
		.TexWrapType	= D3DRMWRAP_SPHERE
		.Color.R		= 1.0
		.Color.G		= 1.0
		.Color.B		= 1.0
		.Color.A		= 1.0
		.DrawCenter.x	= 0.0
		.DrawCenter.y	= 0.0
		.DrawCenter.z	= 0.0
		.BoxSides		= 5			'don't render the bottom
		.ViewFromOutside = True		'look at the box from the outside (inside is transparent)
        .Visible        = False     'nothing loaded
		END WITH
	END FUNCTION


	SUB LoadTextureFile
		DIM openDialog 	AS QOPENDIALOG

		IF QD3DPrimitive.TextureFile = null THEN
			openDialog.Caption = "select a bitmap for the texture"
			openDialog.filter = "*.bmp (bitmaps)|*.bmp"
   			IF openDialog.execute THEN
				IF FILEEXISTS(openDialog.fileName) THEN 
					QD3DPrimitive.TextureFile = openDialog.fileName
				ELSE
					ShowMessage "Texture file does not exist"
					EXIT SUB
				END IF
			END IF	'fileopen execute
		END IF		'no file name
		QD3DPrimitive.Mesh.loadTexture(QD3DPrimitive.TextureFile)
	END SUB




	SUB MakeHorizPlane(DXScreen AS QDXSCREEN)	'simple horizontal plane
		DIM Face	AS QD3DFace
		DIM	xc		AS SINGLE						'quick draw center
		DIM	yc		AS SINGLE
		DIM	zc		AS SINGLE

		xc = QD3DPrimitive.DrawCenter.x			'looks silly but easier to read/debug
		yc = QD3DPrimitive.DrawCenter.y
		zc = QD3DPrimitive.DrawCenter.z
		DXScreen.CreateFace(Face)
		IF QD3DPrimitive.ViewFromOutside THEN
			Face.AddVertex(-1+xc, 0+yc, -1):	Face.AddVertex( 1+xc, 0+yc, -1)
			Face.AddVertex( 1+xc, 0+yc, 1):		Face.AddVertex(-1+xc, 0+yc, 1)
		ELSE
			Face.AddVertex(-1+xc, 0+yc, 1):		Face.AddVertex( 1+xc, 0+yc, 1)
			Face.AddVertex( 1+xc, 0+yc, -1):	Face.AddVertex(-1+xc, 0+yc, -1)
		END IF
		QD3DPrimitive.Mesh.AddFace(Face)
		QD3DPrimitive.Visible = True        
	END SUB


	SUB MakeVertZPlane(DXScreen AS QDXSCREEN)		'simple vertical plane down the z-axis (x = 0)
		DIM Face 	AS QD3DFace
		DIM	xc		AS SINGLE						'quick draw center
		DIM	yc		AS SINGLE
		DIM	zc		AS SINGLE

		xc = QD3DPrimitive.DrawCenter.x			'looks silly but easier to read/debug
		yc = QD3DPrimitive.DrawCenter.y
		zc = QD3DPrimitive.DrawCenter.z
		DXScreen.CreateFace(Face)
		IF QD3DPrimitive.ViewFromOutside THEN
			Face.AddVertex(xc, 0+yc, -1+zc):	Face.AddVertex(xc, 1+yc, -1+zc)
			Face.AddVertex(xc, 1+yc,  1+zc):	Face.AddVertex(xc, 0+yc,  1+zc)
		ELSE
			Face.AddVertex(xc, 0+yc,  1+zc):	Face.AddVertex(xc, 1+yc,  1+zc)
			Face.AddVertex(xc, 1+yc, -1+zc): 	Face.AddVertex(xc, 0+yc, -1+zc)
		END IF
		QD3DPrimitive.Mesh.AddFace(Face)
		QD3DPrimitive.Visible = True
	END SUB



	SUB MakeVertXPlane(DXScreen AS QDXSCREEN)		'simple vertical plane down the x-axis (z = 0)
		DIM Face 	AS QD3DFace
		DIM	xc		AS SINGLE						'quick draw center
		DIM	yc		AS SINGLE
		DIM	zc		AS SINGLE

		xc = QD3DPrimitive.DrawCenter.x			'looks silly but easier to read/debug
		yc = QD3DPrimitive.DrawCenter.y
		zc = QD3DPrimitive.DrawCenter.z
		DXScreen.CreateFace(Face)
		IF QD3DPrimitive.ViewFromOutside = True THEN
			Face.AddVertex( 1+xc, 0+yc, zc):  	Face.AddVertex( 1+xc, 1+yc, zc)
			Face.AddVertex(-1+xc, 1+yc, zc): 	Face.AddVertex(-1+xc, 0+yc, zc)
		ELSE
			Face.AddVertex(-1+xc, 0+yc, zc): 	Face.AddVertex(-1+xc, 1+yc, zc)
			Face.AddVertex( 1+xc, 1+yc, zc):	Face.AddVertex( 1+xc, 0+yc, zc)
		END IF
		QD3DPrimitive.Mesh.AddFace(Face)
		QD3DPrimitive.Visible = True
	END SUB



	SUB MakeBox(DXScreen AS QDXSCREEN)			'must pass in DXscreen for COM operation
		DIM Face 	AS QD3DFace
		DIM tmp		AS QD3DVECTOR				'keep track of DrawCenter
		DIM tmpView	AS INTEGER					'and view state

		WITH QD3DPrimitive
		tmp.x = .DrawCenter.x					'store them
		tmp.y = .DrawCenter.y
		tmp.z = .DrawCenter.z
		tmpView = .ViewFromOutside

		.DrawCenter.z = 1
		.MakeVertXPlane(DXScreen)				'back plane

		IF .ViewFromOutside = True THEN .ViewFromOutside = False ELSE .ViewFromOutside = True
		.DrawCenter.z = -1
		.MakeVertXPlane(DXScreen)				'front plane
		.ViewFromOutside = tmpView

		IF .ViewFromOutside = True THEN .ViewFromOutside = False ELSE .ViewFromOutside = True
		.DrawCenter.z = 0
		.DrawCenter.x = -1
		.MakeVertZPlane(DXScreen)				'left plane
		.ViewFromOutside = tmpView
		.DrawCenter.x = 1						'right plane
		.MakeVertZPlane(DXScreen)

		IF .BoxSides > 4 THEN					'ceiling
		IF .ViewFromOutside = True THEN .ViewFromOutside = False ELSE .ViewFromOutside = True
			.DrawCenter.z = 0
			.DrawCenter.x = 0
			.DrawCenter.y = 1
			.MakeHorizPlane(DXScreen)
    		.ViewFromOutside = tmpView
		END IF

		IF .BoxSides > 5 THEN					'floor
			.DrawCenter.y = 0
			.MakeHorizPlane(DXScreen)
		END IF

		.DrawCenter.x = tmp.x					'restore
		.DrawCenter.y = tmp.y
		.DrawCenter.z = tmp.z
		.ViewFromOutside = tmpView
		.Visible = True
		END WITH
	END SUB



	SUB MakePyramid(DXScreen AS QDXSCREEN)	'simple pyramid from center
		DIM Face 	AS QD3DFace

		WITH QD3DPrimitive
		DXScreen.CreateFace(Face)

		Face.AddVertex(0,  0, 0) 
		Face.AddVertex(1,  1, 1)
   		Face.AddVertex(1, -1, 1)
		IF .ViewFromOutside = False THEN
			Face.AddVertex(1,  1, 1)		'add extra vert to avoid culling
		END IF
		.Mesh.AddFace(Face)

		Face.AddVertex( 0, 0, 0) 
		Face.AddVertex( 1, 1, 1)
		Face.AddVertex(-1, 1, 1)
		IF .ViewFromOutside = False THEN
		Face.AddVertex( 1, 1, 1)
		END IF
		.Mesh.AddFace(Face)

		Face.AddVertex( 0,  0, 0) 
		Face.AddVertex(-1,  1, 1)
		Face.AddVertex(-1, -1, 1)
		IF .ViewFromOutside = False THEN
		Face.AddVertex(-1,  1, 1)
		END IF
		.Mesh.AddFace(Face)

		Face.AddVertex( 0,  0, 0) 
		Face.AddVertex(-1, -1, 1)
		Face.AddVertex( 1, -1, 1)
		IF .ViewFromOutside = False THEN
		Face.AddVertex(-1, -1, 1)
		END IF
		.Mesh.AddFace(Face)
		.Visible = True
		END WITH
	END SUB



    SUB MakeSphere(DXScreen AS QDXSCREEN, NumFaces AS INTEGER)   'simple sphere from center
        DIM Phi         AS SINGLE
        DIM Theta       AS SINGLE
        DIM theStep     AS SINGLE
        DIM theStep2    AS SINGLE
        DIM x1 as SINGLE, y1 AS SINGLE, z1 AS SINGLE
        DIM x2 as SINGLE, y2 AS SINGLE, z2 AS SINGLE
        DIM x3 as SINGLE, y3 AS SINGLE
        DIM x4 as SINGLE, y4 AS SINGLE
        DIM Face        AS QD3DFace
        DIM pi          AS SINGLE: pi = 3.14159265359
        DIM pi2         AS SINGLE: pi2 = 6.2831853072

		WITH QD3DPrimitive
        .xc = .DrawCenter.x
        .yc = .DrawCenter.y
        .zc = .DrawCenter.z
        theStep = pi/SQR(NumFaces)
        theStep2 = 2* TheStep

        FOR Phi = 0 TO pi STEP TheStep
        FOR Theta = 0 TO pi2 STEP TheStep2
            DXScreen.CreateFace(Face)
            y1 = SIN(Phi) * COS(Theta)
            x1 = SIN(Phi) * SIN(Theta)
            z1 = COS(Phi)
    
            y2 = SIN(Phi) * COS(Theta + TheStep2)
            x2 = SIN(Phi) * SIN(Theta + TheStep2)
            z2 = COS(Phi + TheStep)
    
            y3 = SIN(Phi + TheStep) * COS(Theta + TheStep2)
            x3 = SIN(Phi + TheStep) * SIN(Theta + TheStep2)
    
            y4 = SIN(Phi + TheStep) * COS(Theta)
            x4 = SIN(Phi + TheStep) * SIN(Theta)
    		IF .ViewFromOutside = False THEN
                 Face.AddVertex(x4  + .xc,  y4  + .yc, z2  + .zc)
                 Face.AddVertex(x3  + .xc,  y3  + .yc, z2  + .zc)
                 Face.AddVertex(x2  + .xc,  y2  + .yc, z1  + .zc)
                 Face.AddVertex(x1  + .xc,  y1  + .yc, z1  + .zc)
            ELSE
                 Face.AddVertex(x1  + .xc,  y1  + .yc, z1  + .zc)
                 Face.AddVertex(x2  + .xc,  y2  + .yc, z1  + .zc)
                 Face.AddVertex(x3  + .xc,  y3  + .yc, z2  + .zc)
                 Face.AddVertex(x4  + .xc,  y4  + .yc, z2  + .zc)
            END IF

            .Mesh.AddFace(Face)
        NEXT Theta
        NEXT Phi
		.Visible = True
 		END WITH
    END SUB




    SUB MakeCylinder(DXScreen AS QDXSCREEN, NumFaces AS INTEGER)   'simple sphere from center
        DIM Theta       AS SINGLE
        DIM Theta2      AS SINGLE
        DIM TheStep     AS SINGLE
        DIM x as SINGLE,  y AS SINGLE,  z AS SINGLE
        DIM x2 as SINGLE, y2 AS SINGLE, z2 AS SINGLE
        DIM Face        AS QD3DFace
        DIM pi2         AS SINGLE: pi2 = 6.2831853072

		WITH QD3DPrimitive
        .xc = .DrawCenter.x
        .yc = .DrawCenter.y
        .zc = .DrawCenter.z
        y = 1.0
        y2 = -1.0
        TheStep = pi2/NumFaces
        FOR Theta = 0.0 TO pi2 STEP TheStep
            DXScreen.CreateFace(Face)                           'recreate to null prior faces
            Theta2 = Theta + TheStep
            x = COS(Theta):     z = SIN(Theta)
            x2 = COS(Theta2):   z2 = SIN(Theta2)
    		IF .ViewFromOutside = False THEN
                Face.AddVertex(x  + .xc,  y2 + .yc, z  + .zc)
                Face.AddVertex(x2 + .xc,  y2 + .yc, z2 + .zc)
                Face.AddVertex(x2 + .xc,  y  + .yc, z2 + .zc)
                Face.AddVertex(x  + .xc,  y  + .yc, z  + .zc)
            ELSE
                Face.AddVertex(x  + .xc,  y  + .yc, z  + .zc)
                Face.AddVertex(x2 + .xc,  y  + .yc, z2 + .zc)
                Face.AddVertex(x2 + .xc,  y2 + .yc, z2 + .zc)
                Face.AddVertex(x  + .xc,  y2 + .yc, z  + .zc)
            END IF
            .Mesh.AddFace(Face)
        NEXT Theta
		.Visible = True
 		END WITH
    END SUB



    SUB MakeCone(DXScreen AS QDXSCREEN, NumFaces AS INTEGER)   'simple sphere from center
        DIM Theta       AS SINGLE
        DIM Theta2      AS SINGLE
        DIM TheStep     AS SINGLE
        DIM x as SINGLE,  y AS SINGLE,  z AS SINGLE
        DIM x2 as SINGLE, y2 AS SINGLE, z2 AS SINGLE
        DIM Face        AS QD3DFace
        DIM pi2         AS SINGLE: pi2 = 6.2831853072

		WITH QD3DPrimitive
        .xc = .DrawCenter.x
        .yc = .DrawCenter.y
        .zc = .DrawCenter.z
        y = 1.0
        y2 = -1.0
        TheStep = pi2/NumFaces
        FOR Theta = 0.0 TO pi2 STEP TheStep                 'work in a circle radian
            DXScreen.CreateFace(Face)                       'recreate to null prior faces
            Theta2 = Theta + TheStep                        'next vert of circle
            x = COS(Theta):     z = SIN(Theta)
            x2 = COS(Theta2):   z2 = SIN(Theta2)
    		IF .ViewFromOutside = False THEN
                Face.AddVertex(x  + .xc,  y2 + .yc, z  + .zc)
                Face.AddVertex(x2 + .xc,  y2 + .yc, z2 + .zc)
                Face.AddVertex(0.0+ .xc,  y  + .yc, 0.0 + .zc)
            ELSE
                Face.AddVertex(0.0+ .xc,  y  + .yc, 0.0 + .zc)
                Face.AddVertex(x2 + .xc,  y2 + .yc, z2 + .zc)
                Face.AddVertex(x  + .xc,  y2 + .yc, z  + .zc)
            END IF
            .Mesh.AddFace(Face)
        NEXT Theta
		.Visible = True
 		END WITH
    END SUB


	CONSTRUCTOR
		New()
	END CONSTRUCTOR
END TYPE





'========================================================================================================
'    QD3DCloneMesh component version 1.0
'
' make multiple objects from the same mesh
' 10/2004 JohnK
'========================================================================================================



CONST MaxD3DClones	= 100						'Multiply up to 100 D3Dframes in the scene

TYPE QD3DCloneMesh		EXTENDS QOBJECT			'can't make arrays of custom objects
PRIVATE:
	Initialized			AS INTEGER
	RangeX				AS SINGLE
	RangeZ				AS SINGLE
PUBLIC:
	Visible				AS INTEGER	PROPERTY SET Set_Visible		'toggle visible on-off
	CloneNum			AS INTEGER	PROPERTY SET Set_CloneNum			'how many times to clone
	File				AS STRING				'filename  of X or 3DS 3d model
	Mesh				AS QD3DMESHBUILDER		'one mesh to multiply
	Frame(MaxD3DClones) AS QD3DFrame
	Range				AS QRECT				'set a box volume range to place all the cloned objects
	RandPos				AS INTEGER	PROPERTY SET Set_RandPos		'randomly generate positions?
	Pos(MaxD3DClones)	AS QD3DVECTOR			'position
	Orient(MaxD3DClones) AS QD3DOrientVector		'6 element vector for d3d retained mode camera
	RandScale			AS INTEGER 	PROPERTY SET Set_RandScale		'randomly generate sizes?
	Scale				AS QD3DVECTOR			'allow x,y,z scaling each frame
	TextureFile			AS STRING				'the texture file (.bmp or .ppm)
	TexOriginX			AS SINGLE				'texture origin
	TexOriginY			AS SINGLE				'in model space
	TexOriginZ			AS SINGLE				'These are the first 3 args for the D3Dwrap function
	TexOriginU			AS SINGLE				'u,v texture origin
	TexOriginV			AS SINGLE				'of the last args in D3Dwrap function
	TexScaleU			AS SINGLE				'u,v texture scaling
	TexScaleV			AS SINGLE				'2nd to last args in D3Dwrap function
	TexWrapType			AS LONG					'd3drm wrapping type code
	Color				AS QD3DRGBA				'(0 - 1) color whole mesh, if < 0 then don't modify -- if you set alpha you must set rgb... sorry


	PROPERTY SET Set_Visible(VisibleValue AS INTEGER)   'Property Set for Visible property
		DIM i AS INTEGER
		This.Visible = VisibleValue
		IF VisibleValue = 1 THEN                      'If Visible property is set to True
			IF This.Initialized THEN
			FOR i = 1 TO This.CloneNum
				This.Frame(i).AddVisual(This.Mesh)			'load the frames
			NEXT i
			ELSE
				ShowMessage "Initialize CloneObject first"
			END IF
	    ELSE                                          'Otherwise
			IF This.Initialized THEN
			FOR i = 1 TO This.CloneNum
				This.Frame(i).DeleteVisual(This.Mesh)		'unload the frames
			NEXT i
			END IF
		END IF
	END PROPERTY


	PROPERTY SET Set_CloneNum(TheCloneNum AS INTEGER)
		IF TheCloneNum < = MaxD3DClones THEN
			This.CloneNum = TheCloneNum		'it needs to be set!
		END IF
	END PROPERTY



	PROPERTY SET Set_RandPos(RandPosValue AS INTEGER)   'Property Set for Visible property
		DIM i AS INTEGER
		This.RandPos = RandPosValue
   		IF RandPosValue <> 0 THEN
			WITH This
			.RangeX = .Range.Right - .Range.Left
			.RangeZ = .Range.Top - .Range.Bottom
			FOR i = 1 TO .CloneNum
				This.Pos(i).x = RND * .RangeX + (.Range.Left/1)	'convert to single
				This.Pos(i).y = RND
				This.Pos(i).z = RND * .RangeZ + (.Range.Bottom/1)
			NEXT i
			END WITH
		END IF
	END PROPERTY


	PROPERTY SET Set_RandScale(RandScaleValue AS INTEGER)   'Property Set for Visible property
		WITH This
		.RandScale = RandScaleValue
   		IF RandScaleValue <> 0 THEN
			.Scale.x = RND
			.Scale.y = RND
			.Scale.z = .Scale.x
		ELSE
			.Scale.x = 1.0!
			.Scale.y = 1.0!
			.Scale.z = 1.0!
		END IF
		END WITH
	END PROPERTY



	SUB Init(DXscreen AS QDXSCREEN)
		DIM i	AS INTEGER

		IF This.Initialized THEN
		FOR i = 1 TO This.CloneNum
			This.Frame(i).DeleteVisual(This.Mesh)		'remove old ones first
		NEXT i
		END IF

		DXScreen.CreateMeshbuilder(This.Mesh)
		IF This.File <>"" THEN This.Mesh.Load(This.File)
		This.Mesh.Scale(This.Scale.x, This.Scale.y, This.Scale.z)' this works on each new load..but you can't remove them
		FOR i = 1 TO This.CloneNum
			DXScreen.CreateFrame(This.Frame(i))
			This.Frame(i).AddVisual(This.Mesh)
			This.Frame(i).SetPosition(This.Pos(i).x, This.Pos(i).y, This.Pos(i).z)
'			This.Frame.AddScale(D3DRMCOMBINE_BEFORE,This.Scale(i).x, This.Scale(i).y, This.Scale(i).z) 'this crashes
		NEXT i
		This.Initialized = True
	END SUB



	FUNCTION New()		AS INTEGER
	DIM i AS INTEGER
		WITH QD3DCloneMesh
		.Initialized	= False	'need to setup with QDXScreen
		.Visible 		= True
		.File			= null
		.CloneNum		= 0
		.RandPos		= False
		.Range.Left		= -1
		.Range.Top		= 1
		.Range.Right	= 1
		.Range.Bottom	= -1
		.RangeX			= 2 'total range left-right
		.RangeZ			= 2 'same for top-bottom
		.RandScale		= False
		.Scale.x		= 1.0!
		.Scale.y		= 1.0!		'can't scale each frame! Bug in program?
		.Scale.z		= 1.0!

		FOR i = 0 TO MaxD3DClones
			.Pos(i).x		= 0.0!
			.Pos(i).y		= 0.0!
			.Pos(i).z		= 0.0!
			.Orient(i).x 	= 0.0!
			.Orient(i).y 	= 1.0!
			.Orient(i).z 	= 1.0!
			.Orient(i).dvx 	= 0.0!
			.Orient(i).dvy 	= 1.0!
			.Orient(i).dvz 	= 0.0!
		NEXT i

		.TextureFile	= null
		.TexOriginX		= 0.0!
		.TexOriginY		= 0.0!
		.TexOriginZ		= 0.0!
		.TexOriginU		= 0.0!
		.TexOriginV		= 0.0!
		.TexScaleU		= 0.0!
		.TexScaleV		= 0.0!
		.TexWrapType	= D3DRMWRAP_SPHERE
		.Color.R		= 0.0!
		.Color.G		= 0.0!
		.Color.B		= 0.0!
		.Color.A		= 0.0!
		END WITH
	END FUNCTION

	CONSTRUCTOR
		New
	END CONSTRUCTOR
END TYPE



$UNDEF null
$TYPECHECK OFF

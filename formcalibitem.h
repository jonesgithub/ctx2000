
#ifndef _FORMCALIBITEM_H_
#define _FORMCALIBITEM_H_



#define     COMMON_CTRL_STYLE_NUM         5
#define	EDIT_STYLE		WS_VISIBLE|WS_GROUP|ES_DIGIT_ONLY  // WS_BORDER,
#define	EDIT_W			165
#define	EDIT_H			30
#define EDIT_EXSTYLE		WS_EX_TRANSPARENT

#define	EDIT_SHOWAD_TO_X		420
#define	EDIT_SHOWAD_TO_Y		150
#define EDIT_SHOWAD_TO_ID			105
#define EDIT_SHOWAD_TO_CAPTION		""
#define EDIT_SHOWAD_TO_ADDDATA		0

#define	EDIT_SHOWAD_X		420
#define	EDIT_SHOWAD_Y		190
#define EDIT_SHOWAD_ID			100
#define EDIT_SHOWAD_CAPTION		""
#define EDIT_SHOWAD_ADDDATA		0

#define	EDIT_WEIGHTS_X		420
#define	EDIT_WEIGHTS_Y		230
#define EDIT_WEIGHTS_ID			101
#define EDIT_WEIGHTS_CAPTION		"3000"
#define EDIT_WEIGHTS_ADDDATA		0

#define	EDIT_ZEROAD_X		420
#define	EDIT_ZEROAD_Y		270
#define EDIT_ZEROAD_ID			102
#define EDIT_ZEROAD_CAPTION		""
#define EDIT_ZEROAD_ADDDATA		0

#define	EDIT_CALIBAD_X		420
#define	EDIT_CALIBAD_Y		310
#define EDIT_CALIBAD_ID			103
#define EDIT_CALIBAD_CAPTION		""
#define EDIT_CALIBAD_ADDDATA		0

#define	EDIT_CALIBK_X		420
#define	EDIT_CALIBK_Y		350
#define	EDIT_LINEK_Y		70

#define	EDIT_LINEK_VALUE_Y	110


#define EDIT_CALIBK_ID			104
#define EDIT_CALIBK_CAPTION		""
#define EDIT_CALIBK_ADDDATA		0

//#define SPAN_X 50
#define S_W   120
#define STATIC_START_AD {EDIT_SHOWAD_TO_X-S_W,EDIT_LINEK_VALUE_Y,S_W,EDIT_H,"起始点AD:"}
#define STATIC_END_AD   {EDIT_SHOWAD_TO_X-S_W,EDIT_SHOWAD_TO_Y,S_W,EDIT_H,"结束点AD:"}
#define STATIC_CUR_AD   {EDIT_SHOWAD_X-S_W,EDIT_SHOWAD_Y,S_W,EDIT_H,"当前AD值:"}
#define STATIC_START_X  {EDIT_WEIGHTS_X-S_W,EDIT_WEIGHTS_Y,S_W,EDIT_H,"起始点X:"}
#define STATIC_START_Y  {EDIT_ZEROAD_X-S_W,EDIT_ZEROAD_Y,S_W,EDIT_H,"起始点Y:"}
#define STATIC_END_X    {EDIT_CALIBAD_X-S_W,EDIT_CALIBAD_Y,S_W,EDIT_H,"结束点X:"}
#define STATIC_END_Y    {EDIT_CALIBK_X-S_W,EDIT_CALIBK_Y,S_W,EDIT_H,"结束点Y:"}

#define EDIT_START_AD {EDIT_SHOWAD_TO_X,EDIT_LINEK_VALUE_Y,EDIT_W,EDIT_H,"0"}
#define EDIT_END_AD   {EDIT_SHOWAD_TO_X,EDIT_SHOWAD_TO_Y,EDIT_W,EDIT_H,"0"}
#define EDIT_CUR_AD   {EDIT_SHOWAD_X,EDIT_SHOWAD_Y,EDIT_W,EDIT_H,"0"}
#define EDIT_START_X  {EDIT_WEIGHTS_X,EDIT_WEIGHTS_Y,EDIT_W,EDIT_H,"0"}
#define EDIT_START_Y  {EDIT_ZEROAD_X,EDIT_ZEROAD_Y,EDIT_W,EDIT_H,"0"}
#define EDIT_END_X    {EDIT_CALIBAD_X,EDIT_CALIBAD_Y,EDIT_W,EDIT_H,"0"}
#define EDIT_END_Y    {EDIT_CALIBK_X,EDIT_CALIBK_Y,EDIT_W,EDIT_H,"0"}




#define SKIN_CTRL_STYLE_NUM		4

#define	BUTTON_STYLE                    SI_TYPE_CMDBUTTON|SI_TEST_SHAPE_RECT|SI_STATUS_VISIBLE

#define	BUTTON_CABZERO_ID               1
#define	BUTTON_CABZERO_X        270 -50
#define	BUTTON_CABZERO_Y        410
#define	BUTTON_CABZERO_ITEMRC           {}
#define	BUTTON_CABZERO_BMPINDEX		1
#define	BUTTON_CABZERO_TIP              NULL
#define	BUTTON_CABZERO_ATTACHED		0
#define	BUTTON_CABZERO_DATA             NULL

#define	BUTTON_CABWET_ID		2
#define	BUTTON_CABWET_X		390 -60
#define	BUTTON_CABWET_Y		410
#define	BUTTON_CABWET_ITEMRC		{}
#define	BUTTON_CABWET_BMPINDEX		2
#define	BUTTON_CABWET_TIP                 NULL
#define	BUTTON_CABWET_ATTACHED		0
#define	BUTTON_CABWET_DATA		NULL

#define	BUTTON_SAVE_ID                  3
#define	BUTTON_SAVE_X		510 -70
#define	BUTTON_SAVE_Y		410
#define	BUTTON_SAVE_ITEMRC		{}
#define	BUTTON_SAVE_BMPINDEX		3
#define	BUTTON_SAVE_TIP                 NULL
#define	BUTTON_SAVE_ATTACHED		0
#define	BUTTON_SAVE_DATA		NULL

#define	BUTTON_EXIT_ID			4
#define	BUTTON_EXIT_X		738
#define	BUTTON_EXIT_Y		8
#define	BUTTON_EXIT_ITEMRC		{}
#define	BUTTON_EXIT_BMPINDEX		4
#define	BUTTON_EXIT_TIP			NULL
#define	BUTTON_EXIT_ATTACHED		0
#define	BUTTON_EXIT_DATA		NULL

#define BUTTON_RET_CABLIC       660
#define ICON_SHOW_STABLE_X     650// 550
#define BUTTON_LINEK_X          660 //
#define BUTTON_LINEK_X_MDF    630 -80

#define BUTTON_CABZERO     {1,BUTTON_CABZERO_X,BUTTON_CABZERO_Y}
#define BUTTON_CABK        {2,BUTTON_CABWET_X,BUTTON_CABWET_Y}
#define BUTTON_SAVE        {3,BUTTON_SAVE_X,BUTTON_SAVE_Y}
#define BUTTON_EXIT        {4,BUTTON_EXIT_X,BUTTON_EXIT_Y}
#define  BUTTON_RET_CALIB  {5,BUTTON_RET_CABLIC,BUTTON_SAVE_Y}
#define  BUTTON_LINEK      {6,BUTTON_LINEK_X_MDF,BUTTON_SAVE_Y}
#define  BUTTON_READ_LINEK      {7,BUTTON_LINEK_X,BUTTON_SAVE_Y-65}

#define         SKIN_BMP_NUM            7

#define 	ICO_WETCALIB_X                      60
#define 	ICO_WETCALIB_Y                      65

#define 	ICO_WETCALIB_TEXT_X                 60
#define 	ICO_WETCALIB_TEXT_Y                 185

#define 	ICO_SHOWAD_TO_X		280
#define 	ICO_SHOWAD_TO_Y         150

#define 	ICO_SHOWAD_X		280
#define 	ICO_SHOWAD_Y                190

#define 	ICO_WEIGHTS_X		280
#define 	ICO_WEIGHTS_Y               230

#define 	ICO_ZEROAD_X		280
#define 	ICO_ZEROAD_Y                270

#define 	ICO_CALIBAD_X           280
#define 	ICO_CALIBAD_Y               310

#define 	ICO_CALIBK_X            280
#define 	ICO_CALIBK_Y                350

#endif



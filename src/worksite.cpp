#include "worksite.h"
#include "worksiteitem.h"
#include "BmpRes.h"
#include "tajidbmgr.h"
#include <iniFile.h>
#include <Poco/Format.h>
#include "comdata.h"
#include <yatengine.h>

using namespace TelEngine;
extern TTjRecord g_TC[21];
static COMM_CTRL_DESC lablectrls[] = {
    {50,  50, 100,30,"Left-Down:"},
    {50,  80, 30,30,"x1:"},
    {160, 80, 30,30,"y1:"},

    {50,  120, 100,30,"Right-Down:"},
    {50,  150, 30, 30,"x2:"},
    {160, 150, 30, 30,"y2:"},

    {50,  190, 100,30,"Right-Up:"},
    {50,  220, 30,30,"x3:"},
    {160, 220, 30,30,"y3:"},

    {50,  260, 100,30,"Left-Up:"},
    {50,  290, 30,30,"x4:"},
    {160, 290, 30,30,"y4:"},
//====================
    {290,  50,  100,30,"Y-->N Angle:"},

    {290,  120, 100,30,"Anchor Point:"},

    {290,  150, 30,30,"x1:"},
    {400,  150, 30,30,"y1:"},

    {290,  210, 30,30,"x2:"},
    {400,  210, 30,30,"y2:"},

    {290,  260, 200,30,"Vehicle Stop Distance:"},
    {290,  330, 200,30,"Vehicle Lowspeed Distance:"},

    {550,  50,  200,30, "Brake Distance:"},
    {550,  120, 200,30,"Danger Distance:"},
    {550,  190, 200,30,"Warn Distance:"},
    {550,  260, 200,30,"Add Safe Angle:"},
};
static COMM_CTRL_DESC editctrls[] = {
    {80,  80,  80,30,"0"},
    {190, 80,  80,30,"0"},

    {80,  150, 80,30,"0"},
    {190, 150, 80,30,"0"},

    {80,  220, 80,30,"0"},
    {190, 220, 80,30,"0"},

    {80,  290, 80,30,"0"},
    {190, 290, 80,30,"0"},
//===============
    {320, 80,  100,30,"0"},

    {320, 150,  80,30,"1"},
    {430, 150,  80,30,"2"},

    {320, 220,  80,30,"3"},
    {430, 220,  80,30,"4"},

    {320, 290,  80,30,"5"},
    {320, 360,  80,30,"6"},

    {550,  80,  100,30, "0"},
    {550,  150, 100,30,"1"},
    {550,  220, 100,30,"2"},
    {550,  290, 100,30,"3"},
};
static const char* mmenu_bmps[] = {
        PCOMM_BACKGROUND,
        PCOMM_MDY_BTN,
        PCOMM_SAVE_BTN,
        PCOMM_CLOSE_BTN,
        PCOMM_RET_BTN
};
static SKIN_BUTTON_DESC skinctrls[] = {
        {1,BUTTON_DEFAULE_X,BUTTON_DEFAULE_Y},
        {2,BUTTON_SAVE_X,BUTTON_SAVE_Y},
        {3,BUTTON_EXIT_X,BUTTON_EXIT_Y},
        {4,BUTTON_RETURN_XX,BUTTON_SAVE_Y}
};
static const char* icon_path[] = {

};

CWorkSite::CWorkSite()
{
    if(!LoadRes(&mmenu_bmps[0],ARRAY_SIZE(mmenu_bmps,char*)))
    {
        printf("Can't loadres\n");
        exit(0);
    }
    for(int i = 0 ;i < (sizeof(lablectrls)/sizeof(COMM_CTRL_DESC));i++)
    {
        lables[i] = new CStatic(&lablectrls[i],this);
    }
    for(int i = 0 ;i < (sizeof(editctrls)/sizeof(COMM_CTRL_DESC)) ;i++)
    {
        edits[i] = new CEdit(&editctrls[i],this);
    }
    btn_mdy     = new CSkinButton(&skinctrls[0],this);
    btn_save    = new CSkinButton(&skinctrls[1],this);
    btn_exit    = new CSkinButton(&skinctrls[2],this);;
    btn_ret     = new CSkinButton(&skinctrls[3],this);;
    InitSkinHeader("WET_param");
}
CWorkSite::~CWorkSite()
{	

}
void    CWorkSite::OnPaint(HWND hWnd)
{
    HDC hdc = BeginPaint(hWnd);
    EndPaint(hWnd,hdc);
}
void    CWorkSite::OnShow()
{

    for(int i = 0; i <4;i++)
    {
        edits[i*2+0]->SetText(Poco::format("%0.2f",  wksp[i][0]));
        edits[i*2+1]->SetText(Poco::format("%0.2f",  wksp[i][1]));
    }
    edits[8]->SetText(Poco::format("%0.2f",YNAngle));
    edits[9]->SetText(Poco::format("%0.2f",czwzb[0][0]));
    edits[10]->SetText(Poco::format("%0.2f",czwzb[0][1]));
    edits[11]->SetText(Poco::format("%0.2f",czwzb[1][0]));
    edits[12]->SetText(Poco::format("%0.2f",czwzb[1][1]));

    edits[13]->SetText(Poco::format("%0.2f",VStopDis));
    edits[14]->SetText(Poco::format("%0.2f",VWarnDis));

    edits[15]->SetText(Poco::format("%0.2f",BrakeDis));
    edits[16]->SetText(Poco::format("%0.2f",DangerDis));
    edits[17]->SetText(Poco::format("%0.2f",WarnDis));
    edits[18]->SetText(Poco::format("%0.2f",AddAngle));
    /*
    CTajiDbMgr::Get().load("ctx2000.sqlite3");

    int id = CTajiDbMgr::Get().GetLocalIndex();

    for(int i = 0; i < 8;)
    {
        double x_pos = CTajiDbMgr::Get().m_tj[id].ws.worksite_coord.at(i/2).x;
        double y_pos = CTajiDbMgr::Get().m_tj[id].ws.worksite_coord.at(i/2).y;
        fprintf(stderr,"x=%0.2f,y=%0.2f\n",x_pos,y_pos);
        edits[i++]->SetText(Poco::format("%0.2f",x_pos));
        edits[i++]->SetText(Poco::format("%0.2f",y_pos));
    }

    edits[8]->SetText(Poco::format("%0.2f",CTajiDbMgr::Get().m_tj[id].ws.y_angle));

    edits[9]->SetText(Poco::format("%0.2f",CTajiDbMgr::Get().m_tj[id].ws.anchor_coord.at(0).x));
    edits[10]->SetText(Poco::format("%0.2f",CTajiDbMgr::Get().m_tj[id].ws.anchor_coord.at(0).y));
    edits[11]->SetText(Poco::format("%0.2f",CTajiDbMgr::Get().m_tj[id].ws.anchor_coord.at(1).x));
    edits[12]->SetText(Poco::format("%0.2f",CTajiDbMgr::Get().m_tj[id].ws.anchor_coord.at(1).y));

    edits[13]->SetText(Poco::format("%0.2f",CTajiDbMgr::Get().m_tj[id].ws.car_high_spd_dist));
    edits[14]->SetText(Poco::format("%0.2f",CTajiDbMgr::Get().m_tj[id].ws.car_low_spd_dist));

    edits[15]->SetText(Poco::format("%0.2f",CTajiDbMgr::Get().m_tj[id].ws.brake_dist));
    edits[16]->SetText(Poco::format("%0.2f",CTajiDbMgr::Get().m_tj[id].ws.slowdown_dist));
    edits[17]->SetText(Poco::format("%0.2f",CTajiDbMgr::Get().m_tj[id].ws.alert_dist));
    edits[18]->SetText(Poco::format("%0.2f",CTajiDbMgr::Get().m_tj[id].ws.inertia_angle));

    //edits[0]->SetText(Poco::format("%0.2f",CTajiDbMgr::Get().m_tj.ws.alert_dist));
    //edits[1]->SetText(Poco::format("%0.2f",CTajiDbMgr::Get().m_tj.ws.alert_dist));
    */
}
void    CWorkSite::OnButtonClick(skin_item_t* item)
{

    if(item->id == btn_mdy->GetId())
    {

    }
    else if(item->id == btn_save->GetId())
    {
        /*
        int id = CTajiDbMgr::Get().GetLocalIndex();
        CTajiDbMgr::Get().m_tj[id].ws.car_high_spd_dist = edits[13]->GetFloatValue();
        CTajiDbMgr::Get().m_tj[id].ws.car_low_spd_dist  = edits[14]->GetFloatValue();
        CTajiDbMgr::Get().m_tj[id].ws.brake_dist        = edits[15]->GetFloatValue();
        CTajiDbMgr::Get().m_tj[id].ws.slowdown_dist     = edits[16]->GetFloatValue();
        CTajiDbMgr::Get().m_tj[id].ws.alert_dist        = edits[17]->GetFloatValue();
        CTajiDbMgr::Get().m_tj[id].ws.inertia_angle     = edits[18]->GetFloatValue();
        CTajiDbMgr::Get().UpdateWorksite(&CTajiDbMgr::Get().m_tj[id].ws);
        */
        bool ok;
        for(int i = 0 ;i < 4;i++)
        {
            wksp[i][0] = edits[i*2+0]->GetFloatValue(ok);
            wksp[i][1] = edits[i*2+1]->GetFloatValue(ok);
        }
        YNAngle = edits[8]->GetFloatValue(ok);
        for(int i = 0 ;i < 2;i++)
        {
            czwzb[i][0] =  edits[i*2+9]->GetFloatValue(ok);
            czwzb[i][1] =  edits[i*2+10]->GetFloatValue(ok);
        }

        VStopDis    = edits[13]->GetFloatValue(ok);
        VWarnDis    = edits[14]->GetFloatValue(ok);
        BrakeDis    = edits[15]->GetFloatValue(ok);
        DangerDis   = edits[16]->GetFloatValue(ok);
        WarnDis     = edits[17]->GetFloatValue(ok);
        AddAngle    = edits[18]->GetFloatValue(ok);

        edits[13]->SetText(Poco::format("%0.2f",VStopDis));
        edits[14]->SetText(Poco::format("%0.2f",VWarnDis));
        edits[15]->SetText(Poco::format("%0.2f",BrakeDis));
        edits[16]->SetText(Poco::format("%0.2f",DangerDis));
        edits[17]->SetText(Poco::format("%0.2f",WarnDis));
        edits[18]->SetText(Poco::format("%0.2f",AddAngle));

        Message m("mainctrl.cmd");

        m.setParam("type",  "save_worksite");

        if (!Engine::dispatch(m)) {
             Debug("mainctrl",DebugWarn,"ext.ctrl failed");
        }
    }
    else if(item->id == btn_exit->GetId())
    {
        Close();
    }
    else if(item->id == btn_ret->GetId())
    {
        Close();
    }

}
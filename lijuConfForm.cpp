#include "lijuConfFormItem.h"
#include "lijuConfForm.h"
#include "BmpRes.h"
#include "tajidbmgr.h"
#include "MineAddBox.h"
#include "comdata.h"
#include <Poco/Format.h>
static char* userlist_caption[] =
{
    "No.",
    "Arm Length",
    "Weight"
};

#define COL_NR	TABLESIZE(userlist_caption)

static char* userlist_group[] =
{
    "Supervisor",
    "Normal User"
//	"�ѽ����ʻ�"
};

#define GROUP_NR	TABLESIZE(userlist_group)

static const char *mmenu_bmps[] =
{
    PCOMM_LIST_BKGROUND,
    PCOMM_ADD_BTN,
    PCOMM_DEL_BTN,
    PCOMM_EDIT_BTN,
    PCOMM_RET_BTN,
    PCOMM_CLOSE_BTN
};

static SKIN_BUTTON_DESC SkinBtnsDesc[] =
{
    SKIN_BUTTON_ADD,
    SKIN_BUTTON_DEL,
    SKIN_BUTTON_EDIT,
    SKIN_BUTTON_QUIT,
    SKIN_BUTTON_EXIT
};
static COMM_CTRL_DESC CommCtrlsDesc[] =
{
    LISTVIEW_USER,
    {80,250,120,40,"0"},
    {80,300,120,40,"0"},
    {80,350,120,40,"0"}
};

static const char *icon_path[] =
{
    PPRESET_SITE_ICON,
    PPRESET_SITE_LABEL,
    PCOMM_LINE_ICON,
    PPRESET_ADMIN_TEXT
};

static POS BmpsPos[] =
{
    {
        SYSMT_X,
        SYSMT_Y
    },
    {
        SYSMT_TEXT_X,
        SYSMT_TEXT_Y
    },
    {
        LINE_X,
        LINE_Y
    },
    {
        SYSMT_ADMIN_X,
        SYSMT_ADMIN_Y
    }
};

CLiJuManForm::CLiJuManForm()
{
    if (!LoadRes(&mmenu_bmps[0], ARRAY_SIZE(mmenu_bmps, char *)))
    {
        printf("Can't loadres\n");
        exit(0);
    }

    for (int i = 0; i < USERMAN_SKIN_BTNS_NUM; i++)
    {
        _skinBtns[i] = new CSkinButton(&SkinBtnsDesc[i],this);
    }
    _lvLiJu = new CListView(&CommCtrlsDesc[0],this);
    cbx_type= new CComBox(&CommCtrlsDesc[1],this);
    cbx_arm_len=new CComBox(&CommCtrlsDesc[2],this);
    cbx_beilv=new CComBox(&CommCtrlsDesc[3],this);
    _icons.AddIcons(icon_path,ARRAY_SIZE(icon_path,char*));
    InitSkinHeader("CUserManForm");

}

CLiJuManForm::~CLiJuManForm()
{
}

void
CLiJuManForm::OnPaint(HWND hWnd)
{
    HDC hdc = BeginPaint(hWnd);

    for (int i = 0; i < SKIN_BMP_NUM; i++)
        _icons.Show(hdc,BmpsPos[i].x,BmpsPos[i].y,i+1);
    EndPaint(hWnd, hdc);
}

void
CLiJuManForm::OnClose()
{

}

void
CLiJuManForm::OnButtonClick(skin_item_t * item)
{
    if(item->id == _skinBtns[0]->GetId())
    {
        CMineAddBox liju;
        liju.m_arm_len="";
        liju.m_weight ="";
        liju.CreateForm(m_hWnd);
        if(liju.m_bOk){
            std::string type = cbx_type->GetSelItemText();
            std::string len  = cbx_arm_len->GetSelItemText();
            std::string beilv= cbx_beilv->GetSelItemText();
            if( (type.length() > 0 ) && (len.length() > 0) && (beilv.length() > 0)&&(liju.m_arm_len.length() > 0) && (liju.m_weight.length() > 0) )
            {
                CTajiDbMgr::Get().addlijuItem(type,len,beilv,liju.m_arm_len,liju.m_weight);
            }
            RefreshList(type,len,beilv);

        }
    }
    else if(item->id == _skinBtns[1]->GetId())
    {
        std::string len     = _lvLiJu->GetSelSubItemText(1);
        std::string weight  = _lvLiJu->GetSelSubItemText(2);
        std::string type    = cbx_type->GetSelItemText();
        std::string armlen  = cbx_arm_len->GetSelItemText();
        std::string beilv   = cbx_beilv->GetSelItemText();

        fprintf(stderr,"delete len=%s,we=%s\n",len.c_str(),weight.c_str());
        CTajiDbMgr::Get().deleteTjItem(type,armlen,beilv,len,weight);
        ReloadLijuItems();
    }
    else if(item->id == _skinBtns[2]->GetId())
    {
        CMineAddBox liju;
        liju.m_arm_len = _lvLiJu->GetSelSubItemText(1);
        liju.m_weight  = _lvLiJu->GetSelSubItemText(2);
        liju.CreateForm(m_hWnd);
        if(liju.m_bOk){
            std::string type = cbx_type->GetSelItemText();
            std::string len  = cbx_arm_len->GetSelItemText();
            std::string beilv= cbx_beilv->GetSelItemText();
            std::string armlen  = _lvLiJu->GetSelSubItemText(1);
            std::string weight  = _lvLiJu->GetSelSubItemText(2);
            if( (type.length() > 0 ) && (len.length() > 0) && (beilv.length() > 0)&&(liju.m_arm_len.length() > 0) && (liju.m_weight.length() > 0) )
            {
                TLiju newitem,olditem;
                newitem.armlen = liju.m_arm_len;
                newitem.weight = liju.m_weight;
                olditem.armlen = armlen;
                olditem.weight = weight;
                CTajiDbMgr::Get().modifylijuItem(type,len,beilv,olditem,newitem);
            }
            RefreshList(type,len,beilv);

        }
    }
    else if(item->id == _skinBtns[3]->GetId())
    {
        Close();
    }
    else if(item->id == _skinBtns[4]->GetId())
    {
        Close();
    }
}

void
CLiJuManForm::InitListCol()
{
    int width[COL_NR] = {120, 120, LIST_USER_W-360};
    int index = -1;
    for (int i = 0; i < COL_NR; i++)
    {
        _lvLiJu->AddColumn(i,userlist_caption[i],width[i]);
    }
    _lvLiJu->Clear();
    TStringList item;
    if(CTajiDbMgr::Get().getTjTypes(item))
    {
        for(size_t i = 0 ; i < item.size(); i++)
        {
            cbx_type->AddItem(item.at(i));
            if(item.at(i) == TCTypeName)
            {
                index = i;
            }
        }
        cbx_type->SetCurSel(index);
    }
    cbx_arm_len->SetText(StrTCArmLen);
    cbx_beilv->Clear();
    cbx_beilv->AddItem("1");
    cbx_beilv->AddItem("2");
    cbx_beilv->AddItem("4");
    cbx_beilv->AddItem("6");
    cbx_beilv->AddItem("8");
    cbx_beilv->SetText(StrTCBeilv);

}
void CLiJuManForm::ReloadLijuItems()
{
    std::string type = cbx_type->GetSelItemText();
    std::string len  = cbx_arm_len->GetSelItemText();
    std::string beilv= cbx_beilv->GetSelItemText();
    if( type.length()>0 || len.length()>0 || beilv.length()>0)
    {
        RefreshList(type,len,beilv);
    }else{
        _lvLiJu->Clear();
    }
}
void CLiJuManForm::OnShow()
{
    _lvLiJu->EnableSkinStyle(true);
    _lvLiJu->EnableTreeViewStyle(true);
    InitListCol();
    ReloadLijuItems();
}
void CLiJuManForm::OnCommCtrlNotify(HWND hwnd, int id, int nc)
{
    fprintf(stderr,"nc=%d\n",nc);
    if( (id == cbx_type->GetId()) &&  (nc == CBN_CLOSEUP)){
        TStringList rst;
        if(CTajiDbMgr::Get().getTjArmLen(cbx_type->GetSelItemText(),rst))
        {
            cbx_arm_len->Clear();
            for(size_t i = 0 ; i < rst.size(); i++)
            {
                cbx_arm_len->AddItem(rst.at(i));
            }
            cbx_arm_len->SetCurSel(-1);
        }
    }else if(id == cbx_beilv->GetId() && nc == CBN_CLOSEUP){
        ReloadLijuItems();
    }
}
#include <Poco/Format.h>
void CLiJuManForm::RefreshList(std::string type, std::string len ,std::string beilv)
{
    TLijuRst rst;
    _lvLiJu->Clear();
    if(CTajiDbMgr::Get().getlijuItems(type,len,beilv,rst))
    {

         TStringList list;
         for(size_t i = 0; i < rst.size(); i++)
         {
             list.clear();
             list.push_back(Poco::format("%u",i+1));
             list.push_back(rst.at(i).armlen);
             list.push_back(rst.at(i).weight);
            _lvLiJu->AddSubItems(list,25);
         }
    }
}

#ifndef FORMCALIB_H
#define FORMCALIB_H
#include "dt_core.h"
#include <yateclass.h>
#include <yatengine.h>
using namespace TelEngine;

class CFormCalib:public CSkinForm
{
public:
    CFormCalib();
    ~CFormCalib();
    virtual void OnCreate();
    virtual void OnClose();
    virtual void OnTimer(int ID);
    virtual void OnPaint(HWND hWnd);
    virtual void OnShow();
    virtual void OnUserMsg(HWND hWnd, int message, WPARAM wParam, LPARAM lParam);
    virtual void OnButtonClick(skin_item_t* item);
private:
    void calc_angle(int type);
    void calc_up_angle(int type);
    CSkinButton* _btns[20];
    CEdit*       _edits[10];
    CStatic*     _lables[10];
    MessageHandler* msgHandler;
};

#endif // FORMCALIB_H

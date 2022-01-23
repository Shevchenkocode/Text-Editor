/***************************************************************
 * Name:      Text_EditorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Ihor Shevchenko ()
 * Created:   2022-01-03
 * Copyright: Ihor Shevchenko ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "Text_EditorApp.h"
#include "Text_EditorMain.h"

IMPLEMENT_APP(Text_EditorApp);

bool Text_EditorApp::OnInit()
{
    Text_EditorFrame* frame = new Text_EditorFrame(0L);
    frame->Show();
    return true;
}

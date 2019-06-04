#pragma once
#include <windows.h>
#include <string>
#include <sstream>
#include <iomanip>

#define TRANSLATE_WM(msg) L#msg

inline std::wstring GetWinMessage( UINT uMsg );

static std::wstring ConvertMessage( MSG msg )
{
	std::wstringstream oss;

	oss
		<< L' ' << std::left << std::setfill( L'.' ) << std::setw( 25 ) << GetWinMessage( msg.message )
		<< std::hex << std::right
		<< L"    Msg: 0x" << std::setfill( L'0' ) << std::setw( 4 ) << msg.message
		<< L"    WP: 0x" << std::setw( 8 ) << msg.wParam
		<< L"    LP: 0x" << std::setw( 8 ) << msg.lParam << std::endl;

	return oss.str();
}

std::wstring GetWinMessage( UINT uMsg )
{
	switch( uMsg )
	{
		case WM_NULL: { return TRANSLATE_WM( WM_NULL ); }
		case WM_CREATE: { return TRANSLATE_WM( WM_CREATE ); }
		case WM_DESTROY: { return TRANSLATE_WM( WM_DESTROY ); }
		case WM_MOVE: { return TRANSLATE_WM( WM_MOVE ); }
		case WM_SIZE: { return TRANSLATE_WM( WM_SIZE ); }
		case WM_ACTIVATE: { return TRANSLATE_WM( WM_ACTIVATE ); }
		case WM_SETFOCUS: { return TRANSLATE_WM( WM_SETFOCUS ); }
		case WM_KILLFOCUS: { return TRANSLATE_WM( WM_KILLFOCUS ); }
		case WM_ENABLE: { return TRANSLATE_WM( WM_ENABLE ); }
		case WM_SETREDRAW: { return TRANSLATE_WM( WM_SETREDRAW ); }
		case WM_SETTEXT: { return TRANSLATE_WM( WM_SETTEXT ); }
		case WM_GETTEXT: { return TRANSLATE_WM( WM_GETTEXT ); }
		case WM_GETTEXTLENGTH: { return TRANSLATE_WM( WM_GETTEXTLENGTH ); }
		case WM_PAINT: { return TRANSLATE_WM( WM_PAINT ); }
		case WM_CLOSE: { return TRANSLATE_WM( WM_CLOSE ); }
		case WM_QUERYENDSESSION: { return TRANSLATE_WM( WM_QUERYENDSESSION ); }
		case WM_QUIT: { return TRANSLATE_WM( WM_QUIT ); }
		case WM_QUERYOPEN: { return TRANSLATE_WM( WM_QUERYOPEN ); }
		case WM_ERASEBKGND: { return TRANSLATE_WM( WM_ERASEBKGND ); }
		case WM_SYSCOLORCHANGE: { return TRANSLATE_WM( WM_SYSCOLORCHANGE ); }
		case WM_ENDSESSION: { return TRANSLATE_WM( WM_ENDSESSION ); }
		case WM_SHOWWINDOW: { return TRANSLATE_WM( WM_SHOWWINDOW ); }
		case WM_WININICHANGE: { return TRANSLATE_WM( WM_WININICHANGE ); }
		case WM_DEVMODECHANGE: { return TRANSLATE_WM( WM_DEVMODECHANGE ); }
		case WM_ACTIVATEAPP: { return TRANSLATE_WM( WM_ACTIVATEAPP ); }
		case WM_FONTCHANGE: { return TRANSLATE_WM( WM_FONTCHANGE ); }
		case WM_TIMECHANGE: { return TRANSLATE_WM( WM_TIMECHANGE ); }
		case WM_CANCELMODE: { return TRANSLATE_WM( WM_CANCELMODE ); }
		case WM_SETCURSOR: { return TRANSLATE_WM( WM_SETCURSOR ); }
		case WM_MOUSEACTIVATE: { return TRANSLATE_WM( WM_MOUSEACTIVATE ); }
		case WM_CHILDACTIVATE: { return TRANSLATE_WM( WM_CHILDACTIVATE ); }
		case WM_QUEUESYNC: { return TRANSLATE_WM( WM_QUEUESYNC ); }
		case WM_GETMINMAXINFO: { return TRANSLATE_WM( WM_GETMINMAXINFO ); }
		case WM_PAINTICON: { return TRANSLATE_WM( WM_PAINTICON ); }
		case WM_ICONERASEBKGND: { return TRANSLATE_WM( WM_ICONERASEBKGND ); }
		case WM_NEXTDLGCTL: { return TRANSLATE_WM( WM_NEXTDLGCTL ); }
		case WM_SPOOLERSTATUS: { return TRANSLATE_WM( WM_SPOOLERSTATUS ); }
		case WM_DRAWITEM: { return TRANSLATE_WM( WM_DRAWITEM ); }
		case WM_MEASUREITEM: { return TRANSLATE_WM( WM_MEASUREITEM ); }
		case WM_DELETEITEM: { return TRANSLATE_WM( WM_DELETEITEM ); }
		case WM_VKEYTOITEM: { return TRANSLATE_WM( WM_VKEYTOITEM ); }
		case WM_CHARTOITEM: { return TRANSLATE_WM( WM_CHARTOITEM ); }
		case WM_SETFONT: { return TRANSLATE_WM( WM_SETFONT ); }
		case WM_GETFONT: { return TRANSLATE_WM( WM_GETFONT ); }
		case WM_SETHOTKEY: { return TRANSLATE_WM( WM_SETHOTKEY ); }
		case WM_GETHOTKEY: { return TRANSLATE_WM( WM_GETHOTKEY ); }
		case WM_QUERYDRAGICON: { return TRANSLATE_WM( WM_QUERYDRAGICON ); }
		case WM_COMPAREITEM: { return TRANSLATE_WM( WM_COMPAREITEM ); }
		case WM_GETOBJECT: { return TRANSLATE_WM( WM_GETOBJECT ); }
		case WM_COMPACTING: { return TRANSLATE_WM( WM_COMPACTING ); }
		case WM_COMMNOTIFY: { return TRANSLATE_WM( WM_COMMNOTIFY ); }
		case WM_WINDOWPOSCHANGING: { return TRANSLATE_WM( WM_WINDOWPOSCHANGING ); }
		case WM_WINDOWPOSCHANGED: { return TRANSLATE_WM( WM_WINDOWPOSCHANGED ); }
		case WM_POWER: { return TRANSLATE_WM( WM_POWER ); }
		case WM_COPYDATA: { return TRANSLATE_WM( WM_COPYDATA ); }
		case WM_CANCELJOURNAL: { return TRANSLATE_WM( WM_CANCELJOURNAL ); }
		case WM_NOTIFY: { return TRANSLATE_WM( WM_NOTIFY ); }
		case WM_INPUTLANGCHANGEREQUEST: { return TRANSLATE_WM( WM_INPUTLANGCHANGEREQUEST ); }
		case WM_INPUTLANGCHANGE: { return TRANSLATE_WM( WM_INPUTLANGCHANGE ); }
		case WM_TCARD: { return TRANSLATE_WM( WM_TCARD ); }
		case WM_HELP: { return TRANSLATE_WM( WM_HELP ); }
		case WM_USERCHANGED: { return TRANSLATE_WM( WM_USERCHANGED ); }
		case WM_NOTIFYFORMAT: { return TRANSLATE_WM( WM_NOTIFYFORMAT ); }
		case WM_CONTEXTMENU: { return TRANSLATE_WM( WM_CONTEXTMENU ); }
		case WM_STYLECHANGING: { return TRANSLATE_WM( WM_STYLECHANGING ); }
		case WM_STYLECHANGED: { return TRANSLATE_WM( WM_STYLECHANGED ); }
		case WM_DISPLAYCHANGE: { return TRANSLATE_WM( WM_DISPLAYCHANGE ); }
		case WM_GETICON: { return TRANSLATE_WM( WM_GETICON ); }
		case WM_SETICON: { return TRANSLATE_WM( WM_SETICON ); }
		case WM_NCCREATE: { return TRANSLATE_WM( WM_NCCREATE ); }
		case WM_NCDESTROY: { return TRANSLATE_WM( WM_NCDESTROY ); }
		case WM_NCCALCSIZE: { return TRANSLATE_WM( WM_NCCALCSIZE ); }
		case WM_NCHITTEST: { return TRANSLATE_WM( WM_NCHITTEST ); }
		case WM_NCPAINT: { return TRANSLATE_WM( WM_NCPAINT ); }
		case WM_NCACTIVATE: { return TRANSLATE_WM( WM_NCACTIVATE ); }
		case WM_GETDLGCODE: { return TRANSLATE_WM( WM_GETDLGCODE ); }
		case WM_SYNCPAINT: { return TRANSLATE_WM( WM_SYNCPAINT ); }
		case WM_NCMOUSEMOVE: { return TRANSLATE_WM( WM_NCMOUSEMOVE ); }
		case WM_NCLBUTTONDOWN: { return TRANSLATE_WM( WM_NCLBUTTONDOWN ); }
		case WM_NCLBUTTONUP: { return TRANSLATE_WM( WM_NCLBUTTONUP ); }
		case WM_NCLBUTTONDBLCLK: { return TRANSLATE_WM( WM_NCLBUTTONDBLCLK ); }
		case WM_NCRBUTTONDOWN: { return TRANSLATE_WM( WM_NCRBUTTONDOWN ); }
		case WM_NCRBUTTONUP: { return TRANSLATE_WM( WM_NCRBUTTONUP ); }
		case WM_NCRBUTTONDBLCLK: { return TRANSLATE_WM( WM_NCRBUTTONDBLCLK ); }
		case WM_NCMBUTTONDOWN: { return TRANSLATE_WM( WM_NCMBUTTONDOWN ); }
		case WM_NCMBUTTONUP: { return TRANSLATE_WM( WM_NCMBUTTONUP ); }
		case WM_NCMBUTTONDBLCLK: { return TRANSLATE_WM( WM_NCMBUTTONDBLCLK ); }
		case WM_NCXBUTTONDOWN: { return TRANSLATE_WM( WM_NCXBUTTONDOWN ); }
		case WM_NCXBUTTONUP: { return TRANSLATE_WM( WM_NCXBUTTONUP ); }
		case WM_NCXBUTTONDBLCLK: { return TRANSLATE_WM( WM_NCXBUTTONDBLCLK ); }
		case EM_GETSEL: { return TRANSLATE_WM( EM_GETSEL ); }
		case EM_SETSEL: { return TRANSLATE_WM( EM_SETSEL ); }
		case EM_GETRECT: { return TRANSLATE_WM( EM_GETRECT ); }
		case EM_SETRECT: { return TRANSLATE_WM( EM_SETRECT ); }
		case EM_SETRECTNP: { return TRANSLATE_WM( EM_SETRECTNP ); }
		case EM_SCROLL: { return TRANSLATE_WM( EM_SCROLL ); }
		case EM_LINESCROLL: { return TRANSLATE_WM( EM_LINESCROLL ); }
		case EM_SCROLLCARET: { return TRANSLATE_WM( EM_SCROLLCARET ); }
		case EM_GETMODIFY: { return TRANSLATE_WM( EM_GETMODIFY ); }
		case EM_SETMODIFY: { return TRANSLATE_WM( EM_SETMODIFY ); }
		case EM_GETLINECOUNT: { return TRANSLATE_WM( EM_GETLINECOUNT ); }
		case EM_LINEINDEX: { return TRANSLATE_WM( EM_LINEINDEX ); }
		case EM_SETHANDLE: { return TRANSLATE_WM( EM_SETHANDLE ); }
		case EM_GETHANDLE: { return TRANSLATE_WM( EM_GETHANDLE ); }
		case EM_GETTHUMB: { return TRANSLATE_WM( EM_GETTHUMB ); }
		case EM_LINELENGTH: { return TRANSLATE_WM( EM_LINELENGTH ); }
		case EM_REPLACESEL: { return TRANSLATE_WM( EM_REPLACESEL ); }
		case EM_GETLINE: { return TRANSLATE_WM( EM_GETLINE ); }
		case EM_LIMITTEXT: { return TRANSLATE_WM( EM_LIMITTEXT ); }
		case EM_CANUNDO: { return TRANSLATE_WM( EM_CANUNDO ); }
		case EM_UNDO: { return TRANSLATE_WM( EM_UNDO ); }
		case EM_FMTLINES: { return TRANSLATE_WM( EM_FMTLINES ); }
		case EM_LINEFROMCHAR: { return TRANSLATE_WM( EM_LINEFROMCHAR ); }
		case EM_SETTABSTOPS: { return TRANSLATE_WM( EM_SETTABSTOPS ); }
		case EM_SETPASSWORDCHAR: { return TRANSLATE_WM( EM_SETPASSWORDCHAR ); }
		case EM_EMPTYUNDOBUFFER: { return TRANSLATE_WM( EM_EMPTYUNDOBUFFER ); }
		case EM_GETFIRSTVISIBLELINE: { return TRANSLATE_WM( EM_GETFIRSTVISIBLELINE ); }
		case EM_SETREADONLY: { return TRANSLATE_WM( EM_SETREADONLY ); }
		case EM_SETWORDBREAKPROC: { return TRANSLATE_WM( EM_SETWORDBREAKPROC ); }
		case EM_GETWORDBREAKPROC: { return TRANSLATE_WM( EM_GETWORDBREAKPROC ); }
		case EM_GETPASSWORDCHAR: { return TRANSLATE_WM( EM_GETPASSWORDCHAR ); }
		case EM_SETMARGINS: { return TRANSLATE_WM( EM_SETMARGINS ); }
		case EM_GETMARGINS: { return TRANSLATE_WM( EM_GETMARGINS ); }
		case EM_GETLIMITTEXT: { return TRANSLATE_WM( EM_GETLIMITTEXT ); }
		case EM_POSFROMCHAR: { return TRANSLATE_WM( EM_POSFROMCHAR ); }
		case EM_CHARFROMPOS: { return TRANSLATE_WM( EM_CHARFROMPOS ); }
		case EM_SETIMESTATUS: { return TRANSLATE_WM( EM_SETIMESTATUS ); }
		case EM_GETIMESTATUS: { return TRANSLATE_WM( EM_GETIMESTATUS ); }
		case SBM_SETPOS: { return TRANSLATE_WM( SBM_SETPOS ); }
		case SBM_GETPOS: { return TRANSLATE_WM( SBM_GETPOS ); }
		case SBM_SETRANGE: { return TRANSLATE_WM( SBM_SETRANGE ); }
		case SBM_GETRANGE: { return TRANSLATE_WM( SBM_GETRANGE ); }
		case SBM_ENABLE_ARROWS: { return TRANSLATE_WM( SBM_ENABLE_ARROWS ); }
		case SBM_SETRANGEREDRAW: { return TRANSLATE_WM( SBM_SETRANGEREDRAW ); }
		case SBM_SETSCROLLINFO: { return TRANSLATE_WM( SBM_SETSCROLLINFO ); }
		case SBM_GETSCROLLINFO: { return TRANSLATE_WM( SBM_GETSCROLLINFO ); }
		case SBM_GETSCROLLBARINFO: { return TRANSLATE_WM( SBM_GETSCROLLBARINFO ); }
		case BM_GETCHECK: { return TRANSLATE_WM( BM_GETCHECK ); }
		case BM_SETCHECK: { return TRANSLATE_WM( BM_SETCHECK ); }
		case BM_GETSTATE: { return TRANSLATE_WM( BM_GETSTATE ); }
		case BM_SETSTATE: { return TRANSLATE_WM( BM_SETSTATE ); }
		case BM_SETSTYLE: { return TRANSLATE_WM( BM_SETSTYLE ); }
		case BM_CLICK: { return TRANSLATE_WM( BM_CLICK ); }
		case BM_GETIMAGE: { return TRANSLATE_WM( BM_GETIMAGE ); }
		case BM_SETIMAGE: { return TRANSLATE_WM( BM_SETIMAGE ); }
		case BM_SETDONTCLICK: { return TRANSLATE_WM( BM_SETDONTCLICK ); }
		case WM_INPUT: { return TRANSLATE_WM( WM_INPUT ); }
		case WM_KEYDOWN: { return TRANSLATE_WM( WM_KEYDOWN ); }
		case WM_KEYUP: { return TRANSLATE_WM( WM_KEYUP ); }
		case WM_CHAR: { return TRANSLATE_WM( WM_CHAR ); }
		case WM_DEADCHAR: { return TRANSLATE_WM( WM_DEADCHAR ); }
		case WM_SYSKEYDOWN: { return TRANSLATE_WM( WM_SYSKEYDOWN ); }
		case WM_SYSKEYUP: { return TRANSLATE_WM( WM_SYSKEYUP ); }
		case WM_SYSCHAR: { return TRANSLATE_WM( WM_SYSCHAR ); }
		case WM_SYSDEADCHAR: { return TRANSLATE_WM( WM_SYSDEADCHAR ); }
		case WM_UNICHAR: { return TRANSLATE_WM( WM_UNICHAR ); }
		case WM_IME_STARTCOMPOSITION: { return TRANSLATE_WM( WM_IME_STARTCOMPOSITION ); }
		case WM_IME_ENDCOMPOSITION: { return TRANSLATE_WM( WM_IME_ENDCOMPOSITION ); }
		case WM_IME_COMPOSITION: { return TRANSLATE_WM( WM_IME_COMPOSITION ); }
		case WM_INITDIALOG: { return TRANSLATE_WM( WM_INITDIALOG ); }
		case WM_COMMAND: { return TRANSLATE_WM( WM_COMMAND ); }
		case WM_SYSCOMMAND: { return TRANSLATE_WM( WM_SYSCOMMAND ); }
		case WM_TIMER: { return TRANSLATE_WM( WM_TIMER ); }
		case WM_HSCROLL: { return TRANSLATE_WM( WM_HSCROLL ); }
		case WM_VSCROLL: { return TRANSLATE_WM( WM_VSCROLL ); }
		case WM_INITMENU: { return TRANSLATE_WM( WM_INITMENU ); }
		case WM_INITMENUPOPUP: { return TRANSLATE_WM( WM_INITMENUPOPUP ); }
		case WM_MENUSELECT: { return TRANSLATE_WM( WM_MENUSELECT ); }
		case WM_MENUCHAR: { return TRANSLATE_WM( WM_MENUCHAR ); }
		case WM_ENTERIDLE: { return TRANSLATE_WM( WM_ENTERIDLE ); }
		case WM_MENURBUTTONUP: { return TRANSLATE_WM( WM_MENURBUTTONUP ); }
		case WM_MENUDRAG: { return TRANSLATE_WM( WM_MENUDRAG ); }
		case WM_MENUGETOBJECT: { return TRANSLATE_WM( WM_MENUGETOBJECT ); }
		case WM_UNINITMENUPOPUP: { return TRANSLATE_WM( WM_UNINITMENUPOPUP ); }
		case WM_MENUCOMMAND: { return TRANSLATE_WM( WM_MENUCOMMAND ); }
		case WM_CHANGEUISTATE: { return TRANSLATE_WM( WM_CHANGEUISTATE ); }
		case WM_UPDATEUISTATE: { return TRANSLATE_WM( WM_UPDATEUISTATE ); }
		case WM_QUERYUISTATE: { return TRANSLATE_WM( WM_QUERYUISTATE ); }
		case WM_CTLCOLORMSGBOX: { return TRANSLATE_WM( WM_CTLCOLORMSGBOX ); }
		case WM_CTLCOLOREDIT: { return TRANSLATE_WM( WM_CTLCOLOREDIT ); }
		case WM_CTLCOLORLISTBOX: { return TRANSLATE_WM( WM_CTLCOLORLISTBOX ); }
		case WM_CTLCOLORBTN: { return TRANSLATE_WM( WM_CTLCOLORBTN ); }
		case WM_CTLCOLORDLG: { return TRANSLATE_WM( WM_CTLCOLORDLG ); }
		case WM_CTLCOLORSCROLLBAR: { return TRANSLATE_WM( WM_CTLCOLORSCROLLBAR ); }
		case WM_CTLCOLORSTATIC: { return TRANSLATE_WM( WM_CTLCOLORSTATIC ); }
		case WM_MOUSEMOVE: { return TRANSLATE_WM( WM_MOUSEMOVE ); }
		case WM_LBUTTONDOWN: { return TRANSLATE_WM( WM_LBUTTONDOWN ); }
		case WM_LBUTTONUP: { return TRANSLATE_WM( WM_LBUTTONUP ); }
		case WM_LBUTTONDBLCLK: { return TRANSLATE_WM( WM_LBUTTONDBLCLK ); }
		case WM_RBUTTONDOWN: { return TRANSLATE_WM( WM_RBUTTONDOWN ); }
		case WM_RBUTTONUP: { return TRANSLATE_WM( WM_RBUTTONUP ); }
		case WM_RBUTTONDBLCLK: { return TRANSLATE_WM( WM_RBUTTONDBLCLK ); }
		case WM_MBUTTONDOWN: { return TRANSLATE_WM( WM_MBUTTONDOWN ); }
		case WM_MBUTTONUP: { return TRANSLATE_WM( WM_MBUTTONUP ); }
		case WM_MBUTTONDBLCLK: { return TRANSLATE_WM( WM_MBUTTONDBLCLK ); }
		case WM_MOUSELAST: { return TRANSLATE_WM( WM_MOUSELAST ); }
		case WM_MOUSEWHEEL: { return TRANSLATE_WM( WM_MOUSEWHEEL ); }
		case WM_XBUTTONDOWN: { return TRANSLATE_WM( WM_XBUTTONDOWN ); }
		case WM_XBUTTONUP: { return TRANSLATE_WM( WM_XBUTTONUP ); }
		case WM_XBUTTONDBLCLK: { return TRANSLATE_WM( WM_XBUTTONDBLCLK ); }
		case WM_PARENTNOTIFY: { return TRANSLATE_WM( WM_PARENTNOTIFY ); }
		case WM_ENTERMENULOOP: { return TRANSLATE_WM( WM_ENTERMENULOOP ); }
		case WM_EXITMENULOOP: { return TRANSLATE_WM( WM_EXITMENULOOP ); }
		case WM_NEXTMENU: { return TRANSLATE_WM( WM_NEXTMENU ); }
		case WM_SIZING: { return TRANSLATE_WM( WM_SIZING ); }
		case WM_CAPTURECHANGED: { return TRANSLATE_WM( WM_CAPTURECHANGED ); }
		case WM_MOVING: { return TRANSLATE_WM( WM_MOVING ); }
		case WM_POWERBROADCAST: { return TRANSLATE_WM( WM_POWERBROADCAST ); }
		case WM_DEVICECHANGE: { return TRANSLATE_WM( WM_DEVICECHANGE ); }
		case WM_MDICREATE: { return TRANSLATE_WM( WM_MDICREATE ); }
		case WM_MDIDESTROY: { return TRANSLATE_WM( WM_MDIDESTROY ); }
		case WM_MDIACTIVATE: { return TRANSLATE_WM( WM_MDIACTIVATE ); }
		case WM_MDIRESTORE: { return TRANSLATE_WM( WM_MDIRESTORE ); }
		case WM_MDINEXT: { return TRANSLATE_WM( WM_MDINEXT ); }
		case WM_MDIMAXIMIZE: { return TRANSLATE_WM( WM_MDIMAXIMIZE ); }
		case WM_MDITILE: { return TRANSLATE_WM( WM_MDITILE ); }
		case WM_MDICASCADE: { return TRANSLATE_WM( WM_MDICASCADE ); }
		case WM_MDIICONARRANGE: { return TRANSLATE_WM( WM_MDIICONARRANGE ); }
		case WM_MDIGETACTIVE: { return TRANSLATE_WM( WM_MDIGETACTIVE ); }
		case WM_MDISETMENU: { return TRANSLATE_WM( WM_MDISETMENU ); }
		case WM_ENTERSIZEMOVE: { return TRANSLATE_WM( WM_ENTERSIZEMOVE ); }
		case WM_EXITSIZEMOVE: { return TRANSLATE_WM( WM_EXITSIZEMOVE ); }
		case WM_DROPFILES: { return TRANSLATE_WM( WM_DROPFILES ); }
		case WM_MDIREFRESHMENU: { return TRANSLATE_WM( WM_MDIREFRESHMENU ); }
		case WM_IME_SETCONTEXT: { return TRANSLATE_WM( WM_IME_SETCONTEXT ); }
		case WM_IME_NOTIFY: { return TRANSLATE_WM( WM_IME_NOTIFY ); }
		case WM_IME_CONTROL: { return TRANSLATE_WM( WM_IME_CONTROL ); }
		case WM_IME_COMPOSITIONFULL: { return TRANSLATE_WM( WM_IME_COMPOSITIONFULL ); }
		case WM_IME_SELECT: { return TRANSLATE_WM( WM_IME_SELECT ); }
		case WM_IME_CHAR: { return TRANSLATE_WM( WM_IME_CHAR ); }
		case WM_IME_REQUEST: { return TRANSLATE_WM( WM_IME_REQUEST ); }
		case WM_IME_KEYDOWN: { return TRANSLATE_WM( WM_IME_KEYDOWN ); }
		case WM_IME_KEYUP: { return TRANSLATE_WM( WM_IME_KEYUP ); }
		case WM_NCMOUSEHOVER: { return TRANSLATE_WM( WM_NCMOUSEHOVER ); }
		case WM_MOUSEHOVER: { return TRANSLATE_WM( WM_MOUSEHOVER ); }
		case WM_NCMOUSELEAVE: { return TRANSLATE_WM( WM_NCMOUSELEAVE ); }
		case WM_MOUSELEAVE: { return TRANSLATE_WM( WM_MOUSELEAVE ); }
		case WM_CUT: { return TRANSLATE_WM( WM_CUT ); }
		case WM_COPY: { return TRANSLATE_WM( WM_COPY ); }
		case WM_PASTE: { return TRANSLATE_WM( WM_PASTE ); }
		case WM_CLEAR: { return TRANSLATE_WM( WM_CLEAR ); }
		case WM_UNDO: { return TRANSLATE_WM( WM_UNDO ); }
		case WM_RENDERFORMAT: { return TRANSLATE_WM( WM_RENDERFORMAT ); }
		case WM_RENDERALLFORMATS: { return TRANSLATE_WM( WM_RENDERALLFORMATS ); }
		case WM_DESTROYCLIPBOARD: { return TRANSLATE_WM( WM_DESTROYCLIPBOARD ); }
		case WM_DRAWCLIPBOARD: { return TRANSLATE_WM( WM_DRAWCLIPBOARD ); }
		case WM_PAINTCLIPBOARD: { return TRANSLATE_WM( WM_PAINTCLIPBOARD ); }
		case WM_VSCROLLCLIPBOARD: { return TRANSLATE_WM( WM_VSCROLLCLIPBOARD ); }
		case WM_SIZECLIPBOARD: { return TRANSLATE_WM( WM_SIZECLIPBOARD ); }
		case WM_ASKCBFORMATNAME: { return TRANSLATE_WM( WM_ASKCBFORMATNAME ); }
		case WM_CHANGECBCHAIN: { return TRANSLATE_WM( WM_CHANGECBCHAIN ); }
		case WM_HSCROLLCLIPBOARD: { return TRANSLATE_WM( WM_HSCROLLCLIPBOARD ); }
		case WM_QUERYNEWPALETTE: { return TRANSLATE_WM( WM_QUERYNEWPALETTE ); }
		case WM_PALETTEISCHANGING: { return TRANSLATE_WM( WM_PALETTEISCHANGING ); }
		case WM_PALETTECHANGED: { return TRANSLATE_WM( WM_PALETTECHANGED ); }
		case WM_HOTKEY: { return TRANSLATE_WM( WM_HOTKEY ); }
		case WM_PRINT: { return TRANSLATE_WM( WM_PRINT ); }
		case WM_PRINTCLIENT: { return TRANSLATE_WM( WM_PRINTCLIENT ); }
		case WM_APPCOMMAND: { return TRANSLATE_WM( WM_APPCOMMAND ); }
		case WM_HANDHELDFIRST: { return TRANSLATE_WM( WM_HANDHELDFIRST ); }
		case WM_HANDHELDLAST: { return TRANSLATE_WM( WM_HANDHELDLAST ); }
		case WM_AFXFIRST: { return TRANSLATE_WM( WM_AFXFIRST ); }
		case WM_AFXLAST: { return TRANSLATE_WM( WM_AFXLAST ); }
		case WM_PENWINFIRST: { return TRANSLATE_WM( WM_PENWINFIRST ); }
		case WM_PENWINLAST: { return TRANSLATE_WM( WM_PENWINLAST ); }
		case WM_APP: { return TRANSLATE_WM( WM_APP ); }
		default: return L"Unknown";
	}
};

#undef TRANSLATE_WM
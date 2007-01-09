/************************************************************

$RCSfile: lgewire.h,v $

Copyright (c) 2006, Sun Microsystems, Inc. 

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from The Open Group.

$Revision: 1.1.4.2 $
$Date: 2006/01/18 18:51:05 $
$State: Exp $

********************************************************/

/*
 * lge.h - Looking Glass Extension Definitions
 */
 
#ifndef _LGEWIRE_H
#define _LGEWIRE_H

#include "X11/Xfuncproto.h"

#define LGE_NAME "LGE"

/* Current interface version numbers */
#define LGE_MAJOR_VERSION   6      
#define LGE_MINOR_VERSION   0

/* Display Server is alive */
#define  X_LgeQueryVersion	     0
#define  X_LgeRegisterClient         1
#define  X_LgeRegisterScreen         2
#define  X_LgeControlLgMode          3
#define  X_LgeSendEvent              4
#define  X_LgeInputContextCreate     5
#define  X_LgeInputContextDestroy    6
#define  X_LgeInputContextBindClient 7
#define  X_LgeInputContextSendEvent  8

/* Arguments to XLgeRegisterClient */
#define LGE_CLIENT_GENERIC	     0
#define LGE_CLIENT_PICKER            1
#define LGE_CLIENT_EVENT_DELIVERER   2

typedef XID InputContext;

typedef struct {
    CARD8       reqType;		
    CARD8       lgeReqType;
    CARD16	length B16;
} xLgeQueryVersionReq;

#define sz_xLgeQueryVersionReq	sizeof(xLgeQueryVersionReq)

typedef struct {
    /* Always X_Reply */
    BYTE        type;			
    CARD8       unused;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD32	majorVersion B32;
    CARD32	minorVersion B32;
    CARD32      implementation B32;
    CARD32	pad3 B32;
    CARD32	pad4 B32;
    CARD32	pad5 B32;
} xLgeQueryVersionReply;

#define sz_xLgeQueryVersionReply sizeof(xLgeQueryVersionReply)

typedef struct {
    CARD8  reqType;
    CARD8  lgeReqType;
    CARD16 length B16;
    CARD8  clientType;
    BOOL   sendEventDirect;
    CARD16 pad2 B16;
} xLgeRegisterClientReq;

#define sz_xLgeRegisterClientReq sizeof(xLgeRegisterClientReq)

typedef struct {
    CARD8  reqType;
    CARD8  lgeReqType;
    CARD16 length B16;
    /* The pseudo-root window of the screen */
    Window prw;  
} xLgeRegisterScreenReq;

#define sz_xLgeRegisterScreenReq sizeof(xLgeRegisterScreenReq)

typedef struct {                                            
    CARD8     reqType;                                               
    CARD8     lgeReqType;                                          
    CARD16    length B16;                                            
    BOOL      enable;
    CARD8     pad1;
    CARD16    pad2 B16;
} xLgeControlLgModeReq;                                                       

#define sz_xLgeControlLgModeReq sizeof(xLgeControlLgModeReq)

typedef struct {                                            
    CARD8     reqType;                                               
    CARD8     lgeReqType;                                          
    CARD16    length B16;                                            
    xEvent    event;                                                 
} xLgeSendEventReq;                                                       

#define sz_xLgeSendEventReq sizeof(xLgeSendEventReq)

typedef struct {                                            
    CARD8        reqType;                                               
    CARD8        lgeReqType;                                          
    CARD16       length B16;                                            
    InputContext ictx;
} xLgeInputContextCreateReq;                                                       

#define sz_xLgeInputContextCreateReq sizeof(xLgeInputContextCreateReq)

typedef struct {                                            
    CARD8        reqType;                                               
    CARD8        lgeReqType;                                          
    CARD16       length B16;                                            
    InputContext ictx;
} xLgeInputContextDestroyReq;                                                       

#define sz_xLgeInputContextDestroyReq sizeof(xLgeInputContextDestroyReq)

typedef struct {                                            
    CARD8        reqType;                                               
    CARD8        lgeReqType;                                          
    CARD16       length B16;                                            
    InputContext ictx;
    Window       win;
} xLgeInputContextBindClientReq;                                                       

#define sz_xLgeInputContextBindClientReq sizeof(xLgeInputContextBindClientReq)

typedef struct {                                            
    CARD8        reqType;                                               
    CARD8        lgeReqType;                                          
    CARD16       length B16;                                            
    InputContext ictx;
    xEvent       event;                                                 
} xLgeInputContextSendEventReq;                                                       

#define sz_xLgeInputContextSendEventReq sizeof(xLgeInputContextSendEventReq)

#endif /* LGEWIRE_H */


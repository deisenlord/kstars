/*  INDI Device
    Copyright (C) 2003 Jasem Mutlaq (mutlaqja@ikarustech.com)
    		       Elwood C. Downey

    This application is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.
 */

#ifndef INDIDEVICE_H
#define INDIDEVICE_H

#include <kdialogbase.h>
#include <unistd.h>
#include <tqptrlist.h>

#include "indielement.h"

class DeviceManager;
class INDI_D;
class INDI_P;
class INDI_G;
class INDI_E;
class INDIMenu;
class INDIStdDevice;
class SkyObject;

class KLed;
class KLineEdit;
class KComboBox;
class KDoubleSpinBox;
class KPushButton;
class KPopupMenu;

class TQTable;
class TQLabel;
class TQHBoxLayout;
class TQVBoxLayout;
class TQFrame;
class TQLineEdit;
class TQString;
class TQTextEdit;
class TQListView;
class TQTabWidget;
class TQSpacerItem;
class TQGridLayout;
class TQButtonGroup;
class TQCheckBox;
class TQScrollView;
class TQSocketNotifier;
class TQVBox;

/*************************************************************************
** The INDI Tree
**
** INDI_ELEMENT <----------------------------------------
**     |						|
**     -----> INDI_PROPERTY				|
**                        |				|
**                        -----> INDI_GROUP		|
**                                        |		|
**                                        -----> INDI_DEVICE
**                                               |         |
                                          Device Manager  INDI Menu
**************************************************************************/


/* INDI device */
class INDI_D : public KDialogBase  
{
 Q_OBJECT
  public:
   INDI_D(INDIMenu *parentMenu, DeviceManager *parentManager, TQString inName, TQString inLabel);
   ~INDI_D();

    TQString 	name;			/* device name */
    QString	label;			/* device label */
    QVBox	*deviceVBox;		/* device tab frame */
    TQTabWidget  *groupContainer;	/* Groups within the device */
    QTextEdit	*msgST_w;		/* scrolled text for messages */
    unsigned char *dataBuffer;          /* Generic buffer */
    //TQScrollView *sv;			/* Scroll view */
    //TQVBoxLayout *mainLayout;
    //TQVBox       *propertyLayout;
    //TQSpacerItem *vSpacer;
    //TQSpacerItem *hSpacer;

    //TQPushButton  *clear;
    //TQHBoxLayout  *buttonLayout;
    INDIStdDevice  *stdDev;

    TQPtrList<INDI_G> gl;		/* list of pointers to groups */
  
    INDI_G        *curGroup;
    bool	  INDIStdSupport;

    INDIMenu      *parent;
    DeviceManager *parentMgr;
    
    enum DTypes { DATA_FITS, DATA_STREAM, DATA_OTHER, DATA_CCDPREVIEW };

   /*****************************************************************
   * Build
   ******************************************************************/
   int buildTextGUI    (XMLEle *root, char errmsg[]);
   int buildNumberGUI  (XMLEle *root, char errmsg[]);
   int buildSwitchesGUI(XMLEle *root, char errmsg[]);
   int buildMenuGUI    (INDI_P *pp, XMLEle *root, char errmsg[]);
   int buildLightsGUI  (XMLEle *root, char errmsg[]);
   int buildBLOBGUI    (XMLEle *root, char errmsg[]);
   
   /*****************************************************************
   * Add
   ******************************************************************/
   INDI_P *  addProperty (XMLEle *root, char errmsg[]);

   /*****************************************************************
   * Find
   ******************************************************************/
   INDI_P *   findProp    (TQString name);
   INDI_E *   findElem    (TQString name);
   INDI_G *   findGroup   (TQString grouptag, int create, char errmsg[]);
   int        findPerm    (INDI_P *pp  , XMLEle *root, PPerm *permp, char errmsg[]);

   /*****************************************************************
   * Set/New
   ******************************************************************/
   int setValue       (INDI_P *pp, XMLEle *root, char errmsg[]);
   int setLabelState  (INDI_P *pp, XMLEle *root, char errmsg[]);
   int setTextValue   (INDI_P *pp, XMLEle *root, char errmsg[]);
   int setBLOB        (INDI_P *pp, XMLEle * root, char errmsg[]);
       
   int newValue       (INDI_P *pp, XMLEle *root, char errmsg[]);
   int newTextValue   (INDI_P *pp, XMLEle *root, char errmsg[]);

   int setAnyCmd      (XMLEle *root, char errmsg[]);
   int newAnyCmd      (XMLEle *root, char errmsg[]);

   int  removeProperty(INDI_P *pp);

   /*****************************************************************
   * Crack
   ******************************************************************/
   int crackLightState  (char *name, PState *psp);
   int crackSwitchState (char *name, PState *psp);
   
   /*****************************************************************
   * Data processing
   ******************************************************************/
   int processBlob(INDI_E *blobEL, XMLEle *ep, char errmsg[]);
   
   /*****************************************************************
   * INDI standard property policy
   ******************************************************************/
   bool isOn();
   void registerProperty(INDI_P *pp);
   bool isINDIStd(INDI_P *pp);

};

#endif

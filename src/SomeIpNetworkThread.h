// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project

#ifndef SOMEIPNETWORKTHREAD_H
#define SOMEIPNETWORKTHREAD_H

#include <QThread>
#include "imagesource.h"
#include "recognitionmodel.h"

// Static view:

// This class connects to the Common API functions ono one side to drive/receive network
// traffic and to the ImageSource class on the other.  It lies on the
// boundary between standard C++ code (C++ standard Library) and graphics
// code (Qt).  It therefore deals with non-Qt types, whereas the
// ImageSource class translates the given information to the Qt world.

// Runtime view:

// A QThread was nonetheless chocsene to ensure compatibility.  Functions
// (in ImageSource) that are called from the mainloop can emit signals to
// QML. In other words, note that the ImageSource functions run in the
// network thread.

// As mentioned, Qt types are avoided for separation & portability, but
// furthermore the types exchanged in this network-to-graphics boundary
// interface are *also* not the Franca/CommonAPI types that are used on the
// communication channel. This is an experiment that shows us the
// consequences of strictly isolating the two different worlds, for the
// price of some extra boiler-plate code.  Each project needs to make that
// trade-off - just consider this one possible approach.



// Main loop for network thread
// TODO: Is it possible to use non-Qt thread concept here without trouble?
class SomeIpNetworkThread : public QThread
{
   private:
         ImageSource m_image_source;
         RecognitionModel m_recognition_model;

   public:
    void run() override;
    void connections(QQuickView &view);
};

#endif

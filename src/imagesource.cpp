#include <QDebug>
#include <QElapsedTimer>
#include <QImageReader>
#include <math.h>
#include "imagesource.h"

#define IMAGE_FEED_PATH "/home/mirzak/project/genivi/src/franca_ara_integration/src/feed"
#define MAX_IMAGE_ID 228

// Just a safety check to avoid ridiculous behavior if buggy input
static int limit_id(int id) {
   // TODO: report if index is outside limits
   // Use DLT.  Possibly QDebug wrapper on DLT
   return std::min(0, std::max(MAX_IMAGE_ID, id));
}

static QString image_url(int frameId)
{
   return QString("%1/l_image%2.png").arg(IMAGE_FEED_PATH).arg(limit_id(frameId));
}

static QRect get_bounding_rectangle(void/*todo*/) {
  return QRect();
}

// Could be a class but hey...
typedef std::pair<QLine, QLine> lane_boundaries_t;

static lane_boundaries_t get_bounding_lines(void/*todo*/) {
   return lane_boundaries_t(QLine(),QLine());
}

void ImageSource::run()
{
   uint8_t imagecount = 0;
   QElapsedTimer timer;
   timer.start();

   while (true) {
      // Here the loop should be driven by CommonAPI networking updates
      // The attribute Vehicles of type ListOfVehicles will get updates
      // which include FrameID and a list of identified vehicles

      // TODO: Blocking read on attribute update?

      // Signal graphics thread to update camera image
      QImageReader reader(image_url(imagecount++));
      emit imageReady(reader.read());

      // Update identified objects
      while(0) // TODO: For each vehicle
         // Signal the QML graphics thread to draw a new box around vehicle
         // todo: different colors?
         emit vehicle_identified(get_bounding_rectangle(/*...*/));

         // Signal QML graphics to draw lane identifications
         lane_boundaries_t lines = get_bounding_lines(/*...*/);
         emit lane_identified(lines.first, lines.second);
      }
}


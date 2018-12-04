#ifndef _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_itk_scenario2_portinterfaces_video_skeleton_h
#define _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_itk_scenario2_portinterfaces_video_skeleton_h

#include "ara/com/internal/skeleton/ara_skeleton_base.h"

#include "ara/com/illegal_state_exception.h"
#include "video_common.h"

namespace itk {
namespace scenario2 {
namespace portinterfaces {
namespace skeleton {

namespace events {
using VideoData = ara::com::internal::skeleton::EventDispatcher<::ByteArray>;
} // namespace events

class VideoSkeleton : public itk::scenario2::portinterfaces::Video, public ara::com::internal::skeleton::TypedServiceImplBase<VideoSkeleton> {
 public:
  /**
   * \uptrace{SWS_CM_00130}
   */
  VideoSkeleton(ara::com::InstanceIdentifier instance_id, ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent) : ara::com::internal::skeleton::TypedServiceImplBase<VideoSkeleton>(instance_id, mode) {}
  virtual ~VideoSkeleton() {
    StopOfferService();
  }

  /**
   * \brief Skeleton shall be move constructable.
   */
  explicit VideoSkeleton(VideoSkeleton&&) = default;

  /**
   * \brief Skeleton shall be move assignable.
   */
  VideoSkeleton& operator=(VideoSkeleton&&) = default;

  /**
   * \brief Skeleton shall not be copy constructable.
   */
  explicit VideoSkeleton(const VideoSkeleton&) = delete;

  /**
   * \brief Skeleton shall not be copy assignable.
   */
  VideoSkeleton& operator=(const VideoSkeleton&) = delete;

  void OfferService() {

    ara::com::internal::skeleton::TypedServiceImplBase<VideoSkeleton>::OfferService();
  }

  events::VideoData VideoData;
};

} // namespace skeleton
} // namespace portinterfaces
} // namespace scenario2
} // namespace itk

#endif // _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_itk_scenario2_portinterfaces_video_skeleton_h


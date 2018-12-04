#ifndef _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_idrivinglane_proxy_h
#define _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_idrivinglane_proxy_h

#include "ara/com/internal/proxy/ara_proxy_base.h"
#include "idrivinglane_common.h"

namespace genivi {
namespace aasr {
namespace showcase {
namespace proxy {

namespace events {
using LaneDetected = ara::com::internal::proxy::Event<::genivi::aasr::showcase::Lane>;
} // namespace events

class IDrivingLaneProxyBase : public ara::com::internal::proxy::ProxyBindingBase, public genivi::aasr::showcase::IDrivingLane {
 public:
  virtual events::LaneDetected& GetLaneDetected() = 0;
};

class IDrivingLaneProxy : public ara::com::internal::proxy::ProxyBase<IDrivingLaneProxyBase>, public genivi::aasr::showcase::IDrivingLane {

private:
public:
  explicit IDrivingLaneProxy(const HandleType& proxy_base_factory) :
      ara::com::internal::proxy::ProxyBase<IDrivingLaneProxyBase>(proxy_base_factory),
      LaneDetected(proxy_base_->GetLaneDetected())
  {}

  /**
   * \brief Proxy shall be move constructable.
   */
  explicit IDrivingLaneProxy(IDrivingLaneProxy&&) = default;

  /**
   * \brief Proxy shall be move assignable.
   */
  IDrivingLaneProxy& operator=(IDrivingLaneProxy&&) = default;

  /**
   * \brief Proxy shall not be copy constructable.
   */
  explicit IDrivingLaneProxy(const IDrivingLaneProxy&) = delete;

  /**
   * \brief Proxy shall not be copy assignable.
   */
  IDrivingLaneProxy& operator=(const IDrivingLaneProxy&) = delete;

  events::LaneDetected& LaneDetected;
};

} // namespace proxy
} // namespace showcase
} // namespace aasr
} // namespace genivi

#endif // _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_idrivinglane_proxy_h


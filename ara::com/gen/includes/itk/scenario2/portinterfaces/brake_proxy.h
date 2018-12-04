#ifndef _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_itk_scenario2_portinterfaces_brake_proxy_h
#define _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_itk_scenario2_portinterfaces_brake_proxy_h

#include "ara/com/internal/proxy/ara_proxy_base.h"
#include "brake_common.h"

namespace itk {
namespace scenario2 {
namespace portinterfaces {
namespace proxy {

namespace events {
using BrakeSignal = ara::com::internal::proxy::Event<::itk::scenario2::BrakeSignalType>;
} // namespace events

class BrakeProxyBase : public ara::com::internal::proxy::ProxyBindingBase, public itk::scenario2::portinterfaces::Brake {
 public:
  virtual events::BrakeSignal& GetBrakeSignal() = 0;
};

class BrakeProxy : public ara::com::internal::proxy::ProxyBase<BrakeProxyBase>, public itk::scenario2::portinterfaces::Brake {

private:
public:
  explicit BrakeProxy(const HandleType& proxy_base_factory) :
      ara::com::internal::proxy::ProxyBase<BrakeProxyBase>(proxy_base_factory),
      BrakeSignal(proxy_base_->GetBrakeSignal())
  {}

  /**
   * \brief Proxy shall be move constructable.
   */
  explicit BrakeProxy(BrakeProxy&&) = default;

  /**
   * \brief Proxy shall be move assignable.
   */
  BrakeProxy& operator=(BrakeProxy&&) = default;

  /**
   * \brief Proxy shall not be copy constructable.
   */
  explicit BrakeProxy(const BrakeProxy&) = delete;

  /**
   * \brief Proxy shall not be copy assignable.
   */
  BrakeProxy& operator=(const BrakeProxy&) = delete;

  events::BrakeSignal& BrakeSignal;
};

} // namespace proxy
} // namespace portinterfaces
} // namespace scenario2
} // namespace itk

#endif // _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_itk_scenario2_portinterfaces_brake_proxy_h


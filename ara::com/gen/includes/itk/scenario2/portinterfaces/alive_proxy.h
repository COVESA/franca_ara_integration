#ifndef _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_itk_scenario2_portinterfaces_alive_proxy_h
#define _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_itk_scenario2_portinterfaces_alive_proxy_h

#include "ara/com/internal/proxy/ara_proxy_base.h"
#include "alive_common.h"

namespace itk {
namespace scenario2 {
namespace portinterfaces {
namespace proxy {

namespace events {
using Id = ara::com::internal::proxy::Event<::UInt8>;
} // namespace events

class AliveProxyBase : public ara::com::internal::proxy::ProxyBindingBase, public itk::scenario2::portinterfaces::Alive {
 public:
  virtual events::Id& GetId() = 0;
};

class AliveProxy : public ara::com::internal::proxy::ProxyBase<AliveProxyBase>, public itk::scenario2::portinterfaces::Alive {

private:
public:
  explicit AliveProxy(const HandleType& proxy_base_factory) :
      ara::com::internal::proxy::ProxyBase<AliveProxyBase>(proxy_base_factory),
      Id(proxy_base_->GetId())
  {}

  /**
   * \brief Proxy shall be move constructable.
   */
  explicit AliveProxy(AliveProxy&&) = default;

  /**
   * \brief Proxy shall be move assignable.
   */
  AliveProxy& operator=(AliveProxy&&) = default;

  /**
   * \brief Proxy shall not be copy constructable.
   */
  explicit AliveProxy(const AliveProxy&) = delete;

  /**
   * \brief Proxy shall not be copy assignable.
   */
  AliveProxy& operator=(const AliveProxy&) = delete;

  events::Id& Id;
};

} // namespace proxy
} // namespace portinterfaces
} // namespace scenario2
} // namespace itk

#endif // _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_itk_scenario2_portinterfaces_alive_proxy_h


#ifndef _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_ivehicles_proxy_h
#define _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_ivehicles_proxy_h

#include "ara/com/internal/proxy/ara_proxy_base.h"
#include "ivehicles_common.h"

namespace genivi {
namespace aasr {
namespace showcase {
namespace proxy {

namespace methods {
using SetFloatingPointPrecision = ara::com::internal::proxy::Method<genivi::aasr::showcase::IVehicles::SetFloatingPointPrecisionOutput(const ::genivi::aasr::showcase::FloatingPointPrecision&)>;
} // namespace methods
namespace fields {
using VehiclesField = ara::com::internal::proxy::Field<::genivi::aasr::showcase::ListOfVehicles>;
template <typename T, bool E2E = ara::com::internal::e2e::is_e2e_enabled<T>::value>
class VehiclesProxy {
private:
  VehiclesField& field;

public:
  explicit VehiclesProxy(VehiclesField& Vehicles) : field(Vehicles)
  ,Get(Vehicles.Get)
  { }

  // Event Base.
  void Subscribe(ara::com::EventCacheUpdatePolicy policy, std::size_t cacheSize) {
    field.Subscribe(policy, cacheSize);
  }
  
  bool IsSubscribed() const {
    return field.IsSubscribed();
  }

  void Unsubscribe() {
    return field.Unsubscribe();
  }

  void Cleanup() {
    field.Cleanup();
  }

  void SetReceiveHandler(ara::com::EventReceiveHandler handler) {
    field.SetReceiveHandler(handler);
  }

  void UnsetReceiveHandler() {
    field.UnsetReceiveHandler();
  }

  void SetSubscriptionStateChangeHandler(ara::com::SubscriptionStateChangeHandler handler) {
    field.SetSubscriptionStateChangeHandler(handler);
  }

  void UnsetSubscriptionStateChangeHandler() {
    field.UnsetSubscriptionStateChangeHandler();
  }

  using container_type = VehiclesField::container_type;

  // Event.
  bool Update() {
    return field.Update();
  }

  bool Update(ara::com::FilterFunction<T> filter) {
    return field.Update(filter);
  }

  const container_type &GetCachedSamples() const {
    return field.GetCachedSamples();
  }

  template <typename U=T, typename = std::enable_if_t<E2E, U>>
  ara::com::e2exf::E2EResult GetE2EResult() const noexcept {
    return field.GetE2EResult();
  }

  // Field.
  using GetResultType = VehiclesField::GetResultType;
  using Output = GetResultType;
  using MethodGet = ara::com::internal::proxy::Method<GetResultType()>;
  MethodGet &Get;

};
using Vehicles = VehiclesProxy<::genivi::aasr::showcase::ListOfVehicles>;
} // namespace fields

class IVehiclesProxyBase : public ara::com::internal::proxy::ProxyBindingBase, public genivi::aasr::showcase::IVehicles {
 public:
  virtual methods::SetFloatingPointPrecision& GetSetFloatingPointPrecision() = 0;
  virtual fields::VehiclesField& GetVehicles() = 0;
};

class IVehiclesProxy : public ara::com::internal::proxy::ProxyBase<IVehiclesProxyBase>, public genivi::aasr::showcase::IVehicles {

private:
  fields::VehiclesField& VehiclesField;
public:
  explicit IVehiclesProxy(const HandleType& proxy_base_factory) :
      ara::com::internal::proxy::ProxyBase<IVehiclesProxyBase>(proxy_base_factory),
      VehiclesField(proxy_base_->GetVehicles()),
      SetFloatingPointPrecision(proxy_base_->GetSetFloatingPointPrecision()),
      Vehicles(VehiclesField)
  {}

  /**
   * \brief Proxy shall be move constructable.
   */
  explicit IVehiclesProxy(IVehiclesProxy&&) = default;

  /**
   * \brief Proxy shall be move assignable.
   */
  IVehiclesProxy& operator=(IVehiclesProxy&&) = default;

  /**
   * \brief Proxy shall not be copy constructable.
   */
  explicit IVehiclesProxy(const IVehiclesProxy&) = delete;

  /**
   * \brief Proxy shall not be copy assignable.
   */
  IVehiclesProxy& operator=(const IVehiclesProxy&) = delete;

  methods::SetFloatingPointPrecision& SetFloatingPointPrecision;
  fields::Vehicles Vehicles;
};

} // namespace proxy
} // namespace showcase
} // namespace aasr
} // namespace genivi

#endif // _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_ivehicles_proxy_h


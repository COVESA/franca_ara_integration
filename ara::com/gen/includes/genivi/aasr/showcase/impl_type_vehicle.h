#ifndef _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_impl_type_vehicle_h
#define _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_impl_type_vehicle_h

#include "impl_type_uint8.h"
#include "genivi/aasr/showcase/impl_type_flexiblefloatingpointcontainer.h"
namespace genivi {
namespace aasr {
namespace showcase {

struct Vehicle {
  ::UInt8 id;
  ::genivi::aasr::showcase::FlexibleFloatingPointContainer currentDistance;
  ::genivi::aasr::showcase::FlexibleFloatingPointContainer collisionTime;

  using IsEnumerableTag = void;
  template<typename F>
  void enumerate(F& fun) {
    fun(id);
    fun(currentDistance);
    fun(collisionTime);
  }
};
} // namespace showcase
} // namespace aasr
} // namespace genivi

#endif // _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_impl_type_vehicle_h


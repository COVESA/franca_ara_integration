#ifndef _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_impl_type_flexiblefloatingpointcontainer_h
#define _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_impl_type_flexiblefloatingpointcontainer_h

#include "genivi/aasr/showcase/impl_type_flexiblefloatingpoint.h"
#include "genivi/aasr/showcase/impl_type_floatingpointprecision.h"
namespace genivi {
namespace aasr {
namespace showcase {

struct FlexibleFloatingPointContainer {
  ::genivi::aasr::showcase::FloatingPointPrecision precision;
  ::genivi::aasr::showcase::FlexibleFloatingPoint floatingPoint;

  using IsEnumerableTag = void;
  template<typename F>
  void enumerate(F& fun) {
    fun(precision);
    fun(floatingPoint);
  }
};
} // namespace showcase
} // namespace aasr
} // namespace genivi

#endif // _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_impl_type_flexiblefloatingpointcontainer_h


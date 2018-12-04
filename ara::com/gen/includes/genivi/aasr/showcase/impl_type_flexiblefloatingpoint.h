#ifndef _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_impl_type_flexiblefloatingpoint_h
#define _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_impl_type_flexiblefloatingpoint_h

#include "impl_type_double.h"
#include "impl_type_float.h"
namespace genivi {
namespace aasr {
namespace showcase {

struct FlexibleFloatingPoint {
  ::Float floatingPoint32Bit;
  ::Double floatingPoint64Bit;

  using IsEnumerableTag = void;
  template<typename F>
  void enumerate(F& fun) {
    fun(floatingPoint32Bit);
    fun(floatingPoint64Bit);
  }
};
} // namespace showcase
} // namespace aasr
} // namespace genivi

#endif // _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_impl_type_flexiblefloatingpoint_h


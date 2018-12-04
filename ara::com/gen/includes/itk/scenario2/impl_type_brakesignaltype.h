#ifndef _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_itk_scenario2_impl_type_brakesignaltype_h
#define _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_itk_scenario2_impl_type_brakesignaltype_h

#include "impl_type_uint8.h"
namespace itk {
namespace scenario2 {

struct BrakeSignalType {
  ::UInt8 size;
  ::UInt8 payload;

  using IsEnumerableTag = void;
  template<typename F>
  void enumerate(F& fun) {
    fun(size);
    fun(payload);
  }
};
} // namespace scenario2
} // namespace itk

#endif // _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_itk_scenario2_impl_type_brakesignaltype_h


#ifndef _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_impl_type_lane_h
#define _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_impl_type_lane_h

#include "impl_type_string.h"
#include "impl_type_uint32.h"
#include "impl_type_uint8.h"
namespace genivi {
namespace aasr {
namespace showcase {

struct Lane {
  ::UInt8 frameId;
  ::String frameHash;
  ::UInt32 lowerLeftPointX;
  ::UInt32 lowerLeftPointY;
  ::UInt32 lowerRightPointX;
  ::UInt32 lowerRightPointY;
  ::UInt32 intersectionPointX;
  ::UInt32 intersectionPointY;

  using IsEnumerableTag = void;
  template<typename F>
  void enumerate(F& fun) {
    fun(frameId);
    fun(frameHash);
    fun(lowerLeftPointX);
    fun(lowerLeftPointY);
    fun(lowerRightPointX);
    fun(lowerRightPointY);
    fun(intersectionPointX);
    fun(intersectionPointY);
  }
};
} // namespace showcase
} // namespace aasr
} // namespace genivi

#endif // _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_impl_type_lane_h


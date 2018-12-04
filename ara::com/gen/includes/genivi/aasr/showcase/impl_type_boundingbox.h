#ifndef _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_impl_type_boundingbox_h
#define _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_impl_type_boundingbox_h

#include "impl_type_uint32.h"
namespace genivi {
namespace aasr {
namespace showcase {

struct BoundingBox {
  ::UInt32 topLeftX;
  ::UInt32 topLeftY;
  ::UInt32 width;
  ::UInt32 height;

  using IsEnumerableTag = void;
  template<typename F>
  void enumerate(F& fun) {
    fun(topLeftX);
    fun(topLeftY);
    fun(width);
    fun(height);
  }
};
} // namespace showcase
} // namespace aasr
} // namespace genivi

#endif // _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_impl_type_boundingbox_h


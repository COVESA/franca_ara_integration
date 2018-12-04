#ifndef _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_impl_type_listofvehicles_h
#define _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_impl_type_listofvehicles_h

#include "impl_type_string.h"
#include "impl_type_uint8.h"
#include "genivi/aasr/showcase/impl_type_boundingboxes.h"
#include "genivi/aasr/showcase/impl_type_vehiclevector.h"
namespace genivi {
namespace aasr {
namespace showcase {

struct ListOfVehicles {
  ::UInt8 frameId;
  ::String frameHash;
  ::genivi::aasr::showcase::VehicleVector detectedVehicles;
  ::genivi::aasr::showcase::BoundingBoxes boxes;

  using IsEnumerableTag = void;
  template<typename F>
  void enumerate(F& fun) {
    fun(frameId);
    fun(frameHash);
    fun(detectedVehicles);
    fun(boxes);
  }
};
} // namespace showcase
} // namespace aasr
} // namespace genivi

#endif // _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_impl_type_listofvehicles_h


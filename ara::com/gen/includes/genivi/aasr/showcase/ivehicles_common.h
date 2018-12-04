#ifndef _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_ivehicles_common_h
#define _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_ivehicles_common_h

#include <string.h>

#include "ara/com/types.h"

#include "ara/com/exception.h"
#include "genivi/aasr/showcase/impl_type_floatingpointprecision.h"
#include "genivi/aasr/showcase/impl_type_listofvehicles.h"
#include "impl_type_boolean.h"
namespace genivi {
namespace aasr {
namespace showcase {

class IVehicles {
 public:
  static constexpr ara::com::internal::ServiceId service_id = 0xb19c;
  static constexpr ara::com::internal::ServiceVersion service_version = 0x01000000;
  struct SetFloatingPointPrecisionOutput {
    ::Boolean rv;

    using IsEnumerableTag = void;
    template<typename F>
    void enumerate(F& fun) {
      fun(rv);
    }
  };
};

} // namespace showcase
} // namespace aasr
} // namespace genivi

#endif // _100_ApplicationDevelopment_APDTestApplication_buildARA____gen_includes_genivi_aasr_showcase_ivehicles_common_h


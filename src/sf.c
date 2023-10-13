#include <assert.h>
#include "num.h"
#include "sf.h"
#include "new.h"
#include "log.h"
#include <gsl/gsl_errno.h>
#include <gsl/gsl_sf.h>

#define EPSILON new(num, 1.0e-7, 0.0)

num_t
num_rgamma (const num_t z)
{
    assert(num_is_real(z));
    const double x = num_to_double(z);
        
    gsl_sf_result result;

    int status = gsl_sf_gammainv_e(x, &result);

    log_debug("status  = %s\n", gsl_strerror(status));
    log_debug ("1/Gamma(%g) = %.18f +/- % .18f\n",
               x, result.val, result.err);
    return new(num, result.val, 0.0);
}

#include <assert.h>
#include "num.h"
#include "sf.h"
#include "new.h"
#include "log.h"
#include <gsl/gsl_errno.h>
#include <gsl/gsl_sf.h>
#include <arb.h>
#include <arb_hypgeom.h>

num_t
num_erfc (const num_t z)
{
    assert(num_is_real(z));
    const double x = num_to_double(z);
        
    gsl_sf_result result;

    int status =  gsl_sf_erfc_e(x, &result);

    log_debug("status  = %s\n", gsl_strerror(status));
    log_debug ("erfc(%g) = %.6e +/- % .6e\n",
               x, result.val, result.err);
    return new(num, result.val, 0.0);
}

num_t
num_rgamma (const num_t z)
{
    assert(num_is_real(z));

    const int prec = 53;
    arb_t res, x;    
    arb_init(res); arb_init(x);
    arb_set_d(x, num_to_double(z));
    arb_hypgeom_rgamma(res, x,  prec);
    const double ret = arf_get_d(arb_midref(res), ARF_RND_NEAR) ;
    arb_clear(res); arb_clear(x);

    log_debug("1/Gamma(%g) = %.6e\n", num_to_double(z), ret);

    
    return new(num, ret, 0.0);
}

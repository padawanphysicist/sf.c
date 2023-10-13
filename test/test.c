#include "unity.h"
#include "num.h"
#include "new.h"
#include "sf.h"

void
setUp (void)
{
    // set stuff up here
}

void
tearDown (void)
{
    // clean stuff up here
}

void
test_erfc (void)
{
    const num_t x = new(num, 1.2, 0.0);
    
    const double ret = num_to_double(num_erfc(x));
    delete(x);
        
    TEST_ASSERT_EQUAL_DOUBLE( 0.0896860217703646, ret );    
}

void
test_rgamma (void)
{
    const num_t x = new(num, 0.5, 0.0);
    
    const double ret = num_to_double(num_rgamma(x));
    delete(x);
        
    TEST_ASSERT_EQUAL_DOUBLE( 0.564189583547756, ret );    
}



int
main (void)
{
    UNITY_BEGIN();
            
    RUN_TEST(test_erfc);
    RUN_TEST(test_rgamma);
    
    return UNITY_END();
}

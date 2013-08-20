#ifndef __STAN__AGRAD__REV__AS_BOOL_HPP__
#define __STAN__AGRAD__REV__AS_BOOL_HPP__

#include <stan/agrad/rev/var.hpp>

namespace stan {
  namespace agrad {

    /**
     * Return 1 if the argument is unequal to zero and 0 otherwise.
     *
     * @param x Value.
     * @return 0 if argument is equal to zero and 1 otherwise.
     */
    inline int as_bool(const agrad::var& v) {
      return 0.0 != v.vi_->val_;
    }

  }
}
#endif

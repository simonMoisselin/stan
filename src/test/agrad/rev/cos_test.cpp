#include <stan/agrad/rev/cos.hpp>
#include <test/agrad/util.hpp>
#include <gtest/gtest.h>

TEST(AgradRev,cos_var) {
  AVAR a = 0.49;
  AVAR f = cos(a);
  EXPECT_FLOAT_EQ(.8823329, f.val());

  AVEC x = createAVEC(a);
  VEC g;
  f.grad(x,g);
  EXPECT_FLOAT_EQ(-sin(0.49),g[0]);
}

TEST(AgradRev,cos_neg_var) {
  AVAR a = -0.49;
  AVAR f = cos(a);
  EXPECT_FLOAT_EQ((.8823329), f.val());

  AVEC x = createAVEC(a);
  VEC g;
  f.grad(x,g);
  EXPECT_FLOAT_EQ(-sin(-0.49), g[0]);
}

TEST(AgradRev,cos_boundry) {
  double inf = std::numeric_limits<double>::infinity();
  AVAR a = inf;
  EXPECT_THROW(cos(a),std::domain_error)
    <<"cos(a) should throw error";

  AVAR b = -inf;
  EXPECT_THROW(cos(b),std::domain_error)
    <<"cos(b) should throw error";
}

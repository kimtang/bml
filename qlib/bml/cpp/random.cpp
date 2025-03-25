
# define BOOST_MATH_ASSERT_UNDEFINED_POLICY false

# include <cstdint>
# include <kdb/kdb.hpp>
# include <bml/random/random.hpp>

#pragma warning( push )
#pragma warning( disable : 4311)

namespace qtype = kx::qtype;

// namespace bml {namespace random { generator_map_ generator_map; distribution_map_ distribution_map; }}

# define Random_generator1_				\
(minstd_rand0)							\
(minstd_rand)							\
(rand48)								\
(ecuyer1988)							\
(knuth_b)								\
(kreutzer1986)							\
(taus88)								\
(hellekalek1995)						\
(mt11213b)								\
(mt19937)								\
(mt19937_64)							\
(lagged_fibonacci607)					\
(lagged_fibonacci1279)					\
(lagged_fibonacci2281)					\
(lagged_fibonacci3217)					\
(lagged_fibonacci4423)					\
(lagged_fibonacci9689)					\
(lagged_fibonacci19937)					\


# define Random_generator2_				\
(lagged_fibonacci23209)					\
(lagged_fibonacci44497)					\
(ranlux3)								\
(ranlux4)								\
(ranlux64_3)							\
(ranlux64_4)							\
(ranlux3_01)							\
(ranlux4_01)							\
(ranlux64_3_01)							\
(ranlux64_4_01)							\
(ranlux24)								\
(ranlux48)								\


# define Random_generator(r,data,elem)															\
kx::K elem(kx::K seed_)																			\
{																								\
	kx::result_of::value<qtype::long_>::type seed = kx::value<qtype::long_>(seed_);				\
	boost::random::elem* gst = new boost::random::elem(seed);									\
	std::uintptr_t ptr = reinterpret_cast<long>(gst);											\
	bml::random::generator_map[ptr] = gst;														\
	return kx::kj(ptr);																			\
}																								\

BOOST_PP_SEQ_FOR_EACH(Random_generator, _, Random_generator1_)
BOOST_PP_SEQ_FOR_EACH(Random_generator, _, Random_generator2_)

# define DIST_table_dim 3

# define DIST_table																			\
((rbernoulli_distribution,bernoulli_distribution<>,(float_)))									\
((rbeta_distribution,beta_distribution<>,(float_),(float_)))									\
((rbinomial_distribution,binomial_distribution<>,(long_)(float_)))								\
((rcauchy_distribution,cauchy_distribution<>,(float_)(float_)))									\
((rchi_squared_distribution,chi_squared_distribution<>,(float_)))								\
((rexponential_distribution,exponential_distribution<>,(float_)))								\
((rextreme_value_distribution,extreme_value_distribution<>,(float_)(float_)))					\
((rfisher_f_distribution,fisher_f_distribution<>,(float_)(float_)))								\
((rgamma_distribution,gamma_distribution<>,(float_)(float_)))									\
((rgeometric_distribution,geometric_distribution<>,(float_)))									\
((rlaplace_distribution,laplace_distribution<>,(float_),(float_)))								\
((rlognormal_distribution,lognormal_distribution<>,(float_)(float_)))							\
((rnegative_binomial_distribution,negative_binomial_distribution<>,(long_)(float_)))			\
((rnon_central_chi_squared_distribution,non_central_chi_squared_distribution<>,(float_)(float_)))\
((rnormal_distribution,normal_distribution<>,(float_)(float_)))									\
((rpoisson_distribution,poisson_distribution<>,(float_)))										\
((rstudent_t_distribution,student_t_distribution<>,(float_)))									\
((rtriangle_distribution,triangle_distribution<>,(float_)(float_)))								\
((runiform_int_distribution,uniform_int_distribution<>,(long_)(long_)))							\
((runiform_real_distribution,uniform_real_distribution<>,(float_)(float_)))						\
((runiform_smallint,uniform_smallint<>,(long_)(long_)))											\
((rweibull_distribution,weibull_distribution<>,(float_)(float_)))								\


// (discrete_distribution<>)								\
// (hyperexponential_distribution<>)						\
// (piecewise_constant_distribution<>)						\
// (piecewise_linear_distribution<>)						\


# define DIST_create_argument(z,n,data) kx::K BOOST_PP_CAT(k,n)
# define DIST_create_convert(r,data,n,elem) kx::result_of::value<qtype::elem>::type BOOST_PP_CAT(l,n) = kx::value<qtype::elem>(BOOST_PP_CAT(k,n));

# define DIST_generator(r,data,tuple)																																									\
	kx::K BOOST_PP_TUPLE_ELEM(DIST_table_dim,0,tuple)(BOOST_PP_ENUM(BOOST_PP_SEQ_SIZE(BOOST_PP_TUPLE_ELEM(DIST_table_dim,2,tuple)),DIST_create_argument, _ ))												\
{																																																		\
	BOOST_PP_SEQ_FOR_EACH_I(DIST_create_convert, _ , BOOST_PP_TUPLE_ELEM(DIST_table_dim,2,tuple))																										\
	boost::random::BOOST_PP_TUPLE_ELEM(DIST_table_dim,1,tuple) * dst;																																			\
	dst = new boost::random::BOOST_PP_TUPLE_ELEM(DIST_table_dim,1,tuple) ( BOOST_PP_ENUM_PARAMS(BOOST_PP_SEQ_SIZE(BOOST_PP_TUPLE_ELEM(DIST_table_dim,2,tuple)),l) );											\
	std::uintptr_t ptr = reinterpret_cast<long>(dst);																																					\
	bml::random::distribution_map[ptr] = dst;																																							\
	return kx::kj(ptr);																																													\
};																																																		\


BOOST_PP_SEQ_FOR_EACH(DIST_generator, ~, DIST_table)

kx::K uniform_01()
{
	boost::random::uniform_01<>* dst = new boost::random::uniform_01<>();
	std::uintptr_t ptr = reinterpret_cast<long>(dst);
	bml::random::distribution_map[ptr] = dst;
	return kx::kj(ptr);
}

kx::K delete_(kx::K ptr_)
{
	kx::result_of::value<qtype::long_>::type ptr = kx::value<qtype::long_>(ptr_);
	bml::random::generator_map_::iterator git = bml::random::generator_map.find(ptr);
	if (git != bml::random::generator_map.end()) {
		bml::random::rdelete_(git->second);
		bml::random::generator_map.erase(git);
		return kx::kb(1);
	}

	bml::random::distribution_map_::iterator dit = bml::random::distribution_map.find(ptr);
	if (dit != bml::random::distribution_map.end()) {
		bml::random::rdelete_(dit->second);
		bml::random::distribution_map.erase(dit);
		return kx::kb(1);
	}

	return kx::kb(0);
}


kx::K generate(kx::K g__, kx::K d__, kx::K num_)
{
	kx::result_of::value<qtype::long_>::type g_ = kx::value<qtype::long_>(g__);
	bml::random::generator_map_::iterator g = bml::random::generator_map.find(g_);
	if (bml::random::generator_map.end() == g) { return kx::kb(0); }

	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	bml::random::distribution_map_::iterator d = bml::random::distribution_map.find(d_);
	if (bml::random::distribution_map.end() == d) { return kx::kb(0); }

	kx::result_of::value<qtype::long_>::type num = kx::value<qtype::long_>(num_);
	return bml::random::generate_(g->second, d->second, num);
}

# undef Random_generator1_
# undef Random_generator2_

#undef FDIST_table1

#pragma warning( pop )
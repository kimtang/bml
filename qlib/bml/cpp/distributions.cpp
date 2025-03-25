
# define BOOST_MATH_ASSERT_UNDEFINED_POLICY false

# include <cstdint>
# include <boost/math/distributions.hpp>
# include <bml/math/math.hpp>
# include <kdb/kdb.hpp>

#pragma warning( push )
#pragma warning( disable : 4311)

// namespace bml { namespace math { distribution_map_ distribution_map; } }

namespace qtype = kx::qtype;

# define FDIST_table_dim 3

# define FDIST_table1																				\
((darcsine_distribution,arcsine_distribution<>,(float_)(float_)))									\
((dbernoulli_distribution,bernoulli_distribution<>,(float_)))										\
((dbeta_distribution,beta_distribution<>,(float_)(float_)))											\
((dbinomial_distribution,binomial_distribution<>,(float_)(float_)))									\
((dcauchy_distribution,cauchy_distribution<>,(float_)(float_)))										\
((dchi_squared_distribution,chi_squared_distribution<>,(float_)))									\
((dexponential_distribution,exponential_distribution<>,(float_)))									\
((dextreme_value_distribution,extreme_value_distribution<>,(float_)(float_)))						\
((dfisher_f_distribution,fisher_f_distribution<>,(float_)(float_)))									\
((dgamma_distribution,gamma_distribution<>,(float_)(float_)))										\
((dgeometric_distribution,geometric_distribution<>,(float_)))										\
((dholtsmark_distribution,holtsmark_distribution<>,(float_)(float_)))								\
((dhypergeometric_distribution,hypergeometric_distribution<>,(long_)(long_)(long_)))				\
((dinverse_chi_squared_distribution,inverse_chi_squared_distribution<>,(float_)(float_)))			\
((dinverse_gamma_distribution,inverse_gamma_distribution<>,(float_)(float_)))			\
((dinverse_gaussian_distribution,inverse_gaussian_distribution<>,(float_)(float_)))			\
((dkolmogorov_smirnov_distribution,kolmogorov_smirnov_distribution<>,(float_)))			\
((dlandau_distribution,landau_distribution<>,(float_)(float_)))			\
((dlaplace_distribution,laplace_distribution<>,(float_)(float_)))									\
((dlogistic_distribution,logistic_distribution<>,(float_)(float_)))									\
((dmapairy_distribution,mapairy_distribution<>,(float_)(float_)))								\
((dlognormal_distribution,lognormal_distribution<>,(float_)(float_)))								\
((dnegative_binomial_distribution,negative_binomial_distribution<>,(float_)(float_)))				\
((dnon_central_beta_distribution,non_central_beta_distribution<>,(float_)(float_)(float_)))			\
((dnon_central_t_distribution,non_central_t_distribution<>,(float_)(float_)))						\
((dnon_central_chi_squared_distribution,non_central_chi_squared_distribution<>,(float_)(float_)))						\
((dnon_central_f_distribution,non_central_f_distribution<>,(float_)(float_)(float_)))						\
((dnormal_distribution,normal_distribution<>,(float_)(float_)))										\
((dpareto_distribution,pareto_distribution<>,(float_)(float_)))										\
((dpoisson_distribution,poisson_distribution<>,(float_)))											\
((drayleigh_distribution,rayleigh_distribution<>,(float_)))											\
((dsaspoint5_distribution,saspoint5_distribution<>,(float_)(float_)))											\
((dskew_normal_distribution,skew_normal_distribution<>,(float_)(float_)(float_)))                   \
((dstudents_t_distribution,students_t_distribution<>,(float_)))										\
((dtriangular_distribution,triangular_distribution<>,(float_)(float_)(float_)))										\
((duniform_distribution,uniform_distribution<>,(float_)(float_)))										\
((dweibull_distribution,weibull_distribution<>,(float_)(float_)))									\


# define FDIST_create_argument(z,n,data) kx::K BOOST_PP_CAT(k,n)
# define FDIST_create_convert(r,data,n,elem) kx::result_of::value<qtype::elem>::type BOOST_PP_CAT(l,n) = kx::value<qtype::elem>(BOOST_PP_CAT(k,n));

# define FDIST_generator(r,data,tuple)																																									\
	kx::K BOOST_PP_TUPLE_ELEM(FDIST_table_dim,0,tuple)(BOOST_PP_ENUM(BOOST_PP_SEQ_SIZE(BOOST_PP_TUPLE_ELEM(FDIST_table_dim,2,tuple)),FDIST_create_argument, _ ))												\
{																																																		\
	BOOST_PP_SEQ_FOR_EACH_I(FDIST_create_convert, _ , BOOST_PP_TUPLE_ELEM(FDIST_table_dim,2,tuple))																										\
	boost::math::BOOST_PP_TUPLE_ELEM(FDIST_table_dim,1,tuple) * dst;																																			\
	dst = new boost::math::BOOST_PP_TUPLE_ELEM(FDIST_table_dim,1,tuple) ( BOOST_PP_ENUM_PARAMS(BOOST_PP_SEQ_SIZE(BOOST_PP_TUPLE_ELEM(FDIST_table_dim,2,tuple)),l) );											\
	std::uintptr_t ptr = reinterpret_cast<long>(dst);																																					\
	bml::math::distribution_map[ptr] = dst;																																							\
	return kx::kj(ptr);																																													\
};																																																		\


BOOST_PP_SEQ_FOR_EACH(FDIST_generator, ~, FDIST_table1)

//kx::K dnormal_distribution(kx::K k0,kx::K k1)
//{
//	kx::result_of::value<qtype::float_>::type l0 = kx::value<qtype::float_>(k0);
//	kx::result_of::value<qtype::float_>::type l1 = kx::value<qtype::float_>(k1);
//	boost::math::normal_distribution<>* dst = new boost::math::normal_distribution<>(l0,l1);
//	std::uintptr_t ptr = reinterpret_cast<long>(dst);
//	bml::math::distribution_map[ptr] = dst;
//	return kx::kj(ptr);
//}

kx::K cdf(kx::K d__, kx::K x_)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	kx::vector<qtype::float_> x(x_);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::cdf_visitor<kx::vector<qtype::float_> > cv(x);
	return boost::apply_visitor(cv, d->second);
}

kx::K cdf_comp(kx::K d__, kx::K x_)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	kx::vector<qtype::float_> x(x_);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::cdf_comp_visitor<kx::vector<qtype::float_> > cv(x);
	return boost::apply_visitor(cv, d->second);
}

kx::K pdf(kx::K d__, kx::K x_)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	kx::vector<qtype::float_> x(x_);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::pdf_visitor<kx::vector<qtype::float_> > cv(x);
	return boost::apply_visitor(cv, d->second);
}

kx::K quantile(kx::K d__, kx::K x_)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	kx::vector<qtype::float_> x(x_);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::quantile_visitor<kx::vector<qtype::float_> > cv(x);
	return boost::apply_visitor(cv, d->second);
}

kx::K quantile_comp(kx::K d__, kx::K x_)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	kx::vector<qtype::float_> x(x_);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::quantile_comp_visitor<kx::vector<qtype::float_> > cv(x);
	return boost::apply_visitor(cv, d->second);
}

kx::K hazard(kx::K d__, kx::K x_)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	kx::vector<qtype::float_> x(x_);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::hazard_visitor<kx::vector<qtype::float_> > cv(x);
	return boost::apply_visitor(cv, d->second);
}

kx::K chf(kx::K d__, kx::K x_)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	kx::vector<qtype::float_> x(x_);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::chf_visitor<kx::vector<qtype::float_> > cv(x);
	return boost::apply_visitor(cv, d->second);
}

kx::K mean_(kx::K d__)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::mean_visitor cv;
	return boost::apply_visitor(cv, d->second);
}

kx::K median_(kx::K d__)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::median_visitor cv;
	return boost::apply_visitor(cv, d->second);
}

kx::K mode_(kx::K d__)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::mode_visitor cv;
	return boost::apply_visitor(cv, d->second);
}

kx::K standard_deviation_(kx::K d__)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::standard_deviation_visitor cv;
	return boost::apply_visitor(cv, d->second);
}

kx::K variance_(kx::K d__)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::variance_visitor cv;
	return boost::apply_visitor(cv, d->second);
}

kx::K skewness_(kx::K d__)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::skewness_visitor cv;
	return boost::apply_visitor(cv, d->second);
}

kx::K kurtosis_(kx::K d__)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::kurtosis_visitor cv;
	return boost::apply_visitor(cv, d->second);
}

# undef Random_generator1_
# undef Random_generator2_

#undef FDIST_table1

#pragma warning( pop )
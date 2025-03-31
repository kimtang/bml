
# define BOOST_MATH_ASSERT_UNDEFINED_POLICY false

#pragma warning( push )
#pragma warning( disable : 4311)

# include <cstdint>
# include <boost/math/distributions.hpp>
# include <bml/math/distributions.hpp>
# include <kdb/kdb.hpp>

namespace qtype = kx::qtype;

# define FDIST_table_dim 3

# define FDIST_table1																				\
((bml_dist_arcsine,arcsine_distribution<>,(float_)(float_)))									\
((bml_dist_bernoulli,bernoulli_distribution<>,(float_)))										\
((bml_dist_beta,beta_distribution<>,(float_)(float_)))											\
((bml_dist_binomial,binomial_distribution<>,(float_)(float_)))									\
((bml_dist_cauchy,cauchy_distribution<>,(float_)(float_)))										\
((bml_dist_chi_squared,chi_squared_distribution<>,(float_)))									\
((bml_dist_exponential,exponential_distribution<>,(float_)))									\
((bml_dist_extreme_value,extreme_value_distribution<>,(float_)(float_)))						\
((bml_dist_fisher_f,fisher_f_distribution<>,(float_)(float_)))									\
((bml_dist_gamma,gamma_distribution<>,(float_)(float_)))										\
((bml_dist_geometric,geometric_distribution<>,(float_)))										\
((bml_dist_holtsmark,holtsmark_distribution<>,(float_)(float_)))								\
((bml_dist_hypergeometric,hypergeometric_distribution<>,(long_)(long_)(long_)))				\
((bml_dist_inverse_chi_squared,inverse_chi_squared_distribution<>,(float_)(float_)))			\
((bml_dist_inverse_gamma,inverse_gamma_distribution<>,(float_)(float_)))			\
((bml_dist_inverse_gaussian,inverse_gaussian_distribution<>,(float_)(float_)))			\
((bml_dist_kolmogorov_smirnov,kolmogorov_smirnov_distribution<>,(float_)))			\
((bml_dist_landau,landau_distribution<>,(float_)(float_)))			\
((bml_dist_laplace,laplace_distribution<>,(float_)(float_)))									\
((bml_dist_logistic,logistic_distribution<>,(float_)(float_)))									\
((bml_dist_mapairy,mapairy_distribution<>,(float_)(float_)))								\
((bml_dist_lognormal,lognormal_distribution<>,(float_)(float_)))								\
((bml_dist_negative_binomial,negative_binomial_distribution<>,(float_)(float_)))				\
((bml_dist_non_central_beta,non_central_beta_distribution<>,(float_)(float_)(float_)))			\
((bml_dist_non_central_t,non_central_t_distribution<>,(float_)(float_)))						\
((bml_dist_non_central_chi_squared,non_central_chi_squared_distribution<>,(float_)(float_)))						\
((bml_dist_non_central_f,non_central_f_distribution<>,(float_)(float_)(float_)))						\
((bml_dist_normal,normal_distribution<>,(float_)(float_)))										\
((bml_dist_pareto,pareto_distribution<>,(float_)(float_)))										\
((bml_dist_poisson,poisson_distribution<>,(float_)))											\
((bml_dist_rayleigh,rayleigh_distribution<>,(float_)))											\
((bml_dist_saspoint5,saspoint5_distribution<>,(float_)(float_)))											\
((bml_dist_skew_normal,skew_normal_distribution<>,(float_)(float_)(float_)))                   \
((bml_dist_students_t,students_t_distribution<>,(float_)))										\
((bml_dist_triangular,triangular_distribution<>,(float_)(float_)(float_)))										\
((bml_dist_uniform,uniform_distribution<>,(float_)(float_)))										\
((bml_dist_weibull,weibull_distribution<>,(float_)(float_)))									\


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

kx::K bml_dist_cdf0(kx::K d__, kx::K x_)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	kx::raw_vector<qtype::float_> x(x_);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::cdf_visitor<kx::raw_vector<qtype::float_> > cv(x);
	return boost::apply_visitor(cv, d->second);
}

kx::K bml_dist_cdf_comp0(kx::K d__, kx::K x_)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	kx::raw_vector<qtype::float_> x(x_);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::cdf_comp_visitor<kx::raw_vector<qtype::float_> > cv(x);
	return boost::apply_visitor(cv, d->second);
}

kx::K bml_dist_pdf0(kx::K d__, kx::K x_)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	kx::raw_vector<qtype::float_> x(x_);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::pdf_visitor<kx::raw_vector<qtype::float_> > cv(x);
	return boost::apply_visitor(cv, d->second);
}

kx::K bml_dist_quantile0(kx::K d__, kx::K x_)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	kx::raw_vector<qtype::float_> x(x_);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::quantile_visitor<kx::raw_vector<qtype::float_> > cv(x);
	return boost::apply_visitor(cv, d->second);
}

kx::K bml_dist_quantile_comp0(kx::K d__, kx::K x_)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	kx::raw_vector<qtype::float_> x(x_);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::quantile_comp_visitor<kx::raw_vector<qtype::float_> > cv(x);
	return boost::apply_visitor(cv, d->second);
}

kx::K bml_dist_hazard0(kx::K d__, kx::K x_)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	kx::raw_vector<qtype::float_> x(x_);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::hazard_visitor<kx::raw_vector<qtype::float_> > cv(x);
	return boost::apply_visitor(cv, d->second);
}

kx::K bml_dist_chf0(kx::K d__, kx::K x_)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	kx::raw_vector<qtype::float_> x(x_);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::chf_visitor<kx::raw_vector<qtype::float_> > cv(x);
	return boost::apply_visitor(cv, d->second);
}

kx::K bml_dist_mean0(kx::K d__)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::mean_visitor cv;
	return boost::apply_visitor(cv, d->second);
}

kx::K bml_dist_median0(kx::K d__)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::median_visitor cv;
	return boost::apply_visitor(cv, d->second);
}

kx::K bml_dist_mode0(kx::K d__)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::mode_visitor cv;
	return boost::apply_visitor(cv, d->second);
}

kx::K bml_dist_standard_deviation0(kx::K d__)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::standard_deviation_visitor cv;
	return boost::apply_visitor(cv, d->second);
}

kx::K bml_dist_variance0(kx::K d__)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::variance_visitor cv;
	return boost::apply_visitor(cv, d->second);
}

kx::K bml_dist_skewness0(kx::K d__)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::skewness_visitor cv;
	return boost::apply_visitor(cv, d->second);
}

kx::K bml_dist_kurtosis0(kx::K d__)
{
	kx::result_of::value<qtype::long_>::type d_ = kx::value<qtype::long_>(d__);
	bml::math::distribution_map_::iterator d = bml::math::distribution_map.find(d_);
	if (bml::math::distribution_map.end() == d) { return kx::kb(0); }

	bml::math::kurtosis_visitor cv;
	return boost::apply_visitor(cv, d->second);
}

#pragma warning( pop )

# undef Random_generator1_
# undef Random_generator2_
# undef FDIST_table1

# ifndef BML_RANDOM_RANDOM_HPP_KKT_15_05_2014
# define BML_RANDOM_RANDOM_HPP_KKT_15_05_2014

#pragma push_macro("BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS")
#pragma push_macro("BOOST_MPL_LIMIT_LIST_SIZE")
#pragma push_macro("BOOST_MPL_LIMIT_VECTOR_SIZE")

# undef BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS 
# undef BOOST_MPL_LIMIT_LIST_SIZE 
# undef BOOST_MPL_LIMIT_VECTOR_SIZE


# define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS 
# define BOOST_MPL_LIMIT_LIST_SIZE 30 
# define BOOST_MPL_LIMIT_VECTOR_SIZE 30

# include <boost/random.hpp>
# include <boost/variant.hpp>
# include <boost/preprocessor.hpp>
# include <boost/ref.hpp>
# include <kdb/kdb.hpp>

# include <cstdint>
# include <map>

namespace bml {namespace random{

# define Random_generator_																		\
													 (kreutzer1986)								\
													 (taus88)									\
													 (hellekalek1995)							\
													 (mt11213b)									\
													 (mt19937)									\
													 (mt19937_64)								\
													 (lagged_fibonacci607)						\
													 (lagged_fibonacci1279)						\
													 (lagged_fibonacci2281)						\
													 (lagged_fibonacci3217)						\
													 (lagged_fibonacci4423)						\
													 (lagged_fibonacci9689)						\
													 (lagged_fibonacci19937)					\
													 (lagged_fibonacci23209)					\
													 (lagged_fibonacci44497)					\
													 (ranlux3)									\
													 (ranlux4)									\
													 (ranlux64_3)								\
													 (ranlux64_4)								\
													 (ranlux3_01)								\
													 (ranlux4_01)								\
													 (ranlux64_3_01)							\
													 (ranlux64_4_01)							\
													 (ranlux24)									\
													 (ranlux48)									\

# define BOOST_add_namespace(r,data,elem) BOOST_PP_CAT(BOOST_PP_CAT(data,elem),*)
# define Random_generator BOOST_PP_SEQ_TRANSFORM(BOOST_add_namespace, boost::random:: , Random_generator_ )

# define DIST_generator_							(uniform_smallint<kx::J>)								\
						 							(uniform_int_distribution<kx::J>)						\
						 							(uniform_01<>)											\
						 							(uniform_real_distribution<>)							\
						 							(bernoulli_distribution<>)								\
						 						 	(binomial_distribution<kx::J>)							\
						 						 	(geometric_distribution<kx::J>)							\
						 						 	(negative_binomial_distribution<kx::J>)					\
						 						 	(poisson_distribution<kx::J>)							\
						 						 	(exponential_distribution<>)							\
						 						 	(gamma_distribution<>)									\
						 						 	(weibull_distribution<>)								\
						 						 	(extreme_value_distribution<>)							\
						 						 	(normal_distribution<kx::F>)							\
						 						 	(lognormal_distribution<>)								\
						 						 	(chi_squared_distribution<>)							\
													(cauchy_distribution<>)									\
													(fisher_f_distribution<>)								\
													(student_t_distribution<>)								\

													// (discrete_distribution<kx::J>)							\
													// (piecewise_constant_distribution<>)					\
													// (piecewise_linear_distribution<>)					\
													// (triangle_distribution<>)							\

													//(uniform_on_sphere<>)								\

# define DIST_generator BOOST_PP_SEQ_TRANSFORM(BOOST_add_namespace, boost::random:: , DIST_generator_ )

typedef boost::variant<BOOST_PP_SEQ_ENUM(Random_generator)> generator;
typedef boost::variant<BOOST_PP_SEQ_ENUM(DIST_generator)> distribution;

namespace tool{
	template<typename T> struct convert;

	template<>struct convert<kx::J>{
		typedef kx::qtype::long_ type;
	};
	template<>struct convert<kx::F>{
		typedef kx::qtype::float_ type;
	};
	template<>struct convert<bool>{
		typedef kx::qtype::boolean_ type;
	};

	// BOOST_PP_SEQ_FOR_EACH(kdb_convert,~,kdb_table)

}

template<typename D>
class generator_visitor : public boost::static_visitor<kx::K>
{
public:

	generator_visitor(D& d, long num) : d_(d),num_(num){};
	template<typename G>
	kx::K operator()(G* g){
		kx::vector<typename bml::random::tool::convert<typename D::result_type>::type > result(static_cast<std::size_t>(num_));
		std::generate(result.begin(),result.end(),boost::bind(d_,boost::ref(*g)));
		return result;
	}

	D& d_;
	long num_;
};

class distribution_visitor : public boost::static_visitor<kx::K>
{
public:
	distribution_visitor(generator& g, long num) :g_(g),num_(num) {};

	template<typename D>
	kx::K operator()(D* d)
	{
		generator_visitor<D> gv(*d,num_);
		return boost::apply_visitor(gv,g_);
	}

	long num_;
	generator& g_;
};

kx::K generate_(generator&g ,distribution& d,long num)
{
	distribution_visitor dv(g,num);
	return boost::apply_visitor(dv,d);
};

class delete_visitor : public boost::static_visitor<>
{
public:
	template<typename DG>
	void operator()(DG * dg_)
	{
		DG* dg = reinterpret_cast<DG*>(dg_);
		delete dg;
	}
};

template<typename T>
void rdelete_(T& t)
{
	delete_visitor dv;
	boost::apply_visitor(dv,t);
};

typedef std::map<std::uintptr_t,generator > generator_map_;
typedef std::map<std::uintptr_t,distribution > distribution_map_;

generator_map_ generator_map; 
distribution_map_ distribution_map;

}}


# undef Random_generator_
# undef DIST_generator_

# undef Random_generator
# undef DIST_generator

# endif

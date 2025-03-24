
# ifndef BML_MATH_MATH_HPP_KKT_17_05_2014
# define BML_MATH_MATH_HPP_KKT_17_05_2014

# undef BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS 
# undef BOOST_MPL_LIMIT_LIST_SIZE 
# undef BOOST_MPL_LIMIT_VECTOR_SIZE

# include <boost/math/distributions.hpp>
# include <boost/variant.hpp>
# include <boost/preprocessor.hpp>
# include <boost/ref.hpp>
# include <kdb/kdb.hpp>

# include <cstdint>
# include <map>

namespace bml{namespace math{

# define MATH_DIST_generator1_								\
(arcsine_distribution<>)										\
(bernoulli_distribution<>)										\
(beta_distribution<>)											\
(binomial_distribution<>)										\
(cauchy_distribution<>)											\
(chi_squared_distribution<>)									\
(exponential_distribution<>)									\
(extreme_value_distribution<>)								\
(fisher_f_distribution<>)										\
(gamma_distribution<>)											\
(geometric_distribution<>)										\
(holtsmark_distribution<>)										\
(hypergeometric_distribution<>)								\
(inverse_chi_squared_distribution<>)						\
(inverse_gamma_distribution<>)								\
(inverse_gaussian_distribution<>)							\
(kolmogorov_smirnov_distribution<>)							\
(landau_distribution<>)											\
(laplace_distribution<>)										\
(logistic_distribution<>)										\
(lognormal_distribution<>)										\
(mapairy_distribution<>)									\
(negative_binomial_distribution<>)							\
(non_central_beta_distribution<>)							\

# define MATH_DIST_generator2_								\
(non_central_t_distribution<>)								\
(non_central_chi_squared_distribution<>)								\
(non_central_f_distribution<>)									\
(normal_distribution<>)											\
(pareto_distribution<>)											\
(poisson_distribution<>)										\
(rayleigh_distribution<>)										\
(saspoint5_distribution<>)										\
(skew_normal_distribution<>)									\
(students_t_distribution<>)									\
(triangular_distribution<>)									\
(uniform_distribution<>)									\
(weibull_distribution<>)										\


# define BOOST_add_namespace(r,data,elem) BOOST_PP_CAT(BOOST_PP_CAT(data,elem),*)
# define MATH_DIST_generator1 BOOST_PP_SEQ_TRANSFORM(BOOST_add_namespace, boost::math:: , MATH_DIST_generator1_ )
# define MATH_DIST_generator2 BOOST_PP_SEQ_TRANSFORM(BOOST_add_namespace, boost::math:: , MATH_DIST_generator2_ )

typedef boost::variant<BOOST_PP_SEQ_ENUM(MATH_DIST_generator1)> distribution1;
typedef boost::variant<BOOST_PP_SEQ_ENUM(MATH_DIST_generator2)> distribution2;
typedef boost::variant<distribution1,distribution2> distribution;

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

template<typename K>
class cdf_visitor : public boost::static_visitor<kx::K>
{
public:
	cdf_visitor(K & k) : k_(k){};
	template<typename G>
	kx::K operator()(G* g){
		typedef typename G::value_type value_type; 
		kx::vector<typename bml::math::tool::convert<value_type>::type > result(k_.size());
		std::transform(k_.begin(),k_.end(),result.begin(),boost::bind<value_type>(boost::math::cdf<G,value_type>,*g,_1));
		return result;
	}

	kx::K operator()(const distribution1& d) {return d.apply_visitor(*this);}
	kx::K operator()(const distribution2& d) {return d.apply_visitor(*this);}

	K & k_;
};

template <class Dist, class RealType>
RealType cdf_comp_(const Dist& d, const RealType& r)
{
   return boost::math::cdf(boost::math::complement(d, r));
}

template<typename K>
class cdf_comp_visitor : public boost::static_visitor<kx::K>
{
public:
	cdf_comp_visitor(K & k) : k_(k){};
	template<typename G>
	kx::K operator()(G* g){
		typedef typename G::value_type value_type; 
		kx::vector<typename bml::math::tool::convert<value_type>::type > result(k_.size());
		//std::transform(k_.begin(),k_.end(),result.begin(),boost::bind<value_type>(boost::math::chf<G,value_type>,*g,_1));
		std::transform(k_.begin(),k_.end(),result.begin(),boost::bind<value_type>(cdf_comp_<G,value_type>,*g,_1));
		return result;
	}

	kx::K operator()(const distribution1& d) { return d.apply_visitor(*this); }
	kx::K operator()(const distribution2& d) { return d.apply_visitor(*this); }

	K & k_;
};

template<typename K>
class pdf_visitor : public boost::static_visitor<kx::K>
{
public:
	pdf_visitor(K & k) : k_(k){};
	template<typename G>
	kx::K operator()(G* g){
		typedef typename G::value_type value_type; 
		kx::vector<typename bml::math::tool::convert<value_type>::type > result(k_.size());
		std::transform(k_.begin(),k_.end(),result.begin(),boost::bind<value_type>(boost::math::pdf<G,value_type>,*g,_1));
		return result;
	}

	kx::K operator()(const distribution1& d) { return d.apply_visitor(*this); }
	kx::K operator()(const distribution2& d) { return d.apply_visitor(*this); }

	K & k_;
};

template<typename K>
class quantile_visitor : public boost::static_visitor<kx::K>
{
public:
	quantile_visitor(K & k) : k_(k){};
	template<typename G>
	kx::K operator()(G* g){
		typedef typename G::value_type value_type; 
		kx::vector<typename bml::math::tool::convert<value_type>::type > result(k_.size());
		std::transform(k_.begin(),k_.end(),result.begin(),boost::bind<value_type>(boost::math::quantile<G,value_type>,*g,_1));
		return result;
	}

	kx::K operator()(const distribution1& d) { return d.apply_visitor(*this); }
	kx::K operator()(const distribution2& d) { return d.apply_visitor(*this); }

	K & k_;
};

template <class Dist, class RealType>
RealType quantile_comp_(const Dist& d, const RealType& r)
{
   return boost::math::quantile(boost::math::complement(d, r));
}

template<typename K>
class quantile_comp_visitor : public boost::static_visitor<kx::K>
{
public:
	quantile_comp_visitor(K & k) : k_(k){};
	template<typename G>
	kx::K operator()(G* g){
		typedef typename G::value_type value_type; 
		kx::vector<typename bml::math::tool::convert<value_type>::type > result(k_.size());
		std::transform(k_.begin(),k_.end(),result.begin(),boost::bind<value_type>(quantile_comp_<G,value_type>,*g,_1));
		return result;
	}

	kx::K operator()(const distribution1& d) { return d.apply_visitor(*this); }
	kx::K operator()(const distribution2& d) { return d.apply_visitor(*this); }

	K & k_;
};

template<typename K>
class hazard_visitor : public boost::static_visitor<kx::K>
{
public:
	hazard_visitor(K & k) : k_(k){};
	template<typename G>
	kx::K operator()(G* g){
		typedef typename G::value_type value_type; 
		kx::vector<typename bml::math::tool::convert<value_type>::type > result(k_.size());
		std::transform(k_.begin(),k_.end(),result.begin(),boost::bind<value_type>(boost::math::hazard<G,value_type>,*g,_1));
		return result;
	}

	kx::K operator()(const distribution1& d) { return d.apply_visitor(*this); }
	kx::K operator()(const distribution2& d) { return d.apply_visitor(*this); }

	K & k_;
};

template<typename K>
class chf_visitor : public boost::static_visitor<kx::K>
{
public:
	chf_visitor(K & k) : k_(k){};
	template<typename G>
	kx::K operator()(G* g){
		typedef typename G::value_type value_type; 
		kx::vector<typename bml::math::tool::convert<value_type>::type > result(k_.size());
		std::transform(k_.begin(),k_.end(),result.begin(),boost::bind<value_type>(boost::math::chf<G,value_type>,*g,_1));
		return result;
	}

	kx::K operator()(const distribution1& d) { return d.apply_visitor(*this); }
	kx::K operator()(const distribution2& d) { return d.apply_visitor(*this); }

	K & k_;
};

class mean_visitor : public boost::static_visitor<kx::K>
{
public:
	template<typename G> kx::K operator()(G* g){ return kx::kf( boost::math::mean(*g));}
	kx::K operator()(const distribution1& d) { return d.apply_visitor(*this); }
	kx::K operator()(const distribution2& d) { return d.apply_visitor(*this); }

};

class median_visitor : public boost::static_visitor<kx::K>
{
public:
	template<typename G> kx::K operator()(G* g){ return kx::kf( boost::math::median(*g));}
	kx::K operator()(const distribution1& d) { return d.apply_visitor(*this); }
	kx::K operator()(const distribution2& d) { return d.apply_visitor(*this); }

};

class mode_visitor : public boost::static_visitor<kx::K>
{
public:
	template<typename G> kx::K operator()(G* g){ return kx::kf( boost::math::mode(*g));}
	kx::K operator()(const distribution1& d) { return d.apply_visitor(*this); }
	kx::K operator()(const distribution2& d) { return d.apply_visitor(*this); }

};

class standard_deviation_visitor : public boost::static_visitor<kx::K>
{
public:
	template<typename G> kx::K operator()(G* g){ return kx::kf( boost::math::standard_deviation(*g));}
	kx::K operator()(const distribution1& d) { return d.apply_visitor(*this); }
	kx::K operator()(const distribution2& d) { return d.apply_visitor(*this); }

};

class variance_visitor : public boost::static_visitor<kx::K>
{
public:
	template<typename G> kx::K operator()(G* g){ return kx::kf( boost::math::variance(*g));}
	kx::K operator()(const distribution1& d) { return d.apply_visitor(*this); }
	kx::K operator()(const distribution2& d) { return d.apply_visitor(*this); }

};

class skewness_visitor : public boost::static_visitor<kx::K>
{
public:
	template<typename G> kx::K operator()(G* g){ return kx::kf( boost::math::skewness(*g));}
	kx::K operator()(const distribution1& d) { return d.apply_visitor(*this); }
	kx::K operator()(const distribution2& d) { return d.apply_visitor(*this); }

};

class kurtosis_visitor : public boost::static_visitor<kx::K>
{
public:
	template<typename G> kx::K operator()(G* g){ return kx::kf( boost::math::kurtosis(*g));}
	kx::K operator()(const distribution1& d) { return d.apply_visitor(*this); }
	kx::K operator()(const distribution2& d) { return d.apply_visitor(*this); }

};

// TODO: Implement support

typedef std::map<std::uintptr_t,distribution > distribution_map_;

distribution_map_ distribution_map;

}}

# undef MATH_DIST_generator1_
# undef MATH_DIST_generator1

# undef MATH_DIST_generator2_
# undef MATH_DIST_generator2

# undef BOOST_add_namespace

# endif 

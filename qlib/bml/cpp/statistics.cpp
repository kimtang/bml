
#include <boost/math/statistics/univariate_statistics.hpp>
#include <boost/math/statistics/bivariate_statistics.hpp>

# include <kdb/kdb.hpp>

namespace qtype = kx::qtype;

kx::K bml_stat_mean(kx::K x_)
{
	kx::raw_vector<qtype::float_> x(x_);
	kx::F mu = boost::math::statistics::mean(x.begin(), x.end());
	return kx::kf(mu);
}

kx::K bml_stat_variance(kx::K x_)
{
	kx::raw_vector<qtype::float_> x(x_);
	kx::F mu = boost::math::statistics::variance(x.begin(), x.end());
	return kx::kf(mu);
}

kx::K bml_stat_skewness(kx::K x_)
{
	kx::raw_vector<qtype::float_> x(x_);
	kx::F mu = boost::math::statistics::skewness(x.begin(), x.end());
	return kx::kf(mu);
}

kx::K bml_stat_kurtosis(kx::K x_)
{
	kx::raw_vector<qtype::float_> x(x_);
	kx::F mu = boost::math::statistics::kurtosis(x.begin(), x.end());
	return kx::kf(mu);
}

kx::K bml_stat_first_four_moments(kx::K x_)
{
	kx::raw_vector<qtype::float_> x(x_);
	auto [m1,m2,m3, m4] = boost::math::statistics::first_four_moments(x.begin(), x.end());
	double m[] = { m1,m2,m3, m4 };
	kx::S s[] = { kx::ss("m1"),kx::ss("m2"),kx::ss("m3"), kx::ss("m4") };
	
	kx::vector<qtype::float_> v(m, m+4);
	kx::vector<qtype::symbol_> k(s, s+ 4);

	return kx::xD(k,v);
}

kx::K bml_stat_median(kx::K x_)
{
	kx::raw_vector<qtype::float_> x(x_);
	kx::F mu = boost::math::statistics::median(x.begin(), x.end());
	return kx::kf(mu);
}

kx::K bml_stat_interquartile_range(kx::K x_)
{
	kx::raw_vector<qtype::float_> x(x_);
	kx::F mu = boost::math::statistics::interquartile_range(x.begin(), x.end());
	return kx::kf(mu);
}

kx::K bml_stat_gini_coefficient(kx::K x_)
{
	kx::raw_vector<qtype::float_> x(x_);
	kx::F mu = boost::math::statistics::gini_coefficient(x.begin(), x.end());
	return kx::kf(mu);
}

kx::K bml_stat_covariance(kx::K x_, kx::K y_)
{
	kx::raw_vector<qtype::float_> x(x_);
	kx::raw_vector<qtype::float_> y(y_);
	kx::F mu = boost::math::statistics::covariance(x, y);
	return kx::kf(mu);
}

kx::K bml_stat_means_and_covariance(kx::K x_, kx::K y_)
{
	kx::raw_vector<qtype::float_> x(x_);
	kx::raw_vector<qtype::float_> y(y_);
	auto [m1,m2,cov] = boost::math::statistics::means_and_covariance(x, y);
	double m[] = { m1,m2,cov };
	kx::S s[] = { kx::ss("m1"),kx::ss("m2"),kx::ss("cov")};

	kx::vector<qtype::float_> v(m, m + 3);
	kx::vector<qtype::symbol_> k(s, s + 3);

	return kx::xD(v,k);
}

kx::K bml_stat_correlation_coefficient(kx::K x_, kx::K y_)
{
	kx::raw_vector<qtype::float_> x(x_);
	kx::raw_vector<qtype::float_> y(y_);
	kx::F mu = boost::math::statistics::correlation_coefficient(x, y);
	return kx::kf(mu);
}
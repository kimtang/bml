
#include <boost/math/special_functions/erf.hpp>

# include <kdb/kdb.hpp>

namespace qtype = kx::qtype;

kx::K bml_spfn_erf(kx::K x_)
{
	kx::raw_vector<qtype::float_> x(x_);
	kx::vector<qtype::float_> result(x.size());
	std::transform(x.begin(), x.end(), result.begin(), boost::math::erf<kx::F>);
	return result;
}

kx::K bml_spfn_erfc(kx::K x_)
{
	kx::raw_vector<qtype::float_> x(x_);
	kx::vector<qtype::float_> result(x.size());
	std::transform(x.begin(), x.end(), result.begin(), boost::math::erfc<kx::F>);
	return result;
}
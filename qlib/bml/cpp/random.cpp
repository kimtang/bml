# define BOOST_MATH_ASSERT_UNDEFINED_POLICY false

# include <cstdint>
# include <kdb/kdb.hpp>

#pragma warning( push )
#pragma warning( disable : 4311)

namespace qtype = kx::qtype;

kx::K dot_(kx::K a1, kx::K a2)
{
	return kx::dot(a1, a2);
}


#pragma warning( pop )
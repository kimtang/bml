

# include <kdb/kdb.hpp>

namespace qtype = kx::qtype;

kx::K bml_api_dot_(kx::K a1, kx::K a2)
{
	return kx::dot(a1, a2);
}
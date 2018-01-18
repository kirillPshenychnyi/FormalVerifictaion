#ifndef __VLOG_DM_DESIGN_UNIT_FACTORY_HPP__
#define __VLOG_DM_DESIGN_UNIT_FACTORY_HPP__

/***************************************************************************/

#include "boost\noncopyable.hpp"

/***************************************************************************/

namespace VlogDM
{
	struct Location;
}

/***************************************************************************/

namespace VlogDM {
namespace Writable {

/***************************************************************************/

	struct DesignUnit;

/***************************************************************************/

struct DesignUnitFactory
	:	public boost::noncopyable
{

/***************************************************************************/

	virtual ~DesignUnitFactory() {}

	virtual std::unique_ptr< DesignUnit > newDesignUnit( 
			std::string const & _name
		,	Location const & _location 
	) const = 0;

/***************************************************************************/

};

/***************************************************************************/

}
}

/***************************************************************************/

#endif // !__VLOG_DM_DESIGN_UNIT_FACTORY_HPP__


#ifndef __VLOG_DM_DECLARED_FACTORY_HPP__
#define __VLOG_DM_DECLARED_FACTORY_HPP__

/***************************************************************************/

#include "vlog_data_model\api\vlog_dm_fwd.hpp"

#include "vlog_data_model\api\vlog_dm_port_directrion.hpp"
#include "vlog_data_model\api\vlog_dm_net_type.hpp"

/***************************************************************************/

namespace VlogDM {
namespace Writable {

/***************************************************************************/

struct DeclaredFactory 
	:	public boost::noncopyable
{

/***************************************************************************/

	virtual ~DeclaredFactory() = default;

	virtual PortPtr newPort ( 
			VlogDM::Declaration const & _declaration
		,	std::string const & _name
		,	Location const & _location
		,	PortDirection::Direction _direction
		,	std::unique_ptr< Dimension > _dimension
	) const = 0;

	virtual VariablePtr newVariable ( 
			VlogDM::Declaration const & _declaration
		,	std::string const & _name
		,	Location const & _location
		,	bool _isSigned
		,	std::unique_ptr< Dimension > _dimension
	) const = 0;

/***************************************************************************/

};

/***************************************************************************/

}
}

/***************************************************************************/

#endif // __VLOG_DM_DECLARED_FACTORY_HPP__
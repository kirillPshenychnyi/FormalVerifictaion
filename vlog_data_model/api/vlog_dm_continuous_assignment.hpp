#ifndef __VLOG_DM_CONTINUOUS_ASSIGNMENT_HPP__
#define __VLOG_DM_CONTINUOUS_ASSIGNMENT_HPP__

/***************************************************************************/

#include "vlog_data_model\api\vlog_dm_process.hpp"

/***************************************************************************/

namespace VlogDM {

/***************************************************************************/

struct BinaryOperator;

/***************************************************************************/

struct ContinuousAssignment
	:	public Process
{

/***************************************************************************/

	virtual BinaryOperator const & getAssignment() const = 0;

/***************************************************************************/

};

/***************************************************************************/

}

/***************************************************************************/

#endif // !__VLOG_DM_CONTINUOUS_ASSIGNMENT_HPP__
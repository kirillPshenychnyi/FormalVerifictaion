#ifndef __VLOG_DM_TYPE_VISITOR_HPP__
#define __VLOG_DM_TYPE_VISITOR_HPP__

/***************************************************************************/

#include <boost\noncopyable.hpp>

/***************************************************************************/

namespace VlogDM {

/***************************************************************************/

struct NetType;
struct VariableType;

/***************************************************************************/

struct TypeVisitor
	:	public boost::noncopyable
{

/***************************************************************************/

	virtual void visit( NetType const & _netType ) = 0;

	virtual void visit( VariableType const & _varType ) = 0;

/***************************************************************************/

};

/***************************************************************************/

struct TypeDefaultVisitor
	:	public TypeVisitor
{

/***************************************************************************/

	void visit( NetType const& _port ) override {}
	
	void visit( VariableType const & _varType ) override {}

/***************************************************************************/

};

/***************************************************************************/

}

/***************************************************************************/

#endif // !__VLOG_DM_TYPE_VISITOR_HPP__

#ifndef __AEP_MODEL_ACCESSOR_HPP__
#define __AEP_MODEL_ACCESSOR_HPP__

/***************************************************************************/

#include "aep_model\api\aep_model_fwd.hpp"

/***************************************************************************/

namespace AepModel {

/***************************************************************************/

struct IAccessor
	:	public boost::noncopyable
{ 

/***************************************************************************/

	virtual ~IAccessor() = default;

	virtual OvlCheckersFactory const& getCheckersFactory() const = 0;

	virtual boost::optional< AssertionContext& > takeAssertionContext( 
		std::string const & _dutName 
	) = 0;
 
	virtual boost::optional< AssertionContext const & > getAssertionContext( 
		std::string const & _dutName 
	) = 0;
 
	virtual AssertionContext & addContext( std::string const & _dutName ) = 0;

	virtual void forEachContext( AssertionContextCallback _callback ) = 0;

	virtual void forEachContext( ConstAssertionContextCallback _callback ) const = 0;

	virtual void regenerateAssertions( std::string const & _path ) const = 0;

	virtual int getContextsCount() const = 0;

	virtual void reset() = 0;

/***************************************************************************/

};

/***************************************************************************/

}

/***************************************************************************/

#endif // !__AEP_MODEL_ACCESSOR_HPP__

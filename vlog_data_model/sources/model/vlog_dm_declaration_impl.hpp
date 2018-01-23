#ifndef __VLOG_DM_DECLARATION_IMPL_HPP__
#define __VLOG_DM_DECLARATION_IMPL_HPP__

/***************************************************************************/

#include "api\vlog_dm_declaration.hpp"
#include "api\vlog_dm_declared.hpp"
#include "api\vlog_dm_location.hpp"

#include "sources\model\vlog_dm_located_impl.hpp"

#include <boost\unordered_set.hpp>
#include "common_tools\collections\tools_collection_utils.hpp"

/***************************************************************************/

namespace VlogDM { 

/***************************************************************************/

template< typename _Writable >
class DeclarationImpl
	:	public LocatedImpl< _Writable >
{

/***************************************************************************/

	typedef
		LocatedImpl< _Writable >
		BaseClass;

	typedef
		Tools::Collections::NamedHasher< Declared::Ptr >
		DeclaredHasher;

	typedef
		Tools::Collections::NamedComparator< Declared::Ptr >
		DeclaredComparator;

	typedef
		boost::unordered_set< Declared::Ptr, DeclaredHasher, DeclaredComparator >
		Declareds;

/***************************************************************************/

public:

/***************************************************************************/

	DeclarationImpl( Location const & _location );

/***************************************************************************/

	boost::optional< Declared const & > findDeclared( 
			std::string const & _declared 
	) const override;

	int getDeclaredsCount() const override;

/***************************************************************************/

protected:

/***************************************************************************/

	void addDeclared( std::unique_ptr< Declared > _declared ) override;

/***************************************************************************/

private:

/***************************************************************************/

	Declareds m_declareds;

/***************************************************************************/

};

/***************************************************************************/

template< typename _Writable >
DeclarationImpl< _Writable >::DeclarationImpl( Location const & _location )	
	:	BaseClass( _location )
{
}

/***************************************************************************/

template< typename _Writable >
boost::optional< Declared const & > 
DeclarationImpl< _Writable >::findDeclared( std::string const & _declared ) const 
{
	auto value = m_declareds.find( _declared, DeclaredHasher(), DeclaredComparator() );

	return
			value == m_declareds.end()
		?	boost::optional< Declared const & >()
		:	**value;

}

/***************************************************************************/

template< typename _Writable >
int 
DeclarationImpl< _Writable >::getDeclaredsCount() const
{
	return m_declareds.size();
}

/***************************************************************************/

template< typename _Writable >
void 
DeclarationImpl< _Writable >::addDeclared( std::unique_ptr< Declared > _declared )
{
	m_declareds.insert( std::move( _declared ) );
}

/***************************************************************************/

}

#endif // __VLOG_DM_DECLARATION_IMPL_HPP__
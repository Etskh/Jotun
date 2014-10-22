#ifndef __INCLUDED_JOTUN_List_h
#define __INCLUDED_JOTUN_List_h

#include <vector>
#include "core/Patterns.h"

namespace core {

template< class _Type >
class List
{
public:
	typedef	std::vector<_Type>					ListType;
	typedef typename ListType::iterator			iterator;
	
public:
					List			( void );
					List			( const List& ref );
					List			( const _Type* array, uint count );
					~List			( void );
	
public:
	List&			operator=		( const List& ref );
	List&			operator+=		( const List& ref );
	List			operator+		( const List& ref );

public:
	uint			size			( void ) const;
	bool			empty			( void ) const { return size() == 0; }
	inline uint		length			( void ) const { return size(); }
	
public:
	iterator		begin			( void );
	iterator		end				( void );
	
public:
	_Type&			operator[]		( int index );
	const _Type&	operator[]		( int index ) const;
	List&			operator+=		( const _Type& ref );
	//List&			operator+=		( _Type val );
	
public:
	void			push_back		( const _Type& ref );
	//void			push_back		( _Type val );
	void			Add				( const _Type& ref );
	//void			Add				( _Type val );
	
public:
	_Type&			back			( void );
	
private:
	ListType		_data;
};

} // namespace List

#include "List.inl"

#endif // __INCLUDED_JOTUN_List_h

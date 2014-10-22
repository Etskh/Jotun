



template <class _Component, class ... _Args>
bool	gui::Widget::AddComponent		( _Args ... args )
{
	AddAttribute<_Component>(args...);
	return true;
}

template <class _Component>
_Component*	gui::Widget::Get		( void )
{
	return GetAttribute<_Component>();
}

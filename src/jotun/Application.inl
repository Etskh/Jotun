

template < class _System >
void	Application::Load	( SmrtPtr< _System > sys )
{
	_systems.push_back( HSystem( sys.ptr() ));
}
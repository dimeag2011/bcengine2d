//-----------------------------------------------------------------------------------------
inline void Item::setPeso(float &rkPeso)
{
	m_kPeso = rkPeso;
}
//-----------------------------------------------------------------------------------------
inline float Item::getPeso() const
{
	return m_kPeso;
}
//-----------------------------------------------------------------------------------------
inline void Item::setDescripcion(const string &rkDesc)
{
	m_kDesc = rkDesc;
}
//-----------------------------------------------------------------------------------------
inline string Item::getDescripcion() const 
{
	return m_kDesc;
}
//-----------------------------------------------------------------------------------------
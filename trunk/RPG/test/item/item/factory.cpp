//-----------------------------------------------------------------------
#include "factory.h"
//-----------------------------------------------------------------------------------------
Factory::Factory()
{
	/****/
}
//-----------------------------------------------------------------------------------------
Factory::~Factory()
{
	/****/
}
//-----------------------------------------------------------------------------------------
void Factory::remove(Component *kComponent){

    // Si el kComponente no es nulo
    if (kComponent){

        // Enviamos el iterador al principio
        m_lkListIterator = m_lKList.begin();

        // Mientras el iterador no llegue al final
        // y el valor sea diferente al Component
        while ((m_lkListIterator != m_lKList.end()) &&
            ((*m_lkListIterator != kComponent))){
            // Incrementamos el iterador
            m_lkListIterator++;
        }

        // Si el iterador llego al final, salimos del metodo
        if (m_lkListIterator == m_lKList.end()){
            return;
        }
        // Si el valor de iterador del componente
        if ((*m_lkListIterator) == kComponent){

            // Quitamos el el componente de la lista.
            m_lKList.remove(kComponent);
            delete kComponent;
            kComponent = NULL;
        }
  }
}
//-----------------------------------------------------------------------------------------
void Factory::removeAll(){
	
	Component * kComponent;

	//Recorro todo el iterador para borrar todos los objetos.
	for(m_lkListIterator = m_lKList.begin(); m_lkListIterator != m_lKList.end();
		m_lkListIterator++)
	{
		kComponent = *m_lkListIterator;
		
	        
		delete kComponent;
        kComponent = NULL;
	}

	m_lKList.clear();
}
//-----------------------------------------------------------------------------------------

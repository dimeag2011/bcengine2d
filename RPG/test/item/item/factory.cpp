#include "factory.h"
//-----------------------------------------------------------------------------------------
Factory::Factory(){
	/****/
}
//-----------------------------------------------------------------------------------------
Factory::~Factory(){
	/****/
}
//-----------------------------------------------------------------------------------------
void Factory::remove(Component *kComponent){

    // Si el Componente no es nulo
    if (kComponent){

        // Enviamos el iterador al principio
        m_klKlistIterator = m_lKList.begin();

        // Mientras el iterador no llegue al final
        // y el valor sea diferente al Item
        while ((m_klKlistIterator != m_lKList.end()) &&
            ((*m_klKlistIterator != kComponent))){
            // Incrementamos el iterador
            m_klKlistIterator++;
        }

        // Si el iterador llego al final, salimos del metodo
        if (m_klKlistIterator == m_lKList.end()){
            return;
        }
        // Si el valor de iterador del componente
        if ((m_klKlistIterator) == kComponent){

            // Quitamos el el componente de la lista.
            m_lKList.remove(kComponent);
            delete kComponent;
            kComponent = NULL;
        }
  }
}//-----------------------------------------------------------------------------------------
Factory::removeAll(){
	
	Component * kComponent;
	//Recorro todo el iterador para borrar sus componentes.
	for(m_klKlistIterator = m_lKList.begin(); m_klKlistIterator != m_lKList.end()
		m_klKlistIterator++;)
	{
		kComponent = *m_klKlistIterator;
		
		
		m_lKList.remove(m_klKlistIterator);
        
		delete kComponent;
        kComponent = NULL;
	}

	m_lKList.clear();
}


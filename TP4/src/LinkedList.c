/*
 * LinkedList.c
 *
 *  Created on: 17 nov. 2021
 *      Author: MI COMPU
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* esto= NULL;
    esto = (LinkedList*) malloc(sizeof(LinkedList));
    if(esto != NULL)
    {
        esto->pFirstNode = NULL;
        esto->size = 0;
    }

    return esto;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNodo = NULL;
    int contador = 0;
    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this) )
    {
        for( pNodo = this->pFirstNode; contador < nodeIndex ; contador ++)
        {
            pNodo = pNodo->pNextNode;
        }
    }
    return pNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo = NULL;
    Node* nodoAux = NULL;
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        nuevoNodo = (Node*) malloc(sizeof(Node));
        if(nuevoNodo != NULL )
        {
            nuevoNodo->pElement = pElement;
            if(nodeIndex == 0 )
            {
                nuevoNodo->pNextNode = this->pFirstNode;
                this->pFirstNode = nuevoNodo;
            }
            else
            {
                nodoAux = getNode(this,nodeIndex - 1);
                nuevoNodo->pNextNode = nodoAux->pNextNode;
                nodoAux->pNextNode = nuevoNodo;

            }
            this->size++;
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{

    int returnAux = -1;
    if(this != NULL )
    {

        returnAux = addNode(this,(ll_len(this)),pElement);

    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodo = NULL;
    if(this != NULL && index > -1 && index < ll_len(this) )
    {

        nodo = getNode(this,index);
        if(nodo != NULL)
        {
            returnAux = nodo->pElement;
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    Node* pNode = NULL;
    int returnAux = -1;

    if(this != NULL && index > -1 && index < ll_len(this) )
    {
          pNode = getNode(this,index);
          if(pNode != NULL)
          {
            pNode->pElement = pElement;
            returnAux = 0;

          }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    if(this != NULL && index >=0 && index < ll_len(this))
    {
        Node* nodoAremover = getNode(this,index);
        if(index == 0)
        {
            this->pFirstNode = nodoAremover->pNextNode;
        }
        else
        {
            Node* nodoAnterior = getNode(this,index - 1);
            nodoAnterior->pNextNode = (nodoAnterior->pNextNode)->pNextNode;
        }
        free(nodoAremover);
        this->size--;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        while( ll_len(this) != 0)
        {
            ll_remove(this,0);
        }
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL )
    {
        int tam = ll_len(this);
        for(int i=0; i<tam; i++)
        {

            if(ll_get(this,i) == pElement)
            {
                returnAux = i;
                break;
            }
        }

    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL )
    {

        int tam = ll_len(this);
        if(tam )
        {
            returnAux = 0;
        }
        else
        {

           returnAux = 1;
        }

    }


    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
     if(this != NULL && index > -1 && index <= ll_len(this))
    {

        returnAux = addNode(this,index,pElement);

    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && index >=0 && index < ll_len(this))
    {
        returnAux = ll_get(this,index);
        if(ll_remove(this,index))
        {

            returnAux = NULL;
        }

    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
           returnAux = 1;
            if(ll_indexOf(this,pElement) == -1)
            {
                returnAux = 0;
            }


    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int largo = 0;

    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;
        largo = ll_len(this2);
        for(int i=0;i<largo;i++)
        {
            if(ll_indexOf(this,ll_get(this2,i)) == -1)
            {
                returnAux = 0;
                break;
            }
        }

    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement = NULL;
    if(this != NULL && from > -1 && from < ll_len(this) && to > from && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();
        if( cloneArray != NULL)
        {
            for(int i = from; i< to; i++)
            {
                pElement = ll_get(this,i);
                ll_add(cloneArray,pElement);
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    cloneArray = ll_subList(this,0,ll_len(this));

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int largo = 0;
    void* elemento1 = NULL;
    void* elemento2 = NULL;
    void* aux = NULL;

    if( this != NULL && pFunc != NULL && order > -1 && order < 2)
    {
        largo = ll_len(this);
        for(int i = 0; i < largo - 1; i++ )
        {
            for(int j = i + 1; j< largo; j++)
            {
                elemento1 = ll_get(this,i);
                elemento2 = ll_get(this,j);
                if(order)
                {
                    if(pFunc(elemento1,elemento2) > 0)
                    {
                        aux = elemento1;
                        elemento1 = elemento2;
                        elemento2 = aux;
                        ll_set(this,i,elemento1);
                        ll_set(this,j,elemento2);
                    }
                }
                else
                {
                    if(pFunc(elemento1,elemento2) < 0)
                    {
                        aux = elemento1;
                        elemento1 = elemento2;
                        elemento2 = aux;
                        ll_set(this,i,elemento1);
                        ll_set(this,j,elemento2);
                    }

                }
            }
        }
        returnAux = 0;
    }

    return returnAux;

}





/** \brief Permite filtrar usando una función como criterio
 *
 * \param void* función que debe entregar un 0 si no se cumple o un 1 por el contrario
  *\param  LinkedList* lista conteniendo todos los datos a contrastar contra el criterio
 * \return  LinkedList* lista que cumple con el criterio
 *
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* nueva = NULL;
    void* elemento = NULL;
    int largo = 0;
    if(this != NULL && pFunc != NULL)
    {
        nueva = ll_newLinkedList();
        if(nueva != NULL)
        {

            largo = ll_len(this);
            for(int i = 0;i<largo; i++)
            {
                elemento = ll_get(this,i);
                if(pFunc(elemento))
                {

                    ll_add(nueva, elemento);
                }
            }
        }
    }
    return nueva;
}



/** \brief Permite filtrar una LinkedList a través de una función que acepta dos parámetros
 *
 * \param void* función de criterio
 * \param char un carácter
 * \param  LinkedList* LinkedList conteniendo datos
 * \return LinkedList* un linkedlist que cumple con los criterios
 *
 */
LinkedList* ll_filter2(LinkedList* this, int (*pFunc)(void* ,char))
{
    LinkedList* nueva = NULL;
    void* elemento = NULL;
    char letra;

    int largo = 0;
    if(this != NULL && pFunc != NULL)
    {
        nueva = ll_newLinkedList();
        if(nueva != NULL)
        {
            letra = inputChar("Ingrese letra :");

            largo = ll_len(this);
            for(int i = 0;i<largo; i++)
            {
                elemento = ll_get(this,i);
                if(pFunc(elemento, letra ))
                {

                    ll_add(nueva, elemento);
                }
            }
        }
    }
    return nueva;
}



LinkedList* ll_filter3(LinkedList* this, int (*pFunc)(void* ,int))
{
    LinkedList* nueva = NULL;
    void* elemento = NULL;
    int numero;

    int largo = 0;
    if(this != NULL && pFunc != NULL)
    {
        nueva = ll_newLinkedList();
        if(nueva != NULL)
        {
            numero = inputInt("Ingrese número :");

            largo = ll_len(this);
            for(int i = 0;i<largo; i++)
            {
                elemento = ll_get(this,i);
                if(pFunc(elemento, numero ))
                {

                    ll_add(nueva, elemento);
                }
            }
        }
    }
    return nueva;
}



int ll_map(LinkedList* this, void (*pFunc)(void*))
{
	int rtn = -1;
	void* pAuxiliar;
	//VERIFICAR NULIDAD
	if(this != NULL && pFunc != NULL)
	{
		//RECORRER MI LISTA
		for(int i = 0; i< ll_len(this); i++)
		{
			//TOMO EL ELEMENTO
			pAuxiliar = ll_get(this, i);
			if(pAuxiliar != NULL)
			{
				//MAPEO
				pFunc(pAuxiliar);
			}
		}
		rtn = 0;
	}
	return rtn;
}

#pragma once 

template<typename Type >
class List {
public :
	Type	elem;

	List<Type>* next = nullptr;

	List(const Type &elem) 
	{
		this->elem = elem;
	}

	int Length()
	{
		if (nullptr == next) return 1;
		else return next->Length() + 1;
	}
	void Append(const Type & elem)
	{
		// ajoute elem a la fin de al liste 
		if (next == nullptr)
			next = new List(elem);
		else
			next->Append(elem);
		
	}
	List<Type>* AddFirst(const Type & elem)
	{
		// ajoute elem au debut de la ligne 
		auto Toto = new List(elem);
		Toto->next = this;
		return Toto;
	}
	List<Type>* Remove(const Type & removeme) 
	{
		
		if (this->elem == removeme)
		{
			auto suitedeliste = next;
			delete this;
			return suitedeliste -> Remove(removeme);

		}
		else
		{
			if (next)
			{
				next = next->Remove(removeme);
			}
			return this;
		}
		
	}
	bool Contains(const Type & elemATrouver)
	{
		if (elem == elemATrouver)
		{
			return true; 
		}
		else if (next == nullptr)
		{
			return false; 
		}
		else 
		{
			return next->Contains(elemATrouver);
		}
	}
	
};

typedef List<int> IntList;

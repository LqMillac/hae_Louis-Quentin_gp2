#pragma once
#include "Lib.hpp"
#include <algorithm>
#include<unordered_map>

using namespace std;

namespace std {
	template <>
	struct hash<Vector2i>
	{
		std::size_t operator() ( const Vector2i& k)const
		{
		return (unsigned int)(k.x << 16) | ((unsigned int)k.y);
		}
	};

	template <>
	struct hash<Vector2f>
	{
		std::size_t operator() (const Vector2f& k) const
		{
			return (unsigned int)(((int)k.x) << 16) | ((unsigned int)k.y);
		}
	};

}
class dijkstra
{
public:

	std::vector<Vector2f> G;
	Vector2f start;
	std::unordered_map<Vector2f, double> distance;
	std::unordered_map<Vector2f, Vector2f> pred;
	
	void Initialisation(const std::vector<Vector2f>& _graph, const Vector2f & _start)
	{
		G = _graph;
		start = _start;
		 for (int i=0; i < G.size();i++)
		//for (const Vector2f& vec : _graph)
		{
			Vector2f vec = G[i];
			distance[vec] = 9999999;
	    }
		distance[_start] = 0;
		int i = 0;

		/*Initialisation(G, sdeb)
			1 pour chaque point s de G faire
			2    d[s] : = infini             /* on initialise les sommets autres que sdeb à infini
			3 fin pour
			4 d[sdeb] : = 0                  /* la distance au sommet de départ sdeb est nulle */
	}
	Vector2f FindMin(std::vector<Vector2f>& queue)
	{
		double Mini = 9999999; // Infinity
		Vector2f sommet = Vector2f(-1, -1);
		for (const Vector2f& vec : queue)
		{
			if (distance[sommet] < Mini)
			{
				Mini = distance[vec];
				sommet = vec;
			}
		}
		return sommet;
		/*Trouve_min(Q)
				1 mini : = infini
				2 sommet : = -1
				3 pour chaque sommet s de Q
				4    si d[s] < mini
				5    alors
				6        mini : = d[s]
				7        sommet : = s
				8 renvoyer sommet*/
	}
	int  FindMin2(std::vector<Vector2f>& queue)
	{
		double Mini = 9999999; // Infinity
		
		int vtx = -1;
		for (int i =0; i< queue.size();i++)
		{
			const Vector2f& vec = queue[i];
		
			if (distance[vec] < Mini)
			{
				Mini = distance[vec];
				vtx= i;
			}
		
		}
		return vtx;
	
	}
	double weight(Vector2f a, Vector2f b)
	{
		Vector2f diff = b - a;
		double length = sqrt((diff.x*diff.x + diff.y*diff.y));
		return 0.0;
	}

	void UpdateDistance(Vector2f s1, Vector2f s2)
	{
		/*maj_distances(s1, s2)
		1 si d[s2] > d[s1] + Poids(s1, s2)       Si la distance de sdeb à s2 est plus grande que
		2                                      celle de sdeb à S1 plus celle de S1 à S2
		3    alors
		4        d[s2] : = d[s1] + Poids(s1, s2) /On prend ce nouveau chemin qui est plus court
		5        prédécesseur[s2] : = s1         En notant par où on passe */
		if (distance[s2] > distance[s1] + weight(s1, s2))
		{
			distance[s2] = distance[s1] + weight(s1, s2);
			pred[s2] = s1;
		}

	}
	void Compute(std::vector<Vector2f> G,Vector2f _start)
	{
		/*Dijkstra(G, Poids, sdeb)
		1 Initialisation(G, sdeb)
		2 Q : = ensemble de tous les nœuds
		3 tant que Q n'est pas un ensemble vide faire
		4       s1 : = Trouve_min(Q)
		5       Q : = Q privé de s1
		6       pour chaque nœud s2 voisin de s1 faire
		7           maj_distances(s1, s2)
		8       fin pour
		9 fin tant que*/
		Initialisation(G,start);
		std::vector<Vector2f> Q = G;
		while(Q.size()>0)
		{
			Vector2f s1 = FindMin(Q);
			int sai = FindMin2(Q);
			s1 = Q[sai];
			Q.erase(Q.begin() + sai);
			for (const Vector2f & s : Q)
			{
				if ((s.x == s1.x + 1 && s.y == s1.y) 
					|| (s.x == s1.x  -1 && s.y == s1.y) 
					|| (s.x == s1.x  && s.y == s1.y+1) 
					|| (s.x == s1.x  && s.y == s1.y-1))
				{
					UpdateDistance(s1, s);
				}
			}
		}

	}
	bool FindPath(std::vector<Vector2f>& _result, const Vector2f & end)
	{
		/*A = suite vide
			2 s : = sfin
			3 tant que s != sdeb faire
			4   A = A + s                  on ajoute s à la suite A 
			5   s = prédécesseur[s]        on continue de suivre le chemin 
			6 fin tant que*/
		_result.clear();
		Vector2f cur = end;
		while (cur != start)
		{
			_result.push_back(cur);
			cur = pred[cur];
		}
		if (_result.size() == 0)
		{
			return false;
		}
		else
		{
			_result.push_back(start);
			std::reverse(_result.begin(), _result.end());
		}
		
		
			return false; 
	}
	

	

			
	
};


#ifndef UFA_GALE_SHAPLEY_ALGORITHM_HPP
#define UFA_GALE_SHAPLEY_ALGORITHM_HPP

#include "ufa/logic/FormationPlacement.hpp"

namespace ufa
{
	class GaleShapleyRelationship
	{
	public:
		int womanID;
		float distance;
	};
	
	bool operator<(const GaleShapleyRelationship &p_relationship1, const GaleShapleyRelationship &p_relationship2);
	
	class GaleShapleyMan
	{
	public:
		int id;
		int next;
		Vec2 position;
		std::vector<float> distances;
		std::vector<GaleShapleyRelationship> preferredWomen;
		int nextWoman;
		int engagedTo;
	};
	
	class GaleShapleyWoman
	{
	public:
		int id;
		Vec2 position;
		int engagedTo;
	};
	
	class GaleShapleyAlgorithm : public ufa::FormationPlacement
	{
	private:
		Formation *formation_;
		std::vector<GaleShapleyMan> men_;
		std::vector<GaleShapleyWoman> women_;
		int currentMan_;
		int currentWoman_;
		
		void init(Formation& p_formation);
		void pairWomanAndMen();
		void applyPositions();
		
		bool womanIsEngaged(const int p_woman);
		int nextPreferredWoman(const int p_man);
		void engage(const int p_man, const int p_woman);
	public:
		GaleShapleyAlgorithm();
		~GaleShapleyAlgorithm();

		void placeUnits(Formation& p_formation);
	};

}

#endif
